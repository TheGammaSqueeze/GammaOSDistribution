package com.android.systemui.controls.management;

import android.content.ComponentName;
import android.util.Log;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.RecyclerView;
import com.android.systemui.controls.ControlInterface;
import com.android.systemui.controls.CustomIconCache;
import com.android.systemui.controls.controller.ControlInfo;
import java.util.Collections;

/**
 * Model used to show and rearrange favorites.
 *
 * The model will show all the favorite controls and a divider that can be toggled visible/gone.
 * It will place the items selected as favorites before the divider and the ones unselected after.
 *
 * @property componentName used by the [ControlAdapter] to retrieve resources.
 * @property favorites list of current favorites
 * @property favoritesModelCallback callback to notify on first change and empty favorites
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\r\u0018\u0000 /2\u00020\u0001:\u0002/0B+\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0014\u0010\u001f\u001a\u00020 2\n\u0010\f\u001a\u0006\u0012\u0002\b\u00030\rH\u0016J\u0018\u0010!\u001a\u00020 2\u0006\u0010\"\u001a\u00020#2\u0006\u0010$\u001a\u00020\u001aH\u0016J\u0018\u0010%\u001a\u00020 2\u0006\u0010&\u001a\u00020\u000f2\u0006\u0010\'\u001a\u00020\u000fH\u0002J\u0018\u0010(\u001a\u00020 2\u0006\u0010&\u001a\u00020\u000f2\u0006\u0010\'\u001a\u00020\u000fH\u0016J\u0018\u0010)\u001a\u00020 2\u0006\u0010&\u001a\u00020\u000f2\u0006\u0010\'\u001a\u00020\u000fH\u0002J\u0018\u0010*\u001a\u00020 2\u0006\u0010&\u001a\u00020\u000f2\u0006\u0010\'\u001a\u00020\u000fH\u0002J\u0018\u0010+\u001a\u00020 2\u0006\u0010,\u001a\u00020\u000f2\u0006\u0010-\u001a\u00020\u001aH\u0002J\u0018\u0010.\u001a\u00020 2\u0006\u0010,\u001a\u00020\u000f2\u0006\u0010-\u001a\u00020\u001aH\u0002R\u0014\u0010\f\u001a\b\u0012\u0002\b\u0003\u0018\u00010\rX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00110\u0007X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u001a\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u00078VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0014\u0010\u0013R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0015\u001a\u00020\u0016\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0018R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u001b\u001a\u00020\u001cX\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u001e"}, d2 = {"Lcom/android/systemui/controls/management/FavoritesModel;", "Lcom/android/systemui/controls/management/ControlsModel;", "customIconCache", "Lcom/android/systemui/controls/CustomIconCache;", "componentName", "Landroid/content/ComponentName;", "favorites", "", "Lcom/android/systemui/controls/controller/ControlInfo;", "favoritesModelCallback", "Lcom/android/systemui/controls/management/FavoritesModel$FavoritesModelCallback;", "(Lcom/android/systemui/controls/CustomIconCache;Landroid/content/ComponentName;Ljava/util/List;Lcom/android/systemui/controls/management/FavoritesModel$FavoritesModelCallback;)V", "adapter", "Landroidx/recyclerview/widget/RecyclerView$Adapter;", "dividerPosition", "", "elements", "Lcom/android/systemui/controls/management/ElementWrapper;", "getElements", "()Ljava/util/List;", "getFavorites", "itemTouchHelperCallback", "Landroidx/recyclerview/widget/ItemTouchHelper$SimpleCallback;", "getItemTouchHelperCallback", "()Landroidx/recyclerview/widget/ItemTouchHelper$SimpleCallback;", "modified", "", "moveHelper", "Lcom/android/systemui/controls/management/ControlsModel$MoveHelper;", "getMoveHelper", "()Lcom/android/systemui/controls/management/ControlsModel$MoveHelper;", "attachAdapter", "", "changeFavoriteStatus", "controlId", "", "favorite", "moveElement", "from", "to", "onMoveItem", "onMoveItemInternal", "updateDivider", "updateDividerNone", "oldDividerPosition", "show", "updateDividerShow", "Companion", "FavoritesModelCallback"})
public final class FavoritesModel implements com.android.systemui.controls.management.ControlsModel {
    private androidx.recyclerview.widget.RecyclerView.Adapter<?> adapter;
    private boolean modified = false;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.controls.management.ControlsModel.MoveHelper moveHelper = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<com.android.systemui.controls.management.ElementWrapper> elements = null;
    
    /**
     * Indicates the position of the divider to determine
     */
    private int dividerPosition;
    
    /**
     * Touch helper to facilitate dragging in the [RecyclerView].
     *
     * Only views above the divider line (favorites) can be dragged or accept drops.
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.recyclerview.widget.ItemTouchHelper.SimpleCallback itemTouchHelperCallback = null;
    private final com.android.systemui.controls.CustomIconCache customIconCache = null;
    private final android.content.ComponentName componentName = null;
    private final com.android.systemui.controls.management.FavoritesModel.FavoritesModelCallback favoritesModelCallback = null;
    private static final java.lang.String TAG = "FavoritesModel";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.management.FavoritesModel.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.controls.management.ControlsModel.MoveHelper getMoveHelper() {
        return null;
    }
    
    @java.lang.Override()
    public void attachAdapter(@org.jetbrains.annotations.NotNull()
    androidx.recyclerview.widget.RecyclerView.Adapter<?> adapter) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.List<com.android.systemui.controls.controller.ControlInfo> getFavorites() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.List<com.android.systemui.controls.management.ElementWrapper> getElements() {
        return null;
    }
    
    @java.lang.Override()
    public void changeFavoriteStatus(@org.jetbrains.annotations.NotNull()
    java.lang.String controlId, boolean favorite) {
    }
    
    @java.lang.Override()
    public void onMoveItem(int from, int to) {
    }
    
    private final void updateDividerNone(int oldDividerPosition, boolean show) {
    }
    
    private final void updateDividerShow(int oldDividerPosition, boolean show) {
    }
    
    /**
     * Performs the update in the model.
     *
     *  * update the favorite field of the [ControlInterface]
     *  * update the fields of the [DividerWrapper]
     *  * move the corresponding element in [elements]
     *
     * It may emit the following signals:
     *  * [RecyclerView.Adapter.notifyItemChanged] if a [ControlInterface.favorite] has changed
     *    (in the new position) or if the information in [DividerWrapper] has changed (in the
     *    old position).
     *  * [RecyclerView.Adapter.notifyItemMoved]
     *  * [FavoritesModelCallback.onNoneChanged] whenever we go from 1 to 0 favorites and back
     *  * [ControlsModel.ControlsModelCallback.onFirstChange] upon the first change in the model
     */
    private final void onMoveItemInternal(int from, int to) {
    }
    
    private final void updateDivider(int from, int to) {
    }
    
    private final void moveElement(int from, int to) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.recyclerview.widget.ItemTouchHelper.SimpleCallback getItemTouchHelperCallback() {
        return null;
    }
    
    public FavoritesModel(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.CustomIconCache customIconCache, @org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.controls.controller.ControlInfo> favorites, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.FavoritesModel.FavoritesModelCallback favoritesModelCallback) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/controls/management/FavoritesModel$FavoritesModelCallback;", "Lcom/android/systemui/controls/management/ControlsModel$ControlsModelCallback;", "onNoneChanged", "", "showNoFavorites", ""})
    public static abstract interface FavoritesModelCallback extends com.android.systemui.controls.management.ControlsModel.ControlsModelCallback {
        
        public abstract void onNoneChanged(boolean showNoFavorites);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/FavoritesModel$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}