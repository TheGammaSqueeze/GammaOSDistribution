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

#include "parent_def.h"

#include "fields/all_fields.h"
#include "util.h"

ParentDef::ParentDef(std::string name, FieldList fields) : ParentDef(name, fields, nullptr) {}
ParentDef::ParentDef(std::string name, FieldList fields, ParentDef* parent)
    : TypeDef(name), fields_(fields), parent_(parent) {}

void ParentDef::AddParentConstraint(std::string field_name, std::variant<int64_t, std::string> value) {
  // NOTE: This could end up being very slow if there are a lot of constraints.
  const auto& parent_params = parent_->GetParamList();
  const auto& constrained_field = parent_params.GetField(field_name);
  if (constrained_field == nullptr) {
    ERROR() << "Attempting to constrain field " << field_name << " in parent " << parent_->name_
            << ", but no such field exists.";
  }

  if (constrained_field->GetFieldType() == ScalarField::kFieldType) {
    if (!std::holds_alternative<int64_t>(value)) {
      ERROR(constrained_field) << "Attempting to constrain a scalar field to an enum value in " << parent_->name_;
    }
  } else if (constrained_field->GetFieldType() == EnumField::kFieldType) {
    if (!std::holds_alternative<std::string>(value)) {
      ERROR(constrained_field) << "Attempting to constrain an enum field to a scalar value in " << parent_->name_;
    }
    const auto& enum_def = static_cast<EnumField*>(constrained_field)->GetEnumDef();
    if (!enum_def.HasEntry(std::get<std::string>(value))) {
      ERROR(constrained_field) << "No matching enumeration \"" << std::get<std::string>(value)
                               << "\" for constraint on enum in parent " << parent_->name_ << ".";
    }

    // For enums, we have to qualify the value using the enum type name.
    value = enum_def.GetTypeName() + "::" + std::get<std::string>(value);
  } else {
    ERROR(constrained_field) << "Field in parent " << parent_->name_ << " is not viable for constraining.";
  }

  parent_constraints_.insert(std::pair(field_name, value));
}

void ParentDef::AddTestCase(std::string packet_bytes) {
  test_cases_.insert(std::move(packet_bytes));
}

// Assign all size fields to their corresponding variable length fields.
// Will crash if
//  - there aren't any fields that don't match up to a field.
//  - the size field points to a fixed size field.
//  - if the size field comes after the variable length field.
void ParentDef::AssignSizeFields() {
  for (const auto& field : fields_) {
    DEBUG() << "field name: " << field->GetName();

    if (field->GetFieldType() != SizeField::kFieldType && field->GetFieldType() != CountField::kFieldType) {
      continue;
    }

    const SizeField* size_field = static_cast<SizeField*>(field);
    // Check to see if a corresponding field can be found.
    const auto& var_len_field = fields_.GetField(size_field->GetSizedFieldName());
    if (var_len_field == nullptr) {
      ERROR(field) << "Could not find corresponding field for size/count field.";
    }

    // Do the ordering check to ensure the size field comes before the
    // variable length field.
    for (auto it = fields_.begin(); *it != size_field; it++) {
      DEBUG() << "field name: " << (*it)->GetName();
      if (*it == var_len_field) {
        ERROR(var_len_field, size_field) << "Size/count field must come before the variable length field it describes.";
      }
    }

    if (var_len_field->GetFieldType() == PayloadField::kFieldType) {
      const auto& payload_field = static_cast<PayloadField*>(var_len_field);
      payload_field->SetSizeField(size_field);
      continue;
    }

    if (var_len_field->GetFieldType() == BodyField::kFieldType) {
      const auto& body_field = static_cast<BodyField*>(var_len_field);
      body_field->SetSizeField(size_field);
      continue;
    }

    if (var_len_field->GetFieldType() == VectorField::kFieldType) {
      const auto& vector_field = static_cast<VectorField*>(var_len_field);
      vector_field->SetSizeField(size_field);
      continue;
    }

    // If we've reached this point then the field wasn't a variable length field.
    // Check to see if the field is a variable length field
    ERROR(field, size_field) << "Can not use size/count in reference to a fixed size field.\n";
  }
}

void ParentDef::SetEndianness(bool is_little_endian) {
  is_little_endian_ = is_little_endian;
}

// Get the size. You scan specify without_payload in order to exclude payload fields as children will be overriding it.
Size ParentDef::GetSize(bool without_payload) const {
  auto size = Size(0);

  for (const auto& field : fields_) {
    if (without_payload &&
        (field->GetFieldType() == PayloadField::kFieldType || field->GetFieldType() == BodyField::kFieldType)) {
      continue;
    }

    // The offset to the field must be passed in as an argument for dynamically sized custom fields.
    if (field->GetFieldType() == CustomField::kFieldType && field->GetSize().has_dynamic()) {
      std::stringstream custom_field_size;

      // Custom fields are special as their size field takes an argument.
      custom_field_size << field->GetSize().dynamic_string() << "(begin()";

      // Check if we can determine offset from begin(), otherwise error because by this point,
      // the size of the custom field is unknown and can't be subtracted from end() to get the
      // offset.
      auto offset = GetOffsetForField(field->GetName(), false);
      if (offset.empty()) {
        ERROR(field) << "Custom Field offset can not be determined from begin().";
      }

      if (offset.bits() % 8 != 0) {
        ERROR(field) << "Custom fields must be byte aligned.";
      }
      if (offset.has_bits()) custom_field_size << " + " << offset.bits() / 8;
      if (offset.has_dynamic()) custom_field_size << " + " << offset.dynamic_string();
      custom_field_size << ")";

      size += custom_field_size.str();
      continue;
    }

    size += field->GetSize();
  }

  if (parent_ != nullptr) {
    size += parent_->GetSize(true);
  }

  return size;
}

// Get the offset until the field is reached, if there is no field
// returns an empty Size. from_end requests the offset to the field
// starting from the end() iterator. If there is a field with an unknown
// size along the traversal, then an empty size is returned.
Size ParentDef::GetOffsetForField(std::string field_name, bool from_end) const {
  // Check first if the field exists.
  if (fields_.GetField(field_name) == nullptr) {
    ERROR() << "Can't find a field offset for nonexistent field named: " << field_name << " in " << name_;
  }

  PacketField* padded_field = nullptr;
  {
    PacketField* last_field = nullptr;
    for (const auto field : fields_) {
      if (field->GetFieldType() == PaddingField::kFieldType) {
        padded_field = last_field;
      }
      last_field = field;
    }
  }

  // We have to use a generic lambda to conditionally change iteration direction
  // due to iterator and reverse_iterator being different types.
  auto size_lambda = [&](auto from, auto to) -> Size {
    auto size = Size(0);
    for (auto it = from; it != to; it++) {
      // We've reached the field, end the loop.
      if ((*it)->GetName() == field_name) break;
      const auto& field = *it;
      // If there is a field with an unknown size before the field, return an empty Size.
      if (field->GetSize().empty() && padded_field != field) {
        return Size();
      }
      if (field != padded_field) {
        if (!from_end || field->GetFieldType() != PaddingField::kFieldType) {
          size += field->GetSize();
        }
      }
    }
    return size;
  };

  // Change iteration direction based on from_end.
  auto size = Size();
  if (from_end)
    size = size_lambda(fields_.rbegin(), fields_.rend());
  else
    size = size_lambda(fields_.begin(), fields_.end());
  if (size.empty()) return size;

  // We need the offset until a payload or body field.
  if (parent_ != nullptr) {
    if (parent_->fields_.HasPayload()) {
      auto parent_payload_offset = parent_->GetOffsetForField("payload", from_end);
      if (parent_payload_offset.empty()) {
        ERROR() << "Empty offset for payload in " << parent_->name_ << " finding the offset for field: " << field_name;
      }
      size += parent_payload_offset;
    } else {
      auto parent_body_offset = parent_->GetOffsetForField("body", from_end);
      if (parent_body_offset.empty()) {
        ERROR() << "Empty offset for body in " << parent_->name_ << " finding the offset for field: " << field_name;
      }
      size += parent_body_offset;
    }
  }

  return size;
}

FieldList ParentDef::GetParamList() const {
  FieldList params;

  std::set<std::string> param_types = {
      ScalarField::kFieldType,
      EnumField::kFieldType,
      ArrayField::kFieldType,
      VectorField::kFieldType,
      CustomField::kFieldType,
      StructField::kFieldType,
      VariableLengthStructField::kFieldType,
      PayloadField::kFieldType,
  };

  if (parent_ != nullptr) {
    auto parent_params = parent_->GetParamList().GetFieldsWithTypes(param_types);

    // Do not include constrained fields in the params
    for (const auto& field : parent_params) {
      if (parent_constraints_.find(field->GetName()) == parent_constraints_.end()) {
        params.AppendField(field);
      }
    }
  }
  // Add our parameters.
  return params.Merge(fields_.GetFieldsWithTypes(param_types));
}

void ParentDef::GenMembers(std::ostream& s) const {
  // Add the parameter list.
  for (const auto& field : fields_) {
    if (field->GenBuilderMember(s)) {
      s << "_{};";
    }
  }
}

void ParentDef::GenSize(std::ostream& s) const {
  auto header_fields = fields_.GetFieldsBeforePayloadOrBody();
  auto footer_fields = fields_.GetFieldsAfterPayloadOrBody();

  Size padded_size;
  const PacketField* padded_field = nullptr;
  const PacketField* last_field = nullptr;
  for (const auto& field : fields_) {
    if (field->GetFieldType() == PaddingField::kFieldType) {
      if (!padded_size.empty()) {
        ERROR() << "Only one padding field is allowed.  Second field: " << field->GetName();
      }
      padded_field = last_field;
      padded_size = field->GetSize();
    }
    last_field = field;
  }

  s << "protected:";
  s << "size_t BitsOfHeader() const {";
  s << "return 0";

  if (parent_ != nullptr) {
    if (parent_->GetDefinitionType() == Type::PACKET) {
      s << " + " << parent_->name_ << "Builder::BitsOfHeader() ";
    } else {
      s << " + " << parent_->name_ << "::BitsOfHeader() ";
    }
  }

  for (const auto& field : header_fields) {
    if (field == padded_field) {
      s << " + " << padded_size;
    } else {
      s << " + " << field->GetBuilderSize();
    }
  }
  s << ";";

  s << "}\n\n";

  s << "size_t BitsOfFooter() const {";
  s << "return 0";
  for (const auto& field : footer_fields) {
    if (field == padded_field) {
      s << " + " << padded_size;
    } else {
      s << " + " << field->GetBuilderSize();
    }
  }

  if (parent_ != nullptr) {
    if (parent_->GetDefinitionType() == Type::PACKET) {
      s << " + " << parent_->name_ << "Builder::BitsOfFooter() ";
    } else {
      s << " + " << parent_->name_ << "::BitsOfFooter() ";
    }
  }
  s << ";";
  s << "}\n\n";

  if (fields_.HasPayload()) {
    s << "size_t GetPayloadSize() const {";
    s << "if (payload_ != nullptr) {return payload_->size();}";
    s << "else { return size() - (BitsOfHeader() + BitsOfFooter()) / 8;}";
    s << ";}\n\n";
  }

  s << "public:";
  s << "virtual size_t size() const override {";
  s << "return (BitsOfHeader() / 8)";
  if (fields_.HasPayload()) {
    s << "+ payload_->size()";
  }
  if (fields_.HasBody()) {
    for (const auto& field : header_fields) {
      if (field->GetFieldType() == SizeField::kFieldType) {
        const auto& field_name = ((SizeField*)field)->GetSizedFieldName();
        if (field_name == "body") {
          s << "+ body_size_extracted_";
        }
      }
    }
  }
  s << " + (BitsOfFooter() / 8);";
  s << "}\n";
}

void ParentDef::GenSerialize(std::ostream& s) const {
  auto header_fields = fields_.GetFieldsBeforePayloadOrBody();
  auto footer_fields = fields_.GetFieldsAfterPayloadOrBody();

  s << "protected:";
  s << "void SerializeHeader(BitInserter&";
  if (parent_ != nullptr || header_fields.size() != 0) {
    s << " i ";
  }
  s << ") const {";

  if (parent_ != nullptr) {
    if (parent_->GetDefinitionType() == Type::PACKET) {
      s << parent_->name_ << "Builder::SerializeHeader(i);";
    } else {
      s << parent_->name_ << "::SerializeHeader(i);";
    }
  }

  const PacketField* padded_field = nullptr;
  {
    PacketField* last_field = nullptr;
    for (const auto field : header_fields) {
      if (field->GetFieldType() == PaddingField::kFieldType) {
        padded_field = last_field;
      }
      last_field = field;
    }
  }

  for (const auto& field : header_fields) {
    if (field->GetFieldType() == SizeField::kFieldType) {
      const auto& field_name = ((SizeField*)field)->GetSizedFieldName();
      const auto& sized_field = fields_.GetField(field_name);
      if (sized_field == nullptr) {
        ERROR(field) << __func__ << ": Can't find sized field named " << field_name;
      }
      if (sized_field->GetFieldType() == PayloadField::kFieldType) {
        s << "size_t payload_bytes = GetPayloadSize();";
        std::string modifier = ((PayloadField*)sized_field)->size_modifier_;
        if (modifier != "") {
          s << "static_assert((" << modifier << ")%8 == 0, \"Modifiers must be byte-aligned\");";
          s << "payload_bytes = payload_bytes + (" << modifier << ") / 8;";
        }
        s << "ASSERT(payload_bytes < (static_cast<size_t>(1) << " << field->GetSize().bits() << "));";
        s << "insert(static_cast<" << field->GetDataType() << ">(payload_bytes), i," << field->GetSize().bits() << ");";
      } else if (sized_field->GetFieldType() == BodyField::kFieldType) {
        s << field->GetName() << "_extracted_ = 0;";
        s << "size_t local_size = " << name_ << "::size();";

        s << "ASSERT((size() - local_size) < (static_cast<size_t>(1) << " << field->GetSize().bits() << "));";
        s << "insert(static_cast<" << field->GetDataType() << ">(size() - local_size), i," << field->GetSize().bits()
          << ");";
      } else {
        if (sized_field->GetFieldType() != VectorField::kFieldType) {
          ERROR(field) << __func__ << ": Unhandled sized field type for " << field_name;
        }
        const auto& vector_name = field_name + "_";
        const VectorField* vector = (VectorField*)sized_field;
        s << "size_t " << vector_name + "bytes = 0;";
        if (vector->element_size_.empty() || vector->element_size_.has_dynamic()) {
          s << "for (auto elem : " << vector_name << ") {";
          s << vector_name + "bytes += elem.size(); }";
        } else {
          s << vector_name + "bytes = ";
          s << vector_name << ".size() * ((" << vector->element_size_ << ") / 8);";
        }
        std::string modifier = vector->GetSizeModifier();
        if (modifier != "") {
          s << "static_assert((" << modifier << ")%8 == 0, \"Modifiers must be byte-aligned\");";
          s << vector_name << "bytes = ";
          s << vector_name << "bytes + (" << modifier << ") / 8;";
        }
        s << "ASSERT(" << vector_name + "bytes < (1 << " << field->GetSize().bits() << "));";
        s << "insert(" << vector_name << "bytes, i, ";
        s << field->GetSize().bits() << ");";
      }
    } else if (field->GetFieldType() == ChecksumStartField::kFieldType) {
      const auto& field_name = ((ChecksumStartField*)field)->GetStartedFieldName();
      const auto& started_field = fields_.GetField(field_name);
      if (started_field == nullptr) {
        ERROR(field) << __func__ << ": Can't find checksum field named " << field_name << "(" << field->GetName()
                     << ")";
      }
      s << "auto shared_checksum_ptr = std::make_shared<" << started_field->GetDataType() << ">();";
      s << "shared_checksum_ptr->Initialize();";
      s << "i.RegisterObserver(packet::ByteObserver(";
      s << "[shared_checksum_ptr](uint8_t byte){ shared_checksum_ptr->AddByte(byte);},";
      s << "[shared_checksum_ptr](){ return static_cast<uint64_t>(shared_checksum_ptr->GetChecksum());}));";
    } else if (field->GetFieldType() == PaddingField::kFieldType) {
      s << "ASSERT(unpadded_size <= " << field->GetSize().bytes() << ");";
      s << "size_t padding_bytes = ";
      s << field->GetSize().bytes() << " - unpadded_size;";
      s << "for (size_t padding = 0; padding < padding_bytes; padding++) {i.insert_byte(0);}";
    } else if (field->GetFieldType() == CountField::kFieldType) {
      const auto& vector_name = ((SizeField*)field)->GetSizedFieldName() + "_";
      s << "insert(" << vector_name << ".size(), i, " << field->GetSize().bits() << ");";
    } else {
      if (field == padded_field) {
        s << "size_t unpadded_size = (" << field->GetBuilderSize() << ") / 8;";
      }
      field->GenInserter(s);
    }
  }
  s << "}\n\n";

  s << "void SerializeFooter(BitInserter&";
  if (parent_ != nullptr || footer_fields.size() != 0) {
    s << " i ";
  }
  s << ") const {";

  for (const auto& field : footer_fields) {
    field->GenInserter(s);
  }
  if (parent_ != nullptr) {
    if (parent_->GetDefinitionType() == Type::PACKET) {
      s << parent_->name_ << "Builder::SerializeFooter(i);";
    } else {
      s << parent_->name_ << "::SerializeFooter(i);";
    }
  }
  s << "}\n\n";

  s << "public:";
  s << "virtual void Serialize(BitInserter& i) const override {";
  s << "SerializeHeader(i);";
  if (fields_.HasPayload()) {
    s << "payload_->Serialize(i);";
  }
  s << "SerializeFooter(i);";

  s << "}\n";
}

void ParentDef::GenInstanceOf(std::ostream& s) const {
  if (parent_ != nullptr && parent_constraints_.size() > 0) {
    s << "static bool IsInstance(const " << parent_->name_ << "& parent) {";
    // Get the list of parent params.
    FieldList parent_params = parent_->GetParamList().GetFieldsWithoutTypes({
        PayloadField::kFieldType,
        BodyField::kFieldType,
    });

    // Check if constrained parent fields are set to their correct values.
    for (const auto& field : parent_params) {
      const auto& constraint = parent_constraints_.find(field->GetName());
      if (constraint != parent_constraints_.end()) {
        s << "if (parent." << field->GetName() << "_ != ";
        if (field->GetFieldType() == ScalarField::kFieldType) {
          s << std::get<int64_t>(constraint->second) << ")";
          s << "{ return false;}";
        } else if (field->GetFieldType() == EnumField::kFieldType) {
          s << std::get<std::string>(constraint->second) << ")";
          s << "{ return false;}";
        } else {
          ERROR(field) << "Constraints on non enum/scalar fields should be impossible.";
        }
      }
    }
    s << "return true;}";
  }
}

const ParentDef* ParentDef::GetRootDef() const {
  if (parent_ == nullptr) {
    return this;
  }

  return parent_->GetRootDef();
}

std::vector<const ParentDef*> ParentDef::GetAncestors() const {
  std::vector<const ParentDef*> res;
  auto parent = parent_;
  while (parent != nullptr) {
    res.push_back(parent);
    parent = parent->parent_;
  }
  std::reverse(res.begin(), res.end());
  return res;
}

std::map<std::string, std::variant<int64_t, std::string>> ParentDef::GetAllConstraints() const {
  std::map<std::string, std::variant<int64_t, std::string>> res;
  res.insert(parent_constraints_.begin(), parent_constraints_.end());
  for (auto parent : GetAncestors()) {
    res.insert(parent->parent_constraints_.begin(), parent->parent_constraints_.end());
  }
  return res;
}

bool ParentDef::HasAncestorNamed(std::string name) const {
  auto parent = parent_;
  while (parent != nullptr) {
    if (parent->name_ == name) {
      return true;
    }
    parent = parent->parent_;
  }
  return false;
}

std::string ParentDef::FindConstraintField() const {
  std::string res;
  for (const auto& child : children_) {
    if (!child->parent_constraints_.empty()) {
      return child->parent_constraints_.begin()->first;
    }
    res = child->FindConstraintField();
  }
  return res;
}

std::map<const ParentDef*, const std::variant<int64_t, std::string>>
    ParentDef::FindDescendantsWithConstraint(
    std::string constraint_name) const {
  std::map<const ParentDef*, const std::variant<int64_t, std::string>> res;

  for (auto const& child : children_) {
    auto constraint = child->parent_constraints_.find(constraint_name);
    if (constraint != child->parent_constraints_.end()) {
      res.insert(std::pair(child, constraint->second));
    }
    auto m = child->FindDescendantsWithConstraint(constraint_name);
    res.insert(m.begin(), m.end());
  }
  return res;
}

std::vector<const ParentDef*> ParentDef::FindPathToDescendant(std::string descendant) const {
  std::vector<const ParentDef*> res;

  for (auto const& child : children_) {
    auto v = child->FindPathToDescendant(descendant);
    if (v.size() > 0) {
      res.insert(res.begin(), v.begin(), v.end());
      res.push_back(child);
    }
    if (child->name_ == descendant) {
      res.push_back(child);
      return res;
    }
  }
  return res;
}

bool ParentDef::HasChildEnums() const {
  return !children_.empty() || fields_.HasPayload();
}

void ParentDef::GenRustConformanceCheck(std::ostream& s) const {
  auto fields = fields_.GetFieldsWithTypes({
      FixedScalarField::kFieldType,
  });

  for (auto const& field : fields) {
    auto start_offset = GetOffsetForField(field->GetName(), false);
    auto end_offset = GetOffsetForField(field->GetName(), true);

    auto f = (FixedScalarField*)field;
    f->GenRustGetter(s, start_offset, end_offset);
    s << "if " << f->GetName() << " != ";
    f->GenValue(s);
    s << " { return false; } ";
  }
}

void ParentDef::GenRustWriteToFields(std::ostream& s) const {
  auto fields = fields_.GetFieldsWithoutTypes({
      BodyField::kFieldType,
      PaddingField::kFieldType,
      ReservedField::kFieldType,
  });

  for (auto const& field : fields) {
    auto start_field_offset = GetOffsetForField(field->GetName(), false);
    auto end_field_offset = GetOffsetForField(field->GetName(), true);

    if (start_field_offset.empty() && end_field_offset.empty()) {
      ERROR(field) << "Field location for " << field->GetName() << " is ambiguous, "
                   << "no method exists to determine field location from begin() or end().\n";
    }

    if (field->GetFieldType() == SizeField::kFieldType) {
      const auto& field_name = ((SizeField*)field)->GetSizedFieldName();
      const auto& sized_field = fields_.GetField(field_name);
      if (sized_field == nullptr) {
        ERROR(field) << __func__ << ": Can't find sized field named " << field_name;
      }
      if (sized_field->GetFieldType() == PayloadField::kFieldType) {
        std::string modifier = ((PayloadField*)sized_field)->size_modifier_;
        if (modifier != "") {
          ERROR(field) << __func__ << ": size modifiers not implemented yet for " << field_name;
        }

        s << "let " << field->GetName() << " = " << field->GetRustDataType()
          << "::try_from(self.child.get_total_size()).expect(\"payload size did not fit\");";
      } else if (sized_field->GetFieldType() == BodyField::kFieldType) {
        s << "let " << field->GetName() << " = " << field->GetRustDataType()
          << "::try_from(self.get_total_size() - self.get_size()).expect(\"payload size did not fit\");";
      } else if (sized_field->GetFieldType() == VectorField::kFieldType) {
        const auto& vector_name = field_name + "_bytes";
        const VectorField* vector = (VectorField*)sized_field;
        if (vector->element_size_.empty() || vector->element_size_.has_dynamic()) {
          s << "let " << vector_name + " = self." << field_name
            << ".iter().fold(0, |acc, x| acc + x.get_total_size());";
        } else {
          s << "let " << vector_name + " = self." << field_name << ".len() * ((" << vector->element_size_ << ") / 8);";
        }
        std::string modifier = vector->GetSizeModifier();
        if (modifier != "") {
          s << "let " << vector_name << " = " << vector_name << " + (" << modifier.substr(1) << ") / 8;";
        }

        s << "let " << field->GetName() << " = " << field->GetRustDataType() << "::try_from(" << vector_name
          << ").expect(\"payload size did not fit\");";
      } else {
        ERROR(field) << __func__ << ": Unhandled sized field type for " << field_name;
      }
    }

    field->GenRustWriter(s, start_field_offset, end_field_offset);
  }
}

void ParentDef::GenSizeRetVal(std::ostream& s) const {
  int size = 0;
  auto fields = fields_.GetFieldsWithoutTypes({
      BodyField::kFieldType,
  });
  const PacketField* padded_field = nullptr;
  auto padding_fields = fields_.GetFieldsWithTypes({
      PaddingField::kFieldType,
  });
  if (padding_fields.size()) {
    PacketField* last_field = nullptr;
    for (const auto field : fields) {
      if (field->GetFieldType() == PaddingField::kFieldType) {
        padded_field = last_field;
      }
      last_field = field;
    }
  }

  s << "let ret = 0;";
  for (const auto field : fields) {
    bool is_vector = field->GetFieldType() == VectorField::kFieldType;
    if (field != padded_field) {  // Skip the size of padded fields
      if (is_vector) {
        if (size > 0) {
          if (size % 8 != 0) {
            ERROR() << "size is not a multiple of 8!\n";
          }
          s << "let ret = ret + " << size / 8 << ";";
          size = 0;
        }

        const VectorField* vector = (VectorField*)field;
        if (vector->element_size_.empty() || vector->element_size_.has_dynamic()) {
          s << "let ret = ret + self." << vector->GetName() << ".iter().fold(0, |acc, x| acc + x.get_total_size());";
        } else {
          s << "let ret = ret + (self." << vector->GetName() << ".len() * ((" << vector->element_size_ << ") / 8));";
        }
      } else {
        size += field->GetSize().bits();
      }
    } else {
      s << "/* Skipping " << field->GetName() << " since it is padded */";
    }
  }
  if (size > 0) {
    if (size % 8 != 0) {
      ERROR() << "size is not a multiple of 8!\n";
    }
    s << "let ret = ret + " << size / 8 << ";";
  }

  s << "ret";
}
