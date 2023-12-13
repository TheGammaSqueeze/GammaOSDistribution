package org.calyxos.backup.storage.backup;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;
import kotlinx.coroutines.GlobalScope;
import org.calyxos.backup.storage.R;
import org.calyxos.backup.storage.api.BackupObserver;
import org.calyxos.backup.storage.api.StorageBackup;
import org.calyxos.backup.storage.ui.Notifications;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0006\n\u0000\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"TAG", ""})
public final class BackupServiceKt {
    private static final java.lang.String TAG = "BackupService";
}