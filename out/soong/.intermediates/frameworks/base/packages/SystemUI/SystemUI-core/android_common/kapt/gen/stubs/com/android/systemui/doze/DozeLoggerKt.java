package com.android.systemui.doze;

import android.view.Display;
import com.android.systemui.doze.DozeLog.Reason;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.dagger.DozeLog;
import com.android.systemui.statusbar.policy.DevicePostureController;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000e\"\u0011\u0010\u0000\u001a\u00020\u0001\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0002\u0010\u0003\"\u000e\u0010\u0004\u001a\u00020\u0005X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DATE_FORMAT", "Ljava/text/SimpleDateFormat;", "getDATE_FORMAT", "()Ljava/text/SimpleDateFormat;", "TAG", ""})
public final class DozeLoggerKt {
    private static final java.lang.String TAG = "DozeLog";
    @org.jetbrains.annotations.NotNull()
    private static final java.text.SimpleDateFormat DATE_FORMAT = null;
    
    @org.jetbrains.annotations.NotNull()
    public static final java.text.SimpleDateFormat getDATE_FORMAT() {
        return null;
    }
}