//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include <boost/test/unit_test.hpp>
#include "ParserFlatbuffersSerializeFixture.hpp"
#include "../Deserializer.hpp"

#include <string>
#include <iostream>

BOOST_AUTO_TEST_SUITE(DeserializeParser)

struct ActivationFixture : public ParserFlatbuffersSerializeFixture
{
    explicit ActivationFixture(const std::string& inputShape,
                               const std::string& outputShape,
                               const std::string& dataType,
                               const std::string& activationType="Sigmoid",
                               const std::string& a = "0.0",
                               const std::string& b = "0.0")
    {
        m_JsonString = R"(
        {
            inputIds: [0],
            outputIds: [2],
            layers: [{
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
                            outputSlots: [{
                                index: 0,
                                tensorInfo: {
                                    dimensions: )" + inputShape + R"(,
                                    dataType: )" + dataType + R"(
                                },
                            }],
                        },
                    }
                },
            },
            {
                layer_type: "ActivationLayer",
                layer : {
                    base: {
                        index:1,
                        layerName: "ActivationLayer",
                        layerType: "Activation",
                        inputSlots: [{
                            index: 0,
                            connection: {sourceLayerIndex:0, outputSlotIndex:0 },
                        }],
                        outputSlots: [{
                            index: 0,
                            tensorInfo: {
                                dimensions: )" + outputShape + R"(,
                                dataType: )" + dataType + R"(
                            },
                        }],
                    },
                    descriptor: {
                        a: )" + a + R"(,
                        b: )" + b + R"(,
                        activationFunction: )" + activationType + R"(
                    },
                },
            },
            {
                layer_type: "OutputLayer",
                layer: {
                    base:{
                        layerBindingId: 2,
                        base: {
                            index: 2,
                            layerName: "OutputLayer",
                            layerType: "Output",
                            inputSlots: [{
                                index: 0,
                                connection: {sourceLayerIndex:1, outputSlotIndex:0 },
                            }],
                            outputSlots: [{
                                index: 0,
                                tensorInfo: {
                                    dimensions: )" + outputShape + R"(,
                                    dataType: )" + dataType + R"(
                                },
                            }],
                        }
                    }
                },
            }]
        }
        )";
        Setup();
    }
};

struct SimpleActivationFixture : ActivationFixture
{
    SimpleActivationFixture() : ActivationFixture("[1, 2, 2, 1]",
                                                  "[1, 2, 2, 1]",
                                                  "QuantisedAsymm8",
                                                  "ReLu") {}
};

struct SimpleActivationFixture2 : ActivationFixture
{
    SimpleActivationFixture2() : ActivationFixture("[1, 2, 2, 1]",
                                                   "[1, 2, 2, 1]",
                                                   "Float32",
                                                   "ReLu") {}
};

struct SimpleActivationFixture3 : ActivationFixture
{
    SimpleActivationFixture3() : ActivationFixture("[1, 2, 2, 1]",
                                                   "[1, 2, 2, 1]",
                                                   "QuantisedAsymm8",
                                                   "BoundedReLu",
                                                   "5.0",
                                                   "0.0") {}
};

struct SimpleActivationFixture4 : ActivationFixture
{
    SimpleActivationFixture4() : ActivationFixture("[1, 2, 2, 1]",
                                                   "[1, 2, 2, 1]",
                                                   "Float32",
                                                   "BoundedReLu",
                                                   "5.0",
                                                   "0.0") {}
};


BOOST_FIXTURE_TEST_CASE(ActivationReluQuantisedAsymm8, SimpleActivationFixture)
{
    RunTest<4, armnn::DataType::QAsymmU8>(
            0,
            {{"InputLayer", {10, 0, 2, 0}}},
            {{"OutputLayer", {10, 0, 2, 0}}});
}

BOOST_FIXTURE_TEST_CASE(ActivationReluFloat32, SimpleActivationFixture2)
{
    RunTest<4, armnn::DataType::Float32>(
            0,
            {{"InputLayer", {111, -85, 226, 3}}},
            {{"OutputLayer", {111, 0, 226, 3}}});
}


BOOST_FIXTURE_TEST_CASE(ActivationBoundedReluQuantisedAsymm8, SimpleActivationFixture3)
{
    RunTest<4, armnn::DataType::QAsymmU8>(
            0,
            {{"InputLayer", {10, 0, 2, 0}}},
            {{"OutputLayer", {5, 0, 2, 0}}});
}

BOOST_FIXTURE_TEST_CASE(ActivationBoundedReluFloat32, SimpleActivationFixture4)
{
    RunTest<4, armnn::DataType::Float32>(
            0,
            {{"InputLayer", {111, -85, 226, 3}}},
            {{"OutputLayer", {5, 0, 5, 3}}});
}

BOOST_AUTO_TEST_SUITE_END()
