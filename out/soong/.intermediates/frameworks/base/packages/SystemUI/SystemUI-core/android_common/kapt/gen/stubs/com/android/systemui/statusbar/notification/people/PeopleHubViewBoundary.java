package com.android.systemui.statusbar.notification.people;

import android.content.Context;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Handler;
import android.os.UserHandle;
import android.provider.Settings;
import android.view.View;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.ActivityStarter;
import javax.inject.Inject;

/**
 * Abstract `View` representation of PeopleHub.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J\u0010\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000fH&R\u0012\u0010\u0002\u001a\u00020\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005R \u0010\u0006\u001a\u0010\u0012\f\u0012\n\u0012\u0006\u0012\u0004\u0018\u00010\t0\b0\u0007X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleHubViewBoundary;", "", "associatedViewForClickAnimation", "Landroid/view/View;", "getAssociatedViewForClickAnimation", "()Landroid/view/View;", "personViewAdapters", "Lkotlin/sequences/Sequence;", "Lcom/android/systemui/statusbar/notification/people/DataListener;", "Lcom/android/systemui/statusbar/notification/people/PersonViewModel;", "getPersonViewAdapters", "()Lkotlin/sequences/Sequence;", "setVisible", "", "isVisible", ""})
public abstract interface PeopleHubViewBoundary {
    
    /**
     * View used for animating the activity launch caused by clicking a person in the hub.
     */
    @org.jetbrains.annotations.NotNull()
    public abstract android.view.View getAssociatedViewForClickAnimation();
    
    /**
     * [DataListener]s for individual people in the hub.
     *
     * These listeners should be ordered such that the first element will be bound to the most
     * recent person to be added to the hub, and then continuing in descending order. If there are
     * not enough people to satisfy each listener, `null` will be passed instead, indicating that
     * the `View` should render a placeholder.
     */
    @org.jetbrains.annotations.NotNull()
    public abstract kotlin.sequences.Sequence<com.android.systemui.statusbar.notification.people.DataListener<com.android.systemui.statusbar.notification.people.PersonViewModel>> getPersonViewAdapters();
    
    /**
     * Sets the visibility of the Hub in the notification shade.
     */
    public abstract void setVisible(boolean isVisible);
}