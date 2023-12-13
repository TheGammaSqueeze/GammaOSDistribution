//
// Copyright © 2020 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include <backendsCommon/LayerSupportBase.hpp>

namespace sdb // sample dynamic backend
{

class SampleDynamicLayerSupport : public armnn::LayerSupportBase
{
public:
    bool IsAdditionSupported(const armnn::TensorInfo& input0,
                             const armnn::TensorInfo& input1,
                             const armnn::TensorInfo& output,
                             armnn::Optional<std::string&> reasonIfUnsupported = armnn::EmptyOptional()) const override;

    bool IsInputSupported(const armnn::TensorInfo& input,
                          armnn::Optional<std::string&> reasonIfUnsupported) const override;

    bool IsOutputSupported(const armnn::TensorInfo& output,
                           armnn::Optional<std::string&> reasonIfUnsupported) const override;
};

} // namespace sdb
