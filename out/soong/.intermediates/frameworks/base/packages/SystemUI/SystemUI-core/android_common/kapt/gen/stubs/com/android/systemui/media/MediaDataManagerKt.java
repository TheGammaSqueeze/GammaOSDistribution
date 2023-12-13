package com.android.systemui.media;

import android.app.Notification;
import android.app.PendingIntent;
import android.app.smartspace.SmartspaceConfig;
import android.app.smartspace.SmartspaceManager;
import android.app.smartspace.SmartspaceSession;
import android.app.smartspace.SmartspaceTarget;
import android.content.BroadcastReceiver;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.ImageDecoder;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.Icon;
import android.media.MediaDescription;
import android.media.MediaMetadata;
import android.media.session.MediaController;
import android.media.session.MediaSession;
import android.net.Uri;
import android.os.Parcelable;
import android.os.UserHandle;
import android.provider.Settings;
import android.service.notification.StatusBarNotification;
import android.text.TextUtils;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.R;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.BcSmartspaceDataPlugin;
import com.android.systemui.statusbar.notification.row.HybridGroupManager;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.util.Assert;
import com.android.systemui.util.Utils;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.time.SystemClock;
import java.io.FileDescriptor;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000(\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\u001a\u000e\u0010\u0010\u001a\u00020\u00052\u0006\u0010\u0011\u001a\u00020\u0012\"\u0016\u0010\u0000\u001a\b\u0012\u0004\u0012\u00020\u00020\u0001X\u0082\u0004\u00a2\u0006\u0004\n\u0002\u0010\u0003\"\u000e\u0010\u0004\u001a\u00020\u0005X\u0082T\u00a2\u0006\u0002\n\u0000\"\u001c\u0010\u0006\u001a\u00020\u00078\u0000X\u0081\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\b\u0010\t\u001a\u0004\b\n\u0010\u000b\"\u000e\u0010\f\u001a\u00020\u0002X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u000f\u001a\u00020\u0002X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"ART_URIS", "", "", "[Ljava/lang/String;", "DEBUG", "", "EMPTY_SMARTSPACE_MEDIA_DATA", "Lcom/android/systemui/media/SmartspaceMediaData;", "getEMPTY_SMARTSPACE_MEDIA_DATA$annotations", "()V", "getEMPTY_SMARTSPACE_MEDIA_DATA", "()Lcom/android/systemui/media/SmartspaceMediaData;", "EXTRAS_SMARTSPACE_DISMISS_INTENT_KEY", "LOADING", "Lcom/android/systemui/media/MediaData;", "TAG", "isMediaNotification", "sbn", "Landroid/service/notification/StatusBarNotification;"})
public final class MediaDataManagerKt {
    private static final java.lang.String[] ART_URIS = {"android.media.metadata.ALBUM_ART_URI", "android.media.metadata.ART_URI", "android.media.metadata.DISPLAY_ICON_URI"};
    private static final java.lang.String TAG = "MediaDataManager";
    private static final boolean DEBUG = true;
    private static final java.lang.String EXTRAS_SMARTSPACE_DISMISS_INTENT_KEY = "dismiss_intent";
    private static final com.android.systemui.media.MediaData LOADING = null;
    @org.jetbrains.annotations.NotNull()
    private static final com.android.systemui.media.SmartspaceMediaData EMPTY_SMARTSPACE_MEDIA_DATA = null;
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getEMPTY_SMARTSPACE_MEDIA_DATA$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.SmartspaceMediaData getEMPTY_SMARTSPACE_MEDIA_DATA() {
        return null;
    }
    
    public static final boolean isMediaNotification(@org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn) {
        return false;
    }
}