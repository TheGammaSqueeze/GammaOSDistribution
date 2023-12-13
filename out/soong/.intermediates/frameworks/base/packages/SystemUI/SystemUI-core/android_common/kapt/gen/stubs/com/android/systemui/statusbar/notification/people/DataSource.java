package com.android.systemui.statusbar.notification.people;

import java.lang.System;

/**
 * Boundary between a View and data pipeline, as seen by the View.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\bf\u0018\u0000*\u0006\b\u0000\u0010\u0001 \u00012\u00020\u0002J\u0016\u0010\u0003\u001a\u00020\u00042\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00028\u00000\u0006H&"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/DataSource;", "T", "", "registerListener", "Lcom/android/systemui/statusbar/notification/people/Subscription;", "listener", "Lcom/android/systemui/statusbar/notification/people/DataListener;"})
public abstract interface DataSource<T extends java.lang.Object> {
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.statusbar.notification.people.Subscription registerListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.DataListener<? super T> listener);
}