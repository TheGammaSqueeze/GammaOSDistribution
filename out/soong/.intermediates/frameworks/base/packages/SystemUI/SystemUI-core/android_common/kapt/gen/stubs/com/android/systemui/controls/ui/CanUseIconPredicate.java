package com.android.systemui.controls.ui;

import android.content.ContentProvider;
import android.graphics.drawable.Icon;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\b\n\u0002\b\u0004\u0018\u00002\u000e\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u00030\u0001B\r\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0016\u0010\u0007\u001a\u00020\u00032\u0006\u0010\b\u001a\u00020\u0002H\u0096\u0002\u00a2\u0006\u0002\u0010\tR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/CanUseIconPredicate;", "Lkotlin/Function1;", "Landroid/graphics/drawable/Icon;", "", "currentUserId", "", "(I)V", "invoke", "icon", "(Landroid/graphics/drawable/Icon;)Ljava/lang/Boolean;"})
public final class CanUseIconPredicate implements kotlin.jvm.functions.Function1<android.graphics.drawable.Icon, java.lang.Boolean> {
    private final int currentUserId = 0;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.Boolean invoke(@org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Icon icon) {
        return null;
    }
    
    public CanUseIconPredicate(int currentUserId) {
        super();
    }
}