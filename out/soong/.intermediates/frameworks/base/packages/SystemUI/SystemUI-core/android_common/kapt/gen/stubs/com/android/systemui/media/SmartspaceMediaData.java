package com.android.systemui.media;

import android.app.smartspace.SmartspaceAction;
import android.content.Intent;

/**
 * State of a Smartspace media recommendations view.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\t\n\u0002\b\u001d\b\u0086\b\u0018\u00002\u00020\u0001BW\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\u0003\u0012\b\u0010\b\u001a\u0004\u0018\u00010\t\u0012\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\t0\u000b\u0012\b\u0010\f\u001a\u0004\u0018\u00010\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u00a2\u0006\u0002\u0010\u0012J\t\u0010!\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\"\u001a\u00020\u0005H\u00c6\u0003J\t\u0010#\u001a\u00020\u0005H\u00c6\u0003J\t\u0010$\u001a\u00020\u0003H\u00c6\u0003J\u000b\u0010%\u001a\u0004\u0018\u00010\tH\u00c6\u0003J\u000f\u0010&\u001a\b\u0012\u0004\u0012\u00020\t0\u000bH\u00c6\u0003J\u000b\u0010\'\u001a\u0004\u0018\u00010\rH\u00c6\u0003J\t\u0010(\u001a\u00020\u000fH\u00c6\u0003J\t\u0010)\u001a\u00020\u0011H\u00c6\u0003Jm\u0010*\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00052\b\b\u0002\u0010\u0007\u001a\u00020\u00032\n\b\u0002\u0010\b\u001a\u0004\u0018\u00010\t2\u000e\b\u0002\u0010\n\u001a\b\u0012\u0004\u0012\u00020\t0\u000b2\n\b\u0002\u0010\f\u001a\u0004\u0018\u00010\r2\b\b\u0002\u0010\u000e\u001a\u00020\u000f2\b\b\u0002\u0010\u0010\u001a\u00020\u0011H\u00c6\u0001J\u0013\u0010+\u001a\u00020\u00052\b\u0010,\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010-\u001a\u00020\u000fH\u00d6\u0001J\t\u0010.\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u000e\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0013\u0010\b\u001a\u0004\u0018\u00010\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016R\u0013\u0010\f\u001a\u0004\u0018\u00010\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0018R\u0011\u0010\u0010\u001a\u00020\u0011\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0019\u0010\u001aR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0004\u0010\u001bR\u0011\u0010\u0006\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u001bR\u0011\u0010\u0007\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001c\u0010\u001dR\u0017\u0010\n\u001a\b\u0012\u0004\u0012\u00020\t0\u000b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001e\u0010\u001fR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b \u0010\u001d"}, d2 = {"Lcom/android/systemui/media/SmartspaceMediaData;", "", "targetId", "", "isActive", "", "isValid", "packageName", "cardAction", "Landroid/app/smartspace/SmartspaceAction;", "recommendations", "", "dismissIntent", "Landroid/content/Intent;", "backgroundColor", "", "headphoneConnectionTimeMillis", "", "(Ljava/lang/String;ZZLjava/lang/String;Landroid/app/smartspace/SmartspaceAction;Ljava/util/List;Landroid/content/Intent;IJ)V", "getBackgroundColor", "()I", "getCardAction", "()Landroid/app/smartspace/SmartspaceAction;", "getDismissIntent", "()Landroid/content/Intent;", "getHeadphoneConnectionTimeMillis", "()J", "()Z", "getPackageName", "()Ljava/lang/String;", "getRecommendations", "()Ljava/util/List;", "getTargetId", "component1", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "equals", "other", "hashCode", "toString"})
public final class SmartspaceMediaData {
    
    /**
     * Unique id of a Smartspace media target.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String targetId = null;
    
    /**
     * Indicates if the status is active.
     */
    private final boolean isActive = false;
    
    /**
     * Indicates if all the required data field is valid.
     */
    private final boolean isValid = false;
    
    /**
     * Package name of the media recommendations' provider-app.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String packageName = null;
    
    /**
     * Action to perform when the card is tapped. Also contains the target's extra info.
     */
    @org.jetbrains.annotations.Nullable()
    private final android.app.smartspace.SmartspaceAction cardAction = null;
    
    /**
     * List of media recommendations.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<android.app.smartspace.SmartspaceAction> recommendations = null;
    
    /**
     * Intent for the user's initiated dismissal.
     */
    @org.jetbrains.annotations.Nullable()
    private final android.content.Intent dismissIntent = null;
    
    /**
     * View's background color.
     */
    private final int backgroundColor = 0;
    
    /**
     * The timestamp in milliseconds that headphone is connected.
     */
    private final long headphoneConnectionTimeMillis = 0L;
    
    /**
     * Unique id of a Smartspace media target.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getTargetId() {
        return null;
    }
    
    /**
     * Indicates if the status is active.
     */
    public final boolean isActive() {
        return false;
    }
    
    /**
     * Indicates if all the required data field is valid.
     */
    public final boolean isValid() {
        return false;
    }
    
    /**
     * Package name of the media recommendations' provider-app.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPackageName() {
        return null;
    }
    
    /**
     * Action to perform when the card is tapped. Also contains the target's extra info.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.app.smartspace.SmartspaceAction getCardAction() {
        return null;
    }
    
    /**
     * List of media recommendations.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<android.app.smartspace.SmartspaceAction> getRecommendations() {
        return null;
    }
    
    /**
     * Intent for the user's initiated dismissal.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.content.Intent getDismissIntent() {
        return null;
    }
    
    /**
     * View's background color.
     */
    public final int getBackgroundColor() {
        return 0;
    }
    
    /**
     * The timestamp in milliseconds that headphone is connected.
     */
    public final long getHeadphoneConnectionTimeMillis() {
        return 0L;
    }
    
    public SmartspaceMediaData(@org.jetbrains.annotations.NotNull()
    java.lang.String targetId, boolean isActive, boolean isValid, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.Nullable()
    android.app.smartspace.SmartspaceAction cardAction, @org.jetbrains.annotations.NotNull()
    java.util.List<android.app.smartspace.SmartspaceAction> recommendations, @org.jetbrains.annotations.Nullable()
    android.content.Intent dismissIntent, int backgroundColor, long headphoneConnectionTimeMillis) {
        super();
    }
    
    /**
     * Unique id of a Smartspace media target.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component1() {
        return null;
    }
    
    /**
     * Indicates if the status is active.
     */
    public final boolean component2() {
        return false;
    }
    
    /**
     * Indicates if all the required data field is valid.
     */
    public final boolean component3() {
        return false;
    }
    
    /**
     * Package name of the media recommendations' provider-app.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component4() {
        return null;
    }
    
    /**
     * Action to perform when the card is tapped. Also contains the target's extra info.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.app.smartspace.SmartspaceAction component5() {
        return null;
    }
    
    /**
     * List of media recommendations.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<android.app.smartspace.SmartspaceAction> component6() {
        return null;
    }
    
    /**
     * Intent for the user's initiated dismissal.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.content.Intent component7() {
        return null;
    }
    
    /**
     * View's background color.
     */
    public final int component8() {
        return 0;
    }
    
    /**
     * The timestamp in milliseconds that headphone is connected.
     */
    public final long component9() {
        return 0L;
    }
    
    /**
     * State of a Smartspace media recommendations view.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.media.SmartspaceMediaData copy(@org.jetbrains.annotations.NotNull()
    java.lang.String targetId, boolean isActive, boolean isValid, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.Nullable()
    android.app.smartspace.SmartspaceAction cardAction, @org.jetbrains.annotations.NotNull()
    java.util.List<android.app.smartspace.SmartspaceAction> recommendations, @org.jetbrains.annotations.Nullable()
    android.content.Intent dismissIntent, int backgroundColor, long headphoneConnectionTimeMillis) {
        return null;
    }
    
    /**
     * State of a Smartspace media recommendations view.
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * State of a Smartspace media recommendations view.
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * State of a Smartspace media recommendations view.
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}