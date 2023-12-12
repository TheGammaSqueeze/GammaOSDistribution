package com.android.systemui.statusbar;

import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

/**
 * A singleton that creates concise but readable strings representing the values of the disable
 * flags for debugging.
 *
 * See [CommandQueue.disable] for information about disable flags.
 *
 * Note that, for both lists passed in, each flag must have a distinct [DisableFlag.flagIsSetSymbol]
 * and distinct [DisableFlag.flagNotSetSymbol] within the list. If this isn't true, the logs could
 * be ambiguous so an [IllegalArgumentException] is thrown.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\b\u0007\u0018\u00002\u00020\u0001:\u0002\u0015\u0016B\u0007\b\u0017\u00a2\u0006\u0002\u0010\u0002B!\u0012\f\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004\u0012\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004\u00a2\u0006\u0002\u0010\u0007J\u0016\u0010\b\u001a\u00020\t2\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004H\u0002J\u0018\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u000eH\u0002J&\u0010\u0010\u001a\u00020\f2\n\b\u0002\u0010\r\u001a\u0004\u0018\u00010\u000e2\u0006\u0010\u000f\u001a\u00020\u000e2\n\b\u0002\u0010\u0011\u001a\u0004\u0018\u00010\u000eJ\u0010\u0010\u0012\u001a\u00020\f2\u0006\u0010\u0013\u001a\u00020\u000eH\u0002J\u0018\u0010\u0014\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u000eH\u0002R\u0014\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/DisableFlagsLogger;", "", "()V", "disable1FlagsList", "", "Lcom/android/systemui/statusbar/DisableFlagsLogger$DisableFlag;", "disable2FlagsList", "(Ljava/util/List;Ljava/util/List;)V", "flagsListHasDuplicateSymbols", "", "list", "getDiffString", "", "old", "Lcom/android/systemui/statusbar/DisableFlagsLogger$DisableState;", "new", "getDisableFlagsString", "newAfterLocalModification", "getFlagsString", "state", "getFlagsStringWithDiff", "DisableFlag", "DisableState"})
@com.android.systemui.dagger.SysUISingleton()
public final class DisableFlagsLogger {
    private final java.util.List<com.android.systemui.statusbar.DisableFlagsLogger.DisableFlag> disable1FlagsList = null;
    private final java.util.List<com.android.systemui.statusbar.DisableFlagsLogger.DisableFlag> disable2FlagsList = null;
    
    private final boolean flagsListHasDuplicateSymbols(java.util.List<com.android.systemui.statusbar.DisableFlagsLogger.DisableFlag> list) {
        return false;
    }
    
    /**
     * Returns a string representing the, old, new, and new-after-modification disable flag states,
     * as well as the differences between each of the states.
     *
     * Example:
     *  Old: EnaiHbcRso.qINgr | New: EnaihBcRso.qiNGR (hB.iGR) | New after local modification:
     *  EnaihBcRso.qInGR (.n)
     *
     * A capital character signifies the flag is set and a lowercase character signifies that the
     * flag isn't set. The flag states will be logged in the same order as the passed-in lists.
     *
     * The difference between states is written between parentheses, and won't be included if there
     * is no difference. the new-after-modification state also won't be included if there's no
     * difference from the new state.
     *
     * @param old the disable state that had been previously sent. Null if we don't need to log the
     *  previously sent state.
     * @param new the new disable state that has just been sent.
     * @param newAfterLocalModification the new disable states after a class has locally modified
     *  them. Null if the class does not locally modify.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getDisableFlagsString(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.DisableFlagsLogger.DisableState old, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.DisableFlagsLogger.DisableState p1_54480, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.DisableFlagsLogger.DisableState newAfterLocalModification) {
        return null;
    }
    
    /**
     * Returns a string representing [new] state, as well as the difference from [old] to [new]
     * (if there is one).
     */
    private final java.lang.String getFlagsStringWithDiff(com.android.systemui.statusbar.DisableFlagsLogger.DisableState old, com.android.systemui.statusbar.DisableFlagsLogger.DisableState p1_54480) {
        return null;
    }
    
    /**
     * Returns a string representing the difference between [old] and [new], or an empty string if
     * there is no difference.
     *
     * For example, if old was "abc.DE" and new was "aBC.De", the difference returned would be
     * "(BC.e)".
     */
    private final java.lang.String getDiffString(com.android.systemui.statusbar.DisableFlagsLogger.DisableState old, com.android.systemui.statusbar.DisableFlagsLogger.DisableState p1_54480) {
        return null;
    }
    
    /**
     * Returns a string representing the disable flag states, e.g. "EnaihBcRso.qiNGR".
     */
    private final java.lang.String getFlagsString(com.android.systemui.statusbar.DisableFlagsLogger.DisableState state) {
        return null;
    }
    
    public DisableFlagsLogger(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.statusbar.DisableFlagsLogger.DisableFlag> disable1FlagsList, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.statusbar.DisableFlagsLogger.DisableFlag> disable2FlagsList) {
        super();
    }
    
    @javax.inject.Inject()
    public DisableFlagsLogger() {
        super();
    }
    
    /**
     * A POJO representing each disable flag.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\f\n\u0002\b\u0005\u0018\u00002\u00020\u0001B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0007J\u0015\u0010\b\u001a\u00020\u00052\u0006\u0010\t\u001a\u00020\u0003H\u0000\u00a2\u0006\u0002\b\nR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/DisableFlagsLogger$DisableFlag;", "", "bitMask", "", "flagIsSetSymbol", "", "flagNotSetSymbol", "(ICC)V", "getFlagStatus", "state", "getFlagStatus$main"})
    public static final class DisableFlag {
        private final int bitMask = 0;
        private final char flagIsSetSymbol = '\u0000';
        private final char flagNotSetSymbol = '\u0000';
        
        /**
         * Returns a character representing whether or not this flag is set in [state].
         *
         * A capital character signifies the flag is set and a lowercase character signifies that
         * the flag isn't set.
         */
        public final char getFlagStatus$main(int state) {
            return '\u0000';
        }
        
        public DisableFlag(int bitMask, char flagIsSetSymbol, char flagNotSetSymbol) {
            super();
        }
    }
    
    /**
     * POJO to hold [disable1] and [disable2].
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0005J\t\u0010\t\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\n\u001a\u00020\u0003H\u00c6\u0003J\u001d\u0010\u000b\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\f\u001a\u00020\r2\b\u0010\u000e\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u000f\u001a\u00020\u0003H\u00d6\u0001J\t\u0010\u0010\u001a\u00020\u0011H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007R\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\u0007"}, d2 = {"Lcom/android/systemui/statusbar/DisableFlagsLogger$DisableState;", "", "disable1", "", "disable2", "(II)V", "getDisable1", "()I", "getDisable2", "component1", "component2", "copy", "equals", "", "other", "hashCode", "toString", ""})
    public static final class DisableState {
        private final int disable1 = 0;
        private final int disable2 = 0;
        
        public final int getDisable1() {
            return 0;
        }
        
        public final int getDisable2() {
            return 0;
        }
        
        public DisableState(int disable1, int disable2) {
            super();
        }
        
        public final int component1() {
            return 0;
        }
        
        public final int component2() {
            return 0;
        }
        
        /**
         * POJO to hold [disable1] and [disable2].
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.statusbar.DisableFlagsLogger.DisableState copy(int disable1, int disable2) {
            return null;
        }
        
        /**
         * POJO to hold [disable1] and [disable2].
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * POJO to hold [disable1] and [disable2].
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * POJO to hold [disable1] and [disable2].
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
}