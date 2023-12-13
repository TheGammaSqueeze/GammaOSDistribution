//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//
#pragma once

#include "TestLayerVisitor.hpp"


#include <boost/test/unit_test.hpp>

namespace
{

#define DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(name) \
class Test##name##LayerVisitor : public armnn::TestLayerVisitor \
{ \
private: \
    using Descriptor = armnn::name##Descriptor; \
    Descriptor m_Descriptor; \
    \
    bool CheckDescriptor(const Descriptor& descriptor) \
    { \
        return descriptor == m_Descriptor; \
    } \
\
public: \
    explicit Test##name##LayerVisitor(const Descriptor& descriptor, \
                                      const char* layerName = nullptr) \
        : armnn::TestLayerVisitor(layerName) \
        , m_Descriptor(descriptor) {}; \
    \
    void Visit##name##Layer(const armnn::IConnectableLayer* layer, \
                            const Descriptor& descriptor, \
                            const char* layerName = nullptr) override \
    { \
        CheckLayerPointer(layer); \
        CheckDescriptor(descriptor); \
        CheckLayerName(layerName); \
    } \
};

} // anonymous namespace

DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Activation)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(ArgMinMax)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(BatchToSpaceNd)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Comparison)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Concat)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(DepthToSpace)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(ElementwiseUnary)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Fill)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Gather)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(InstanceNormalization)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(L2Normalization)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(LogicalBinary)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(LogSoftmax)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Mean)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Normalization)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Pad)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Permute)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Pooling2d)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Reshape)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Resize)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Slice)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Softmax)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(SpaceToBatchNd)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(SpaceToDepth)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Splitter)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Stack)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(StandIn)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(StridedSlice)
DECLARE_TEST_NAME_AND_DESCRIPTOR_LAYER_VISITOR_CLASS(Transpose)
