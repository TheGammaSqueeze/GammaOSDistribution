package com.android.systemui.log;

import android.util.Log;

/**
 * Enum version of @Log.Level
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u000b\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u0017\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nj\u0002\b\u000bj\u0002\b\fj\u0002\b\rj\u0002\b\u000ej\u0002\b\u000fj\u0002\b\u0010"}, d2 = {"Lcom/android/systemui/log/LogLevel;", "", "nativeLevel", "", "shortString", "", "(Ljava/lang/String;IILjava/lang/String;)V", "getNativeLevel", "()I", "getShortString", "()Ljava/lang/String;", "VERBOSE", "DEBUG", "INFO", "WARNING", "ERROR", "WTF"})
public enum LogLevel {
    /*public static final*/ VERBOSE /* = new VERBOSE(0, null) */,
    /*public static final*/ DEBUG /* = new DEBUG(0, null) */,
    /*public static final*/ INFO /* = new INFO(0, null) */,
    /*public static final*/ WARNING /* = new WARNING(0, null) */,
    /*public static final*/ ERROR /* = new ERROR(0, null) */,
    /*public static final*/ WTF /* = new WTF(0, null) */;
    private final int nativeLevel = 0;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String shortString = null;
    
    public final int getNativeLevel() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getShortString() {
        return null;
    }
    
    LogLevel(@android.util.Log.Level()
    int nativeLevel, java.lang.String shortString) {
    }
}