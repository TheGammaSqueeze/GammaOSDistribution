package org.calyxos.backup.storage.scanner;

import android.content.ContentUris;
import android.content.Context;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.util.Log;
import androidx.annotation.RequiresApi;
import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.api.MediaType;
import org.calyxos.backup.storage.content.MediaFile;
import java.io.File;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u0000 \u001c2\u00020\u0001:\u0001\u001cB\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0018\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rH\u0002J\u0017\u0010\u000e\u001a\u0004\u0018\u00010\u000f2\u0006\u0010\u0010\u001a\u00020\rH\u0000\u00a2\u0006\u0002\b\u0011J\u0010\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\tH\u0002J\'\u0010\u0015\u001a\b\u0012\u0004\u0012\u00020\t0\u00162\u0006\u0010\u0010\u001a\u00020\r2\n\b\u0002\u0010\u0017\u001a\u0004\u0018\u00010\u000fH\u0000\u00a2\u0006\u0002\b\u0018J\u001e\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u001a0\u00162\u0006\u0010\u0010\u001a\u00020\r2\b\b\u0002\u0010\u001b\u001a\u00020\u0013R\u0016\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/scanner/MediaScanner;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "contentResolver", "Landroid/content/ContentResolver;", "kotlin.jvm.PlatformType", "createMediaFile", "Lorg/calyxos/backup/storage/content/MediaFile;", "cursor", "Landroid/database/Cursor;", "queryUri", "Landroid/net/Uri;", "getPath", "", "uri", "getPath$main", "getRealSize", "", "mediaFile", "scanMediaUri", "", "extraQuery", "scanMediaUri$main", "scanUri", "Lorg/calyxos/backup/storage/api/BackupFile;", "maxSize", "Companion"})
public final class MediaScanner {
    private final android.content.ContentResolver contentResolver = null;
    @java.lang.Deprecated()
    private static final java.lang.String[] PROJECTION_29 = {"_id", "relative_path", "_display_name", "date_modified", "_size", "owner_package_name", "volume_name"};
    @androidx.annotation.RequiresApi(value = 30)
    @java.lang.Deprecated()
    private static final java.lang.String[] PROJECTION_30 = {"is_favorite", "generation_modified"};
    @java.lang.Deprecated()
    private static final int PROJECTION_ID = 0;
    @java.lang.Deprecated()
    private static final int PROJECTION_PATH = 1;
    @java.lang.Deprecated()
    private static final int PROJECTION_NAME = 2;
    @java.lang.Deprecated()
    private static final int PROJECTION_DATE_MODIFIED = 3;
    @java.lang.Deprecated()
    private static final int PROJECTION_SIZE = 4;
    @java.lang.Deprecated()
    private static final int PROJECTION_OWNER_PACKAGE_NAME = 5;
    @java.lang.Deprecated()
    private static final int PROJECTION_VOLUME_NAME = 6;
    @java.lang.Deprecated()
    private static final int PROJECTION_IS_FAVORITE = 7;
    @java.lang.Deprecated()
    private static final int PROJECTION_GENERATION_MODIFIED = 8;
    @org.jetbrains.annotations.NotNull()
    private static final org.calyxos.backup.storage.scanner.MediaScanner.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<org.calyxos.backup.storage.api.BackupFile> scanUri(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, long maxSize) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<org.calyxos.backup.storage.content.MediaFile> scanMediaUri$main(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, @org.jetbrains.annotations.Nullable()
    java.lang.String extraQuery) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getPath$main(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri) {
        return null;
    }
    
    private final org.calyxos.backup.storage.content.MediaFile createMediaFile(android.database.Cursor cursor, android.net.Uri queryUri) {
        return null;
    }
    
    private final long getRealSize(org.calyxos.backup.storage.content.MediaFile mediaFile) {
        return 0L;
    }
    
    public MediaScanner(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\b\b\u0082\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0016\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u0006R\u0018\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\u00050\u00048\u0002X\u0083\u0004\u00a2\u0006\u0004\n\u0002\u0010\u0006R\u000e\u0010\b\u001a\u00020\tX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\tX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\tX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\tX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\tX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\tX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\tX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\tX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\tX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/scanner/MediaScanner$Companion;", "", "()V", "PROJECTION_29", "", "", "[Ljava/lang/String;", "PROJECTION_30", "PROJECTION_DATE_MODIFIED", "", "PROJECTION_GENERATION_MODIFIED", "PROJECTION_ID", "PROJECTION_IS_FAVORITE", "PROJECTION_NAME", "PROJECTION_OWNER_PACKAGE_NAME", "PROJECTION_PATH", "PROJECTION_SIZE", "PROJECTION_VOLUME_NAME"})
    static final class Companion {
        
        private Companion() {
            super();
        }
    }
}