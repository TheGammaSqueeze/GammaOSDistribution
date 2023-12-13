// Copyright (C) 2018 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "base/System.h"

#include "Standalone.h"

#include <functional>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace emugl {

class HelloTriangle : public SampleApplication {
protected:
    struct VertexAttributes {
        float position[2];
        float color[3];
    };
    void initialize() override;
    void draw() override;

private:
    GLint mTransformLoc;
    GLuint mBuffer;
    float mTime = 0.0f;
};

}  // namespace emugl
