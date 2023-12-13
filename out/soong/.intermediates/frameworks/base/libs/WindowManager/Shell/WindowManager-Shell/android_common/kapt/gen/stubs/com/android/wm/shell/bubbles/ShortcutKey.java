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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0003\b\u0086\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\t\u0010\u000b\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\f\u001a\u00020\u0005H\u00c6\u0003J\u001d\u0010\r\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0005H\u00c6\u0001J\u0013\u0010\u000e\u001a\u00020\u000f2\b\u0010\u0010\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0011\u001a\u00020\u0003H\u00d6\u0001J\t\u0010\u0012\u001a\u00020\u0005H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\n"}, d2 = {"Lcom/android/wm/shell/bubbles/ShortcutKey;", "", "userId", "", "pkg", "", "(ILjava/lang/String;)V", "getPkg", "()Ljava/lang/String;", "getUserId", "()I", "component1", "component2", "copy", "equals", "", "other", "hashCode", "toString"})
public final class ShortcutKey {
    private final int userId = 0;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String pkg = null;
    
    public final int getUserId() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPkg() {
        return null;
    }
    
    public ShortcutKey(int userId, @org.jetbrains.annotations.NotNull()
    java.lang.String pkg) {
        super();
    }
    
    public final int component1() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.wm.shell.bubbles.ShortcutKey copy(int userId, @org.jetbrains.annotations.NotNull()
    java.lang.String pkg) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}