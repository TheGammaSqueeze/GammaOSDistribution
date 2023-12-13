/*
 * Copyright (C) 2021 The Android Open Source Project
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
package com.android.annotationvisitor;

import org.apache.bcel.classfile.JavaClass;

import java.util.Formatter;
import java.util.Locale;

/**
 * Encapsulates context for a single annotation on a class.
 */
public class AnnotatedClassContext extends AnnotationContext {

    public final String signatureFormatString;

    public AnnotatedClassContext(
            Status status,
            JavaClass definingClass,
            String signatureFormatString) {
        super(status, definingClass);
        this.signatureFormatString = signatureFormatString;
    }

    @Override
    public String getMemberDescriptor() {
        return String.format(Locale.US, signatureFormatString, getClassDescriptor());
    }

    private String buildReportString(String message, Object... args) {
        Formatter error = new Formatter();
        error
                .format("%s: %s: ", definingClass.getSourceFileName(), definingClass.getClassName())
                .format(Locale.US, message, args);
        return error.toString();
    }

    @Override
    public void reportError(String message, Object... args) {
        status.error(buildReportString(message, args));
    }

    @Override
    public void reportWarning(String message, Object... args) {
        status.warning(buildReportString(message, args));
    }

}
