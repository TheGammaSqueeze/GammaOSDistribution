package org.calyxos.backup.storage.plugin.saf;

import android.annotation.SuppressLint;
import android.content.Context;
import android.provider.Settings;
import android.util.Log;
import androidx.documentfile.provider.DocumentFile;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0018\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0007\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\b\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\t\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"CHUNK_FOLDER_COUNT", "", "MIME_TYPE", "", "TAG", "chunkFolderRegex", "Lkotlin/text/Regex;", "chunkRegex", "folderRegex", "snapshotRegex"})
public final class SafStoragePluginKt {
    private static final kotlin.text.Regex folderRegex = null;
    private static final kotlin.text.Regex chunkFolderRegex = null;
    private static final kotlin.text.Regex chunkRegex = null;
    private static final kotlin.text.Regex snapshotRegex = null;
    private static final java.lang.String MIME_TYPE = "application/octet-stream";
    public static final int CHUNK_FOLDER_COUNT = 256;
    private static final java.lang.String TAG = "SafStoragePlugin";
}