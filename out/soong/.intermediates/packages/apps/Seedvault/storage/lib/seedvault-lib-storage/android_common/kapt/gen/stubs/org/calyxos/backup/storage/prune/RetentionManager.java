package org.calyxos.backup.storage.prune;

import android.content.Context;
import org.calyxos.backup.storage.api.SnapshotRetention;
import org.calyxos.backup.storage.api.StoredSnapshot;
import java.io.IOException;
import java.time.LocalDate;
import java.time.temporal.ChronoField;
import java.time.temporal.Temporal;
import java.time.temporal.TemporalAdjuster;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\b\u0000\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0006\u0010\u0005\u001a\u00020\u0006J\u001a\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\b2\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\t0\bJ<\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\t0\b2\u0018\u0010\f\u001a\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\t\u0012\u0004\u0012\u00020\u000e0\r0\b2\u0006\u0010\u000f\u001a\u00020\u00102\n\b\u0002\u0010\u0011\u001a\u0004\u0018\u00010\u0012H\u0002J\u000e\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0006R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/prune/RetentionManager;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "getSnapshotRetention", "Lorg/calyxos/backup/storage/api/SnapshotRetention;", "getSnapshotsToDelete", "", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "storedSnapshots", "getToKeep", "pairs", "Lkotlin/Pair;", "Ljava/time/LocalDate;", "keep", "", "temporalAdjuster", "Ljava/time/temporal/TemporalAdjuster;", "setSnapshotRetention", "", "retention"})
public final class RetentionManager {
    private final android.content.Context context = null;
    
    public final void setSnapshotRetention(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.SnapshotRetention retention) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.api.SnapshotRetention getSnapshotRetention() {
        return null;
    }
    
    /**
     * Takes a list of [StoredSnapshot]s and returns a list of those
     * that can be deleted according to the current snapshot retention policy.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<org.calyxos.backup.storage.api.StoredSnapshot> getSnapshotsToDelete(@org.jetbrains.annotations.NotNull()
    java.util.List<org.calyxos.backup.storage.api.StoredSnapshot> storedSnapshots) {
        return null;
    }
    
    private final java.util.List<org.calyxos.backup.storage.api.StoredSnapshot> getToKeep(java.util.List<kotlin.Pair<org.calyxos.backup.storage.api.StoredSnapshot, java.time.LocalDate>> pairs, int keep, java.time.temporal.TemporalAdjuster temporalAdjuster) {
        return null;
    }
    
    public RetentionManager(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}