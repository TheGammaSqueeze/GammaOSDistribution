package com.android.systemui.controls.management;

import android.app.ActivityOptions;
import android.content.ComponentName;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewStub;
import android.widget.Button;
import android.widget.TextView;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.recyclerview.widget.RecyclerView.AdapterDataObserver;
import com.android.systemui.R;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.controller.ControlsController;
import com.android.systemui.controls.ui.ControlsActivity;
import com.android.systemui.controls.ui.ControlsUiController;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.settings.CurrentUserTracker;
import com.android.systemui.util.LifecycleActivity;
import java.util.concurrent.Executor;
import javax.inject.Inject;

/**
 * Activity to select an application to favorite the [Control] provided by them.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000V\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u0000  2\u00020\u0001:\u0001 B;\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u00a2\u0006\u0002\u0010\rJ\b\u0010\u0014\u001a\u00020\u0015H\u0002J\u0010\u0010\u0016\u001a\u00020\u00152\b\u0010\u0017\u001a\u0004\u0018\u00010\u0018J\b\u0010\u0019\u001a\u00020\u0015H\u0016J\u0012\u0010\u001a\u001a\u00020\u00152\b\u0010\u001b\u001a\u0004\u0018\u00010\u001cH\u0014J\b\u0010\u001d\u001a\u00020\u0015H\u0014J\b\u0010\u001e\u001a\u00020\u0015H\u0014J\b\u0010\u001f\u001a\u00020\u0015H\u0014R\u000e\u0010\u0004\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlsProviderSelectorActivity;", "Lcom/android/systemui/util/LifecycleActivity;", "executor", "Ljava/util/concurrent/Executor;", "backExecutor", "listingController", "Lcom/android/systemui/controls/management/ControlsListingController;", "controlsController", "Lcom/android/systemui/controls/controller/ControlsController;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "uiController", "Lcom/android/systemui/controls/ui/ControlsUiController;", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/Executor;Lcom/android/systemui/controls/management/ControlsListingController;Lcom/android/systemui/controls/controller/ControlsController;Lcom/android/systemui/broadcast/BroadcastDispatcher;Lcom/android/systemui/controls/ui/ControlsUiController;)V", "backShouldExit", "", "currentUserTracker", "Lcom/android/systemui/settings/CurrentUserTracker;", "recyclerView", "Landroidx/recyclerview/widget/RecyclerView;", "animateExitAndFinish", "", "launchFavoritingActivity", "component", "Landroid/content/ComponentName;", "onBackPressed", "onCreate", "savedInstanceState", "Landroid/os/Bundle;", "onDestroy", "onStart", "onStop", "Companion"})
public final class ControlsProviderSelectorActivity extends com.android.systemui.util.LifecycleActivity {
    private boolean backShouldExit = false;
    private androidx.recyclerview.widget.RecyclerView recyclerView;
    private final com.android.systemui.settings.CurrentUserTracker currentUserTracker = null;
    private final java.util.concurrent.Executor executor = null;
    private final java.util.concurrent.Executor backExecutor = null;
    private final com.android.systemui.controls.management.ControlsListingController listingController = null;
    private final com.android.systemui.controls.controller.ControlsController controlsController = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    private final com.android.systemui.controls.ui.ControlsUiController uiController = null;
    private static final java.lang.String TAG = "ControlsProviderSelectorActivity";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String BACK_SHOULD_EXIT = "back_should_exit";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.management.ControlsProviderSelectorActivity.Companion Companion = null;
    
    @java.lang.Override()
    protected void onCreate(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @java.lang.Override()
    public void onBackPressed() {
    }
    
    @java.lang.Override()
    protected void onStart() {
    }
    
    @java.lang.Override()
    protected void onStop() {
    }
    
    /**
     * Launch the [ControlsFavoritingActivity] for the specified component.
     * @param component a component name for a [ControlsProviderService]
     */
    public final void launchFavoritingActivity(@org.jetbrains.annotations.Nullable()
    android.content.ComponentName component) {
    }
    
    @java.lang.Override()
    protected void onDestroy() {
    }
    
    private final void animateExitAndFinish() {
    }
    
    @javax.inject.Inject()
    public ControlsProviderSelectorActivity(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    java.util.concurrent.Executor backExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsListingController listingController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsController controlsController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlsUiController uiController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlsProviderSelectorActivity$Companion;", "", "()V", "BACK_SHOULD_EXIT", "", "TAG"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}