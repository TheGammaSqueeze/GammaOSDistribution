/*
 * Copyright 2021 The Android Open Source Project
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

package android.app.appsearch.cts.app;

import static com.google.common.truth.Truth.assertThat;

import android.app.appsearch.RemoveByDocumentIdRequest;

import org.junit.Test;

import java.util.Arrays;

public class RemoveByDocumentIdRequestCtsTest {
    @Test
    public void testBuildRequest() {
        RemoveByDocumentIdRequest request =
                new RemoveByDocumentIdRequest.Builder("namespace")
                        .addIds("uri1", "uri2")
                        .addIds(Arrays.asList("uri3"))
                        .build();

        assertThat(request.getNamespace()).isEqualTo("namespace");
        assertThat(request.getIds()).containsExactly("uri1", "uri2", "uri3").inOrder();
    }
}
