package org.calyxos.backup.storage.api;

import org.calyxos.backup.storage.backup.BackupSnapshot;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b6\u0018\u00002\u00020\u0001:\u0002\u0003\u0004B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002\u0082\u0001\u0002\u0005\u0006"}, d2 = {"Lorg/calyxos/backup/storage/api/SnapshotResult;", "", "()V", "Error", "Success", "Lorg/calyxos/backup/storage/api/SnapshotResult$Success;", "Lorg/calyxos/backup/storage/api/SnapshotResult$Error;"})
public abstract class SnapshotResult {
    
    private SnapshotResult() {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0013\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\u0002\u0010\u0005J\u000f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u00c6\u0003J\u0019\u0010\t\u001a\u00020\u00002\u000e\b\u0002\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u00c6\u0001J\u0013\u0010\n\u001a\u00020\u000b2\b\u0010\f\u001a\u0004\u0018\u00010\rH\u00d6\u0003J\t\u0010\u000e\u001a\u00020\u000fH\u00d6\u0001J\t\u0010\u0010\u001a\u00020\u0011H\u00d6\u0001R\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007"}, d2 = {"Lorg/calyxos/backup/storage/api/SnapshotResult$Success;", "Lorg/calyxos/backup/storage/api/SnapshotResult;", "snapshots", "", "Lorg/calyxos/backup/storage/api/SnapshotItem;", "(Ljava/util/List;)V", "getSnapshots", "()Ljava/util/List;", "component1", "copy", "equals", "", "other", "", "hashCode", "", "toString", ""})
    public static final class Success extends org.calyxos.backup.storage.api.SnapshotResult {
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<org.calyxos.backup.storage.api.SnapshotItem> snapshots = null;
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<org.calyxos.backup.storage.api.SnapshotItem> getSnapshots() {
            return null;
        }
        
        public Success(@org.jetbrains.annotations.NotNull()
        java.util.List<org.calyxos.backup.storage.api.SnapshotItem> snapshots) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<org.calyxos.backup.storage.api.SnapshotItem> component1() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final org.calyxos.backup.storage.api.SnapshotResult.Success copy(@org.jetbrains.annotations.NotNull()
        java.util.List<org.calyxos.backup.storage.api.SnapshotItem> snapshots) {
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
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0011\u0012\n\u0010\u0002\u001a\u00060\u0003j\u0002`\u0004\u00a2\u0006\u0002\u0010\u0005J\r\u0010\b\u001a\u00060\u0003j\u0002`\u0004H\u00c6\u0003J\u0017\u0010\t\u001a\u00020\u00002\f\b\u0002\u0010\u0002\u001a\u00060\u0003j\u0002`\u0004H\u00c6\u0001J\u0013\u0010\n\u001a\u00020\u000b2\b\u0010\f\u001a\u0004\u0018\u00010\rH\u00d6\u0003J\t\u0010\u000e\u001a\u00020\u000fH\u00d6\u0001J\t\u0010\u0010\u001a\u00020\u0011H\u00d6\u0001R\u0015\u0010\u0002\u001a\u00060\u0003j\u0002`\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007"}, d2 = {"Lorg/calyxos/backup/storage/api/SnapshotResult$Error;", "Lorg/calyxos/backup/storage/api/SnapshotResult;", "e", "Ljava/lang/Exception;", "Lkotlin/Exception;", "(Ljava/lang/Exception;)V", "getE", "()Ljava/lang/Exception;", "component1", "copy", "equals", "", "other", "", "hashCode", "", "toString", ""})
    public static final class Error extends org.calyxos.backup.storage.api.SnapshotResult {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.Exception e = null;
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.Exception getE() {
            return null;
        }
        
        public Error(@org.jetbrains.annotations.NotNull()
        java.lang.Exception e) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.Exception component1() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final org.calyxos.backup.storage.api.SnapshotResult.Error copy(@org.jetbrains.annotations.NotNull()
        java.lang.Exception e) {
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
}