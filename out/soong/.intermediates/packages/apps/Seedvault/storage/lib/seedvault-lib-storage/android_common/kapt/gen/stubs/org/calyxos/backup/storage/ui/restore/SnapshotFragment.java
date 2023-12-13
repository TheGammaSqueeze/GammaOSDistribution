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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b&\u0018\u00002\u00020\u00012\u00020\u0002B\u0005\u00a2\u0006\u0002\u0010\u0003J$\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000b2\b\u0010\f\u001a\u0004\u0018\u00010\r2\b\u0010\u000e\u001a\u0004\u0018\u00010\u000fH\u0016R\u0012\u0010\u0004\u001a\u00020\u0005X\u00a4\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0006\u0010\u0007"}, d2 = {"Lorg/calyxos/backup/storage/ui/restore/SnapshotFragment;", "Landroidx/fragment/app/Fragment;", "Lorg/calyxos/backup/storage/ui/restore/SnapshotClickListener;", "()V", "viewModel", "Lorg/calyxos/backup/storage/ui/restore/SnapshotViewModel;", "getViewModel", "()Lorg/calyxos/backup/storage/ui/restore/SnapshotViewModel;", "onCreateView", "Landroid/view/View;", "inflater", "Landroid/view/LayoutInflater;", "container", "Landroid/view/ViewGroup;", "savedInstanceState", "Landroid/os/Bundle;"})
public abstract class SnapshotFragment extends androidx.fragment.app.Fragment implements org.calyxos.backup.storage.ui.restore.SnapshotClickListener {
    
    @org.jetbrains.annotations.NotNull()
    protected abstract org.calyxos.backup.storage.ui.restore.SnapshotViewModel getViewModel();
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View onCreateView(@org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater inflater, @org.jetbrains.annotations.Nullable()
    android.view.ViewGroup container, @org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
        return null;
    }
    
    public SnapshotFragment() {
        super();
    }
}