package com.android.systemui.controls.management;

import android.text.TextUtils;
import android.util.ArrayMap;
import com.android.systemui.controls.ControlStatus;
import com.android.systemui.controls.controller.ControlInfo;

/**
 * This model is used to show controls separated by zones.
 *
 * The model will sort the controls and zones in the following manner:
 * * The zones will be sorted in a first seen basis
 * * The controls in each zone will be sorted in a first seen basis.
 *
 * The controls passed should belong to the same structure, as an instance of this model will be
 * created for each structure.
 *
 * The list of favorite ids can contain ids for controls not passed to this model. Those will be
 * filtered out.
 *
 * @property controls List of controls as returned by loading
 * @property initialFavoriteIds sorted ids of favorite controls.
 * @property noZoneString text to use as header for all controls that have blank or `null` zone.
 * @property controlsModelCallback callback to notify that favorites have changed for the first time
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010!\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0001\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0005\u0018\u00002\u00020\u0001:\u0001!B1\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00060\u0003\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0018\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\u00062\u0006\u0010\u001e\u001a\u00020\u0016H\u0016J\u001c\u0010\u001f\u001a\b\u0012\u0004\u0012\u00020\r0\u00032\f\u0010 \u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u0002R\u0014\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\f\u001a\b\u0012\u0004\u0012\u00020\r0\u0003X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00060\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00130\u00038VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0014\u0010\u000fR\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0017\u001a\u0004\u0018\u00010\u0018X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0019\u0010\u001a"}, d2 = {"Lcom/android/systemui/controls/management/AllModel;", "Lcom/android/systemui/controls/management/ControlsModel;", "controls", "", "Lcom/android/systemui/controls/ControlStatus;", "initialFavoriteIds", "", "emptyZoneString", "", "controlsModelCallback", "Lcom/android/systemui/controls/management/ControlsModel$ControlsModelCallback;", "(Ljava/util/List;Ljava/util/List;Ljava/lang/CharSequence;Lcom/android/systemui/controls/management/ControlsModel$ControlsModelCallback;)V", "elements", "Lcom/android/systemui/controls/management/ElementWrapper;", "getElements", "()Ljava/util/List;", "favoriteIds", "", "favorites", "Lcom/android/systemui/controls/controller/ControlInfo;", "getFavorites", "modified", "", "moveHelper", "", "getMoveHelper", "()Ljava/lang/Void;", "changeFavoriteStatus", "", "controlId", "favorite", "createWrappers", "list", "OrderedMap"})
public final class AllModel implements com.android.systemui.controls.management.ControlsModel {
    private boolean modified = false;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.Void moveHelper = null;
    private final java.util.List<java.lang.String> favoriteIds = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<com.android.systemui.controls.management.ElementWrapper> elements = null;
    private final java.util.List<com.android.systemui.controls.ControlStatus> controls = null;
    private final java.lang.CharSequence emptyZoneString = null;
    private final com.android.systemui.controls.management.ControlsModel.ControlsModelCallback controlsModelCallback = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Void getMoveHelper() {
        return null;
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
    
    private final java.util.List<com.android.systemui.controls.management.ElementWrapper> createWrappers(java.util.List<com.android.systemui.controls.ControlStatus> list) {
        return null;
    }
    
    public AllModel(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.controls.ControlStatus> controls, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> initialFavoriteIds, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence emptyZoneString, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsModel.ControlsModelCallback controlsModelCallback) {
        super();
    }
    
    /**
     * Move an item (in elements) from one position to another.
     */
    public void onMoveItem(int from, int to) {
    }
    
    /**
     * Attach an adapter to the model.
     *
     * This can be used to notify the adapter of changes in the model.
     */
    public void attachAdapter(@org.jetbrains.annotations.NotNull()
    androidx.recyclerview.widget.RecyclerView.Adapter<?> adapter) {
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000H\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\b\u0003\n\u0002\u0010#\n\u0002\u0010\'\n\u0002\b\u0005\n\u0002\u0010!\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u001f\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u000b\n\u0002\u0010$\n\u0000\b\u0002\u0018\u0000*\u0004\b\u0000\u0010\u0001*\u0004\b\u0001\u0010\u00022\u000e\u0012\u0004\u0012\u0002H\u0001\u0012\u0004\u0012\u0002H\u00020\u0003B\u0019\u0012\u0012\u0010\u0004\u001a\u000e\u0012\u0004\u0012\u00028\u0000\u0012\u0004\u0012\u00028\u00010\u0003\u00a2\u0006\u0002\u0010\u0005J\b\u0010\u0019\u001a\u00020\u001aH\u0016J\u0016\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00028\u0000H\u0096\u0001\u00a2\u0006\u0002\u0010\u001eJ\u0016\u0010\u001f\u001a\u00020\u001c2\u0006\u0010 \u001a\u00028\u0001H\u0096\u0001\u00a2\u0006\u0002\u0010\u001eJ\u0018\u0010!\u001a\u0004\u0018\u00018\u00012\u0006\u0010\u001d\u001a\u00028\u0000H\u0096\u0003\u00a2\u0006\u0002\u0010\"J\t\u0010#\u001a\u00020\u001cH\u0096\u0001J\u001f\u0010$\u001a\u0004\u0018\u00018\u00012\u0006\u0010\u001d\u001a\u00028\u00002\u0006\u0010 \u001a\u00028\u0001H\u0016\u00a2\u0006\u0002\u0010%J\u001f\u0010&\u001a\u00020\u001a2\u0014\u0010\'\u001a\u0010\u0012\u0006\b\u0001\u0012\u00028\u0000\u0012\u0004\u0012\u00028\u00010(H\u0096\u0001J\u0017\u0010)\u001a\u0004\u0018\u00018\u00012\u0006\u0010\u001d\u001a\u00028\u0000H\u0016\u00a2\u0006\u0002\u0010\"R$\u0010\u0006\u001a\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00028\u0000\u0012\u0004\u0012\u00028\u00010\b0\u0007X\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b\t\u0010\nR\u0018\u0010\u000b\u001a\b\u0012\u0004\u0012\u00028\u00000\u0007X\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\nR\u001a\u0010\u0004\u001a\u000e\u0012\u0004\u0012\u00028\u0000\u0012\u0004\u0012\u00028\u00010\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0017\u0010\r\u001a\b\u0012\u0004\u0012\u00028\u00000\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0012\u0010\u0011\u001a\u00020\u0012X\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b\u0013\u0010\u0014R\u0018\u0010\u0015\u001a\b\u0012\u0004\u0012\u00028\u00010\u0016X\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b\u0017\u0010\u0018"}, d2 = {"Lcom/android/systemui/controls/management/AllModel$OrderedMap;", "K", "V", "", "map", "(Ljava/util/Map;)V", "entries", "", "", "getEntries", "()Ljava/util/Set;", "keys", "getKeys", "orderedKeys", "", "getOrderedKeys", "()Ljava/util/List;", "size", "", "getSize", "()I", "values", "", "getValues", "()Ljava/util/Collection;", "clear", "", "containsKey", "", "key", "(Ljava/lang/Object;)Z", "containsValue", "value", "get", "(Ljava/lang/Object;)Ljava/lang/Object;", "isEmpty", "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", "putAll", "from", "", "remove"})
    static final class OrderedMap<K extends java.lang.Object, V extends java.lang.Object> implements java.util.Map<K, V> {
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<K> orderedKeys = null;
        private final java.util.Map<K, V> map = null;
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<K> getOrderedKeys() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        @java.lang.Override()
        public V put(K key, V value) {
            return null;
        }
        
        @java.lang.Override()
        public void clear() {
        }
        
        @org.jetbrains.annotations.Nullable()
        @java.lang.Override()
        public V remove(java.lang.Object key) {
            return null;
        }
        
        public OrderedMap(@org.jetbrains.annotations.NotNull()
        java.util.Map<K, V> map) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.util.Set<java.util.Map.Entry<K, V>> getEntries() {
            return null;
        }
        
        @java.lang.Override()
        public final java.util.Set<java.util.Map.Entry<K, V>> entrySet() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.util.Set<K> getKeys() {
            return null;
        }
        
        @java.lang.Override()
        public final java.util.Set<K> keySet() {
            return null;
        }
        
        @java.lang.Override()
        public int getSize() {
            return 0;
        }
        
        @java.lang.Override()
        public final int size() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.util.Collection<V> getValues() {
            return null;
        }
        
        @java.lang.Override()
        public final java.util.Collection<V> values() {
            return null;
        }
        
        @java.lang.Override()
        public boolean containsKey(java.lang.Object key) {
            return false;
        }
        
        @java.lang.Override()
        public boolean containsValue(java.lang.Object value) {
            return false;
        }
        
        @org.jetbrains.annotations.Nullable()
        @java.lang.Override()
        public V get(java.lang.Object key) {
            return null;
        }
        
        @java.lang.Override()
        public boolean isEmpty() {
            return false;
        }
        
        @java.lang.Override()
        public void putAll(@org.jetbrains.annotations.NotNull()
        java.util.Map<? extends K, ? extends V> from) {
        }
    }
}