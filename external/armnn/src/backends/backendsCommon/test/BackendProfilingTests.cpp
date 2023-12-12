//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "CounterDirectory.hpp"
#include "CounterIdMap.hpp"
#include "Holder.hpp"
#include "MockBackend.hpp"
#include "MockBackendId.hpp"
#include "PeriodicCounterCapture.hpp"
#include "PeriodicCounterSelectionCommandHandler.hpp"
#include "ProfilingStateMachine.hpp"
#include "ProfilingUtils.hpp"
#include "RequestCounterDirectoryCommandHandler.hpp"

#include <test/TestUtils.hpp>

#include <armnn/utility/IgnoreUnused.hpp>
#include <armnn/BackendId.hpp>
#include <armnn/Logging.hpp>
#include <armnn/profiling/ISendTimelinePacket.hpp>

#include <boost/test/unit_test.hpp>
#include <vector>

#include <cstdint>
#include <limits>
#include <backends/BackendProfiling.hpp>

using namespace armnn::profiling;

class ReadCounterVals : public IReadCounterValues
{
    virtual bool IsCounterRegistered(uint16_t counterUid) const override
    {
        return (counterUid > 4 && counterUid < 11);
    }
    virtual uint16_t GetCounterCount() const override
    {
        return 1;
    }
    virtual uint32_t GetAbsoluteCounterValue(uint16_t counterUid) const override
    {
        return counterUid;
    }
    virtual uint32_t GetDeltaCounterValue(uint16_t counterUid) override
    {
        return counterUid;
    }
};

class MockBackendSendCounterPacket : public ISendCounterPacket
{
public:
    using IndexValuePairsVector = std::vector<CounterValue>;

    /// Create and write a StreamMetaDataPacket in the buffer
    virtual void SendStreamMetaDataPacket() {}

    /// Create and write a CounterDirectoryPacket from the parameters to the buffer.
    virtual void SendCounterDirectoryPacket(const ICounterDirectory& counterDirectory)
    {
        armnn::IgnoreUnused(counterDirectory);
    }

    /// Create and write a PeriodicCounterCapturePacket from the parameters to the buffer.
    virtual void SendPeriodicCounterCapturePacket(uint64_t timestamp, const IndexValuePairsVector& values)
    {
        m_timestamps.emplace_back(Timestamp{timestamp, values});
    }

    /// Create and write a PeriodicCounterSelectionPacket from the parameters to the buffer.
    virtual void SendPeriodicCounterSelectionPacket(uint32_t capturePeriod,
                                                    const std::vector<uint16_t>& selectedCounterIds)
    {
        armnn::IgnoreUnused(capturePeriod);
        armnn::IgnoreUnused(selectedCounterIds);
    }

    std::vector<Timestamp> GetTimestamps()
    {
        return  m_timestamps;
    }

    void ClearTimestamps()
    {
        m_timestamps.clear();
    }

private:
    std::vector<Timestamp> m_timestamps;
};

arm::pipe::Packet PacketWriter(uint32_t period, std::vector<uint16_t> countervalues)
{
    const uint32_t packetId = 0x40000;
    uint32_t offset = 0;
    uint32_t dataLength = static_cast<uint32_t>(4 + countervalues.size() * 2);
    std::unique_ptr<unsigned char[]> uniqueData = std::make_unique<unsigned char[]>(dataLength);
    unsigned char* data1                        = reinterpret_cast<unsigned char*>(uniqueData.get());

    WriteUint32(data1, offset, period);
    offset += 4;
    for (auto countervalue : countervalues)
    {
        WriteUint16(data1, offset, countervalue);
        offset += 2;
    }

    return {packetId, dataLength, uniqueData};
}

BOOST_AUTO_TEST_SUITE(BackendProfilingTestSuite)

BOOST_AUTO_TEST_CASE(BackendProfilingCounterRegisterMockBackendTest)
{
    // Reset the profiling service to the uninitialized state
    armnn::IRuntime::CreationOptions options;
    options.m_ProfilingOptions.m_EnableProfiling = true;

    armnn::MockBackendInitialiser initialiser;
    // Create a runtime
    armnn::Runtime runtime(options);

    unsigned int shiftedId = 0;

#if defined(ETHOSN_SUPPORT_ENABLED)
    // Shift the id as ETHOSN is enabled.
    shiftedId = 4;
#endif

    // Check if the MockBackends 3 dummy counters {0, 1, 2-5 (four cores)} are registered
    armnn::BackendId mockId = armnn::MockBackendId();
    const armnn::profiling::ICounterMappings& counterMap = GetProfilingService(&runtime).GetCounterMappings();
    BOOST_CHECK(counterMap.GetGlobalId(0, mockId) == 5 + shiftedId);
    BOOST_CHECK(counterMap.GetGlobalId(1, mockId) == 6 + shiftedId);
    BOOST_CHECK(counterMap.GetGlobalId(2, mockId) == 7 + shiftedId);
    BOOST_CHECK(counterMap.GetGlobalId(3, mockId) == 8 + shiftedId);
    BOOST_CHECK(counterMap.GetGlobalId(4, mockId) == 9 + shiftedId);
    BOOST_CHECK(counterMap.GetGlobalId(5, mockId) == 10 + shiftedId);
    options.m_ProfilingOptions.m_EnableProfiling = false;
    GetProfilingService(&runtime).ResetExternalProfilingOptions(options.m_ProfilingOptions, true);
}

BOOST_AUTO_TEST_CASE(TestBackendCounters)
{
    Holder holder;
    arm::pipe::PacketVersionResolver packetVersionResolver;
    ProfilingStateMachine stateMachine;
    ReadCounterVals readCounterVals;
    CounterIdMap counterIdMap;
    MockBackendSendCounterPacket sendCounterPacket;

    const armnn::BackendId cpuAccId(armnn::Compute::CpuAcc);
    const armnn::BackendId gpuAccId(armnn::Compute::GpuAcc);

    armnn::IRuntime::CreationOptions options;
    options.m_ProfilingOptions.m_EnableProfiling = true;

    armnn::profiling::ProfilingService profilingService;

    std::unique_ptr<armnn::profiling::IBackendProfiling> cpuBackendProfilingPtr =
            std::make_unique<BackendProfiling>(options, profilingService, cpuAccId);
    std::unique_ptr<armnn::profiling::IBackendProfiling> gpuBackendProfilingPtr =
            std::make_unique<BackendProfiling>(options, profilingService, gpuAccId);

    std::shared_ptr<armnn::profiling::IBackendProfilingContext> cpuProfilingContextPtr =
            std::make_shared<armnn::MockBackendProfilingContext>(cpuBackendProfilingPtr);
    std::shared_ptr<armnn::profiling::IBackendProfilingContext> gpuProfilingContextPtr =
            std::make_shared<armnn::MockBackendProfilingContext>(gpuBackendProfilingPtr);

    std::unordered_map<armnn::BackendId,
            std::shared_ptr<armnn::profiling::IBackendProfilingContext>> backendProfilingContexts;

    backendProfilingContexts[cpuAccId] = cpuProfilingContextPtr;
    backendProfilingContexts[gpuAccId] = gpuProfilingContextPtr;

    uint16_t globalId = 5;

    counterIdMap.RegisterMapping(globalId++, 0, cpuAccId);
    counterIdMap.RegisterMapping(globalId++, 1, cpuAccId);
    counterIdMap.RegisterMapping(globalId++, 2, cpuAccId);

    counterIdMap.RegisterMapping(globalId++, 0, gpuAccId);
    counterIdMap.RegisterMapping(globalId++, 1, gpuAccId);
    counterIdMap.RegisterMapping(globalId++, 2, gpuAccId);

    backendProfilingContexts[cpuAccId] = cpuProfilingContextPtr;
    backendProfilingContexts[gpuAccId] = gpuProfilingContextPtr;

    PeriodicCounterCapture periodicCounterCapture(holder, sendCounterPacket, readCounterVals,
                                                  counterIdMap, backendProfilingContexts);

    uint16_t maxArmnnCounterId = 4;

    PeriodicCounterSelectionCommandHandler periodicCounterSelectionCommandHandler(0,
                                                  4,
                                                  packetVersionResolver.ResolvePacketVersion(0, 4).GetEncodedValue(),
                                                  backendProfilingContexts,
                                                  counterIdMap,
                                                  holder,
                                                  maxArmnnCounterId,
                                                  periodicCounterCapture,
                                                  readCounterVals,
                                                  sendCounterPacket,
                                                  stateMachine);

    stateMachine.TransitionToState(ProfilingState::NotConnected);
    stateMachine.TransitionToState(ProfilingState::WaitingForAck);
    stateMachine.TransitionToState(ProfilingState::Active);

    uint32_t period = 12345u;

    std::vector<uint16_t> cpuCounters{5, 6, 7};
    std::vector<uint16_t> gpuCounters{8, 9, 10};

    // Request only gpu counters
    periodicCounterSelectionCommandHandler(PacketWriter(period, gpuCounters));
    periodicCounterCapture.Stop();

    std::set<armnn::BackendId> activeIds = holder.GetCaptureData().GetActiveBackends();
    BOOST_CHECK(activeIds.size() == 1);
    BOOST_CHECK(activeIds.find(gpuAccId) != activeIds.end());

    std::vector<Timestamp> recievedTimestamp = sendCounterPacket.GetTimestamps();

    BOOST_CHECK(recievedTimestamp[0].timestamp == period);
    BOOST_CHECK(recievedTimestamp.size() == 1);
    BOOST_CHECK(recievedTimestamp[0].counterValues.size() == gpuCounters.size());
    for (unsigned long i=0; i< gpuCounters.size(); ++i)
    {
        BOOST_CHECK(recievedTimestamp[0].counterValues[i].counterId == gpuCounters[i]);
        BOOST_CHECK(recievedTimestamp[0].counterValues[i].counterValue == i + 1u);
    }
    sendCounterPacket.ClearTimestamps();

    // Request only cpu counters
    periodicCounterSelectionCommandHandler(PacketWriter(period, cpuCounters));
    periodicCounterCapture.Stop();

    activeIds = holder.GetCaptureData().GetActiveBackends();
    BOOST_CHECK(activeIds.size() == 1);
    BOOST_CHECK(activeIds.find(cpuAccId) != activeIds.end());

    recievedTimestamp = sendCounterPacket.GetTimestamps();

    BOOST_CHECK(recievedTimestamp[0].timestamp == period);
    BOOST_CHECK(recievedTimestamp.size() == 1);
    BOOST_CHECK(recievedTimestamp[0].counterValues.size() == cpuCounters.size());
    for (unsigned long i=0; i< cpuCounters.size(); ++i)
    {
        BOOST_CHECK(recievedTimestamp[0].counterValues[i].counterId == cpuCounters[i]);
        BOOST_CHECK(recievedTimestamp[0].counterValues[i].counterValue == i + 1u);
    }
    sendCounterPacket.ClearTimestamps();

    // Request combination of cpu & gpu counters with new period
    period = 12222u;
    periodicCounterSelectionCommandHandler(PacketWriter(period, {cpuCounters[0], gpuCounters[2],
                                                                 gpuCounters[1], cpuCounters[1], gpuCounters[0]}));
    periodicCounterCapture.Stop();

    activeIds = holder.GetCaptureData().GetActiveBackends();
    BOOST_CHECK(activeIds.size() == 2);
    BOOST_CHECK(activeIds.find(cpuAccId) != activeIds.end());
    BOOST_CHECK(activeIds.find(gpuAccId) != activeIds.end());

    recievedTimestamp = sendCounterPacket.GetTimestamps();

    BOOST_CHECK(recievedTimestamp[0].timestamp == period);
    BOOST_CHECK(recievedTimestamp[1].timestamp == period);

    BOOST_CHECK(recievedTimestamp.size() == 2);
    BOOST_CHECK(recievedTimestamp[0].counterValues.size() == 2);
    BOOST_CHECK(recievedTimestamp[1].counterValues.size() == gpuCounters.size());

    BOOST_CHECK(recievedTimestamp[0].counterValues[0].counterId == cpuCounters[0]);
    BOOST_CHECK(recievedTimestamp[0].counterValues[0].counterValue == 1u);
    BOOST_CHECK(recievedTimestamp[0].counterValues[1].counterId == cpuCounters[1]);
    BOOST_CHECK(recievedTimestamp[0].counterValues[1].counterValue == 2u);

    for (unsigned long i=0; i< gpuCounters.size(); ++i)
    {
        BOOST_CHECK(recievedTimestamp[1].counterValues[i].counterId == gpuCounters[i]);
        BOOST_CHECK(recievedTimestamp[1].counterValues[i].counterValue == i + 1u);
    }

    sendCounterPacket.ClearTimestamps();

    // Request all counters
    std::vector<uint16_t> counterValues;
    counterValues.insert(counterValues.begin(), cpuCounters.begin(), cpuCounters.end());
    counterValues.insert(counterValues.begin(), gpuCounters.begin(), gpuCounters.end());

    periodicCounterSelectionCommandHandler(PacketWriter(period, counterValues));
    periodicCounterCapture.Stop();

    activeIds = holder.GetCaptureData().GetActiveBackends();
    BOOST_CHECK(activeIds.size() == 2);
    BOOST_CHECK(activeIds.find(cpuAccId) != activeIds.end());
    BOOST_CHECK(activeIds.find(gpuAccId) != activeIds.end());

    recievedTimestamp = sendCounterPacket.GetTimestamps();

    BOOST_CHECK(recievedTimestamp[0].counterValues.size() == cpuCounters.size());
    for (unsigned long i=0; i< cpuCounters.size(); ++i)
    {
        BOOST_CHECK(recievedTimestamp[0].counterValues[i].counterId == cpuCounters[i]);
        BOOST_CHECK(recievedTimestamp[0].counterValues[i].counterValue == i + 1u);
    }

    BOOST_CHECK(recievedTimestamp[1].counterValues.size() == gpuCounters.size());
    for (unsigned long i=0; i< gpuCounters.size(); ++i)
    {
        BOOST_CHECK(recievedTimestamp[1].counterValues[i].counterId == gpuCounters[i]);
        BOOST_CHECK(recievedTimestamp[1].counterValues[i].counterValue == i + 1u);
    }
    sendCounterPacket.ClearTimestamps();

    // Request random counters with duplicates and invalid counters
    counterValues = {0, 0, 200, cpuCounters[2], gpuCounters[0],3 ,30, cpuCounters[0],cpuCounters[2], gpuCounters[1], 3,
                     90, 0, 30, gpuCounters[0], gpuCounters[0]};

    periodicCounterSelectionCommandHandler(PacketWriter(period, counterValues));
    periodicCounterCapture.Stop();

    activeIds = holder.GetCaptureData().GetActiveBackends();
    BOOST_CHECK(activeIds.size() == 2);
    BOOST_CHECK(activeIds.find(cpuAccId) != activeIds.end());
    BOOST_CHECK(activeIds.find(gpuAccId) != activeIds.end());

    recievedTimestamp = sendCounterPacket.GetTimestamps();

    BOOST_CHECK(recievedTimestamp.size() == 2);

    BOOST_CHECK(recievedTimestamp[0].counterValues.size() == 2);

    BOOST_CHECK(recievedTimestamp[0].counterValues[0].counterId == cpuCounters[0]);
    BOOST_CHECK(recievedTimestamp[0].counterValues[0].counterValue == 1u);
    BOOST_CHECK(recievedTimestamp[0].counterValues[1].counterId == cpuCounters[2]);
    BOOST_CHECK(recievedTimestamp[0].counterValues[1].counterValue == 3u);

    BOOST_CHECK(recievedTimestamp[1].counterValues.size() == 2);

    BOOST_CHECK(recievedTimestamp[1].counterValues[0].counterId == gpuCounters[0]);
    BOOST_CHECK(recievedTimestamp[1].counterValues[0].counterValue == 1u);
    BOOST_CHECK(recievedTimestamp[1].counterValues[1].counterId == gpuCounters[1]);
    BOOST_CHECK(recievedTimestamp[1].counterValues[1].counterValue == 2u);

    sendCounterPacket.ClearTimestamps();

    // Request no counters
    periodicCounterSelectionCommandHandler(PacketWriter(period, {}));
    periodicCounterCapture.Stop();

    activeIds = holder.GetCaptureData().GetActiveBackends();
    BOOST_CHECK(activeIds.size() == 0);

    recievedTimestamp = sendCounterPacket.GetTimestamps();
    BOOST_CHECK(recievedTimestamp.size() == 0);

    sendCounterPacket.ClearTimestamps();

    // Request period of zero
    periodicCounterSelectionCommandHandler(PacketWriter(0, counterValues));
    periodicCounterCapture.Stop();

    activeIds = holder.GetCaptureData().GetActiveBackends();
    BOOST_CHECK(activeIds.size() == 0);

    recievedTimestamp = sendCounterPacket.GetTimestamps();
    BOOST_CHECK(recievedTimestamp.size() == 0);
}

BOOST_AUTO_TEST_CASE(TestBackendCounterLogging)
{
    std::stringstream ss;

    struct StreamRedirector
    {
    public:
        StreamRedirector(std::ostream &stream, std::streambuf *newStreamBuffer)
                : m_Stream(stream), m_BackupBuffer(m_Stream.rdbuf(newStreamBuffer))
        {}

        ~StreamRedirector()
        { m_Stream.rdbuf(m_BackupBuffer); }

    private:
        std::ostream &m_Stream;
        std::streambuf *m_BackupBuffer;
    };

    Holder holder;
    arm::pipe::PacketVersionResolver packetVersionResolver;
    ProfilingStateMachine stateMachine;
    ReadCounterVals readCounterVals;
    StreamRedirector redirect(std::cout, ss.rdbuf());
    CounterIdMap counterIdMap;
    MockBackendSendCounterPacket sendCounterPacket;

    const armnn::BackendId cpuAccId(armnn::Compute::CpuAcc);
    const armnn::BackendId gpuAccId(armnn::Compute::GpuAcc);

    armnn::IRuntime::CreationOptions options;
    options.m_ProfilingOptions.m_EnableProfiling = true;

    armnn::profiling::ProfilingService profilingService;

    std::unique_ptr<armnn::profiling::IBackendProfiling> cpuBackendProfilingPtr =
            std::make_unique<BackendProfiling>(options, profilingService, cpuAccId);

    std::shared_ptr<armnn::profiling::IBackendProfilingContext> cpuProfilingContextPtr =
            std::make_shared<armnn::MockBackendProfilingContext>(cpuBackendProfilingPtr);

    std::unordered_map<armnn::BackendId,
            std::shared_ptr<armnn::profiling::IBackendProfilingContext>> backendProfilingContexts;

    uint16_t globalId = 5;
    counterIdMap.RegisterMapping(globalId, 0, cpuAccId);
    backendProfilingContexts[cpuAccId] = cpuProfilingContextPtr;

    PeriodicCounterCapture periodicCounterCapture(holder, sendCounterPacket, readCounterVals,
                                                  counterIdMap, backendProfilingContexts);

    uint16_t maxArmnnCounterId = 4;

    PeriodicCounterSelectionCommandHandler periodicCounterSelectionCommandHandler(0,
                                                  4,
                                                  packetVersionResolver.ResolvePacketVersion(0, 4).GetEncodedValue(),
                                                  backendProfilingContexts,
                                                  counterIdMap,
                                                  holder,
                                                  maxArmnnCounterId,
                                                  periodicCounterCapture,
                                                  readCounterVals,
                                                  sendCounterPacket,
                                                  stateMachine);

    stateMachine.TransitionToState(ProfilingState::NotConnected);
    stateMachine.TransitionToState(ProfilingState::WaitingForAck);
    stateMachine.TransitionToState(ProfilingState::Active);

    uint32_t period = 15939u;

    armnn::SetAllLoggingSinks(true, false, false);
    SetLogFilter(armnn::LogSeverity::Warning);
    periodicCounterSelectionCommandHandler(PacketWriter(period, {5}));
    periodicCounterCapture.Stop();
    SetLogFilter(armnn::LogSeverity::Fatal);

    BOOST_CHECK(ss.str().find("ActivateCounters example test error") != std::string::npos);
}

BOOST_AUTO_TEST_CASE(BackendProfilingContextGetSendTimelinePacket)
{
    // Reset the profiling service to the uninitialized state
    armnn::IRuntime::CreationOptions options;
    options.m_ProfilingOptions.m_EnableProfiling = true;
    armnn::profiling::ProfilingService profilingService;
    profilingService.ConfigureProfilingService(options.m_ProfilingOptions, true);

    armnn::MockBackendInitialiser initialiser;
    // Create a runtime. During this the mock backend will be registered and context returned.
    armnn::IRuntimePtr runtime(armnn::IRuntime::Create(options));
    armnn::MockBackendProfilingService mockProfilingService = armnn::MockBackendProfilingService::Instance();
    armnn::MockBackendProfilingContext *mockBackEndProfilingContext = mockProfilingService.GetContext();
    // Check that there is a valid context set.
    BOOST_CHECK(mockBackEndProfilingContext);
    armnn::IBackendInternal::IBackendProfilingPtr& backendProfilingIface =
        mockBackEndProfilingContext->GetBackendProfiling();
    BOOST_CHECK(backendProfilingIface);

    // Now for the meat of the test. We're just going to send a random packet and make sure there
    // are no exceptions or errors. The sending of packets is already tested in SendTimelinePacketTests.
    std::unique_ptr<armnn::profiling::ISendTimelinePacket> timelinePacket =
        backendProfilingIface->GetSendTimelinePacket();
    // Send TimelineEntityClassBinaryPacket
    const uint64_t entityBinaryPacketProfilingGuid = 123456u;
    timelinePacket->SendTimelineEntityBinaryPacket(entityBinaryPacketProfilingGuid);
    timelinePacket->Commit();

    // Reset the profiling servie after the test.
    options.m_ProfilingOptions.m_EnableProfiling = false;
    profilingService.ResetExternalProfilingOptions(options.m_ProfilingOptions, true);
}

BOOST_AUTO_TEST_CASE(GetProfilingGuidGenerator)
{
    // Reset the profiling service to the uninitialized state
    armnn::IRuntime::CreationOptions options;
    options.m_ProfilingOptions.m_EnableProfiling = true;

    armnn::MockBackendInitialiser initialiser;
    // Create a runtime. During this the mock backend will be registered and context returned.
    armnn::IRuntimePtr runtime(armnn::IRuntime::Create(options));
    armnn::MockBackendProfilingService mockProfilingService = armnn::MockBackendProfilingService::Instance();
    armnn::MockBackendProfilingContext *mockBackEndProfilingContext = mockProfilingService.GetContext();
    // Check that there is a valid context set.
    BOOST_CHECK(mockBackEndProfilingContext);
    armnn::IBackendInternal::IBackendProfilingPtr& backendProfilingIface =
        mockBackEndProfilingContext->GetBackendProfiling();
    BOOST_CHECK(backendProfilingIface);

    // Get the Guid generator and check the getting two Guid's results in the second being greater than the first.
    armnn::profiling::IProfilingGuidGenerator& guidGenerator = backendProfilingIface->GetProfilingGuidGenerator();
    const armnn::profiling::ProfilingDynamicGuid& firstGuid = guidGenerator.NextGuid();
    const armnn::profiling::ProfilingDynamicGuid& secondGuid = guidGenerator.NextGuid();
    BOOST_CHECK(secondGuid > firstGuid);

    // Reset the profiling servie after the test.
    options.m_ProfilingOptions.m_EnableProfiling = false;
}

BOOST_AUTO_TEST_SUITE_END()
