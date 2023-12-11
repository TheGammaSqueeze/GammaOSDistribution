package com.android.systemui.media;

import android.app.PendingIntent;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.Icon;
import android.media.session.MediaSession;

/**
 * State of a media view.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\\\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\r\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\t\n\u0002\bL\b\u0086\b\u0018\u0000 p2\u00020\u0001:\u0001pB\u00ef\u0001\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0003\u0012\b\u0010\u0007\u001a\u0004\u0018\u00010\b\u0012\b\u0010\t\u001a\u0004\u0018\u00010\n\u0012\b\u0010\u000b\u001a\u0004\u0018\u00010\f\u0012\b\u0010\r\u001a\u0004\u0018\u00010\f\u0012\b\u0010\u000e\u001a\u0004\u0018\u00010\n\u0012\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010\u0012\f\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00030\u0010\u0012\u0006\u0010\u0013\u001a\u00020\b\u0012\b\u0010\u0014\u001a\u0004\u0018\u00010\u0015\u0012\b\u0010\u0016\u001a\u0004\u0018\u00010\u0017\u0012\b\u0010\u0018\u001a\u0004\u0018\u00010\u0019\u0012\u0006\u0010\u001a\u001a\u00020\u0005\u0012\b\u0010\u001b\u001a\u0004\u0018\u00010\u001c\u0012\b\b\u0002\u0010\u001d\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u001e\u001a\u00020\u0005\u0012\n\b\u0002\u0010\u001f\u001a\u0004\u0018\u00010\b\u0012\b\b\u0002\u0010 \u001a\u00020\u0005\u0012\n\b\u0002\u0010!\u001a\u0004\u0018\u00010\u0005\u0012\b\b\u0002\u0010\"\u001a\u00020\u0005\u0012\b\b\u0002\u0010#\u001a\u00020$\u00a2\u0006\u0002\u0010%J\t\u0010R\u001a\u00020\u0003H\u00c6\u0003J\u000f\u0010S\u001a\b\u0012\u0004\u0012\u00020\u00030\u0010H\u00c6\u0003J\t\u0010T\u001a\u00020\bH\u00c6\u0003J\u000b\u0010U\u001a\u0004\u0018\u00010\u0015H\u00c6\u0003J\u000b\u0010V\u001a\u0004\u0018\u00010\u0017H\u00c6\u0003J\u000b\u0010W\u001a\u0004\u0018\u00010\u0019H\u00c6\u0003J\t\u0010X\u001a\u00020\u0005H\u00c6\u0003J\u000b\u0010Y\u001a\u0004\u0018\u00010\u001cH\u00c6\u0003J\t\u0010Z\u001a\u00020\u0003H\u00c6\u0003J\t\u0010[\u001a\u00020\u0005H\u00c6\u0003J\u000b\u0010\\\u001a\u0004\u0018\u00010\bH\u00c6\u0003J\t\u0010]\u001a\u00020\u0005H\u00c6\u0003J\t\u0010^\u001a\u00020\u0005H\u00c6\u0003J\u0010\u0010_\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003\u00a2\u0006\u0002\u0010=J\t\u0010`\u001a\u00020\u0005H\u00c6\u0003J\t\u0010a\u001a\u00020$H\u00c6\u0003J\t\u0010b\u001a\u00020\u0003H\u00c6\u0003J\u000b\u0010c\u001a\u0004\u0018\u00010\bH\u00c6\u0003J\u000b\u0010d\u001a\u0004\u0018\u00010\nH\u00c6\u0003J\u000b\u0010e\u001a\u0004\u0018\u00010\fH\u00c6\u0003J\u000b\u0010f\u001a\u0004\u0018\u00010\fH\u00c6\u0003J\u000b\u0010g\u001a\u0004\u0018\u00010\nH\u00c6\u0003J\u000f\u0010h\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010H\u00c6\u0003J\u0096\u0002\u0010i\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00032\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\b2\n\b\u0002\u0010\t\u001a\u0004\u0018\u00010\n2\n\b\u0002\u0010\u000b\u001a\u0004\u0018\u00010\f2\n\b\u0002\u0010\r\u001a\u0004\u0018\u00010\f2\n\b\u0002\u0010\u000e\u001a\u0004\u0018\u00010\n2\u000e\b\u0002\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u00102\u000e\b\u0002\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00030\u00102\b\b\u0002\u0010\u0013\u001a\u00020\b2\n\b\u0002\u0010\u0014\u001a\u0004\u0018\u00010\u00152\n\b\u0002\u0010\u0016\u001a\u0004\u0018\u00010\u00172\n\b\u0002\u0010\u0018\u001a\u0004\u0018\u00010\u00192\b\b\u0002\u0010\u001a\u001a\u00020\u00052\n\b\u0002\u0010\u001b\u001a\u0004\u0018\u00010\u001c2\b\b\u0002\u0010\u001d\u001a\u00020\u00032\b\b\u0002\u0010\u001e\u001a\u00020\u00052\n\b\u0002\u0010\u001f\u001a\u0004\u0018\u00010\b2\b\b\u0002\u0010 \u001a\u00020\u00052\n\b\u0002\u0010!\u001a\u0004\u0018\u00010\u00052\b\b\u0002\u0010\"\u001a\u00020\u00052\b\b\u0002\u0010#\u001a\u00020$H\u00c6\u0001\u00a2\u0006\u0002\u0010jJ\u0013\u0010k\u001a\u00020\u00052\b\u0010l\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010m\u001a\u00020\u0003H\u00d6\u0001J\u0006\u0010n\u001a\u00020\u0005J\t\u0010o\u001a\u00020\bH\u00d6\u0001R\u0017\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010\u00a2\u0006\b\n\u0000\u001a\u0004\b&\u0010\'R\u0017\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00030\u0010\u00a2\u0006\b\n\u0000\u001a\u0004\b(\u0010\'R\u001a\u0010\u001a\u001a\u00020\u0005X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b)\u0010*\"\u0004\b+\u0010,R\u0013\u0010\u0007\u001a\u0004\u0018\u00010\b\u00a2\u0006\b\n\u0000\u001a\u0004\b-\u0010.R\u0013\u0010\t\u001a\u0004\u0018\u00010\n\u00a2\u0006\b\n\u0000\u001a\u0004\b/\u00100R\u0013\u0010\u000b\u001a\u0004\u0018\u00010\f\u00a2\u0006\b\n\u0000\u001a\u0004\b1\u00102R\u0013\u0010\u000e\u001a\u0004\u0018\u00010\n\u00a2\u0006\b\n\u0000\u001a\u0004\b3\u00100R\u0011\u0010\u0006\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b4\u00105R\u0013\u0010\u0016\u001a\u0004\u0018\u00010\u0017\u00a2\u0006\b\n\u0000\u001a\u0004\b6\u00107R\u0013\u0010\u0018\u001a\u0004\u0018\u00010\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\b8\u00109R\u001a\u0010 \u001a\u00020\u0005X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b:\u0010*\"\u0004\b;\u0010,R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b<\u0010*R\u0011\u0010\"\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\"\u0010*R\u0015\u0010!\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\n\n\u0002\u0010>\u001a\u0004\b!\u0010=R\u001a\u0010#\u001a\u00020$X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b?\u0010@\"\u0004\bA\u0010BR\u0013\u0010\u001f\u001a\u0004\u0018\u00010\b\u00a2\u0006\b\n\u0000\u001a\u0004\bC\u0010.R\u0011\u0010\u0013\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\bD\u0010.R\u001a\u0010\u001d\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bE\u00105\"\u0004\bF\u0010GR\u001c\u0010\u001b\u001a\u0004\u0018\u00010\u001cX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bH\u0010I\"\u0004\bJ\u0010KR\u001a\u0010\u001e\u001a\u00020\u0005X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bL\u0010*\"\u0004\bM\u0010,R\u0013\u0010\r\u001a\u0004\u0018\u00010\f\u00a2\u0006\b\n\u0000\u001a\u0004\bN\u00102R\u0013\u0010\u0014\u001a\u0004\u0018\u00010\u0015\u00a2\u0006\b\n\u0000\u001a\u0004\bO\u0010PR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\bQ\u00105"}, d2 = {"Lcom/android/systemui/media/MediaData;", "", "userId", "", "initialized", "", "backgroundColor", "app", "", "appIcon", "Landroid/graphics/drawable/Icon;", "artist", "", "song", "artwork", "actions", "", "Lcom/android/systemui/media/MediaAction;", "actionsToShowInCompact", "packageName", "token", "Landroid/media/session/MediaSession$Token;", "clickIntent", "Landroid/app/PendingIntent;", "device", "Lcom/android/systemui/media/MediaDeviceData;", "active", "resumeAction", "Ljava/lang/Runnable;", "playbackLocation", "resumption", "notificationKey", "hasCheckedForResume", "isPlaying", "isClearable", "lastActive", "", "(IZILjava/lang/String;Landroid/graphics/drawable/Icon;Ljava/lang/CharSequence;Ljava/lang/CharSequence;Landroid/graphics/drawable/Icon;Ljava/util/List;Ljava/util/List;Ljava/lang/String;Landroid/media/session/MediaSession$Token;Landroid/app/PendingIntent;Lcom/android/systemui/media/MediaDeviceData;ZLjava/lang/Runnable;IZLjava/lang/String;ZLjava/lang/Boolean;ZJ)V", "getActions", "()Ljava/util/List;", "getActionsToShowInCompact", "getActive", "()Z", "setActive", "(Z)V", "getApp", "()Ljava/lang/String;", "getAppIcon", "()Landroid/graphics/drawable/Icon;", "getArtist", "()Ljava/lang/CharSequence;", "getArtwork", "getBackgroundColor", "()I", "getClickIntent", "()Landroid/app/PendingIntent;", "getDevice", "()Lcom/android/systemui/media/MediaDeviceData;", "getHasCheckedForResume", "setHasCheckedForResume", "getInitialized", "()Ljava/lang/Boolean;", "Ljava/lang/Boolean;", "getLastActive", "()J", "setLastActive", "(J)V", "getNotificationKey", "getPackageName", "getPlaybackLocation", "setPlaybackLocation", "(I)V", "getResumeAction", "()Ljava/lang/Runnable;", "setResumeAction", "(Ljava/lang/Runnable;)V", "getResumption", "setResumption", "getSong", "getToken", "()Landroid/media/session/MediaSession$Token;", "getUserId", "component1", "component10", "component11", "component12", "component13", "component14", "component15", "component16", "component17", "component18", "component19", "component2", "component20", "component21", "component22", "component23", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "(IZILjava/lang/String;Landroid/graphics/drawable/Icon;Ljava/lang/CharSequence;Ljava/lang/CharSequence;Landroid/graphics/drawable/Icon;Ljava/util/List;Ljava/util/List;Ljava/lang/String;Landroid/media/session/MediaSession$Token;Landroid/app/PendingIntent;Lcom/android/systemui/media/MediaDeviceData;ZLjava/lang/Runnable;IZLjava/lang/String;ZLjava/lang/Boolean;ZJ)Lcom/android/systemui/media/MediaData;", "equals", "other", "hashCode", "isLocalSession", "toString", "Companion"})
public final class MediaData {
    private final int userId = 0;
    private final boolean initialized = false;
    private final int backgroundColor = 0;
    
    /**
     * App name that will be displayed on the player.
     */
    @org.jetbrains.annotations.Nullable()
    private final java.lang.String app = null;
    
    /**
     * App icon shown on player.
     */
    @org.jetbrains.annotations.Nullable()
    private final android.graphics.drawable.Icon appIcon = null;
    
    /**
     * Artist name.
     */
    @org.jetbrains.annotations.Nullable()
    private final java.lang.CharSequence artist = null;
    
    /**
     * Song name.
     */
    @org.jetbrains.annotations.Nullable()
    private final java.lang.CharSequence song = null;
    
    /**
     * Album artwork.
     */
    @org.jetbrains.annotations.Nullable()
    private final android.graphics.drawable.Icon artwork = null;
    
    /**
     * List of actions that can be performed on the player: prev, next, play, pause, etc.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<com.android.systemui.media.MediaAction> actions = null;
    
    /**
     * Same as above, but shown on smaller versions of the player, like in QQS or keyguard.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<java.lang.Integer> actionsToShowInCompact = null;
    
    /**
     * Package name of the app that's posting the media.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String packageName = null;
    
    /**
     * Unique media session identifier.
     */
    @org.jetbrains.annotations.Nullable()
    private final android.media.session.MediaSession.Token token = null;
    
    /**
     * Action to perform when the player is tapped.
     * This is unrelated to {@link #actions}.
     */
    @org.jetbrains.annotations.Nullable()
    private final android.app.PendingIntent clickIntent = null;
    
    /**
     * Where the media is playing: phone, headphones, ear buds, remote session.
     */
    @org.jetbrains.annotations.Nullable()
    private final com.android.systemui.media.MediaDeviceData device = null;
    
    /**
     * When active, a player will be displayed on keyguard and quick-quick settings.
     * This is unrelated to the stream being playing or not, a player will not be active if
     * timed out, or in resumption mode.
     */
    private boolean active;
    
    /**
     * Action that should be performed to restart a non active session.
     */
    @org.jetbrains.annotations.Nullable()
    private java.lang.Runnable resumeAction;
    
    /**
     * Playback location: one of PLAYBACK_LOCAL, PLAYBACK_CAST_LOCAL, or PLAYBACK_CAST_REMOTE
     */
    private int playbackLocation;
    
    /**
     * Indicates that this player is a resumption player (ie. It only shows a play actions which
     * will start the app and start playing).
     */
    private boolean resumption;
    
    /**
     * Notification key for cancelling a media player after a timeout (when not using resumption.)
     */
    @org.jetbrains.annotations.Nullable()
    private final java.lang.String notificationKey = null;
    private boolean hasCheckedForResume;
    
    /**
     * If apps do not report PlaybackState, set as null to imply 'undetermined'
     */
    @org.jetbrains.annotations.Nullable()
    private final java.lang.Boolean isPlaying = null;
    
    /**
     * Set from the notification and used as fallback when PlaybackState cannot be determined
     */
    private final boolean isClearable = false;
    
    /**
     * Timestamp when this player was last active.
     */
    private long lastActive;
    
    /**
     * Media is playing on the local device
     */
    public static final int PLAYBACK_LOCAL = 0;
    
    /**
     * Media is cast but originated on the local device
     */
    public static final int PLAYBACK_CAST_LOCAL = 1;
    
    /**
     * Media is from a remote cast notification
     */
    public static final int PLAYBACK_CAST_REMOTE = 2;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.MediaData.Companion Companion = null;
    
    public final boolean isLocalSession() {
        return false;
    }
    
    public final int getUserId() {
        return 0;
    }
    
    public final boolean getInitialized() {
        return false;
    }
    
    public final int getBackgroundColor() {
        return 0;
    }
    
    /**
     * App name that will be displayed on the player.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getApp() {
        return null;
    }
    
    /**
     * App icon shown on player.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.drawable.Icon getAppIcon() {
        return null;
    }
    
    /**
     * Artist name.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.CharSequence getArtist() {
        return null;
    }
    
    /**
     * Song name.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.CharSequence getSong() {
        return null;
    }
    
    /**
     * Album artwork.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.drawable.Icon getArtwork() {
        return null;
    }
    
    /**
     * List of actions that can be performed on the player: prev, next, play, pause, etc.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.media.MediaAction> getActions() {
        return null;
    }
    
    /**
     * Same as above, but shown on smaller versions of the player, like in QQS or keyguard.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.Integer> getActionsToShowInCompact() {
        return null;
    }
    
    /**
     * Package name of the app that's posting the media.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPackageName() {
        return null;
    }
    
    /**
     * Unique media session identifier.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.media.session.MediaSession.Token getToken() {
        return null;
    }
    
    /**
     * Action to perform when the player is tapped.
     * This is unrelated to {@link #actions}.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.app.PendingIntent getClickIntent() {
        return null;
    }
    
    /**
     * Where the media is playing: phone, headphones, ear buds, remote session.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.media.MediaDeviceData getDevice() {
        return null;
    }
    
    /**
     * When active, a player will be displayed on keyguard and quick-quick settings.
     * This is unrelated to the stream being playing or not, a player will not be active if
     * timed out, or in resumption mode.
     */
    public final boolean getActive() {
        return false;
    }
    
    /**
     * When active, a player will be displayed on keyguard and quick-quick settings.
     * This is unrelated to the stream being playing or not, a player will not be active if
     * timed out, or in resumption mode.
     */
    public final void setActive(boolean p0) {
    }
    
    /**
     * Action that should be performed to restart a non active session.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Runnable getResumeAction() {
        return null;
    }
    
    /**
     * Action that should be performed to restart a non active session.
     */
    public final void setResumeAction(@org.jetbrains.annotations.Nullable()
    java.lang.Runnable p0) {
    }
    
    /**
     * Playback location: one of PLAYBACK_LOCAL, PLAYBACK_CAST_LOCAL, or PLAYBACK_CAST_REMOTE
     */
    public final int getPlaybackLocation() {
        return 0;
    }
    
    /**
     * Playback location: one of PLAYBACK_LOCAL, PLAYBACK_CAST_LOCAL, or PLAYBACK_CAST_REMOTE
     */
    public final void setPlaybackLocation(int p0) {
    }
    
    /**
     * Indicates that this player is a resumption player (ie. It only shows a play actions which
     * will start the app and start playing).
     */
    public final boolean getResumption() {
        return false;
    }
    
    /**
     * Indicates that this player is a resumption player (ie. It only shows a play actions which
     * will start the app and start playing).
     */
    public final void setResumption(boolean p0) {
    }
    
    /**
     * Notification key for cancelling a media player after a timeout (when not using resumption.)
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getNotificationKey() {
        return null;
    }
    
    public final boolean getHasCheckedForResume() {
        return false;
    }
    
    public final void setHasCheckedForResume(boolean p0) {
    }
    
    /**
     * If apps do not report PlaybackState, set as null to imply 'undetermined'
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Boolean isPlaying() {
        return null;
    }
    
    /**
     * Set from the notification and used as fallback when PlaybackState cannot be determined
     */
    public final boolean isClearable() {
        return false;
    }
    
    /**
     * Timestamp when this player was last active.
     */
    public final long getLastActive() {
        return 0L;
    }
    
    /**
     * Timestamp when this player was last active.
     */
    public final void setLastActive(long p0) {
    }
    
    public MediaData(int userId, boolean initialized, int backgroundColor, @org.jetbrains.annotations.Nullable()
    java.lang.String app, @org.jetbrains.annotations.Nullable()
    android.graphics.drawable.Icon appIcon, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence artist, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence song, @org.jetbrains.annotations.Nullable()
    android.graphics.drawable.Icon artwork, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.media.MediaAction> actions, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.Integer> actionsToShowInCompact, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.Nullable()
    android.media.session.MediaSession.Token token, @org.jetbrains.annotations.Nullable()
    android.app.PendingIntent clickIntent, @org.jetbrains.annotations.Nullable()
    com.android.systemui.media.MediaDeviceData device, boolean active, @org.jetbrains.annotations.Nullable()
    java.lang.Runnable resumeAction, int playbackLocation, boolean resumption, @org.jetbrains.annotations.Nullable()
    java.lang.String notificationKey, boolean hasCheckedForResume, @org.jetbrains.annotations.Nullable()
    java.lang.Boolean isPlaying, boolean isClearable, long lastActive) {
        super();
    }
    
    public final int component1() {
        return 0;
    }
    
    public final boolean component2() {
        return false;
    }
    
    public final int component3() {
        return 0;
    }
    
    /**
     * App name that will be displayed on the player.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component4() {
        return null;
    }
    
    /**
     * App icon shown on player.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.drawable.Icon component5() {
        return null;
    }
    
    /**
     * Artist name.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.CharSequence component6() {
        return null;
    }
    
    /**
     * Song name.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.CharSequence component7() {
        return null;
    }
    
    /**
     * Album artwork.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.drawable.Icon component8() {
        return null;
    }
    
    /**
     * List of actions that can be performed on the player: prev, next, play, pause, etc.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.media.MediaAction> component9() {
        return null;
    }
    
    /**
     * Same as above, but shown on smaller versions of the player, like in QQS or keyguard.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.Integer> component10() {
        return null;
    }
    
    /**
     * Package name of the app that's posting the media.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component11() {
        return null;
    }
    
    /**
     * Unique media session identifier.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.media.session.MediaSession.Token component12() {
        return null;
    }
    
    /**
     * Action to perform when the player is tapped.
     * This is unrelated to {@link #actions}.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.app.PendingIntent component13() {
        return null;
    }
    
    /**
     * Where the media is playing: phone, headphones, ear buds, remote session.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.media.MediaDeviceData component14() {
        return null;
    }
    
    /**
     * When active, a player will be displayed on keyguard and quick-quick settings.
     * This is unrelated to the stream being playing or not, a player will not be active if
     * timed out, or in resumption mode.
     */
    public final boolean component15() {
        return false;
    }
    
    /**
     * Action that should be performed to restart a non active session.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Runnable component16() {
        return null;
    }
    
    /**
     * Playback location: one of PLAYBACK_LOCAL, PLAYBACK_CAST_LOCAL, or PLAYBACK_CAST_REMOTE
     */
    public final int component17() {
        return 0;
    }
    
    /**
     * Indicates that this player is a resumption player (ie. It only shows a play actions which
     * will start the app and start playing).
     */
    public final boolean component18() {
        return false;
    }
    
    /**
     * Notification key for cancelling a media player after a timeout (when not using resumption.)
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component19() {
        return null;
    }
    
    public final boolean component20() {
        return false;
    }
    
    /**
     * If apps do not report PlaybackState, set as null to imply 'undetermined'
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Boolean component21() {
        return null;
    }
    
    /**
     * Set from the notification and used as fallback when PlaybackState cannot be determined
     */
    public final boolean component22() {
        return false;
    }
    
    /**
     * Timestamp when this player was last active.
     */
    public final long component23() {
        return 0L;
    }
    
    /**
     * State of a media view.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.media.MediaData copy(int userId, boolean initialized, int backgroundColor, @org.jetbrains.annotations.Nullable()
    java.lang.String app, @org.jetbrains.annotations.Nullable()
    android.graphics.drawable.Icon appIcon, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence artist, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence song, @org.jetbrains.annotations.Nullable()
    android.graphics.drawable.Icon artwork, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.media.MediaAction> actions, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.Integer> actionsToShowInCompact, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.Nullable()
    android.media.session.MediaSession.Token token, @org.jetbrains.annotations.Nullable()
    android.app.PendingIntent clickIntent, @org.jetbrains.annotations.Nullable()
    com.android.systemui.media.MediaDeviceData device, boolean active, @org.jetbrains.annotations.Nullable()
    java.lang.Runnable resumeAction, int playbackLocation, boolean resumption, @org.jetbrains.annotations.Nullable()
    java.lang.String notificationKey, boolean hasCheckedForResume, @org.jetbrains.annotations.Nullable()
    java.lang.Boolean isPlaying, boolean isClearable, long lastActive) {
        return null;
    }
    
    /**
     * State of a media view.
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * State of a media view.
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * State of a media view.
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaData$Companion;", "", "()V", "PLAYBACK_CAST_LOCAL", "", "PLAYBACK_CAST_REMOTE", "PLAYBACK_LOCAL"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}