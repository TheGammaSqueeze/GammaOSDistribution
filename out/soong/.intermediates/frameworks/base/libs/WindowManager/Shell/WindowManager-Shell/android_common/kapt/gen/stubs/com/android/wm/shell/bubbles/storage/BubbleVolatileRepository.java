package com.android.wm.shell.bubbles.storage;

import android.content.pm.LauncherApps;
import android.os.UserHandle;
import android.util.SparseArray;
import com.android.internal.annotations.VisibleForTesting;
import com.android.wm.shell.bubbles.ShortcutKey;

/**
 * BubbleVolatileRepository holds the most updated snapshot of list of bubbles for in-memory
 * manipulation.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0007\n\u0002\u0010!\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u001c\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\f2\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\b0\u0007J\u0016\u0010\u0018\u001a\u00020\u00162\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\u0002J\u0014\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\b0\u00142\u0006\u0010\u0017\u001a\u00020\fJ\u001c\u0010\u001a\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\f2\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\b0\u0007J\u0016\u0010\u001b\u001a\u00020\u00162\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\u0002R\u001d\u0010\u0005\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\b0\u00070\u00068F\u00a2\u0006\u0006\u001a\u0004\b\t\u0010\nR$\u0010\u000b\u001a\u00020\f8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b\r\u0010\u000e\u001a\u0004\b\u000f\u0010\u0010\"\u0004\b\u0011\u0010\u0012R\u001a\u0010\u0013\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\b0\u00140\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/bubbles/storage/BubbleVolatileRepository;", "", "launcherApps", "Landroid/content/pm/LauncherApps;", "(Landroid/content/pm/LauncherApps;)V", "bubbles", "Landroid/util/SparseArray;", "", "Lcom/android/wm/shell/bubbles/storage/BubbleEntity;", "getBubbles", "()Landroid/util/SparseArray;", "capacity", "", "getCapacity$annotations", "()V", "getCapacity", "()I", "setCapacity", "(I)V", "entitiesByUser", "", "addBubbles", "", "userId", "cache", "getEntities", "removeBubbles", "uncache"})
public final class BubbleVolatileRepository {
    
    /**
     * Set of bubbles per user. Each set of bubbles is ordered by recency.
     */
    private android.util.SparseArray<java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity>> entitiesByUser;
    
    /**
     * The capacity of the cache.
     */
    private int capacity = 16;
    private final android.content.pm.LauncherApps launcherApps = null;
    
    /**
     * The capacity of the cache.
     */
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getCapacity$annotations() {
    }
    
    public final int getCapacity() {
        return 0;
    }
    
    public final void setCapacity(int p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final synchronized android.util.SparseArray<java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity>> getBubbles() {
        return null;
    }
    
    /**
     * Returns the entity list of the provided user's bubbles or creates one if it doesn't exist.
     */
    @org.jetbrains.annotations.NotNull()
    public final synchronized java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity> getEntities(int userId) {
        return null;
    }
    
    /**
     * Add the bubbles to memory and perform a de-duplication. In case a bubble already exists,
     * it will be moved to the last.
     */
    public final synchronized void addBubbles(int userId, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity> bubbles) {
    }
    
    public final synchronized void removeBubbles(int userId, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity> bubbles) {
    }
    
    private final void cache(java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity> bubbles) {
    }
    
    private final void uncache(java.util.List<com.android.wm.shell.bubbles.storage.BubbleEntity> bubbles) {
    }
    
    public BubbleVolatileRepository(@org.jetbrains.annotations.NotNull()
    android.content.pm.LauncherApps launcherApps) {
        super();
    }
}