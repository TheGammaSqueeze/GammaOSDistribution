//
// Copyright © 2020 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include <boost/test/unit_test.hpp>
#include "armnnOnnxParser/IOnnxParser.hpp"
#include "ParserPrototxtFixture.hpp"

BOOST_AUTO_TEST_SUITE(OnnxParser)

struct ClipMainFixture : public armnnUtils::ParserPrototxtFixture<armnnOnnxParser::IOnnxParser>
{
    ClipMainFixture(std::string min, std::string max)
    {
        m_Prototext = R"(
                   ir_version: 3
                   producer_name:  "CNTK"
                   producer_version:  "2.5.1"
                   domain:  "ai.cntk"
                   model_version: 1
                   graph {
                     name:  "CNTKGraph"
                     input {
                        name: "Input"
                        type {
                          tensor_type {
                            elem_type: 1
                            shape {
                              dim {
                                dim_value: 5
                              }
                            }
                          }
                        }
                      }
                     node {
                         input: "Input"
                         input:")" + min + R"("
                         input:")" + max + R"("
                         output: "Output"
                         name: "ActivationLayer"
                         op_type: "Clip"
                    }
                      output {
                          name: "Output"
                          type {
                             tensor_type {
                               elem_type: 1
                               shape {
                                   dim {
                                       dim_value: 5
                                   }
                               }
                            }
                         }
                      }
                    }
                   opset_import {
                      version: 7
                    })";
        Setup();
    }
};

struct ClipFixture : ClipMainFixture
{
    ClipFixture() : ClipMainFixture("2", "3.5") {}
};

BOOST_FIXTURE_TEST_CASE(ValidClipTest, ClipFixture)
{
    RunTest<1>({{"Input",  { -1.5f, 1.25f, 3.5f, 8.0, 2.5}}},
               {{ "Output", { 2.0f, 2.0f, 3.5f, 3.5, 2.5}}});
}

struct ClipNoMaxInputFixture : ClipMainFixture
{
    ClipNoMaxInputFixture() : ClipMainFixture("0", std::string()) {}
};

BOOST_FIXTURE_TEST_CASE(ValidNoMaxInputClipTest, ClipNoMaxInputFixture)
{
    RunTest<1>({{"Input",  { -1.5f, -5.25f, -0.5f, 8.0f, std::numeric_limits<float>::max() }}},
               {{ "Output", { 0.0f, 0.0f, 0.0f, 8.0f, std::numeric_limits<float>::max() }}});
}

struct ClipNoMinInputFixture : ClipMainFixture
{
    ClipNoMinInputFixture() : ClipMainFixture(std::string(), "6") {}
};

BOOST_FIXTURE_TEST_CASE(ValidNoMinInputClipTest, ClipNoMinInputFixture)
{
    RunTest<1>({{"Input",   { std::numeric_limits<float>::lowest(), -5.25f, -0.5f, 8.0f, 200.0f }}},
               {{ "Output", { std::numeric_limits<float>::lowest(), -5.25f, -0.5f, 6.0f, 6.0f }}});
}

struct ClipNoInputFixture : ClipMainFixture
{
    ClipNoInputFixture() : ClipMainFixture(std::string(), std::string()) {}
};

BOOST_FIXTURE_TEST_CASE(ValidNoInputClipTest, ClipNoInputFixture)
{
    RunTest<1>({{"Input",   { std::numeric_limits<float>::lowest(), -1.25f, 3.5f, 8.0f,
                              std::numeric_limits<float>::max()}}},
               {{ "Output", { std::numeric_limits<float>::lowest(), -1.25f, 3.5f, 8.0f,
                              std::numeric_limits<float>::max()}}});
}

BOOST_AUTO_TEST_SUITE_END()
