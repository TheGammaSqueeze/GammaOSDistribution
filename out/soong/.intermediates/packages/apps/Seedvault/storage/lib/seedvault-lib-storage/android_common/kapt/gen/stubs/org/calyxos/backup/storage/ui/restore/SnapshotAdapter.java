package org.calyxos.backup.storage.ui.restore;

import android.text.format.Formatter;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import androidx.recyclerview.widget.DiffUtil;
import androidx.recyclerview.widget.ListAdapter;
import androidx.recyclerview.widget.RecyclerView;
import org.calyxos.backup.storage.R;
import org.calyxos.backup.storage.api.SnapshotItem;
import org.calyxos.backup.storage.ui.restore.SnapshotAdapter.SnapshotViewHolder;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0000\u0018\u00002\u0012\u0012\u0004\u0012\u00020\u0002\u0012\b\u0012\u00060\u0003R\u00020\u00000\u0001:\u0001\u0010B\r\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u001c\u0010\u0007\u001a\u00020\b2\n\u0010\t\u001a\u00060\u0003R\u00020\u00002\u0006\u0010\n\u001a\u00020\u000bH\u0016J\u001c\u0010\f\u001a\u00060\u0003R\u00020\u00002\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u000bH\u0016R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/ui/restore/SnapshotAdapter;", "Landroidx/recyclerview/widget/ListAdapter;", "Lorg/calyxos/backup/storage/api/SnapshotItem;", "Lorg/calyxos/backup/storage/ui/restore/SnapshotAdapter$SnapshotViewHolder;", "listener", "Lorg/calyxos/backup/storage/ui/restore/SnapshotClickListener;", "(Lorg/calyxos/backup/storage/ui/restore/SnapshotClickListener;)V", "onBindViewHolder", "", "holder", "position", "", "onCreateViewHolder", "parent", "Landroid/view/ViewGroup;", "viewType", "SnapshotViewHolder"})
public final class SnapshotAdapter extends androidx.recyclerview.widget.ListAdapter<org.calyxos.backup.storage.api.SnapshotItem, org.calyxos.backup.storage.ui.restore.SnapshotAdapter.SnapshotViewHolder> {
    private final org.calyxos.backup.storage.ui.restore.SnapshotClickListener listener = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public org.calyxos.backup.storage.ui.restore.SnapshotAdapter.SnapshotViewHolder onCreateViewHolder(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent, int viewType) {
        return null;
    }
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.restore.SnapshotAdapter.SnapshotViewHolder holder, int position) {
    }
    
    public SnapshotAdapter(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.restore.SnapshotClickListener listener) {
        super(null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\b\u0086\u0004\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eR\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/ui/restore/SnapshotAdapter$SnapshotViewHolder;", "Landroidx/recyclerview/widget/RecyclerView$ViewHolder;", "view", "Landroid/view/View;", "(Lorg/calyxos/backup/storage/ui/restore/SnapshotAdapter;Landroid/view/View;)V", "layout", "Landroid/view/ViewGroup;", "nameView", "Landroid/widget/TextView;", "sizeView", "timeView", "bind", "", "item", "Lorg/calyxos/backup/storage/api/SnapshotItem;"})
    public final class SnapshotViewHolder extends androidx.recyclerview.widget.RecyclerView.ViewHolder {
        private final android.view.ViewGroup layout = null;
        private final android.widget.TextView nameView = null;
        private final android.widget.TextView timeView = null;
        private final android.widget.TextView sizeView = null;
        
        public final void bind(@org.jetbrains.annotations.NotNull()
        org.calyxos.backup.storage.api.SnapshotItem item) {
        }
        
        public SnapshotViewHolder(@org.jetbrains.annotations.NotNull()
        android.view.View view) {
            super(null);
        }
    }
}