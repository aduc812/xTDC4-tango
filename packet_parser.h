
#define XTDC4_WRAPPER_OK 0;
#define XTDC4_WRAPPER_BUFFER_TOO_SMALL -1
#define	XTDC4_WRAPPER_DATA_TOO_LONG -2
// not exactly an error - just indication that there are more hits to extract than buffer requested 
#define	XTDC4_WRAPPER_BUFFER_FULL 1


//constants
#define MAX_DATA_LENGTH 1024*1024*100 //100 Mb


int xTDC4_packet_parser(crono_packet  **first_packet, crono_packet **last_packet, __int64 buffer_size,
	unsigned int *hits, unsigned char *channels, unsigned __int64 *start_timestamps,
	int *number_of_hits, int *number_of_valid_packets,
	int *number_of_errors, int *number_of_empty,
	unsigned char package_error_flags_mask, unsigned char hit_error_flags_mask);