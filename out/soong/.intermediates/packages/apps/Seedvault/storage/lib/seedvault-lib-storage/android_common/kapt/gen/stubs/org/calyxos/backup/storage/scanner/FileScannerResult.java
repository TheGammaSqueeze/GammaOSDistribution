package org.calyxos.backup.storage.scanner;

import android.net.Uri;
import android.provider.DocumentsContract;
import android.provider.MediaStore;
import android.util.Log;
import org.calyxos.backup.storage.content.ContentFile;
import org.calyxos.backup.storage.content.DocFile;
import org.calyxos.backup.storage.content.MediaFile;
import org.calyxos.backup.storage.db.UriStore;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0005\b\u0000\u0018\u00002\u00020\u0001B!\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\u0002\u0010\u0006R\u0017\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\b"}, d2 = {"Lorg/calyxos/backup/storage/scanner/FileScannerResult;", "", "smallFiles", "", "Lorg/calyxos/backup/storage/content/ContentFile;", "files", "(Ljava/util/List;Ljava/util/List;)V", "getFiles", "()Ljava/util/List;", "getSmallFiles"})
public final class FileScannerResult {
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<org.calyxos.backup.storage.content.ContentFile> smallFiles = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<org.calyxos.backup.storage.content.ContentFile> files = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<org.calyxos.backup.storage.content.ContentFile> getSmallFiles() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<org.calyxos.backup.storage.content.ContentFile> getFiles() {
        return null;
    }
    
    public FileScannerResult(@org.jetbrains.annotations.NotNull()
    java.util.List<? extends org.calyxos.backup.storage.content.ContentFile> smallFiles, @org.jetbrains.annotations.NotNull()
    java.util.List<? extends org.calyxos.backup.storage.content.ContentFile> files) {
        super();
    }
}