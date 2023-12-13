package org.calyxos.backup.storage.ui.backup;

import android.app.Application;
import android.net.Uri;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;
import kotlinx.coroutines.Dispatchers;
import org.calyxos.backup.storage.api.BackupContentType;
import org.calyxos.backup.storage.api.SnapshotRetention;
import org.calyxos.backup.storage.api.StorageBackup;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\b&\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0015\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0014H\u0000\u00a2\u0006\u0002\b\u0015J\u0011\u0010\u0016\u001a\u00020\u0012H\u0084@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0017J\u0015\u0010\u0018\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0014H\u0000\u00a2\u0006\u0002\b\u0019R\u001a\u0010\u0005\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\b0\u00070\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\t\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\b0\u00070\nX\u0080\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0012\u0010\r\u001a\u00020\u000eX\u00a4\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000f\u0010\u0010\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/ui/backup/BackupContentViewModel;", "Landroidx/lifecycle/AndroidViewModel;", "app", "Landroid/app/Application;", "(Landroid/app/Application;)V", "_content", "Landroidx/lifecycle/MutableLiveData;", "", "Lorg/calyxos/backup/storage/ui/backup/BackupContentItem;", "content", "Landroidx/lifecycle/LiveData;", "getContent$main", "()Landroidx/lifecycle/LiveData;", "storageBackup", "Lorg/calyxos/backup/storage/api/StorageBackup;", "getStorageBackup", "()Lorg/calyxos/backup/storage/api/StorageBackup;", "addUri", "", "uri", "Landroid/net/Uri;", "addUri$main", "loadContent", "(Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "removeUri", "removeUri$main"})
public abstract class BackupContentViewModel extends androidx.lifecycle.AndroidViewModel {
    private final androidx.lifecycle.MutableLiveData<java.util.List<org.calyxos.backup.storage.ui.backup.BackupContentItem>> _content = null;
    @org.jetbrains.annotations.NotNull()
    private final androidx.lifecycle.LiveData<java.util.List<org.calyxos.backup.storage.ui.backup.BackupContentItem>> content = null;
    
    @org.jetbrains.annotations.NotNull()
    protected abstract org.calyxos.backup.storage.api.StorageBackup getStorageBackup();
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.LiveData<java.util.List<org.calyxos.backup.storage.ui.backup.BackupContentItem>> getContent$main() {
        return null;
    }
    
    public final void addUri$main(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri) {
    }
    
    public final void removeUri$main(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri) {
    }
    
    @org.jetbrains.annotations.Nullable()
    protected final java.lang.Object loadContent(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p0) {
        return null;
    }
    
    public BackupContentViewModel(@org.jetbrains.annotations.NotNull()
    android.app.Application app) {
        super(null);
    }
}