/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.google.android.car.kitchensink.telemetry;

import static android.car.telemetry.TelemetryProto.StatsPublisher.SystemMetric.ACTIVITY_FOREGROUND_STATE_CHANGED;
import static android.car.telemetry.TelemetryProto.StatsPublisher.SystemMetric.ANR_OCCURRED;
import static android.car.telemetry.TelemetryProto.StatsPublisher.SystemMetric.APP_CRASH_OCCURRED;
import static android.car.telemetry.TelemetryProto.StatsPublisher.SystemMetric.APP_START_MEMORY_STATE_CAPTURED;
import static android.car.telemetry.TelemetryProto.StatsPublisher.SystemMetric.PROCESS_CPU_TIME;
import static android.car.telemetry.TelemetryProto.StatsPublisher.SystemMetric.PROCESS_MEMORY_STATE;
import static android.car.telemetry.TelemetryProto.StatsPublisher.SystemMetric.WTF_OCCURRED;

import android.annotation.NonNull;
import android.annotation.Nullable;
import android.app.ActivityManager;
import android.car.telemetry.CarTelemetryManager;
import android.car.telemetry.TelemetryProto;
import android.car.telemetry.TelemetryProto.ConnectivityPublisher;
import android.hardware.automotive.vehicle.V2_0.VehicleProperty;
import android.os.Bundle;
import android.os.PersistableBundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import androidx.fragment.app.Fragment;

import com.google.android.car.kitchensink.KitchenSinkActivity;
import com.google.android.car.kitchensink.R;
import com.google.protobuf.InvalidProtocolBufferException;

import java.io.IOException;
import java.io.InputStream;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;

public class CarTelemetryTestFragment extends Fragment {
    private static final String TAG = CarTelemetryTestFragment.class.getSimpleName();

    private static final int SCRIPT_EXECUTION_PRIORITY_HIGH = 0;
    private static final int SCRIPT_EXECUTION_PRIORITY_LOW = 100;

    /** Vehicle property via gear change section. */
    private static final String LUA_SCRIPT_ON_GEAR_CHANGE =
            "function onGearChange(published_data, state)\n"
                    + "    result = {data = \"Hello World!\"}\n"
                    + "    on_script_finished(result)\n"
                    + "end\n";

    private static final TelemetryProto.Publisher VEHICLE_PROPERTY_PUBLISHER =
            TelemetryProto.Publisher.newBuilder()
                    .setVehicleProperty(
                            TelemetryProto.VehiclePropertyPublisher.newBuilder()
                                    .setVehiclePropertyId(VehicleProperty.GEAR_SELECTION)
                                    .setReadRate(0f)
                                    .build())
                    .build();
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG_ON_GEAR_CHANGE_V1 =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("my_metrics_config")
                    .setVersion(1)
                    .setScript(LUA_SCRIPT_ON_GEAR_CHANGE)
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onGearChange")
                                    .setPublisher(VEHICLE_PROPERTY_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_LOW))
                    .build();
    private static final String ON_GEAR_CHANGE_CONFIG_NAME =
            METRICS_CONFIG_ON_GEAR_CHANGE_V1.getName();

    /** ProcessMemoryState section. */
    private static final String LUA_SCRIPT_ON_PROCESS_MEMORY_STATE = new StringBuilder()
            .append("function calculateAverage(tbl)\n")
            .append("    sum = 0\n")
            .append("    size = 0\n")
            .append("    for _, value in ipairs(tbl) do\n")
            .append("        sum = sum + value\n")
            .append("        size = size + 1\n")
            .append("    end\n")
            .append("    return sum/size\n")
            .append("end\n")
            .append("function onProcessMemory(published_data, state)\n")
            .append("    result = {}\n")
            .append("    result.page_fault_avg = calculateAverage(published_data.page_fault)\n")
            .append("    result.major_page_fault_avg = calculateAverage("
                    + "published_data.page_major_fault)\n")
            .append("    result.oom_adj_score_avg = calculateAverage("
                    + "published_data.oom_adj_score)\n")
            .append("    result.rss_in_bytes_avg = calculateAverage("
                    + "published_data.rss_in_bytes)\n")
            .append("    result.swap_in_bytes_avg = calculateAverage("
                    + "published_data.swap_in_bytes)\n")
            .append("    result.cache_in_bytes_avg = calculateAverage("
                    + "published_data.cache_in_bytes)\n")
            .append("    on_script_finished(result)\n")
            .append("end\n")
            .toString();
    private static final TelemetryProto.Publisher PROCESS_MEMORY_PUBLISHER =
            TelemetryProto.Publisher.newBuilder()
                    .setStats(
                            TelemetryProto.StatsPublisher.newBuilder()
                                    .setSystemMetric(PROCESS_MEMORY_STATE))
                    .build();
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG_PROCESS_MEMORY_V1 =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("process_memory_metrics_config")
                    .setVersion(1)
                    .setScript(LUA_SCRIPT_ON_PROCESS_MEMORY_STATE)
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onProcessMemory")
                                    .setPublisher(PROCESS_MEMORY_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .build();
    private static final String PROCESS_MEMORY_CONFIG_NAME =
            METRICS_CONFIG_PROCESS_MEMORY_V1.getName();

    /** AppStartMemoryStateCaptured section. */
    private static final String LUA_SCRIPT_ON_APP_START_MEMORY_STATE_CAPTURED = new StringBuilder()
            .append("function calculateAverage(tbl)\n")
            .append("    sum = 0\n")
            .append("    size = 0\n")
            .append("    for _, value in ipairs(tbl) do\n")
            .append("        sum = sum + value\n")
            .append("        size = size + 1\n")
            .append("    end\n")
            .append("    return sum/size\n")
            .append("end\n")
            .append("function onAppStartMemoryStateCaptured(published_data, state)\n")
            .append("    result = {}\n")
            .append("    result.uid = published_data.uid\n")
            .append("    result.page_fault_avg = calculateAverage(published_data.page_fault)\n")
            .append("    result.major_page_fault_avg = calculateAverage("
                    + "published_data.page_major_fault)\n")
            .append("    result.rss_in_bytes_avg = calculateAverage("
                    + "published_data.rss_in_bytes)\n")
            .append("    result.swap_in_bytes_avg = calculateAverage("
                    + "published_data.swap_in_bytes)\n")
            .append("    result.cache_in_bytes_avg = calculateAverage("
                    + "published_data.cache_in_bytes)\n")
            .append("    on_script_finished(result)\n")
            .append("end\n")
            .toString();
    private static final TelemetryProto.Publisher APP_START_MEMORY_STATE_CAPTURED_PUBLISHER =
            TelemetryProto.Publisher.newBuilder()
                    .setStats(
                            TelemetryProto.StatsPublisher.newBuilder()
                                    .setSystemMetric(APP_START_MEMORY_STATE_CAPTURED))
                    .build();
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG_APP_START_MEMORY_V1 =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("app_start_memory_metrics_config")
                    .setVersion(1)
                    .setScript(LUA_SCRIPT_ON_APP_START_MEMORY_STATE_CAPTURED)
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onAppStartMemoryStateCaptured")
                                    .setPublisher(APP_START_MEMORY_STATE_CAPTURED_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .build();
    private static final String APP_START_MEMORY_STATE_CAPTURED_CONFIG_NAME =
            METRICS_CONFIG_APP_START_MEMORY_V1.getName();

    /** ActivityForegroundStateChanged section. */
    private static final String LUA_SCRIPT_ON_ACTIVITY_FOREGROUND_STATE_CHANGED =
            new StringBuilder()
                    .append("function onActivityForegroundStateChanged(published_data, state)\n")
                    .append("    result = {}\n")
                    .append("    n = 0\n")
                    .append("    for k, v in pairs(published_data) do\n")
                    .append("        result[k] = v[1]\n")
                    .append("        n = n + 1\n")
                    .append("    end\n")
                    .append("    result.n = n\n")
                    .append("    on_script_finished(result)\n")
                    .append("end\n")
                    .toString();

    private static final TelemetryProto.Publisher ACTIVITY_FOREGROUND_STATE_CHANGED_PUBLISHER =
            TelemetryProto.Publisher.newBuilder()
                    .setStats(
                            TelemetryProto.StatsPublisher.newBuilder()
                                    .setSystemMetric(ACTIVITY_FOREGROUND_STATE_CHANGED))
                    .build();
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG_ACTIVITY_FOREGROUND_STATE_V1 =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("activity_foreground_state_changed_config")
                    .setVersion(1)
                    .setScript(LUA_SCRIPT_ON_ACTIVITY_FOREGROUND_STATE_CHANGED)
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onActivityForegroundStateChanged")
                                    .setPublisher(ACTIVITY_FOREGROUND_STATE_CHANGED_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .build();
    private static final String ACTIVITY_FOREGROUND_STATE_CHANGED_CONFIG_NAME =
            METRICS_CONFIG_ACTIVITY_FOREGROUND_STATE_V1.getName();

    /** ProcessCpuTime section */
    private static final String LUA_SCRIPT_ON_PROCESS_CPU_TIME =
            new StringBuilder()
                    .append("function onProcessCpuTime(published_data, state)\n")
                    .append("    result = {}\n")
                    .append("    n = 0\n")
                    .append("    for k, v in pairs(published_data) do\n")
                    .append("        result[k] = v[1]\n")
                    .append("        n = n + 1\n")
                    .append("    end\n")
                    .append("    result.n = n\n")
                    .append("    on_script_finished(result)\n")
                    .append("end\n")
                    .toString();

    private static final TelemetryProto.Publisher PROCESS_CPU_TIME_PUBLISHER =
            TelemetryProto.Publisher.newBuilder()
                    .setStats(
                            TelemetryProto.StatsPublisher.newBuilder()
                                    .setSystemMetric(PROCESS_CPU_TIME))
                    .build();
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG_PROCESS_CPU_TIME_V1 =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("process_cpu_time_config")
                    .setVersion(1)
                    .setScript(LUA_SCRIPT_ON_PROCESS_CPU_TIME)
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onProcessCpuTime")
                                    .setPublisher(PROCESS_CPU_TIME_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .build();
    private static final String PROCESS_CPU_TIME_CONFIG_NAME =
            METRICS_CONFIG_PROCESS_CPU_TIME_V1.getName();

    /** AppCrashOccurred section */
    private static final String LUA_SCRIPT_ON_APP_CRASH_OCCURRED =
            new StringBuilder()
                    .append("function onAppCrashOccurred(published_data, state)\n")
                    .append("    result = {}\n")
                    .append("    for k, v in pairs(published_data) do\n")
                    .append("        result[k] = v[1]\n")
                    .append("    end\n")
                    .append("    on_script_finished(result)\n")
                    .append("end\n")
                    .toString();

    private static final TelemetryProto.Publisher APP_CRASH_OCCURRED_PUBLISHER =
            TelemetryProto.Publisher.newBuilder()
                    .setStats(
                            TelemetryProto.StatsPublisher.newBuilder()
                                    .setSystemMetric(APP_CRASH_OCCURRED))
                    .build();
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG_APP_CRASH_OCCURRED_V1 =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("app_crash_occurred_config")
                    .setVersion(1)
                    .setScript(LUA_SCRIPT_ON_APP_CRASH_OCCURRED)
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onAppCrashOccurred")
                                    .setPublisher(APP_CRASH_OCCURRED_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .build();
    private static final String APP_CRASH_OCCURRED_CONFIG_NAME =
            METRICS_CONFIG_APP_CRASH_OCCURRED_V1.getName();

    /** ANROccurred section */
    private static final String LUA_SCRIPT_ON_ANR_OCCURRED =
            new StringBuilder()
                    .append("function onAnrOccurred(published_data, state)\n")
                    .append("    result = {}\n")
                    .append("    for k, v in pairs(published_data) do\n")
                    .append("        result[k] = v[1]\n")
                    .append("    end\n")
                    .append("    on_script_finished(result)\n")
                    .append("end\n")
                    .toString();

    private static final TelemetryProto.Publisher ANR_OCCURRED_PUBLISHER =
            TelemetryProto.Publisher.newBuilder()
                    .setStats(
                            TelemetryProto.StatsPublisher.newBuilder()
                                    .setSystemMetric(ANR_OCCURRED))
                    .build();
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG_ANR_OCCURRED_V1 =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("anr_occurred_config")
                    .setVersion(1)
                    .setScript(LUA_SCRIPT_ON_ANR_OCCURRED)
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onAnrOccurred")
                                    .setPublisher(ANR_OCCURRED_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .build();
    private static final String ANR_OCCURRED_CONFIG_NAME = METRICS_CONFIG_ANR_OCCURRED_V1.getName();

    /** WTFOccurred section */
    private static final String LUA_SCRIPT_ON_WTF_OCCURRED =
            new StringBuilder()
                    .append("function onWtfOccurred(published_data, state)\n")
                    .append("    result = {}\n")
                    .append("    for k, v in pairs(published_data) do\n")
                    .append("        result[k] = v[1]\n")
                    .append("    end\n")
                    .append("    on_script_finished(result)\n")
                    .append("end\n")
                    .toString();

    private static final TelemetryProto.Publisher WTF_OCCURRED_PUBLISHER =
            TelemetryProto.Publisher.newBuilder()
                    .setStats(
                            TelemetryProto.StatsPublisher.newBuilder()
                                    .setSystemMetric(WTF_OCCURRED))
                    .build();
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG_WTF_OCCURRED_V1 =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("wtf_occurred_config")
                    .setVersion(1)
                    .setScript(LUA_SCRIPT_ON_WTF_OCCURRED)
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onWtfOccurred")
                                    .setPublisher(WTF_OCCURRED_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .build();
    private static final String WTF_OCCURRED_CONFIG_NAME = METRICS_CONFIG_WTF_OCCURRED_V1.getName();

    /** Wifi Netstats */
    private static final String LUA_SCRIPT_ON_WIFI_NETSTATS =
            new StringBuilder()
                    .append("function onWifiNetstats(published_data, state)\n")
                    .append("    on_script_finished(published_data)\n")
                    .append("end\n")
                    .toString();

    private static final TelemetryProto.Publisher WIFI_NETSTATS_PUBLISHER =
            TelemetryProto.Publisher.newBuilder()
                    .setConnectivity(
                            ConnectivityPublisher.newBuilder()
                                    .setTransport(ConnectivityPublisher.Transport.TRANSPORT_WIFI)
                                    .setOemType(ConnectivityPublisher.OemType.OEM_NONE))
                    .build();
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG_WIFI_NETSTATS =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("wifi_netstats_config")
                    .setVersion(1)
                    .setScript(LUA_SCRIPT_ON_WIFI_NETSTATS)
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onWifiNetstats")
                                    .setPublisher(WIFI_NETSTATS_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .build();
    private static final String WIFI_NETSTATS_CONFIG_NAME = METRICS_CONFIG_WIFI_NETSTATS.getName();

    /**
     * PROCESS_CPU_TIME + PROCESS_MEMORY + WIFI_NETSTATS section. Reuses the same publisher
     * configuration that were defined above for PROCESS_CPU_TIME, PROCESS_MEMORY, and
     * WIFI_NETSTATS. Its script is R.raw.telemetry_stats_and_connectivity_script which is loaded at
     * runtime. The script produces a final report when it receives atoms PROCESS_MEMORY and
     * PROCESS_CPU_TIME, and more than 5 pieces of data from connectivity publisher.
     */
    private static final TelemetryProto.MetricsConfig METRICS_CONFIG_STATS_AND_CONNECTIVITY_V1 =
            TelemetryProto.MetricsConfig.newBuilder()
                    .setName("stats_and_connectivity_metrics_config")
                    .setVersion(1)
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onProcessMemory")
                                    .setPublisher(PROCESS_MEMORY_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onProcessCpuTime")
                                    .setPublisher(PROCESS_CPU_TIME_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .addSubscribers(
                            TelemetryProto.Subscriber.newBuilder()
                                    .setHandler("onWifiNetstats")
                                    .setPublisher(WIFI_NETSTATS_PUBLISHER)
                                    .setPriority(SCRIPT_EXECUTION_PRIORITY_HIGH))
                    .build();

    private static final String STATS_AND_CONNECTIVITY_CONFIG_NAME =
            METRICS_CONFIG_STATS_AND_CONNECTIVITY_V1.getName();

    private final Executor mExecutor = Executors.newSingleThreadExecutor();

    private boolean mReceiveReportNotification = false;
    private CarTelemetryManager mCarTelemetryManager;
    private FinishedReportListenerImpl mListener;
    private AddMetricsConfigCallbackImpl mAddMetricsConfigCallback;
    private KitchenSinkActivity mActivity;
    private TextView mOutputTextView;
    private Button mTootleConfigsBtn;
    private Button mEnableReportNotificationButton;
    private View mConfigButtonsView; // MetricsConfig buttons

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        mActivity = (KitchenSinkActivity) getActivity();
        mCarTelemetryManager = mActivity.getCarTelemetryManager();
        mListener = new FinishedReportListenerImpl();
        mAddMetricsConfigCallback = new AddMetricsConfigCallbackImpl();
        super.onCreate(savedInstanceState);
    }

    @Nullable
    @Override
    public View onCreateView(
            @NonNull LayoutInflater inflater,
            @Nullable ViewGroup container,
            @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.car_telemetry_test, container, false);
        mOutputTextView = view.findViewById(R.id.output_textview);
        mConfigButtonsView = view.findViewById(R.id.metrics_config_buttons_view);
        mTootleConfigsBtn = view.findViewById(R.id.toggle_metrics_configs_btn);
        mTootleConfigsBtn.setOnClickListener(this::toggleMetricsConfigButtons);
        mEnableReportNotificationButton = view.findViewById(R.id.enable_report_notification_btn);
        mEnableReportNotificationButton.setOnClickListener(this::enableReportNotification);
        mEnableReportNotificationButton.setText(
                getString(R.string.receive_report_notification_text, mReceiveReportNotification));

        /** VehiclePropertyPublisher on_gear_change */
        view.findViewById(R.id.send_on_gear_change_config)
                .setOnClickListener(this::onSendGearChangeConfigBtnClick);
        view.findViewById(R.id.remove_on_gear_change_config)
                .setOnClickListener(this::onRemoveGearChangeConfigBtnClick);
        view.findViewById(R.id.get_on_gear_change_report)
                .setOnClickListener(this::onGetGearChangeReportBtnClick);
        /** StatsPublisher process_memory */
        view.findViewById(R.id.send_on_process_memory_config)
                .setOnClickListener(this::onSendProcessMemoryConfigBtnClick);
        view.findViewById(R.id.remove_on_process_memory_config)
                .setOnClickListener(this::onRemoveProcessMemoryConfigBtnClick);
        view.findViewById(R.id.get_on_process_memory_report)
                .setOnClickListener(this::onGetProcessMemoryReportBtnClick);
        /** StatsPublisher app_start_memory_state */
        view.findViewById(R.id.send_on_app_start_memory_state_captured_config)
                .setOnClickListener(this::onSendAppStartMemoryStateCapturedConfigBtnClick);
        view.findViewById(R.id.remove_on_app_start_memory_state_captured_config)
                .setOnClickListener(this::onRemoveAppStartMemoryStateCapturedConfigBtnClick);
        view.findViewById(R.id.get_on_app_start_memory_state_captured_report)
                .setOnClickListener(this::onGetAppStartMemoryStateCapturedReportBtnClick);
        /** StatsPublisher activity_foreground_state_change */
        view.findViewById(R.id.send_on_activity_foreground_state_changed_config)
                .setOnClickListener(this::onSendActivityForegroundStateChangedConfigBtnClick);
        view.findViewById(R.id.remove_on_activity_foreground_state_changed_config)
                .setOnClickListener(this::onRemoveActivityForegroundStateChangedConfigBtnClick);
        view.findViewById(R.id.get_on_activity_foreground_state_changed_report)
                .setOnClickListener(this::onGetActivityForegroundStateChangedReportBtnClick);
        /** StatsPublisher process_cpu_time */
        view.findViewById(R.id.send_on_process_cpu_time_config)
                .setOnClickListener(this::onSendProcessCpuTimeConfigBtnClick);
        view.findViewById(R.id.remove_on_process_cpu_time_config)
                .setOnClickListener(this::onRemoveProcessCpuTimeConfigBtnClick);
        view.findViewById(R.id.get_on_process_cpu_time_report)
                .setOnClickListener(this::onGetProcessCpuTimeReportBtnClick);
        /** StatsPublisher AppCrashOccurred section */
        view.findViewById(R.id.send_on_app_crash_occurred_config)
                .setOnClickListener(this::onSendAppCrashOccurredConfigBtnClick);
        view.findViewById(R.id.remove_on_app_crash_occurred_config)
                .setOnClickListener(this::onRemoveAppCrashOccurredConfigBtnClick);
        view.findViewById(R.id.get_on_app_crash_occurred_report)
                .setOnClickListener(this::onGetAppCrashOccurredReportBtnClick);
        /** StatsPublisher ANROccurred section */
        view.findViewById(R.id.send_on_anr_occurred_config)
                .setOnClickListener(this::onSendAnrOccurredConfigBtnClick);
        view.findViewById(R.id.remove_on_anr_occurred_config)
                .setOnClickListener(this::onRemoveAnrOccurredConfigBtnClick);
        view.findViewById(R.id.get_on_anr_occurred_report)
                .setOnClickListener(this::onGetAnrOccurredReportBtnClick);
        /** StatsPublisher WTFOccurred section */
        view.findViewById(R.id.send_on_wtf_occurred_config)
                .setOnClickListener(this::onSendWtfOccurredConfigBtnClick);
        view.findViewById(R.id.remove_on_wtf_occurred_config)
                .setOnClickListener(this::onRemoveWtfOccurredConfigBtnClick);
        view.findViewById(R.id.get_on_wtf_occurred_report)
                .setOnClickListener(this::onGetWtfOccurredReportBtnClick);
        /** ConnectivityPublisher wifi_netstats section */
        view.findViewById(R.id.send_on_wifi_netstats_config)
                .setOnClickListener(this::onSendWifiNetstatsConfigBtnClick);
        view.findViewById(R.id.remove_on_wifi_netstats_config)
                .setOnClickListener(this::onRemoveWifiNetstatsConfigBtnClick);
        view.findViewById(R.id.get_on_wifi_netstats_report)
                .setOnClickListener(this::onGetWifiNetstatsReportBtnClick);
        /** StatsPublisher + ConnectivityPublisher section */
        view.findViewById(R.id.send_stats_and_connectivity_config)
                .setOnClickListener(this::onSendStatsAndConnectivityConfigBtnClick);
        view.findViewById(R.id.remove_stats_and_connectivity_config)
                .setOnClickListener(this::onRemoveStatsAndConnectivityConfigBtnClick);
        view.findViewById(R.id.get_stats_and_connectivity_report)
                .setOnClickListener(this::onGetStatsAndConnectivityReportBtnClick);
        /** Print mem info button */
        view.findViewById(R.id.print_mem_info_btn).setOnClickListener(this::onPrintMemInfoBtnClick);
        return view;
    }

    private void showOutput(String s) {
        String now = LocalDateTime.now().format(DateTimeFormatter.ofPattern("HH:mm:ss.SSS"));
        String text = now + " : " + s;
        Log.i(TAG, text);
        mActivity.runOnUiThread(
                () -> {
                    mOutputTextView.setText(text + "\n" + mOutputTextView.getText());
                });
    }

    private void toggleMetricsConfigButtons(View view) {
        boolean visible = mConfigButtonsView.getVisibility() == View.VISIBLE;
        mConfigButtonsView.setVisibility(visible ? View.GONE : View.VISIBLE);
        mTootleConfigsBtn.setText(visible ? "Configs ▶" : "Configs ▼");
    }

    private void enableReportNotification(View view) {
        mReceiveReportNotification = !mReceiveReportNotification;
        mEnableReportNotificationButton.setText(
                getString(R.string.receive_report_notification_text, mReceiveReportNotification));
        if (mReceiveReportNotification) {
            mCarTelemetryManager.setReportReadyListener(mExecutor, this::onReportReady);
        } else {
            mCarTelemetryManager.clearReportReadyListener();
        }
    }

    /** Implementation of functional interface {@link CarTelemetryManager.ReportReadyListener}. */
    private void onReportReady(@NonNull String metricsConfigName) {
        String s = "Report for MetricsConfig " + metricsConfigName + " is ready.";
        showOutput(s);
    }

    private void onSendGearChangeConfigBtnClick(View view) {
        mCarTelemetryManager.addMetricsConfig(
                ON_GEAR_CHANGE_CONFIG_NAME,
                METRICS_CONFIG_ON_GEAR_CHANGE_V1.toByteArray(),
                mExecutor,
                mAddMetricsConfigCallback);
    }

    private void onRemoveGearChangeConfigBtnClick(View view) {
        showOutput("Removing MetricsConfig that listens for gear change...");
        mCarTelemetryManager.removeMetricsConfig(ON_GEAR_CHANGE_CONFIG_NAME);
    }

    private void onGetGearChangeReportBtnClick(View view) {
        mCarTelemetryManager.getFinishedReport(ON_GEAR_CHANGE_CONFIG_NAME, mExecutor, mListener);
    }

    private void onSendProcessMemoryConfigBtnClick(View view) {
        mCarTelemetryManager.addMetricsConfig(
                PROCESS_MEMORY_CONFIG_NAME,
                METRICS_CONFIG_PROCESS_MEMORY_V1.toByteArray(),
                mExecutor,
                mAddMetricsConfigCallback);
    }

    private void onRemoveProcessMemoryConfigBtnClick(View view) {
        showOutput("Removing MetricsConfig that listens for PROCESS_MEMORY_STATE...");
        mCarTelemetryManager.removeMetricsConfig(PROCESS_MEMORY_CONFIG_NAME);
    }

    private void onGetProcessMemoryReportBtnClick(View view) {
        mCarTelemetryManager.getFinishedReport(PROCESS_MEMORY_CONFIG_NAME, mExecutor, mListener);
    }

    private void onSendAppStartMemoryStateCapturedConfigBtnClick(View view) {
        mCarTelemetryManager.addMetricsConfig(
                APP_START_MEMORY_STATE_CAPTURED_CONFIG_NAME,
                METRICS_CONFIG_APP_START_MEMORY_V1.toByteArray(),
                mExecutor,
                mAddMetricsConfigCallback);
    }

    private void onRemoveAppStartMemoryStateCapturedConfigBtnClick(View view) {
        showOutput("Removing MetricsConfig that listens for APP_START_MEMORY_STATE_CAPTURED...");
        mCarTelemetryManager.removeMetricsConfig(APP_START_MEMORY_STATE_CAPTURED_CONFIG_NAME);
    }

    private void onGetAppStartMemoryStateCapturedReportBtnClick(View view) {
        mCarTelemetryManager.getFinishedReport(
                APP_START_MEMORY_STATE_CAPTURED_CONFIG_NAME, mExecutor, mListener);
    }

    private void onSendActivityForegroundStateChangedConfigBtnClick(View view) {
        mCarTelemetryManager.addMetricsConfig(
                ACTIVITY_FOREGROUND_STATE_CHANGED_CONFIG_NAME,
                METRICS_CONFIG_ACTIVITY_FOREGROUND_STATE_V1.toByteArray(),
                mExecutor,
                mAddMetricsConfigCallback);
    }

    private void onRemoveActivityForegroundStateChangedConfigBtnClick(View view) {
        showOutput("Removing MetricsConfig that listens for ACTIVITY_FOREGROUND_STATE_CHANGED...");
        mCarTelemetryManager.removeMetricsConfig(ACTIVITY_FOREGROUND_STATE_CHANGED_CONFIG_NAME);
    }

    private void onGetActivityForegroundStateChangedReportBtnClick(View view) {
        mCarTelemetryManager.getFinishedReport(
                ACTIVITY_FOREGROUND_STATE_CHANGED_CONFIG_NAME, mExecutor, mListener);
    }

    private void onSendProcessCpuTimeConfigBtnClick(View view) {
        mCarTelemetryManager.addMetricsConfig(
                PROCESS_CPU_TIME_CONFIG_NAME,
                METRICS_CONFIG_PROCESS_CPU_TIME_V1.toByteArray(),
                mExecutor,
                mAddMetricsConfigCallback);
    }

    private void onRemoveProcessCpuTimeConfigBtnClick(View view) {
        showOutput("Removing MetricsConfig that listens for PROCESS_CPU_TIME...");
        mCarTelemetryManager.removeMetricsConfig(PROCESS_CPU_TIME_CONFIG_NAME);
    }

    private void onGetProcessCpuTimeReportBtnClick(View view) {
        mCarTelemetryManager.getFinishedReport(PROCESS_CPU_TIME_CONFIG_NAME, mExecutor, mListener);
    }

    private void onSendAppCrashOccurredConfigBtnClick(View view) {
        mCarTelemetryManager.addMetricsConfig(
                APP_CRASH_OCCURRED_CONFIG_NAME,
                METRICS_CONFIG_APP_CRASH_OCCURRED_V1.toByteArray(),
                mExecutor,
                mAddMetricsConfigCallback);
    }

    private void onRemoveAppCrashOccurredConfigBtnClick(View view) {
        showOutput("Removing MetricsConfig that listens for APP_CRASH_OCCURRED...");
        mCarTelemetryManager.removeMetricsConfig(APP_CRASH_OCCURRED_CONFIG_NAME);
    }

    private void onGetAppCrashOccurredReportBtnClick(View view) {
        mCarTelemetryManager.getFinishedReport(
                APP_CRASH_OCCURRED_CONFIG_NAME, mExecutor, mListener);
    }

    private void onSendAnrOccurredConfigBtnClick(View view) {
        mCarTelemetryManager.addMetricsConfig(
                ANR_OCCURRED_CONFIG_NAME,
                METRICS_CONFIG_ANR_OCCURRED_V1.toByteArray(),
                mExecutor,
                mAddMetricsConfigCallback);
    }

    private void onRemoveAnrOccurredConfigBtnClick(View view) {
        showOutput("Removing MetricsConfig that listens for ANR_OCCURRED...");
        mCarTelemetryManager.removeMetricsConfig(ANR_OCCURRED_CONFIG_NAME);
    }

    private void onGetAnrOccurredReportBtnClick(View view) {
        mCarTelemetryManager.getFinishedReport(ANR_OCCURRED_CONFIG_NAME, mExecutor, mListener);
    }

    private void onSendWtfOccurredConfigBtnClick(View view) {
        mCarTelemetryManager.addMetricsConfig(
                WTF_OCCURRED_CONFIG_NAME,
                METRICS_CONFIG_WTF_OCCURRED_V1.toByteArray(),
                mExecutor,
                mAddMetricsConfigCallback);
    }

    private void onRemoveWtfOccurredConfigBtnClick(View view) {
        showOutput("Removing MetricsConfig that listens for WTF_OCCURRED...");
        mCarTelemetryManager.removeMetricsConfig(WTF_OCCURRED_CONFIG_NAME);
    }

    private void onGetWtfOccurredReportBtnClick(View view) {
        mCarTelemetryManager.getFinishedReport(WTF_OCCURRED_CONFIG_NAME, mExecutor, mListener);
    }

    private void onSendWifiNetstatsConfigBtnClick(View view) {
        mCarTelemetryManager.addMetricsConfig(
                WIFI_NETSTATS_CONFIG_NAME,
                METRICS_CONFIG_WIFI_NETSTATS.toByteArray(),
                mExecutor,
                mAddMetricsConfigCallback);
    }

    private void onRemoveWifiNetstatsConfigBtnClick(View view) {
        showOutput("Removing MetricsConfig that listens for wifi netstats...");
        mCarTelemetryManager.removeMetricsConfig(WIFI_NETSTATS_CONFIG_NAME);
    }

    private void onGetWifiNetstatsReportBtnClick(View view) {
        mCarTelemetryManager.getFinishedReport(WIFI_NETSTATS_CONFIG_NAME, mExecutor, mListener);
    }

    private void onSendStatsAndConnectivityConfigBtnClick(View view) {
        String luaScript;
        try (InputStream is =
                getResources().openRawResource(R.raw.telemetry_stats_and_connectivity_script)) {
            byte[] bytes = new byte[is.available()];
            is.read(bytes);
            luaScript = new String(bytes);
        } catch (IOException e) {
            showOutput(
                    "Unable to send MetricsConfig that combines Memory and CPU atoms, because "
                            + "reading Lua script from file failed.");
            return;
        }
        TelemetryProto.MetricsConfig config =
                METRICS_CONFIG_STATS_AND_CONNECTIVITY_V1.toBuilder().setScript(luaScript).build();
        mCarTelemetryManager.addMetricsConfig(
                STATS_AND_CONNECTIVITY_CONFIG_NAME,
                config.toByteArray(),
                mExecutor,
                mAddMetricsConfigCallback);
    }

    private void onRemoveStatsAndConnectivityConfigBtnClick(View view) {
        showOutput("Removing MetricsConfig that listens for stats data & connectivity data...");
        mCarTelemetryManager.removeMetricsConfig(STATS_AND_CONNECTIVITY_CONFIG_NAME);
    }

    private void onGetStatsAndConnectivityReportBtnClick(View view) {
        mCarTelemetryManager.getFinishedReport(
                STATS_AND_CONNECTIVITY_CONFIG_NAME, mExecutor, mListener);
    }

    /** Gets a MemoryInfo object for the device's current memory status. */
    private ActivityManager.MemoryInfo getAvailableMemory() {
        ActivityManager activityManager = getActivity().getSystemService(ActivityManager.class);
        ActivityManager.MemoryInfo memoryInfo = new ActivityManager.MemoryInfo();
        activityManager.getMemoryInfo(memoryInfo);
        return memoryInfo;
    }

    private void onPrintMemInfoBtnClick(View view) {
        // Use android's "alloc-stress" system tool to create an artificial memory pressure.
        ActivityManager.MemoryInfo info = getAvailableMemory();
        showOutput("MemoryInfo availMem=" + (info.availMem / 1024 / 1024) + "/"
                + (info.totalMem / 1024 / 1024) + "mb, isLowMem=" + info.lowMemory
                + ", threshold=" + (info.threshold / 1024 / 1024) + "mb");
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
    }

    /**
     * Updates the view to show {@link CarTelemetryManager#addMetricsConfig(String, byte[],
     * Executor, CarTelemetryManager.AddMetricsConfigCallback)} status code. The callbacks are
     * executed in {@link #mExecutor}.
     */
    private final class AddMetricsConfigCallbackImpl
            implements CarTelemetryManager.AddMetricsConfigCallback {

        @Override
        public void onAddMetricsConfigStatus(@NonNull String metricsConfigName, int statusCode) {
            showOutput("Add MetricsConfig status for " + metricsConfigName + ": "
                    + statusCodeToString(statusCode));
        }

        private String statusCodeToString(int statusCode) {
            switch (statusCode) {
                case CarTelemetryManager.STATUS_ADD_METRICS_CONFIG_SUCCEEDED:
                    return "SUCCESS";
                case CarTelemetryManager.STATUS_ADD_METRICS_CONFIG_ALREADY_EXISTS:
                    return "ERROR ALREADY_EXISTS";
                case CarTelemetryManager.STATUS_ADD_METRICS_CONFIG_VERSION_TOO_OLD:
                    return "ERROR VERSION_TOO_OLD";
                case CarTelemetryManager.STATUS_ADD_METRICS_CONFIG_PARSE_FAILED:
                    return "ERROR PARSE_FAILED";
                case CarTelemetryManager.STATUS_ADD_METRICS_CONFIG_SIGNATURE_VERIFICATION_FAILED:
                    return "ERROR SIGNATURE_VERIFICATION_FAILED";
                default:
                    return "ERROR UNKNOWN";
            }
        }
    }

    /**
     * Implementation of the {@link CarTelemetryManager.MetricsReportCallback}. They update the view
     * to show the outputs from the APIs of {@link CarTelemetryManager}. The callbacks are executed
     * in {@link mExecutor}.
     */
    private final class FinishedReportListenerImpl implements
            CarTelemetryManager.MetricsReportCallback {

        @Override
        public void onResult(
                @NonNull String metricsConfigName,
                @Nullable PersistableBundle report,
                @Nullable byte[] telemetryError,
                @CarTelemetryManager.MetricsReportStatus int status) {
            if (report != null) {
                StringBuilder sb = new StringBuilder("PersistableBundle[\n");
                for (String key : report.keySet()) {
                    sb.append("    " + key + ": " + report.get(key) + ",\n");
                }
                sb.append("]");
                showOutput("Result for " + metricsConfigName + ": " + sb.toString());
            } else if (telemetryError != null) {
                parseError(metricsConfigName, telemetryError);
            } else {
                showOutput("No report exists for MetricsConfig " + metricsConfigName
                        + ", reason = " + statusCodeToString(status));
            }
        }

        private void parseError(@NonNull String metricsConfigName, @NonNull byte[] error) {
            try {
                TelemetryProto.TelemetryError telemetryError =
                        TelemetryProto.TelemetryError.parseFrom(error);
                showOutput("Error for " + metricsConfigName + ": " + telemetryError);
            } catch (InvalidProtocolBufferException e) {
                showOutput("Unable to parse error result for MetricsConfig " + metricsConfigName
                        + ": " + e.getMessage());
            }
        }

        private String statusCodeToString(int statusCode) {
            switch (statusCode) {
                case CarTelemetryManager.STATUS_GET_METRICS_CONFIG_FINISHED:
                    return "REPORT RETRIEVED";
                case CarTelemetryManager.STATUS_GET_METRICS_CONFIG_PENDING:
                    return "REPORT PENDING";
                case CarTelemetryManager.STATUS_GET_METRICS_CONFIG_INTERIM_RESULTS:
                    return "INTERIM RESULT EXISTS";
                case CarTelemetryManager.STATUS_GET_METRICS_CONFIG_RUNTIME_ERROR:
                    return "RUNTIME ERROR";
                case CarTelemetryManager.STATUS_GET_METRICS_CONFIG_DOES_NOT_EXIST:
                    return "METRICS CONFIG DOES NOT EXIST";
                default:
                    return "INVALID STATUS CODE";
            }
        }
    }
}
