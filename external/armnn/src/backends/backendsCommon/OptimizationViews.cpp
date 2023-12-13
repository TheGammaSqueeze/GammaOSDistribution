//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include <armnn/backends/OptimizationViews.hpp>

namespace armnn
{

bool OptimizationViews::Validate(const armnn::SubgraphView& originalSubgraph) const
{
    //This needs to verify that:
    // 1) the sum of m_SuccesfulOptimizations & m_FailedOptimizations & m_UntouchedSubgraphs contains subgraphviews
    //    which cover the entire space of the originalSubgraph.
    // 2) Each SubstitutionPair contains matching inputs and outputs
    bool valid = true;

    // Create a copy of the layer list from the original subgraph and sort it
    SubgraphView::Layers originalLayers = originalSubgraph.GetLayers();
    originalLayers.sort();

    // Create a new list based on the sum of all the subgraphs and sort it
    SubgraphView::Layers countedLayers;
    for (auto& failed : m_FailedOptimizations)
    {
        countedLayers.insert(countedLayers.end(), failed.GetLayers().begin(), failed.GetLayers().end());
    }
    for (auto& untouched : m_UntouchedSubgraphs)
    {
        countedLayers.insert(countedLayers.end(), untouched.GetLayers().begin(), untouched.GetLayers().end());
    }
    for (auto& successful : m_SuccesfulOptimizations)
    {
        countedLayers.insert(countedLayers.end(),
                             successful.m_SubstitutableSubgraph.GetLayers().begin(),
                             successful.m_SubstitutableSubgraph.GetLayers().end());
    }
    countedLayers.sort();

    // Compare the two lists to make sure they match
    valid &= originalLayers.size() == countedLayers.size();

    auto oIt = originalLayers.begin();
    auto cIt = countedLayers.begin();
    for (size_t i=0; i < originalLayers.size() && valid; ++i, ++oIt, ++cIt)
    {
        valid &= (*oIt == *cIt);
    }

    // Compare the substitution subgraphs to ensure they are compatible
    if (valid)
    {
        for (auto& substitution : m_SuccesfulOptimizations)
        {
            bool validSubstitution = true;
            const SubgraphView& replacement = substitution.m_ReplacementSubgraph;
            const SubgraphView& old = substitution.m_SubstitutableSubgraph;
            validSubstitution &= replacement.GetInputSlots().size() == old.GetInputSlots().size();
            validSubstitution &= replacement.GetOutputSlots().size() == old.GetOutputSlots().size();
            valid &= validSubstitution;
        }
    }
    return valid;
}
} //namespace armnn
