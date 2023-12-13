#
# Copyright (C) 2020 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Enable ART Module top level apex/sdk/module_export modules. When they are
# enabled the ART Module prebuilts (packages/modules/ArtPrebuilt and
# prebuilts/module_sdk/art) cannot be present with prefer:true in the build
# tree.
# TODO(b/174997203): Clean up the art_module_* products when there is a better
# way to switch between prebuilts and sources.
$(call add_soong_config_namespace,art_module)
$(call add_soong_config_var_value,art_module,source_build,true)
