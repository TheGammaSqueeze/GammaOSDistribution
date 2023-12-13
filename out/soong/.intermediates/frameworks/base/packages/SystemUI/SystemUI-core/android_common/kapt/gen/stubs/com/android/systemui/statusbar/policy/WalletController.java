package com.android.systemui.statusbar.policy;

import java.lang.System;

/**
 * Supports adding a Quick Access Wallet QS tile
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\bf\u0018\u00002\u00020\u0001J\u000f\u0010\u0002\u001a\u0004\u0018\u00010\u0003H&\u00a2\u0006\u0002\u0010\u0004"}, d2 = {"Lcom/android/systemui/statusbar/policy/WalletController;", "", "getWalletPosition", "", "()Ljava/lang/Integer;"})
public abstract interface WalletController {
    
    /**
     * @return valid position or null to indicate no tile should be set
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Integer getWalletPosition();
}