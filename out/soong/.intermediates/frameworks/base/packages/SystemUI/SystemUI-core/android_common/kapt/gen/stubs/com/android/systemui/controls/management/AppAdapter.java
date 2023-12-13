package com.android.systemui.controls.management;

import android.content.ComponentName;
import android.content.res.Resources;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.lifecycle.Lifecycle;
import androidx.lifecycle.LifecycleOwner;
import androidx.recyclerview.widget.RecyclerView;
import com.android.systemui.R;
import com.android.systemui.controls.ControlsServiceInfo;
import java.text.Collator;
import java.util.concurrent.Executor;

/**
 * Adapter for binding [ControlsServiceInfo] related to [ControlsProviderService].
 *
 * This class handles subscribing and keeping track of the list of valid applications for
 * displaying.
 *
 * @param uiExecutor an executor on the view thread of the containing [RecyclerView]
 * @param lifecycle the lifecycle of the containing [LifecycleOwner] to control listening status
 * @param controlsListingController the controller to keep track of valid applications
 * @param layoutInflater an inflater for the views in the containing [RecyclerView]
 * @param onAppSelected a callback to indicate that an app has been selected in the list.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000d\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001:\u0001#BU\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0004\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0016\b\u0002\u0010\f\u001a\u0010\u0012\u0006\u0012\u0004\u0018\u00010\u000e\u0012\u0004\u0012\u00020\u000f0\r\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u00a2\u0006\u0002\u0010\u0014J\b\u0010\u001a\u001a\u00020\u001bH\u0016J\u0018\u0010\u001c\u001a\u00020\u000f2\u0006\u0010\u001d\u001a\u00020\u00022\u0006\u0010\u001e\u001a\u00020\u001bH\u0016J\u0018\u0010\u001f\u001a\u00020\u00022\u0006\u0010 \u001a\u00020!2\u0006\u0010\"\u001a\u00020\u001bH\u0016R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\u00190\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001c\u0010\f\u001a\u0010\u0012\u0006\u0012\u0004\u0018\u00010\u000e\u0012\u0004\u0012\u00020\u000f0\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/AppAdapter;", "Landroidx/recyclerview/widget/RecyclerView$Adapter;", "Lcom/android/systemui/controls/management/AppAdapter$Holder;", "backgroundExecutor", "Ljava/util/concurrent/Executor;", "uiExecutor", "lifecycle", "Landroidx/lifecycle/Lifecycle;", "controlsListingController", "Lcom/android/systemui/controls/management/ControlsListingController;", "layoutInflater", "Landroid/view/LayoutInflater;", "onAppSelected", "Lkotlin/Function1;", "Landroid/content/ComponentName;", "", "favoritesRenderer", "Lcom/android/systemui/controls/management/FavoritesRenderer;", "resources", "Landroid/content/res/Resources;", "(Ljava/util/concurrent/Executor;Ljava/util/concurrent/Executor;Landroidx/lifecycle/Lifecycle;Lcom/android/systemui/controls/management/ControlsListingController;Landroid/view/LayoutInflater;Lkotlin/jvm/functions/Function1;Lcom/android/systemui/controls/management/FavoritesRenderer;Landroid/content/res/Resources;)V", "callback", "Lcom/android/systemui/controls/management/ControlsListingController$ControlsListingCallback;", "listOfServices", "", "Lcom/android/systemui/controls/ControlsServiceInfo;", "getItemCount", "", "onBindViewHolder", "holder", "index", "onCreateViewHolder", "parent", "Landroid/view/ViewGroup;", "i", "Holder"})
public final class AppAdapter extends androidx.recyclerview.widget.RecyclerView.Adapter<com.android.systemui.controls.management.AppAdapter.Holder> {
    private java.util.List<com.android.systemui.controls.ControlsServiceInfo> listOfServices;
    private final com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback callback = null;
    private final android.view.LayoutInflater layoutInflater = null;
    private final kotlin.jvm.functions.Function1<android.content.ComponentName, kotlin.Unit> onAppSelected = null;
    private final com.android.systemui.controls.management.FavoritesRenderer favoritesRenderer = null;
    private final android.content.res.Resources resources = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.controls.management.AppAdapter.Holder onCreateViewHolder(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent, int i) {
        return null;
    }
    
    @java.lang.Override()
    public int getItemCount() {
        return 0;
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.AppAdapter.Holder holder, int index) {
    }
    
    public AppAdapter(@org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor backgroundExecutor, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor uiExecutor, @org.jetbrains.annotations.NotNull()
    androidx.lifecycle.Lifecycle lifecycle, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsListingController controlsListingController, @org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater layoutInflater, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super android.content.ComponentName, kotlin.Unit> onAppSelected, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.FavoritesRenderer favoritesRenderer, @org.jetbrains.annotations.NotNull()
    android.content.res.Resources resources) {
        super();
    }
    
    /**
     * Holder for binding views in the [RecyclerView]-
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u000e\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/AppAdapter$Holder;", "Landroidx/recyclerview/widget/RecyclerView$ViewHolder;", "view", "Landroid/view/View;", "favRenderer", "Lcom/android/systemui/controls/management/FavoritesRenderer;", "(Landroid/view/View;Lcom/android/systemui/controls/management/FavoritesRenderer;)V", "getFavRenderer", "()Lcom/android/systemui/controls/management/FavoritesRenderer;", "favorites", "Landroid/widget/TextView;", "icon", "Landroid/widget/ImageView;", "title", "bindData", "", "data", "Lcom/android/systemui/controls/ControlsServiceInfo;"})
    public static final class Holder extends androidx.recyclerview.widget.RecyclerView.ViewHolder {
        private final android.widget.ImageView icon = null;
        private final android.widget.TextView title = null;
        private final android.widget.TextView favorites = null;
        @org.jetbrains.annotations.NotNull()
        private final com.android.systemui.controls.management.FavoritesRenderer favRenderer = null;
        
        /**
         * Bind data to the view
         * @param data Information about the [ControlsProviderService] to bind to the data
         */
        public final void bindData(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ControlsServiceInfo data) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.controls.management.FavoritesRenderer getFavRenderer() {
            return null;
        }
        
        public Holder(@org.jetbrains.annotations.NotNull()
        android.view.View view, @org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.management.FavoritesRenderer favRenderer) {
            super(null);
        }
    }
}