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

package com.android.car.telemetry.databroker;

import android.annotation.NonNull;
import android.car.telemetry.TelemetryProto;
import android.os.Handler;

import com.android.car.systeminterface.SystemStateInterface;
import com.android.car.telemetry.MetricsConfigStore;
import com.android.car.telemetry.sessioncontroller.SessionController;
import com.android.car.telemetry.systemmonitor.SystemMonitor;
import com.android.car.telemetry.systemmonitor.SystemMonitorEvent;

import java.time.Duration;

/**
 * DataBrokerController instantiates the DataBroker and manages what Publishers
 * it can read from based current system states and policies.
 */
public class DataBrokerController {

    /** Interface for report ready notifications. */
    public interface ReportReadyListener{
        /** Sends a notification when the metrics config reached a terminal state. */
        void onReportReady(@NonNull String metricsConfigName);
    }

    /**
     * Priorities range from 0 to 100, with 0 being the highest priority and 100 being the lowest.
     * A {@link ScriptExecutionTask} must have equal or higher priority than the threshold in order
     * to be executed.
     * The following constants are chosen with the idea that subscribers with a priority of 0
     * must be executed as soon as data is published regardless of system health conditions.
     * Otherwise {@link ScriptExecutionTask}s are executed from the highest priority to the lowest
     * subject to system health constraints from {@link SystemMonitor}.
     */
    public static final int TASK_PRIORITY_HI = 0;
    public static final int TASK_PRIORITY_MED = 50;
    public static final int TASK_PRIORITY_LOW = 100;

    private final DataBroker mDataBroker;
    private final Handler mTelemetryHandler;
    private final MetricsConfigStore mMetricsConfigStore;
    private final ReportReadyListener mReportReadyListener;
    private final SystemMonitor mSystemMonitor;
    private final SystemStateInterface mSystemStateInterface;
    private final SessionController mSessionController;

    public DataBrokerController(
            @NonNull DataBroker dataBroker,
            @NonNull Handler telemetryHandler,
            @NonNull MetricsConfigStore metricsConfigStore,
            @NonNull ReportReadyListener reportReadyListener,
            @NonNull SystemMonitor systemMonitor,
            @NonNull SystemStateInterface systemStateInterface,
            @NonNull SessionController sessionController) {
        mDataBroker = dataBroker;
        mTelemetryHandler = telemetryHandler;
        mMetricsConfigStore = metricsConfigStore;
        mReportReadyListener = reportReadyListener;
        mSystemMonitor = systemMonitor;
        mSystemStateInterface = systemStateInterface;
        mSessionController = sessionController;

        mDataBroker.setOnScriptFinishedCallback(
                metricsConfigName -> onScriptFinished(metricsConfigName));
        mSystemMonitor.setSystemMonitorCallback(this::onSystemMonitorEvent);
        mSystemStateInterface.scheduleActionForBootCompleted(
                this::startMetricsCollection, Duration.ZERO);
    }

    /**
     * Starts collecting data. Once data is sent by publishers, DataBroker will arrange scripts to
     * run. This method is called by some thread on executor service, therefore the work needs to
     * be posted on the telemetry thread.
     */
    private void startMetricsCollection() {
        mTelemetryHandler.post(() -> {
            for (TelemetryProto.MetricsConfig config :
                    mMetricsConfigStore.getActiveMetricsConfigs()) {
                mDataBroker.addMetricsConfig(config.getName(), config);
            }
            // By this point all publishers are instantiated according to the active configs
            // and subscribed to session updates. The publishers are ready to handle session updates
            // that this call might trigger.
            mSessionController.initSession();
        });
    }

    /**
     * Listens to script finished event from {@link DataBroker}.
     *
     * @param metricsConfigName the unique identifier of the config whose script finished.
     */
    public void onScriptFinished(@NonNull String metricsConfigName) {
        mMetricsConfigStore.removeMetricsConfig(metricsConfigName);
        mDataBroker.removeMetricsConfig(metricsConfigName);
        mReportReadyListener.onReportReady(metricsConfigName);
    }

    /**
     * Listens to {@link SystemMonitorEvent} and changes the cut-off priority
     * for {@link DataBroker} such that only tasks with the same or more urgent
     * priority can be run.
     *
     * Highest priority is 0 and lowest is 100.
     *
     * @param event the {@link SystemMonitorEvent} received.
     */
    public void onSystemMonitorEvent(@NonNull SystemMonitorEvent event) {
        if (event.getCpuUsageLevel() == SystemMonitorEvent.USAGE_LEVEL_HI
                || event.getMemoryUsageLevel() == SystemMonitorEvent.USAGE_LEVEL_HI) {
            mDataBroker.setTaskExecutionPriority(TASK_PRIORITY_HI);
        } else if (event.getCpuUsageLevel() == SystemMonitorEvent.USAGE_LEVEL_MED
                || event.getMemoryUsageLevel() == SystemMonitorEvent.USAGE_LEVEL_MED) {
            mDataBroker.setTaskExecutionPriority(TASK_PRIORITY_MED);
        } else {
            mDataBroker.setTaskExecutionPriority(TASK_PRIORITY_LOW);
        }
    }
}
