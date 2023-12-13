package org.calyxos.backup.storage.scanner;

import android.net.Uri;
import android.provider.DocumentsContract;
import android.provider.MediaStore;
import android.util.Log;
import org.calyxos.backup.storage.content.ContentFile;
import org.calyxos.backup.storage.content.DocFile;
import org.calyxos.backup.storage.content.MediaFile;
import org.calyxos.backup.storage.db.UriStore;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0000\u0018\u0000 \u00142\u00020\u0001:\u0001\u0014B\'\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0002\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0016\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\r0\f2\u0006\u0010\u000e\u001a\u00020\u000fH\u0002J\u0006\u0010\u0010\u001a\u00020\u0011J\u0016\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00130\f2\u0006\u0010\u000e\u001a\u00020\u000fH\u0002R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/scanner/FileScanner;", "", "uriStore", "Lorg/calyxos/backup/storage/db/UriStore;", "mediaScanner", "Lorg/calyxos/backup/storage/scanner/MediaScanner;", "documentScanner", "Lorg/calyxos/backup/storage/scanner/DocumentScanner;", "smallFileSizeMax", "", "(Lorg/calyxos/backup/storage/db/UriStore;Lorg/calyxos/backup/storage/scanner/MediaScanner;Lorg/calyxos/backup/storage/scanner/DocumentScanner;I)V", "getDocumentFiles", "", "Lorg/calyxos/backup/storage/content/DocFile;", "uri", "Landroid/net/Uri;", "getFiles", "Lorg/calyxos/backup/storage/scanner/FileScannerResult;", "getMediaFiles", "Lorg/calyxos/backup/storage/content/MediaFile;", "Companion"})
public final class FileScanner {
    private final org.calyxos.backup.storage.db.UriStore uriStore = null;
    private final org.calyxos.backup.storage.scanner.MediaScanner mediaScanner = null;
    private final org.calyxos.backup.storage.scanner.DocumentScanner documentScanner = null;
    private final int smallFileSizeMax = 0;
    private static final java.lang.String TAG = "FileScanner";
    private static final java.lang.String FILES_SMALL = "small";
    private static final java.lang.String FILES_LARGE = "large";
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.scanner.FileScanner.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.scanner.FileScannerResult getFiles() {
        return null;
    }
    
    private final java.util.List<org.calyxos.backup.storage.content.MediaFile> getMediaFiles(android.net.Uri uri) {
        return null;
    }
    
    private final java.util.List<org.calyxos.backup.storage.content.DocFile> getDocumentFiles(android.net.Uri uri) {
        return null;
    }
    
    public FileScanner(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.UriStore uriStore, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.scanner.MediaScanner mediaScanner, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.scanner.DocumentScanner documentScanner, int smallFileSizeMax) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/scanner/FileScanner$Companion;", "", "()V", "FILES_LARGE", "", "FILES_SMALL", "TAG"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}