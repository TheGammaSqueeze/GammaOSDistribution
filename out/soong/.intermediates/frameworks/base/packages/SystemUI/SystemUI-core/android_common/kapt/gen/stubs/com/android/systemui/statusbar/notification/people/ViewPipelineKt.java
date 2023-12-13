package com.android.systemui.statusbar.notification.people;

import java.lang.System;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0014\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u001a6\u0010\u0000\u001a\b\u0012\u0004\u0012\u0002H\u00020\u0001\"\u0004\b\u0000\u0010\u0002\"\u0004\b\u0001\u0010\u0003*\b\u0012\u0004\u0012\u0002H\u00030\u00012\u0012\u0010\u0004\u001a\u000e\u0012\u0004\u0012\u0002H\u0002\u0012\u0004\u0012\u0002H\u00030\u0005\u001a6\u0010\u0006\u001a\b\u0012\u0004\u0012\u0002H\u00030\u0007\"\u0004\b\u0000\u0010\u0002\"\u0004\b\u0001\u0010\u0003*\b\u0012\u0004\u0012\u0002H\u00020\u00072\u0012\u0010\u0004\u001a\u000e\u0012\u0004\u0012\u0002H\u0002\u0012\u0004\u0012\u0002H\u00030\u0005"}, d2 = {"contraMap", "Lcom/android/systemui/statusbar/notification/people/DataListener;", "S", "T", "mapper", "Lkotlin/Function1;", "map", "Lcom/android/systemui/statusbar/notification/people/DataSource;"})
public final class ViewPipelineKt {
    
    /**
     * Convert all data using the given [mapper] before invoking this [DataListener].
     */
    @org.jetbrains.annotations.NotNull()
    public static final <S extends java.lang.Object, T extends java.lang.Object>com.android.systemui.statusbar.notification.people.DataListener<S> contraMap(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.DataListener<? super T> $this$contraMap, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super S, ? extends T> mapper) {
        return null;
    }
    
    /**
     * Transform all data coming out of this [DataSource] using the given [mapper].
     */
    @org.jetbrains.annotations.NotNull()
    public static final <S extends java.lang.Object, T extends java.lang.Object>com.android.systemui.statusbar.notification.people.DataSource<T> map(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.DataSource<? extends S> $this$map, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super S, ? extends T> mapper) {
        return null;
    }
}