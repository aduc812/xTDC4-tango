#include <xTDC4_interface.h>
#include <XTDC4.h>
#include "packet_parser.h"

typedef  unsigned long uint32;


int xTDC4_packet_parser(crono_packet  **first_packet, crono_packet **last_packet, __int64 buffer_size,
	unsigned int *hits, unsigned char *channels, unsigned __int64 *start_timestamps,
	int *number_of_hits, int *number_of_valid_packets,
	int *number_of_errors, int *number_of_empty,
	unsigned char package_error_flags_mask, unsigned char hit_error_flags_mask)
{
	*number_of_errors = 0;
	*number_of_valid_packets = 0;
	*number_of_empty = 0;
	int maxhits = *number_of_hits;
	*number_of_hits = 0;
	__int64 max_data_length = buffer_size;

		//check the length of data read
	if ((last_packet - first_packet) > max_data_length)
	{
		return XTDC4_WRAPPER_DATA_TOO_LONG;
	}

	// iterate over all packets from first to last
	while ((*first_packet) <= (*last_packet))
	{
		int bPacketInvalid = 0;
		crono_packet *p = *first_packet;
		// a packet with no hits
		if (p->length == 0)
		{
			(*number_of_empty)++;
			bPacketInvalid = 1;
		}

		if (p->flags&(package_error_flags_mask))
		{
			(*number_of_errors)++;
			bPacketInvalid = 1;
		}

		if (!bPacketInvalid)
		{
			int hitcount = 2 * (p->length);
			if ((p->flags & 0x1) == 1)
				hitcount -= 1;
			if (hitcount > maxhits)
				return XTDC4_WRAPPER_BUFFER_TOO_SMALL; // current 
			if (hitcount > maxhits - *number_of_hits)
				return XTDC4_WRAPPER_BUFFER_FULL;
			uint32 *packetdata = (uint32*)(p->data);
			//check individual hits for errors
			if ((hit_error_flags_mask)& 0xf0)
			{
				for (int ctr = 0; ctr < hitcount; ctr++)
				{
					if (packetdata[ctr] & ((uint32)(hit_error_flags_mask)& (uint32)0xf0))
					{
						(*number_of_errors)++;
						bPacketInvalid = 1;
						break;
					}

				}
			}

			if (!bPacketInvalid) // if the packet is valid, copy it to the output
			{
				uint32 rollover_count = 0;
				int realhitcount = 0;
				for (int ctr = 0; ctr < hitcount; ctr++)
				{
					if ((packetdata[ctr] & (uint32)0x2f) == 0x2f)// in the last byte, bit 5 is rollover and bits 0..3 indicate channel 15
					{
						rollover_count += 0x01000000;
					}
					else
					{
						hits[*number_of_hits + realhitcount] = (packetdata[ctr] >> 8) + rollover_count;//(packetdata[ctr] >> 8)
						channels[*number_of_hits + realhitcount] = (unsigned char)(packetdata[ctr] & 0x0f);
						start_timestamps[*number_of_hits + realhitcount] = p->timestamp;
						realhitcount++; // not a rollover event
					}
				}
				// memcpy does not work if we want to skip rollovers
				//memcpy_s(hits + *number_of_hits, (maxhits - *number_of_hits) * 4, packetdata, hitcount * 4);
				if (realhitcount)
				{
					(*number_of_valid_packets)++;
					*number_of_hits = *number_of_hits + realhitcount;// update number of hits to be returned				
				}
				else
				{
					(*number_of_empty)++; // package contained only rollover events
				}

			}
		}
		// go to next packet
		*first_packet = crono_next_packet(*first_packet);

	}
	return XTDC4_WRAPPER_OK;
}