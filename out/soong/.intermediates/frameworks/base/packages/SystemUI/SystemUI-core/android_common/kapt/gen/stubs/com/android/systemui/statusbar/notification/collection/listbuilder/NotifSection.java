package com.android.systemui.statusbar.notification.collection.listbuilder;

import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner;
import com.android.systemui.statusbar.notification.collection.render.NodeController;
import com.android.systemui.statusbar.notification.stack.PriorityBucket;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000e\n\u0002\b\b\n\u0002\u0010\u000b\n\u0002\b\u0003\b\u0086\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\t\u0010\u0017\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0018\u001a\u00020\u0005H\u00c6\u0003J\u001d\u0010\u0019\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0005H\u00c6\u0001J\u0013\u0010\u001a\u001a\u00020\u001b2\b\u0010\u001c\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001d\u001a\u00020\u0005H\u00d6\u0001J\t\u0010\u001e\u001a\u00020\u0012H\u00d6\u0001R\u0017\u0010\u0007\u001a\u00020\u0005\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\b\u0010\t\u001a\u0004\b\n\u0010\u000bR\u0013\u0010\f\u001a\u0004\u0018\u00010\r8F\u00a2\u0006\u0006\u001a\u0004\b\u000e\u0010\u000fR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u000bR\u0011\u0010\u0011\u001a\u00020\u00128F\u00a2\u0006\u0006\u001a\u0004\b\u0013\u0010\u0014R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/listbuilder/NotifSection;", "", "sectioner", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifSectioner;", "index", "", "(Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifSectioner;I)V", "bucket", "getBucket$annotations", "()V", "getBucket", "()I", "headerController", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "getHeaderController", "()Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "getIndex", "label", "", "getLabel", "()Ljava/lang/String;", "getSectioner", "()Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifSectioner;", "component1", "component2", "copy", "equals", "", "other", "hashCode", "toString"})
public final class NotifSection {
    private final int bucket = 0;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner sectioner = null;
    private final int index = 0;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getLabel() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.render.NodeController getHeaderController() {
        return null;
    }
    
    @com.android.systemui.statusbar.notification.stack.PriorityBucket()
    @java.lang.Deprecated()
    public static void getBucket$annotations() {
    }
    
    public final int getBucket() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner getSectioner() {
        return null;
    }
    
    public final int getIndex() {
        return 0;
    }
    
    public NotifSection(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner sectioner, int index) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner component1() {
        return null;
    }
    
    public final int component2() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection copy(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner sectioner, int index) {
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