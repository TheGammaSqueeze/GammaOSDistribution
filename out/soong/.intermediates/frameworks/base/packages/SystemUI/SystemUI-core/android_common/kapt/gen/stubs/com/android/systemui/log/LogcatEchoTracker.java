package com.android.systemui.log;

import java.lang.System;

/**
 * Keeps track of which [LogBuffer] messages should also appear in logcat.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\bf\u0018\u00002\u00020\u0001J\u0018\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0007H&J\u0018\u0010\b\u001a\u00020\u00032\u0006\u0010\t\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0007H&"}, d2 = {"Lcom/android/systemui/log/LogcatEchoTracker;", "", "isBufferLoggable", "", "bufferName", "", "level", "Lcom/android/systemui/log/LogLevel;", "isTagLoggable", "tagName"})
public abstract interface LogcatEchoTracker {
    
    /**
     * Whether [bufferName] should echo messages of [level] or higher to logcat.
     */
    public abstract boolean isBufferLoggable(@org.jetbrains.annotations.NotNull()
    java.lang.String bufferName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level);
    
    /**
     * Whether [tagName] should echo messages of [level] or higher to logcat.
     */
    public abstract boolean isTagLoggable(@org.jetbrains.annotations.NotNull()
    java.lang.String tagName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level);
}