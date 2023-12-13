#!/bin/bash
#  Copyright (C) 2021 The Android Open Source Project
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

# Run this script to regenerate the overlayable.xml file.

if [[ -z "$ANDROID_BUILD_TOP" ]]; then
  echo 'ANDROID_BUILD_TOP environment variable is empty; did you forget to run `lunch`?'
  exit 1
fi

PROJECT_TOP=$ANDROID_BUILD_TOP/packages/apps/Car/Media

python3 $ANDROID_BUILD_TOP/packages/apps/Car/tests/tools/rro/generate-overlayable.py \
    -n CarMediaApp \
    -r $PROJECT_TOP/res \
    -e $PROJECT_TOP/res/values/overlayable.xml $PROJECT_TOP/res/xml/automotive_app_desc.xml $PROJECT_TOP/res/values/colors.xml $PROJECT_TOP/res/values/dimens.xml $PROJECT_TOP/res/color/progress_bar_thumb_inner_ring_color.xml $PROJECT_TOP/res/color/progress_bar_thumb_outer_ring_color.xml \
    -o $PROJECT_TOP/res/values/overlayable.xml