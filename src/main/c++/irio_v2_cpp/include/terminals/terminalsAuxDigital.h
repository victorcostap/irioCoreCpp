#pragma once

#include <terminals/impl/terminalsAuxDigitalImpl.h>

namespace iriov2 {
/**
 * Class managing all terminals related to the
 * auxiliary digital functionality of the RIO device
 *
 * @ingroup Terminals
 */
class TerminalsAuxDigital {
public:
	/**
	 * Constructor.
	 * Manages finding the related auxiliary digital terminals
	 * in the parsed bitfile and reading their values from the FPGA
	 * if required
	 *
	 * @throw std::runtime_error	The combined number of found auxDI and
	 * auxDO terminals are greater than the number of auxiliary
	 * digital terminals supported by the platform
	 *
	 * @param parsedBitfile	Parsed bitfile with the analog terminals
	 * @param session		NiFpga_Session to be used in NiFpga related functions.
	 * @param platform		Platform that is using the terminals. Used to know the maximum number of terminals that can be found.
	 */
	TerminalsAuxDigital(
			const bfp::BFP &parsedBitfile,
			const NiFpga_Session &session,
			const Platform &platform);

	TerminalsAuxDigital(const TerminalsAuxDigital &other);

	/**
	 * Returns the value of an auxDI terminal.
	 *
	 * @throw iriov2::errors::NiFpgaError	Error occurred in an FPGA operation
	 * @throw iriov2::errors::ResourceNotFoundError Resource specified not found
	 *
	 * @param n	Number of the auxDI terminal to read
	 * @return	Value read from the auxDI terminal
	 */
	bool getAuxDI(const std::uint32_t n) const;

	/**
	 * Returns the value of an auxDO terminal.
	 *
	 * @throw iriov2::errors::NiFpgaError	Error occurred in an FPGA operation
	 * @throw iriov2::errors::ResourceNotFoundError Resource specified not found
	 *
	 * @param n	Number of the auxDO terminal to read
	 * @return	Value read from the auxDO terminal
	 */
	bool getAuxDO(const std::uint32_t n) const;

	/**
	 * Returns number of auxDI terminals found
	 *
	 * @return Number of auxDI terminals found
	 */
	size_t getNumAuxDI() const;

	/**
	 * Returns number of auxDO terminals found
	 *
	 * @return Number of auxDO terminals found
	 */
	size_t getNumAuxDO() const;

	/**
	 * Writes to a specific auxDO terminal a value
	 *
	 * @throw iriov2::errors::NiFpgaError	Error occurred in an FPGA operation
	 * @throw iriov2::errors::ResourceNotFoundError Resource specified not found
	 *
	 * @param n	Number of the auxDO terminal to write
	 * @param value	Value to write to the terminal
	 */
	void setAuxDO(const std::uint32_t n, const bool value) const;

private:
	std::shared_ptr<TerminalsAuxDigitalImpl> m_impl;
};

}
