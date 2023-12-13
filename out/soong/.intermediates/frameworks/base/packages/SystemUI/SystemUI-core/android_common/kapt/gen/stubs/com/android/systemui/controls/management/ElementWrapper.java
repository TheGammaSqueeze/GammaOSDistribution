package com.android.systemui.controls.management;

import android.content.ComponentName;
import android.graphics.drawable.Icon;
import androidx.recyclerview.widget.RecyclerView;
import com.android.systemui.controls.ControlInterface;
import com.android.systemui.controls.ControlStatus;
import com.android.systemui.controls.controller.ControlInfo;

/**
 * Wrapper classes for the different types of elements shown in the [RecyclerView]s in
 * [ControlAdapter].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b6\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002\u0082\u0001\u0004\u0003\u0004\u0005\u0006"}, d2 = {"Lcom/android/systemui/controls/management/ElementWrapper;", "", "()V", "Lcom/android/systemui/controls/management/ZoneNameWrapper;", "Lcom/android/systemui/controls/management/ControlStatusWrapper;", "Lcom/android/systemui/controls/management/ControlInfoWrapper;", "Lcom/android/systemui/controls/management/DividerWrapper;"})
public abstract class ElementWrapper {
    
    private ElementWrapper() {
        super();
    }
}