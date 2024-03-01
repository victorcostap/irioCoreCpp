#include <terminals/terminalsDMADAQ.h>
#include <terminals/impl/terminalsDMADAQImpl.h>
#include <utils.h>
#include <errorsIrio.h>

namespace iriov2{

TerminalsDMADAQ::TerminalsDMADAQ(std::shared_ptr<TerminalsDMADAQImpl> impl) :
		TerminalsDMACommon(std::static_pointer_cast<TerminalsDMACommonImpl>(impl)) {
}

std::uint16_t TerminalsDMADAQ::getLengthBlock(const std::uint32_t &n) const {
	return std::static_pointer_cast<TerminalsDMADAQImpl>(m_impl)->getLengthBlock(n);

}

std::uint16_t TerminalsDMADAQ::getSamplingRate(const std::uint32_t &n) const {
	return std::static_pointer_cast<TerminalsDMADAQImpl>(m_impl)->getSamplingRate(n);
}

void TerminalsDMADAQ::setSamplingRate(
		const std::uint32_t &n,
		const std::uint16_t &samplingRate) const {

	std::static_pointer_cast<TerminalsDMADAQImpl>(m_impl)->setSamplingRate(n, samplingRate);
}
}