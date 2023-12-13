package com.android.systemui.privacy;

import android.content.Context;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010\u000e\n\u0002\b\u0010\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001B)\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0002\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\t\u0010\u0017\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0018\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u0019\u001a\u00020\u0007H\u00c6\u0003J\t\u0010\u001a\u001a\u00020\tH\u00c6\u0003J1\u0010\u001b\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\b\b\u0002\u0010\b\u001a\u00020\tH\u00c6\u0001J\u0013\u0010\u001c\u001a\u00020\t2\b\u0010\u001d\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001e\u001a\u00020\u001fH\u00d6\u0001J\t\u0010 \u001a\u00020\u000eH\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\r\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016"}, d2 = {"Lcom/android/systemui/privacy/PrivacyItem;", "", "privacyType", "Lcom/android/systemui/privacy/PrivacyType;", "application", "Lcom/android/systemui/privacy/PrivacyApplication;", "timeStampElapsed", "", "paused", "", "(Lcom/android/systemui/privacy/PrivacyType;Lcom/android/systemui/privacy/PrivacyApplication;JZ)V", "getApplication", "()Lcom/android/systemui/privacy/PrivacyApplication;", "log", "", "getLog", "()Ljava/lang/String;", "getPaused", "()Z", "getPrivacyType", "()Lcom/android/systemui/privacy/PrivacyType;", "getTimeStampElapsed", "()J", "component1", "component2", "component3", "component4", "copy", "equals", "other", "hashCode", "", "toString"})
public final class PrivacyItem {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String log = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.privacy.PrivacyType privacyType = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.privacy.PrivacyApplication application = null;
    private final long timeStampElapsed = 0L;
    private final boolean paused = false;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getLog() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.privacy.PrivacyType getPrivacyType() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.privacy.PrivacyApplication getApplication() {
        return null;
    }
    
    public final long getTimeStampElapsed() {
        return 0L;
    }
    
    public final boolean getPaused() {
        return false;
    }
    
    public PrivacyItem(@org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyType privacyType, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyApplication application, long timeStampElapsed, boolean paused) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.privacy.PrivacyType component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.privacy.PrivacyApplication component2() {
        return null;
    }
    
    public final long component3() {
        return 0L;
    }
    
    public final boolean component4() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.privacy.PrivacyItem copy(@org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyType privacyType, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyApplication application, long timeStampElapsed, boolean paused) {
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