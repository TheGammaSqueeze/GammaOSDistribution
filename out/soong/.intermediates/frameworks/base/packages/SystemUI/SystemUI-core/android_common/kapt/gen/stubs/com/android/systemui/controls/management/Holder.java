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
 * Holder for binding views in the [RecyclerView]-
 * @param view the [View] for this [Holder]
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b6\u0018\u00002\u00020\u0001B\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH&J\u0010\u0010\t\u001a\u00020\u00062\u0006\u0010\n\u001a\u00020\u000bH\u0016\u0082\u0001\u0003\f\r\u000e"}, d2 = {"Lcom/android/systemui/controls/management/Holder;", "Landroidx/recyclerview/widget/RecyclerView$ViewHolder;", "view", "Landroid/view/View;", "(Landroid/view/View;)V", "bindData", "", "wrapper", "Lcom/android/systemui/controls/management/ElementWrapper;", "updateFavorite", "favorite", "", "Lcom/android/systemui/controls/management/DividerHolder;", "Lcom/android/systemui/controls/management/ZoneHolder;", "Lcom/android/systemui/controls/management/ControlHolder;"})
public abstract class Holder extends androidx.recyclerview.widget.RecyclerView.ViewHolder {
    
    /**
     * Bind the data from the model into the view
     */
    public abstract void bindData(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ElementWrapper wrapper);
    
    public void updateFavorite(boolean favorite) {
    }
    
    private Holder(android.view.View view) {
        super(null);
    }
}