package com.android.systemui.media;

import android.content.Context;
import android.content.Intent;
import android.content.res.ColorStateList;
import android.content.res.Configuration;
import android.util.Log;
import android.util.MathUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import androidx.annotation.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.R;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.qs.PageIndicator;
import com.android.systemui.shared.system.SysUiStatsLog;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.Utils;
import com.android.systemui.util.animation.UniqueObjectHostView;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.time.SystemClock;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.TreeMap;
import javax.inject.Inject;
import javax.inject.Provider;

@androidx.annotation.VisibleForTesting()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000r\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010#\n\u0000\n\u0002\u0010\u001f\n\u0002\b\u0003\b\u00c1\u0002\u0018\u00002\u00020\u0001:\u00012B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J.\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\n2\u0006\u0010\u001a\u001a\u00020\u00042\u0006\u0010\u001b\u001a\u00020\r2\u0006\u0010\u001c\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u000fJ.\u0010\u001f\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\n2\u0006\u0010\u001a\u001a\u00020\u00132\u0006\u0010\u001b\u001a\u00020\r2\u0006\u0010 \u001a\u00020\u000f2\u0006\u0010\u001c\u001a\u00020\u001dJ\b\u0010!\u001a\u00020\u0018H\u0007J\u0006\u0010\"\u001a\u00020#J\u0010\u0010$\u001a\u0004\u0018\u00010\r2\u0006\u0010\u0019\u001a\u00020\nJ\u000e\u0010%\u001a\u00020#2\u0006\u0010\u0019\u001a\u00020\nJ\u0006\u0010&\u001a\u00020\u000fJ\u000e\u0010\u001e\u001a\u00020\u000f2\u0006\u0010\u0019\u001a\u00020\nJ\u001e\u0010\b\u001a\u001a\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\n\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u000f0(0\'J\u0018\u0010)\u001a\u00020\u00182\b\u0010*\u001a\u0004\u0018\u00010\n2\u0006\u0010+\u001a\u00020\nJ\f\u0010,\u001a\b\u0012\u0004\u0012\u00020\u00070-J\f\u0010.\u001a\b\u0012\u0004\u0012\u00020\r0/J\u0010\u00100\u001a\u0004\u0018\u00010\r2\u0006\u0010\u0019\u001a\u00020\nJ\b\u00101\u001a\u0004\u0018\u00010\nR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\b\u001a\u000e\u0012\u0004\u0012\u00020\n\u0012\u0004\u0012\u00020\u00070\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u000b\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\r0\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u0010\u001a\u00020\u000f2\u0006\u0010\u000e\u001a\u00020\u000f@BX\u0080\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\"\u0010\u0014\u001a\u0004\u0018\u00010\u00132\b\u0010\u000e\u001a\u0004\u0018\u00010\u0013@BX\u0080\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016"}, d2 = {"Lcom/android/systemui/media/MediaPlayerData;", "", "()V", "EMPTY", "Lcom/android/systemui/media/MediaData;", "comparator", "Ljava/util/Comparator;", "Lcom/android/systemui/media/MediaPlayerData$MediaSortKey;", "mediaData", "", "", "mediaPlayers", "Ljava/util/TreeMap;", "Lcom/android/systemui/media/MediaControlPanel;", "<set-?>", "", "shouldPrioritizeSs", "getShouldPrioritizeSs$main", "()Z", "Lcom/android/systemui/media/SmartspaceMediaData;", "smartspaceMediaData", "getSmartspaceMediaData$main", "()Lcom/android/systemui/media/SmartspaceMediaData;", "addMediaPlayer", "", "key", "data", "player", "clock", "Lcom/android/systemui/util/time/SystemClock;", "isSsReactivated", "addMediaRecommendation", "shouldPrioritize", "clear", "firstActiveMediaIndex", "", "getMediaPlayer", "getMediaPlayerIndex", "hasActiveMediaOrRecommendationCard", "", "Lkotlin/Triple;", "moveIfExists", "oldKey", "newKey", "playerKeys", "", "players", "", "removeMediaPlayer", "smartspaceMediaKey", "MediaSortKey"})
public final class MediaPlayerData {
    private static final com.android.systemui.media.MediaData EMPTY = null;
    private static boolean shouldPrioritizeSs = false;
    @org.jetbrains.annotations.Nullable()
    private static com.android.systemui.media.SmartspaceMediaData smartspaceMediaData;
    private static final java.util.Comparator<com.android.systemui.media.MediaPlayerData.MediaSortKey> comparator = null;
    private static final java.util.TreeMap<com.android.systemui.media.MediaPlayerData.MediaSortKey, com.android.systemui.media.MediaControlPanel> mediaPlayers = null;
    private static final java.util.Map<java.lang.String, com.android.systemui.media.MediaPlayerData.MediaSortKey> mediaData = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.MediaPlayerData INSTANCE = null;
    
    public final boolean getShouldPrioritizeSs$main() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.media.SmartspaceMediaData getSmartspaceMediaData$main() {
        return null;
    }
    
    public final void addMediaPlayer(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaData data, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaControlPanel player, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock clock, boolean isSsReactivated) {
    }
    
    public final void addMediaRecommendation(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.SmartspaceMediaData data, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaControlPanel player, boolean shouldPrioritize, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock clock) {
    }
    
    public final void moveIfExists(@org.jetbrains.annotations.Nullable()
    java.lang.String oldKey, @org.jetbrains.annotations.NotNull()
    java.lang.String newKey) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.media.MediaControlPanel getMediaPlayer(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
        return null;
    }
    
    public final int getMediaPlayerIndex(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.media.MediaControlPanel removeMediaPlayer(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<kotlin.Triple<java.lang.String, com.android.systemui.media.MediaData, java.lang.Boolean>> mediaData() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Collection<com.android.systemui.media.MediaControlPanel> players() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Set<com.android.systemui.media.MediaPlayerData.MediaSortKey> playerKeys() {
        return null;
    }
    
    /**
     * Returns the index of the first non-timeout media.
     */
    public final int firstActiveMediaIndex() {
        return 0;
    }
    
    /**
     * Returns the existing Smartspace target id.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String smartspaceMediaKey() {
        return null;
    }
    
    @androidx.annotation.VisibleForTesting()
    public final void clear() {
    }
    
    public final boolean hasActiveMediaOrRecommendationCard() {
        return false;
    }
    
    public final boolean isSsReactivated(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
        return false;
    }
    
    private MediaPlayerData() {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u000f\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B)\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0002\u0010\b\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\tJ\t\u0010\u000f\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0010\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u0011\u001a\u00020\u0007H\u00c6\u0003J\t\u0010\u0012\u001a\u00020\u0003H\u00c6\u0003J1\u0010\u0013\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\b\b\u0002\u0010\b\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\u0014\u001a\u00020\u00032\b\u0010\u0015\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0016\u001a\u00020\u0017H\u00d6\u0001J\t\u0010\u0018\u001a\u00020\u0019H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0002\u0010\fR\u0011\u0010\b\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\fR\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000e"}, d2 = {"Lcom/android/systemui/media/MediaPlayerData$MediaSortKey;", "", "isSsMediaRec", "", "data", "Lcom/android/systemui/media/MediaData;", "updateTime", "", "isSsReactivated", "(ZLcom/android/systemui/media/MediaData;JZ)V", "getData", "()Lcom/android/systemui/media/MediaData;", "()Z", "getUpdateTime", "()J", "component1", "component2", "component3", "component4", "copy", "equals", "other", "hashCode", "", "toString", ""})
    public static final class MediaSortKey {
        private final boolean isSsMediaRec = false;
        @org.jetbrains.annotations.NotNull()
        private final com.android.systemui.media.MediaData data = null;
        private final long updateTime = 0L;
        private final boolean isSsReactivated = false;
        
        public final boolean isSsMediaRec() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.media.MediaData getData() {
            return null;
        }
        
        public final long getUpdateTime() {
            return 0L;
        }
        
        public final boolean isSsReactivated() {
            return false;
        }
        
        public MediaSortKey(boolean isSsMediaRec, @org.jetbrains.annotations.NotNull()
        com.android.systemui.media.MediaData data, long updateTime, boolean isSsReactivated) {
            super();
        }
        
        public final boolean component1() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.media.MediaData component2() {
            return null;
        }
        
        public final long component3() {
            return 0L;
        }
        
        public final boolean component4() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.media.MediaPlayerData.MediaSortKey copy(boolean isSsMediaRec, @org.jetbrains.annotations.NotNull()
        com.android.systemui.media.MediaData data, long updateTime, boolean isSsReactivated) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
}