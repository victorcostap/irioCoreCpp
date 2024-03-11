#pragma once

#include <profiles/profileBase.h>


namespace iriov2 {
/**
 * Profile with the terminals specific to cRIO devices.
 *
 * This class must be a extended by other profile classes,
 * should not be used by itself.
 *
 * @ingroup Profiles
 * @ingroup ProfilesCRIO
 * @ingroup cRIO
 */
class ProfileCRIO: virtual public ProfileBase {
 public:
	/**
	 * Constructor.
	 *
	 * Initializes terminals specific to cRIO
	 *
	 * @throw iriov2::errors::NiFpgaError	Error occurred in an FPGA operation
	 *
	 * @param parsedBitfile	Parsed bitfile
	 * @param session		NiFpga_Session to be used in NiFpga related functions
	 * @param id			Profile used
	 */
	ProfileCRIO(
			const bfp::BFP &parsedBitfile,
			const NiFpga_Session &session,
			const PROFILE_ID &id);

	TerminalscRIO cRIO() const override;

 private:
	TerminalscRIO m_cRIO;
};

}  // namespace iriov2
