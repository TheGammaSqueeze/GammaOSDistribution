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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\b\u0002\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0003J\u0018\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u00022\u0006\u0010\u0007\u001a\u00020\u0002H\u0016J\u0018\u0010\b\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u00022\u0006\u0010\u0007\u001a\u00020\u0002H\u0016"}, d2 = {"Lorg/calyxos/backup/storage/ui/restore/SnapshotItemCallback;", "Landroidx/recyclerview/widget/DiffUtil$ItemCallback;", "Lorg/calyxos/backup/storage/api/SnapshotItem;", "()V", "areContentsTheSame", "", "oldItem", "newItem", "areItemsTheSame"})
final class SnapshotItemCallback extends androidx.recyclerview.widget.DiffUtil.ItemCallback<org.calyxos.backup.storage.api.SnapshotItem> {
    
    @java.lang.Override()
    public boolean areItemsTheSame(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.SnapshotItem oldItem, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.SnapshotItem newItem) {
        return false;
    }
    
    @java.lang.Override()
    public boolean areContentsTheSame(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.SnapshotItem oldItem, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.SnapshotItem newItem) {
        return false;
    }
    
    public SnapshotItemCallback() {
        super();
    }
}