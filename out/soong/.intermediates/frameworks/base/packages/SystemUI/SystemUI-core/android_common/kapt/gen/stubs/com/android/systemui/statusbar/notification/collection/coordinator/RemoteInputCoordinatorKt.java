package com.android.systemui.statusbar.notification.collection.coordinator;

import android.os.Handler;
import android.util.Log;
import androidx.annotation.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager.RemoteInputListener;
import com.android.systemui.statusbar.RemoteInputController;
import com.android.systemui.statusbar.RemoteInputNotificationRebuilder;
import com.android.systemui.statusbar.SmartReplyController;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.notifcollection.SelfTrackingLifetimeExtender;
import com.android.systemui.statusbar.notification.collection.notifcollection.InternalNotifUpdater;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0016\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0010\u000e\"\u001b\u0010\u0000\u001a\u00020\u00018BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u0004\u0010\u0005\u001a\u0004\b\u0002\u0010\u0003\"\u000e\u0010\u0006\u001a\u00020\u0007X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\b\u001a\u00020\u0007X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\t\u001a\u00020\nX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DEBUG", "", "getDEBUG", "()Z", "DEBUG$delegate", "Lkotlin/Lazy;", "REMOTE_INPUT_ACTIVE_EXTENDER_AUTO_CANCEL_DELAY", "", "REMOTE_INPUT_EXTENDER_RELEASE_DELAY", "TAG", ""})
public final class RemoteInputCoordinatorKt {
    private static final java.lang.String TAG = "RemoteInputCoordinator";
    
    /**
     * How long to wait before auto-dismissing a notification that was kept for active remote input, and
     * has now sent a remote input. We auto-dismiss, because the app may not cannot cancel
     * these given that they technically don't exist anymore. We wait a bit in case the app issues
     * an update, and to also give the other lifetime extenders a beat to decide they want it.
     */
    private static final long REMOTE_INPUT_ACTIVE_EXTENDER_AUTO_CANCEL_DELAY = 500L;
    
    /**
     * How long to wait before releasing a lifetime extension when requested to do so due to a user
     * interaction (such as tapping another action).
     * We wait a bit in case the app issues an update in response to the action, but not too long or we
     * risk appearing unresponsive to the user.
     */
    private static final long REMOTE_INPUT_EXTENDER_RELEASE_DELAY = 200L;
    
    /**
     * Whether this class should print spammy debug logs
     */
    private static final kotlin.Lazy DEBUG$delegate = null;
    
    /**
     * Whether this class should print spammy debug logs
     */
    private static final boolean getDEBUG() {
        return false;
    }
}