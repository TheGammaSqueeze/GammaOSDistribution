package com.android.systemui.power;

import java.lang.System;

/**
 * A simple data class to snapshot battery state when a particular check for the
 * low battery warning is running in the background.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0007\n\u0002\u0010\t\n\u0002\b\'\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B?\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\u0003\u0012\u0006\u0010\b\u001a\u00020\u0003\u0012\u0006\u0010\t\u001a\u00020\u0003\u0012\u0006\u0010\n\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u000bBm\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\u0003\u0012\u0006\u0010\b\u001a\u00020\u0003\u0012\u0006\u0010\t\u001a\u00020\u0003\u0012\u0006\u0010\n\u001a\u00020\u0003\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\r\u0012\u0006\u0010\u000f\u001a\u00020\r\u0012\u0006\u0010\u0010\u001a\u00020\r\u0012\u0006\u0010\u0011\u001a\u00020\u0005\u0012\u0006\u0010\u0012\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0013J\t\u0010#\u001a\u00020\u0003H\u00c6\u0003J\t\u0010$\u001a\u00020\rH\u00c6\u0003J\t\u0010%\u001a\u00020\rH\u00c6\u0003J\t\u0010&\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\'\u001a\u00020\u0005H\u00c6\u0003J\t\u0010(\u001a\u00020\u0005H\u00c6\u0003J\t\u0010)\u001a\u00020\u0005H\u00c6\u0003J\t\u0010*\u001a\u00020\u0003H\u00c6\u0003J\t\u0010+\u001a\u00020\u0003H\u00c6\u0003J\t\u0010,\u001a\u00020\u0003H\u00c6\u0003J\t\u0010-\u001a\u00020\u0003H\u00c6\u0003J\t\u0010.\u001a\u00020\rH\u00c6\u0003J\t\u0010/\u001a\u00020\rH\u00c6\u0003J\u008b\u0001\u00100\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00052\b\b\u0002\u0010\u0007\u001a\u00020\u00032\b\b\u0002\u0010\b\u001a\u00020\u00032\b\b\u0002\u0010\t\u001a\u00020\u00032\b\b\u0002\u0010\n\u001a\u00020\u00032\b\b\u0002\u0010\f\u001a\u00020\r2\b\b\u0002\u0010\u000e\u001a\u00020\r2\b\b\u0002\u0010\u000f\u001a\u00020\r2\b\b\u0002\u0010\u0010\u001a\u00020\r2\b\b\u0002\u0010\u0011\u001a\u00020\u00052\b\b\u0002\u0010\u0012\u001a\u00020\u0005H\u00c6\u0001J\u0013\u00101\u001a\u00020\u00052\b\u00102\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u00103\u001a\u00020\u0003H\u00d6\u0001J\t\u00104\u001a\u000205H\u00d6\u0001R\u0011\u0010\u000e\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0015R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017R\u0011\u0010\b\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0017R\u0011\u0010\u0007\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0019\u0010\u0017R\u0011\u0010\u0011\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u001aR\u001e\u0010\u001c\u001a\u00020\u00052\u0006\u0010\u001b\u001a\u00020\u0005@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001c\u0010\u001aR\u0011\u0010\u0012\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u001aR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0004\u0010\u001aR\u0011\u0010\n\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u0017R\u0011\u0010\u0010\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001e\u0010\u0015R\u0011\u0010\u0006\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001f\u0010\u001aR\u0011\u0010\t\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b \u0010\u0017R\u0011\u0010\u000f\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\u0015R\u0011\u0010\f\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\"\u0010\u0015"}, d2 = {"Lcom/android/systemui/power/BatteryStateSnapshot;", "", "batteryLevel", "", "isPowerSaver", "", "plugged", "bucket", "batteryStatus", "severeLevelThreshold", "lowLevelThreshold", "(IZZIIII)V", "timeRemainingMillis", "", "averageTimeToDischargeMillis", "severeThresholdMillis", "lowThresholdMillis", "isBasedOnUsage", "isLowWarningEnabled", "(IZZIIIIJJJJZZ)V", "getAverageTimeToDischargeMillis", "()J", "getBatteryLevel", "()I", "getBatteryStatus", "getBucket", "()Z", "<set-?>", "isHybrid", "getLowLevelThreshold", "getLowThresholdMillis", "getPlugged", "getSevereLevelThreshold", "getSevereThresholdMillis", "getTimeRemainingMillis", "component1", "component10", "component11", "component12", "component13", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "equals", "other", "hashCode", "toString", ""})
public final class BatteryStateSnapshot {
    
    /**
     * Returns whether hybrid warning logic/copy should be used for this snapshot
     */
    private boolean isHybrid = false;
    private final int batteryLevel = 0;
    private final boolean isPowerSaver = false;
    private final boolean plugged = false;
    private final int bucket = 0;
    private final int batteryStatus = 0;
    private final int severeLevelThreshold = 0;
    private final int lowLevelThreshold = 0;
    private final long timeRemainingMillis = 0L;
    private final long averageTimeToDischargeMillis = 0L;
    private final long severeThresholdMillis = 0L;
    private final long lowThresholdMillis = 0L;
    private final boolean isBasedOnUsage = false;
    private final boolean isLowWarningEnabled = false;
    
    public final boolean isHybrid() {
        return false;
    }
    
    public final int getBatteryLevel() {
        return 0;
    }
    
    public final boolean isPowerSaver() {
        return false;
    }
    
    public final boolean getPlugged() {
        return false;
    }
    
    public final int getBucket() {
        return 0;
    }
    
    public final int getBatteryStatus() {
        return 0;
    }
    
    public final int getSevereLevelThreshold() {
        return 0;
    }
    
    public final int getLowLevelThreshold() {
        return 0;
    }
    
    public final long getTimeRemainingMillis() {
        return 0L;
    }
    
    public final long getAverageTimeToDischargeMillis() {
        return 0L;
    }
    
    public final long getSevereThresholdMillis() {
        return 0L;
    }
    
    public final long getLowThresholdMillis() {
        return 0L;
    }
    
    public final boolean isBasedOnUsage() {
        return false;
    }
    
    public final boolean isLowWarningEnabled() {
        return false;
    }
    
    public BatteryStateSnapshot(int batteryLevel, boolean isPowerSaver, boolean plugged, int bucket, int batteryStatus, int severeLevelThreshold, int lowLevelThreshold, long timeRemainingMillis, long averageTimeToDischargeMillis, long severeThresholdMillis, long lowThresholdMillis, boolean isBasedOnUsage, boolean isLowWarningEnabled) {
        super();
    }
    
    public BatteryStateSnapshot(int batteryLevel, boolean isPowerSaver, boolean plugged, int bucket, int batteryStatus, int severeLevelThreshold, int lowLevelThreshold) {
        super();
    }
    
    public final int component1() {
        return 0;
    }
    
    public final boolean component2() {
        return false;
    }
    
    public final boolean component3() {
        return false;
    }
    
    public final int component4() {
        return 0;
    }
    
    public final int component5() {
        return 0;
    }
    
    public final int component6() {
        return 0;
    }
    
    public final int component7() {
        return 0;
    }
    
    public final long component8() {
        return 0L;
    }
    
    public final long component9() {
        return 0L;
    }
    
    public final long component10() {
        return 0L;
    }
    
    public final long component11() {
        return 0L;
    }
    
    public final boolean component12() {
        return false;
    }
    
    public final boolean component13() {
        return false;
    }
    
    /**
     * A simple data class to snapshot battery state when a particular check for the
     * low battery warning is running in the background.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.power.BatteryStateSnapshot copy(int batteryLevel, boolean isPowerSaver, boolean plugged, int bucket, int batteryStatus, int severeLevelThreshold, int lowLevelThreshold, long timeRemainingMillis, long averageTimeToDischargeMillis, long severeThresholdMillis, long lowThresholdMillis, boolean isBasedOnUsage, boolean isLowWarningEnabled) {
        return null;
    }
    
    /**
     * A simple data class to snapshot battery state when a particular check for the
     * low battery warning is running in the background.
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * A simple data class to snapshot battery state when a particular check for the
     * low battery warning is running in the background.
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * A simple data class to snapshot battery state when a particular check for the
     * low battery warning is running in the background.
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}