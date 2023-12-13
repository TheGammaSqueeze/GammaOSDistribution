package com.android.systemui.settings;

import android.content.ContentResolver;

/**
 * Implemented by [UserTrackerImpl].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\bf\u0018\u00002\u00020\u0001R\u0012\u0010\u0002\u001a\u00020\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005"}, d2 = {"Lcom/android/systemui/settings/UserContentResolverProvider;", "", "userContentResolver", "Landroid/content/ContentResolver;", "getUserContentResolver", "()Landroid/content/ContentResolver;"})
public abstract interface UserContentResolverProvider {
    
    @org.jetbrains.annotations.NotNull()
    public abstract android.content.ContentResolver getUserContentResolver();
}