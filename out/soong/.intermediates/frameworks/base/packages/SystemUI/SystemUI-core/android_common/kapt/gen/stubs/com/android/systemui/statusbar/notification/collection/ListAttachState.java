package com.android.systemui.statusbar.notification.collection;

import com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter;

/**
 * Stores the state that [ShadeListBuilder] assigns to this [ListEntry]
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0016\n\u0002\u0010\u0002\n\u0002\b\b\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\b\u0086\b\u0018\u0000 12\u00020\u0001:\u00011B7\b\u0002\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u0012\b\u0010\b\u001a\u0004\u0018\u00010\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\u000e\u0010!\u001a\u00020\"2\u0006\u0010#\u001a\u00020\u0000J\u000b\u0010$\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\u000b\u0010%\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003J\u000b\u0010&\u001a\u0004\u0018\u00010\u0007H\u00c6\u0003J\u000b\u0010\'\u001a\u0004\u0018\u00010\tH\u00c6\u0003J\t\u0010(\u001a\u00020\u000bH\u00c6\u0003JC\u0010)\u001a\u00020\u00002\n\b\u0002\u0010\u0002\u001a\u0004\u0018\u00010\u00032\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u00052\n\b\u0002\u0010\u0006\u001a\u0004\u0018\u00010\u00072\n\b\u0002\u0010\b\u001a\u0004\u0018\u00010\t2\b\b\u0002\u0010\n\u001a\u00020\u000bH\u00c6\u0001J\u0013\u0010*\u001a\u00020+2\b\u0010#\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010,\u001a\u00020-H\u00d6\u0001J\u0006\u0010.\u001a\u00020\"J\t\u0010/\u001a\u000200H\u00d6\u0001R\u001c\u0010\u0006\u001a\u0004\u0018\u00010\u0007X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\r\u0010\u000e\"\u0004\b\u000f\u0010\u0010R\u001c\u0010\u0002\u001a\u0004\u0018\u00010\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u001c\u0010\b\u001a\u0004\u0018\u00010\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0015\u0010\u0016\"\u0004\b\u0017\u0010\u0018R\u001c\u0010\u0004\u001a\u0004\u0018\u00010\u0005X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0019\u0010\u001a\"\u0004\b\u001b\u0010\u001cR\u001a\u0010\n\u001a\u00020\u000bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001d\u0010\u001e\"\u0004\b\u001f\u0010 "}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/ListAttachState;", "", "parent", "Lcom/android/systemui/statusbar/notification/collection/GroupEntry;", "section", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/NotifSection;", "excludingFilter", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifFilter;", "promoter", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifPromoter;", "suppressedChanges", "Lcom/android/systemui/statusbar/notification/collection/SuppressedAttachState;", "(Lcom/android/systemui/statusbar/notification/collection/GroupEntry;Lcom/android/systemui/statusbar/notification/collection/listbuilder/NotifSection;Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifFilter;Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifPromoter;Lcom/android/systemui/statusbar/notification/collection/SuppressedAttachState;)V", "getExcludingFilter", "()Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifFilter;", "setExcludingFilter", "(Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifFilter;)V", "getParent", "()Lcom/android/systemui/statusbar/notification/collection/GroupEntry;", "setParent", "(Lcom/android/systemui/statusbar/notification/collection/GroupEntry;)V", "getPromoter", "()Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifPromoter;", "setPromoter", "(Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifPromoter;)V", "getSection", "()Lcom/android/systemui/statusbar/notification/collection/listbuilder/NotifSection;", "setSection", "(Lcom/android/systemui/statusbar/notification/collection/listbuilder/NotifSection;)V", "getSuppressedChanges", "()Lcom/android/systemui/statusbar/notification/collection/SuppressedAttachState;", "setSuppressedChanges", "(Lcom/android/systemui/statusbar/notification/collection/SuppressedAttachState;)V", "clone", "", "other", "component1", "component2", "component3", "component4", "component5", "copy", "equals", "", "hashCode", "", "reset", "toString", "", "Companion"})
public final class ListAttachState {
    
    /**
     * Null if not attached to the current shade list. If top-level, then the shade list root. If
     * part of a group, then that group's GroupEntry.
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.collection.GroupEntry parent;
    
    /**
     * The section that this ListEntry was sorted into. If the child of the group, this will be the
     * parent's section. Null if not attached to the list.
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection section;
    
    /**
     * If a [NotifFilter] is excluding this entry from the list, then that filter. Always null for
     * [GroupEntry]s.
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter excludingFilter;
    
    /**
     * The [NotifPromoter] promoting this entry to top-level, if any. Always null for [GroupEntry]s.
     */
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter promoter;
    
    /**
     * If the [VisualStabilityManager] is suppressing group or section changes for this entry,
     * suppressedChanges will contain the new parent or section that we would have assigned to
     * the entry had it not been suppressed by the VisualStabilityManager.
     */
    @org.jetbrains.annotations.NotNull()
    private com.android.systemui.statusbar.notification.collection.SuppressedAttachState suppressedChanges;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.collection.ListAttachState.Companion Companion = null;
    
    /**
     * Copies the state of another instance.
     */
    public final void clone(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.ListAttachState other) {
    }
    
    /**
     * Resets back to a "clean" state (the same as created by the factory method)
     */
    public final void reset() {
    }
    
    /**
     * Null if not attached to the current shade list. If top-level, then the shade list root. If
     * part of a group, then that group's GroupEntry.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.GroupEntry getParent() {
        return null;
    }
    
    /**
     * Null if not attached to the current shade list. If top-level, then the shade list root. If
     * part of a group, then that group's GroupEntry.
     */
    public final void setParent(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry p0) {
    }
    
    /**
     * The section that this ListEntry was sorted into. If the child of the group, this will be the
     * parent's section. Null if not attached to the list.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection getSection() {
        return null;
    }
    
    /**
     * The section that this ListEntry was sorted into. If the child of the group, this will be the
     * parent's section. Null if not attached to the list.
     */
    public final void setSection(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection p0) {
    }
    
    /**
     * If a [NotifFilter] is excluding this entry from the list, then that filter. Always null for
     * [GroupEntry]s.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter getExcludingFilter() {
        return null;
    }
    
    /**
     * If a [NotifFilter] is excluding this entry from the list, then that filter. Always null for
     * [GroupEntry]s.
     */
    public final void setExcludingFilter(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter p0) {
    }
    
    /**
     * The [NotifPromoter] promoting this entry to top-level, if any. Always null for [GroupEntry]s.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter getPromoter() {
        return null;
    }
    
    /**
     * The [NotifPromoter] promoting this entry to top-level, if any. Always null for [GroupEntry]s.
     */
    public final void setPromoter(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter p0) {
    }
    
    /**
     * If the [VisualStabilityManager] is suppressing group or section changes for this entry,
     * suppressedChanges will contain the new parent or section that we would have assigned to
     * the entry had it not been suppressed by the VisualStabilityManager.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.SuppressedAttachState getSuppressedChanges() {
        return null;
    }
    
    /**
     * If the [VisualStabilityManager] is suppressing group or section changes for this entry,
     * suppressedChanges will contain the new parent or section that we would have assigned to
     * the entry had it not been suppressed by the VisualStabilityManager.
     */
    public final void setSuppressedChanges(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.SuppressedAttachState p0) {
    }
    
    private ListAttachState(com.android.systemui.statusbar.notification.collection.GroupEntry parent, com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection section, com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter excludingFilter, com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter promoter, com.android.systemui.statusbar.notification.collection.SuppressedAttachState suppressedChanges) {
        super();
    }
    
    /**
     * Null if not attached to the current shade list. If top-level, then the shade list root. If
     * part of a group, then that group's GroupEntry.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.GroupEntry component1() {
        return null;
    }
    
    /**
     * The section that this ListEntry was sorted into. If the child of the group, this will be the
     * parent's section. Null if not attached to the list.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection component2() {
        return null;
    }
    
    /**
     * If a [NotifFilter] is excluding this entry from the list, then that filter. Always null for
     * [GroupEntry]s.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter component3() {
        return null;
    }
    
    /**
     * The [NotifPromoter] promoting this entry to top-level, if any. Always null for [GroupEntry]s.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter component4() {
        return null;
    }
    
    /**
     * If the [VisualStabilityManager] is suppressing group or section changes for this entry,
     * suppressedChanges will contain the new parent or section that we would have assigned to
     * the entry had it not been suppressed by the VisualStabilityManager.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.SuppressedAttachState component5() {
        return null;
    }
    
    /**
     * Stores the state that [ShadeListBuilder] assigns to this [ListEntry]
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.ListAttachState copy(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry parent, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection section, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter excludingFilter, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter promoter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.SuppressedAttachState suppressedChanges) {
        return null;
    }
    
    /**
     * Stores the state that [ShadeListBuilder] assigns to this [ListEntry]
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Stores the state that [ShadeListBuilder] assigns to this [ListEntry]
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Stores the state that [ShadeListBuilder] assigns to this [ListEntry]
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.collection.ListAttachState create() {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0007"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/ListAttachState$Companion;", "", "()V", "create", "Lcom/android/systemui/statusbar/notification/collection/ListAttachState;"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.statusbar.notification.collection.ListAttachState create() {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}