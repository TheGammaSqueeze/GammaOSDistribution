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

#ifndef ICING_RESULT_PROJECTION_TREE_H_
#define ICING_RESULT_PROJECTION_TREE_H_

#include <string_view>
#include <vector>

#include "icing/text_classifier/lib3/utils/base/statusor.h"
#include "icing/proto/search.pb.h"

namespace icing {
namespace lib {

class ProjectionTree {
 public:
  static constexpr std::string_view kSchemaTypeWildcard = "*";

  struct Node {
    explicit Node(std::string_view name = "") : name(name) {}

    std::string_view name;
    std::vector<Node> children;
  };

  explicit ProjectionTree(const TypePropertyMask& type_field_mask);

  const Node& root() const { return root_; }

 private:
  // Add a child node with property_name to current_children and returns a
  // pointer to the child node.
  Node* AddChildNode(std::string_view property_name,
                     std::vector<Node>* current_children);

  Node root_;
};

}  // namespace lib
}  // namespace icing

#endif  // ICING_RESULT_PROJECTION_TREE_H_
