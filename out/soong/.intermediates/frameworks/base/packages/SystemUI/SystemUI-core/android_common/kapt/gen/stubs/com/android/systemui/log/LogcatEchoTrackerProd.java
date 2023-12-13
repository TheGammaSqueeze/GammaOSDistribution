package com.android.systemui.log;

import java.lang.System;

/**
 * Production version of [LogcatEchoTracker] that isn't configurable.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016J\u0018\u0010\t\u001a\u00020\u00042\u0006\u0010\n\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016"}, d2 = {"Lcom/android/systemui/log/LogcatEchoTrackerProd;", "Lcom/android/systemui/log/LogcatEchoTracker;", "()V", "isBufferLoggable", "", "bufferName", "", "level", "Lcom/android/systemui/log/LogLevel;", "isTagLoggable", "tagName"})
public final class LogcatEchoTrackerProd implements com.android.systemui.log.LogcatEchoTracker {
    
    @java.lang.Override()
    public boolean isBufferLoggable(@org.jetbrains.annotations.NotNull()
    java.lang.String bufferName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level) {
        return false;
    }
    
    @java.lang.Override()
    public boolean isTagLoggable(@org.jetbrains.annotations.NotNull()
    java.lang.String tagName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level) {
        return false;
    }
    
    public LogcatEchoTrackerProd() {
        super();
    }
}