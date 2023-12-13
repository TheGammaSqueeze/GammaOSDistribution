//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "RefWorkloadUtils.hpp"
#include <backendsCommon/WorkloadData.hpp>
#include <armnn/Tensor.hpp>
#include <armnn/utility/Assert.hpp>
#include "Splitter.hpp"

#include <cmath>
#include <limits>

#include "Decoders.hpp"
#include "Encoders.hpp"

namespace armnn
{

void Split(const SplitterQueueDescriptor& data)
{
    const TensorInfo& inputInfo = GetTensorInfo(data.m_Inputs[0]);

    std::unique_ptr<Decoder<float>> decoderPtr =
        MakeDecoder<float>(inputInfo, data.m_Inputs[0]->Map());
    Decoder<float>& decoder = *decoderPtr;

    for (unsigned int index = 0; index < inputInfo.GetNumElements(); ++index)
    {
        unsigned int indices[MaxNumOfTensorDimensions] = { 0 };

        unsigned int indexRemainder = index;
        unsigned int dimensionStride = inputInfo.GetNumElements();

        for (unsigned int i = 0; i<inputInfo.GetNumDimensions(); i++)
        {
            dimensionStride /= inputInfo.GetShape()[i];
            indices[i] = indexRemainder / dimensionStride; // Use integer division to round down.
            indexRemainder -= indices[i] * dimensionStride;
        }

        for (unsigned int viewIdx = 0; viewIdx < data.m_ViewOrigins.size(); ++viewIdx)
        {
            SplitterQueueDescriptor::ViewOrigin const& view = data.m_ViewOrigins[viewIdx];

            //Split view extents are defined by the size of (the corresponding) input tensor.
            const TensorInfo& outputInfo = GetTensorInfo(data.m_Outputs[viewIdx]);
            ARMNN_ASSERT(outputInfo.GetNumDimensions() == inputInfo.GetNumDimensions());

            // Check all dimensions to see if this element is inside the given input view.
            bool insideView = true;
            for (unsigned int i = 0; i<outputInfo.GetNumDimensions(); i++)
            {
                if (indices[i] < view.m_Origin[i])
                {
                    insideView = false;
                }
                if (indices[i] >= view.m_Origin[i] + outputInfo.GetShape()[i])
                {
                    insideView = false;
                }
            }

            if (insideView)
            {
                std::unique_ptr<Encoder<float>> encoderPtr =
                    MakeEncoder<float>(outputInfo, data.m_Outputs[viewIdx]->Map());
                Encoder<float>& encoder = *encoderPtr;

                unsigned int outIndex = 0;
                unsigned int dimensionStride = 1;
                float inputValue = 0.f;

                for (unsigned int i = outputInfo.GetNumDimensions(); i-- > 0;)
                {
                    outIndex += dimensionStride * (indices[i] - view.m_Origin[i]);
                    dimensionStride *= outputInfo.GetShape()[i];
                }

                decoder += index;
                inputValue = decoder.Get();
                decoder -= index;

                encoder += outIndex;
                encoder.Set(inputValue);
                break;
            }
        }
    }
}

}