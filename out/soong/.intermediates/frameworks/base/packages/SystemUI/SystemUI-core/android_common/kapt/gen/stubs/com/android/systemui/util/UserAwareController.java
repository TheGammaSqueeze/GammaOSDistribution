package com.android.systemui.util;

import android.os.UserHandle;

/**
 * An interface for controllers that keep track of the current user and can be notified of user
 * changes.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\tH\u0017R\u0012\u0010\u0002\u001a\u00020\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/systemui/util/UserAwareController;", "", "currentUserId", "", "getCurrentUserId", "()I", "changeUser", "", "newUser", "Landroid/os/UserHandle;"})
public abstract interface UserAwareController {
    
    public default void changeUser(@org.jetbrains.annotations.NotNull()
    android.os.UserHandle newUser) {
    }
    
    public abstract int getCurrentUserId();
}