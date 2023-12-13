//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//
#include <catch.hpp>
#include <opencv2/opencv.hpp>
#include <NetworkPipeline.hpp>
#include "Types.hpp"

static std::string GetResourceFilePath(const std::string& filename)
{
    std::string testResources = TEST_RESOURCE_DIR;
    if (0 == testResources.size())
    {
        throw "Invalid test resources directory provided";
    }
    else
    {
        if(testResources.back() != '/')
        {
            return testResources + "/" + filename;
        }
        else
        {
            return testResources + filename;
        }
    }
}

TEST_CASE("Test Network Execution SSD_MOBILE")
{
    std::string testResources = TEST_RESOURCE_DIR;
    REQUIRE(testResources != "");
    // Create the network options
    od::ODPipelineOptions options;
    options.m_ModelFilePath = GetResourceFilePath("detect.tflite");
    options.m_ModelName = "SSD_MOBILE";
    options.m_backends = {"CpuAcc", "CpuRef"};

    od::IPipelinePtr objectDetectionPipeline = od::CreatePipeline(options);

    od::InferenceResults results;
    cv::Mat processed;
    cv::Mat inputFrame = cv::imread(GetResourceFilePath("basketball1.png"), cv::IMREAD_COLOR);
    cv::cvtColor(inputFrame, inputFrame, cv::COLOR_BGR2RGB);

    objectDetectionPipeline->PreProcessing(inputFrame, processed);

    CHECK(processed.type() == CV_8UC3);
    CHECK(processed.cols == 300);
    CHECK(processed.rows == 300);

    objectDetectionPipeline->Inference(processed, results);
    objectDetectionPipeline->PostProcessing(results,
                                            [](od::DetectedObjects detects) -> void {
                                                CHECK(detects.size() == 2);
                                                CHECK(detects[0].GetLabel() == "0");
                                            });

}
