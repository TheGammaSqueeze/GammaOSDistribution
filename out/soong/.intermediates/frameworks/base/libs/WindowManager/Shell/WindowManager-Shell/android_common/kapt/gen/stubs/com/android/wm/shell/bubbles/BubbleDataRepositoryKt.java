package com.android.wm.shell.bubbles;

import android.annotation.SuppressLint;
import android.annotation.UserIdInt;
import android.content.Context;
import android.content.pm.LauncherApps;
import android.os.UserHandle;
import android.util.Log;
import com.android.wm.shell.bubbles.storage.BubbleEntity;
import com.android.wm.shell.bubbles.storage.BubblePersistentRepository;
import com.android.wm.shell.bubbles.storage.BubbleVolatileRepository;
import com.android.wm.shell.common.ShellExecutor;
import kotlinx.coroutines.Dispatchers;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0012\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0005X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DEBUG", "", "SHORTCUT_QUERY_FLAG", "", "TAG", ""})
public final class BubbleDataRepositoryKt {
    private static final java.lang.String TAG = "BubbleDataRepository";
    private static final boolean DEBUG = false;
    private static final int SHORTCUT_QUERY_FLAG = 1041;
}