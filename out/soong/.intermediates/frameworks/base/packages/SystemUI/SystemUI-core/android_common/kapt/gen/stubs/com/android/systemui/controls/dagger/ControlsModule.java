package com.android.systemui.controls.dagger;

import android.app.Activity;
import android.content.pm.PackageManager;
import com.android.systemui.controls.ControlsMetricsLogger;
import com.android.systemui.controls.ControlsMetricsLoggerImpl;
import com.android.systemui.controls.controller.ControlsBindingController;
import com.android.systemui.controls.controller.ControlsBindingControllerImpl;
import com.android.systemui.controls.controller.ControlsController;
import com.android.systemui.controls.controller.ControlsControllerImpl;
import com.android.systemui.controls.controller.ControlsFavoritePersistenceWrapper;
import com.android.systemui.controls.management.ControlsEditingActivity;
import com.android.systemui.controls.management.ControlsFavoritingActivity;
import com.android.systemui.controls.management.ControlsListingController;
import com.android.systemui.controls.management.ControlsListingControllerImpl;
import com.android.systemui.controls.management.ControlsProviderSelectorActivity;
import com.android.systemui.controls.management.ControlsRequestDialog;
import com.android.systemui.controls.ui.ControlActionCoordinator;
import com.android.systemui.controls.ui.ControlActionCoordinatorImpl;
import com.android.systemui.controls.ui.ControlsActivity;
import com.android.systemui.controls.ui.ControlsUiController;
import com.android.systemui.controls.ui.ControlsUiControllerImpl;
import com.android.systemui.dagger.SysUISingleton;
import dagger.Binds;
import dagger.BindsOptionalOf;
import dagger.Module;
import dagger.Provides;
import dagger.multibindings.ClassKey;
import dagger.multibindings.IntoMap;

/**
 * Module for injecting classes in `com.android.systemui.controls`-
 *
 * Classes provided by this module should only be injected directly into other classes in this
 * module. For injecting outside of this module (for example, [GlobalActionsDialog], inject
 * [ControlsComponent] and obtain the corresponding optionals from it.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000x\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\b\'\u0018\u0000 &2\u00020\u0001:\u0001&B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\'J\u0010\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\'J\u0010\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fH\'J\u0010\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0010H\'J\u0010\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u000f\u001a\u00020\u0013H\'J\u0010\u0010\u0014\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u0015H\'J\u0010\u0010\u0016\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u0017H\'J\u0010\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u000f\u001a\u00020\u001aH\'J\u0010\u0010\u001b\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u001cH\'J\u0010\u0010\u001d\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u001eH\'J\u0010\u0010\u001f\u001a\u00020 2\u0006\u0010!\u001a\u00020\"H\'J\u0010\u0010#\u001a\u00020$2\u0006\u0010\u000f\u001a\u00020%H\'"}, d2 = {"Lcom/android/systemui/controls/dagger/ControlsModule;", "", "()V", "optionalPersistenceWrapper", "Lcom/android/systemui/controls/controller/ControlsFavoritePersistenceWrapper;", "provideControlActionCoordinator", "Lcom/android/systemui/controls/ui/ControlActionCoordinator;", "coordinator", "Lcom/android/systemui/controls/ui/ControlActionCoordinatorImpl;", "provideControlsActivity", "Landroid/app/Activity;", "activity", "Lcom/android/systemui/controls/ui/ControlsActivity;", "provideControlsBindingController", "Lcom/android/systemui/controls/controller/ControlsBindingController;", "controller", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;", "provideControlsController", "Lcom/android/systemui/controls/controller/ControlsController;", "Lcom/android/systemui/controls/controller/ControlsControllerImpl;", "provideControlsEditingActivity", "Lcom/android/systemui/controls/management/ControlsEditingActivity;", "provideControlsFavoritingActivity", "Lcom/android/systemui/controls/management/ControlsFavoritingActivity;", "provideControlsListingController", "Lcom/android/systemui/controls/management/ControlsListingController;", "Lcom/android/systemui/controls/management/ControlsListingControllerImpl;", "provideControlsProviderActivity", "Lcom/android/systemui/controls/management/ControlsProviderSelectorActivity;", "provideControlsRequestDialog", "Lcom/android/systemui/controls/management/ControlsRequestDialog;", "provideMetricsLogger", "Lcom/android/systemui/controls/ControlsMetricsLogger;", "logger", "Lcom/android/systemui/controls/ControlsMetricsLoggerImpl;", "provideUiController", "Lcom/android/systemui/controls/ui/ControlsUiController;", "Lcom/android/systemui/controls/ui/ControlsUiControllerImpl;", "Companion"})
@dagger.Module()
public abstract class ControlsModule {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.dagger.ControlsModule.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.controls.management.ControlsListingController provideControlsListingController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsListingControllerImpl controller);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.controls.controller.ControlsController provideControlsController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsControllerImpl controller);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.controls.controller.ControlsBindingController provideControlsBindingController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsBindingControllerImpl controller);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.controls.ui.ControlsUiController provideUiController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlsUiControllerImpl controller);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.controls.ControlsMetricsLogger provideMetricsLogger(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ControlsMetricsLoggerImpl logger);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.controls.ui.ControlActionCoordinator provideControlActionCoordinator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlActionCoordinatorImpl coordinator);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.BindsOptionalOf()
    public abstract com.android.systemui.controls.controller.ControlsFavoritePersistenceWrapper optionalPersistenceWrapper();
    
    @org.jetbrains.annotations.NotNull()
    @dagger.multibindings.ClassKey(value = com.android.systemui.controls.management.ControlsProviderSelectorActivity.class)
    @dagger.multibindings.IntoMap()
    @dagger.Binds()
    public abstract android.app.Activity provideControlsProviderActivity(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsProviderSelectorActivity activity);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.multibindings.ClassKey(value = com.android.systemui.controls.management.ControlsFavoritingActivity.class)
    @dagger.multibindings.IntoMap()
    @dagger.Binds()
    public abstract android.app.Activity provideControlsFavoritingActivity(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsFavoritingActivity activity);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.multibindings.ClassKey(value = com.android.systemui.controls.management.ControlsEditingActivity.class)
    @dagger.multibindings.IntoMap()
    @dagger.Binds()
    public abstract android.app.Activity provideControlsEditingActivity(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsEditingActivity activity);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.multibindings.ClassKey(value = com.android.systemui.controls.management.ControlsRequestDialog.class)
    @dagger.multibindings.IntoMap()
    @dagger.Binds()
    public abstract android.app.Activity provideControlsRequestDialog(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsRequestDialog activity);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.multibindings.ClassKey(value = com.android.systemui.controls.ui.ControlsActivity.class)
    @dagger.multibindings.IntoMap()
    @dagger.Binds()
    public abstract android.app.Activity provideControlsActivity(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlsActivity activity);
    
    public ControlsModule() {
        super();
    }
    
    @ControlsFeatureEnabled()
    @com.android.systemui.dagger.SysUISingleton()
    @dagger.Provides()
    public static final boolean providesControlsFeatureEnabled(@org.jetbrains.annotations.NotNull()
    android.content.pm.PackageManager pm) {
        return false;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\b\u0087\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0007"}, d2 = {"Lcom/android/systemui/controls/dagger/ControlsModule$Companion;", "", "()V", "providesControlsFeatureEnabled", "", "pm", "Landroid/content/pm/PackageManager;"})
    @dagger.Module()
    public static final class Companion {
        
        @ControlsFeatureEnabled()
        @com.android.systemui.dagger.SysUISingleton()
        @dagger.Provides()
        public final boolean providesControlsFeatureEnabled(@org.jetbrains.annotations.NotNull()
        android.content.pm.PackageManager pm) {
            return false;
        }
        
        private Companion() {
            super();
        }
    }
}