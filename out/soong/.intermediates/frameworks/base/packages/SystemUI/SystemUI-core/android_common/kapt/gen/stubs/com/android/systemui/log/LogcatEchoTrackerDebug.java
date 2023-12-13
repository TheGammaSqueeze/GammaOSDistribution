package com.android.systemui.log;

import android.content.ContentResolver;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Handler;
import android.os.Looper;
import android.provider.Settings;

/**
 * Version of [LogcatEchoTracker] for debuggable builds
 *
 * The log level of individual buffers or tags can be controlled via global settings:
 *
 * ```
 * # Echo any message to <bufferName> of <level> or higher
 * $ adb shell settings put global systemui/buffer/<bufferName> <level>
 *
 * # Echo any message of <tag> and of <level> or higher
 * $ adb shell settings put global systemui/tag/<tag> <level>
 * ```
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\b\u0018\u0000 \u001b2\u00020\u0001:\u0001\u001bB\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rH\u0002J,\u0010\u000e\u001a\u00020\b2\u0006\u0010\u000f\u001a\u00020\u00072\u0006\u0010\u0010\u001a\u00020\u00072\u0012\u0010\u0011\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\b0\u0006H\u0002J\u0018\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u00072\u0006\u0010\u0015\u001a\u00020\bH\u0016J\u0018\u0010\u0016\u001a\u00020\u00132\u0006\u0010\u0017\u001a\u00020\u00072\u0006\u0010\u0015\u001a\u00020\bH\u0016J\u0012\u0010\u0018\u001a\u00020\b2\b\u0010\u0019\u001a\u0004\u0018\u00010\u0007H\u0002J\u0010\u0010\u001a\u001a\u00020\b2\u0006\u0010\u0010\u001a\u00020\u0007H\u0002R\u001a\u0010\u0005\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\b0\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\t\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\b0\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/log/LogcatEchoTrackerDebug;", "Lcom/android/systemui/log/LogcatEchoTracker;", "contentResolver", "Landroid/content/ContentResolver;", "(Landroid/content/ContentResolver;)V", "cachedBufferLevels", "", "", "Lcom/android/systemui/log/LogLevel;", "cachedTagLevels", "attach", "", "mainLooper", "Landroid/os/Looper;", "getLogLevel", "name", "path", "cache", "isBufferLoggable", "", "bufferName", "level", "isTagLoggable", "tagName", "parseProp", "propValue", "readSetting", "Factory"})
public final class LogcatEchoTrackerDebug implements com.android.systemui.log.LogcatEchoTracker {
    private final java.util.Map<java.lang.String, com.android.systemui.log.LogLevel> cachedBufferLevels = null;
    private final java.util.Map<java.lang.String, com.android.systemui.log.LogLevel> cachedTagLevels = null;
    private final android.content.ContentResolver contentResolver = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.log.LogcatEchoTrackerDebug.Factory Factory = null;
    
    private final void attach(android.os.Looper mainLooper) {
    }
    
    /**
     * Whether [bufferName] should echo messages of [level] or higher to logcat.
     */
    @java.lang.Override()
    public synchronized boolean isBufferLoggable(@org.jetbrains.annotations.NotNull()
    java.lang.String bufferName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level) {
        return false;
    }
    
    /**
     * Whether [tagName] should echo messages of [level] or higher to logcat.
     */
    @java.lang.Override()
    public synchronized boolean isTagLoggable(@org.jetbrains.annotations.NotNull()
    java.lang.String tagName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level) {
        return false;
    }
    
    private final com.android.systemui.log.LogLevel getLogLevel(java.lang.String name, java.lang.String path, java.util.Map<java.lang.String, com.android.systemui.log.LogLevel> cache) {
        return null;
    }
    
    private final com.android.systemui.log.LogLevel readSetting(java.lang.String path) {
        return null;
    }
    
    private final com.android.systemui.log.LogLevel parseProp(java.lang.String propValue) {
        return null;
    }
    
    private LogcatEchoTrackerDebug(android.content.ContentResolver contentResolver) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.log.LogcatEchoTrackerDebug create(@org.jetbrains.annotations.NotNull()
    android.content.ContentResolver contentResolver, @org.jetbrains.annotations.NotNull()
    android.os.Looper mainLooper) {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0007"}, d2 = {"Lcom/android/systemui/log/LogcatEchoTrackerDebug$Factory;", "", "()V", "create", "Lcom/android/systemui/log/LogcatEchoTrackerDebug;", "contentResolver", "Landroid/content/ContentResolver;", "mainLooper", "Landroid/os/Looper;"})
    public static final class Factory {
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.log.LogcatEchoTrackerDebug create(@org.jetbrains.annotations.NotNull()
        android.content.ContentResolver contentResolver, @org.jetbrains.annotations.NotNull()
        android.os.Looper mainLooper) {
            return null;
        }
        
        private Factory() {
            super();
        }
    }
}