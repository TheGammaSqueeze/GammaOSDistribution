package com.android.systemui.qs.logging;

import android.service.quicksettings.Tile;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.LogLevel;
import com.android.systemui.log.LogMessage;
import com.android.systemui.log.dagger.QSLog;
import com.android.systemui.plugins.qs.QSTile;
import com.android.systemui.statusbar.StatusBarState;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\t\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004JE\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0017\u0010\t\u001a\u0013\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\u00060\n\u00a2\u0006\u0002\b\f2\u0019\b\b\u0010\r\u001a\u0013\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\u000e0\n\u00a2\u0006\u0002\b\fH\u0082\bJ\u001e\u0010\u000f\u001a\u00020\u00062\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u000e2\u0006\u0010\u0013\u001a\u00020\u000eJ\u0016\u0010\u0014\u001a\u00020\u00062\u0006\u0010\u0015\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u000eJ\u000e\u0010\u0016\u001a\u00020\u00062\u0006\u0010\u0017\u001a\u00020\u000eJ\u0016\u0010\u0018\u001a\u00020\u00062\u0006\u0010\u0017\u001a\u00020\u000e2\u0006\u0010\u0010\u001a\u00020\u0011J\u001e\u0010\u0019\u001a\u00020\u00062\u0006\u0010\u0017\u001a\u00020\u000e2\u0006\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001bJ\u0016\u0010\u001d\u001a\u00020\u00062\u0006\u0010\u0017\u001a\u00020\u000e2\u0006\u0010\u001e\u001a\u00020\u000eJ\u001e\u0010\u001f\u001a\u00020\u00062\u0006\u0010\u0017\u001a\u00020\u000e2\u0006\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001bJ\u001e\u0010 \u001a\u00020\u00062\u0006\u0010\u0017\u001a\u00020\u000e2\u0006\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001bJ\u0016\u0010!\u001a\u00020\u00062\u0006\u0010\u0017\u001a\u00020\u000e2\u0006\u0010\u001c\u001a\u00020\"J\u0010\u0010#\u001a\u00020\u000e2\u0006\u0010\u001c\u001a\u00020\u001bH\u0002R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/logging/QSLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "log", "", "logLevel", "Lcom/android/systemui/log/LogLevel;", "initializer", "Lkotlin/Function1;", "Lcom/android/systemui/log/LogMessage;", "Lkotlin/ExtensionFunctionType;", "printer", "", "logAllTilesChangeListening", "listening", "", "containerName", "allSpecs", "logPanelExpanded", "expanded", "logTileAdded", "tileSpec", "logTileChangeListening", "logTileClick", "statusBarState", "", "state", "logTileDestroyed", "reason", "logTileLongClick", "logTileSecondaryClick", "logTileUpdated", "Lcom/android/systemui/plugins/qs/QSTile$State;", "toStateString"})
public final class QSLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logTileAdded(@org.jetbrains.annotations.NotNull()
    java.lang.String tileSpec) {
    }
    
    public final void logTileDestroyed(@org.jetbrains.annotations.NotNull()
    java.lang.String tileSpec, @org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
    }
    
    public final void logTileChangeListening(@org.jetbrains.annotations.NotNull()
    java.lang.String tileSpec, boolean listening) {
    }
    
    public final void logAllTilesChangeListening(boolean listening, @org.jetbrains.annotations.NotNull()
    java.lang.String containerName, @org.jetbrains.annotations.NotNull()
    java.lang.String allSpecs) {
    }
    
    public final void logTileClick(@org.jetbrains.annotations.NotNull()
    java.lang.String tileSpec, int statusBarState, int state) {
    }
    
    public final void logTileSecondaryClick(@org.jetbrains.annotations.NotNull()
    java.lang.String tileSpec, int statusBarState, int state) {
    }
    
    public final void logTileLongClick(@org.jetbrains.annotations.NotNull()
    java.lang.String tileSpec, int statusBarState, int state) {
    }
    
    public final void logTileUpdated(@org.jetbrains.annotations.NotNull()
    java.lang.String tileSpec, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSTile.State state) {
    }
    
    public final void logPanelExpanded(boolean expanded, @org.jetbrains.annotations.NotNull()
    java.lang.String containerName) {
    }
    
    private final java.lang.String toStateString(int state) {
        return null;
    }
    
    private final void log(com.android.systemui.log.LogLevel logLevel, kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, kotlin.Unit> initializer, kotlin.jvm.functions.Function1<? super com.android.systemui.log.LogMessage, java.lang.String> printer) {
    }
    
    @javax.inject.Inject()
    public QSLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.QSLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}