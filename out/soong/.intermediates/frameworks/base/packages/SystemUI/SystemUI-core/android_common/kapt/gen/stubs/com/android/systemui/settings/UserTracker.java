package com.android.systemui.settings;

import android.content.Context;
import android.content.pm.UserInfo;
import android.os.UserHandle;
import java.util.concurrent.Executor;

/**
 * User tracker for SystemUI.
 *
 * This tracker provides async access to current user information, as well as callbacks for
 * user/profile change.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\bf\u0018\u00002\u00020\u00012\u00020\u0002:\u0001\u001aJ\u0018\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u0018H&J\u0010\u0010\u0019\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016H&R\u0012\u0010\u0003\u001a\u00020\u0004X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0005\u0010\u0006R\u0012\u0010\u0007\u001a\u00020\bX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\t\u0010\nR\u0012\u0010\u000b\u001a\u00020\fX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\r\u0010\u000eR\u0018\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\f0\u0010X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0011\u0010\u0012"}, d2 = {"Lcom/android/systemui/settings/UserTracker;", "Lcom/android/systemui/settings/UserContentResolverProvider;", "Lcom/android/systemui/settings/UserContextProvider;", "userHandle", "Landroid/os/UserHandle;", "getUserHandle", "()Landroid/os/UserHandle;", "userId", "", "getUserId", "()I", "userInfo", "Landroid/content/pm/UserInfo;", "getUserInfo", "()Landroid/content/pm/UserInfo;", "userProfiles", "", "getUserProfiles", "()Ljava/util/List;", "addCallback", "", "callback", "Lcom/android/systemui/settings/UserTracker$Callback;", "executor", "Ljava/util/concurrent/Executor;", "removeCallback", "Callback"})
public abstract interface UserTracker extends com.android.systemui.settings.UserContentResolverProvider, com.android.systemui.settings.UserContextProvider {
    
    /**
     * Current user's id.
     */
    public abstract int getUserId();
    
    /**
     * [UserHandle] for current user
     */
    @org.jetbrains.annotations.NotNull()
    public abstract android.os.UserHandle getUserHandle();
    
    /**
     * [UserInfo] for current user
     */
    @org.jetbrains.annotations.NotNull()
    public abstract android.content.pm.UserInfo getUserInfo();
    
    /**
     * List of profiles associated with the current user.
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.util.List<android.content.pm.UserInfo> getUserProfiles();
    
    /**
     * Add a [Callback] to be notified of chances, on a particular [Executor]
     */
    public abstract void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker.Callback callback, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor);
    
    /**
     * Remove a [Callback] previously added.
     */
    public abstract void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker.Callback callback);
    
    /**
     * Ćallback for notifying of changes.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0016\u0010\u0002\u001a\u00020\u00032\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005H\u0017J\u0018\u0010\u0007\u001a\u00020\u00032\u0006\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000bH\u0017\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/systemui/settings/UserTracker$Callback;", "", "onProfilesChanged", "", "profiles", "", "Landroid/content/pm/UserInfo;", "onUserChanged", "newUser", "", "userContext", "Landroid/content/Context;"})
    public static abstract interface Callback {
        
        /**
         * Notifies that the current user has changed.
         */
        public default void onUserChanged(int newUser, @org.jetbrains.annotations.NotNull()
        android.content.Context userContext) {
        }
        
        /**
         * Notifies that the current user's profiles have changed.
         */
        public default void onProfilesChanged(@org.jetbrains.annotations.NotNull()
        java.util.List<? extends android.content.pm.UserInfo> profiles) {
        }
    }
}