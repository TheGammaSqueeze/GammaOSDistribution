//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include <boost/test/unit_test.hpp>
#include "ParserFlatbuffersSerializeFixture.hpp"
#include "../Deserializer.hpp"

#include <string>
#include <iostream>

BOOST_AUTO_TEST_SUITE(Deserializer)

struct Pooling2dFixture : public ParserFlatbuffersSerializeFixture
{
    explicit Pooling2dFixture(const std::string &inputShape,
                              const std::string &outputShape,
                              const std::string &dataType,
                              const std::string &dataLayout,
                              const std::string &poolingAlgorithm)
    {
        m_JsonString = R"(
    {
            inputIds: [0],
            outputIds: [2],
            layers: [
            {
                layer_type: "InputLayer",
                layer: {
                      base: {
                            layerBindingId: 0,
                            base: {
                                index: 0,
                                layerName: "InputLayer",
                                layerType: "Input",
                                inputSlots: [{
                                    index: 0,
                                    connection: {sourceLayerIndex:0, outputSlotIndex:0 },
                                }],
                                outputSlots: [ {
                                    index: 0,
                                    tensorInfo: {
                                        dimensions: )" + inputShape + R"(,
                                        dataType: )" + dataType + R"(
                                        }}]
                                }
                }}},
                {
                layer_type: "Pooling2dLayer",
                layer: {
                      base: {
                           index: 1,
                           layerName: "Pooling2dLayer",
                           layerType: "Pooling2d",
                           inputSlots: [{
                                  index: 0,
                                  connection: {sourceLayerIndex:0, outputSlotIndex:0 },
                           }],
                           outputSlots: [ {
                                  index: 0,
                                  tensorInfo: {
                                       dimensions: )" + outputShape + R"(,
                                       dataType: )" + dataType + R"(

                           }}]},
                      descriptor: {
                           poolType: )" + poolingAlgorithm + R"(,
                           outputShapeRounding: "Floor",
                           paddingMethod: Exclude,
                           dataLayout: )" + dataLayout + R"(,
                           padLeft: 0,
                           padRight: 0,
                           padTop: 0,
                           padBottom: 0,
                           poolWidth: 2,
                           poolHeight: 2,
                           strideX: 2,
                           strideY: 2
                           }
                }},
                {
                layer_type: "OutputLayer",
                layer: {
                    base:{
                          layerBindingId: 0,
                          base: {
                                index: 2,
                                layerName: "OutputLayer",
                                layerType: "Output",
                                inputSlots: [{
                                    index: 0,
                                    connection: {sourceLayerIndex:1, outputSlotIndex:0 },
                                }],
                                outputSlots: [ {
                                    index: 0,
                                    tensorInfo: {
                                        dimensions: )" + outputShape + R"(,
                                        dataType: )" + dataType + R"(
                                    },
                            }],
                        }}},
            }]
     }
 )";
        SetupSingleInputSingleOutput("InputLayer", "OutputLayer");
    }
};

struct SimpleAvgPooling2dFixture : Pooling2dFixture
{
    SimpleAvgPooling2dFixture() : Pooling2dFixture("[ 1, 2, 2, 1 ]", "[ 1, 1, 1, 1 ]",
                                                   "Float32", "NHWC", "Average") {}
};

struct SimpleAvgPooling2dFixture2 : Pooling2dFixture
{
    SimpleAvgPooling2dFixture2() : Pooling2dFixture("[ 1, 2, 2, 1 ]",
                                                    "[ 1, 1, 1, 1 ]",
                                                    "QuantisedAsymm8", "NHWC", "Average") {}
};

struct SimpleMaxPooling2dFixture : Pooling2dFixture
{
    SimpleMaxPooling2dFixture() : Pooling2dFixture("[ 1, 1, 2, 2 ]",
                                                   "[ 1, 1, 1, 1 ]",
                                                   "Float32", "NCHW", "Max") {}
};

struct SimpleMaxPooling2dFixture2 : Pooling2dFixture
{
    SimpleMaxPooling2dFixture2() : Pooling2dFixture("[ 1, 1, 2, 2 ]",
                                                    "[ 1, 1, 1, 1 ]",
                                                    "QuantisedAsymm8", "NCHW", "Max") {}
};

BOOST_FIXTURE_TEST_CASE(Pooling2dFloat32Avg, SimpleAvgPooling2dFixture)
{
    RunTest<4, armnn::DataType::Float32>(0, { 2, 3, 5, 2 }, { 3 });
}

BOOST_FIXTURE_TEST_CASE(Pooling2dQuantisedAsymm8Avg, SimpleAvgPooling2dFixture2)
{
    RunTest<4, armnn::DataType::QAsymmU8>(0,
                                                { 20, 40, 60, 80 },
                                                { 50 });
}

BOOST_FIXTURE_TEST_CASE(Pooling2dFloat32Max, SimpleMaxPooling2dFixture)
{
    RunTest<4, armnn::DataType::Float32>(0, { 2, 5, 5, 2 }, { 5 });
}

BOOST_FIXTURE_TEST_CASE(Pooling2dQuantisedAsymm8Max, SimpleMaxPooling2dFixture2)
{
    RunTest<4, armnn::DataType::QAsymmU8>(0,
                                                { 20, 40, 60, 80 },
                                                { 80 });
}

BOOST_AUTO_TEST_SUITE_END()

