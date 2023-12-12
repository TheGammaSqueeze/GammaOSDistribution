package com.android.systemui.statusbar.notification.collection;

import com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection;

/**
 * Stores the suppressed state that [ShadeListBuilder] assigned to this [ListEntry] before the
 * VisualStabilityManager suppressed group and section changes.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u000e\n\u0002\u0010\u0002\n\u0002\b\u0007\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\b\u0086\b\u0018\u0000 \"2\u00020\u0001:\u0001\"B#\b\u0002\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u000e\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u0000J\u000b\u0010\u0018\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\u000b\u0010\u0019\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003J\t\u0010\u001a\u001a\u00020\u0007H\u00c6\u0003J+\u0010\u001b\u001a\u00020\u00002\n\b\u0002\u0010\u0002\u001a\u0004\u0018\u00010\u00032\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u0007H\u00c6\u0001J\u0013\u0010\u001c\u001a\u00020\u00072\b\u0010\u0017\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001d\u001a\u00020\u001eH\u00d6\u0001J\u0006\u0010\u001f\u001a\u00020\u0016J\t\u0010 \u001a\u00020!H\u00d6\u0001R\u001c\u0010\u0004\u001a\u0004\u0018\u00010\u0005X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\t\u0010\n\"\u0004\b\u000b\u0010\fR\u001c\u0010\u0002\u001a\u0004\u0018\u00010\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\r\u0010\u000e\"\u0004\b\u000f\u0010\u0010R\u001a\u0010\u0006\u001a\u00020\u0007X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/SuppressedAttachState;", "", "section", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/NotifSection;", "parent", "Lcom/android/systemui/statusbar/notification/collection/GroupEntry;", "wasPruneSuppressed", "", "(Lcom/android/systemui/statusbar/notification/collection/listbuilder/NotifSection;Lcom/android/systemui/statusbar/notification/collection/GroupEntry;Z)V", "getParent", "()Lcom/android/systemui/statusbar/notification/collection/GroupEntry;", "setParent", "(Lcom/android/systemui/statusbar/notification/collection/GroupEntry;)V", "getSection", "()Lcom/android/systemui/statusbar/notification/collection/listbuilder/NotifSection;", "setSection", "(Lcom/android/systemui/statusbar/notification/collection/listbuilder/NotifSection;)V", "getWasPruneSuppressed", "()Z", "setWasPruneSuppressed", "(Z)V", "clone", "", "other", "component1", "component2", "component3", "copy", "equals", "hashCode", "", "reset", "toString", "", "Companion"})
public final class SuppressedAttachState {
    
    /**
     * The suppressed section assignment for this ListEntry.
     * Null if no section change was suppressed.
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection section;
    
    /**
     * The suppressed parent assignment for this ListEntry.
     * - Null if no parent change was suppressed.
     * - Root if suppressing group change to top-level
     * - GroupEntry if suppressing group change to a different group
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.collection.GroupEntry parent;
    
    /**
     * Whether the ListEntry would have been pruned had its group change not been suppressed.
     */
    private boolean wasPruneSuppressed;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.collection.SuppressedAttachState.Companion Companion = null;
    
    /**
     * Copies the state of another instance.
     */
    public final void clone(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.SuppressedAttachState other) {
    }
    
    /**
     * Resets back to a "clean" state (the same as created by the factory method)
     */
    public final void reset() {
    }
    
    /**
     * The suppressed section assignment for this ListEntry.
     * Null if no section change was suppressed.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection getSection() {
        return null;
    }
    
    /**
     * The suppressed section assignment for this ListEntry.
     * Null if no section change was suppressed.
     */
    public final void setSection(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection p0) {
    }
    
    /**
     * The suppressed parent assignment for this ListEntry.
     * - Null if no parent change was suppressed.
     * - Root if suppressing group change to top-level
     * - GroupEntry if suppressing group change to a different group
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.GroupEntry getParent() {
        return null;
    }
    
    /**
     * The suppressed parent assignment for this ListEntry.
     * - Null if no parent change was suppressed.
     * - Root if suppressing group change to top-level
     * - GroupEntry if suppressing group change to a different group
     */
    public final void setParent(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry p0) {
    }
    
    /**
     * Whether the ListEntry would have been pruned had its group change not been suppressed.
     */
    public final boolean getWasPruneSuppressed() {
        return false;
    }
    
    /**
     * Whether the ListEntry would have been pruned had its group change not been suppressed.
     */
    public final void setWasPruneSuppressed(boolean p0) {
    }
    
    private SuppressedAttachState(com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection section, com.android.systemui.statusbar.notification.collection.GroupEntry parent, boolean wasPruneSuppressed) {
        super();
    }
    
    /**
     * The suppressed section assignment for this ListEntry.
     * Null if no section change was suppressed.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection component1() {
        return null;
    }
    
    /**
     * The suppressed parent assignment for this ListEntry.
     * - Null if no parent change was suppressed.
     * - Root if suppressing group change to top-level
     * - GroupEntry if suppressing group change to a different group
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.GroupEntry component2() {
        return null;
    }
    
    /**
     * Whether the ListEntry would have been pruned had its group change not been suppressed.
     */
    public final boolean component3() {
        return false;
    }
    
    /**
     * Stores the suppressed state that [ShadeListBuilder] assigned to this [ListEntry] before the
     * VisualStabilityManager suppressed group and section changes.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.SuppressedAttachState copy(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection section, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry parent, boolean wasPruneSuppressed) {
        return null;
    }
    
    /**
     * Stores the suppressed state that [ShadeListBuilder] assigned to this [ListEntry] before the
     * VisualStabilityManager suppressed group and section changes.
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Stores the suppressed state that [ShadeListBuilder] assigned to this [ListEntry] before the
     * VisualStabilityManager suppressed group and section changes.
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Stores the suppressed state that [ShadeListBuilder] assigned to this [ListEntry] before the
     * VisualStabilityManager suppressed group and section changes.
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.collection.SuppressedAttachState create() {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0007"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/SuppressedAttachState$Companion;", "", "()V", "create", "Lcom/android/systemui/statusbar/notification/collection/SuppressedAttachState;"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.statusbar.notification.collection.SuppressedAttachState create() {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}