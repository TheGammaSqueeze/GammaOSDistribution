package com.android.systemui.media.dialog;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.text.TextUtils;
import android.util.Log;
import com.android.settingslib.media.MediaOutputConstants;
import javax.inject.Inject;

/**
 * BroadcastReceiver for handling media output intent
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u000f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0018\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/dialog/MediaOutputDialogReceiver;", "Landroid/content/BroadcastReceiver;", "mediaOutputDialogFactory", "Lcom/android/systemui/media/dialog/MediaOutputDialogFactory;", "(Lcom/android/systemui/media/dialog/MediaOutputDialogFactory;)V", "onReceive", "", "context", "Landroid/content/Context;", "intent", "Landroid/content/Intent;"})
public final class MediaOutputDialogReceiver extends android.content.BroadcastReceiver {
    private final com.android.systemui.media.dialog.MediaOutputDialogFactory mediaOutputDialogFactory = null;
    
    @java.lang.Override()
    public void onReceive(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.content.Intent intent) {
    }
    
    @javax.inject.Inject()
    public MediaOutputDialogReceiver(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.dialog.MediaOutputDialogFactory mediaOutputDialogFactory) {
        super();
    }
}