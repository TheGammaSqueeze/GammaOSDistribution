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
import android.annotation.Nullable;
import android.car.telemetry.TelemetryProto;
import android.car.telemetry.TelemetryProto.MetricsConfig;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.IBinder;
import android.os.Looper;
import android.os.Message;
import android.os.ParcelFileDescriptor;
import android.os.PersistableBundle;
import android.os.RemoteException;
import android.os.UserHandle;
import android.util.ArrayMap;
import android.util.TimingsTraceLog;

import com.android.car.CarLog;
import com.android.car.CarServiceUtils;
import com.android.car.telemetry.CarTelemetryService;
import com.android.car.telemetry.ResultStore;
import com.android.car.telemetry.publisher.AbstractPublisher;
import com.android.car.telemetry.publisher.PublisherFactory;
import com.android.car.telemetry.scriptexecutorinterface.IScriptExecutor;
import com.android.car.telemetry.scriptexecutorinterface.IScriptExecutorListener;
import com.android.car.telemetry.util.IoUtils;
import com.android.internal.annotations.VisibleForTesting;
import com.android.server.utils.Slogf;

import java.io.IOException;
import java.io.OutputStream;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.PriorityBlockingQueue;

/**
 * Implementation of the data path component of CarTelemetryService. Forwards the published data
 * from publishers to consumers subject to the Controller's decision.
 * All methods should be called from the telemetry thread unless otherwise specified as thread-safe.
 */
public class DataBrokerImpl implements DataBroker {

    @VisibleForTesting
    static final int MSG_HANDLE_TASK = 1;
    @VisibleForTesting
    static final int MSG_BIND_TO_SCRIPT_EXECUTOR = 2;
    @VisibleForTesting
    static final int MSG_STOP_HANGING_SCRIPT = 3;

    /** Bind to script executor 5 times before entering disabled state. */
    private static final int MAX_BIND_SCRIPT_EXECUTOR_ATTEMPTS = 5;

    /** Maximum wait time for a script to finish. */
    private static final long MAX_SCRIPT_EXECUTION_TIME_MILLIS = 30_000L; // 30 seconds

    private static final String SCRIPT_EXECUTOR_PACKAGE = "com.android.car.scriptexecutor";
    private static final String SCRIPT_EXECUTOR_CLASS =
            "com.android.car.scriptexecutor.ScriptExecutor";

    private final Context mContext;
    private final PublisherFactory mPublisherFactory;
    private final ResultStore mResultStore;
    private final ScriptExecutorListener mScriptExecutorListener;
    private final HandlerThread mTelemetryThread = CarServiceUtils.getHandlerThread(
            CarTelemetryService.class.getSimpleName());
    private final Handler mTelemetryHandler = new TaskHandler(mTelemetryThread.getLooper());

    /** Thread-safe priority queue for scheduling tasks. */
    private final PriorityBlockingQueue<ScriptExecutionTask> mTaskQueue =
            new PriorityBlockingQueue<>();

    /**
     * Maps MetricsConfig name to its subscriptions. This map is useful for removing MetricsConfigs.
     */
    private final ArrayMap<String, List<DataSubscriber>> mSubscriptionMap = new ArrayMap<>();

    /**
     * If something irrecoverable happened, DataBroker should enter into a disabled state to prevent
     * doing futile work.
     */
    private boolean mDisabled = false;

    /** Current number of attempts to bind to ScriptExecutor. */
    private int mBindScriptExecutorAttempts = 0;

    /** Priority of current system to determine if a {@link ScriptExecutionTask} can run. */
    private int mPriority = 1;

    /** Waiting period between attempts to bind script executor. Can be shortened for tests. */
    @VisibleForTesting long mBindScriptExecutorDelayMillis = 3_000L;

    /**
     * Name of the {@link MetricsConfig} that is currently running.
     * A non-null value indicates ScriptExecutor is currently running this config, which means
     * DataBroker should not make another ScriptExecutor binder call.
     */
    private String mCurrentMetricsConfigName;
    private IScriptExecutor mScriptExecutor;
    private ScriptFinishedCallback mScriptFinishedCallback;

    /**
     * Used only for the purpose of tracking the duration of running a script. The duration
     * starts before the ScriptExecutor binder call and ends when a status is returned via
     * ScriptExecutorListener or when the binder call throws an exception.
     */
    private TimingsTraceLog mScriptExecutionTraceLog;

    private final ServiceConnection mServiceConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            mTelemetryHandler.post(() -> {
                mScriptExecutor = IScriptExecutor.Stub.asInterface(service);
                scheduleNextTask();
            });
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
            // TODO(b/198684473): clean up the state after script executor disconnects
            mTelemetryHandler.post(() -> {
                unbindScriptExecutor();
            });
        }
    };

    public DataBrokerImpl(
            @NonNull Context context,
            @NonNull PublisherFactory publisherFactory,
            @NonNull ResultStore resultStore,
            @NonNull TimingsTraceLog traceLog) {
        mContext = context;
        mPublisherFactory = publisherFactory;
        mResultStore = resultStore;
        mScriptExecutorListener = new ScriptExecutorListener(this);
        mPublisherFactory.initialize(this::onPublisherFailure);
        mScriptExecutionTraceLog = traceLog;
    }

    private void onPublisherFailure(
            @NonNull AbstractPublisher publisher,
            @NonNull List<TelemetryProto.MetricsConfig> affectedConfigs,
            @Nullable Throwable error) {
        // TODO(b/193680465): disable MetricsConfig and log the error
        Slogf.w(CarLog.TAG_TELEMETRY, "publisher failed", error);
    }

    private void bindScriptExecutor() {
        // do not re-bind if broker is in a disabled state or if script executor is nonnull
        if (mDisabled || mScriptExecutor != null) {
            return;
        }
        Intent intent = new Intent();
        intent.setComponent(new ComponentName(SCRIPT_EXECUTOR_PACKAGE, SCRIPT_EXECUTOR_CLASS));
        boolean success = mContext.bindServiceAsUser(
                intent,
                mServiceConnection,
                Context.BIND_AUTO_CREATE,
                UserHandle.SYSTEM);
        if (success) {
            mBindScriptExecutorAttempts = 0; // reset
            return;
        }
        unbindScriptExecutor();
        mBindScriptExecutorAttempts++;
        if (mBindScriptExecutorAttempts < MAX_BIND_SCRIPT_EXECUTOR_ATTEMPTS) {
            Slogf.w(CarLog.TAG_TELEMETRY,
                    "failed to get valid connection to ScriptExecutor, retrying in "
                            + mBindScriptExecutorDelayMillis + "ms.");
            mTelemetryHandler.sendEmptyMessageDelayed(MSG_BIND_TO_SCRIPT_EXECUTOR,
                    mBindScriptExecutorDelayMillis);
        } else {
            Slogf.w(CarLog.TAG_TELEMETRY, "failed to get valid connection to ScriptExecutor, "
                    + "disabling DataBroker");
            disableBroker();
        }
    }

    /**
     * Unbinds {@link ScriptExecutor} to release the connection. This method should be called from
     * the telemetry thread.
     */
    private void unbindScriptExecutor() {
        // TODO(b/198648763): unbind from script executor when there is no work to do
        // if a script is running while we unbind from ScriptExecutor, end trace log first
        if (mCurrentMetricsConfigName != null) {
            mScriptExecutionTraceLog.traceEnd();
            mCurrentMetricsConfigName = null;
        }
        mScriptExecutor = null;
        try {
            mContext.unbindService(mServiceConnection);
        } catch (IllegalArgumentException e) {
            // If ScriptExecutor is gone before unbinding, it will throw this exception
            Slogf.w(CarLog.TAG_TELEMETRY, "Failed to unbind from ScriptExecutor", e);
        }
    }

    /**
     * Enters into a disabled state because something irrecoverable happened.
     * TODO(b/200841260): expose the state to the caller.
     */
    private void disableBroker() {
        mDisabled = true;
        // remove all MetricConfigs, disable all publishers, stop receiving data
        for (String configName : mSubscriptionMap.keySet()) {
            // get the metrics config from the DataSubscriber and remove the metrics config
            if (mSubscriptionMap.get(configName).size() != 0) {
                removeMetricsConfig(configName);
            }
        }
        mSubscriptionMap.clear();
    }

    @Override
    public void addMetricsConfig(
            @NonNull String metricsConfigName, @NonNull MetricsConfig metricsConfig) {
        // TODO(b/187743369): pass status back to caller
        // if broker is disabled or metricsConfig already exists, do nothing
        if (mDisabled || mSubscriptionMap.containsKey(metricsConfigName)) {
            return;
        }
        // Create the subscribers for this metrics configuration
        List<DataSubscriber> dataSubscribers = new ArrayList<>(
                metricsConfig.getSubscribersList().size());
        for (TelemetryProto.Subscriber subscriber : metricsConfig.getSubscribersList()) {
            // protobuf publisher to a concrete Publisher
            AbstractPublisher publisher = mPublisherFactory.getPublisher(
                    subscriber.getPublisher().getPublisherCase());
            // create DataSubscriber from TelemetryProto.Subscriber
            DataSubscriber dataSubscriber = new DataSubscriber(
                    this,
                    metricsConfig,
                    subscriber);
            dataSubscribers.add(dataSubscriber);

            try {
                // The publisher will start sending data to the subscriber.
                // TODO(b/191378559): handle bad configs
                publisher.addDataSubscriber(dataSubscriber);
            } catch (IllegalArgumentException e) {
                Slogf.w(CarLog.TAG_TELEMETRY, "Invalid config", e);
                return;
            }
        }
        mSubscriptionMap.put(metricsConfigName, dataSubscribers);
    }

    @Override
    public void removeMetricsConfig(@NonNull String metricsConfigName) {
        // TODO(b/187743369): pass status back to caller
        if (!mSubscriptionMap.containsKey(metricsConfigName)) {
            return;
        }
        // get the subscriptions associated with this MetricsConfig, remove it from the map
        List<DataSubscriber> dataSubscribers = mSubscriptionMap.remove(metricsConfigName);
        // for each subscriber, remove it from publishers
        for (DataSubscriber subscriber : dataSubscribers) {
            AbstractPublisher publisher = mPublisherFactory.getPublisher(
                    subscriber.getPublisherParam().getPublisherCase());
            try {
                publisher.removeDataSubscriber(subscriber);
            } catch (IllegalArgumentException e) {
                // It shouldn't happen, but if happens, let's just log it.
                Slogf.w(CarLog.TAG_TELEMETRY, "Failed to remove subscriber from publisher", e);
            }
        }
        // Remove all the tasks associated with this metrics config. The underlying impl uses the
        // weakly consistent iterator, which is thread-safe but does not freeze the collection while
        // iterating, so it may or may not reflect any updates since the iterator was created.
        // But since adding & polling from queue should happen in the same thread, the task queue
        // should not be changed while tasks are being iterated and removed.
        mTaskQueue.removeIf(task -> task.isAssociatedWithMetricsConfig(metricsConfigName));
    }

    @Override
    public void removeAllMetricsConfigs() {
        mPublisherFactory.removeAllDataSubscribers();
        mSubscriptionMap.clear();
        mTaskQueue.clear();
    }

    @Override
    public void addTaskToQueue(@NonNull ScriptExecutionTask task) {
        if (mDisabled) {
            return;
        }
        mTaskQueue.add(task);
        scheduleNextTask();
    }

    /**
     * This method can be called from any thread.
     * It is possible for this method to be invoked from different threads at the same time, but
     * it is not possible to schedule the same task twice, because the handler handles message
     * in the order they come in, this means the task will be polled sequentially instead of
     * concurrently. Every task that is scheduled and run will be distinct.
     * TODO(b/187743369): If the threading behavior in DataSubscriber changes, ScriptExecutionTask
     *  will also have different threading behavior. Update javadoc when the behavior is decided.
     */
    @Override
    public void scheduleNextTask() {
        if (mDisabled || mTelemetryHandler.hasMessages(MSG_HANDLE_TASK)) {
            return;
        }
        mTelemetryHandler.sendEmptyMessage(MSG_HANDLE_TASK);
    }

    @Override
    public void setOnScriptFinishedCallback(@NonNull ScriptFinishedCallback callback) {
        if (mDisabled) {
            return;
        }
        mScriptFinishedCallback = callback;
    }

    @Override
    public void setTaskExecutionPriority(int priority) {
        if (mDisabled) {
            return;
        }
        mPriority = priority;
        scheduleNextTask(); // when priority updates, schedule a task which checks task queue
    }

    @VisibleForTesting
    @NonNull
    ArrayMap<String, List<DataSubscriber>> getSubscriptionMap() {
        return new ArrayMap<>(mSubscriptionMap);
    }

    @VisibleForTesting
    @NonNull
    Handler getTelemetryHandler() {
        return mTelemetryHandler;
    }

    @VisibleForTesting
    @NonNull
    PriorityBlockingQueue<ScriptExecutionTask> getTaskQueue() {
        return mTaskQueue;
    }

    /**
     * Polls and runs a task from the head of the priority queue if the queue is nonempty and the
     * head of the queue has priority higher than or equal to the current priority. A higher
     * priority is denoted by a lower priority number, so head of the queue should have equal or
     * lower priority number to be polled.
     */
    private void pollAndExecuteTask() {
        // check databroker state is ready to run script
        if (mDisabled || mCurrentMetricsConfigName != null) {
            return;
        }
        // check task is valid and ready to be run
        ScriptExecutionTask task = mTaskQueue.peek();
        if (task == null || task.getPriority() > mPriority) {
            return;
        }
        // if script executor is null, bind service
        if (mScriptExecutor == null) {
            Slogf.w(CarLog.TAG_TELEMETRY, "script executor is null, binding to script executor");
            // upon successful binding, a task will be scheduled to run if there are any
            mTelemetryHandler.sendEmptyMessage(MSG_BIND_TO_SCRIPT_EXECUTOR);
            return;
        }
        mTaskQueue.poll(); // remove task from queue
        // update current config name because a script is currently running
        mCurrentMetricsConfigName = task.getMetricsConfig().getName();
        mScriptExecutionTraceLog.traceBegin(
                "executing script " + mCurrentMetricsConfigName);
        try {
            if (task.isLargeData()) {
                Slogf.d(CarLog.TAG_TELEMETRY, "invoking script executor for large input");
                invokeScriptForLargeInput(task);
            } else {
                Slogf.d(CarLog.TAG_TELEMETRY, "invoking script executor");
                mScriptExecutor.invokeScript(
                        task.getMetricsConfig().getScript(),
                        task.getHandlerName(),
                        task.getData(),
                        mResultStore.getInterimResult(mCurrentMetricsConfigName),
                        mScriptExecutorListener);
            }
            mTelemetryHandler.sendEmptyMessageDelayed(
                    MSG_STOP_HANGING_SCRIPT, MAX_SCRIPT_EXECUTION_TIME_MILLIS);
        } catch (RemoteException e) {
            mScriptExecutionTraceLog.traceEnd();
            Slogf.w(CarLog.TAG_TELEMETRY, "remote exception occurred invoking script", e);
            unbindScriptExecutor();
            addTaskToQueue(task); // will trigger scheduleNextTask() and re-binding scriptexecutor
        } catch (IOException e) {
            mScriptExecutionTraceLog.traceEnd();
            Slogf.w(CarLog.TAG_TELEMETRY, "Either unable to create pipe or failed to pipe data"
                    + " to ScriptExecutor. Skipping the published data", e);
            mCurrentMetricsConfigName = null;
            scheduleNextTask(); // drop this task and schedule the next one
        }
    }

    /**
     * Sets up pipes, invokes ScriptExecutor#invokeScriptForLargeInput() API, and writes the
     * script input to the pipe.
     *
     * @param task containing all the necessary parameters for ScriptExecutor API.
     * @throws IOException if cannot create pipe or cannot write the bundle to pipe.
     * @throws RemoteException if ScriptExecutor failed.
     */
    private void invokeScriptForLargeInput(@NonNull ScriptExecutionTask task)
            throws IOException, RemoteException {
        ParcelFileDescriptor[] fds = ParcelFileDescriptor.createPipe();
        ParcelFileDescriptor readFd = fds[0];
        ParcelFileDescriptor writeFd = fds[1];
        try {
            mScriptExecutor.invokeScriptForLargeInput(
                    task.getMetricsConfig().getScript(),
                    task.getHandlerName(),
                    readFd,
                    mResultStore.getInterimResult(mCurrentMetricsConfigName),
                    mScriptExecutorListener);
        } catch (RemoteException e) {
            IoUtils.closeQuietly(readFd);
            IoUtils.closeQuietly(writeFd);
            throw e;
        }
        IoUtils.closeQuietly(readFd);

        Slogf.d(CarLog.TAG_TELEMETRY, "writing large script data to pipe");
        try (OutputStream outputStream = new ParcelFileDescriptor.AutoCloseOutputStream(writeFd)) {
            task.getData().writeToStream(outputStream);
        }
    }

    /** Stores final metrics and schedules the next task. */
    private void onScriptFinished(@NonNull PersistableBundle result) {
        mTelemetryHandler.post(() -> {
            mScriptExecutionTraceLog.traceEnd(); // end trace as soon as script completes running
            mTelemetryHandler.removeMessages(MSG_STOP_HANGING_SCRIPT);
            mResultStore.putFinalResult(mCurrentMetricsConfigName, result);
            mScriptFinishedCallback.onScriptFinished(mCurrentMetricsConfigName);
            mCurrentMetricsConfigName = null;
            scheduleNextTask();
        });
    }

    /** Stores interim metrics and schedules the next task. */
    private void onScriptSuccess(@NonNull PersistableBundle stateToPersist) {
        mTelemetryHandler.post(() -> {
            mScriptExecutionTraceLog.traceEnd(); // end trace as soon as script completes running
            mTelemetryHandler.removeMessages(MSG_STOP_HANGING_SCRIPT);
            mResultStore.putInterimResult(mCurrentMetricsConfigName, stateToPersist);
            mCurrentMetricsConfigName = null;
            scheduleNextTask();
        });
    }

    /** Stores telemetry error and schedules the next task. */
    private void onScriptError(
            int errorType, @NonNull String message, @Nullable String stackTrace) {
        mTelemetryHandler.post(() -> {
            mScriptExecutionTraceLog.traceEnd(); // end trace as soon as script completes running
            mTelemetryHandler.removeMessages(MSG_STOP_HANGING_SCRIPT);
            TelemetryProto.TelemetryError.Builder error = TelemetryProto.TelemetryError.newBuilder()
                    .setErrorType(TelemetryProto.TelemetryError.ErrorType.forNumber(errorType))
                    .setMessage(message);
            if (stackTrace != null) {
                error.setStackTrace(stackTrace);
            }
            mResultStore.putErrorResult(mCurrentMetricsConfigName, error.build());
            mScriptFinishedCallback.onScriptFinished(mCurrentMetricsConfigName);
            mCurrentMetricsConfigName = null;
            scheduleNextTask();
        });
    }

    /** Listens for script execution status. Methods are called on the binder thread. */
    private static final class ScriptExecutorListener extends IScriptExecutorListener.Stub {
        private final WeakReference<DataBrokerImpl> mWeakDataBroker;

        private ScriptExecutorListener(@NonNull DataBrokerImpl dataBroker) {
            mWeakDataBroker = new WeakReference<>(dataBroker);
        }

        @Override
        public void onScriptFinished(@NonNull PersistableBundle result) {
            DataBrokerImpl dataBroker = mWeakDataBroker.get();
            if (dataBroker == null) {
                return;
            }
            dataBroker.onScriptFinished(result);
        }

        @Override
        public void onSuccess(@NonNull PersistableBundle stateToPersist) {
            DataBrokerImpl dataBroker = mWeakDataBroker.get();
            if (dataBroker == null) {
                return;
            }
            dataBroker.onScriptSuccess(stateToPersist);
        }

        @Override
        public void onError(int errorType, @NonNull String message, @Nullable String stackTrace) {
            DataBrokerImpl dataBroker = mWeakDataBroker.get();
            if (dataBroker == null) {
                return;
            }
            dataBroker.onScriptError(errorType, message, stackTrace);
        }
    }

    /** Callback handler to handle scheduling and rescheduling of {@link ScriptExecutionTask}s. */
    class TaskHandler extends Handler {
        TaskHandler(@NonNull Looper looper) {
            super(looper);
        }

        /**
         * Handles a message depending on the message ID.
         * If the msg ID is MSG_HANDLE_TASK, it polls a task from the priority queue and executing a
         * {@link ScriptExecutionTask}. There are multiple places where this message is sent: when
         * priority updates, when a new task is added to the priority queue, and when a task
         * finishes running.
         */
        @Override
        public void handleMessage(@NonNull Message msg) {
            switch (msg.what) {
                case MSG_HANDLE_TASK:
                    pollAndExecuteTask(); // run the next task
                    break;
                case MSG_BIND_TO_SCRIPT_EXECUTOR:
                    bindScriptExecutor();
                    break;
                case MSG_STOP_HANGING_SCRIPT:
                    // TODO(b/223224704): log error
                    unbindScriptExecutor();
                    scheduleNextTask();
                    break;
                default:
                    Slogf.w(CarLog.TAG_TELEMETRY, "TaskHandler received unknown message.");
            }
        }
    }
}
