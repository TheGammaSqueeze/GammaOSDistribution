package com.android.systemui.controls.ui;

import android.annotation.ColorRes;
import android.annotation.MainThread;
import android.content.ComponentName;
import android.content.Context;
import android.graphics.drawable.Drawable;
import android.service.controls.DeviceTypes;
import android.service.controls.templates.TemperatureControlTemplate;
import android.util.ArrayMap;
import android.util.SparseArray;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0014\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0000\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"&\u0010\u0003\u001a\u001a\u0012\u0004\u0012\u00020\u0001\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\u00010\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u001a\u0010\u0006\u001a\u000e\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\u00010\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"BUCKET_SIZE", "", "THERMOSTAT_RANGE", "deviceColorMap", "", "Lkotlin/Pair;", "deviceIconMap"})
public final class RenderInfoKt {
    private static final int BUCKET_SIZE = 1000;
    private static final int THERMOSTAT_RANGE = 49000;
    private static final java.util.Map<java.lang.Integer, kotlin.Pair<java.lang.Integer, java.lang.Integer>> deviceColorMap = null;
    private static final java.util.Map<java.lang.Integer, java.lang.Integer> deviceIconMap = null;
}