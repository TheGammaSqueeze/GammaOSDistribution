/*
 * Copyright (C) 2015 The Android Open Source Project
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

#include "class_table-inl.h"

#include "base/stl_util.h"
#include "mirror/class-inl.h"
#include "oat_file.h"

namespace art {

ClassTable::ClassTable() : lock_("Class loader classes", kClassLoaderClassesLock) {
  Runtime* const runtime = Runtime::Current();
  classes_.push_back(ClassSet(runtime->GetHashTableMinLoadFactor(),
                              runtime->GetHashTableMaxLoadFactor()));
}

void ClassTable::FreezeSnapshot() {
  WriterMutexLock mu(Thread::Current(), lock_);
  classes_.push_back(ClassSet());
}

ObjPtr<mirror::Class> ClassTable::UpdateClass(const char* descriptor,
                                              ObjPtr<mirror::Class> klass,
                                              size_t hash) {
  WriterMutexLock mu(Thread::Current(), lock_);
  // Should only be updating latest table.
  DescriptorHashPair pair(descriptor, hash);
  auto existing_it = classes_.back().FindWithHash(pair, hash);
  if (existing_it == classes_.back().end()) {
    for (const ClassSet& class_set : classes_) {
      if (class_set.FindWithHash(pair, hash) != class_set.end()) {
        LOG(FATAL) << "Updating class found in frozen table " << descriptor;
      }
    }
    LOG(FATAL) << "Updating class not found " << descriptor;
  }
  const ObjPtr<mirror::Class> existing = existing_it->Read();
  CHECK_NE(existing, klass) << descriptor;
  CHECK(!existing->IsResolved()) << descriptor;
  CHECK_EQ(klass->GetStatus(), ClassStatus::kResolving) << descriptor;
  CHECK(!klass->IsTemp()) << descriptor;
  VerifyObject(klass);
  // Update the element in the hash set with the new class. This is safe to do since the descriptor
  // doesn't change.
  *existing_it = TableSlot(klass, hash);
  return existing;
}

size_t ClassTable::CountDefiningLoaderClasses(ObjPtr<mirror::ClassLoader> defining_loader,
                                              const ClassSet& set) const {
  size_t count = 0;
  for (const TableSlot& root : set) {
    if (root.Read()->GetClassLoader() == defining_loader) {
      ++count;
    }
  }
  return count;
}

size_t ClassTable::NumZygoteClasses(ObjPtr<mirror::ClassLoader> defining_loader) const {
  ReaderMutexLock mu(Thread::Current(), lock_);
  size_t sum = 0;
  for (size_t i = 0; i < classes_.size() - 1; ++i) {
    sum += CountDefiningLoaderClasses(defining_loader, classes_[i]);
  }
  return sum;
}

size_t ClassTable::NumNonZygoteClasses(ObjPtr<mirror::ClassLoader> defining_loader) const {
  ReaderMutexLock mu(Thread::Current(), lock_);
  return CountDefiningLoaderClasses(defining_loader, classes_.back());
}

size_t ClassTable::NumReferencedZygoteClasses() const {
  ReaderMutexLock mu(Thread::Current(), lock_);
  size_t sum = 0;
  for (size_t i = 0; i < classes_.size() - 1; ++i) {
    sum += classes_[i].size();
  }
  return sum;
}

size_t ClassTable::NumReferencedNonZygoteClasses() const {
  ReaderMutexLock mu(Thread::Current(), lock_);
  return classes_.back().size();
}

ObjPtr<mirror::Class> ClassTable::Lookup(const char* descriptor, size_t hash) {
  DescriptorHashPair pair(descriptor, hash);
  ReaderMutexLock mu(Thread::Current(), lock_);
  for (ClassSet& class_set : classes_) {
    auto it = class_set.FindWithHash(pair, hash);
    if (it != class_set.end()) {
      return it->Read();
    }
  }
  return nullptr;
}

void ClassTable::Insert(ObjPtr<mirror::Class> klass) {
  InsertWithHash(klass, TableSlot::HashDescriptor(klass));
}

void ClassTable::InsertWithHash(ObjPtr<mirror::Class> klass, size_t hash) {
  WriterMutexLock mu(Thread::Current(), lock_);
  classes_.back().InsertWithHash(TableSlot(klass, hash), hash);
}

bool ClassTable::Remove(const char* descriptor) {
  DescriptorHashPair pair(descriptor, ComputeModifiedUtf8Hash(descriptor));
  WriterMutexLock mu(Thread::Current(), lock_);
  for (ClassSet& class_set : classes_) {
    auto it = class_set.find(pair);
    if (it != class_set.end()) {
      class_set.erase(it);
      return true;
    }
  }
  return false;
}

bool ClassTable::InsertStrongRoot(ObjPtr<mirror::Object> obj) {
  WriterMutexLock mu(Thread::Current(), lock_);
  DCHECK(obj != nullptr);
  for (GcRoot<mirror::Object>& root : strong_roots_) {
    if (root.Read() == obj) {
      return false;
    }
  }
  strong_roots_.push_back(GcRoot<mirror::Object>(obj));
  // If `obj` is a dex cache associated with a new oat file with GC roots, add it to oat_files_.
  if (obj->IsDexCache()) {
    const DexFile* dex_file = ObjPtr<mirror::DexCache>::DownCast(obj)->GetDexFile();
    if (dex_file != nullptr && dex_file->GetOatDexFile() != nullptr) {
      const OatFile* oat_file = dex_file->GetOatDexFile()->GetOatFile();
      if (oat_file != nullptr && !oat_file->GetBssGcRoots().empty()) {
        InsertOatFileLocked(oat_file);  // Ignore return value.
      }
    }
  }
  return true;
}

bool ClassTable::InsertOatFile(const OatFile* oat_file) {
  WriterMutexLock mu(Thread::Current(), lock_);
  return InsertOatFileLocked(oat_file);
}

bool ClassTable::InsertOatFileLocked(const OatFile* oat_file) {
  if (ContainsElement(oat_files_, oat_file)) {
    return false;
  }
  oat_files_.push_back(oat_file);
  return true;
}

size_t ClassTable::ReadFromMemory(uint8_t* ptr) {
  size_t read_count = 0;
  AddClassSet(ClassSet(ptr, /*make copy*/false, &read_count));
  return read_count;
}

void ClassTable::AddClassSet(ClassSet&& set) {
  WriterMutexLock mu(Thread::Current(), lock_);
  classes_.insert(classes_.begin(), std::move(set));
}

void ClassTable::ClearStrongRoots() {
  WriterMutexLock mu(Thread::Current(), lock_);
  oat_files_.clear();
  strong_roots_.clear();
}

ClassTable::TableSlot::TableSlot(ObjPtr<mirror::Class> klass)
    : TableSlot(klass, HashDescriptor(klass)) {}

uint32_t ClassTable::TableSlot::HashDescriptor(ObjPtr<mirror::Class> klass) {
  std::string temp;
  return ComputeModifiedUtf8Hash(klass->GetDescriptor(&temp));
}

}  // namespace art
