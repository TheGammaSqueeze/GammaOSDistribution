// Copyright (C) 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "icing/scoring/scoring-processor.h"

#include <memory>
#include <utility>
#include <vector>

#include "icing/text_classifier/lib3/utils/base/status.h"
#include "icing/text_classifier/lib3/utils/base/statusor.h"
#include "icing/index/hit/doc-hit-info.h"
#include "icing/index/iterator/doc-hit-info-iterator.h"
#include "icing/scoring/ranker.h"
#include "icing/scoring/scored-document-hit.h"
#include "icing/scoring/scorer.h"
#include "icing/store/document-store.h"
#include "icing/util/status-macros.h"

namespace icing {
namespace lib {

namespace {
constexpr double kDefaultScoreInDescendingOrder = 0;
constexpr double kDefaultScoreInAscendingOrder =
    std::numeric_limits<double>::max();
}  // namespace

libtextclassifier3::StatusOr<std::unique_ptr<ScoringProcessor>>
ScoringProcessor::Create(const ScoringSpecProto& scoring_spec,
                         const DocumentStore* document_store) {
  ICING_RETURN_ERROR_IF_NULL(document_store);

  bool is_descending_order =
      scoring_spec.order_by() == ScoringSpecProto::Order::DESC;

  ICING_ASSIGN_OR_RETURN(
      std::unique_ptr<Scorer> scorer,
      Scorer::Create(scoring_spec.rank_by(),
                     is_descending_order ? kDefaultScoreInDescendingOrder
                                         : kDefaultScoreInAscendingOrder,
                     document_store));

  // Using `new` to access a non-public constructor.
  return std::unique_ptr<ScoringProcessor>(
      new ScoringProcessor(std::move(scorer)));
}

std::vector<ScoredDocumentHit> ScoringProcessor::Score(
    std::unique_ptr<DocHitInfoIterator> doc_hit_info_iterator, int num_to_score,
    std::unordered_map<std::string, std::unique_ptr<DocHitInfoIterator>>*
        query_term_iterators) {
  std::vector<ScoredDocumentHit> scored_document_hits;
  scorer_->PrepareToScore(query_term_iterators);

  while (doc_hit_info_iterator->Advance().ok() && num_to_score-- > 0) {
    const DocHitInfo& doc_hit_info = doc_hit_info_iterator->doc_hit_info();
    // TODO(b/144955274) Calculate hit demotion factor from HitScore
    double hit_demotion_factor = 1.0;
    // The final score of the doc_hit_info = score of doc * demotion factor of
    // hit.
    double score =
        scorer_->GetScore(doc_hit_info, doc_hit_info_iterator.get()) *
        hit_demotion_factor;
    scored_document_hits.emplace_back(
        doc_hit_info.document_id(), doc_hit_info.hit_section_ids_mask(), score);
  }

  return scored_document_hits;
}

}  // namespace lib
}  // namespace icing
