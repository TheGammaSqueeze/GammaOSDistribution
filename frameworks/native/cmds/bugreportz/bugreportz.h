// Copyright 2016 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef BUGREPORTZ_H
#define BUGREPORTZ_H

// Calls dumpstate using the given socket and output its result to stdout.
// Ownership of the socket is not transferred.
int bugreportz(int s, bool show_progress);

// Calls dumpstate using the given socket and write the file content to stdout
// instead of file location. Ownership of the socket is not transferred.
int bugreportz_stream(int s);

#endif  // BUGREPORTZ_H
