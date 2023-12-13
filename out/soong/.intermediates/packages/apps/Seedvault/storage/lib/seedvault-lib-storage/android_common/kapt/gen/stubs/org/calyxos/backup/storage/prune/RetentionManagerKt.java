package org.calyxos.backup.storage.prune;

import android.content.Context;
import org.calyxos.backup.storage.api.SnapshotRetention;
import org.calyxos.backup.storage.api.StoredSnapshot;
import java.io.IOException;
import java.time.LocalDate;
import java.time.temporal.ChronoField;
import java.time.temporal.Temporal;
import java.time.temporal.TemporalAdjuster;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0012\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0006\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0006\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0007\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\b\u001a\u00020\u0001X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\t\u001a\u00020\u0001X\u0080T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\n\u001a\u00020\u0001X\u0080T\u00a2\u0006\u0002\n\u0000"}, d2 = {"PREFS", "", "PREF_DAILY", "PREF_DEFAULT_DAILY", "", "PREF_DEFAULT_MONTHLY", "PREF_DEFAULT_WEEKLY", "PREF_DEFAULT_YEARLY", "PREF_MONTHLY", "PREF_WEEKLY", "PREF_YEARLY"})
public final class RetentionManagerKt {
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PREFS = "org.calyxos.backup.storage.prune.retention";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PREF_DAILY = "daily";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PREF_WEEKLY = "weekly";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PREF_MONTHLY = "monthly";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PREF_YEARLY = "yearly";
    public static final int PREF_DEFAULT_DAILY = 3;
    public static final int PREF_DEFAULT_WEEKLY = 2;
    public static final int PREF_DEFAULT_MONTHLY = 2;
    public static final int PREF_DEFAULT_YEARLY = 1;
}