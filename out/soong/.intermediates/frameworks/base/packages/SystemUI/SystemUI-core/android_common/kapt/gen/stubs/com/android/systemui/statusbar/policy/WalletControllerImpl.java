package com.android.systemui.statusbar.policy;

import android.service.quickaccesswallet.QuickAccessWalletClient;
import android.util.Log;
import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

/**
 * Check if the wallet service is available for use, and place the tile.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\b\u0007\u0018\u0000 \b2\u00020\u0001:\u0001\bB\u000f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000f\u0010\u0005\u001a\u0004\u0018\u00010\u0006H\u0016\u00a2\u0006\u0002\u0010\u0007R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/WalletControllerImpl;", "Lcom/android/systemui/statusbar/policy/WalletController;", "quickAccessWalletClient", "Landroid/service/quickaccesswallet/QuickAccessWalletClient;", "(Landroid/service/quickaccesswallet/QuickAccessWalletClient;)V", "getWalletPosition", "", "()Ljava/lang/Integer;", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class WalletControllerImpl implements com.android.systemui.statusbar.policy.WalletController {
    private final android.service.quickaccesswallet.QuickAccessWalletClient quickAccessWalletClient = null;
    private static final java.lang.String TAG = "WalletControllerImpl";
    public static final int QS_PRIORITY_POSITION = 3;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.policy.WalletControllerImpl.Companion Companion = null;
    
    /**
     * @return QS_PRIORITY_POSITION or null to indicate no tile should be set
     */
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Integer getWalletPosition() {
        return null;
    }
    
    @javax.inject.Inject()
    public WalletControllerImpl(@org.jetbrains.annotations.NotNull()
    android.service.quickaccesswallet.QuickAccessWalletClient quickAccessWalletClient) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/WalletControllerImpl$Companion;", "", "()V", "QS_PRIORITY_POSITION", "", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}