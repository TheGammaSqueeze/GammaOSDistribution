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

/**
 * A class that facilitates management and loading of Media Data, ready for binding.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00a6\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\t\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0011\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0010\b\u0007\u0018\u0000 \u0091\u00012\u00020\u00012\u00020\u0002:\u0004\u0091\u0001\u0092\u0001B\u008b\u0001\b\u0017\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\b\b\u0001\u0010\u0005\u001a\u00020\u0006\u0012\b\b\u0001\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u0012\u0006\u0010\u0017\u001a\u00020\u0018\u0012\u0006\u0010\u0019\u001a\u00020\u001a\u0012\u0006\u0010\u001b\u001a\u00020\u001c\u0012\u0006\u0010\u001d\u001a\u00020\u001e\u0012\u0006\u0010\u001f\u001a\u00020 \u0012\u0006\u0010!\u001a\u00020\"\u00a2\u0006\u0002\u0010#B\u0099\u0001\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\b\b\u0001\u0010\u0005\u001a\u00020\u0006\u0012\b\b\u0001\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u0012\u0006\u0010\u0017\u001a\u00020\u0018\u0012\u0006\u0010\u0019\u001a\u00020\u001a\u0012\u0006\u0010\u001b\u001a\u00020\u001c\u0012\u0006\u0010\u001d\u001a\u00020\u001e\u0012\u0006\u0010$\u001a\u00020%\u0012\u0006\u0010&\u001a\u00020%\u0012\u0006\u0010\'\u001a\u00020 \u0012\u0006\u0010!\u001a\u00020\"\u00a2\u0006\u0002\u0010(J\u0010\u0010?\u001a\u00020%2\u0006\u0010@\u001a\u000200H\u0002J\u000e\u0010A\u001a\u00020B2\u0006\u0010@\u001a\u000200J>\u0010C\u001a\u00020B2\u0006\u0010D\u001a\u00020-2\u0006\u0010E\u001a\u00020F2\u0006\u0010G\u001a\u00020H2\u0006\u0010I\u001a\u00020J2\u0006\u0010K\u001a\u0002032\u0006\u0010L\u001a\u00020M2\u0006\u0010N\u001a\u000203J\u0006\u0010O\u001a\u00020BJ\u0016\u0010P\u001a\u00020%2\u0006\u0010Q\u001a\u0002032\u0006\u0010R\u001a\u00020SJ\u0016\u0010T\u001a\u00020B2\u0006\u0010Q\u001a\u0002032\u0006\u0010R\u001a\u00020SJ-\u0010U\u001a\u00020B2\u0006\u0010V\u001a\u00020W2\u0006\u0010X\u001a\u00020Y2\u000e\u0010Z\u001a\n\u0012\u0006\b\u0001\u0012\u0002030[H\u0016\u00a2\u0006\u0002\u0010\\J\u001a\u0010]\u001a\u0004\u0018\u0001032\u0006\u0010Q\u001a\u0002032\u0006\u0010N\u001a\u000203H\u0002J\u0010\u0010^\u001a\u00020_2\u0006\u0010G\u001a\u00020HH\u0002J\u0006\u0010`\u001a\u00020%J\u0006\u0010a\u001a\u00020%J\u0006\u0010b\u001a\u00020%J\u0006\u0010c\u001a\u00020%J\u0010\u0010d\u001a\u00020%2\u0006\u0010e\u001a\u00020fH\u0002J\u0012\u0010g\u001a\u0004\u0018\u00010h2\u0006\u0010i\u001a\u00020jH\u0002J\u0012\u0010g\u001a\u0004\u0018\u00010h2\u0006\u0010k\u001a\u00020lH\u0002J\"\u0010m\u001a\u00020B2\u0006\u0010Q\u001a\u0002032\u0006\u0010e\u001a\u00020f2\b\u0010n\u001a\u0004\u0018\u000103H\u0002J\"\u0010o\u001a\u00020B2\u0006\u0010Q\u001a\u0002032\u0006\u0010e\u001a\u00020f2\b\u0010n\u001a\u0004\u0018\u000103H\u0002J@\u0010p\u001a\u00020B2\u0006\u0010D\u001a\u00020-2\u0006\u0010E\u001a\u00020F2\u0006\u0010q\u001a\u00020H2\u0006\u0010I\u001a\u00020J2\u0006\u0010K\u001a\u0002032\u0006\u0010L\u001a\u00020M2\u0006\u0010N\u001a\u000203H\u0002J\"\u0010r\u001a\u00020B2\u0006\u0010Q\u001a\u0002032\b\u0010n\u001a\u0004\u0018\u0001032\u0006\u0010s\u001a\u000204H\u0002J\u0010\u0010t\u001a\u00020B2\u0006\u0010Q\u001a\u000203H\u0002J\u0018\u0010u\u001a\u00020B2\u0006\u0010Q\u001a\u0002032\u0006\u0010s\u001a\u000207H\u0002J\u0018\u0010v\u001a\u00020B2\u0006\u0010Q\u001a\u0002032\u0006\u0010w\u001a\u00020%H\u0002J \u0010x\u001a\u00020B2\u0006\u0010Q\u001a\u0002032\b\u0010n\u001a\u0004\u0018\u0001032\u0006\u0010y\u001a\u000204J\u0016\u0010z\u001a\u00020B2\u0006\u0010Q\u001a\u0002032\u0006\u0010e\u001a\u00020fJ\u000e\u0010{\u001a\u00020B2\u0006\u0010Q\u001a\u000203J\u0016\u0010|\u001a\u00020B2\f\u0010}\u001a\b\u0012\u0004\u0012\u00020\u007f0~H\u0016J\u0007\u0010\u0080\u0001\u001a\u00020BJ\u0014\u0010N\u001a\u0004\u0018\u0001032\b\u0010\u0081\u0001\u001a\u00030\u0082\u0001H\u0002J\u0011\u0010\u0083\u0001\u001a\u00020B2\u0006\u0010N\u001a\u000203H\u0002J\u0011\u0010\u0084\u0001\u001a\u00020B2\u0006\u0010Q\u001a\u000203H\u0002J\u000f\u0010\u0085\u0001\u001a\u00020B2\u0006\u0010@\u001a\u000200J\u0012\u0010\u0086\u0001\u001a\u00020%2\u0007\u0010\u0087\u0001\u001a\u00020MH\u0002J\u0010\u0010\u0088\u0001\u001a\u00020B2\u0007\u0010\u0089\u0001\u001a\u00020%J\u0019\u0010\u008a\u0001\u001a\u00020B2\u0006\u0010Q\u001a\u0002032\b\u0010G\u001a\u0004\u0018\u00010HJ+\u0010\u008b\u0001\u001a\u00020B2\u0006\u0010Q\u001a\u0002032\u0007\u0010\u008c\u0001\u001a\u00020%2\t\b\u0002\u0010\u008d\u0001\u001a\u00020%H\u0000\u00a2\u0006\u0003\b\u008e\u0001J\u001c\u0010\u008f\u0001\u001a\u0002072\b\u0010\u0081\u0001\u001a\u00030\u0082\u00012\u0007\u0010\u0090\u0001\u001a\u00020%H\u0002R\u000e\u0010\u001b\u001a\u00020\u001cX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010)\u001a\u00020%X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010*\u001a\u00020+X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010,\u001a\u00020-X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010.\u001a\b\u0012\u0004\u0012\u0002000/X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R*\u00101\u001a\u001e\u0012\u0004\u0012\u000203\u0012\u0004\u0012\u00020402j\u000e\u0012\u0004\u0012\u000203\u0012\u0004\u0012\u000204`5X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u00106\u001a\u000207X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b8\u00109\"\u0004\b:\u0010;R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010<\u001a\u0004\u0018\u00010=X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020 X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010>\u001a\u00020-X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010!\u001a\u00020\"X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010$\u001a\u00020%X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010&\u001a\u00020%X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaDataManager;", "Lcom/android/systemui/Dumpable;", "Lcom/android/systemui/plugins/BcSmartspaceDataPlugin$SmartspaceTargetListener;", "context", "Landroid/content/Context;", "backgroundExecutor", "Ljava/util/concurrent/Executor;", "foregroundExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "mediaControllerFactory", "Lcom/android/systemui/media/MediaControllerFactory;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "mediaTimeoutListener", "Lcom/android/systemui/media/MediaTimeoutListener;", "mediaResumeListener", "Lcom/android/systemui/media/MediaResumeListener;", "mediaSessionBasedFilter", "Lcom/android/systemui/media/MediaSessionBasedFilter;", "mediaDeviceManager", "Lcom/android/systemui/media/MediaDeviceManager;", "mediaDataCombineLatest", "Lcom/android/systemui/media/MediaDataCombineLatest;", "mediaDataFilter", "Lcom/android/systemui/media/MediaDataFilter;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "smartspaceMediaDataProvider", "Lcom/android/systemui/media/SmartspaceMediaDataProvider;", "clock", "Lcom/android/systemui/util/time/SystemClock;", "tunerService", "Lcom/android/systemui/tuner/TunerService;", "(Landroid/content/Context;Ljava/util/concurrent/Executor;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/media/MediaControllerFactory;Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/broadcast/BroadcastDispatcher;Lcom/android/systemui/media/MediaTimeoutListener;Lcom/android/systemui/media/MediaResumeListener;Lcom/android/systemui/media/MediaSessionBasedFilter;Lcom/android/systemui/media/MediaDeviceManager;Lcom/android/systemui/media/MediaDataCombineLatest;Lcom/android/systemui/media/MediaDataFilter;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/media/SmartspaceMediaDataProvider;Lcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/tuner/TunerService;)V", "useMediaResumption", "", "useQsMediaPlayer", "systemClock", "(Landroid/content/Context;Ljava/util/concurrent/Executor;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/media/MediaControllerFactory;Lcom/android/systemui/broadcast/BroadcastDispatcher;Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/media/MediaTimeoutListener;Lcom/android/systemui/media/MediaResumeListener;Lcom/android/systemui/media/MediaSessionBasedFilter;Lcom/android/systemui/media/MediaDeviceManager;Lcom/android/systemui/media/MediaDataCombineLatest;Lcom/android/systemui/media/MediaDataFilter;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/media/SmartspaceMediaDataProvider;ZZLcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/tuner/TunerService;)V", "allowMediaRecommendations", "appChangeReceiver", "Landroid/content/BroadcastReceiver;", "bgColor", "", "internalListeners", "", "Lcom/android/systemui/media/MediaDataManager$Listener;", "mediaEntries", "Ljava/util/LinkedHashMap;", "", "Lcom/android/systemui/media/MediaData;", "Lkotlin/collections/LinkedHashMap;", "smartspaceMediaData", "Lcom/android/systemui/media/SmartspaceMediaData;", "getSmartspaceMediaData", "()Lcom/android/systemui/media/SmartspaceMediaData;", "setSmartspaceMediaData", "(Lcom/android/systemui/media/SmartspaceMediaData;)V", "smartspaceSession", "Landroid/app/smartspace/SmartspaceSession;", "themeText", "addInternalListener", "listener", "addListener", "", "addResumptionControls", "userId", "desc", "Landroid/media/MediaDescription;", "action", "Ljava/lang/Runnable;", "token", "Landroid/media/session/MediaSession$Token;", "appName", "appIntent", "Landroid/app/PendingIntent;", "packageName", "destroy", "dismissMediaData", "key", "delay", "", "dismissSmartspaceRecommendation", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "findExistingEntry", "getResumeMediaAction", "Lcom/android/systemui/media/MediaAction;", "hasActiveMedia", "hasActiveMediaOrRecommendation", "hasAnyMedia", "hasAnyMediaOrRecommendation", "isRemoteCastNotification", "sbn", "Landroid/service/notification/StatusBarNotification;", "loadBitmapFromUri", "Landroid/graphics/Bitmap;", "metadata", "Landroid/media/MediaMetadata;", "uri", "Landroid/net/Uri;", "loadMediaData", "oldKey", "loadMediaDataInBg", "loadMediaDataInBgForResumption", "resumeAction", "notifyMediaDataLoaded", "info", "notifyMediaDataRemoved", "notifySmartspaceMediaDataLoaded", "notifySmartspaceMediaDataRemoved", "immediately", "onMediaDataLoaded", "data", "onNotificationAdded", "onNotificationRemoved", "onSmartspaceTargetsUpdated", "targets", "", "Landroid/os/Parcelable;", "onSwipeToDismiss", "target", "Landroid/app/smartspace/SmartspaceTarget;", "removeAllForPackage", "removeEntry", "removeListener", "sendPendingIntent", "intent", "setMediaResumptionEnabled", "isEnabled", "setResumeAction", "setTimedOut", "timedOut", "forceUpdate", "setTimedOut$main", "toSmartspaceMediaData", "isActive", "Companion", "Listener"})
@com.android.systemui.dagger.SysUISingleton()
public final class MediaDataManager implements com.android.systemui.Dumpable, com.android.systemui.plugins.BcSmartspaceDataPlugin.SmartspaceTargetListener {
    private final int themeText = 0;
    private final int bgColor = 0;
    private final java.util.Set<com.android.systemui.media.MediaDataManager.Listener> internalListeners = null;
    private final java.util.LinkedHashMap<java.lang.String, com.android.systemui.media.MediaData> mediaEntries = null;
    @org.jetbrains.annotations.NotNull()
    private com.android.systemui.media.SmartspaceMediaData smartspaceMediaData;
    private android.app.smartspace.SmartspaceSession smartspaceSession;
    private boolean allowMediaRecommendations;
    private final android.content.BroadcastReceiver appChangeReceiver = null;
    private final android.content.Context context = null;
    private final java.util.concurrent.Executor backgroundExecutor = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor foregroundExecutor = null;
    private final com.android.systemui.media.MediaControllerFactory mediaControllerFactory = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    private final com.android.systemui.media.MediaDataFilter mediaDataFilter = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final com.android.systemui.media.SmartspaceMediaDataProvider smartspaceMediaDataProvider = null;
    private boolean useMediaResumption;
    private final boolean useQsMediaPlayer = false;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    private final com.android.systemui.tuner.TunerService tunerService = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String SMARTSPACE_UI_SURFACE_LABEL = "media_data_manager";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String EXTRAS_MEDIA_SOURCE_PACKAGE_NAME = "package_name";
    public static final int MAX_COMPACT_ACTIONS = 3;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.MediaDataManager.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.media.SmartspaceMediaData getSmartspaceMediaData() {
        return null;
    }
    
    public final void setSmartspaceMediaData(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.SmartspaceMediaData p0) {
    }
    
    /**
     * Check whether this notification is an RCN
     * TODO(b/204910409) implement new API for explicitly declaring this
     */
    private final boolean isRemoteCastNotification(android.service.notification.StatusBarNotification sbn) {
        return false;
    }
    
    public final void destroy() {
    }
    
    public final void onNotificationAdded(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn) {
    }
    
    private final void removeAllForPackage(java.lang.String packageName) {
    }
    
    public final void setResumeAction(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.Nullable()
    java.lang.Runnable action) {
    }
    
    public final void addResumptionControls(int userId, @org.jetbrains.annotations.NotNull()
    android.media.MediaDescription desc, @org.jetbrains.annotations.NotNull()
    java.lang.Runnable action, @org.jetbrains.annotations.NotNull()
    android.media.session.MediaSession.Token token, @org.jetbrains.annotations.NotNull()
    java.lang.String appName, @org.jetbrains.annotations.NotNull()
    android.app.PendingIntent appIntent, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName) {
    }
    
    /**
     * Check if there is an existing entry that matches the key or package name.
     * Returns the key that matches, or null if not found.
     */
    private final java.lang.String findExistingEntry(java.lang.String key, java.lang.String packageName) {
        return null;
    }
    
    private final void loadMediaData(java.lang.String key, android.service.notification.StatusBarNotification sbn, java.lang.String oldKey) {
    }
    
    /**
     * Add a listener for changes in this class
     */
    public final void addListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataManager.Listener listener) {
    }
    
    /**
     * Remove a listener for changes in this class
     */
    public final void removeListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataManager.Listener listener) {
    }
    
    /**
     * Add a listener for internal events.
     */
    private final boolean addInternalListener(com.android.systemui.media.MediaDataManager.Listener listener) {
        return false;
    }
    
    /**
     * Notify internal listeners of media loaded event.
     *
     * External listeners registered with [addListener] will be notified after the event propagates
     * through the internal listener pipeline.
     */
    private final void notifyMediaDataLoaded(java.lang.String key, java.lang.String oldKey, com.android.systemui.media.MediaData info) {
    }
    
    /**
     * Notify internal listeners of Smartspace media loaded event.
     *
     * External listeners registered with [addListener] will be notified after the event propagates
     * through the internal listener pipeline.
     */
    private final void notifySmartspaceMediaDataLoaded(java.lang.String key, com.android.systemui.media.SmartspaceMediaData info) {
    }
    
    /**
     * Notify internal listeners of media removed event.
     *
     * External listeners registered with [addListener] will be notified after the event propagates
     * through the internal listener pipeline.
     */
    private final void notifyMediaDataRemoved(java.lang.String key) {
    }
    
    /**
     * Notify internal listeners of Smartspace media removed event.
     *
     * External listeners registered with [addListener] will be notified after the event propagates
     * through the internal listener pipeline.
     *
     * @param immediately indicates should apply the UI changes immediately, otherwise wait until
     * the next refresh-round before UI becomes visible. Should only be true if the update is
     * initiated by user's interaction.
     */
    private final void notifySmartspaceMediaDataRemoved(java.lang.String key, boolean immediately) {
    }
    
    /**
     * Called whenever the player has been paused or stopped for a while, or swiped from QQS.
     * This will make the player not active anymore, hiding it from QQS and Keyguard.
     * @see MediaData.active
     */
    public final void setTimedOut$main(@org.jetbrains.annotations.NotNull()
    java.lang.String key, boolean timedOut, boolean forceUpdate) {
    }
    
    private final void removeEntry(java.lang.String key) {
    }
    
    /**
     * Dismiss a media entry. Returns false if the key was not found.
     */
    public final boolean dismissMediaData(@org.jetbrains.annotations.NotNull()
    java.lang.String key, long delay) {
        return false;
    }
    
    /**
     * Called whenever the recommendation has been expired, or swiped from QQS.
     * This will make the recommendation view to not be shown anymore during this headphone
     * connection session.
     */
    public final void dismissSmartspaceRecommendation(@org.jetbrains.annotations.NotNull()
    java.lang.String key, long delay) {
    }
    
    private final void loadMediaDataInBgForResumption(int userId, android.media.MediaDescription desc, java.lang.Runnable resumeAction, android.media.session.MediaSession.Token token, java.lang.String appName, android.app.PendingIntent appIntent, java.lang.String packageName) {
    }
    
    private final void loadMediaDataInBg(java.lang.String key, android.service.notification.StatusBarNotification sbn, java.lang.String oldKey) {
    }
    
    /**
     * Load a bitmap from the various Art metadata URIs
     */
    private final android.graphics.Bitmap loadBitmapFromUri(android.media.MediaMetadata metadata) {
        return null;
    }
    
    private final boolean sendPendingIntent(android.app.PendingIntent intent) {
        return false;
    }
    
    /**
     * Load a bitmap from a URI
     * @param uri the uri to load
     * @return bitmap, or null if couldn't be loaded
     */
    private final android.graphics.Bitmap loadBitmapFromUri(android.net.Uri uri) {
        return null;
    }
    
    private final com.android.systemui.media.MediaAction getResumeMediaAction(java.lang.Runnable action) {
        return null;
    }
    
    public final void onMediaDataLoaded(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.Nullable()
    java.lang.String oldKey, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaData data) {
    }
    
    @java.lang.Override()
    public void onSmartspaceTargetsUpdated(@org.jetbrains.annotations.NotNull()
    java.util.List<? extends android.os.Parcelable> targets) {
    }
    
    public final void onNotificationRemoved(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void setMediaResumptionEnabled(boolean isEnabled) {
    }
    
    /**
     * Invoked when the user has dismissed the media carousel
     */
    public final void onSwipeToDismiss() {
    }
    
    /**
     * Are there any media notifications active, including the recommendations?
     */
    public final boolean hasActiveMediaOrRecommendation() {
        return false;
    }
    
    /**
     * Are there any media entries we should display, including the recommendations?
     * If resumption is enabled, this will include inactive players
     * If resumption is disabled, we only want to show active players
     */
    public final boolean hasAnyMediaOrRecommendation() {
        return false;
    }
    
    /**
     * Are there any resume media notifications active, excluding the recommendations?
     */
    public final boolean hasActiveMedia() {
        return false;
    }
    
    /**
     * Are there any resume media notifications active, excluding the recommendations?
     * If resumption is enabled, this will include inactive players
     * If resumption is disabled, we only want to show active players
     */
    public final boolean hasAnyMedia() {
        return false;
    }
    
    /**
     * Converts the pass-in SmartspaceTarget to SmartspaceMediaData with the pass-in active status.
     *
     * @return An empty SmartspaceMediaData with the valid target Id is returned if the
     * SmartspaceTarget's data is invalid.
     */
    private final com.android.systemui.media.SmartspaceMediaData toSmartspaceMediaData(android.app.smartspace.SmartspaceTarget target, boolean isActive) {
        return null;
    }
    
    private final java.lang.String packageName(android.app.smartspace.SmartspaceTarget target) {
        return null;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    public MediaDataManager(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    java.util.concurrent.Executor backgroundExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor foregroundExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaControllerFactory mediaControllerFactory, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaTimeoutListener mediaTimeoutListener, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaResumeListener mediaResumeListener, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaSessionBasedFilter mediaSessionBasedFilter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDeviceManager mediaDeviceManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataCombineLatest mediaDataCombineLatest, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataFilter mediaDataFilter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.SmartspaceMediaDataProvider smartspaceMediaDataProvider, boolean useMediaResumption, boolean useQsMediaPlayer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
    com.android.systemui.tuner.TunerService tunerService) {
        super();
    }
    
    @javax.inject.Inject()
    public MediaDataManager(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    java.util.concurrent.Executor backgroundExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor foregroundExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaControllerFactory mediaControllerFactory, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaTimeoutListener mediaTimeoutListener, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaResumeListener mediaResumeListener, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaSessionBasedFilter mediaSessionBasedFilter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDeviceManager mediaDeviceManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataCombineLatest mediaDataCombineLatest, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataFilter mediaDataFilter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.SmartspaceMediaDataProvider smartspaceMediaDataProvider, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock clock, @org.jetbrains.annotations.NotNull()
    com.android.systemui.tuner.TunerService tunerService) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\bf\u0018\u00002\u00020\u0001J@\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\b\u0010\u0006\u001a\u0004\u0018\u00010\u00052\u0006\u0010\u0007\u001a\u00020\b2\b\b\u0002\u0010\t\u001a\u00020\n2\b\b\u0002\u0010\u000b\u001a\u00020\f2\b\b\u0002\u0010\r\u001a\u00020\nH\u0016J\u0010\u0010\u000e\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\u0016J\"\u0010\u000f\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0007\u001a\u00020\u00102\b\b\u0002\u0010\u0011\u001a\u00020\nH\u0016J\u001a\u0010\u0012\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\t\u001a\u00020\nH\u0016"}, d2 = {"Lcom/android/systemui/media/MediaDataManager$Listener;", "", "onMediaDataLoaded", "", "key", "", "oldKey", "data", "Lcom/android/systemui/media/MediaData;", "immediately", "", "receivedSmartspaceCardLatency", "", "isSsReactivated", "onMediaDataRemoved", "onSmartspaceMediaDataLoaded", "Lcom/android/systemui/media/SmartspaceMediaData;", "shouldPrioritize", "onSmartspaceMediaDataRemoved"})
    public static abstract interface Listener {
        
        /**
         * Called whenever there's new MediaData Loaded for the consumption in views.
         *
         * oldKey is provided to check whether the view has changed keys, which can happen when a
         * player has gone from resume state (key is package name) to active state (key is
         * notification key) or vice versa.
         *
         * @param immediately indicates should apply the UI changes immediately, otherwise wait
         * until the next refresh-round before UI becomes visible. True by default to take in place
         * immediately.
         *
         * @param receivedSmartspaceCardLatency is the latency between headphone connects and sysUI
         * displays Smartspace media targets. Will be 0 if the data is not activated by Smartspace
         * signal.
         *
         * @param isSsReactivated indicates resume media card is reactivated by Smartspace
         * recommendation signal
         */
        public abstract void onMediaDataLoaded(@org.jetbrains.annotations.NotNull()
        java.lang.String key, @org.jetbrains.annotations.Nullable()
        java.lang.String oldKey, @org.jetbrains.annotations.NotNull()
        com.android.systemui.media.MediaData data, boolean immediately, int receivedSmartspaceCardLatency, boolean isSsReactivated);
        
        /**
         * Called whenever there's new Smartspace media data loaded.
         *
         * @param shouldPrioritize indicates the sorting priority of the Smartspace card. If true,
         * it will be prioritized as the first card. Otherwise, it will show up as the last card as
         * default.
         */
        public abstract void onSmartspaceMediaDataLoaded(@org.jetbrains.annotations.NotNull()
        java.lang.String key, @org.jetbrains.annotations.NotNull()
        com.android.systemui.media.SmartspaceMediaData data, boolean shouldPrioritize);
        
        /**
         * Called whenever a previously existing Media notification was removed.
         */
        public abstract void onMediaDataRemoved(@org.jetbrains.annotations.NotNull()
        java.lang.String key);
        
        /**
         * Called whenever a previously existing Smartspace media data was removed.
         *
         * @param immediately indicates should apply the UI changes immediately, otherwise wait
         * until the next refresh-round before UI becomes visible. True by default to take in place
         * immediately.
         */
        public abstract void onSmartspaceMediaDataRemoved(@org.jetbrains.annotations.NotNull()
        java.lang.String key, boolean immediately);
        
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
        public static final class DefaultImpls {
            
            /**
             * Called whenever there's new MediaData Loaded for the consumption in views.
             *
             * oldKey is provided to check whether the view has changed keys, which can happen when a
             * player has gone from resume state (key is package name) to active state (key is
             * notification key) or vice versa.
             *
             * @param immediately indicates should apply the UI changes immediately, otherwise wait
             * until the next refresh-round before UI becomes visible. True by default to take in place
             * immediately.
             *
             * @param receivedSmartspaceCardLatency is the latency between headphone connects and sysUI
             * displays Smartspace media targets. Will be 0 if the data is not activated by Smartspace
             * signal.
             *
             * @param isSsReactivated indicates resume media card is reactivated by Smartspace
             * recommendation signal
             */
            public static void onMediaDataLoaded(@org.jetbrains.annotations.NotNull()
            com.android.systemui.media.MediaDataManager.Listener $this, @org.jetbrains.annotations.NotNull()
            java.lang.String key, @org.jetbrains.annotations.Nullable()
            java.lang.String oldKey, @org.jetbrains.annotations.NotNull()
            com.android.systemui.media.MediaData data, boolean immediately, int receivedSmartspaceCardLatency, boolean isSsReactivated) {
            }
            
            /**
             * Called whenever there's new Smartspace media data loaded.
             *
             * @param shouldPrioritize indicates the sorting priority of the Smartspace card. If true,
             * it will be prioritized as the first card. Otherwise, it will show up as the last card as
             * default.
             */
            public static void onSmartspaceMediaDataLoaded(@org.jetbrains.annotations.NotNull()
            com.android.systemui.media.MediaDataManager.Listener $this, @org.jetbrains.annotations.NotNull()
            java.lang.String key, @org.jetbrains.annotations.NotNull()
            com.android.systemui.media.SmartspaceMediaData data, boolean shouldPrioritize) {
            }
            
            /**
             * Called whenever a previously existing Media notification was removed.
             */
            public static void onMediaDataRemoved(@org.jetbrains.annotations.NotNull()
            com.android.systemui.media.MediaDataManager.Listener $this, @org.jetbrains.annotations.NotNull()
            java.lang.String key) {
            }
            
            /**
             * Called whenever a previously existing Smartspace media data was removed.
             *
             * @param immediately indicates should apply the UI changes immediately, otherwise wait
             * until the next refresh-round before UI becomes visible. True by default to take in place
             * immediately.
             */
            public static void onSmartspaceMediaDataRemoved(@org.jetbrains.annotations.NotNull()
            com.android.systemui.media.MediaDataManager.Listener $this, @org.jetbrains.annotations.NotNull()
            java.lang.String key, boolean immediately) {
            }
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0010\u0010\u0003\u001a\u00020\u00048\u0006X\u0087D\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0005\u001a\u00020\u00068\u0006X\u0087D\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0007\u001a\u00020\u00048\u0006X\u0087D\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaDataManager$Companion;", "", "()V", "EXTRAS_MEDIA_SOURCE_PACKAGE_NAME", "", "MAX_COMPACT_ACTIONS", "", "SMARTSPACE_UI_SURFACE_LABEL"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}