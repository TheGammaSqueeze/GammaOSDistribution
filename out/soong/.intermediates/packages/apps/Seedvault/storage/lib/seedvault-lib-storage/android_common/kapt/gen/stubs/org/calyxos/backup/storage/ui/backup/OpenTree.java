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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u001a\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\b\u0010\u0007\u001a\u0004\u0018\u00010\bH\u0016"}, d2 = {"Lorg/calyxos/backup/storage/ui/backup/OpenTree;", "Landroidx/activity/result/contract/ActivityResultContracts$OpenDocumentTree;", "()V", "createIntent", "Landroid/content/Intent;", "context", "Landroid/content/Context;", "input", "Landroid/net/Uri;"})
public final class OpenTree extends androidx.activity.result.contract.ActivityResultContracts.OpenDocumentTree {
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.content.Intent createIntent(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.net.Uri input) {
        return null;
    }
    
    public OpenTree() {
        super();
    }
}