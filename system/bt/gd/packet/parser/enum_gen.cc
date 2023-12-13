/*
 * Copyright 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "enum_gen.h"

#include <iostream>

#include "util.h"

EnumGen::EnumGen(EnumDef e) : e_(std::move(e)) {}

void EnumGen::GenDefinition(std::ostream& stream) {
  stream << "enum class ";
  stream << e_.name_;
  stream << " : " << util::GetTypeForSize(e_.size_);
  stream << " {";
  for (const auto& pair : e_.constants_) {
    stream << pair.second << " = 0x" << std::hex << pair.first << std::dec << ",";
  }
  stream << "};\n";
}

void EnumGen::GenDefinitionPybind11(std::ostream& stream) {
  stream << "py::enum_<" << e_.name_ << ">(m, \"" << e_.name_ << "\")";
  for (const auto& pair : e_.constants_) {
    stream << ".value(\"" << pair.second << "\", " << e_.name_ << "::" << pair.second << ")";
  }
  stream << ";\n";
}

void EnumGen::GenLogging(std::ostream& stream) {
  // Print out the switch statement that converts all the constants to strings.
  stream << "inline std::string " << e_.name_ << "Text(const " << e_.name_ << "& param) {";
  stream << "switch (param) {";
  for (const auto& pair : e_.constants_) {
    stream << "case " << e_.name_ << "::" << pair.second << ":";
    stream << "  return \"" << pair.second << "\";";
  }
  stream << "default:";
  stream << "  return std::string(\"Unknown " << e_.name_ << ": \") + std::to_string(static_cast<int>(param));";
  stream << "}";
  stream << "}\n\n";

  // Print out the stream operator so that the constant can be written to streams.
  stream << "inline std::ostream& operator<<(std::ostream& os, const " << e_.name_ << "& param) {";
  stream << "  return os << " << e_.name_ << "Text(param);";
  stream << "}\n";
}

void EnumGen::GenRustDef(std::ostream& stream) {
  stream << "#[derive(FromPrimitive, ToPrimitive, Debug, Hash, Eq, PartialEq, Clone, Copy)]\n";
  stream << "pub enum " << e_.name_ << " {";
  for (const auto& pair : e_.constants_) {
    stream << util::ConstantCaseToCamelCase(pair.second) << " = 0x" << std::hex << pair.first << std::dec << ",";
  }
  stream << "}";

  if (e_.try_from_enum_ != nullptr) {
    std::vector<std::string> other_items;
    for (const auto& pair : e_.try_from_enum_->constants_) {
      other_items.push_back(pair.second);
    }
    stream << "impl TryFrom<" << e_.try_from_enum_->name_ << "> for " << e_.name_ << " {";
    stream << "type Error = &'static str;";
    stream << "fn try_from(value: " << e_.try_from_enum_->name_ << ") -> std::result::Result<Self, Self::Error> {";
    stream << "match value {";
    for (const auto& pair : e_.constants_) {
      if (std::find(other_items.begin(), other_items.end(), pair.second) == other_items.end()) {
        continue;
      }
      auto constant_name = util::ConstantCaseToCamelCase(pair.second);
      stream << e_.try_from_enum_->name_ << "::" << constant_name << " => Ok(" << e_.name_ << "::" << constant_name
             << "),";
    }
    stream << "_ => Err(\"No mapping for provided key\"),";
    stream << "}}}";
  }
}
