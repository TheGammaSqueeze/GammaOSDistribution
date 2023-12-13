package com.android.permissioncontroller.permission.utils;

import java.lang.System;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0016\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\u001a\u0014\u0010\u0000\u001a\u0010\u0012\f\u0012\n \u0003*\u0004\u0018\u00010\u00020\u00020\u0001\u001a\u0006\u0010\u0004\u001a\u00020\u0005\u001a\u001c\u0010\u0006\u001a\u0010\u0012\f\u0012\n \u0003*\u0004\u0018\u00010\u00020\u00020\u00012\u0006\u0010\u0007\u001a\u00020\u0005\u001a\u0010\u0010\b\u001a\u00020\u0005*\b\u0012\u0004\u0012\u00020\u00020\u0001"}, d2 = {"permissionsStackTrace", "", "Ljava/lang/StackTraceElement;", "kotlin.jvm.PlatformType", "shortStackTrace", "", "stackTraceWithin", "pkgPrefix", "toShortString"})
public final class DebugUtilsKt {
    
    /**
     * A short version of the permission-only stack trace, suitable to use in debug logs.
     *
     * See [toShortString]
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String shortStackTrace() {
        return null;
    }
    
    /**
     * [StackTraceElement]s of only the permission-related frames
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.util.List<java.lang.StackTraceElement> permissionsStackTrace() {
        return null;
    }
    
    /**
     * [StackTraceElement]s of only frames who's [full class name][StackTraceElement.getClassName]
     * starts with [pkgPrefix]
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.util.List<java.lang.StackTraceElement> stackTraceWithin(@org.jetbrains.annotations.NotNull()
    java.lang.String pkgPrefix) {
        return null;
    }
    
    /**
     * Renders a stack trace slice to a short-ish single-line string.
     *
     * Suitable for debugging when full stack trace can be too spammy.
     */
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String toShortString(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.StackTraceElement> $this$toShortString) {
        return null;
    }
}