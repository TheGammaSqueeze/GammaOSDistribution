package com.android.systemui.dump;

import android.util.ArrayMap;
import com.android.systemui.Dumpable;
import com.android.systemui.log.LogBuffer;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;
import javax.inject.Singleton;

/**
 * Maintains a registry of things that should be dumped when a bug report is taken
 *
 * When a bug report is taken, SystemUI dumps various diagnostic information that we hope will be
 * useful for the eventual readers of the bug report. Code that wishes to participate in this dump
 * should register itself here.
 *
 * See [DumpHandler] for more information on how and when this information is dumped.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000P\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u000e\b\u0017\u0018\u00002\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u00052\u0006\u0010\r\u001a\u00020\u0001H\u0002J&\u0010\u000e\u001a\u00020\u000f2\f\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00070\u00062\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0014H\u0002J\u0016\u0010\u0015\u001a\u00020\u000f2\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0014J9\u0010\u0016\u001a\u00020\u000f2\f\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\t0\u00062\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u0011\u001a\u00020\u00122\f\u0010\u001a\u001a\b\u0012\u0004\u0012\u00020\u00050\u001bH\u0002\u00a2\u0006\u0002\u0010\u001cJ)\u0010\u001d\u001a\u00020\u000f2\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u0011\u001a\u00020\u00122\f\u0010\u001a\u001a\b\u0012\u0004\u0012\u00020\u00050\u001b\u00a2\u0006\u0002\u0010\u001eJ9\u0010\u001f\u001a\u00020\u000f2\u0006\u0010 \u001a\u00020\u00052\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u0011\u001a\u00020\u00122\f\u0010\u001a\u001a\b\u0012\u0004\u0012\u00020\u00050\u001b2\u0006\u0010\u0013\u001a\u00020\u0014\u00a2\u0006\u0002\u0010!J\u0006\u0010\"\u001a\u00020\u000fJ\u000e\u0010#\u001a\u00020\u000f2\u0006\u0010\u0011\u001a\u00020\u0012J\u000e\u0010$\u001a\u00020\u000f2\u0006\u0010\u0011\u001a\u00020\u0012J\u0016\u0010%\u001a\u00020\u000f2\u0006\u0010\f\u001a\u00020\u00052\u0006\u0010\u0010\u001a\u00020\u0007J\u000e\u0010&\u001a\u00020\u000f2\u0006\u0010\'\u001a\u00020\tJ\u0016\u0010&\u001a\u00020\u000f2\u0006\u0010\f\u001a\u00020\u00052\u0006\u0010\'\u001a\u00020\tJ\u0006\u0010(\u001a\u00020\u000fJ\u000e\u0010)\u001a\u00020\u000f2\u0006\u0010\f\u001a\u00020\u0005R \u0010\u0003\u001a\u0014\u0012\u0004\u0012\u00020\u0005\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00070\u00060\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\b\u001a\u0014\u0012\u0004\u0012\u00020\u0005\u0012\n\u0012\b\u0012\u0004\u0012\u00020\t0\u00060\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/dump/DumpManager;", "", "()V", "buffers", "", "", "Lcom/android/systemui/dump/RegisteredDumpable;", "Lcom/android/systemui/log/LogBuffer;", "dumpables", "Lcom/android/systemui/Dumpable;", "canAssignToNameLocked", "", "name", "newDumpable", "dumpBuffer", "", "buffer", "pw", "Ljava/io/PrintWriter;", "tailLength", "", "dumpBuffers", "dumpDumpable", "dumpable", "fd", "Ljava/io/FileDescriptor;", "args", "", "(Lcom/android/systemui/dump/RegisteredDumpable;Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "dumpDumpables", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "dumpTarget", "target", "(Ljava/lang/String;Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;I)V", "freezeBuffers", "listBuffers", "listDumpables", "registerBuffer", "registerDumpable", "module", "unfreezeBuffers", "unregisterDumpable"})
@javax.inject.Singleton()
public class DumpManager {
    private final java.util.Map<java.lang.String, com.android.systemui.dump.RegisteredDumpable<com.android.systemui.Dumpable>> dumpables = null;
    private final java.util.Map<java.lang.String, com.android.systemui.dump.RegisteredDumpable<com.android.systemui.log.LogBuffer>> buffers = null;
    
    /**
     * Register a dumpable to be called during a bug report. The dumpable will be called during the
     * CRITICAL section of the bug report, so don't dump an excessive amount of stuff here.
     *
     * @param name The name to register the dumpable under. This is typically the qualified class
     * name of the thing being dumped (getClass().getName()), but can be anything as long as it
     * doesn't clash with an existing registration.
     */
    public final synchronized void registerDumpable(@org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    com.android.systemui.Dumpable module) {
    }
    
    /**
     * Same as the above override, but automatically uses the simple class name as the dumpable
     * name.
     */
    public final synchronized void registerDumpable(@org.jetbrains.annotations.NotNull()
    com.android.systemui.Dumpable module) {
    }
    
    /**
     * Unregisters a previously-registered dumpable.
     */
    public final synchronized void unregisterDumpable(@org.jetbrains.annotations.NotNull()
    java.lang.String name) {
    }
    
    /**
     * Register a [LogBuffer] to be dumped during a bug report.
     */
    public final synchronized void registerBuffer(@org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    com.android.systemui.log.LogBuffer buffer) {
    }
    
    /**
     * Dumps the first dumpable or buffer whose registered name ends with [target]
     */
    public final synchronized void dumpTarget(@org.jetbrains.annotations.NotNull()
    java.lang.String target, @org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args, int tailLength) {
    }
    
    /**
     * Dumps all registered dumpables to [pw]
     */
    public final synchronized void dumpDumpables(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    /**
     * Dumps the names of all registered dumpables (one per line)
     */
    public final synchronized void listDumpables(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw) {
    }
    
    /**
     * Dumps all registered [LogBuffer]s to [pw]
     */
    public final synchronized void dumpBuffers(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, int tailLength) {
    }
    
    /**
     * Dumps the names of all registered buffers (one per line)
     */
    public final synchronized void listBuffers(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw) {
    }
    
    public final synchronized void freezeBuffers() {
    }
    
    public final synchronized void unfreezeBuffers() {
    }
    
    private final void dumpDumpable(com.android.systemui.dump.RegisteredDumpable<com.android.systemui.Dumpable> dumpable, java.io.FileDescriptor fd, java.io.PrintWriter pw, java.lang.String[] args) {
    }
    
    private final void dumpBuffer(com.android.systemui.dump.RegisteredDumpable<com.android.systemui.log.LogBuffer> buffer, java.io.PrintWriter pw, int tailLength) {
    }
    
    private final boolean canAssignToNameLocked(java.lang.String name, java.lang.Object newDumpable) {
        return false;
    }
    
    @javax.inject.Inject()
    public DumpManager() {
        super();
    }
}