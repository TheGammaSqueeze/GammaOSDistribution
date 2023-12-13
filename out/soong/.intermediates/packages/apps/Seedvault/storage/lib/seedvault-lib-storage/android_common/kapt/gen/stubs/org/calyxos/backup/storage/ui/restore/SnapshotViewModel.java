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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\bf\u0018\u00002\u00020\u0001R\u0018\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0005\u0010\u0006"}, d2 = {"Lorg/calyxos/backup/storage/ui/restore/SnapshotViewModel;", "", "snapshots", "Landroidx/lifecycle/LiveData;", "Lorg/calyxos/backup/storage/api/SnapshotResult;", "getSnapshots", "()Landroidx/lifecycle/LiveData;"})
public abstract interface SnapshotViewModel {
    
    @org.jetbrains.annotations.NotNull()
    public abstract androidx.lifecycle.LiveData<org.calyxos.backup.storage.api.SnapshotResult> getSnapshots();
}