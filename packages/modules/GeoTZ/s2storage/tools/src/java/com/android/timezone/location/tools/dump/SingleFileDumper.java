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

package com.android.timezone.location.tools.dump;

import static com.android.timezone.location.tools.dump.DumpUtils.createPrintWriter;

import com.android.timezone.location.storage.util.Visitor;

import java.io.File;
import java.io.PrintWriter;
import java.util.Objects;

/**
 * A class that can be used as a base class for a visitor that dumps information to a single file,
 * or as a helper for one.
 */
class SingleFileDumper implements Visitor {

    private final File mFile;

    protected PrintWriter mWriter;

    SingleFileDumper(File file) {
        mFile = Objects.requireNonNull(file);
    }

    @Override
    public void begin() throws Visitor.VisitException {
        mWriter = createPrintWriter(mFile);
    }

    public void println(String string) {
        mWriter.println(string);
    }

    public void println() {
        mWriter.println();
    }

    @Override
    public void end() throws Visitor.VisitException {
        mWriter.close();
    }
}
