//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//
#pragma once

#include <aclCommon/ArmComputeTensorHandle.hpp>
#include <aclCommon/ArmComputeTensorUtils.hpp>

#include <Half.hpp>

#include <armnn/utility/PolymorphicDowncast.hpp>

#include <arm_compute/runtime/CL/CLTensor.h>
#include <arm_compute/runtime/CL/CLSubTensor.h>
#include <arm_compute/runtime/IMemoryGroup.h>
#include <arm_compute/runtime/MemoryGroup.h>
#include <arm_compute/core/TensorShape.h>
#include <arm_compute/core/Coordinates.h>

namespace armnn
{


class IClTensorHandle : public IAclTensorHandle
{
public:
    virtual arm_compute::ICLTensor& GetTensor() = 0;
    virtual arm_compute::ICLTensor const& GetTensor() const = 0;
    virtual arm_compute::DataType GetDataType() const = 0;
    virtual void SetMemoryGroup(const std::shared_ptr<arm_compute::IMemoryGroup>& memoryGroup) = 0;
};

class ClTensorHandle : public IClTensorHandle
{
public:
    ClTensorHandle(const TensorInfo& tensorInfo)
    {
        armnn::armcomputetensorutils::BuildArmComputeTensor(m_Tensor, tensorInfo);
    }

    ClTensorHandle(const TensorInfo& tensorInfo, DataLayout dataLayout)
    {
        armnn::armcomputetensorutils::BuildArmComputeTensor(m_Tensor, tensorInfo, dataLayout);
    }

    arm_compute::CLTensor& GetTensor() override { return m_Tensor; }
    arm_compute::CLTensor const& GetTensor() const override { return m_Tensor; }
    virtual void Allocate() override {armnn::armcomputetensorutils::InitialiseArmComputeTensorEmpty(m_Tensor);}

    virtual void Manage() override
    {
        assert(m_MemoryGroup != nullptr);
        m_MemoryGroup->manage(&m_Tensor);
    }

    virtual const void* Map(bool blocking = true) const override
    {
        const_cast<arm_compute::CLTensor*>(&m_Tensor)->map(blocking);
        return static_cast<const void*>(m_Tensor.buffer() + m_Tensor.info()->offset_first_element_in_bytes());
    }

    virtual void Unmap() const override { const_cast<arm_compute::CLTensor*>(&m_Tensor)->unmap(); }

    virtual ITensorHandle* GetParent() const override { return nullptr; }

    virtual arm_compute::DataType GetDataType() const override
    {
        return m_Tensor.info()->data_type();
    }

    virtual void SetMemoryGroup(const std::shared_ptr<arm_compute::IMemoryGroup>& memoryGroup) override
    {
        m_MemoryGroup = PolymorphicPointerDowncast<arm_compute::MemoryGroup>(memoryGroup);
    }

    TensorShape GetStrides() const override
    {
        return armcomputetensorutils::GetStrides(m_Tensor.info()->strides_in_bytes());
    }

    TensorShape GetShape() const override
    {
        return armcomputetensorutils::GetShape(m_Tensor.info()->tensor_shape());
    }

private:
    // Only used for testing
    void CopyOutTo(void* memory) const override
    {
        const_cast<armnn::ClTensorHandle*>(this)->Map(true);
        switch(this->GetDataType())
        {
            case arm_compute::DataType::F32:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<float*>(memory));
                break;
            case arm_compute::DataType::U8:
            case arm_compute::DataType::QASYMM8:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<uint8_t*>(memory));
                break;
            case arm_compute::DataType::QSYMM8_PER_CHANNEL:
            case arm_compute::DataType::QASYMM8_SIGNED:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<int8_t*>(memory));
                break;
            case arm_compute::DataType::F16:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<armnn::Half*>(memory));
                break;
            case arm_compute::DataType::S16:
            case arm_compute::DataType::QSYMM16:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<int16_t*>(memory));
                break;
            case arm_compute::DataType::S32:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<int32_t*>(memory));
                break;
            default:
            {
                throw armnn::UnimplementedException();
            }
        }
        const_cast<armnn::ClTensorHandle*>(this)->Unmap();
    }

    // Only used for testing
    void CopyInFrom(const void* memory) override
    {
        this->Map(true);
        switch(this->GetDataType())
        {
            case arm_compute::DataType::F32:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const float*>(memory),
                                                                 this->GetTensor());
                break;
            case arm_compute::DataType::U8:
            case arm_compute::DataType::QASYMM8:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const uint8_t*>(memory),
                                                                 this->GetTensor());
                break;
            case arm_compute::DataType::F16:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const armnn::Half*>(memory),
                                                                 this->GetTensor());
                break;
            case arm_compute::DataType::S16:
            case arm_compute::DataType::QSYMM8_PER_CHANNEL:
            case arm_compute::DataType::QASYMM8_SIGNED:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const int8_t*>(memory),
                                                                 this->GetTensor());
                break;
            case arm_compute::DataType::QSYMM16:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const int16_t*>(memory),
                                                                 this->GetTensor());
                break;
            case arm_compute::DataType::S32:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const int32_t*>(memory),
                                                                 this->GetTensor());
                break;
            default:
            {
                throw armnn::UnimplementedException();
            }
        }
        this->Unmap();
    }

    arm_compute::CLTensor m_Tensor;
    std::shared_ptr<arm_compute::MemoryGroup> m_MemoryGroup;
};

class ClSubTensorHandle : public IClTensorHandle
{
public:
    ClSubTensorHandle(IClTensorHandle* parent,
                      const arm_compute::TensorShape& shape,
                      const arm_compute::Coordinates& coords)
    : m_Tensor(&parent->GetTensor(), shape, coords)
    {
        parentHandle = parent;
    }

    arm_compute::CLSubTensor& GetTensor() override { return m_Tensor; }
    arm_compute::CLSubTensor const& GetTensor() const override { return m_Tensor; }

    virtual void Allocate() override {}
    virtual void Manage() override {}

    virtual const void* Map(bool blocking = true) const override
    {
        const_cast<arm_compute::CLSubTensor*>(&m_Tensor)->map(blocking);
        return static_cast<const void*>(m_Tensor.buffer() + m_Tensor.info()->offset_first_element_in_bytes());
    }
    virtual void Unmap() const override { const_cast<arm_compute::CLSubTensor*>(&m_Tensor)->unmap(); }

    virtual ITensorHandle* GetParent() const override { return parentHandle; }

    virtual arm_compute::DataType GetDataType() const override
    {
        return m_Tensor.info()->data_type();
    }

    virtual void SetMemoryGroup(const std::shared_ptr<arm_compute::IMemoryGroup>&) override {}

    TensorShape GetStrides() const override
    {
        return armcomputetensorutils::GetStrides(m_Tensor.info()->strides_in_bytes());
    }

    TensorShape GetShape() const override
    {
        return armcomputetensorutils::GetShape(m_Tensor.info()->tensor_shape());
    }

private:
    // Only used for testing
    void CopyOutTo(void* memory) const override
    {
        const_cast<ClSubTensorHandle*>(this)->Map(true);
        switch(this->GetDataType())
        {
            case arm_compute::DataType::F32:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<float*>(memory));
                break;
            case arm_compute::DataType::U8:
            case arm_compute::DataType::QASYMM8:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<uint8_t*>(memory));
                break;
            case arm_compute::DataType::F16:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<armnn::Half*>(memory));
                break;
            case arm_compute::DataType::QSYMM8_PER_CHANNEL:
            case arm_compute::DataType::QASYMM8_SIGNED:
            armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                             static_cast<int8_t*>(memory));
                break;
            case arm_compute::DataType::S16:
            case arm_compute::DataType::QSYMM16:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<int16_t*>(memory));
                break;
            case arm_compute::DataType::S32:
                armcomputetensorutils::CopyArmComputeITensorData(this->GetTensor(),
                                                                 static_cast<int32_t*>(memory));
                break;
            default:
            {
                throw armnn::UnimplementedException();
            }
        }
        const_cast<ClSubTensorHandle*>(this)->Unmap();
    }

    // Only used for testing
    void CopyInFrom(const void* memory) override
    {
        this->Map(true);
        switch(this->GetDataType())
        {
            case arm_compute::DataType::F32:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const float*>(memory),
                                                                 this->GetTensor());
                break;
            case arm_compute::DataType::U8:
            case arm_compute::DataType::QASYMM8:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const uint8_t*>(memory),
                                                                 this->GetTensor());
                break;
            case arm_compute::DataType::F16:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const armnn::Half*>(memory),
                                                                 this->GetTensor());
                break;
            case arm_compute::DataType::QSYMM8_PER_CHANNEL:
            case arm_compute::DataType::QASYMM8_SIGNED:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const int8_t*>(memory),
                                                                 this->GetTensor());
                break;
            case arm_compute::DataType::S16:
            case arm_compute::DataType::QSYMM16:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const int16_t*>(memory),
                                                                 this->GetTensor());
                break;
            case arm_compute::DataType::S32:
                armcomputetensorutils::CopyArmComputeITensorData(static_cast<const int32_t*>(memory),
                                                                 this->GetTensor());
                break;
            default:
            {
                throw armnn::UnimplementedException();
            }
        }
        this->Unmap();
    }

    mutable arm_compute::CLSubTensor m_Tensor;
    ITensorHandle* parentHandle = nullptr;
};

} // namespace armnn
