package com.android.systemui.controls.management;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.app.ActivityOptions;
import android.content.ComponentName;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewStub;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.TextView;
import android.widget.Toast;
import androidx.viewpager2.widget.ViewPager2;
import com.android.systemui.Prefs;
import com.android.systemui.R;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.ControlsServiceInfo;
import com.android.systemui.controls.TooltipManager;
import com.android.systemui.controls.controller.ControlsControllerImpl;
import com.android.systemui.controls.controller.StructureInfo;
import com.android.systemui.controls.ui.ControlsActivity;
import com.android.systemui.controls.ui.ControlsUiController;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.settings.CurrentUserTracker;
import com.android.systemui.util.LifecycleActivity;
import java.text.Collator;
import java.util.concurrent.Executor;
import java.util.function.Consumer;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\t\u0010\u000b\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\f\u001a\u00020\u0005H\u00c6\u0003J\u001d\u0010\r\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0005H\u00c6\u0001J\u0013\u0010\u000e\u001a\u00020\u000f2\b\u0010\u0010\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0011\u001a\u00020\u0012H\u00d6\u0001J\t\u0010\u0013\u001a\u00020\u0014H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\n"}, d2 = {"Lcom/android/systemui/controls/management/StructureContainer;", "", "structureName", "", "model", "Lcom/android/systemui/controls/management/ControlsModel;", "(Ljava/lang/CharSequence;Lcom/android/systemui/controls/management/ControlsModel;)V", "getModel", "()Lcom/android/systemui/controls/management/ControlsModel;", "getStructureName", "()Ljava/lang/CharSequence;", "component1", "component2", "copy", "equals", "", "other", "hashCode", "", "toString", ""})
public final class StructureContainer {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.CharSequence structureName = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.controls.management.ControlsModel model = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getStructureName() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.management.ControlsModel getModel() {
        return null;
    }
    
    public StructureContainer(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structureName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsModel model) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.management.ControlsModel component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.management.StructureContainer copy(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structureName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsModel model) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}