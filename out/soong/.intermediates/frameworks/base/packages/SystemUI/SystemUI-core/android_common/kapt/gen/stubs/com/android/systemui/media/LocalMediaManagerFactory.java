package com.android.systemui.media;

import android.content.Context;
import com.android.settingslib.bluetooth.LocalBluetoothManager;
import com.android.settingslib.media.InfoMediaManager;
import com.android.settingslib.media.LocalMediaManager;
import javax.inject.Inject;

/**
 * Factory to create [LocalMediaManager] objects.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\u0018\u00002\u00020\u0001B\u0019\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0006J\u000e\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0004\u001a\u0004\u0018\u00010\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/LocalMediaManagerFactory;", "", "context", "Landroid/content/Context;", "localBluetoothManager", "Lcom/android/settingslib/bluetooth/LocalBluetoothManager;", "(Landroid/content/Context;Lcom/android/settingslib/bluetooth/LocalBluetoothManager;)V", "create", "Lcom/android/settingslib/media/LocalMediaManager;", "packageName", ""})
public final class LocalMediaManagerFactory {
    private final android.content.Context context = null;
    private final com.android.settingslib.bluetooth.LocalBluetoothManager localBluetoothManager = null;
    
    /**
     * Creates a [LocalMediaManager] for the given package.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.settingslib.media.LocalMediaManager create(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName) {
        return null;
    }
    
    @javax.inject.Inject()
    public LocalMediaManagerFactory(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    com.android.settingslib.bluetooth.LocalBluetoothManager localBluetoothManager) {
        super();
    }
}