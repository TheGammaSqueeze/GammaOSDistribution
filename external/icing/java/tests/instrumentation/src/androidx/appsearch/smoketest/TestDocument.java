/*
 * Copyright (C) 2020 The Android Open Source Project
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

package androidx.appsearch.smoketest;

import androidx.appsearch.annotation.Document;
import androidx.appsearch.app.AppSearchSchema.StringPropertyConfig;

@Document
public class TestDocument {
    @Document.Uri private final String uri;

    @Document.Property(indexingType = StringPropertyConfig.INDEXING_TYPE_PREFIXES)
    private final String body;

    TestDocument(String uri, String body) {
        this.uri = uri;
        this.body = body;
    }

    public String getUri() {
        return uri;
    }

    public String getBody() {
        return body;
    }
}
