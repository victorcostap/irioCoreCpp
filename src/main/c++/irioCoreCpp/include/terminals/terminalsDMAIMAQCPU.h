#pragma once

#include "terminals/terminalsDMAIMAQ.h"

namespace irio {

/**
 * Class managing the resources used for DMA CPU IMAQ operations
 * 
 * @ingroup IMAQCPUTerminals
*/
class TerminalsDMAIMAQCPU: public TerminalsDMAIMAQ {
 public:
   /**
	 * Manages finding all the required
	 * DMA CPU IMAQ resources.
	 *
	 * @throw irio::errors::NiFpgaError Error occurred in an FPGA operation
	 *
	 * @param parserManager     Pointer to class managing parsing the bitfile
	 *                          and finding its resources
	 * @param session			NiFpga_Session to be used in NiFpga
	 * 							related functions
	 * @param platform			Platform that is using the terminals.
	 * 							Used to know the maximum number of terminals
	 * 							that can be found
	 */
    TerminalsDMAIMAQCPU(ParserManager *parserManager,
					    const NiFpga_Session &session,
                        const Platform &platform);
};

}  // namespace irio
