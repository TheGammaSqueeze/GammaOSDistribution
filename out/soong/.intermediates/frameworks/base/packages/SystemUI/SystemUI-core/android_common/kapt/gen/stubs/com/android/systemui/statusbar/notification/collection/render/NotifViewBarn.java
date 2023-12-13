package com.android.systemui.statusbar.notification.collection.render;

import android.view.textclassifier.Log;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.collection.ListEntry;
import javax.inject.Inject;

/**
 * The ViewBarn is just a map from [ListEntry] to an instance of a [NodeController].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0007\u0018\u00002\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\u0016\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u0006J\u000e\u0010\f\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nJ\u000e\u0010\r\u001a\u00020\u00062\u0006\u0010\u000e\u001a\u00020\nR\u001a\u0010\u0003\u001a\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u00060\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/NotifViewBarn;", "", "()V", "rowMap", "", "", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "registerViewForEntry", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/ListEntry;", "controller", "removeViewForEntry", "requireView", "forEntry"})
@com.android.systemui.dagger.SysUISingleton()
public final class NotifViewBarn {
    private final java.util.Map<java.lang.String, com.android.systemui.statusbar.notification.collection.render.NodeController> rowMap = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.render.NodeController requireView(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.ListEntry forEntry) {
        return null;
    }
    
    public final void registerViewForEntry(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.ListEntry entry, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController controller) {
    }
    
    public final void removeViewForEntry(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.ListEntry entry) {
    }
    
    @javax.inject.Inject()
    public NotifViewBarn() {
        super();
    }
}