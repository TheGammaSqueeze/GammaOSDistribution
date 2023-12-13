package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.Dumpable;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.ArrayList;
import javax.inject.Inject;

/**
 * Handles the attachment of [Coordinator]s to the [NotifPipeline] so that the
 * Coordinators can register their respective callbacks.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u00012\u00020\u0002"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/NotifCoordinators;", "Lcom/android/systemui/statusbar/notification/collection/coordinator/Coordinator;", "Lcom/android/systemui/Dumpable;"})
public abstract interface NotifCoordinators extends com.android.systemui.statusbar.notification.collection.coordinator.Coordinator, com.android.systemui.Dumpable {
}