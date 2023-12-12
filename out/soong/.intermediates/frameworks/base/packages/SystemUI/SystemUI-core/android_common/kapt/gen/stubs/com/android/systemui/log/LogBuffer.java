package com.android.systemui.log;

import android.util.Log;
import com.android.systemui.log.dagger.LogModule;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayDeque;
import java.util.Locale;

/**
 * A simple ring buffer of recyclable log messages
 *
 * The goal of this class is to enable logging that is both extremely chatty and extremely
 * lightweight. If done properly, logging a message will not result in any heap allocations or
 * string generation. Messages are only converted to strings if the log is actually dumped (usually
 * as the result of taking a bug report).
 *
 * You can dump the entire buffer at any time by running:
 *
 * ```
 * $ adb shell dumpsys activity service com.android.systemui/.SystemUIService <bufferName>
 * ```
 *
 * ...where `bufferName` is the (case-sensitive) [name] passed to the constructor.
 *
 * By default, only messages of WARN level or higher are echoed to logcat, but this can be adjusted
 * locally (usually for debugging purposes).
 *
 * To enable logcat echoing for an entire buffer:
 *
 * ```
 * $ adb shell settings put global systemui/buffer/<bufferName> <level>
 * ```
 *
 * To enable logcat echoing for a specific tag:
 *
 * ```
 * $ adb shell settings put global systemui/tag/<tag> <level>
 * ```
 *
 * In either case, `level` can be any of `verbose`, `debug`, `info`, `warn`, `error`, `assert`, or
 * the first letter of any of the previous.
 *
 * Buffers are provided by [LogModule]. Instances should be created using a [LogBufferFactory].
 *
 * @param name The name of this buffer
 * @param maxLogs The maximum number of messages to keep in memory at any one time, including the
 * unused pool. Must be >= [poolSize].
 * @param poolSize The maximum amount that the size of the buffer is allowed to flex in response to
 * sequential calls to [document] that aren't immediately followed by a matching call to [push].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000X\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\t\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJP\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u00032\u0006\u0010\u0015\u001a\u00020\u00162\u0017\u0010\u0017\u001a\u0013\u0012\u0004\u0012\u00020\u0013\u0012\u0004\u0012\u00020\u00190\u0018\u00a2\u0006\u0002\b\u001a2\u0019\b\b\u0010\u001b\u001a\u0013\u0012\u0004\u0012\u00020\u0013\u0012\u0004\u0012\u00020\u00030\u0018\u00a2\u0006\u0002\b\u001aH\u0086\b\u00f8\u0001\u0000J\u0016\u0010\u001c\u001a\u00020\u00192\u0006\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020\u0005J\u0018\u0010 \u001a\u00020\u00192\u0006\u0010!\u001a\u00020\u00132\u0006\u0010\u001d\u001a\u00020\u001eH\u0002J\u0010\u0010\"\u001a\u00020\u00192\u0006\u0010!\u001a\u00020\u0013H\u0002J\u0006\u0010#\u001a\u00020\u0019JP\u0010$\u001a\u00020\u00192\u0006\u0010\u0014\u001a\u00020\u00032\u0006\u0010\u0015\u001a\u00020\u00162\u0017\u0010\u0017\u001a\u0013\u0012\u0004\u0012\u00020\u0013\u0012\u0004\u0012\u00020\u00190\u0018\u00a2\u0006\u0002\b\u001a2\u0019\b\b\u0010\u001b\u001a\u0013\u0012\u0004\u0012\u00020\u0013\u0012\u0004\u0012\u00020\u00030\u0018\u00a2\u0006\u0002\b\u001aH\u0086\b\u00f8\u0001\u0000J*\u0010%\u001a\u00020\f2\u0006\u0010\u0014\u001a\u00020\u00032\u0006\u0010\u0015\u001a\u00020\u00162\u0012\u0010\u001b\u001a\u000e\u0012\u0004\u0012\u00020\u0013\u0012\u0004\u0012\u00020\u00030\u0018J\u000e\u0010&\u001a\u00020\u00192\u0006\u0010!\u001a\u00020\u0013J\u0006\u0010\'\u001a\u00020\u0019R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u000f\u001a\u00020\u000e2\u0006\u0010\r\u001a\u00020\u000e@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0007\n\u0005\b\u009920\u0001"}, d2 = {"Lcom/android/systemui/log/LogBuffer;", "", "name", "", "maxLogs", "", "poolSize", "logcatEchoTracker", "Lcom/android/systemui/log/LogcatEchoTracker;", "(Ljava/lang/String;IILcom/android/systemui/log/LogcatEchoTracker;)V", "buffer", "Ljava/util/ArrayDeque;", "Lcom/android/systemui/log/LogMessageImpl;", "<set-?>", "", "frozen", "getFrozen", "()Z", "document", "Lcom/android/systemui/log/LogMessage;", "tag", "level", "Lcom/android/systemui/log/LogLevel;", "initializer", "Lkotlin/Function1;", "", "Lkotlin/ExtensionFunctionType;", "printer", "dump", "pw", "Ljava/io/PrintWriter;", "tailLength", "dumpMessage", "message", "echoToLogcat", "freeze", "log", "obtain", "push", "unfreeze"})
public final class LogBuffer {
    private final java.util.ArrayDeque<com.android.systemui.log.LogMessageImpl> buffer = null;
    private boolean frozen = false;
    private final java.lang.String name = null;
    private final int maxLogs = 0;
    private final int poolSize = 0;
    private final com.android.systemui.log.LogcatEchoTracker logcatEchoTracker = null;
    
    public final boolean getFrozen() {
        return false;
    }
    
    /**
     * Logs a message to the log buffer
     *
     * May also log the message to logcat if echoing is enabled for this buffer or tag.
     *
     * The actual string of the log message is not constructed until it is needed. To accomplish
     * this, logging a message is a two-step process. First, a fresh instance  of [LogMessage] is
     * obtained and is passed to the [initializer]. The initializer stores any relevant data on the
     * message's fields. The message is then inserted into the buffer where it waits until it is
     * either pushed out by newer messages or it needs to printed. If and when this latter moment
     * occurs, the [printer] function is called on the message. It reads whatever data the
     * initializer stored and converts it to a human-readable log message.
     *
     * @param tag A string of at most 23 characters, used for grouping logs into categories or
     * subjects. If this message is echoed to logcat, this will be the tag that is used.
     * @param level Which level to log the message at, both to the buffer and to logcat if it's
     * echoed. In general, a module should split most of its logs into either INFO or DEBUG level.
     * INFO level should be reserved for information that other parts of the system might care
     * about, leaving the specifics of code's day-to-day operations to DEBUG.
     * @param initializer A function that will be called immediately to store relevant data on the
     * log message. The value of `this` will be the LogMessage to be initialized.
     * @param printer A function that will be called if and when the message needs to be dumped to
     * logcat or a bug report. It should read the data stored by the initializer and convert it to
     * a human-readable string. The value of `this` will be the LogMessage to be printed.
     * **IMPORTANT:** The printer should ONLY ever reference fields on the LogMessage and NEVER any
     * variables in its enclosing scope. Otherwise, the runtime will need to allocate a new instance
     * of the printer for each call, thwarting our attempts at avoiding any sort of allocation.
     */
    public final void log(@org.jetbrains.annotations.NotNull()
    java.lang.String tag, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, kotlin.Unit> initializer, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> printer) {
    }
    
    /**
     * Same as [log], but doesn't push the message to the buffer. Useful if you need to supply a
     * "reason" for doing something (the thing you supply the reason to will presumably call [push]
     * on that message at some point).
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.log.LogMessage document(@org.jetbrains.annotations.NotNull()
    java.lang.String tag, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, kotlin.Unit> initializer, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> printer) {
        return null;
    }
    
    /**
     * Obtains an instance of [LogMessageImpl], usually from the object pool. If the pool has been
     * exhausted, creates a new instance.
     *
     * In general, you should call [log] or [document] instead of this method.
     */
    @org.jetbrains.annotations.NotNull()
    public final synchronized com.android.systemui.log.LogMessageImpl obtain(@org.jetbrains.annotations.NotNull()
    java.lang.String tag, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogLevel level, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> printer) {
        return null;
    }
    
    /**
     * Pushes a message into buffer, possibly evicting an older message if the buffer is full.
     */
    public final synchronized void push(@org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogMessage message) {
    }
    
    /**
     * Converts the entire buffer to a newline-delimited string
     */
    public final synchronized void dump(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, int tailLength) {
    }
    
    /**
     * "Freezes" the contents of the buffer, making them immutable until [unfreeze] is called.
     * Calls to [log], [document], [obtain], and [push] will not affect the buffer and will return
     * dummy values if necessary.
     */
    public final synchronized void freeze() {
    }
    
    /**
     * Undoes the effects of calling [freeze].
     */
    public final synchronized void unfreeze() {
    }
    
    private final void dumpMessage(com.android.systemui.log.LogMessage message, java.io.PrintWriter pw) {
    }
    
    private final void echoToLogcat(com.android.systemui.log.LogMessage message) {
    }
    
    public LogBuffer(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int maxLogs, int poolSize, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogcatEchoTracker logcatEchoTracker) {
        super();
    }
}