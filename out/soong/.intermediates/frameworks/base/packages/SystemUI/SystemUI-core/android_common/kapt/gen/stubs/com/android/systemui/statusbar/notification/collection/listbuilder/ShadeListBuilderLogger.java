package com.android.systemui.statusbar.notification.collection.listbuilder;

import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.dagger.NotificationLog;
import com.android.systemui.statusbar.notification.collection.GroupEntry;
import com.android.systemui.statusbar.notification.collection.ListEntry;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u000b\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0010\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J&\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\n2\u0006\u0010\f\u001a\u00020\nJ\u0016\u0010\r\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\u000e\u001a\u00020\nJ\u001e\u0010\u000f\u001a\u00020\u00062\u0006\u0010\u0010\u001a\u00020\b2\u0006\u0010\u0011\u001a\u00020\b2\u0006\u0010\u0012\u001a\u00020\bJ*\u0010\u0013\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\u0014\u001a\u00020\n2\b\u0010\u0015\u001a\u0004\u0018\u00010\u00162\b\u0010\u0017\u001a\u0004\u0018\u00010\u0016J\"\u0010\u0018\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\b\u0010\u0019\u001a\u0004\u0018\u00010\u001a2\b\u0010\u001b\u001a\u0004\u0018\u00010\u001aJ\u0014\u0010\u001c\u001a\u00020\u00062\f\u0010\u001d\u001a\b\u0012\u0004\u0012\u00020\u001f0\u001eJ\u0016\u0010 \u001a\u00020\u00062\u0006\u0010!\u001a\u00020\n2\u0006\u0010\"\u001a\u00020\bJ\u0018\u0010#\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\b\u0010$\u001a\u0004\u0018\u00010\u0016J\u0016\u0010%\u001a\u00020\u00062\u0006\u0010!\u001a\u00020\n2\u0006\u0010\"\u001a\u00020\bJ\u0016\u0010&\u001a\u00020\u00062\u0006\u0010!\u001a\u00020\n2\u0006\u0010\"\u001a\u00020\bJ\u0006\u0010\'\u001a\u00020\u0006J\"\u0010(\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\b\u0010)\u001a\u0004\u0018\u00010\u00162\b\u0010$\u001a\u0004\u0018\u00010\u0016J\"\u0010*\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\b\u0010\u0015\u001a\u0004\u0018\u00010\u00162\b\u0010\u0017\u001a\u0004\u0018\u00010\u0016J\u0016\u0010+\u001a\u00020\u00062\u0006\u0010,\u001a\u00020\n2\u0006\u0010\"\u001a\u00020\bJ\u0016\u0010-\u001a\u00020\u00062\u0006\u0010,\u001a\u00020\n2\u0006\u0010\"\u001a\u00020\bJ\"\u0010.\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\b\u0010/\u001a\u0004\u0018\u0001002\b\u00101\u001a\u0004\u0018\u000100J\u0016\u00102\u001a\u00020\u00062\u0006\u0010!\u001a\u00020\n2\u0006\u0010\"\u001a\u00020\bJ\u0016\u00103\u001a\u00020\u00062\u0006\u0010!\u001a\u00020\n2\u0006\u0010\"\u001a\u00020\bJ\"\u00104\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\b\u00105\u001a\u0004\u0018\u0001062\b\u00107\u001a\u0004\u0018\u000106J\"\u00108\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\b\u00109\u001a\u0004\u0018\u0001062\b\u0010:\u001a\u0004\u0018\u000106R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/listbuilder/ShadeListBuilderLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "logDuplicateSummary", "", "buildId", "", "groupKey", "", "existingKey", "newKey", "logDuplicateTopLevelKey", "topLevelKey", "logEndBuildList", "iterationCount", "topLevelEntries", "numChildren", "logEntryAttachStateChanged", "key", "prevParent", "Lcom/android/systemui/statusbar/notification/collection/GroupEntry;", "newParent", "logFilterChanged", "prevFilter", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifFilter;", "newFilter", "logFinalList", "entries", "", "Lcom/android/systemui/statusbar/notification/collection/ListEntry;", "logFinalizeFilterInvalidated", "name", "pipelineState", "logGroupPruningSuppressed", "keepingParent", "logNotifComparatorInvalidated", "logNotifSectionInvalidated", "logOnBuildList", "logParentChangeSuppressed", "suppressedParent", "logParentChanged", "logPreGroupFilterInvalidated", "filterName", "logPreRenderInvalidated", "logPromoterChanged", "prevPromoter", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifPromoter;", "newPromoter", "logPromoterInvalidated", "logReorderingAllowedInvalidated", "logSectionChangeSuppressed", "suppressedSection", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/NotifSection;", "assignedSection", "logSectionChanged", "prevSection", "newSection"})
public final class ShadeListBuilderLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logOnBuildList() {
    }
    
    public final void logEndBuildList(int iterationCount, int topLevelEntries, int numChildren) {
    }
    
    public final void logPreRenderInvalidated(@org.jetbrains.annotations.NotNull()
    java.lang.String filterName, int pipelineState) {
    }
    
    public final void logPreGroupFilterInvalidated(@org.jetbrains.annotations.NotNull()
    java.lang.String filterName, int pipelineState) {
    }
    
    public final void logReorderingAllowedInvalidated(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int pipelineState) {
    }
    
    public final void logPromoterInvalidated(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int pipelineState) {
    }
    
    public final void logNotifSectionInvalidated(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int pipelineState) {
    }
    
    public final void logNotifComparatorInvalidated(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int pipelineState) {
    }
    
    public final void logFinalizeFilterInvalidated(@org.jetbrains.annotations.NotNull()
    java.lang.String name, int pipelineState) {
    }
    
    public final void logDuplicateSummary(int buildId, @org.jetbrains.annotations.NotNull()
    java.lang.String groupKey, @org.jetbrains.annotations.NotNull()
    java.lang.String existingKey, @org.jetbrains.annotations.NotNull()
    java.lang.String newKey) {
    }
    
    public final void logDuplicateTopLevelKey(int buildId, @org.jetbrains.annotations.NotNull()
    java.lang.String topLevelKey) {
    }
    
    public final void logEntryAttachStateChanged(int buildId, @org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry prevParent, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry newParent) {
    }
    
    public final void logParentChanged(int buildId, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry prevParent, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry newParent) {
    }
    
    public final void logParentChangeSuppressed(int buildId, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry suppressedParent, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry keepingParent) {
    }
    
    public final void logGroupPruningSuppressed(int buildId, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.GroupEntry keepingParent) {
    }
    
    public final void logFilterChanged(int buildId, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter prevFilter, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter newFilter) {
    }
    
    public final void logPromoterChanged(int buildId, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter prevPromoter, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifPromoter newPromoter) {
    }
    
    public final void logSectionChanged(int buildId, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection prevSection, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection newSection) {
    }
    
    public final void logSectionChangeSuppressed(int buildId, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection suppressedSection, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection assignedSection) {
    }
    
    public final void logFinalList(@org.jetbrains.annotations.NotNull()
    java.util.List<? extends com.android.systemui.statusbar.notification.collection.ListEntry> entries) {
    }
    
    @javax.inject.Inject()
    public ShadeListBuilderLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.NotificationLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}