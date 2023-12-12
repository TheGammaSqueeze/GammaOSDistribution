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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00fc\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u000b\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0007\u0018\u0000 y2\u00020\u0001:\u0001yBy\b\u0007\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\b\b\u0001\u0010\u0007\u001a\u00020\b\u0012\b\b\u0001\u0010\t\u001a\u00020\b\u0012\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u000b0\u0003\u0012\b\b\u0001\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u0012\u0006\u0010\u0014\u001a\u00020\u0015\u0012\u0006\u0010\u0016\u001a\u00020\u0017\u0012\u0006\u0010\u0018\u001a\u00020\u0019\u00a2\u0006\u0002\u0010\u001aJ\u0010\u0010H\u001a\u00020I2\u0006\u0010J\u001a\u000202H\u0016J\"\u0010K\u001a\u0002062\u0018\u0010L\u001a\u0014\u0012\n\u0012\b\u0012\u0004\u0012\u0002040\u001d\u0012\u0004\u0012\u00020I0MH\u0002J\u001e\u0010N\u001a\u00020I2\f\u0010O\u001a\b\u0012\u0004\u0012\u0002040\u001d2\u0006\u0010P\u001a\u000204H\u0002J\u0010\u0010Q\u001a\u00020I2\u0006\u0010P\u001a\u000204H\u0002J\b\u0010R\u001a\u00020IH\u0002J\u0018\u0010S\u001a\u00020>2\u0006\u0010T\u001a\u00020U2\u0006\u0010V\u001a\u00020>H\u0002J\b\u0010W\u001a\u00020XH\u0002J \u0010Y\u001a\u0004\u0018\u0001042\u0006\u0010Z\u001a\u00020\u001e2\f\u0010O\u001a\b\u0012\u0004\u0012\u0002040\u001dH\u0002J\u0016\u0010[\u001a\u00020\u001e2\f\u0010\\\u001a\b\u0012\u0004\u0012\u00020\u001e0\u001dH\u0016J\b\u0010]\u001a\u00020IH\u0016J \u0010^\u001a\u00020I2\u0006\u0010_\u001a\u00020`2\u0006\u0010a\u001a\u00020b2\u0006\u0010c\u001a\u00020XH\u0016J\u001e\u0010d\u001a\u00020I2\u0006\u0010_\u001a\u00020`2\f\u0010e\u001a\b\u0012\u0004\u0012\u00020f0\u001dH\u0016J\u0018\u0010g\u001a\u00020I2\u0006\u0010h\u001a\u00020i2\u0006\u0010Z\u001a\u00020\u001eH\u0002J\u0010\u0010j\u001a\u00020I2\u0006\u0010=\u001a\u00020>H\u0002J \u0010k\u001a\u00020I2\u0006\u0010=\u001a\u00020>2\u0006\u00109\u001a\u00020:2\u0006\u0010\u001b\u001a\u00020\u0006H\u0016J\u0016\u0010l\u001a\u00020I2\f\u0010O\u001a\b\u0012\u0004\u0012\u0002040\u001dH\u0002J\u0016\u0010m\u001a\u00020I2\f\u0010O\u001a\b\u0012\u0004\u0012\u0002040\u001dH\u0002J\u0016\u0010n\u001a\u00020I2\f\u0010O\u001a\b\u0012\u0004\u0012\u0002040\u001dH\u0002J\u0010\u0010o\u001a\u00020I2\u0006\u0010h\u001a\u00020iH\u0002J\u0010\u0010p\u001a\u00020I2\u0006\u0010Z\u001a\u00020\u001eH\u0002J\u0010\u0010q\u001a\u00020I2\u0006\u0010Z\u001a\u00020\u001eH\u0002J\b\u0010r\u001a\u00020IH\u0002J\u001c\u0010s\u001a\u00020I2\u0006\u0010Z\u001a\u00020\u001e2\n\u0010t\u001a\u0006\u0012\u0002\b\u00030uH\u0002J\u0010\u0010v\u001a\u00020I2\u0006\u0010w\u001a\u000204H\u0002J\u0010\u0010x\u001a\u00020I2\u0006\u0010Z\u001a\u00020\u001eH\u0002R\u000e\u0010\u001b\u001a\u00020\u0006X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u001c\u001a\b\u0012\u0004\u0012\u00020\u001e0\u001dX\u0082.\u00a2\u0006\u0002\n\u0000R\u0011\u0010\t\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001f\u0010 R\u0016\u0010!\u001a\n #*\u0004\u0018\u00010\"0\"X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b$\u0010%R\u0011\u0010\u000e\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b&\u0010\'R\u001a\u0010(\u001a\u000e\u0012\u0004\u0012\u00020*\u0012\u0004\u0012\u00020+0)X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010,\u001a\u000e\u0012\u0004\u0012\u00020*\u0012\u0004\u0012\u00020-0)X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b.\u0010/R\u0017\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u000b0\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b0\u0010/R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u00101\u001a\u000202X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u00103\u001a\b\u0012\u0004\u0012\u0002040\u001dX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u00105\u001a\u000206X\u0082.\u00a2\u0006\u0002\n\u0000R\u0014\u00107\u001a\b\u0012\u0004\u0012\u00020408X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u00109\u001a\u00020:X\u0082.\u00a2\u0006\u0002\n\u0000R\u0014\u0010;\u001a\b\u0012\u0004\u0012\u0002020<X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010=\u001a\u00020>X\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010?\u001a\u0004\u0018\u00010@X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010A\u001a\u00020BX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010C\u001a\u000202X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010D\u001a\u00020\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\f\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\bE\u0010FR\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\bG\u0010 "}, d2 = {"Lcom/android/systemui/controls/ui/ControlsUiControllerImpl;", "Lcom/android/systemui/controls/ui/ControlsUiController;", "controlsController", "Ldagger/Lazy;", "Lcom/android/systemui/controls/controller/ControlsController;", "context", "Landroid/content/Context;", "uiExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "bgExecutor", "controlsListingController", "Lcom/android/systemui/controls/management/ControlsListingController;", "sharedPreferences", "Landroid/content/SharedPreferences;", "controlActionCoordinator", "Lcom/android/systemui/controls/ui/ControlActionCoordinator;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "shadeController", "Lcom/android/systemui/statusbar/phone/ShadeController;", "iconCache", "Lcom/android/systemui/controls/CustomIconCache;", "controlsMetricsLogger", "Lcom/android/systemui/controls/ControlsMetricsLogger;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "(Ldagger/Lazy;Landroid/content/Context;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/util/concurrency/DelayableExecutor;Ldagger/Lazy;Landroid/content/SharedPreferences;Lcom/android/systemui/controls/ui/ControlActionCoordinator;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/statusbar/phone/ShadeController;Lcom/android/systemui/controls/CustomIconCache;Lcom/android/systemui/controls/ControlsMetricsLogger;Lcom/android/systemui/statusbar/policy/KeyguardStateController;)V", "activityContext", "allStructures", "", "Lcom/android/systemui/controls/controller/StructureInfo;", "getBgExecutor", "()Lcom/android/systemui/util/concurrency/DelayableExecutor;", "collator", "Ljava/text/Collator;", "kotlin.jvm.PlatformType", "getContext", "()Landroid/content/Context;", "getControlActionCoordinator", "()Lcom/android/systemui/controls/ui/ControlActionCoordinator;", "controlViewsById", "", "Lcom/android/systemui/controls/ui/ControlKey;", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "controlsById", "Lcom/android/systemui/controls/ui/ControlWithState;", "getControlsController", "()Ldagger/Lazy;", "getControlsListingController", "hidden", "", "lastItems", "Lcom/android/systemui/controls/ui/SelectionItem;", "listingCallback", "Lcom/android/systemui/controls/management/ControlsListingController$ControlsListingCallback;", "localeComparator", "Ljava/util/Comparator;", "onDismiss", "Ljava/lang/Runnable;", "onSeedingComplete", "Ljava/util/function/Consumer;", "parent", "Landroid/view/ViewGroup;", "popup", "Landroid/widget/ListPopupWindow;", "popupThemedContext", "Landroid/view/ContextThemeWrapper;", "retainCache", "selectedStructure", "getSharedPreferences", "()Landroid/content/SharedPreferences;", "getUiExecutor", "closeDialogs", "", "immediately", "createCallback", "onResult", "Lkotlin/Function1;", "createDropDown", "items", "selected", "createListView", "createMenu", "createRow", "inflater", "Landroid/view/LayoutInflater;", "listView", "findMaxColumns", "", "findSelectionItem", "si", "getPreferredStructure", "structures", "hide", "onActionResponse", "componentName", "Landroid/content/ComponentName;", "controlId", "", "response", "onRefreshState", "controls", "Landroid/service/controls/Control;", "putIntentExtras", "intent", "Landroid/content/Intent;", "reload", "show", "showControlsView", "showInitialSetupView", "showSeedingView", "startActivity", "startEditingActivity", "startFavoritingActivity", "startProviderSelectorActivity", "startTargetedActivity", "klazz", "Ljava/lang/Class;", "switchAppOrStructure", "item", "updatePreferences", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class ControlsUiControllerImpl implements com.android.systemui.controls.ui.ControlsUiController {
    private com.android.systemui.controls.controller.StructureInfo selectedStructure;
    private java.util.List<com.android.systemui.controls.controller.StructureInfo> allStructures;
    private final java.util.Map<com.android.systemui.controls.ui.ControlKey, com.android.systemui.controls.ui.ControlWithState> controlsById = null;
    private final java.util.Map<com.android.systemui.controls.ui.ControlKey, com.android.systemui.controls.ui.ControlViewHolder> controlViewsById = null;
    private android.view.ViewGroup parent;
    private java.util.List<com.android.systemui.controls.ui.SelectionItem> lastItems;
    private android.widget.ListPopupWindow popup;
    private boolean hidden = true;
    private java.lang.Runnable onDismiss;
    private final android.view.ContextThemeWrapper popupThemedContext = null;
    private boolean retainCache = false;
    private final java.text.Collator collator = null;
    private final java.util.Comparator<com.android.systemui.controls.ui.SelectionItem> localeComparator = null;
    private final java.util.function.Consumer<java.lang.Boolean> onSeedingComplete = null;
    private android.content.Context activityContext;
    private com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback listingCallback;
    @org.jetbrains.annotations.NotNull()
    private final dagger.Lazy<com.android.systemui.controls.controller.ControlsController> controlsController = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.util.concurrency.DelayableExecutor uiExecutor = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.util.concurrency.DelayableExecutor bgExecutor = null;
    @org.jetbrains.annotations.NotNull()
    private final dagger.Lazy<com.android.systemui.controls.management.ControlsListingController> controlsListingController = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.SharedPreferences sharedPreferences = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.controls.ui.ControlActionCoordinator controlActionCoordinator = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final com.android.systemui.statusbar.phone.ShadeController shadeController = null;
    private final com.android.systemui.controls.CustomIconCache iconCache = null;
    private final com.android.systemui.controls.ControlsMetricsLogger controlsMetricsLogger = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    private static final java.lang.String PREF_COMPONENT = "controls_component";
    private static final java.lang.String PREF_STRUCTURE = "controls_structure";
    private static final long FADE_IN_MILLIS = 200L;
    private static final android.content.ComponentName EMPTY_COMPONENT = null;
    private static final com.android.systemui.controls.controller.StructureInfo EMPTY_STRUCTURE = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.ui.ControlsUiControllerImpl.Companion Companion = null;
    
    private final com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback createCallback(kotlin.jvm.functions.Function1<? super java.util.List<com.android.systemui.controls.ui.SelectionItem>, kotlin.Unit> onResult) {
        return null;
    }
    
    @java.lang.Override()
    public void show(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent, @org.jetbrains.annotations.NotNull()
    java.lang.Runnable onDismiss, @org.jetbrains.annotations.NotNull()
    android.content.Context activityContext) {
    }
    
    private final void reload(android.view.ViewGroup parent) {
    }
    
    private final void showSeedingView(java.util.List<com.android.systemui.controls.ui.SelectionItem> items) {
    }
    
    private final void showInitialSetupView(java.util.List<com.android.systemui.controls.ui.SelectionItem> items) {
    }
    
    private final void startFavoritingActivity(com.android.systemui.controls.controller.StructureInfo si) {
    }
    
    private final void startEditingActivity(com.android.systemui.controls.controller.StructureInfo si) {
    }
    
    private final void startTargetedActivity(com.android.systemui.controls.controller.StructureInfo si, java.lang.Class<?> klazz) {
    }
    
    private final void putIntentExtras(android.content.Intent intent, com.android.systemui.controls.controller.StructureInfo si) {
    }
    
    private final void startProviderSelectorActivity() {
    }
    
    private final void startActivity(android.content.Intent intent) {
    }
    
    private final void showControlsView(java.util.List<com.android.systemui.controls.ui.SelectionItem> items) {
    }
    
    private final void createMenu() {
    }
    
    private final void createDropDown(java.util.List<com.android.systemui.controls.ui.SelectionItem> items, com.android.systemui.controls.ui.SelectionItem selected) {
    }
    
    private final void createListView(com.android.systemui.controls.ui.SelectionItem selected) {
    }
    
    /**
     * For low-dp width screens that also employ an increased font scale, adjust the
     * number of columns. This helps prevent text truncation on these devices.
     */
    private final int findMaxColumns() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.controls.controller.StructureInfo getPreferredStructure(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.controls.controller.StructureInfo> structures) {
        return null;
    }
    
    private final void updatePreferences(com.android.systemui.controls.controller.StructureInfo si) {
    }
    
    private final void switchAppOrStructure(com.android.systemui.controls.ui.SelectionItem item) {
    }
    
    @java.lang.Override()
    public void closeDialogs(boolean immediately) {
    }
    
    @java.lang.Override()
    public void hide() {
    }
    
    @java.lang.Override()
    public void onRefreshState(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.util.List<android.service.controls.Control> controls) {
    }
    
    @java.lang.Override()
    public void onActionResponse(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.String controlId, int response) {
    }
    
    private final android.view.ViewGroup createRow(android.view.LayoutInflater inflater, android.view.ViewGroup listView) {
        return null;
    }
    
    private final com.android.systemui.controls.ui.SelectionItem findSelectionItem(com.android.systemui.controls.controller.StructureInfo si, java.util.List<com.android.systemui.controls.ui.SelectionItem> items) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final dagger.Lazy<com.android.systemui.controls.controller.ControlsController> getControlsController() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.concurrency.DelayableExecutor getUiExecutor() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.concurrency.DelayableExecutor getBgExecutor() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final dagger.Lazy<com.android.systemui.controls.management.ControlsListingController> getControlsListingController() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.SharedPreferences getSharedPreferences() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ui.ControlActionCoordinator getControlActionCoordinator() {
        return null;
    }
    
    @javax.inject.Inject()
    public ControlsUiControllerImpl(@org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.controls.controller.ControlsController> controlsController, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor uiExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    com.android.systemui.util.concurrency.DelayableExecutor bgExecutor, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.controls.management.ControlsListingController> controlsListingController, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.content.SharedPreferences sharedPreferences, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlActionCoordinator controlActionCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.ShadeController shadeController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.CustomIconCache iconCache, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ControlsMetricsLogger controlsMetricsLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000e\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\nX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/ControlsUiControllerImpl$Companion;", "", "()V", "EMPTY_COMPONENT", "Landroid/content/ComponentName;", "EMPTY_STRUCTURE", "Lcom/android/systemui/controls/controller/StructureInfo;", "FADE_IN_MILLIS", "", "PREF_COMPONENT", "", "PREF_STRUCTURE"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}