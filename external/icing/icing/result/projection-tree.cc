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

#include "icing/result/projection-tree.h"

#include <algorithm>

#include "icing/absl_ports/str_join.h"
#include "icing/schema/section-manager.h"

namespace icing {
namespace lib {

ProjectionTree::ProjectionTree(const TypePropertyMask& type_field_mask) {
  for (const std::string& field_mask : type_field_mask.paths()) {
    Node* current_node = &root_;
    for (std::string_view sub_field_mask :
         absl_ports::StrSplit(field_mask, kPropertySeparator)) {
      current_node = AddChildNode(sub_field_mask, &current_node->children);
    }
  }
}

ProjectionTree::Node* ProjectionTree::AddChildNode(
    std::string_view property_name, std::vector<Node>* current_children) {
  auto itr = std::find_if(current_children->begin(), current_children->end(),
                          [&property_name](const Node& node) {
                            return node.name == property_name;
                          });
  if (itr != current_children->end()) {
    return &(*itr);
  }
  current_children->push_back(ProjectionTree::Node(property_name));
  return &current_children->back();
}

}  // namespace lib
}  // namespace icing
