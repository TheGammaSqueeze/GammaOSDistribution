//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include <boost/test/unit_test.hpp>
#include "ParserFlatbuffersSerializeFixture.hpp"
#include "../Deserializer.hpp"

#include <string>

BOOST_AUTO_TEST_SUITE(Deserializer)

struct RankFixture : public ParserFlatbuffersSerializeFixture
{
    explicit RankFixture(const std::string &inputShape,
                         const std::string &dataType)
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
                     base: {
                       layerName: "",
                       layerType: "Input",
                       inputSlots: [

                       ],
                       outputSlots: [
                         {
                           tensorInfo: {
                             dimensions: )" + inputShape + R"(,
                             dataType: )" + dataType + R"(,
                             quantizationScale: 0.0
                           }
                         }
                       ]
                     }
                   }
                 }
               },
               {
                 layer_type: "RankLayer",
                 layer: {
                   base: {
                     index: 1,
                     layerName: "rank",
                     layerType: "Rank",
                     inputSlots: [
                       {
                         connection: {
                           sourceLayerIndex: 0,
                           outputSlotIndex: 0
                         }
                       }
                     ],
                     outputSlots: [
                       {
                         tensorInfo: {
                           dimensions: [ 1 ],
                           dataType: "Signed32",
                           quantizationScale: 0.0,
                           dimensionality: 2
                         }
                       }
                     ]
                   }
                 }
               },
               {
                 layer_type: "OutputLayer",
                 layer: {
                   base: {
                     base: {
                       index: 2,
                       layerName: "",
                       layerType: "Output",
                       inputSlots: [
                         {
                           connection: {
                             sourceLayerIndex: 1,
                             outputSlotIndex: 0
                           }
                         }
                       ],
                       outputSlots: []
                     }
                   }
                 }
               }
             ],
         }
     )";
        Setup();
    }
};

struct SimpleRankDimSize1Fixture : RankFixture
{
    SimpleRankDimSize1Fixture() : RankFixture("[ 8 ]", "QSymmS16") {}
};

struct SimpleRankDimSize2Fixture : RankFixture
{
    SimpleRankDimSize2Fixture() : RankFixture("[ 3, 3 ]", "QSymmS8") {}
};

struct SimpleRankDimSize3Fixture : RankFixture
{
    SimpleRankDimSize3Fixture() : RankFixture("[ 2, 2, 1 ]", "Signed32") {}
};

struct SimpleRankDimSize4Fixture : RankFixture
{
    SimpleRankDimSize4Fixture() : RankFixture("[ 2, 2, 1, 1 ]", "Float32") {}
};

BOOST_FIXTURE_TEST_CASE(RankDimSize1Float16, SimpleRankDimSize1Fixture)
{
    RunTest<1, armnn::DataType::QSymmS16, armnn::DataType::Signed32>( 0,
                                                                      { 1, 2, 3, 4, 5, 6, 7, 8 },
                                                                      { 1 });
}

BOOST_FIXTURE_TEST_CASE(RankDimSize2QAsymmU8, SimpleRankDimSize2Fixture)
{
    RunTest<1, armnn::DataType::QSymmS8, armnn::DataType::Signed32>( 0,
                                                                    { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
                                                                    { 2 });
}

BOOST_FIXTURE_TEST_CASE(RankDimSize3Signed32, SimpleRankDimSize3Fixture)
{
    RunTest<1, armnn::DataType::Signed32, armnn::DataType::Signed32>( 0,
                                                                    { 111, 85, 226, 3 },
                                                                    { 3 });
}

BOOST_FIXTURE_TEST_CASE(RankDimSize4Float32, SimpleRankDimSize4Fixture)
{
    RunTest<1, armnn::DataType::Float32, armnn::DataType::Signed32>( 0,
                                                                   { 111, 85, 226, 3 },
                                                                   { 4 });
}

BOOST_AUTO_TEST_SUITE_END()