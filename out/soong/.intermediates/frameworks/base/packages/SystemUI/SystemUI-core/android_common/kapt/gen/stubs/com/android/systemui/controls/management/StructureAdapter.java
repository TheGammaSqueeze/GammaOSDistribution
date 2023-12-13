package com.android.systemui.controls.management;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001:\u0001\u0012B\u001b\u0012\f\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\b\u0010\t\u001a\u00020\u0007H\u0016J\u0018\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u00022\u0006\u0010\r\u001a\u00020\u0007H\u0016J\u0018\u0010\u000e\u001a\u00020\u00022\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0007H\u0016R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/StructureAdapter;", "Landroidx/recyclerview/widget/RecyclerView$Adapter;", "Lcom/android/systemui/controls/management/StructureAdapter$StructureHolder;", "models", "", "Lcom/android/systemui/controls/management/StructureContainer;", "currentUserId", "", "(Ljava/util/List;I)V", "getItemCount", "onBindViewHolder", "", "holder", "index", "onCreateViewHolder", "parent", "Landroid/view/ViewGroup;", "p1", "StructureHolder"})
public final class StructureAdapter extends androidx.recyclerview.widget.RecyclerView.Adapter<com.android.systemui.controls.management.StructureAdapter.StructureHolder> {
    private final java.util.List<com.android.systemui.controls.management.StructureContainer> models = null;
    private final int currentUserId = 0;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.controls.management.StructureAdapter.StructureHolder onCreateViewHolder(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent, int p1) {
        return null;
    }
    
    @java.lang.Override()
    public int getItemCount() {
        return 0;
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.StructureAdapter.StructureHolder holder, int index) {
    }
    
    public StructureAdapter(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.controls.management.StructureContainer> models, int currentUserId) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u000e\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eJ\b\u0010\u000f\u001a\u00020\fH\u0002R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/StructureAdapter$StructureHolder;", "Landroidx/recyclerview/widget/RecyclerView$ViewHolder;", "view", "Landroid/view/View;", "currentUserId", "", "(Landroid/view/View;I)V", "controlAdapter", "Lcom/android/systemui/controls/management/ControlAdapter;", "recyclerView", "Landroidx/recyclerview/widget/RecyclerView;", "bind", "", "model", "Lcom/android/systemui/controls/management/ControlsModel;", "setUpRecyclerView"})
    public static final class StructureHolder extends androidx.recyclerview.widget.RecyclerView.ViewHolder {
        private final androidx.recyclerview.widget.RecyclerView recyclerView = null;
        private final com.android.systemui.controls.management.ControlAdapter controlAdapter = null;
        
        public final void bind(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.management.ControlsModel model) {
        }
        
        private final void setUpRecyclerView() {
        }
        
        public StructureHolder(@org.jetbrains.annotations.NotNull()
        android.view.View view, int currentUserId) {
            super(null);
        }
    }
}