package com.android.systemui.controls.management;

import android.content.ComponentName;
import android.graphics.Rect;
import android.os.Bundle;
import android.service.controls.Control;
import android.service.controls.DeviceTypes;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.accessibility.AccessibilityNodeInfo;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;
import androidx.core.view.AccessibilityDelegateCompat;
import androidx.core.view.ViewCompat;
import androidx.core.view.accessibility.AccessibilityNodeInfoCompat;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import com.android.systemui.R;
import com.android.systemui.controls.ControlInterface;
import com.android.systemui.controls.ui.CanUseIconPredicate;
import com.android.systemui.controls.ui.RenderInfo;

/**
 * Holder for using with [DividerWrapper] to display a divider between zones.
 *
 * The divider can be shown or hidden. It also has a view the height of a control, that can
 * be toggled visible or gone.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\b\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016R\u000e\u0010\u0005\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/DividerHolder;", "Lcom/android/systemui/controls/management/Holder;", "view", "Landroid/view/View;", "(Landroid/view/View;)V", "divider", "frame", "bindData", "", "wrapper", "Lcom/android/systemui/controls/management/ElementWrapper;"})
final class DividerHolder extends com.android.systemui.controls.management.Holder {
    private final android.view.View frame = null;
    private final android.view.View divider = null;
    
    @java.lang.Override()
    public void bindData(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ElementWrapper wrapper) {
    }
    
    public DividerHolder(@org.jetbrains.annotations.NotNull()
    android.view.View view) {
    }
}