package org.calyxos.backup.storage.ui.restore;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ProgressBar;
import android.widget.TextView;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.LiveData;
import androidx.recyclerview.widget.RecyclerView;
import org.calyxos.backup.storage.R;
import org.calyxos.backup.storage.api.SnapshotItem;
import org.calyxos.backup.storage.api.SnapshotResult;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\b`\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lorg/calyxos/backup/storage/ui/restore/SnapshotClickListener;", "", "onSnapshotClicked", "", "item", "Lorg/calyxos/backup/storage/api/SnapshotItem;"})
public abstract interface SnapshotClickListener {
    
    public abstract void onSnapshotClicked(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.SnapshotItem item);
}