/*
 * Copyright (C) 2022 The Android Open Source Project
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

package com.android.systemui.car.displayarea;

import android.content.Context;
import android.os.Handler;

import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.qs.QSHost;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.wm.shell.common.HandlerExecutor;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SyncTransactionQueue;
import com.android.wm.shell.common.TransactionPool;

import dagger.Module;
import dagger.Provides;

/**
 * Module for Car SysUI Display area
 */
@Module
public abstract class CarDisplayAreaModule {

    @Provides
    @SysUISingleton
    static CarDisplayAreaOrganizer provideCarDisplayAreaOrganizer(
            ShellExecutor mainExecutor, Context context,
            SyncTransactionQueue syncQueue) {
        return new CarDisplayAreaOrganizer(mainExecutor, context, syncQueue);
    }

    @Provides
    @SysUISingleton
    static CarDisplayAreaController provideCarDisplayAreaController(Context context,
            SyncTransactionQueue syncQueue, CarFullscreenTaskListener carFullscreenTaskListener,
            ConfigurationController configurationController, QSHost host,
            ShellExecutor mainExecutor, CarDisplayAreaOrganizer organizer) {
        return new CarDisplayAreaController(context, syncQueue, carFullscreenTaskListener,
                mainExecutor, configurationController, host, organizer);
    }

    @Provides
    @SysUISingleton
    static CarFullscreenTaskListener provideCarFullscreenTaskListener(
            SyncTransactionQueue syncQueue) {
        return new CarFullscreenTaskListener(syncQueue);
    }

    @Provides
    @SysUISingleton
    static SyncTransactionQueue provideSyncTransactionQueue(TransactionPool pool,
            ShellExecutor mainExecutor) {
        return new SyncTransactionQueue(pool, mainExecutor);
    }

    @Provides
    @SysUISingleton
    static TransactionPool provideTransactionPool() {
        return new TransactionPool();
    }

    /**
     * Provide a SysUI main-thread Executor.
     */
    @Provides
    @SysUISingleton
    public static ShellExecutor provideShellExecutor(
            Handler sysuiMainHandler) {
        return new HandlerExecutor(sysuiMainHandler);
    }
}
