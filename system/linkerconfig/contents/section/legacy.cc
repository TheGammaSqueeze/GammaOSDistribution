/*
 * Copyright (C) 2019 The Android Open Source Project
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

#include "linkerconfig/sectionbuilder.h"

#include "linkerconfig/common.h"
#include "linkerconfig/namespacebuilder.h"
#include "linkerconfig/section.h"

using android::linkerconfig::contents::SectionType;
using android::linkerconfig::modules::Namespace;
using android::linkerconfig::modules::Section;

namespace android {
namespace linkerconfig {
namespace contents {
Section BuildLegacySection(Context& ctx) {
  ctx.SetCurrentSection(SectionType::System);
  std::vector<Namespace> namespaces;

  namespaces.emplace_back(BuildSystemDefaultNamespace(ctx));

  std::set<std::string> visible_apexes;

  // APEXes with JNI libs or public libs should be visible
  for (const auto& apex : ctx.GetApexModules()) {
    if (apex.jni_libs.size() > 0 || apex.public_libs.size() > 0) {
      visible_apexes.insert(apex.name);
    }
  }

  return BuildSection(ctx, "legacy", std::move(namespaces), visible_apexes);
}
}  // namespace contents
}  // namespace linkerconfig
}  // namespace android
