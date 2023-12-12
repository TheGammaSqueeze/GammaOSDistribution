package com.android.systemui.dump;

import android.content.Context;
import android.os.SystemClock;
import android.os.Trace;
import com.android.systemui.R;
import com.android.systemui.log.LogBuffer;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

/**
 * Oversees SystemUI's output during bug reports (and dumpsys in general)
 *
 * Dump output is split into two sections, CRITICAL and NORMAL. In general, the CRITICAL section
 * contains all dumpables that were registered to the [DumpManager], while the NORMAL sections
 * contains all [LogBuffer]s (due to their length).
 *
 * The CRITICAL and NORMAL sections can be found within a bug report by searching for
 * "SERVICE com.android.systemui/.SystemUIService" and
 * "SERVICE com.android.systemui/.dump.SystemUIAuxiliaryDumpService", respectively.
 *
 * Finally, some or all of the dump can be triggered on-demand via adb (see below).
 *
 * ```
 * # For the following, let <invocation> be:
 * $ adb shell dumpsys activity service com.android.systemui/.SystemUIService
 *
 * # To dump specific target(s), specify one or more registered names:
 * $ <invocation> NotifCollection
 * $ <invocation> StatusBar FalsingManager BootCompleteCacheImpl
 *
 * # Log buffers can be dumped in the same way (and can even be mixed in with other dump targets,
 * # although it's not clear why one would want such a thing):
 * $ <invocation> NotifLog
 * $ <invocation> StatusBar NotifLog BootCompleteCacheImpl
 *
 * # If passing -t or --tail, shows only the last N lines of any log buffers:
 * $ <invocation> NotifLog --tail 100
 *
 * # Dump targets are matched using String.endsWith(), so dumpables that register using their
 * # fully-qualified class name can still be dumped using their short name:
 * $ <invocation> com.android.keyguard.KeyguardUpdateMonitor
 * $ <invocation> keyguard.KeyguardUpdateMonitor
 * $ <invocation> KeyguardUpdateMonitor
 *
 * # To dump all dumpables or all buffers:
 * $ <invocation> dumpables
 * $ <invocation> buffers
 *
 * # Finally, the following will simulate what we dump during the CRITICAL and NORMAL sections of a
 * # bug report:
 * $ <invocation> bugreport-critical
 * $ <invocation> bugreport-normal
 *
 * # And if you need to be reminded of this list of commands:
 * $ <invocation> -h
 * $ <invocation> --help
 * ```
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000h\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\b\u0005\n\u0002\u0010)\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u0000 02\u00020\u0001:\u00010B\u001f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ)\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010\u00a2\u0006\u0002\u0010\u0012J\u0018\u0010\u0013\u001a\u00020\n2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0014H\u0002J\u0010\u0010\u0015\u001a\u00020\n2\u0006\u0010\r\u001a\u00020\u000eH\u0002J \u0010\u0016\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0014H\u0002J \u0010\u0017\u001a\u00020\n2\u0006\u0010\u0018\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0014H\u0002J\u0010\u0010\u0019\u001a\u00020\n2\u0006\u0010\r\u001a\u00020\u000eH\u0002J\u0018\u0010\u001a\u001a\u00020\n2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0014H\u0002J \u0010\u001b\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0014H\u0002J \u0010\u001c\u001a\u00020\n2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u001d\u001a\u00020\u00112\u0006\u0010\u001e\u001a\u00020\u001fH\u0002J.\u0010 \u001a\u00020\n2\f\u0010!\u001a\b\u0012\u0004\u0012\u00020\u00110\"2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0014H\u0002J\u001b\u0010#\u001a\u00020\u00142\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010H\u0002\u00a2\u0006\u0002\u0010$JL\u0010%\u001a\u0002H&\"\u0004\b\u0000\u0010&2\f\u0010\'\u001a\b\u0012\u0004\u0012\u00020\u00110(2\u0006\u0010)\u001a\u00020\u00112!\u0010*\u001a\u001d\u0012\u0013\u0012\u00110\u0011\u00a2\u0006\f\b,\u0012\b\b-\u0012\u0004\b\b(.\u0012\u0004\u0012\u0002H&0+H\u0002\u00a2\u0006\u0002\u0010/R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/dump/DumpHandler;", "", "context", "Landroid/content/Context;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "logBufferEulogizer", "Lcom/android/systemui/dump/LogBufferEulogizer;", "(Landroid/content/Context;Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/dump/LogBufferEulogizer;)V", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "dumpBuffers", "Lcom/android/systemui/dump/ParsedArgs;", "dumpConfig", "dumpCritical", "dumpDumpables", "fw", "dumpHelp", "dumpNormal", "dumpParameterized", "dumpServiceList", "type", "resId", "", "dumpTargets", "targets", "", "parseArgs", "([Ljava/lang/String;)Lcom/android/systemui/dump/ParsedArgs;", "readArgument", "T", "iterator", "", "flag", "parser", "Lkotlin/Function1;", "Lkotlin/ParameterName;", "name", "arg", "(Ljava/util/Iterator;Ljava/lang/String;Lkotlin/jvm/functions/Function1;)Ljava/lang/Object;", "Companion"})
public final class DumpHandler {
    private final android.content.Context context = null;
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final com.android.systemui.dump.LogBufferEulogizer logBufferEulogizer = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PRIORITY_ARG = "--dump-priority";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PRIORITY_ARG_CRITICAL = "CRITICAL";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PRIORITY_ARG_HIGH = "HIGH";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PRIORITY_ARG_NORMAL = "NORMAL";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.dump.DumpHandler.Companion Companion = null;
    
    /**
     * Dump the diagnostics! Behavior can be controlled via [args].
     */
    public final void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    private final void dumpParameterized(java.io.FileDescriptor fd, java.io.PrintWriter pw, com.android.systemui.dump.ParsedArgs args) {
    }
    
    private final void dumpCritical(java.io.FileDescriptor fd, java.io.PrintWriter pw, com.android.systemui.dump.ParsedArgs args) {
    }
    
    private final void dumpNormal(java.io.PrintWriter pw, com.android.systemui.dump.ParsedArgs args) {
    }
    
    private final void dumpDumpables(java.io.FileDescriptor fw, java.io.PrintWriter pw, com.android.systemui.dump.ParsedArgs args) {
    }
    
    private final void dumpBuffers(java.io.PrintWriter pw, com.android.systemui.dump.ParsedArgs args) {
    }
    
    private final void dumpTargets(java.util.List<java.lang.String> targets, java.io.FileDescriptor fd, java.io.PrintWriter pw, com.android.systemui.dump.ParsedArgs args) {
    }
    
    private final void dumpConfig(java.io.PrintWriter pw) {
    }
    
    private final void dumpServiceList(java.io.PrintWriter pw, java.lang.String type, int resId) {
    }
    
    private final void dumpHelp(java.io.PrintWriter pw) {
    }
    
    private final com.android.systemui.dump.ParsedArgs parseArgs(java.lang.String[] args) {
        return null;
    }
    
    private final <T extends java.lang.Object>T readArgument(java.util.Iterator<java.lang.String> iterator, java.lang.String flag, kotlin.jvm.functions.Function1<? super java.lang.String, ? extends T> parser) {
        return null;
    }
    
    @javax.inject.Inject()
    public DumpHandler(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.LogBufferEulogizer logBufferEulogizer) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/dump/DumpHandler$Companion;", "", "()V", "PRIORITY_ARG", "", "PRIORITY_ARG_CRITICAL", "PRIORITY_ARG_HIGH", "PRIORITY_ARG_NORMAL"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}