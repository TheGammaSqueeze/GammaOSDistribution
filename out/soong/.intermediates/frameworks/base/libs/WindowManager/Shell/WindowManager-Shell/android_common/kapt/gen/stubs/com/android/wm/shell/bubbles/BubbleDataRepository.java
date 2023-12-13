package com.android.wm.shell.bubbles;

import android.annotation.SuppressLint;
import android.annotation.UserIdInt;
import android.content.Context;
import android.content.pm.LauncherApps;
import android.os.UserHandle;
import android.util.Log;
import com.android.wm.shell.bubbles.storage.BubbleEntity;
import com.android.wm.shell.bubbles.storage.BubblePersistentRepository;
import com.android.wm.shell.bubbles.storage.BubbleVolatileRepository;
import com.android.wm.shell.common.ShellExecutor;
import kotlinx.coroutines.Dispatchers;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000^\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\b\u0000\u0018\u00002\u00020\u0001B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0016\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016J\u001c\u0010\u0017\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u00160\u0019J*\u0010\u001a\u001a\u00020\f2\u0006\u0010\u0013\u001a\u00020\u00142\u0018\u0010\u001b\u001a\u0014\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00160\u0019\u0012\u0004\u0012\u00020\u00120\u001cH\u0007J\b\u0010\u001d\u001a\u00020\u0012H\u0002J\u001c\u0010\u001e\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u00160\u0019J\u001c\u0010\u001f\u001a\b\u0012\u0004\u0012\u00020 0\u00192\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u00160\u0019H\u0002R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/bubbles/BubbleDataRepository;", "", "context", "Landroid/content/Context;", "launcherApps", "Landroid/content/pm/LauncherApps;", "mainExecutor", "Lcom/android/wm/shell/common/ShellExecutor;", "(Landroid/content/Context;Landroid/content/pm/LauncherApps;Lcom/android/wm/shell/common/ShellExecutor;)V", "ioScope", "Lkotlinx/coroutines/CoroutineScope;", "job", "Lkotlinx/coroutines/Job;", "persistentRepository", "Lcom/android/wm/shell/bubbles/storage/BubblePersistentRepository;", "volatileRepository", "Lcom/android/wm/shell/bubbles/storage/BubbleVolatileRepository;", "addBubble", "", "userId", "", "bubble", "Lcom/android/wm/shell/bubbles/Bubble;", "addBubbles", "bubbles", "", "loadBubbles", "cb", "Lkotlin/Function1;", "persistToDisk", "removeBubbles", "transform", "Lcom/android/wm/shell/bubbles/storage/BubbleEntity;"})
public final class BubbleDataRepository {
    private final com.android.wm.shell.bubbles.storage.BubbleVolatileRepository volatileRepository = null;
    private final com.android.wm.shell.bubbles.storage.BubblePersistentRepository persistentRepository = null;
    private final kotlinx.coroutines.CoroutineScope ioScope = null;
    private kotlinx.coroutines.Job job;
    private final android.content.pm.LauncherApps launcherApps = null;
    private final com.android.wm.shell.common.ShellExecutor mainExecutor = null;
    
    /**
     * Adds the bubble in memory, then persists the snapshot after adding the bubble to disk
     * asynchronously.
     */
    public final void addBubble(@android.annotation.UserIdInt()
    int userId, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.bubbles.Bubble bubble) {
    }
    
    /**
     * Adds the bubble in memory, then persists the snapshot after adding the bubble to disk
     * asynchronously.
     */
    public final void addBubbles(@android.annotation.UserIdInt()
    int userId, @org.jetbrains.annotations.NotNull()
    java.util.List<? extends com.android.wm.shell.bubbles.Bubble> bubbles) {
    }
    
    /**
     * Removes the bubbles from memory, then persists the snapshot to disk asynchronously.
     */
    public final void removeBubbles(@android.annotation.UserIdInt()
    int userId, @org.jetbrains.annotations.NotNull()
    java.util.List<? extends com.android.wm.shell.bubbles.Bubble> bubbles) {
    }
    
    private final java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity> transform(java.util.List<? extends com.android.wm.shell.bubbles.Bubble> bubbles) {
        return null;
    }
    
    /**
     * Persists the bubbles to disk. When being called multiple times, it waits for first ongoing
     * write operation to finish then run another write operation exactly once.
     *
     * e.g.
     * Job A started -> blocking I/O
     * Job B started, cancels A, wait for blocking I/O in A finishes
     * Job C started, cancels B, wait for job B to finish
     * Job D started, cancels C, wait for job C to finish
     * Job A completed
     * Job B resumes and reaches yield() and is then cancelled
     * Job C resumes and reaches yield() and is then cancelled
     * Job D resumes and performs another blocking I/O
     */
    private final void persistToDisk() {
    }
    
    /**
     * Load bubbles from disk.
     * @param cb The callback to be run after the bubbles are loaded.  This callback is always made
     *          on the main thread of the hosting process. The callback is only run if there are
     *          bubbles.
     */
    @org.jetbrains.annotations.NotNull()
    @android.annotation.SuppressLint(value = {"WrongConstant"})
    public final kotlinx.coroutines.Job loadBubbles(int userId, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.util.List<? extends com.android.wm.shell.bubbles.Bubble>, kotlin.Unit> cb) {
        return null;
    }
    
    public BubbleDataRepository(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.content.pm.LauncherApps launcherApps, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.common.ShellExecutor mainExecutor) {
        super();
    }
}