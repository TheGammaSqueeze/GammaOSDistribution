//
// Copyright © 2019 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "ProfilingStateMachine.hpp"

#include <common/include/CommandHandlerFunctor.hpp>
#include <common/include/Packet.hpp>

namespace armnn
{

namespace profiling
{

class PerJobCounterSelectionCommandHandler : public arm::pipe::CommandHandlerFunctor
{

public:
    PerJobCounterSelectionCommandHandler(uint32_t familyId,
                                         uint32_t packetId,
                                         uint32_t version,
                                         const ProfilingStateMachine& profilingStateMachine)
        : CommandHandlerFunctor(familyId, packetId, version)
        , m_StateMachine(profilingStateMachine)
    {}

    void operator()(const arm::pipe::Packet& packet) override;

private:
    const ProfilingStateMachine& m_StateMachine;
};

} // namespace profiling

} // namespace armnn

