package org.calyxos.backup.storage.scanner;

import android.content.Context;
import android.net.Uri;
import android.provider.DocumentsContract;
import android.provider.MediaStore;
import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.content.DocFile;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\u0018\u0000 \u00142\u00020\u0001:\u0001\u0014B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J/\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\t2\u0006\u0010\u000b\u001a\u00020\f2\b\b\u0002\u0010\r\u001a\u00020\u000e2\b\b\u0002\u0010\u000f\u001a\u00020\u0010H\u0000\u00a2\u0006\u0002\b\u0011J\u001e\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00130\t2\u0006\u0010\u000b\u001a\u00020\f2\b\b\u0002\u0010\u000f\u001a\u00020\u0010R\u0016\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/scanner/DocumentScanner;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "contentResolver", "Landroid/content/ContentResolver;", "kotlin.jvm.PlatformType", "scanDocumentUri", "", "Lorg/calyxos/backup/storage/content/DocFile;", "uri", "Landroid/net/Uri;", "dir", "", "maxSize", "", "scanDocumentUri$main", "scanUri", "Lorg/calyxos/backup/storage/api/BackupFile;", "Companion"})
public final class DocumentScanner {
    private final android.content.ContentResolver contentResolver = null;
    @java.lang.Deprecated()
    private static final java.lang.String[] PROJECTION = {"document_id", "_display_name", "mime_type", "last_modified", "_size", "flags"};
    @java.lang.Deprecated()
    private static final int PROJECTION_ID = 0;
    @java.lang.Deprecated()
    private static final int PROJECTION_NAME = 1;
    @java.lang.Deprecated()
    private static final int PROJECTION_MIME_TYPE = 2;
    @java.lang.Deprecated()
    private static final int PROJECTION_LAST_MODIFIED = 3;
    @java.lang.Deprecated()
    private static final int PROJECTION_COLUMN_SIZE = 4;
    @java.lang.Deprecated()
    private static final int PROJECTION_COLUMN_FLAGS = 5;
    @org.jetbrains.annotations.NotNull()
    private static final org.calyxos.backup.storage.scanner.DocumentScanner.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<org.calyxos.backup.storage.api.BackupFile> scanUri(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, long maxSize) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<org.calyxos.backup.storage.content.DocFile> scanDocumentUri$main(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, @org.jetbrains.annotations.NotNull()
    java.lang.String dir, long maxSize) {
        return null;
    }
    
    public DocumentScanner(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0005\b\u0082\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0016\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u0006R\u000e\u0010\u0007\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/scanner/DocumentScanner$Companion;", "", "()V", "PROJECTION", "", "", "[Ljava/lang/String;", "PROJECTION_COLUMN_FLAGS", "", "PROJECTION_COLUMN_SIZE", "PROJECTION_ID", "PROJECTION_LAST_MODIFIED", "PROJECTION_MIME_TYPE", "PROJECTION_NAME"})
    static final class Companion {
        
        private Companion() {
            super();
        }
    }
}