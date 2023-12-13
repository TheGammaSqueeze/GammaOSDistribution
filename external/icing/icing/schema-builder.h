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

#ifndef ICING_SCHEMA_BUILDER_H_
#define ICING_SCHEMA_BUILDER_H_

#include <cstdint>
#include <initializer_list>
#include <string>
#include <string_view>
#include <utility>

#include "icing/proto/schema.pb.h"

namespace icing {
namespace lib {

class PropertyConfigBuilder {
 public:
  PropertyConfigBuilder() = default;
  explicit PropertyConfigBuilder(PropertyConfigProto property)
      : property_(std::move(property)) {}

  PropertyConfigBuilder& SetName(std::string_view name) {
    property_.set_property_name(std::string(name));
    return *this;
  }

  PropertyConfigBuilder& SetDataType(
      PropertyConfigProto::DataType::Code data_type) {
    property_.set_data_type(data_type);
    return *this;
  }

  PropertyConfigBuilder& SetDataTypeString(
      TermMatchType::Code match_type,
      StringIndexingConfig::TokenizerType::Code tokenizer) {
    property_.set_data_type(PropertyConfigProto::DataType::STRING);
    property_.mutable_string_indexing_config()->set_term_match_type(match_type);
    property_.mutable_string_indexing_config()->set_tokenizer_type(tokenizer);
    return *this;
  }

  PropertyConfigBuilder& SetDataTypeDocument(std::string_view schema_type,
                                             bool index_nested_properties) {
    property_.set_data_type(PropertyConfigProto::DataType::DOCUMENT);
    property_.set_schema_type(std::string(schema_type));
    property_.mutable_document_indexing_config()->set_index_nested_properties(
        index_nested_properties);
    return *this;
  }

  PropertyConfigBuilder& SetCardinality(
      PropertyConfigProto::Cardinality::Code cardinality) {
    property_.set_cardinality(cardinality);
    return *this;
  }

  PropertyConfigProto Build() const { return std::move(property_); }

 private:
  PropertyConfigProto property_;
};

class SchemaTypeConfigBuilder {
 public:
  SchemaTypeConfigBuilder() = default;
  SchemaTypeConfigBuilder(SchemaTypeConfigProto type_config)
      : type_config_(std::move(type_config)) {}

  SchemaTypeConfigBuilder& SetType(std::string_view type) {
    type_config_.set_schema_type(std::string(type));
    return *this;
  }

  SchemaTypeConfigBuilder& SetVersion(int version) {
    type_config_.set_version(version);
    return *this;
  }

  SchemaTypeConfigBuilder& AddProperty(PropertyConfigProto property) {
    *type_config_.add_properties() = std::move(property);
    return *this;
  }
  SchemaTypeConfigBuilder& AddProperty(PropertyConfigBuilder property_builder) {
    *type_config_.add_properties() = property_builder.Build();
    return *this;
  }

  SchemaTypeConfigProto Build() { return std::move(type_config_); }

 private:
  SchemaTypeConfigProto type_config_;
};

class SchemaBuilder {
 public:
  SchemaBuilder() = default;
  SchemaBuilder(SchemaProto schema) : schema_(std::move(schema)) {}

  SchemaBuilder& AddType(SchemaTypeConfigProto type) {
    *schema_.add_types() = std::move(type);
    return *this;
  }
  SchemaBuilder& AddType(SchemaTypeConfigBuilder type_builder) {
    *schema_.add_types() = type_builder.Build();
    return *this;
  }

  SchemaProto Build() { return std::move(schema_); }

 private:
  SchemaProto schema_;
};

}  // namespace lib
}  // namespace icing

#endif  // ICING_SCHEMA_BUILDER_H_
