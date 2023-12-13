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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\b`\u0018\u00002\u00020\u0001J\u0018\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0007H&J\u0018\u0010\b\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0007H&J\u0018\u0010\t\u001a\u00020\n2\u0006\u0010\u0006\u001a\u00020\u00072\u0006\u0010\u000b\u001a\u00020\nH&"}, d2 = {"Lorg/calyxos/backup/storage/ui/backup/ContentClickListener;", "", "onContentClicked", "", "view", "Landroid/view/View;", "item", "Lorg/calyxos/backup/storage/ui/backup/BackupContentItem;", "onFolderOverflowClicked", "onMediaContentEnabled", "", "enabled"})
public abstract interface ContentClickListener {
    
    public abstract void onContentClicked(@org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.backup.BackupContentItem item);
    
    public abstract boolean onMediaContentEnabled(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.backup.BackupContentItem item, boolean enabled);
    
    public abstract void onFolderOverflowClicked(@org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.backup.BackupContentItem item);
}