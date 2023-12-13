package org.calyxos.backup.storage.api;

import org.calyxos.backup.storage.backup.BackupSnapshot;

/**
 * Defines which backup snapshots should be retained when pruning backups.
 *
 * If more than one snapshot exists in a given time frame,
 * only the latest one will be kept.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\u000f\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0003\u0012\u0006\u0010\u0006\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0007J\t\u0010\r\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u000e\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u000f\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0010\u001a\u00020\u0003H\u00c6\u0003J1\u0010\u0011\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u00032\b\b\u0002\u0010\u0006\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\u0012\u001a\u00020\u00132\b\u0010\u0014\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0015\u001a\u00020\u0003H\u00d6\u0001J\t\u0010\u0016\u001a\u00020\u0017H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0011\u0010\u0005\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\tR\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\tR\u0011\u0010\u0006\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\t"}, d2 = {"Lorg/calyxos/backup/storage/api/SnapshotRetention;", "", "daily", "", "weekly", "monthly", "yearly", "(IIII)V", "getDaily", "()I", "getMonthly", "getWeekly", "getYearly", "component1", "component2", "component3", "component4", "copy", "equals", "", "other", "hashCode", "toString", ""})
public final class SnapshotRetention {
    
    /**
     * Keep this many days worth of snapshots when pruning backups.
     */
    private final int daily = 0;
    
    /**
     * Keep this many weeks worth of snapshots when pruning backups.
     */
    private final int weekly = 0;
    
    /**
     * Keep this many months worth of snapshots when pruning backups.
     */
    private final int monthly = 0;
    
    /**
     * Keep this many years worth of snapshots when pruning backups.
     */
    private final int yearly = 0;
    
    /**
     * Keep this many days worth of snapshots when pruning backups.
     */
    public final int getDaily() {
        return 0;
    }
    
    /**
     * Keep this many weeks worth of snapshots when pruning backups.
     */
    public final int getWeekly() {
        return 0;
    }
    
    /**
     * Keep this many months worth of snapshots when pruning backups.
     */
    public final int getMonthly() {
        return 0;
    }
    
    /**
     * Keep this many years worth of snapshots when pruning backups.
     */
    public final int getYearly() {
        return 0;
    }
    
    public SnapshotRetention(int daily, int weekly, int monthly, int yearly) {
        super();
    }
    
    /**
     * Keep this many days worth of snapshots when pruning backups.
     */
    public final int component1() {
        return 0;
    }
    
    /**
     * Keep this many weeks worth of snapshots when pruning backups.
     */
    public final int component2() {
        return 0;
    }
    
    /**
     * Keep this many months worth of snapshots when pruning backups.
     */
    public final int component3() {
        return 0;
    }
    
    /**
     * Keep this many years worth of snapshots when pruning backups.
     */
    public final int component4() {
        return 0;
    }
    
    /**
     * Defines which backup snapshots should be retained when pruning backups.
     *
     * If more than one snapshot exists in a given time frame,
     * only the latest one will be kept.
     */
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.api.SnapshotRetention copy(int daily, int weekly, int monthly, int yearly) {
        return null;
    }
    
    /**
     * Defines which backup snapshots should be retained when pruning backups.
     *
     * If more than one snapshot exists in a given time frame,
     * only the latest one will be kept.
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Defines which backup snapshots should be retained when pruning backups.
     *
     * If more than one snapshot exists in a given time frame,
     * only the latest one will be kept.
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Defines which backup snapshots should be retained when pruning backups.
     *
     * If more than one snapshot exists in a given time frame,
     * only the latest one will be kept.
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}