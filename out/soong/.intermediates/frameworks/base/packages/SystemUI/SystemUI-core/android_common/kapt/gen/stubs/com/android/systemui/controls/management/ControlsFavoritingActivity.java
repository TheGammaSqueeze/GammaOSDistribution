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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00a6\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010 \n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\t\u0018\u0000 D2\u00020\u0001:\u0001DB1\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\b\u00100\u001a\u000201H\u0002J\b\u00102\u001a\u000201H\u0002J\b\u00103\u001a\u000201H\u0002J\b\u00104\u001a\u000201H\u0002J\b\u00105\u001a\u000201H\u0016J\u0010\u00106\u001a\u0002012\u0006\u00107\u001a\u000208H\u0016J\u0012\u00109\u001a\u0002012\b\u0010:\u001a\u0004\u0018\u00010;H\u0014J\b\u0010<\u001a\u000201H\u0014J\b\u0010=\u001a\u000201H\u0014J\b\u0010>\u001a\u000201H\u0014J\b\u0010?\u001a\u000201H\u0014J\b\u0010@\u001a\u000201H\u0014J\b\u0010A\u001a\u000201H\u0002J\b\u0010B\u001a\u000201H\u0002J\b\u0010C\u001a\u00020\u001eH\u0002R\u0010\u0010\r\u001a\u0004\u0018\u00010\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000f\u001a\u0004\u0018\u00010\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u0011\u001a\u0012\u0012\u0004\u0012\u00020\u00130\u0012j\b\u0012\u0004\u0012\u00020\u0013`\u0014X\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0015\u001a\u0004\u0018\u00010\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u001cX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010 \u001a\b\u0012\u0004\u0012\u00020\u00130!X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020#X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010$\u001a\u0004\u0018\u00010%X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010&\u001a\u00020\u001cX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020(X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010)\u001a\u00020*X\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010+\u001a\u0004\u0018\u00010\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010,\u001a\u00020-X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010.\u001a\u00020*X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010/\u001a\u00020*X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlsFavoritingActivity;", "Lcom/android/systemui/util/LifecycleActivity;", "executor", "Ljava/util/concurrent/Executor;", "controller", "Lcom/android/systemui/controls/controller/ControlsControllerImpl;", "listingController", "Lcom/android/systemui/controls/management/ControlsListingController;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "uiController", "Lcom/android/systemui/controls/ui/ControlsUiController;", "(Ljava/util/concurrent/Executor;Lcom/android/systemui/controls/controller/ControlsControllerImpl;Lcom/android/systemui/controls/management/ControlsListingController;Lcom/android/systemui/broadcast/BroadcastDispatcher;Lcom/android/systemui/controls/ui/ControlsUiController;)V", "appName", "", "cancelLoadRunnable", "Ljava/lang/Runnable;", "comparator", "Ljava/util/Comparator;", "Lcom/android/systemui/controls/management/StructureContainer;", "Lkotlin/Comparator;", "component", "Landroid/content/ComponentName;", "controlsModelCallback", "Lcom/android/systemui/controls/management/ControlsModel$ControlsModelCallback;", "currentUserTracker", "Lcom/android/systemui/settings/CurrentUserTracker;", "doneButton", "Landroid/view/View;", "fromProviderSelector", "", "isPagerLoaded", "listOfStructures", "", "listingCallback", "Lcom/android/systemui/controls/management/ControlsListingController$ControlsListingCallback;", "mTooltipManager", "Lcom/android/systemui/controls/TooltipManager;", "otherAppsButton", "pageIndicator", "Lcom/android/systemui/controls/management/ManagementPageIndicator;", "statusText", "Landroid/widget/TextView;", "structureExtra", "structurePager", "Landroidx/viewpager2/widget/ViewPager2;", "subtitleView", "titleView", "animateExitAndFinish", "", "bindButtons", "bindViews", "loadControls", "onBackPressed", "onConfigurationChanged", "newConfig", "Landroid/content/res/Configuration;", "onCreate", "savedInstanceState", "Landroid/os/Bundle;", "onDestroy", "onPause", "onResume", "onStart", "onStop", "openControlsOrigin", "setUpPager", "shouldShowTooltip", "Companion"})
public final class ControlsFavoritingActivity extends com.android.systemui.util.LifecycleActivity {
    private android.content.ComponentName component;
    private java.lang.CharSequence appName;
    private java.lang.CharSequence structureExtra;
    private boolean fromProviderSelector = false;
    private androidx.viewpager2.widget.ViewPager2 structurePager;
    private android.widget.TextView statusText;
    private android.widget.TextView titleView;
    private android.widget.TextView subtitleView;
    private com.android.systemui.controls.management.ManagementPageIndicator pageIndicator;
    private com.android.systemui.controls.TooltipManager mTooltipManager;
    private android.view.View doneButton;
    private android.view.View otherAppsButton;
    private java.util.List<com.android.systemui.controls.management.StructureContainer> listOfStructures;
    private java.util.Comparator<com.android.systemui.controls.management.StructureContainer> comparator;
    private java.lang.Runnable cancelLoadRunnable;
    private boolean isPagerLoaded = false;
    private final com.android.systemui.settings.CurrentUserTracker currentUserTracker = null;
    private final com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback listingCallback = null;
    private final com.android.systemui.controls.management.ControlsModel.ControlsModelCallback controlsModelCallback = null;
    private final java.util.concurrent.Executor executor = null;
    private final com.android.systemui.controls.controller.ControlsControllerImpl controller = null;
    private final com.android.systemui.controls.management.ControlsListingController listingController = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    private final com.android.systemui.controls.ui.ControlsUiController uiController = null;
    private static final java.lang.String TAG = "ControlsFavoritingActivity";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String EXTRA_APP = "extra_app_label";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String EXTRA_STRUCTURE = "extra_structure";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String EXTRA_SINGLE_STRUCTURE = "extra_single_structure";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String EXTRA_FROM_PROVIDER_SELECTOR = "extra_from_provider_selector";
    private static final java.lang.String TOOLTIP_PREFS_KEY = "ControlsStructureSwipeTooltipCount";
    private static final int TOOLTIP_MAX_SHOWN = 2;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.management.ControlsFavoritingActivity.Companion Companion = null;
    
    @java.lang.Override()
    public void onBackPressed() {
    }
    
    @java.lang.Override()
    protected void onCreate(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    private final void loadControls() {
    }
    
    private final void setUpPager() {
    }
    
    private final void bindViews() {
    }
    
    private final void animateExitAndFinish() {
    }
    
    private final void bindButtons() {
    }
    
    private final void openControlsOrigin() {
    }
    
    @java.lang.Override()
    protected void onPause() {
    }
    
    @java.lang.Override()
    protected void onStart() {
    }
    
    @java.lang.Override()
    protected void onResume() {
    }
    
    @java.lang.Override()
    protected void onStop() {
    }
    
    @java.lang.Override()
    public void onConfigurationChanged(@org.jetbrains.annotations.NotNull()
    android.content.res.Configuration newConfig) {
    }
    
    @java.lang.Override()
    protected void onDestroy() {
    }
    
    private final boolean shouldShowTooltip() {
        return false;
    }
    
    @javax.inject.Inject()
    public ControlsFavoritingActivity(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsControllerImpl controller, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsListingController listingController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlsUiController uiController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\b\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlsFavoritingActivity$Companion;", "", "()V", "EXTRA_APP", "", "EXTRA_FROM_PROVIDER_SELECTOR", "EXTRA_SINGLE_STRUCTURE", "EXTRA_STRUCTURE", "TAG", "TOOLTIP_MAX_SHOWN", "", "TOOLTIP_PREFS_KEY"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}