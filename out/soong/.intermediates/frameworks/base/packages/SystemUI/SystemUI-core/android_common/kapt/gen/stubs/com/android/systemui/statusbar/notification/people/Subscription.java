package com.android.systemui.statusbar.notification.people;

import java.lang.System;

/**
 * Represents a registration with a [DataSource].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u000e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\bf\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H&"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/Subscription;", "", "unsubscribe", ""})
public abstract interface Subscription {
    
    /**
     * Removes the previously registered [DataListener] from the [DataSource]
     */
    public abstract void unsubscribe();
}