package com.android.systemui.dump;

import android.content.Context;
import android.util.Log;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.util.io.Files;
import com.android.systemui.util.time.SystemClock;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UncheckedIOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributes;
import java.text.SimpleDateFormat;
import java.util.Locale;
import java.util.concurrent.TimeUnit;
import javax.inject.Inject;

/**
 * Dumps all [LogBuffer]s to a file
 *
 * Intended for emergencies, i.e. we're about to crash. This file can then be read at a later date
 * (usually in a bug report).
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001B\'\b\u0017\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nB5\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u000e\u00a2\u0006\u0002\u0010\u0010J\u0010\u0010\u0011\u001a\u00020\u000e2\u0006\u0010\u0012\u001a\u00020\fH\u0002J\u000e\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016J!\u0010\u0017\u001a\u0002H\u0018\"\f\b\u0000\u0010\u0018*\u00060\u0019j\u0002`\u001a2\u0006\u0010\u001b\u001a\u0002H\u0018\u00a2\u0006\u0002\u0010\u001cR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/dump/LogBufferEulogizer;", "", "context", "Landroid/content/Context;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "files", "Lcom/android/systemui/util/io/Files;", "(Landroid/content/Context;Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/util/io/Files;)V", "logPath", "Ljava/nio/file/Path;", "minWriteGap", "", "maxLogAgeToDump", "(Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/util/io/Files;Ljava/nio/file/Path;JJ)V", "getMillisSinceLastWrite", "path", "readEulogyIfPresent", "", "pw", "Ljava/io/PrintWriter;", "record", "T", "Ljava/lang/Exception;", "Lkotlin/Exception;", "reason", "(Ljava/lang/Exception;)Ljava/lang/Exception;"})
@com.android.systemui.dagger.SysUISingleton()
public final class LogBufferEulogizer {
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    private final com.android.systemui.util.io.Files files = null;
    private final java.nio.file.Path logPath = null;
    private final long minWriteGap = 0L;
    private final long maxLogAgeToDump = 0L;
    
    /**
     * Dumps all active log buffers to a file
     *
     * The file will be prefaced by the [reason], which will then be returned (presumably so it can
     * be thrown).
     */
    @org.jetbrains.annotations.NotNull()
    public final <T extends java.lang.Exception>T record(@org.jetbrains.annotations.NotNull()
    T reason) {
        return null;
    }
    
    /**
     * If a eulogy file is present, writes its contents to [pw].
     */
    public final void readEulogyIfPresent(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw) {
    }
    
    private final long getMillisSinceLastWrite(java.nio.file.Path path) {
        return 0L;
    }
    
    public LogBufferEulogizer(@org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.io.Files files, @org.jetbrains.annotations.NotNull()
    java.nio.file.Path logPath, long minWriteGap, long maxLogAgeToDump) {
        super();
    }
    
    @javax.inject.Inject()
    public LogBufferEulogizer(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.io.Files files) {
        super();
    }
}