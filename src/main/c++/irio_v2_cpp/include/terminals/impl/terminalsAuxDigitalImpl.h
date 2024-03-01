#pragma once

#include <terminals/impl/terminalsBaseImpl.h>

namespace iriov2 {
/**
 * Class implementing the auxiliary digital
 * functionality
 *
 * @ingroup Terminals
 */
class TerminalsAuxDigitalImpl: public TerminalsBaseImpl {
public:
	TerminalsAuxDigitalImpl(
			const bfp::BFP &parsedBitfile,
			const NiFpga_Session &session,
			const Platform &platform);

	bool getAuxDI(const std::uint32_t n) const;

	bool getAuxDO(const std::uint32_t n) const;

	size_t getNumAuxDI() const;

	size_t getNumAuxDO() const;

	void setAuxDO(const std::uint32_t n, const bool value) const;

private:
	std::unordered_map<std::uint32_t, const std::uint32_t> m_mapAuxDI;
	std::unordered_map<std::uint32_t, const std::uint32_t> m_mapAuxDO;

};

}