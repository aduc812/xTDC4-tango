/*----- PROTECTED REGION ID(XTDC4.h) ENABLED START -----*/
//=============================================================================
//
// file :        XTDC4.h
//
// description : Include file for the XTDC4 class
//
// project :     xTDC4_DevServer
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef XTDC4_H
#define XTDC4_H

#include <tango.h>
#include <queue>




/*----- PROTECTED REGION END -----*/	//	XTDC4.h

/**
 *  XTDC4 class description:
 *    https://www.cronologic.de/time_measurement/tdc/xtdc4/
 */

namespace XTDC4_ns
{
/*----- PROTECTED REGION ID(XTDC4::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

typedef std::vector<__int64> datachunk;

/*----- PROTECTED REGION END -----*/	//	XTDC4::Additional Class Declarations

class XTDC4 : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(XTDC4::Data Members) ENABLED START -----*/
private:


/*----- PROTECTED REGION END -----*/	//	XTDC4::Data Members

//	Device property data members
public:
	//	buffer_size:	Amount of local memory used for DMA data buffer
	Tango::DevLong64	buffer_size;
	//	board_id:	the global index in all cronologic devices.
	//  This 8 bit number is filled into each packet created by the board and is useful if data streams
	//  of multiple boards will be merged. If only XTDC4 cards are used this number can be set to the
	//  card index. If boards of different types that use a compatible data format are used in a system
	//  each board should get a unique id. Can be changed at runtime.
	Tango::DevShort	board_id;
	//	card_index:	The index in the list of XTDC4 boards that should be initialized.
	//  There might be multiple boards in the system that are handled by this driver as reported by
	//  xtdc4_count_devices. This index selects one of them. Boards are enumerated depending on the
	//  PCIe slot. The lower the bus number and the lower the slot number the lower the card index.
	Tango::DevShort	card_index;
	//	use_ext_clock:	If set to 1 use external 10 MHz reference. If set to 0 use internal reference.
	Tango::DevShort	use_ext_clock;

//	Attribute data members
public:
	Tango::DevLong	*attr_error_code_read;
	Tango::DevString	*attr_error_message_read;
	Tango::DevShort	*attr_device_type_read;
	Tango::DevBoolean	*attr_START_RISING_read;
	Tango::DevDouble	*attr_START_DC_OFFSET_read;
	Tango::DevBoolean	*attr_CH0_ENABLED_read;
	Tango::DevBoolean	*attr_CH0_RISING_read;
	Tango::DevDouble	*attr_CH0_DC_OFFSET_read;
	Tango::DevBoolean	*attr_CH1_ENABLED_read;
	Tango::DevBoolean	*attr_CH1_RISING_read;
	Tango::DevDouble	*attr_CH1_DC_OFFSET_read;
	Tango::DevBoolean	*attr_CH2_ENABLED_read;
	Tango::DevBoolean	*attr_CH2_RISING_read;
	Tango::DevDouble	*attr_CH2_DC_OFFSET_read;
	Tango::DevBoolean	*attr_CH3_ENABLED_read;
	Tango::DevBoolean	*attr_CH3_RISING_read;
	Tango::DevDouble	*attr_CH3_DC_OFFSET_read;
	Tango::DevLong64	*attr_TW_START_read;
	Tango::DevLong64	*attr_TW_END_read;
	Tango::DevBoolean	*attr_config_changed_read;
	Tango::DevBoolean	*attr_start_trigger_generator_read;
	Tango::DevLong	*attr_last_run_valid_starts_read;
	Tango::DevLong	*attr_last_run_empty_starts_read;
	Tango::DevLong	*attr_last_run_hits_read;
	Tango::DevLong	*attr_last_run_start_errors_read;
	Tango::DevLong	*attr_start_trigger_generator_frequency_read;
	Tango::DevDouble	*attr_run_timeout_read;
	Tango::DevLong	*attr_firmware_revision_read;
	Tango::DevLong	*attr_driver_version_read;
	Tango::DevLong	*attr_board_serial_read;
	Tango::DevDouble	*attr_bin_size_read;
	Tango::DevULong64	*attr_CH0_Timestamps_read;
	Tango::DevULong64	*attr_CH1_Timestamps_read;
	Tango::DevULong64	*attr_CH2_Timestamps_read;
	Tango::DevULong64	*attr_CH3_Timestamps_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	XTDC4(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	XTDC4(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	XTDC4(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~XTDC4() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : XTDC4::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : XTDC4::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute error_code related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_error_code(Tango::Attribute &attr);
	virtual bool is_error_code_allowed(Tango::AttReqType type);
/**
 *	Attribute error_message related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
	virtual void read_error_message(Tango::Attribute &attr);
	virtual bool is_error_message_allowed(Tango::AttReqType type);
/**
 *	Attribute device_type related methods
 *	Description: For xTDC4, the device type is 6
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Scalar
 */
	virtual void read_device_type(Tango::Attribute &attr);
	virtual bool is_device_type_allowed(Tango::AttReqType type);
/**
 *	Attribute START_RISING related methods
 *	Description: Trigger START on rising of falling edge
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_START_RISING(Tango::Attribute &attr);
	virtual void write_START_RISING(Tango::WAttribute &attr);
	virtual bool is_START_RISING_allowed(Tango::AttReqType type);
/**
 *	Attribute START_DC_OFFSET related methods
 *	Description: DC threshold of START input
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_START_DC_OFFSET(Tango::Attribute &attr);
	virtual void write_START_DC_OFFSET(Tango::WAttribute &attr);
	virtual bool is_START_DC_OFFSET_allowed(Tango::AttReqType type);
/**
 *	Attribute CH0_ENABLED related methods
 *	Description: Enable input
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_CH0_ENABLED(Tango::Attribute &attr);
	virtual void write_CH0_ENABLED(Tango::WAttribute &attr);
	virtual bool is_CH0_ENABLED_allowed(Tango::AttReqType type);
/**
 *	Attribute CH0_RISING related methods
 *	Description: Trigger input on rising of falling edge
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_CH0_RISING(Tango::Attribute &attr);
	virtual void write_CH0_RISING(Tango::WAttribute &attr);
	virtual bool is_CH0_RISING_allowed(Tango::AttReqType type);
/**
 *	Attribute CH0_DC_OFFSET related methods
 *	Description: DC threshold of input
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_CH0_DC_OFFSET(Tango::Attribute &attr);
	virtual void write_CH0_DC_OFFSET(Tango::WAttribute &attr);
	virtual bool is_CH0_DC_OFFSET_allowed(Tango::AttReqType type);
/**
 *	Attribute CH1_ENABLED related methods
 *	Description: Enable input
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_CH1_ENABLED(Tango::Attribute &attr);
	virtual void write_CH1_ENABLED(Tango::WAttribute &attr);
	virtual bool is_CH1_ENABLED_allowed(Tango::AttReqType type);
/**
 *	Attribute CH1_RISING related methods
 *	Description: Trigger input on rising of falling edge
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_CH1_RISING(Tango::Attribute &attr);
	virtual void write_CH1_RISING(Tango::WAttribute &attr);
	virtual bool is_CH1_RISING_allowed(Tango::AttReqType type);
/**
 *	Attribute CH1_DC_OFFSET related methods
 *	Description: DC threshold of input
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_CH1_DC_OFFSET(Tango::Attribute &attr);
	virtual void write_CH1_DC_OFFSET(Tango::WAttribute &attr);
	virtual bool is_CH1_DC_OFFSET_allowed(Tango::AttReqType type);
/**
 *	Attribute CH2_ENABLED related methods
 *	Description: Enable input
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_CH2_ENABLED(Tango::Attribute &attr);
	virtual void write_CH2_ENABLED(Tango::WAttribute &attr);
	virtual bool is_CH2_ENABLED_allowed(Tango::AttReqType type);
/**
 *	Attribute CH2_RISING related methods
 *	Description: Trigger input on rising of falling edge
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_CH2_RISING(Tango::Attribute &attr);
	virtual void write_CH2_RISING(Tango::WAttribute &attr);
	virtual bool is_CH2_RISING_allowed(Tango::AttReqType type);
/**
 *	Attribute CH2_DC_OFFSET related methods
 *	Description: DC threshold of input
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_CH2_DC_OFFSET(Tango::Attribute &attr);
	virtual void write_CH2_DC_OFFSET(Tango::WAttribute &attr);
	virtual bool is_CH2_DC_OFFSET_allowed(Tango::AttReqType type);
/**
 *	Attribute CH3_ENABLED related methods
 *	Description: Enable input
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_CH3_ENABLED(Tango::Attribute &attr);
	virtual void write_CH3_ENABLED(Tango::WAttribute &attr);
	virtual bool is_CH3_ENABLED_allowed(Tango::AttReqType type);
/**
 *	Attribute CH3_RISING related methods
 *	Description: Trigger input on rising of falling edge
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_CH3_RISING(Tango::Attribute &attr);
	virtual void write_CH3_RISING(Tango::WAttribute &attr);
	virtual bool is_CH3_RISING_allowed(Tango::AttReqType type);
/**
 *	Attribute CH3_DC_OFFSET related methods
 *	Description: DC threshold of input
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_CH3_DC_OFFSET(Tango::Attribute &attr);
	virtual void write_CH3_DC_OFFSET(Tango::WAttribute &attr);
	virtual bool is_CH3_DC_OFFSET_allowed(Tango::AttReqType type);
/**
 *	Attribute TW_START related methods
 *	Description: Timestamps smaller than TW_START will not be recorded
 *
 *	Data type:	Tango::DevLong64
 *	Attr type:	Scalar
 */
	virtual void read_TW_START(Tango::Attribute &attr);
	virtual void write_TW_START(Tango::WAttribute &attr);
	virtual bool is_TW_START_allowed(Tango::AttReqType type);
/**
 *	Attribute TW_END related methods
 *	Description: Timestamps larger than TW_END will not be recorded
 *
 *	Data type:	Tango::DevLong64
 *	Attr type:	Scalar
 */
	virtual void read_TW_END(Tango::Attribute &attr);
	virtual void write_TW_END(Tango::WAttribute &attr);
	virtual bool is_TW_END_allowed(Tango::AttReqType type);
/**
 *	Attribute config_changed related methods
 *	Description: 
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_config_changed(Tango::Attribute &attr);
	virtual bool is_config_changed_allowed(Tango::AttReqType type);
/**
 *	Attribute start_trigger_generator related methods
 *	Description: Whether to use an internal trigger generator. Frequency controlled by another attribute. Currently hardcoded to 13.2 ns width positive TTL logic. If TRUE, START becomes an output
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_start_trigger_generator(Tango::Attribute &attr);
	virtual void write_start_trigger_generator(Tango::WAttribute &attr);
	virtual bool is_start_trigger_generator_allowed(Tango::AttReqType type);
/**
 *	Attribute last_run_valid_starts related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_last_run_valid_starts(Tango::Attribute &attr);
	virtual bool is_last_run_valid_starts_allowed(Tango::AttReqType type);
/**
 *	Attribute last_run_empty_starts related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_last_run_empty_starts(Tango::Attribute &attr);
	virtual bool is_last_run_empty_starts_allowed(Tango::AttReqType type);
/**
 *	Attribute last_run_hits related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_last_run_hits(Tango::Attribute &attr);
	virtual bool is_last_run_hits_allowed(Tango::AttReqType type);
/**
 *	Attribute last_run_start_errors related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_last_run_start_errors(Tango::Attribute &attr);
	virtual bool is_last_run_start_errors_allowed(Tango::AttReqType type);
/**
 *	Attribute start_trigger_generator_frequency related methods
 *	Description: Frequency of internal trigger, in Hz
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_start_trigger_generator_frequency(Tango::Attribute &attr);
	virtual void write_start_trigger_generator_frequency(Tango::WAttribute &attr);
	virtual bool is_start_trigger_generator_frequency_allowed(Tango::AttReqType type);
/**
 *	Attribute run_timeout related methods
 *	Description: The acquisition run timeout. The timer is started by the first start pulse. To stop on timeout it requires at least one start pulse to arrive after timeout elapsed. 
 *               The device might still be busy for approx 100-200ms after that, but no timestamps are recorded.
 *               Set run_timeout to zero for infinite run
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_run_timeout(Tango::Attribute &attr);
	virtual void write_run_timeout(Tango::WAttribute &attr);
	virtual bool is_run_timeout_allowed(Tango::AttReqType type);
/**
 *	Attribute firmware_revision related methods
 *	Description: Revision number of the FPGA configuration.
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_firmware_revision(Tango::Attribute &attr);
	virtual bool is_firmware_revision_allowed(Tango::AttReqType type);
/**
 *	Attribute driver_version related methods
 *	Description: Encoded version number.
 *               The lower three bytes contain a triple level hierarchy of version numbers, e.g. 0x010103 encodes
 *               version 1.1.3.
 *               A change in the first digit generally requires a recompilation of user applications. Change in the
 *               second digit denote significant improvements or changes that don't break compatibility and the
 *               third digit changes with minor bug fixes and similar updates.
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_driver_version(Tango::Attribute &attr);
	virtual bool is_driver_version_allowed(Tango::AttReqType type);
/**
 *	Attribute board_serial related methods
 *	Description: Serial number.
 *               With year and running number in 8.24 format. The number is identical to the one printed on
 *               the silvery sticker on the board.
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_board_serial(Tango::Attribute &attr);
	virtual bool is_board_serial_allowed(Tango::AttReqType type);
/**
 *	Attribute bin_size related methods
 *	Description: Bin size (in ps) of the measured TDC data. The TDC main clock is running at
 *               a frequency of 76.8 GHz resulting in a bin size of about 13.0208ps.
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_bin_size(Tango::Attribute &attr);
	virtual bool is_bin_size_allowed(Tango::AttReqType type);
/**
 *	Attribute CH0_Timestamps related methods
 *	Description: 
 *
 *	Data type:	Tango::DevULong64
 *	Attr type:	Spectrum max = 1400000
 */
	virtual void read_CH0_Timestamps(Tango::Attribute &attr);
	virtual bool is_CH0_Timestamps_allowed(Tango::AttReqType type);
/**
 *	Attribute CH1_Timestamps related methods
 *	Description: 
 *
 *	Data type:	Tango::DevULong64
 *	Attr type:	Spectrum max = 1400000
 */
	virtual void read_CH1_Timestamps(Tango::Attribute &attr);
	virtual bool is_CH1_Timestamps_allowed(Tango::AttReqType type);
/**
 *	Attribute CH2_Timestamps related methods
 *	Description: 
 *
 *	Data type:	Tango::DevULong64
 *	Attr type:	Spectrum max = 1400000
 */
	virtual void read_CH2_Timestamps(Tango::Attribute &attr);
	virtual bool is_CH2_Timestamps_allowed(Tango::AttReqType type);
/**
 *	Attribute CH3_Timestamps related methods
 *	Description: 
 *
 *	Data type:	Tango::DevULong64
 *	Attr type:	Spectrum max = 1400000
 */
	virtual void read_CH3_Timestamps(Tango::Attribute &attr);
	virtual bool is_CH3_Timestamps_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : XTDC4::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command Start related method
	 *	Description: Starts collecting data. Will fill the DMA memory until stop is called.
	 *
	 */
	virtual void start();
	virtual bool is_Start_allowed(const CORBA::Any &any);
	/**
	 *	Command Stop related method
	 *	Description: Stops collecting data
	 *
	 */
	virtual void stop();
	virtual bool is_Stop_allowed(const CORBA::Any &any);
	/**
	 *	Command Off related method
	 *	Description: Releases the xTDC4, for example to be used locally. To regain it back, call Init
	 *
	 */
	virtual void off();
	virtual bool is_Off_allowed(const CORBA::Any &any);
	/**
	 *	Command apply_config related method
	 *	Description: 
	 *
	 */
	virtual void apply_config();
	virtual bool is_apply_config_allowed(const CORBA::Any &any);
	/**
	 *	Command Clear related method
	 *	Description: Clear all timestamps in buffer.
	 *
	 */
	virtual void clear();
	virtual bool is_Clear_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : XTDC4::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(XTDC4::Additional Method prototypes) ENABLED START -----*/

	void poller_thread(); // this function is run in a separate thread continuously checking for data when running
	void run_poller_thread(); // this is to run the thread above

	// insert and remove datachunks to/from queue
	void push_datachunks(datachunk * current_chunk_array[]);
	void prepare_channel_timestamps_to_send(unsigned char channel, Tango::DevULong64 *attr_CH_Timestamps_read, unsigned long * number_of_timestamps_prepared);
	void flush_timestamps_as_event();
/*----- PROTECTED REGION END -----*/	//	XTDC4::Additional Method prototypes
};

/*----- PROTECTED REGION ID(XTDC4::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	XTDC4::Additional Classes Definitions

}	//	End of namespace

#endif   //	XTDC4_H
