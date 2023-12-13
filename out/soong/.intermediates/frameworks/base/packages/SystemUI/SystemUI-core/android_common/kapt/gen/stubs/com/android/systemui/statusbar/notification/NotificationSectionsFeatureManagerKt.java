package com.android.systemui.statusbar.notification;

import android.content.Context;
import android.provider.DeviceConfig;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.util.DeviceConfigProxy;
import com.android.systemui.util.Utils;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\u001a\u0010\u0010\u0003\u001a\u00020\u00012\u0006\u0010\u0004\u001a\u00020\u0005H\u0002\"\u0012\u0010\u0000\u001a\u0004\u0018\u00010\u0001X\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u0002"}, d2 = {"sUsePeopleFiltering", "", "Ljava/lang/Boolean;", "usePeopleFiltering", "proxy", "Lcom/android/systemui/util/DeviceConfigProxy;"})
public final class NotificationSectionsFeatureManagerKt {
    private static java.lang.Boolean sUsePeopleFiltering;
    
    private static final boolean usePeopleFiltering(com.android.systemui.util.DeviceConfigProxy proxy) {
        return false;
    }
}