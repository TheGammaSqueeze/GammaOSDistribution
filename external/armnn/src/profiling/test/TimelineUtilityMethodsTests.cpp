//
// Copyright © 2019 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "ProfilingMocks.hpp"
#include "ProfilingTestUtils.hpp"

#include <SendTimelinePacket.hpp>
#include <TimelineUtilityMethods.hpp>
#include <LabelsAndEventClasses.hpp>
#include <ProfilingService.hpp>

#include <memory>

#include <boost/test/unit_test.hpp>

using namespace armnn;
using namespace armnn::profiling;

BOOST_AUTO_TEST_SUITE(TimelineUtilityMethodsTests)

BOOST_AUTO_TEST_CASE(CreateTypedLabelTest)
{
    MockBufferManager mockBufferManager(1024);
    ProfilingService  profilingService;

    std::unique_ptr<ISendTimelinePacket> sendTimelinePacket = std::make_unique<SendTimelinePacket>(mockBufferManager);
    TimelineUtilityMethods timelineUtilityMethods(sendTimelinePacket);

    // Generate first guid to ensure that the named typed entity guid is not 0 on local single test.
    profilingService.NextGuid();

    ProfilingGuid entityGuid(123);
    const std::string entityName = "some entity";
    ProfilingStaticGuid labelTypeGuid(456);

    BOOST_CHECK_NO_THROW(timelineUtilityMethods.MarkEntityWithLabel(entityGuid, entityName, labelTypeGuid));

    // Commit all packets at once
    timelineUtilityMethods.Commit();

    // Get the readable buffer
    auto readableBuffer = mockBufferManager.GetReadableBuffer();
    BOOST_CHECK(readableBuffer != nullptr);
    unsigned int size = readableBuffer->GetSize();
    BOOST_CHECK(size == 76);
    const unsigned char* readableData = readableBuffer->GetReadableData();
    BOOST_CHECK(readableData != nullptr);

    // Utils
    unsigned int offset = 0;

    // Verify Header
    VerifyTimelineHeaderBinary(readableData, offset, 68);

    // First dataset sent: TimelineLabelBinaryPacket
    VerifyTimelineLabelBinaryPacketData(EmptyOptional(), entityName, readableData, offset);

    // Second dataset sent: TimelineRelationshipBinaryPacket
    VerifyTimelineRelationshipBinaryPacketData(ProfilingRelationshipType::LabelLink,
                                               EmptyOptional(),
                                               entityGuid,
                                               EmptyOptional(),
                                               labelTypeGuid,
                                               readableData,
                                               offset);

    // Mark the buffer as read
    mockBufferManager.MarkRead(readableBuffer);
}

BOOST_AUTO_TEST_CASE(SendWellKnownLabelsAndEventClassesTest)
{
    MockBufferManager mockBufferManager(1024);
    ProfilingService  profilingService;
    SendTimelinePacket sendTimelinePacket(mockBufferManager);

    BOOST_CHECK_NO_THROW(TimelineUtilityMethods::SendWellKnownLabelsAndEventClasses(sendTimelinePacket));

    // Get the readable buffer
    auto readableBuffer = mockBufferManager.GetReadableBuffer();
    BOOST_CHECK(readableBuffer != nullptr);
    unsigned int size = readableBuffer->GetSize();
    BOOST_TEST(size == 460);
    const unsigned char* readableData = readableBuffer->GetReadableData();
    BOOST_CHECK(readableData != nullptr);

    // Utils
    unsigned int offset = 0;

    // Verify Header
    VerifyTimelineHeaderBinary(readableData, offset, 452);

    // First "well-known" label: NAME
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::NAME_GUID,
                                        LabelsAndEventClasses::NAME_LABEL,
                                        readableData,
                                        offset);

    // Second "well-known" label: TYPE
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::TYPE_GUID,
                                        LabelsAndEventClasses::TYPE_LABEL,
                                        readableData,
                                        offset);

    // Third "well-known" label: INDEX
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::INDEX_GUID,
                                        LabelsAndEventClasses::INDEX_LABEL,
                                        readableData,
                                        offset);

    // Forth "well-known" label: BACKENDID
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::BACKENDID_GUID,
                                        LabelsAndEventClasses::BACKENDID_LABEL,
                                        readableData,
                                        offset);

    // Fifth "well-known" label: CHILD
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::CHILD_GUID,
                                        LabelsAndEventClasses::CHILD_LABEL,
                                        readableData,
                                        offset);

    // Sixth "well-known" label: EXECUTION_OF
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::EXECUTION_OF_GUID,
                                        LabelsAndEventClasses::EXECUTION_OF_LABEL,
                                        readableData,
                                        offset);

    // Seventh "well-known" label: PROCESS_ID_LABEL
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::PROCESS_ID_GUID,
                                        LabelsAndEventClasses::PROCESS_ID_LABEL,
                                        readableData,
                                        offset);

    // Well-known types
    // Layer
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::LAYER_GUID,
                                        LabelsAndEventClasses::LAYER,
                                        readableData,
                                        offset);

    // Workload
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::WORKLOAD_GUID,
                                        LabelsAndEventClasses::WORKLOAD,
                                        readableData,
                                        offset);

    // Network
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::NETWORK_GUID,
                                        LabelsAndEventClasses::NETWORK,
                                        readableData,
                                        offset);

    // Connection
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::CONNECTION_GUID,
                                        LabelsAndEventClasses::CONNECTION,
                                        readableData,
                                        offset);

    // Inference
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::INFERENCE_GUID,
                                        LabelsAndEventClasses::INFERENCE,
                                        readableData,
                                        offset);

    // Workload Execution
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::WORKLOAD_EXECUTION_GUID,
                                        LabelsAndEventClasses::WORKLOAD_EXECUTION,
                                        readableData,
                                        offset);

    // First "well-known" event class: START OF LIFE
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::ARMNN_PROFILING_SOL_EVENT_CLASS_NAME_GUID,
                                        LabelsAndEventClasses::ARMNN_PROFILING_SOL_EVENT_CLASS_NAME,
                                        readableData,
                                        offset);

    VerifyTimelineEventClassBinaryPacketData(LabelsAndEventClasses::ARMNN_PROFILING_SOL_EVENT_CLASS,
                                             LabelsAndEventClasses::ARMNN_PROFILING_SOL_EVENT_CLASS_NAME_GUID,
                                             readableData,
                                             offset);

    // Second "well-known" event class: END OF LIFE
    VerifyTimelineLabelBinaryPacketData(LabelsAndEventClasses::ARMNN_PROFILING_EOL_EVENT_CLASS_NAME_GUID,
                                        LabelsAndEventClasses::ARMNN_PROFILING_EOL_EVENT_CLASS_NAME,
                                        readableData,
                                        offset);

    VerifyTimelineEventClassBinaryPacketData(LabelsAndEventClasses::ARMNN_PROFILING_EOL_EVENT_CLASS,
                                             LabelsAndEventClasses::ARMNN_PROFILING_EOL_EVENT_CLASS_NAME_GUID,
                                             readableData,
                                             offset);

    // Mark the buffer as read
    mockBufferManager.MarkRead(readableBuffer);
}

BOOST_AUTO_TEST_CASE(CreateNamedTypedChildEntityTest)
{
    MockBufferManager mockBufferManager(1024);
    ProfilingService  profilingService;
    std::unique_ptr<ISendTimelinePacket> sendTimelinePacket = std::make_unique<SendTimelinePacket>(mockBufferManager);
    TimelineUtilityMethods timelineUtilityMethods(sendTimelinePacket);

    ProfilingDynamicGuid childEntityGuid(0);
    ProfilingGuid parentEntityGuid(123);
    const std::string entityName = "some entity";
    const std::string entityType = "some type";

    // Generate first guid to ensure that the named typed entity guid is not 0 on local single test.
    profilingService.NextGuid();

    BOOST_CHECK_THROW(timelineUtilityMethods.CreateNamedTypedChildEntity(parentEntityGuid, "", entityType),
                      InvalidArgumentException);
    BOOST_CHECK_THROW(timelineUtilityMethods.CreateNamedTypedChildEntity(parentEntityGuid, entityName, ""),
                      InvalidArgumentException);
    BOOST_CHECK_THROW(timelineUtilityMethods.CreateNamedTypedChildEntity(
        childEntityGuid, parentEntityGuid, "", entityType), InvalidArgumentException);
    BOOST_CHECK_THROW(timelineUtilityMethods.CreateNamedTypedChildEntity(
        childEntityGuid, parentEntityGuid, entityName, ""), InvalidArgumentException);

    BOOST_CHECK_NO_THROW(childEntityGuid = timelineUtilityMethods.CreateNamedTypedChildEntity(parentEntityGuid,
                                                                                              entityName,
                                                                                              entityType));
    BOOST_CHECK(childEntityGuid != ProfilingGuid(0));

    // Commit all packets at once
    timelineUtilityMethods.Commit();

    // Get the readable buffer
    auto readableBuffer = mockBufferManager.GetReadableBuffer();
    BOOST_CHECK(readableBuffer != nullptr);
    unsigned int size = readableBuffer->GetSize();
    BOOST_CHECK(size == 196);
    const unsigned char* readableData = readableBuffer->GetReadableData();
    BOOST_CHECK(readableData != nullptr);

    // Utils
    unsigned int offset = 0;

    // Verify Header
    VerifyTimelineHeaderBinary(readableData, offset, 188);

    // First dataset sent: TimelineEntityBinaryPacket
    VerifyTimelineEntityBinaryPacketData(EmptyOptional(), readableData, offset);

    // Second dataset sent: TimelineLabelBinaryPacket
    VerifyTimelineLabelBinaryPacketData(EmptyOptional(), entityName, readableData, offset);

    // Third dataset sent: TimelineRelationshipBinaryPacket
    VerifyTimelineRelationshipBinaryPacketData(ProfilingRelationshipType::LabelLink,
                                               EmptyOptional(),
                                               EmptyOptional(),
                                               EmptyOptional(),
                                               LabelsAndEventClasses::NAME_GUID,
                                               readableData,
                                               offset);

    // Fifth dataset sent: TimelineLabelBinaryPacket
    VerifyTimelineLabelBinaryPacketData(EmptyOptional(), entityType, readableData, offset);

    // Sixth dataset sent: TimelineRelationshipBinaryPacket
    VerifyTimelineRelationshipBinaryPacketData(ProfilingRelationshipType::LabelLink,
                                               EmptyOptional(),
                                               EmptyOptional(),
                                               EmptyOptional(),
                                               LabelsAndEventClasses::TYPE_GUID,
                                               readableData,
                                               offset);


    // Eighth dataset sent: TimelineRelationshipBinaryPacket
    VerifyTimelineRelationshipBinaryPacketData(ProfilingRelationshipType::RetentionLink,
                                               EmptyOptional(),
                                               parentEntityGuid,
                                               EmptyOptional(),
                                               EmptyOptional(),
                                               readableData,
                                               offset);

    // Mark the buffer as read
    mockBufferManager.MarkRead(readableBuffer);
}

BOOST_AUTO_TEST_CASE(DeclareLabelTest)
{
    MockBufferManager mockBufferManager(1024);
    ProfilingService  profilingService;
    std::unique_ptr<ISendTimelinePacket> sendTimelinePacket = std::make_unique<SendTimelinePacket>(mockBufferManager);
    TimelineUtilityMethods timelineUtilityMethods(sendTimelinePacket);

    // Generate first guid to ensure that the named typed entity guid is not 0 on local single test.
    profilingService.NextGuid();

    // Try declaring an invalid (empty) label
    BOOST_CHECK_THROW(timelineUtilityMethods.DeclareLabel(""), InvalidArgumentException);

    // Try declaring an invalid (wrong SWTrace format) label
    BOOST_CHECK_THROW(timelineUtilityMethods.DeclareLabel("inv@lid lab€l"), RuntimeException);

    // Declare a valid label
    const std::string labelName = "valid label";
    ProfilingGuid labelGuid = 0;
    BOOST_CHECK_NO_THROW(labelGuid = timelineUtilityMethods.DeclareLabel(labelName));
    BOOST_CHECK(labelGuid != ProfilingGuid(0));

    // Try adding the same label as before
    ProfilingGuid newLabelGuid = 0;
    BOOST_CHECK_NO_THROW(newLabelGuid = timelineUtilityMethods.DeclareLabel(labelName));
    BOOST_CHECK(newLabelGuid != ProfilingGuid(0));
    BOOST_CHECK(newLabelGuid == labelGuid);
}

BOOST_AUTO_TEST_CASE(CreateNameTypeEntityInvalidTest)
{
    MockBufferManager mockBufferManager(1024);
    ProfilingService  profilingService;
    std::unique_ptr<ISendTimelinePacket> sendTimelinePacket = std::make_unique<SendTimelinePacket>(mockBufferManager);
    TimelineUtilityMethods timelineUtilityMethods(sendTimelinePacket);

    // Invalid name
    BOOST_CHECK_THROW(timelineUtilityMethods.CreateNamedTypedEntity("", "Type"), InvalidArgumentException);

    // Invalid type
    BOOST_CHECK_THROW(timelineUtilityMethods.CreateNamedTypedEntity("Name", ""), InvalidArgumentException);

    ProfilingDynamicGuid guid = profilingService.NextGuid();

    // CreatedNamedTypedEntity with Guid - Invalid name
    BOOST_CHECK_THROW(timelineUtilityMethods.CreateNamedTypedEntity(guid, "", "Type"),
                      InvalidArgumentException);

    // CreatedNamedTypedEntity with Guid - Invalid type
    BOOST_CHECK_THROW(timelineUtilityMethods.CreateNamedTypedEntity(guid, "Name", ""),
                      InvalidArgumentException);

}

BOOST_AUTO_TEST_CASE(CreateNameTypeEntityTest)
{
    MockBufferManager mockBufferManager(1024);
    ProfilingService  profilingService;
    std::unique_ptr<ISendTimelinePacket> sendTimelinePacket = std::make_unique<SendTimelinePacket>(mockBufferManager);
    TimelineUtilityMethods timelineUtilityMethods(sendTimelinePacket);

    const std::string entityName = "Entity0";
    const std::string entityType = "Type0";

    // Generate first guid to ensure that the named typed entity guid is not 0 on local single test.
    profilingService.NextGuid();

    ProfilingDynamicGuid guid = timelineUtilityMethods.CreateNamedTypedEntity(entityName, entityType);
    BOOST_CHECK(guid != ProfilingGuid(0));

    // Commit all packets at once
    timelineUtilityMethods.Commit();

    // Get the readable buffer
    auto readableBuffer = mockBufferManager.GetReadableBuffer();
    BOOST_CHECK(readableBuffer != nullptr);
    unsigned int size = readableBuffer->GetSize();
    BOOST_CHECK(size == 148);
    const unsigned char* readableData = readableBuffer->GetReadableData();
    BOOST_CHECK(readableData != nullptr);

    // Utils
    unsigned int offset = 0;

    // Verify Header
    VerifyTimelineHeaderBinary(readableData, offset, 140);

    // First dataset sent: TimelineEntityBinaryPacket
    VerifyTimelineEntityBinaryPacketData(guid, readableData, offset);

    // Packets for Name Entity
    // First dataset sent: TimelineLabelBinaryPacket
    VerifyTimelineLabelBinaryPacketData(EmptyOptional(), entityName, readableData, offset);

    // Second dataset sent: TimelineRelationshipBinaryPacket
    VerifyTimelineRelationshipBinaryPacketData(ProfilingRelationshipType::LabelLink,
                                               EmptyOptional(),
                                               EmptyOptional(),
                                               EmptyOptional(),
                                               LabelsAndEventClasses::NAME_GUID,
                                               readableData,
                                               offset);

    // Packets for Type Entity
    // First dataset sent: TimelineLabelBinaryPacket
    VerifyTimelineLabelBinaryPacketData(EmptyOptional(), entityType, readableData, offset);

    // Second dataset sent: TimelineRelationshipBinaryPacket
    VerifyTimelineRelationshipBinaryPacketData(ProfilingRelationshipType::LabelLink,
                                               EmptyOptional(),
                                               EmptyOptional(),
                                               EmptyOptional(),
                                               LabelsAndEventClasses::TYPE_GUID,
                                               readableData,
                                               offset);


    // Mark the buffer as read
    mockBufferManager.MarkRead(readableBuffer);
}

BOOST_AUTO_TEST_CASE(RecordEventTest)
{
    MockBufferManager mockBufferManager(1024);
    ProfilingService  profilingService;
    std::unique_ptr<ISendTimelinePacket> sendTimelinePacket = std::make_unique<SendTimelinePacket>(mockBufferManager);
    TimelineUtilityMethods timelineUtilityMethods(sendTimelinePacket);
    // Generate first guid to ensure that the named typed entity guid is not 0 on local single test.
    profilingService.NextGuid();

    ProfilingGuid entityGuid(123);
    ProfilingStaticGuid eventClassGuid(456);
    ProfilingDynamicGuid eventGuid(0);
    BOOST_CHECK_NO_THROW(eventGuid = timelineUtilityMethods.RecordEvent(entityGuid, eventClassGuid));
    BOOST_CHECK(eventGuid != ProfilingGuid(0));

    // Commit all packets at once
    timelineUtilityMethods.Commit();

    // Get the readable buffer
    auto readableBuffer = mockBufferManager.GetReadableBuffer();
    BOOST_CHECK(readableBuffer != nullptr);
    unsigned int size = readableBuffer->GetSize();

    BOOST_CHECK(size == 68 + ThreadIdSize);

    const unsigned char* readableData = readableBuffer->GetReadableData();
    BOOST_CHECK(readableData != nullptr);

    // Utils
    unsigned int offset = 0;

    // Verify Header
    VerifyTimelineHeaderBinary(readableData, offset, 60 + ThreadIdSize);

    // First dataset sent: TimelineEntityBinaryPacket
    VerifyTimelineEventBinaryPacket(EmptyOptional(), EmptyOptional(), EmptyOptional(), readableData, offset);

    // Second dataset sent: TimelineRelationshipBinaryPacket
    VerifyTimelineRelationshipBinaryPacketData(ProfilingRelationshipType::ExecutionLink,
                                               EmptyOptional(),
                                               entityGuid,
                                               eventGuid,
                                               eventClassGuid,
                                               readableData,
                                               offset);

    // Mark the buffer as read
    mockBufferManager.MarkRead(readableBuffer);
}

BOOST_AUTO_TEST_SUITE_END()
