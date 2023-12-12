//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//
#include <boost/test/unit_test.hpp>
#include "ParserFlatbuffersFixture.hpp"
#include "../TfLiteParser.hpp"

using armnnTfLiteParser::TfLiteParser;
using ModelPtr = TfLiteParser::ModelPtr;

BOOST_AUTO_TEST_SUITE(TensorflowLiteParser)

struct GetInputsOutputsMainFixture : public ParserFlatbuffersFixture
{
    explicit GetInputsOutputsMainFixture(const std::string& inputs, const std::string& outputs)
    {
        m_JsonString = R"(
        {
            "version": 3,
            "operator_codes": [ { "builtin_code": "AVERAGE_POOL_2D" }, { "builtin_code": "CONV_2D" } ],
            "subgraphs": [
            {
                "tensors": [
                {
                    "shape": [ 1, 1, 1, 1 ] ,
                    "type": "UINT8",
                            "buffer": 0,
                            "name": "OutputTensor",
                            "quantization": {
                                "min": [ 0.0 ],
                                "max": [ 255.0 ],
                                "scale": [ 1.0 ],
                                "zero_point": [ 0 ]
                            }
                },
                {
                    "shape": [ 1, 2, 2, 1 ] ,
                    "type": "UINT8",
                            "buffer": 1,
                            "name": "InputTensor",
                            "quantization": {
                                "min": [ -1.2 ],
                                "max": [ 25.5 ],
                                "scale": [ 0.25 ],
                                "zero_point": [ 10 ]
                            }
                }
                ],
                "inputs": [ 1 ],
                "outputs": [ 0 ],
                "operators": [ {
                        "opcode_index": 0,
                        "inputs":  )"
                            + inputs
                            + R"(,
                        "outputs": )"
                            + outputs
                            + R"(,
                        "builtin_options_type": "Pool2DOptions",
                        "builtin_options":
                        {
                            "padding": "VALID",
                            "stride_w": 2,
                            "stride_h": 2,
                            "filter_width": 2,
                            "filter_height": 2,
                            "fused_activation_function": "NONE"
                        },
                        "custom_options_format": "FLEXBUFFERS"
                    } ]
                },
                {
                    "tensors": [
                        {
                            "shape": [ 1, 3, 3, 1 ],
                            "type": "UINT8",
                            "buffer": 0,
                            "name": "ConvInputTensor",
                            "quantization": {
                                "scale": [ 1.0 ],
                                "zero_point": [ 0 ],
                            }
                        },
                        {
                            "shape": [ 1, 1, 1, 1 ],
                            "type": "UINT8",
                            "buffer": 1,
                            "name": "ConvOutputTensor",
                            "quantization": {
                                "min": [ 0.0 ],
                                "max": [ 511.0 ],
                                "scale": [ 2.0 ],
                                "zero_point": [ 0 ],
                            }
                        },
                        {
                            "shape": [ 1, 3, 3, 1 ],
                            "type": "UINT8",
                            "buffer": 2,
                            "name": "filterTensor",
                            "quantization": {
                                "min": [ 0.0 ],
                                "max": [ 255.0 ],
                                "scale": [ 1.0 ],
                                "zero_point": [ 0 ],
                            }
                        }
                    ],
                    "inputs": [ 0 ],
                    "outputs": [ 1 ],
                    "operators": [
                        {
                            "opcode_index": 0,
                            "inputs": [ 0, 2 ],
                            "outputs": [ 1 ],
                            "builtin_options_type": "Conv2DOptions",
                            "builtin_options": {
                                "padding": "VALID",
                                "stride_w": 1,
                                "stride_h": 1,
                                "fused_activation_function": "NONE"
                            },
                            "custom_options_format": "FLEXBUFFERS"
                        }
                    ],
                }
            ],
            "description": "Test Subgraph Inputs Outputs",
            "buffers" : [
                    { },
                    { },
                    { "data": [ 2,1,0, 6,2,1, 4,1,2 ], },
                    { },
                ]
        })";

        ReadStringToBinary();
    }

};

struct GetEmptyInputsOutputsFixture : GetInputsOutputsMainFixture
{
    GetEmptyInputsOutputsFixture() : GetInputsOutputsMainFixture("[ ]", "[ ]") {}
};

struct GetInputsOutputsFixture : GetInputsOutputsMainFixture
{
    GetInputsOutputsFixture() : GetInputsOutputsMainFixture("[ 1 ]", "[ 0 ]") {}
};

BOOST_FIXTURE_TEST_CASE(GetEmptyInputs, GetEmptyInputsOutputsFixture)
{
    TfLiteParser::ModelPtr model = TfLiteParser::LoadModelFromBinary(m_GraphBinary.data(), m_GraphBinary.size());
    TfLiteParser::TensorRawPtrVector tensors = TfLiteParser::GetInputs(model, 0, 0);
    BOOST_CHECK_EQUAL(0, tensors.size());
}

BOOST_FIXTURE_TEST_CASE(GetEmptyOutputs, GetEmptyInputsOutputsFixture)
{
    TfLiteParser::ModelPtr model = TfLiteParser::LoadModelFromBinary(m_GraphBinary.data(), m_GraphBinary.size());
    TfLiteParser::TensorRawPtrVector tensors = TfLiteParser::GetOutputs(model, 0, 0);
    BOOST_CHECK_EQUAL(0, tensors.size());
}

BOOST_FIXTURE_TEST_CASE(GetInputs, GetInputsOutputsFixture)
{
    TfLiteParser::ModelPtr model = TfLiteParser::LoadModelFromBinary(m_GraphBinary.data(), m_GraphBinary.size());
    TfLiteParser::TensorRawPtrVector tensors = TfLiteParser::GetInputs(model, 0, 0);
    BOOST_CHECK_EQUAL(1, tensors.size());
    CheckTensors(tensors[0], 4, { 1, 2, 2, 1 }, tflite::TensorType::TensorType_UINT8, 1,
                      "InputTensor", { -1.2f }, { 25.5f }, { 0.25f }, { 10 });
}

BOOST_FIXTURE_TEST_CASE(GetOutputs, GetInputsOutputsFixture)
{
    TfLiteParser::ModelPtr model = TfLiteParser::LoadModelFromBinary(m_GraphBinary.data(), m_GraphBinary.size());
    TfLiteParser::TensorRawPtrVector tensors = TfLiteParser::GetOutputs(model, 0, 0);
    BOOST_CHECK_EQUAL(1, tensors.size());
    CheckTensors(tensors[0], 4, { 1, 1, 1, 1 }, tflite::TensorType::TensorType_UINT8, 0,
                      "OutputTensor", { 0.0f }, { 255.0f }, { 1.0f }, { 0 });
}

BOOST_FIXTURE_TEST_CASE(GetInputsMultipleInputs, GetInputsOutputsFixture)
{
    TfLiteParser::ModelPtr model = TfLiteParser::LoadModelFromBinary(m_GraphBinary.data(), m_GraphBinary.size());
    TfLiteParser::TensorRawPtrVector tensors = TfLiteParser::GetInputs(model, 1, 0);
    BOOST_CHECK_EQUAL(2, tensors.size());
    CheckTensors(tensors[0], 4, { 1, 3, 3, 1 }, tflite::TensorType::TensorType_UINT8, 0,
                      "ConvInputTensor", { }, { }, { 1.0f }, { 0 });
    CheckTensors(tensors[1], 4, { 1, 3, 3, 1 }, tflite::TensorType::TensorType_UINT8, 2,
                      "filterTensor", { 0.0f }, { 255.0f }, { 1.0f }, { 0 });
}

BOOST_FIXTURE_TEST_CASE(GetOutputs2, GetInputsOutputsFixture)
{
    TfLiteParser::ModelPtr model = TfLiteParser::LoadModelFromBinary(m_GraphBinary.data(), m_GraphBinary.size());
    TfLiteParser::TensorRawPtrVector tensors = TfLiteParser::GetOutputs(model, 1, 0);
    BOOST_CHECK_EQUAL(1, tensors.size());
    CheckTensors(tensors[0], 4, { 1, 1, 1, 1 }, tflite::TensorType::TensorType_UINT8, 1,
                      "ConvOutputTensor", { 0.0f }, { 511.0f }, { 2.0f }, { 0 });
}

BOOST_AUTO_TEST_CASE(GetInputsNullModel)
{
    BOOST_CHECK_THROW(TfLiteParser::GetInputs(nullptr, 0, 0), armnn::ParseException);
}

BOOST_AUTO_TEST_CASE(GetOutputsNullModel)
{
    BOOST_CHECK_THROW(TfLiteParser::GetOutputs(nullptr, 0, 0), armnn::ParseException);
}

BOOST_FIXTURE_TEST_CASE(GetInputsInvalidSubgraph, GetInputsOutputsFixture)
{
    TfLiteParser::ModelPtr model = TfLiteParser::LoadModelFromBinary(m_GraphBinary.data(), m_GraphBinary.size());
    BOOST_CHECK_THROW(TfLiteParser::GetInputs(model, 2, 0), armnn::ParseException);
}

BOOST_FIXTURE_TEST_CASE(GetOutputsInvalidSubgraph, GetInputsOutputsFixture)
{
    TfLiteParser::ModelPtr model = TfLiteParser::LoadModelFromBinary(m_GraphBinary.data(), m_GraphBinary.size());
    BOOST_CHECK_THROW(TfLiteParser::GetOutputs(model, 2, 0), armnn::ParseException);
}

BOOST_FIXTURE_TEST_CASE(GetInputsInvalidOperator, GetInputsOutputsFixture)
{
    TfLiteParser::ModelPtr model = TfLiteParser::LoadModelFromBinary(m_GraphBinary.data(), m_GraphBinary.size());
    BOOST_CHECK_THROW(TfLiteParser::GetInputs(model, 0, 1), armnn::ParseException);
}

BOOST_FIXTURE_TEST_CASE(GetOutputsInvalidOperator, GetInputsOutputsFixture)
{
    TfLiteParser::ModelPtr model = TfLiteParser::LoadModelFromBinary(m_GraphBinary.data(), m_GraphBinary.size());
    BOOST_CHECK_THROW(TfLiteParser::GetOutputs(model, 0, 1), armnn::ParseException);
}

BOOST_AUTO_TEST_SUITE_END()