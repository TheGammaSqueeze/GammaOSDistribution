package com.android.systemui.statusbar;

import android.app.Notification;
import android.os.RemoteException;
import com.android.internal.statusbar.IStatusBarService;
import com.android.internal.statusbar.NotificationVisibility;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.util.Assert;
import java.util.concurrent.Executor;
import javax.inject.Inject;

/**
 * Interface for listeners to get notified when a notification is interacted with via a click or
 * interaction with remote input or actions
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/NotificationInteractionListener;", "", "onNotificationInteraction", "", "key", ""})
public abstract interface NotificationInteractionListener {
    
    public abstract void onNotificationInteraction(@org.jetbrains.annotations.NotNull()
    java.lang.String key);
}