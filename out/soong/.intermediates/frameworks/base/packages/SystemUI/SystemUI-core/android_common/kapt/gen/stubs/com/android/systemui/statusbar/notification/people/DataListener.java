package com.android.systemui.statusbar.notification.people;

import java.lang.System;

/**
 * Boundary between a View and data pipeline, as seen by the pipeline.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\bf\u0018\u0000*\u0006\b\u0000\u0010\u0001 \u00002\u00020\u0002J\u0015\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00028\u0000H&\u00a2\u0006\u0002\u0010\u0006"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/DataListener;", "T", "", "onDataChanged", "", "data", "(Ljava/lang/Object;)V"})
public abstract interface DataListener<T extends java.lang.Object> {
    
    public abstract void onDataChanged(T data);
}