package com.android.systemui.statusbar.notification.stack;

import android.annotation.IntDef;

/**
 * For now, declare the available notification buckets (sections) here so that other
 * presentation code can decide what to do based on an entry's buckets
 */
@android.annotation.IntDef(prefix = {"BUCKET_"}, value = {0, 1, 2, 3, 4, 5, 6})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\b\n\u0002\u0018\u0002\n\u0002\u0010\u001b\b\u0087\u0002\u0018\u00002\u00020\u0001B\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/PriorityBucket;", ""})
@java.lang.annotation.Retention(value = java.lang.annotation.RetentionPolicy.SOURCE)
@kotlin.annotation.Retention(value = kotlin.annotation.AnnotationRetention.SOURCE)
public abstract @interface PriorityBucket {
}