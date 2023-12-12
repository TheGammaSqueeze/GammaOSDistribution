package com.android.systemui.controls.controller;

import android.content.ComponentName;
import android.service.controls.Control;
import android.service.controls.ControlsProviderService;
import android.service.controls.actions.ControlAction;
import com.android.systemui.controls.ControlStatus;
import com.android.systemui.util.UserAwareController;
import com.android.systemui.controls.management.ControlsFavoritingActivity;
import com.android.systemui.controls.ui.ControlsUiController;
import java.util.function.Consumer;

/**
 * Controller to handle communication between different parts of the controls system.
 *
 * This controller is in charge of:
 * * Keeping track of favorites
 * * Determining and keeping track of whether controls are enabled
 * * Listening for user change and propagating that message in the system
 * * Communicate between the UI and the [ControlsBindingController]
 *
 * This controller being a [UserAwareController] means that all operations will be conducted on
 * information for the current user only.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000l\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\r\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\bf\u0018\u00002\u00020\u0001:\u0001+J \u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u00072\u0006\u0010\u0002\u001a\u00020\bH&J \u0010\t\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\u0006\u001a\u00020\u0007H&J\u0016\u0010\f\u001a\u00020\r2\f\u0010\u000e\u001a\b\u0012\u0004\u0012\u00020\r0\u000fH&J\u0010\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0004\u001a\u00020\u0005H&J\u000e\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00140\u0013H&J\u0016\u0010\u0015\u001a\b\u0012\u0004\u0012\u00020\u00140\u00132\u0006\u0010\u0004\u001a\u00020\u0005H&J\u001e\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\u00070\u00132\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\n\u001a\u00020\u000bH&J\b\u0010\u0017\u001a\u00020\u0014H&J,\u0010\u0018\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\f\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u001a0\u000f2\f\u0010\u001b\u001a\b\u0012\u0004\u0012\u00020\u001c0\u000fH&J \u0010\u001d\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u001e\u001a\u00020\u001f2\u0006\u0010 \u001a\u00020\u0011H&J\u0018\u0010!\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\"\u001a\u00020#H&J\u0010\u0010$\u001a\u00020\u00032\u0006\u0010%\u001a\u00020\u0014H&J$\u0010&\u001a\u00020\u00032\f\u0010\'\u001a\b\u0012\u0004\u0012\u00020\u00050\u00132\f\u0010\u000e\u001a\b\u0012\u0004\u0012\u00020(0\u000fH&J\u0010\u0010)\u001a\u00020\u00032\u0006\u0010%\u001a\u00020\u0014H&J\b\u0010*\u001a\u00020\u0003H&\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsController;", "Lcom/android/systemui/util/UserAwareController;", "action", "", "componentName", "Landroid/content/ComponentName;", "controlInfo", "Lcom/android/systemui/controls/controller/ControlInfo;", "Landroid/service/controls/actions/ControlAction;", "addFavorite", "structureName", "", "addSeedingFavoritesCallback", "", "callback", "Ljava/util/function/Consumer;", "countFavoritesForComponent", "", "getFavorites", "", "Lcom/android/systemui/controls/controller/StructureInfo;", "getFavoritesForComponent", "getFavoritesForStructure", "getPreferredStructure", "loadForComponent", "dataCallback", "Lcom/android/systemui/controls/controller/ControlsController$LoadData;", "cancelWrapper", "Ljava/lang/Runnable;", "onActionResponse", "controlId", "", "response", "refreshStatus", "control", "Landroid/service/controls/Control;", "replaceFavoritesForStructure", "structureInfo", "seedFavoritesForComponents", "componentNames", "Lcom/android/systemui/controls/controller/SeedResponse;", "subscribeToFavorites", "unsubscribe", "LoadData"})
public abstract interface ControlsController extends com.android.systemui.util.UserAwareController {
    
    /**
     * Load all available [Control] for a given service.
     *
     * @param componentName the [ComponentName] of the [ControlsProviderService] to load from
     * @param dataCallback a callback in which to retrieve the result
     * @param cancelWrapper a callback to receive a [Runnable] that can be run to cancel the
     *                     request
     */
    public abstract void loadForComponent(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.util.function.Consumer<com.android.systemui.controls.controller.ControlsController.LoadData> dataCallback, @org.jetbrains.annotations.NotNull()
    java.util.function.Consumer<java.lang.Runnable> cancelWrapper);
    
    /**
     * Request to subscribe for favorited controls per structure
     *
     * @param structureInfo structure to limit the subscription to
     * @see [ControlsBindingController.subscribe]
     */
    public abstract void subscribeToFavorites(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.StructureInfo structureInfo);
    
    /**
     * Request to unsubscribe to the current provider.
     *
     * @see [ControlsBindingController.unsubscribe]
     */
    public abstract void unsubscribe();
    
    /**
     * Notify a [ControlsProviderService] that an action has been performed on a [Control].
     *
     * @param componentName the name of the service that provides the [Control]
     * @param controlInfo information of the [Control] receiving the action
     * @param action action performed on the [Control]
     * @see [ControlsBindingController.action]
     */
    public abstract void action(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlInfo controlInfo, @org.jetbrains.annotations.NotNull()
    android.service.controls.actions.ControlAction action);
    
    /**
     * Refresh the status of a [Control] with information provided from the service.
     *
     * @param componentName the name of the service that provides the [Control]
     * @param control a stateful [Control] with updated information
     * @see [ControlsUiController.onRefreshState]
     */
    public abstract void refreshStatus(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    android.service.controls.Control control);
    
    /**
     * Indicate the result of a [ControlAction] performed on a [Control].
     *
     * @param componentName the name of the service that provides the [Control]
     * @param controlId the id of the [Control] the actioned was performed on
     * @param response the result of the action.
     * @see [ControlsUiController.onActionResponse]
     */
    public abstract void onActionResponse(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.String controlId, @android.service.controls.actions.ControlAction.ResponseResult()
    int response);
    
    /**
     * Send a request to seed favorites into the persisted XML file
     *
     * @param componentNames the list of components to seed controls from
     * @param callback one [SeedResponse] per componentName
     */
    public abstract void seedFavoritesForComponents(@org.jetbrains.annotations.NotNull()
    java.util.List<android.content.ComponentName> componentNames, @org.jetbrains.annotations.NotNull()
    java.util.function.Consumer<com.android.systemui.controls.controller.SeedResponse> callback);
    
    /**
     * Callback to be informed when the seeding process has finished
     *
     * @param callback consumer accepts true if successful
     * @return true if seeding is in progress and the callback was added
     */
    public abstract boolean addSeedingFavoritesCallback(@org.jetbrains.annotations.NotNull()
    java.util.function.Consumer<java.lang.Boolean> callback);
    
    /**
     * Get all the favorites.
     *
     * @return a list of the structures that have at least one favorited control
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.util.List<com.android.systemui.controls.controller.StructureInfo> getFavorites();
    
    /**
     * Get all the favorites for a given component.
     *
     * @param componentName the name of the service that provides the [Control]
     * @return a list of the structures that have at least one favorited control
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.util.List<com.android.systemui.controls.controller.StructureInfo> getFavoritesForComponent(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName);
    
    /**
     * Get all the favorites for a given structure.
     *
     * @param componentName the name of the service that provides the [Control]
     * @param structureName the name of the structure
     * @return a list of the current favorites in that structure
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.util.List<com.android.systemui.controls.controller.ControlInfo> getFavoritesForStructure(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structureName);
    
    /**
     * Adds a single favorite to a given component and structure
     * @param componentName the name of the service that provides the [Control]
     * @param structureName the name of the structure that holds the [Control]
     * @param controlInfo persistent information about the [Control] to be added.
     */
    public abstract void addFavorite(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structureName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlInfo controlInfo);
    
    /**
     * Replaces the favorites for the given structure.
     *
     * Calling this method will eliminate the previous selection of favorites and replace it with a
     * new one.
     *
     * @param structureInfo common structure for all of the favorited controls
     */
    public abstract void replaceFavoritesForStructure(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.StructureInfo structureInfo);
    
    /**
     * Return the number of favorites for a given component.
     *
     * This call returns the same as `getFavoritesForComponent(componentName).size`.
     *
     * @param componentName the name of the component
     * @return the number of current favorites for the given component
     */
    public abstract int countFavoritesForComponent(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName);
    
    /**
     * See [ControlsUiController.getPreferredStructure].
     */
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.controls.controller.StructureInfo getPreferredStructure();
    
    /**
     * Interface for structure to pass data to [ControlsFavoritingActivity].
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0000\bf\u0018\u00002\u00020\u0001R\u0018\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0005\u0010\u0006R\u0012\u0010\u0007\u001a\u00020\bX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\t\u0010\nR\u0018\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\f0\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\r\u0010\u0006"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsController$LoadData;", "", "allControls", "", "Lcom/android/systemui/controls/ControlStatus;", "getAllControls", "()Ljava/util/List;", "errorOnLoad", "", "getErrorOnLoad", "()Z", "favoritesIds", "", "getFavoritesIds"})
    public static abstract interface LoadData {
        
        /**
         * All of the available controls for the loaded [ControlsProviderService].
         *
         * This will indicate if they are currently a favorite and whether they were removed (a
         * favorite but not retrieved on load).
         */
        @org.jetbrains.annotations.NotNull()
        public abstract java.util.List<com.android.systemui.controls.ControlStatus> getAllControls();
        
        /**
         * Ordered list of ids of favorite controls.
         */
        @org.jetbrains.annotations.NotNull()
        public abstract java.util.List<java.lang.String> getFavoritesIds();
        
        /**
         * Whether there was an error in loading.
         *
         * In this case, [allControls] will only contain those that were favorited and will not be
         * marked as removed.
         */
        public abstract boolean getErrorOnLoad();
    }
}