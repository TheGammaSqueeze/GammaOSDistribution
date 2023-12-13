package org.calyxos.backup.storage.api;

import android.net.Uri;
import android.provider.MediaStore;
import androidx.annotation.DrawableRes;
import androidx.annotation.StringRes;
import org.calyxos.backup.storage.R;
import org.calyxos.backup.storage.backup.BackupMediaFile;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b6\u0018\u00002\u00020\u0001:\u0001\u0007B\u0011\b\u0002\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006\u0082\u0001\u0002\b\t"}, d2 = {"Lorg/calyxos/backup/storage/api/BackupContentType;", "", "drawableRes", "", "(I)V", "getDrawableRes", "()I", "Custom", "Lorg/calyxos/backup/storage/api/MediaType;", "Lorg/calyxos/backup/storage/api/BackupContentType$Custom;"})
public abstract class BackupContentType {
    private final int drawableRes = 0;
    
    public final int getDrawableRes() {
        return 0;
    }
    
    private BackupContentType(@androidx.annotation.DrawableRes()
    int drawableRes) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006"}, d2 = {"Lorg/calyxos/backup/storage/api/BackupContentType$Custom;", "Lorg/calyxos/backup/storage/api/BackupContentType;", "()V", "getName", "", "uri", "Landroid/net/Uri;"})
    public static final class Custom extends org.calyxos.backup.storage.api.BackupContentType {
        @org.jetbrains.annotations.NotNull()
        public static final org.calyxos.backup.storage.api.BackupContentType.Custom INSTANCE = null;
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getName(@org.jetbrains.annotations.NotNull()
        android.net.Uri uri) {
            return null;
        }
        
        private Custom() {
            super(0);
        }
    }
}