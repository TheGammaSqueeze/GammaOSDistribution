package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.statusbar.notification.collection.ListEntry;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner;
import com.android.systemui.statusbar.notification.collection.render.NodeController;
import com.android.systemui.statusbar.notification.dagger.PeopleHeader;
import com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier;
import javax.inject.Inject;

/**
 * A Conversation/People Coordinator that:
 * - Elevates important conversation notifications
 * - Puts conversations into its own people section. @see [NotifCoordinators] for section ordering.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0007\u0018\u0000 \u00152\u00020\u0001:\u0001\u0015B\u0019\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0010\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0010H\u0016J\u0010\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0014H\u0002R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\t\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\f"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/ConversationCoordinator;", "Lcom/android/systemui/statusbar/notification/collection/coordinator/Coordinator;", "peopleNotificationIdentifier", "Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier;", "peopleHeaderController", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "(Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier;Lcom/android/systemui/statusbar/notification/collection/render/NodeController;)V", "notificationPromoter", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifPromoter;", "sectioner", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifSectioner;", "getSectioner", "()Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifSectioner;", "attach", "", "pipeline", "Lcom/android/systemui/statusbar/notification/collection/NotifPipeline;", "isConversation", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "Companion"})
@com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope()
public final class ConversationCoordinator implements com.android.systemui.statusbar.notification.collection.coordinator.Coordinator {
    private final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter notificationPromoter = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner sectioner = null;
    private final com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier peopleNotificationIdentifier = null;
    private static final java.lang.String TAG = "ConversationCoordinator";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.collection.coordinator.ConversationCoordinator.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner getSectioner() {
        return null;
    }
    
    @java.lang.Override()
    public void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotifPipeline pipeline) {
    }
    
    private final boolean isConversation(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return false;
    }
    
    @javax.inject.Inject()
    public ConversationCoordinator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier peopleNotificationIdentifier, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.statusbar.notification.dagger.PeopleHeader()
    com.android.systemui.statusbar.notification.collection.render.NodeController peopleHeaderController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/ConversationCoordinator$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}