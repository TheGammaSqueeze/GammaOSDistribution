package org.calyxos.backup.storage.ui.backup;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.provider.DocumentsContract;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;
import androidx.activity.result.contract.ActivityResultContracts.OpenDocumentTree;
import androidx.appcompat.widget.PopupMenu;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.RecyclerView;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import org.calyxos.backup.storage.R;
import org.calyxos.backup.storage.api.BackupContentType;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\b&\u0018\u00002\u00020\u00012\u00020\u0002B\u0005\u00a2\u0006\u0002\u0010\u0003J\u0018\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J$\u0010\u0012\u001a\u00020\u000f2\u0006\u0010\u0013\u001a\u00020\u00142\b\u0010\u0015\u001a\u0004\u0018\u00010\u00162\b\u0010\u0017\u001a\u0004\u0018\u00010\u0018H\u0016J\u0018\u0010\u0019\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J\u0018\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u001c\u001a\u00020\u001bH\u0016J\u0012\u0010\u001d\u001a\u00020\r2\b\u0010\u001e\u001a\u0004\u0018\u00010\u0006H\u0002R\u001c\u0010\u0004\u001a\u0010\u0012\f\u0012\n \u0007*\u0004\u0018\u00010\u00060\u00060\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\b\u001a\u00020\tX\u00a4\u0004\u00a2\u0006\u0006\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lorg/calyxos/backup/storage/ui/backup/BackupContentFragment;", "Landroidx/fragment/app/Fragment;", "Lorg/calyxos/backup/storage/ui/backup/ContentClickListener;", "()V", "addRequest", "Landroidx/activity/result/ActivityResultLauncher;", "Landroid/net/Uri;", "kotlin.jvm.PlatformType", "viewModel", "Lorg/calyxos/backup/storage/ui/backup/BackupContentViewModel;", "getViewModel", "()Lorg/calyxos/backup/storage/ui/backup/BackupContentViewModel;", "onContentClicked", "", "view", "Landroid/view/View;", "item", "Lorg/calyxos/backup/storage/ui/backup/BackupContentItem;", "onCreateView", "inflater", "Landroid/view/LayoutInflater;", "container", "Landroid/view/ViewGroup;", "savedInstanceState", "Landroid/os/Bundle;", "onFolderOverflowClicked", "onMediaContentEnabled", "", "enabled", "onTreeUriReceived", "uri"})
public abstract class BackupContentFragment extends androidx.fragment.app.Fragment implements org.calyxos.backup.storage.ui.backup.ContentClickListener {
    private final androidx.activity.result.ActivityResultLauncher<android.net.Uri> addRequest = null;
    
    @org.jetbrains.annotations.NotNull()
    protected abstract org.calyxos.backup.storage.ui.backup.BackupContentViewModel getViewModel();
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View onCreateView(@org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater inflater, @org.jetbrains.annotations.Nullable()
    android.view.ViewGroup container, @org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
        return null;
    }
    
    @java.lang.Override()
    public void onContentClicked(@org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.backup.BackupContentItem item) {
    }
    
    @java.lang.Override()
    public boolean onMediaContentEnabled(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.backup.BackupContentItem item, boolean enabled) {
        return false;
    }
    
    @java.lang.Override()
    public void onFolderOverflowClicked(@org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.backup.BackupContentItem item) {
    }
    
    private final void onTreeUriReceived(android.net.Uri uri) {
    }
    
    public BackupContentFragment() {
        super();
    }
}