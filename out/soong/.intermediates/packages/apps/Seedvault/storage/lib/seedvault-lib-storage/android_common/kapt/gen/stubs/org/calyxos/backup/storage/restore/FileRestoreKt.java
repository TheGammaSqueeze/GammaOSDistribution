package org.calyxos.backup.storage.restore;

import android.content.ContentValues;
import android.content.Context;
import android.media.MediaScannerConnection;
import android.net.Uri;
import android.provider.MediaStore.MediaColumns;
import android.util.Log;
import org.calyxos.backup.storage.api.MediaType;
import org.calyxos.backup.storage.api.RestoreObserver;
import org.calyxos.backup.storage.backup.BackupMediaFile;
import org.calyxos.backup.storage.scanner.MediaScanner;
import java.io.File;
import java.io.IOException;
import java.io.OutputStream;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0006\n\u0000\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"TAG", ""})
public final class FileRestoreKt {
    private static final java.lang.String TAG = "FileRestore";
}