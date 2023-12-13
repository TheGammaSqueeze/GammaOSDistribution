package com.android.systemui.statusbar.notification.collection.render;

import android.annotation.StringRes;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import com.android.systemui.R;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.notification.dagger.HeaderClickAction;
import com.android.systemui.statusbar.notification.dagger.HeaderText;
import com.android.systemui.statusbar.notification.dagger.NodeLabel;
import com.android.systemui.statusbar.notification.dagger.SectionHeaderScope;
import com.android.systemui.statusbar.notification.stack.SectionHeaderView;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\tH&J\u0010\u0010\n\u001a\u00020\u00072\u0006\u0010\u000b\u001a\u00020\fH&J\u0010\u0010\r\u001a\u00020\u00072\u0006\u0010\u000e\u001a\u00020\u000fH&R\u0014\u0010\u0002\u001a\u0004\u0018\u00010\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;", "", "headerView", "Lcom/android/systemui/statusbar/notification/stack/SectionHeaderView;", "getHeaderView", "()Lcom/android/systemui/statusbar/notification/stack/SectionHeaderView;", "reinflateView", "", "parent", "Landroid/view/ViewGroup;", "setClearSectionEnabled", "enabled", "", "setOnClearSectionClickListener", "listener", "Landroid/view/View$OnClickListener;"})
public abstract interface SectionHeaderController {
    
    public abstract void reinflateView(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent);
    
    @org.jetbrains.annotations.Nullable()
    public abstract com.android.systemui.statusbar.notification.stack.SectionHeaderView getHeaderView();
    
    public abstract void setClearSectionEnabled(boolean enabled);
    
    public abstract void setOnClearSectionClickListener(@org.jetbrains.annotations.NotNull()
    android.view.View.OnClickListener listener);
}