//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "RefBackend.hpp"
#include "RefBackendId.hpp"
#include "RefWorkloadFactory.hpp"
#include "RefLayerSupport.hpp"
#include "RefTensorHandleFactory.hpp"

#include <armnn/BackendRegistry.hpp>
#include <armnn/backends/IBackendContext.hpp>
#include <armnn/backends/IMemoryManager.hpp>
#include <armnn/utility/PolymorphicDowncast.hpp>

#include <Optimizer.hpp>

namespace armnn
{

const BackendId& RefBackend::GetIdStatic()
{
    static const BackendId s_Id{RefBackendId()};
    return s_Id;
}

IBackendInternal::IWorkloadFactoryPtr RefBackend::CreateWorkloadFactory(
    const IBackendInternal::IMemoryManagerSharedPtr& memoryManager) const
{
    return std::make_unique<RefWorkloadFactory>(PolymorphicPointerDowncast<RefMemoryManager>(memoryManager));
}

IBackendInternal::IWorkloadFactoryPtr RefBackend::CreateWorkloadFactory(
    class TensorHandleFactoryRegistry& tensorHandleFactoryRegistry) const
{
    auto memoryManager = std::make_shared<RefMemoryManager>();

    tensorHandleFactoryRegistry.RegisterMemoryManager(memoryManager);
    tensorHandleFactoryRegistry.RegisterFactory(std::make_unique<RefTensorHandleFactory>(memoryManager));

    return std::make_unique<RefWorkloadFactory>(PolymorphicPointerDowncast<RefMemoryManager>(memoryManager));
}

IBackendInternal::IBackendContextPtr RefBackend::CreateBackendContext(const IRuntime::CreationOptions&) const
{
    return IBackendContextPtr{};
}

IBackendInternal::IBackendProfilingContextPtr RefBackend::CreateBackendProfilingContext(
    const IRuntime::CreationOptions&, IBackendProfilingPtr&)
{
    return IBackendProfilingContextPtr{};
}

IBackendInternal::IMemoryManagerUniquePtr RefBackend::CreateMemoryManager() const
{
    return std::make_unique<RefMemoryManager>();
}

IBackendInternal::Optimizations RefBackend::GetOptimizations() const
{
    return Optimizations{};
}

IBackendInternal::ILayerSupportSharedPtr RefBackend::GetLayerSupport() const
{
    static ILayerSupportSharedPtr layerSupport{new RefLayerSupport};
    return layerSupport;
}

OptimizationViews RefBackend::OptimizeSubgraphView(const SubgraphView& subgraph) const
{
    OptimizationViews optimizationViews;

    optimizationViews.AddUntouchedSubgraph(SubgraphView(subgraph));

    return optimizationViews;
}

std::vector<ITensorHandleFactory::FactoryId> RefBackend::GetHandleFactoryPreferences() const
{
    return std::vector<ITensorHandleFactory::FactoryId> { RefTensorHandleFactory::GetIdStatic() };
}

void RefBackend::RegisterTensorHandleFactories(class TensorHandleFactoryRegistry& registry)
{
    auto memoryManager = std::make_shared<RefMemoryManager>();

    registry.RegisterMemoryManager(memoryManager);
    registry.RegisterFactory(std::make_unique<RefTensorHandleFactory>(memoryManager));
}

} // namespace armnn
