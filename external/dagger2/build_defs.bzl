# Copyright (C) 2017 The Dagger Authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""This file defines constants useful across the Dagger build."""

DOCLINT_HTML_AND_SYNTAX = ["-Xdoclint:html,syntax"]

DOCLINT_REFERENCES = ["-Xdoclint:reference"]

SOURCE_7_TARGET_7 = [
    "-source",
    "1.7",
    "-target",
    "1.7",
]

POM_VERSION = "2.29.1"

# DO NOT remove the comment on the next line. It's used in deploy-to-maven-central.sh
POM_VERSION_ALPHA = POM_VERSION  + "-alpha"
