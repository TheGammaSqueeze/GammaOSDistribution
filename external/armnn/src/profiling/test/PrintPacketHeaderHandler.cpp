//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "PrintPacketHeaderHandler.hpp"

#include <iostream>
#include <sstream>

namespace armnn
{

namespace profiling
{

std::vector<uint32_t> PrintPacketHeaderHandler::GetHeadersAccepted()
{
    return std::vector<uint32_t>();
}

void PrintPacketHeaderHandler::HandlePacket(const arm::pipe::Packet& packet)
{
    std::stringstream ss;
    ss << "Handler Received Outgoing Packet [" << packet.GetPacketFamily() << ":" << packet.GetPacketId() << "]";
    ss << " Length [" << packet.GetLength() << "]" << std::endl;
    std::cout << ss.str() << std::endl;
};

} // namespace profiling

} // namespace armnn