package com.android.systemui.controls.ui;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ObjectAnimator;
import android.app.Activity;
import android.app.ActivityOptions;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.res.Configuration;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.LayerDrawable;
import android.service.controls.Control;
import android.util.Log;
import android.util.TypedValue;
import android.view.ContextThemeWrapper;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AccelerateInterpolator;
import android.view.animation.DecelerateInterpolator;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListPopupWindow;
import android.widget.Space;
import android.widget.TextView;
import com.android.systemui.R;
import com.android.systemui.controls.ControlsMetricsLogger;
import com.android.systemui.controls.ControlsServiceInfo;
import com.android.systemui.controls.CustomIconCache;
import com.android.systemui.controls.controller.ControlInfo;
import com.android.systemui.controls.controller.ControlsController;
import com.android.systemui.controls.controller.StructureInfo;
import com.android.systemui.controls.management.ControlsEditingActivity;
import com.android.systemui.controls.management.ControlsFavoritingActivity;
import com.android.systemui.controls.management.ControlsListingController;
import com.android.systemui.controls.management.ControlsProviderSelectorActivity;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.globalactions.GlobalActionsPopupMenu;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.concurrency.DelayableExecutor;
import dagger.Lazy;
import java.text.Collator;
import java.util.function.Consumer;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\r\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0011\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010\u000e\b\u0082\b\u0018\u00002\u00020\u0001B-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\t\u0010\u0015\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0016\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0017\u001a\u00020\u0006H\u00c6\u0003J\t\u0010\u0018\u001a\u00020\bH\u00c6\u0003J\t\u0010\u0019\u001a\u00020\nH\u00c6\u0003J;\u0010\u001a\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u00062\b\b\u0002\u0010\u0007\u001a\u00020\b2\b\b\u0002\u0010\t\u001a\u00020\nH\u00c6\u0001J\u0013\u0010\u001b\u001a\u00020\u001c2\b\u0010\u001d\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\u0006\u0010\u001e\u001a\u00020\u0003J\t\u0010\u001f\u001a\u00020\nH\u00d6\u0001J\t\u0010 \u001a\u00020!H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\rR\u0011\u0010\t\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014"}, d2 = {"Lcom/android/systemui/controls/ui/SelectionItem;", "", "appName", "", "structure", "icon", "Landroid/graphics/drawable/Drawable;", "componentName", "Landroid/content/ComponentName;", "uid", "", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;Landroid/graphics/drawable/Drawable;Landroid/content/ComponentName;I)V", "getAppName", "()Ljava/lang/CharSequence;", "getComponentName", "()Landroid/content/ComponentName;", "getIcon", "()Landroid/graphics/drawable/Drawable;", "getStructure", "getUid", "()I", "component1", "component2", "component3", "component4", "component5", "copy", "equals", "", "other", "getTitle", "hashCode", "toString", ""})
final class SelectionItem {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.CharSequence appName = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.CharSequence structure = null;
    @org.jetbrains.annotations.NotNull()
    private final android.graphics.drawable.Drawable icon = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.ComponentName componentName = null;
    private final int uid = 0;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getTitle() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getAppName() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getStructure() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.drawable.Drawable getIcon() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.ComponentName getComponentName() {
        return null;
    }
    
    public final int getUid() {
        return 0;
    }
    
    public SelectionItem(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence appName, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structure, @org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Drawable icon, @org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, int uid) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.drawable.Drawable component3() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.ComponentName component4() {
        return null;
    }
    
    public final int component5() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ui.SelectionItem copy(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence appName, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structure, @org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Drawable icon, @org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, int uid) {
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