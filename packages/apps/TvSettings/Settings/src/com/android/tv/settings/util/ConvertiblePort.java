package com.android.tv.settings.util;

import android.content.Context;
import android.os.RemoteException;
import android.os.SystemProperties;
import android.util.Log;
import com.android.tv.settings.R;

public final class ConvertiblePort {
    private static final String TAG = "ConvertiblePortUtil";
    public static final String USB_PORT_MODE = "persist.vendor.convertible.usb.mode";

    private ConvertiblePort() {
    }

    public static final String getConvertiblePortSetting(Context context) {
        if (!context.getResources().getBoolean(R.bool.has_convertible_port)) {
            Log.d(TAG, "getConvertiblePortSetting: Non-valid platform");
            return "";
        }
        return SystemProperties.get(USB_PORT_MODE);
    }

    public static final int setConvertiblePortSetting(Context context, String mode) {
        if (!context.getResources().getBoolean(R.bool.has_convertible_port)) {
            Log.d(TAG, "setConvertiblePortSetting: Non-valid platform");
            return -1;
        }
        SystemProperties.set(USB_PORT_MODE, mode);
	return 0;
    }
}
