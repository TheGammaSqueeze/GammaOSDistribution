package com.android.systemui.controls.management;

import android.content.ComponentName;
import android.graphics.drawable.Icon;
import androidx.recyclerview.widget.RecyclerView;
import com.android.systemui.controls.ControlInterface;
import com.android.systemui.controls.ControlStatus;
import com.android.systemui.controls.controller.ControlInfo;

/**
 * Model for using with [ControlAdapter].
 *
 * Implementations of this interface provide different views of the controls to show.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\bf\u0018\u00002\u00020\u0001:\u0002\u001b\u001cJ\u0014\u0010\u000e\u001a\u00020\u000f2\n\u0010\u0010\u001a\u0006\u0012\u0002\b\u00030\u0011H\u0016J\u0018\u0010\u0012\u001a\u00020\u000f2\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016H\u0016J\u0018\u0010\u0017\u001a\u00020\u000f2\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u0019H\u0016R\u0018\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0005\u0010\u0006R\u0018\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\b0\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\t\u0010\u0006R\u0014\u0010\n\u001a\u0004\u0018\u00010\u000bX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\r"}, d2 = {"Lcom/android/systemui/controls/management/ControlsModel;", "", "elements", "", "Lcom/android/systemui/controls/management/ElementWrapper;", "getElements", "()Ljava/util/List;", "favorites", "Lcom/android/systemui/controls/controller/ControlInfo;", "getFavorites", "moveHelper", "Lcom/android/systemui/controls/management/ControlsModel$MoveHelper;", "getMoveHelper", "()Lcom/android/systemui/controls/management/ControlsModel$MoveHelper;", "attachAdapter", "", "adapter", "Landroidx/recyclerview/widget/RecyclerView$Adapter;", "changeFavoriteStatus", "controlId", "", "favorite", "", "onMoveItem", "from", "", "to", "ControlsModelCallback", "MoveHelper"})
public abstract interface ControlsModel {
    
    /**
     * List of favorites in order.
     *
     * This should be obtained prior to storing the favorites using
     * [ControlsController.replaceFavoritesForComponent].
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.util.List<com.android.systemui.controls.controller.ControlInfo> getFavorites();
    
    /**
     * List of all the elements to display by the corresponding [RecyclerView].
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.util.List<com.android.systemui.controls.management.ElementWrapper> getElements();
    
    @org.jetbrains.annotations.Nullable()
    public abstract com.android.systemui.controls.management.ControlsModel.MoveHelper getMoveHelper();
    
    /**
     * Change the favorite status of a particular control.
     */
    public abstract void changeFavoriteStatus(@org.jetbrains.annotations.NotNull()
    java.lang.String controlId, boolean favorite);
    
    /**
     * Move an item (in elements) from one position to another.
     */
    public abstract void onMoveItem(int from, int to);
    
    /**
     * Attach an adapter to the model.
     *
     * This can be used to notify the adapter of changes in the model.
     */
    public abstract void attachAdapter(@org.jetbrains.annotations.NotNull()
    androidx.recyclerview.widget.RecyclerView.Adapter<?> adapter);
    
    /**
     * Callback to notify elements (other than the adapter) of relevant changes in the model.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u000e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\bf\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H&"}, d2 = {"Lcom/android/systemui/controls/management/ControlsModel$ControlsModelCallback;", "", "onFirstChange", ""})
    public static abstract interface ControlsModelCallback {
        
        /**
         * Use to notify that the model has changed for the first time
         */
        public abstract void onFirstChange();
    }
    
    /**
     * Interface to facilitate moving controls from an [AccessibilityDelegate].
     *
     * All positions should be 0 based.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\u0010\u0010\u0006\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\u0004\u001a\u00020\u0005H&J\u0010\u0010\t\u001a\u00020\b2\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/controls/management/ControlsModel$MoveHelper;", "", "canMoveAfter", "", "position", "", "canMoveBefore", "moveAfter", "", "moveBefore"})
    public static abstract interface MoveHelper {
        
        /**
         * Whether the control in `position` can be moved to the position before it.
         */
        public abstract boolean canMoveBefore(int position);
        
        /**
         * Whether the control in `position` can be moved to the position after it.
         */
        public abstract boolean canMoveAfter(int position);
        
        /**
         * Move the control in `position` to the position before it.
         */
        public abstract void moveBefore(int position);
        
        /**
         * Move the control in `position` to the position after it.
         */
        public abstract void moveAfter(int position);
    }
    
    /**
     * Model for using with [ControlAdapter].
     *
     * Implementations of this interface provide different views of the controls to show.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
    public final class DefaultImpls {
        
        /**
         * Change the favorite status of a particular control.
         */
        public static void changeFavoriteStatus(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.management.ControlsModel $this, @org.jetbrains.annotations.NotNull()
        java.lang.String controlId, boolean favorite) {
        }
        
        /**
         * Move an item (in elements) from one position to another.
         */
        public static void onMoveItem(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.management.ControlsModel $this, int from, int to) {
        }
        
        /**
         * Attach an adapter to the model.
         *
         * This can be used to notify the adapter of changes in the model.
         */
        public static void attachAdapter(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.management.ControlsModel $this, @org.jetbrains.annotations.NotNull()
        androidx.recyclerview.widget.RecyclerView.Adapter<?> adapter) {
        }
    }
}