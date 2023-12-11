/*
 * Copyright (C) 2017 The Android Open Source Project
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

package com.android.cts.mockime;

import static android.view.ViewGroup.LayoutParams.MATCH_PARENT;
import static android.view.ViewGroup.LayoutParams.WRAP_CONTENT;
import static android.view.WindowManager.LayoutParams.FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS;

import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.inputmethodservice.InputMethodService;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.IBinder;
import android.os.Looper;
import android.os.Process;
import android.os.ResultReceiver;
import android.os.StrictMode;
import android.os.SystemClock;
import android.text.TextUtils;
import android.util.Log;
import android.util.Size;
import android.util.TypedValue;
import android.view.Display;
import android.view.GestureDetector;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.View;
import android.view.ViewConfiguration;
import android.view.Window;
import android.view.WindowInsets;
import android.view.WindowManager;
import android.view.inputmethod.CompletionInfo;
import android.view.inputmethod.CorrectionInfo;
import android.view.inputmethod.CursorAnchorInfo;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.ExtractedTextRequest;
import android.view.inputmethod.InlineSuggestion;
import android.view.inputmethod.InlineSuggestionsRequest;
import android.view.inputmethod.InlineSuggestionsResponse;
import android.view.inputmethod.InputBinding;
import android.view.inputmethod.InputConnection;
import android.view.inputmethod.InputContentInfo;
import android.view.inputmethod.InputMethod;
import android.widget.FrameLayout;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.inline.InlinePresentationSpec;

import androidx.annotation.AnyThread;
import androidx.annotation.CallSuper;
import androidx.annotation.MainThread;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.WorkerThread;
import androidx.autofill.inline.UiVersions;
import androidx.autofill.inline.UiVersions.StylesBuilder;
import androidx.autofill.inline.v1.InlineSuggestionUi;

import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReference;
import java.util.function.BooleanSupplier;
import java.util.function.Consumer;
import java.util.function.Supplier;

/**
 * Mock IME for end-to-end tests.
 */
public final class MockIme extends InputMethodService {

    private static final String TAG = "MockIme";

    private static final String PACKAGE_NAME = "com.android.cts.mockime";

    static ComponentName getComponentName() {
        return new ComponentName(PACKAGE_NAME, MockIme.class.getName());
    }

    static String getImeId() {
        return getComponentName().flattenToShortString();
    }

    static String getCommandActionName(@NonNull String eventActionName) {
        return eventActionName + ".command";
    }

    private final HandlerThread mHandlerThread = new HandlerThread("CommandReceiver");

    private final Handler mMainHandler = new Handler();

    private final Configuration mLastDispatchedConfiguration = new Configuration();

    private static final class CommandReceiver extends BroadcastReceiver {
        @NonNull
        private final String mActionName;
        @NonNull
        private final Consumer<ImeCommand> mOnReceiveCommand;

        CommandReceiver(@NonNull String actionName,
                @NonNull Consumer<ImeCommand> onReceiveCommand) {
            mActionName = actionName;
            mOnReceiveCommand = onReceiveCommand;
        }

        @Override
        public void onReceive(Context context, Intent intent) {
            if (TextUtils.equals(mActionName, intent.getAction())) {
                mOnReceiveCommand.accept(ImeCommand.fromBundle(intent.getExtras()));
            }
        }
    }

    @Nullable
    private InputConnection mMemorizedInputConnection = null;

    @Nullable
    @MainThread
    private InputConnection getMemorizedOrCurrentInputConnection() {
        return mMemorizedInputConnection != null
                ? mMemorizedInputConnection : getCurrentInputConnection();
    }

    @WorkerThread
    private void onReceiveCommand(@NonNull ImeCommand command) {
        getTracer().onReceiveCommand(command, () -> {
            if (command.shouldDispatchToMainThread()) {
                mMainHandler.post(() -> onHandleCommand(command));
            } else {
                onHandleCommand(command);
            }
        });
    }

    @AnyThread
    private void onHandleCommand(@NonNull ImeCommand command) {
        getTracer().onHandleCommand(command, () -> {
            if (command.shouldDispatchToMainThread()) {
                if (Looper.myLooper() != Looper.getMainLooper()) {
                    throw new IllegalStateException("command " + command
                            + " should be handled on the main thread");
                }
                // The context which created from InputMethodService#createXXXContext must behave
                // like an UI context, which can obtain a display, a window manager,
                // a view configuration and a gesture detector instance without strict mode
                // violation.
                final Configuration testConfig = new Configuration();
                testConfig.setToDefaults();
                final Context configContext = createConfigurationContext(testConfig);
                final Context attrContext = createAttributionContext(null /* attributionTag */);
                // UI component accesses on a display context must throw strict mode violations.
                final Context displayContext = createDisplayContext(getDisplay());
                switch (command.getName()) {
                    case "memorizeCurrentInputConnection": {
                        if (!Looper.getMainLooper().isCurrentThread()) {
                            return new UnsupportedOperationException(
                                    "memorizeCurrentInputConnection can be requested only for the"
                                            + " main thread.");
                        }
                        mMemorizedInputConnection = getCurrentInputConnection();
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "unmemorizeCurrentInputConnection": {
                        if (!Looper.getMainLooper().isCurrentThread()) {
                            return new UnsupportedOperationException(
                                    "unmemorizeCurrentInputConnection can be requested only for the"
                                            + " main thread.");
                        }
                        mMemorizedInputConnection = null;
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "getTextBeforeCursor": {
                        final int n = command.getExtras().getInt("n");
                        final int flag = command.getExtras().getInt("flag");
                        return getMemorizedOrCurrentInputConnection().getTextBeforeCursor(n, flag);
                    }
                    case "getTextAfterCursor": {
                        final int n = command.getExtras().getInt("n");
                        final int flag = command.getExtras().getInt("flag");
                        return getMemorizedOrCurrentInputConnection().getTextAfterCursor(n, flag);
                    }
                    case "getSelectedText": {
                        final int flag = command.getExtras().getInt("flag");
                        return getMemorizedOrCurrentInputConnection().getSelectedText(flag);
                    }
                    case "getCursorCapsMode": {
                        final int reqModes = command.getExtras().getInt("reqModes");
                        return getMemorizedOrCurrentInputConnection().getCursorCapsMode(reqModes);
                    }
                    case "getExtractedText": {
                        final ExtractedTextRequest request =
                                command.getExtras().getParcelable("request");
                        final int flags = command.getExtras().getInt("flags");
                        return getMemorizedOrCurrentInputConnection().getExtractedText(request,
                                flags);
                    }
                    case "deleteSurroundingText": {
                        final int beforeLength = command.getExtras().getInt("beforeLength");
                        final int afterLength = command.getExtras().getInt("afterLength");
                        return getMemorizedOrCurrentInputConnection().deleteSurroundingText(
                                beforeLength, afterLength);
                    }
                    case "deleteSurroundingTextInCodePoints": {
                        final int beforeLength = command.getExtras().getInt("beforeLength");
                        final int afterLength = command.getExtras().getInt("afterLength");
                        return getMemorizedOrCurrentInputConnection()
                                .deleteSurroundingTextInCodePoints(beforeLength, afterLength);
                    }
                    case "setComposingText": {
                        final CharSequence text = command.getExtras().getCharSequence("text");
                        final int newCursorPosition =
                                command.getExtras().getInt("newCursorPosition");
                        return getMemorizedOrCurrentInputConnection().setComposingText(
                                text, newCursorPosition);
                    }
                    case "setComposingRegion": {
                        final int start = command.getExtras().getInt("start");
                        final int end = command.getExtras().getInt("end");
                        return getMemorizedOrCurrentInputConnection().setComposingRegion(start,
                                end);
                    }
                    case "finishComposingText":
                        return getMemorizedOrCurrentInputConnection().finishComposingText();
                    case "commitText": {
                        final CharSequence text = command.getExtras().getCharSequence("text");
                        final int newCursorPosition =
                                command.getExtras().getInt("newCursorPosition");
                        return getMemorizedOrCurrentInputConnection().commitText(text,
                                newCursorPosition);
                    }
                    case "commitCompletion": {
                        final CompletionInfo text = command.getExtras().getParcelable("text");
                        return getMemorizedOrCurrentInputConnection().commitCompletion(text);
                    }
                    case "commitCorrection": {
                        final CorrectionInfo correctionInfo =
                                command.getExtras().getParcelable("correctionInfo");
                        return getMemorizedOrCurrentInputConnection().commitCorrection(
                                correctionInfo);
                    }
                    case "setSelection": {
                        final int start = command.getExtras().getInt("start");
                        final int end = command.getExtras().getInt("end");
                        return getMemorizedOrCurrentInputConnection().setSelection(start, end);
                    }
                    case "performEditorAction": {
                        final int editorAction = command.getExtras().getInt("editorAction");
                        return getMemorizedOrCurrentInputConnection().performEditorAction(
                                editorAction);
                    }
                    case "performContextMenuAction": {
                        final int id = command.getExtras().getInt("id");
                        return getMemorizedOrCurrentInputConnection().performContextMenuAction(id);
                    }
                    case "beginBatchEdit":
                        return getMemorizedOrCurrentInputConnection().beginBatchEdit();
                    case "endBatchEdit":
                        return getMemorizedOrCurrentInputConnection().endBatchEdit();
                    case "sendKeyEvent": {
                        final KeyEvent event = command.getExtras().getParcelable("event");
                        return getMemorizedOrCurrentInputConnection().sendKeyEvent(event);
                    }
                    case "clearMetaKeyStates": {
                        final int states = command.getExtras().getInt("states");
                        return getMemorizedOrCurrentInputConnection().clearMetaKeyStates(states);
                    }
                    case "reportFullscreenMode": {
                        final boolean enabled = command.getExtras().getBoolean("enabled");
                        return getMemorizedOrCurrentInputConnection().reportFullscreenMode(enabled);
                    }
                    case "performSpellCheck": {
                        return getMemorizedOrCurrentInputConnection().performSpellCheck();
                    }
                    case "performPrivateCommand": {
                        final String action = command.getExtras().getString("action");
                        final Bundle data = command.getExtras().getBundle("data");
                        return getMemorizedOrCurrentInputConnection().performPrivateCommand(action,
                                data);
                    }
                    case "requestCursorUpdates": {
                        final int cursorUpdateMode = command.getExtras().getInt("cursorUpdateMode");
                        return getMemorizedOrCurrentInputConnection().requestCursorUpdates(
                                cursorUpdateMode);
                    }
                    case "getHandler":
                        return getMemorizedOrCurrentInputConnection().getHandler();
                    case "closeConnection":
                        getMemorizedOrCurrentInputConnection().closeConnection();
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    case "commitContent": {
                        final InputContentInfo inputContentInfo =
                                command.getExtras().getParcelable("inputContentInfo");
                        final int flags = command.getExtras().getInt("flags");
                        final Bundle opts = command.getExtras().getBundle("opts");
                        return getMemorizedOrCurrentInputConnection().commitContent(
                                inputContentInfo, flags, opts);
                    }
                    case "setBackDisposition": {
                        final int backDisposition =
                                command.getExtras().getInt("backDisposition");
                        setBackDisposition(backDisposition);
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "requestHideSelf": {
                        final int flags = command.getExtras().getInt("flags");
                        requestHideSelf(flags);
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "requestShowSelf": {
                        final int flags = command.getExtras().getInt("flags");
                        requestShowSelf(flags);
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "sendDownUpKeyEvents": {
                        final int keyEventCode = command.getExtras().getInt("keyEventCode");
                        sendDownUpKeyEvents(keyEventCode);
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "getApplicationInfo": {
                        final String packageName = command.getExtras().getString("packageName");
                        final int flags = command.getExtras().getInt("flags");
                        try {
                            return getPackageManager().getApplicationInfo(packageName, flags);
                        } catch (PackageManager.NameNotFoundException e) {
                            return e;
                        }
                    }
                    case "getDisplayId":
                        return getDisplay().getDisplayId();
                    case "verifyLayoutInflaterContext":
                        return getLayoutInflater().getContext() == this;
                    case "setHeight":
                        final int height = command.getExtras().getInt("height");
                        mView.setHeight(height);
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    case "setInlineSuggestionsExtras":
                        mInlineSuggestionsExtras = command.getExtras();
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    case "verifyGetDisplay":
                        try {
                            return verifyGetDisplay();
                        } catch (UnsupportedOperationException e) {
                            return e;
                        }
                    case "verifyIsUiContext":
                        return verifyIsUiContext();
                    case "verifyGetWindowManager": {
                        final WindowManager imsWm = getSystemService(WindowManager.class);
                        final WindowManager configContextWm =
                                configContext.getSystemService(WindowManager.class);
                        final WindowManager attrContextWm =
                                attrContext.getSystemService(WindowManager.class);
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "verifyGetViewConfiguration": {
                        final ViewConfiguration imsViewConfig = ViewConfiguration.get(this);
                        final ViewConfiguration configContextViewConfig =
                                ViewConfiguration.get(configContext);
                        final ViewConfiguration attrContextViewConfig =
                                ViewConfiguration.get(attrContext);
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "verifyGetGestureDetector": {
                        GestureDetector.SimpleOnGestureListener listener =
                                new GestureDetector.SimpleOnGestureListener();
                        final GestureDetector imsGestureDetector =
                                new GestureDetector(this, listener);
                        final GestureDetector configContextGestureDetector =
                                new GestureDetector(configContext, listener);
                        final GestureDetector attrGestureDetector =
                                new GestureDetector(attrContext, listener);
                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "verifyGetWindowManagerOnDisplayContext": {
                        // Obtaining a WindowManager on a display context must throw a strict mode
                        // violation.
                        final WindowManager wm = displayContext
                                .getSystemService(WindowManager.class);

                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "verifyGetViewConfigurationOnDisplayContext": {
                        // Obtaining a ViewConfiguration on a display context must throw a strict
                        // mode violation.
                        final ViewConfiguration viewConfiguration =
                                ViewConfiguration.get(displayContext);

                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "verifyGetGestureDetectorOnDisplayContext": {
                        // Obtaining a GestureDetector on a display context must throw a strict mode
                        // violation.
                        GestureDetector.SimpleOnGestureListener listener =
                                new GestureDetector.SimpleOnGestureListener();
                        final GestureDetector gestureDetector =
                                new GestureDetector(displayContext, listener);

                        return ImeEvent.RETURN_VALUE_UNAVAILABLE;
                    }
                    case "getCurrentWindowMetricsBounds": {
                        return getSystemService(WindowManager.class)
                                .getCurrentWindowMetrics().getBounds();
                    }
                }
            }
            return ImeEvent.RETURN_VALUE_UNAVAILABLE;
        });
    }

    private boolean verifyGetDisplay() throws UnsupportedOperationException {
        final Display display;
        final Display configContextDisplay;
        final Configuration config = new Configuration();
        config.setToDefaults();
        final Context configContext = createConfigurationContext(config);
        display = getDisplay();
        configContextDisplay = configContext.getDisplay();
        return display != null && configContextDisplay != null;
    }

    private boolean verifyIsUiContext() {
        final Configuration config = new Configuration();
        config.setToDefaults();
        final Context configContext = createConfigurationContext(config);
        // The value must be true because ConfigurationContext is derived from InputMethodService,
        // which is a UI Context.
        final boolean imeDerivedConfigContext = configContext.isUiContext();
        // The value must be false because DisplayContext won't receive any config update from
        // server.
        final boolean imeDerivedDisplayContext = createDisplayContext(getDisplay()).isUiContext();
        return isUiContext() && imeDerivedConfigContext && !imeDerivedDisplayContext;
    }

    @Nullable
    private Bundle mInlineSuggestionsExtras;

    @Nullable
    private CommandReceiver mCommandReceiver;

    @Nullable
    private ImeSettings mSettings;

    private final AtomicReference<String> mImeEventActionName = new AtomicReference<>();

    @Nullable
    String getImeEventActionName() {
        return mImeEventActionName.get();
    }

    private final AtomicReference<String> mClientPackageName = new AtomicReference<>();

    @Nullable
    String getClientPackageName() {
        return mClientPackageName.get();
    }

    private class MockInputMethodImpl extends InputMethodImpl {
        @Override
        public void showSoftInput(int flags, ResultReceiver resultReceiver) {
            getTracer().showSoftInput(flags, resultReceiver,
                    () -> super.showSoftInput(flags, resultReceiver));
        }

        @Override
        public void hideSoftInput(int flags, ResultReceiver resultReceiver) {
            getTracer().hideSoftInput(flags, resultReceiver,
                    () -> super.hideSoftInput(flags, resultReceiver));
        }

        @Override
        public void attachToken(IBinder token) {
            getTracer().attachToken(token, () -> super.attachToken(token));
        }

        @Override
        public void bindInput(InputBinding binding) {
            getTracer().bindInput(binding, () -> super.bindInput(binding));
        }

        @Override
        public void unbindInput() {
            getTracer().unbindInput(() -> super.unbindInput());
        }
    }

    @Override
    public void onCreate() {
        // Initialize minimum settings to send events in Tracer#onCreate().
        mSettings = SettingsProvider.getSettings();
        if (mSettings == null) {
            throw new IllegalStateException("Settings file is not found. "
                    + "Make sure MockImeSession.create() is used to launch Mock IME.");
        }
        mClientPackageName.set(mSettings.getClientPackageName());
        mImeEventActionName.set(mSettings.getEventCallbackActionName());

        // TODO(b/159593676): consider to detect more violations
        if (mSettings.isStrictModeEnabled()) {
            StrictMode.setVmPolicy(
                    new StrictMode.VmPolicy.Builder()
                            .detectIncorrectContextUse()
                            .penaltyLog()
                            .penaltyListener(Runnable::run,
                                    v -> getTracer().onStrictModeViolated(() -> { }))
                            .build());
        }

        getTracer().onCreate(() -> {
            super.onCreate();
            mHandlerThread.start();
            final String actionName = getCommandActionName(mSettings.getEventCallbackActionName());
            mCommandReceiver = new CommandReceiver(actionName, this::onReceiveCommand);
            final IntentFilter filter = new IntentFilter(actionName);
            final Handler handler = new Handler(mHandlerThread.getLooper());
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                registerReceiver(mCommandReceiver, filter, null /* broadcastPermission */, handler,
                        Context.RECEIVER_VISIBLE_TO_INSTANT_APPS);
            } else {
                registerReceiver(mCommandReceiver, filter, null /* broadcastPermission */, handler);
            }
            if (mSettings.isVerifyContextApisInOnCreate()) {
                getTracer().onVerify("isUiContext", this::verifyIsUiContext);
                getTracer().onVerify("getDisplay", this::verifyGetDisplay);
            }
            final int windowFlags = mSettings.getWindowFlags(0);
            final int windowFlagsMask = mSettings.getWindowFlagsMask(0);
            if (windowFlags != 0 || windowFlagsMask != 0) {
                final int prevFlags = getWindow().getWindow().getAttributes().flags;
                getWindow().getWindow().setFlags(windowFlags, windowFlagsMask);
                // For some reasons, seems that we need to post another requestLayout() when
                // FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS bit is changed.
                // TODO: Investigate the reason.
                if ((windowFlagsMask & FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS) != 0) {
                    final boolean hadFlag = (prevFlags & FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS) != 0;
                    final boolean hasFlag = (windowFlags & FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS) != 0;
                    if (hadFlag != hasFlag) {
                        final View decorView = getWindow().getWindow().getDecorView();
                        decorView.post(() -> decorView.requestLayout());
                    }
                }
            }

            // Ensuring bar contrast interferes with the tests.
            getWindow().getWindow().setStatusBarContrastEnforced(false);
            getWindow().getWindow().setNavigationBarContrastEnforced(false);

            if (mSettings.hasNavigationBarColor()) {
                getWindow().getWindow().setNavigationBarColor(mSettings.getNavigationBarColor());
            }

            // Initialize to current Configuration to prevent unexpected configDiff value dispatched
            // in IME event.
            mLastDispatchedConfiguration.setTo(getResources().getConfiguration());
        });
    }

    @Override
    public void onConfigureWindow(Window win, boolean isFullscreen, boolean isCandidatesOnly) {
        getTracer().onConfigureWindow(win, isFullscreen, isCandidatesOnly,
                () -> super.onConfigureWindow(win, isFullscreen, isCandidatesOnly));
    }

    @Override
    public boolean onEvaluateFullscreenMode() {
        return getTracer().onEvaluateFullscreenMode(() ->
                mSettings.fullscreenModeAllowed(false) && super.onEvaluateFullscreenMode());
    }

    private static final class KeyboardLayoutView extends LinearLayout {
        @NonNull
        private final MockIme mMockIme;
        @NonNull
        private final ImeSettings mSettings;
        @NonNull
        private final View.OnLayoutChangeListener mLayoutListener;

        private final LinearLayout mLayout;

        @Nullable
        private final LinearLayout mSuggestionView;

        private boolean mDrawsBehindNavBar = false;

        KeyboardLayoutView(MockIme mockIme, @NonNull ImeSettings imeSettings,
                @Nullable Consumer<ImeLayoutInfo> onInputViewLayoutChangedCallback) {
            super(mockIme);

            mMockIme = mockIme;
            mSettings = imeSettings;

            setOrientation(VERTICAL);

            final int defaultBackgroundColor =
                    getResources().getColor(android.R.color.holo_orange_dark, null);

            final int mainSpacerHeight = mSettings.getInputViewHeight(LayoutParams.WRAP_CONTENT);
            mLayout = new LinearLayout(getContext());
            mLayout.setOrientation(LinearLayout.VERTICAL);

            if (mSettings.getInlineSuggestionsEnabled()) {
                final HorizontalScrollView scrollView = new HorizontalScrollView(getContext());
                final LayoutParams scrollViewParams = new LayoutParams(MATCH_PARENT, 100);
                scrollView.setLayoutParams(scrollViewParams);

                final LinearLayout suggestionView = new LinearLayout(getContext());
                suggestionView.setBackgroundColor(0xFFEEEEEE);
                final String suggestionViewContentDesc =
                        mSettings.getInlineSuggestionViewContentDesc(null /* default */);
                if (suggestionViewContentDesc != null) {
                    suggestionView.setContentDescription(suggestionViewContentDesc);
                }
                scrollView.addView(suggestionView, new LayoutParams(MATCH_PARENT, MATCH_PARENT));
                mSuggestionView = suggestionView;

                mLayout.addView(scrollView);
            } else {
                mSuggestionView = null;
            }

            {
                final FrameLayout secondaryLayout = new FrameLayout(getContext());
                secondaryLayout.setForegroundGravity(Gravity.CENTER);

                final TextView textView = new TextView(getContext());
                textView.setLayoutParams(new LayoutParams(MATCH_PARENT, WRAP_CONTENT));
                textView.setTextSize(TypedValue.COMPLEX_UNIT_SP, 20);
                textView.setGravity(Gravity.CENTER);
                textView.setText(getImeId());
                textView.setBackgroundColor(
                        mSettings.getBackgroundColor(defaultBackgroundColor));
                secondaryLayout.addView(textView);

                if (mSettings.isWatermarkEnabled(true /* defaultValue */)) {
                    final ImageView imageView = new ImageView(getContext());
                    final Bitmap bitmap = Watermark.create();
                    imageView.setImageBitmap(bitmap);
                    secondaryLayout.addView(imageView,
                            new FrameLayout.LayoutParams(bitmap.getWidth(), bitmap.getHeight(),
                                    Gravity.CENTER));
                }

                mLayout.addView(secondaryLayout);
            }

            addView(mLayout, MATCH_PARENT, mainSpacerHeight);

            final int systemUiVisibility = mSettings.getInputViewSystemUiVisibility(0);
            if (systemUiVisibility != 0) {
                setSystemUiVisibility(systemUiVisibility);
            }

            if (mSettings.getDrawsBehindNavBar()) {
                mDrawsBehindNavBar = true;
                mMockIme.getWindow().getWindow().setDecorFitsSystemWindows(false);
                setSystemUiVisibility(getSystemUiVisibility()
                        | SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION);
            }

            mLayoutListener = (View v, int left, int top, int right, int bottom, int oldLeft,
                    int oldTop, int oldRight, int oldBottom) ->
                    onInputViewLayoutChangedCallback.accept(
                            ImeLayoutInfo.fromLayoutListenerCallback(
                                    v, left, top, right, bottom, oldLeft, oldTop, oldRight,
                                    oldBottom));
            this.addOnLayoutChangeListener(mLayoutListener);
        }

        private void setHeight(int height) {
            mLayout.getLayoutParams().height = height;
            mLayout.requestLayout();
        }

        private void updateBottomPaddingIfNecessary(int newPaddingBottom) {
            if (getPaddingBottom() != newPaddingBottom) {
                setPadding(getPaddingLeft(), getPaddingTop(), getPaddingRight(), newPaddingBottom);
            }
        }

        @Override
        public WindowInsets onApplyWindowInsets(WindowInsets insets) {
            if (insets.isConsumed()
                    || mDrawsBehindNavBar
                    || (getSystemUiVisibility() & SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION) == 0) {
                // In this case we are not interested in consuming NavBar region.
                // Make sure that the bottom padding is empty.
                updateBottomPaddingIfNecessary(0);
                return insets;
            }

            // In some cases the bottom system window inset is not a navigation bar. Wear devices
            // that have bottom chin are examples.  For now, assume that it's a navigation bar if it
            // has the same height as the root window's stable bottom inset.
            final WindowInsets rootWindowInsets = getRootWindowInsets();
            if (rootWindowInsets != null && (rootWindowInsets.getStableInsetBottom()
                    != insets.getSystemWindowInsetBottom())) {
                // This is probably not a NavBar.
                updateBottomPaddingIfNecessary(0);
                return insets;
            }

            final int possibleNavBarHeight = insets.getSystemWindowInsetBottom();
            updateBottomPaddingIfNecessary(possibleNavBarHeight);
            return possibleNavBarHeight <= 0
                    ? insets
                    : insets.replaceSystemWindowInsets(
                            insets.getSystemWindowInsetLeft(),
                            insets.getSystemWindowInsetTop(),
                            insets.getSystemWindowInsetRight(),
                            0 /* bottom */);
        }

        @Override
        protected void onWindowVisibilityChanged(int visibility) {
            mMockIme.getTracer().onWindowVisibilityChanged(() -> {
                super.onWindowVisibilityChanged(visibility);
            }, visibility);
        }

        @Override
        protected void onDetachedFromWindow() {
            super.onDetachedFromWindow();
            removeOnLayoutChangeListener(mLayoutListener);
        }

        @MainThread
        private void updateInlineSuggestions(
                @NonNull PendingInlineSuggestions pendingInlineSuggestions) {
            Log.d(TAG, "updateInlineSuggestions() called: " + pendingInlineSuggestions.mTotalCount);
            if (mSuggestionView == null || !pendingInlineSuggestions.mValid.get()) {
                return;
            }
            mSuggestionView.removeAllViews();
            for (int i = 0; i < pendingInlineSuggestions.mTotalCount; i++) {
                View view = pendingInlineSuggestions.mViews[i];
                if (view == null) {
                    continue;
                }
                mSuggestionView.addView(view);
            }
        }
    }

    KeyboardLayoutView mView;

    private void onInputViewLayoutChanged(@NonNull ImeLayoutInfo layoutInfo) {
        getTracer().onInputViewLayoutChanged(layoutInfo, () -> { });
    }

    @Override
    public View onCreateInputView() {
        return getTracer().onCreateInputView(() -> {
            mView = new KeyboardLayoutView(this, mSettings, this::onInputViewLayoutChanged);
            return mView;
        });
    }

    @Override
    public void onStartInput(EditorInfo editorInfo, boolean restarting) {
        getTracer().onStartInput(editorInfo, restarting,
                () -> super.onStartInput(editorInfo, restarting));
    }

    @Override
    public void onStartInputView(EditorInfo editorInfo, boolean restarting) {
        getTracer().onStartInputView(editorInfo, restarting,
                () -> super.onStartInputView(editorInfo, restarting));
    }

    @Override
    public void onFinishInputView(boolean finishingInput) {
        getTracer().onFinishInputView(finishingInput,
                () -> super.onFinishInputView(finishingInput));
    }

    @Override
    public void onFinishInput() {
        getTracer().onFinishInput(() -> super.onFinishInput());
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        return getTracer().onKeyDown(keyCode, event, () -> super.onKeyDown(keyCode, event));
    }

    @Override
    public void onUpdateCursorAnchorInfo(CursorAnchorInfo cursorAnchorInfo) {
        getTracer().onUpdateCursorAnchorInfo(cursorAnchorInfo,
                () -> super.onUpdateCursorAnchorInfo(cursorAnchorInfo));
    }

    @Override
    public void onUpdateSelection(int oldSelStart, int oldSelEnd, int newSelStart, int newSelEnd,
            int candidatesStart, int candidatesEnd) {
        getTracer().onUpdateSelection(oldSelStart, oldSelEnd, newSelStart, newSelEnd,
                candidatesStart, candidatesEnd,
                () -> super.onUpdateSelection(oldSelStart, oldSelEnd, newSelStart, newSelEnd,
                        candidatesStart, candidatesEnd));
    }

    @CallSuper
    public boolean onEvaluateInputViewShown() {
        return getTracer().onEvaluateInputViewShown(() -> {
            // onShowInputRequested() is indeed @CallSuper so we always call this, even when the
            // result is ignored.
            final boolean originalResult = super.onEvaluateInputViewShown();
            if (!mSettings.getHardKeyboardConfigurationBehaviorAllowed(false)) {
                final Configuration config = getResources().getConfiguration();
                if (config.keyboard != Configuration.KEYBOARD_NOKEYS
                        && config.hardKeyboardHidden != Configuration.HARDKEYBOARDHIDDEN_YES) {
                    // Override the behavior of InputMethodService#onEvaluateInputViewShown()
                    return true;
                }
            }
            return originalResult;
        });
    }

    @Override
    public boolean onShowInputRequested(int flags, boolean configChange) {
        return getTracer().onShowInputRequested(flags, configChange, () -> {
            // onShowInputRequested() is not marked with @CallSuper, but just in case.
            final boolean originalResult = super.onShowInputRequested(flags, configChange);
            if (!mSettings.getHardKeyboardConfigurationBehaviorAllowed(false)) {
                if ((flags & InputMethod.SHOW_EXPLICIT) == 0
                        && getResources().getConfiguration().keyboard
                        != Configuration.KEYBOARD_NOKEYS) {
                    // Override the behavior of InputMethodService#onShowInputRequested()
                    return true;
                }
            }
            return originalResult;
        });
    }

    @Override
    public void onDestroy() {
        getTracer().onDestroy(() -> {
            super.onDestroy();
            unregisterReceiver(mCommandReceiver);
            mHandlerThread.quitSafely();
        });
    }

    @Override
    public AbstractInputMethodImpl onCreateInputMethodInterface() {
        return getTracer().onCreateInputMethodInterface(() -> new MockInputMethodImpl());
    }

    private final ThreadLocal<Tracer> mThreadLocalTracer = new ThreadLocal<>();

    private Tracer getTracer() {
        Tracer tracer = mThreadLocalTracer.get();
        if (tracer == null) {
            tracer = new Tracer(this);
            mThreadLocalTracer.set(tracer);
        }
        return tracer;
    }

    @NonNull
    private ImeState getState() {
        final boolean hasInputBinding = getCurrentInputBinding() != null;
        final boolean hasFallbackInputConnection =
                !hasInputBinding
                        || getCurrentInputConnection() == getCurrentInputBinding().getConnection();
        return new ImeState(hasInputBinding, hasFallbackInputConnection);
    }

    private PendingInlineSuggestions mPendingInlineSuggestions;

    private static final class PendingInlineSuggestions {
        final InlineSuggestionsResponse mResponse;
        final int mTotalCount;
        final View[] mViews;
        final AtomicInteger mInflatedViewCount;
        final AtomicBoolean mValid = new AtomicBoolean(true);

        PendingInlineSuggestions(InlineSuggestionsResponse response) {
            mResponse = response;
            mTotalCount = response.getInlineSuggestions().size();
            mViews = new View[mTotalCount];
            mInflatedViewCount = new AtomicInteger(0);
        }
    }

    @MainThread
    @Override
    public InlineSuggestionsRequest onCreateInlineSuggestionsRequest(Bundle uiExtras) {
        StylesBuilder stylesBuilder = UiVersions.newStylesBuilder();
        stylesBuilder.addStyle(InlineSuggestionUi.newStyleBuilder().build());
        Bundle styles = stylesBuilder.build();

        if (mInlineSuggestionsExtras != null) {
            styles.putAll(mInlineSuggestionsExtras);
        }

        return getTracer().onCreateInlineSuggestionsRequest(() -> {
            final ArrayList<InlinePresentationSpec> presentationSpecs = new ArrayList<>();
            presentationSpecs.add(new InlinePresentationSpec.Builder(new Size(100, 100),
                    new Size(400, 100)).setStyle(styles).build());
            presentationSpecs.add(new InlinePresentationSpec.Builder(new Size(100, 100),
                    new Size(400, 100)).setStyle(styles).build());

            final InlinePresentationSpec tooltipSpec =
                    new InlinePresentationSpec.Builder(new Size(100, 100),
                            new Size(400, 100)).setStyle(styles).build();
            final InlineSuggestionsRequest.Builder builder =
                    new InlineSuggestionsRequest.Builder(presentationSpecs)
                            .setInlineTooltipPresentationSpec(tooltipSpec)
                            .setMaxSuggestionCount(6);
            if (mInlineSuggestionsExtras != null) {
                builder.setExtras(mInlineSuggestionsExtras.deepCopy());
            }
            return builder.build();
        });
    }

    @MainThread
    @Override
    public boolean onInlineSuggestionsResponse(@NonNull InlineSuggestionsResponse response) {
        return getTracer().onInlineSuggestionsResponse(response, () -> {
            final PendingInlineSuggestions pendingInlineSuggestions =
                    new PendingInlineSuggestions(response);
            if (mPendingInlineSuggestions != null) {
                mPendingInlineSuggestions.mValid.set(false);
            }
            mPendingInlineSuggestions = pendingInlineSuggestions;
            if (pendingInlineSuggestions.mTotalCount == 0) {
                if (mView != null) {
                    mView.updateInlineSuggestions(pendingInlineSuggestions);
                }
                return true;
            }

            final ExecutorService executorService = Executors.newCachedThreadPool();
            for (int i = 0; i < pendingInlineSuggestions.mTotalCount; i++) {
                final int index = i;
                InlineSuggestion inlineSuggestion =
                        pendingInlineSuggestions.mResponse.getInlineSuggestions().get(index);
                inlineSuggestion.inflate(
                        this,
                        new Size(WRAP_CONTENT, WRAP_CONTENT),
                        executorService,
                        suggestionView -> {
                            Log.d(TAG, "new inline suggestion view ready");
                            if (suggestionView != null) {
                                suggestionView.setOnClickListener((v) -> {
                                    getTracer().onInlineSuggestionClickedEvent(() -> { });
                                });
                                suggestionView.setOnLongClickListener((v) -> {
                                    getTracer().onInlineSuggestionLongClickedEvent(() -> { });
                                    return true;
                                });
                                pendingInlineSuggestions.mViews[index] = suggestionView;
                            }
                            if (pendingInlineSuggestions.mInflatedViewCount.incrementAndGet()
                                    == pendingInlineSuggestions.mTotalCount
                                    && pendingInlineSuggestions.mValid.get()) {
                                Log.d(TAG, "ready to display all suggestions");
                                mMainHandler.post(() ->
                                        mView.updateInlineSuggestions(pendingInlineSuggestions));
                            }
                        });
            }
            return true;
        });
    }

    @Override
    public void onConfigurationChanged(Configuration configuration) {
        getTracer().onConfigurationChanged(() -> {}, configuration);
        mLastDispatchedConfiguration.setTo(configuration);
    }

    /**
     * Event tracing helper class for {@link MockIme}.
     */
    private static final class Tracer {

        @NonNull
        private final MockIme mIme;

        private final int mThreadId = Process.myTid();

        @NonNull
        private final String mThreadName =
                Thread.currentThread().getName() != null ? Thread.currentThread().getName() : "";

        private final boolean mIsMainThread =
                Looper.getMainLooper().getThread() == Thread.currentThread();

        private int mNestLevel = 0;

        private String mImeEventActionName;

        private String mClientPackageName;

        Tracer(@NonNull MockIme mockIme) {
            mIme = mockIme;
        }

        private void sendEventInternal(@NonNull ImeEvent event) {
            if (mImeEventActionName == null) {
                mImeEventActionName = mIme.getImeEventActionName();
            }
            if (mClientPackageName == null) {
                mClientPackageName = mIme.getClientPackageName();
            }
            if (mImeEventActionName == null || mClientPackageName == null) {
                Log.e(TAG, "Tracer cannot be used before onCreate()");
                return;
            }
            final Intent intent = new Intent()
                    .setAction(mImeEventActionName)
                    .setPackage(mClientPackageName)
                    .putExtras(event.toBundle())
                    .addFlags(Intent.FLAG_RECEIVER_REGISTERED_ONLY
                            | Intent.FLAG_RECEIVER_VISIBLE_TO_INSTANT_APPS);
            mIme.sendBroadcast(intent);
        }

        private void recordEventInternal(@NonNull String eventName, @NonNull Runnable runnable) {
            recordEventInternal(eventName, runnable, new Bundle());
        }

        private void recordEventInternal(@NonNull String eventName, @NonNull Runnable runnable,
                @NonNull Bundle arguments) {
            recordEventInternal(eventName, () -> {
                runnable.run(); return ImeEvent.RETURN_VALUE_UNAVAILABLE;
            }, arguments);
        }

        private <T> T recordEventInternal(@NonNull String eventName,
                @NonNull Supplier<T> supplier) {
            return recordEventInternal(eventName, supplier, new Bundle());
        }

        private <T> T recordEventInternal(@NonNull String eventName,
                @NonNull Supplier<T> supplier, @NonNull Bundle arguments) {
            final ImeState enterState = mIme.getState();
            final long enterTimestamp = SystemClock.elapsedRealtimeNanos();
            final long enterWallTime = System.currentTimeMillis();
            final int nestLevel = mNestLevel;
            // Send enter event
            sendEventInternal(new ImeEvent(eventName, nestLevel, mThreadName,
                    mThreadId, mIsMainThread, enterTimestamp, 0, enterWallTime,
                    0, enterState, null, arguments,
                    ImeEvent.RETURN_VALUE_UNAVAILABLE));
            ++mNestLevel;
            T result;
            try {
                result = supplier.get();
            } finally {
                --mNestLevel;
            }
            final long exitTimestamp = SystemClock.elapsedRealtimeNanos();
            final long exitWallTime = System.currentTimeMillis();
            final ImeState exitState = mIme.getState();
            // Send exit event
            sendEventInternal(new ImeEvent(eventName, nestLevel, mThreadName,
                    mThreadId, mIsMainThread, enterTimestamp, exitTimestamp, enterWallTime,
                    exitWallTime, enterState, exitState, arguments, result));
            return result;
        }

        void onCreate(@NonNull Runnable runnable) {
            recordEventInternal("onCreate", runnable);
        }

        void onVerify(String name, @NonNull BooleanSupplier supplier) {
            final Bundle arguments = new Bundle();
            arguments.putString("name", name);
            recordEventInternal("onVerify", supplier::getAsBoolean, arguments);
        }

        void onConfigureWindow(Window win, boolean isFullscreen, boolean isCandidatesOnly,
                @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putBoolean("isFullscreen", isFullscreen);
            arguments.putBoolean("isCandidatesOnly", isCandidatesOnly);
            recordEventInternal("onConfigureWindow", runnable, arguments);
        }

        boolean onEvaluateFullscreenMode(@NonNull BooleanSupplier supplier) {
            return recordEventInternal("onEvaluateFullscreenMode", supplier::getAsBoolean);
        }

        boolean onEvaluateInputViewShown(@NonNull BooleanSupplier supplier) {
            return recordEventInternal("onEvaluateInputViewShown", supplier::getAsBoolean);
        }

        View onCreateInputView(@NonNull Supplier<View> supplier) {
            return recordEventInternal("onCreateInputView", supplier);
        }

        void onStartInput(EditorInfo editorInfo, boolean restarting, @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putParcelable("editorInfo", editorInfo);
            arguments.putBoolean("restarting", restarting);
            recordEventInternal("onStartInput", runnable, arguments);
        }

        void onWindowVisibilityChanged(@NonNull Runnable runnable, int visibility) {
            final Bundle arguments = new Bundle();
            arguments.putInt("visible", visibility);
            recordEventInternal("onWindowVisibilityChanged", runnable, arguments);
        }

        void onStartInputView(EditorInfo editorInfo, boolean restarting,
                @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putParcelable("editorInfo", editorInfo);
            arguments.putBoolean("restarting", restarting);
            recordEventInternal("onStartInputView", runnable, arguments);
        }

        void onFinishInputView(boolean finishingInput, @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putBoolean("finishingInput", finishingInput);
            recordEventInternal("onFinishInputView", runnable, arguments);
        }

        void onFinishInput(@NonNull Runnable runnable) {
            recordEventInternal("onFinishInput", runnable);
        }

        boolean onKeyDown(int keyCode, KeyEvent event, @NonNull BooleanSupplier supplier) {
            final Bundle arguments = new Bundle();
            arguments.putInt("keyCode", keyCode);
            arguments.putParcelable("event", event);
            return recordEventInternal("onKeyDown", supplier::getAsBoolean, arguments);
        }

        void onUpdateCursorAnchorInfo(CursorAnchorInfo cursorAnchorInfo,
                @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putParcelable("cursorAnchorInfo", cursorAnchorInfo);
            recordEventInternal("onUpdateCursorAnchorInfo", runnable, arguments);
        }

        void onUpdateSelection(int oldSelStart,
                int oldSelEnd,
                int newSelStart,
                int newSelEnd,
                int candidatesStart,
                int candidatesEnd,
                @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putInt("oldSelStart", oldSelStart);
            arguments.putInt("oldSelEnd", oldSelEnd);
            arguments.putInt("newSelStart", newSelStart);
            arguments.putInt("newSelEnd", newSelEnd);
            arguments.putInt("candidatesStart", candidatesStart);
            arguments.putInt("candidatesEnd", candidatesEnd);
            recordEventInternal("onUpdateSelection", runnable, arguments);
        }

        boolean onShowInputRequested(int flags, boolean configChange,
                @NonNull BooleanSupplier supplier) {
            final Bundle arguments = new Bundle();
            arguments.putInt("flags", flags);
            arguments.putBoolean("configChange", configChange);
            return recordEventInternal("onShowInputRequested", supplier::getAsBoolean, arguments);
        }

        void onDestroy(@NonNull Runnable runnable) {
            recordEventInternal("onDestroy", runnable);
        }

        void attachToken(IBinder token, @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putBinder("token", token);
            recordEventInternal("attachToken", runnable, arguments);
        }

        void bindInput(InputBinding binding, @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putParcelable("binding", binding);
            recordEventInternal("bindInput", runnable, arguments);
        }

        void unbindInput(@NonNull Runnable runnable) {
            recordEventInternal("unbindInput", runnable);
        }

        void showSoftInput(int flags, ResultReceiver resultReceiver, @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putInt("flags", flags);
            arguments.putParcelable("resultReceiver", resultReceiver);
            recordEventInternal("showSoftInput", runnable, arguments);
        }

        void hideSoftInput(int flags, ResultReceiver resultReceiver, @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putInt("flags", flags);
            arguments.putParcelable("resultReceiver", resultReceiver);
            recordEventInternal("hideSoftInput", runnable, arguments);
        }

        AbstractInputMethodImpl onCreateInputMethodInterface(
                @NonNull Supplier<AbstractInputMethodImpl> supplier) {
            return recordEventInternal("onCreateInputMethodInterface", supplier);
        }

        void onReceiveCommand(@NonNull ImeCommand command, @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            arguments.putBundle("command", command.toBundle());
            recordEventInternal("onReceiveCommand", runnable, arguments);
        }

        void onHandleCommand(
                @NonNull ImeCommand command, @NonNull Supplier<Object> resultSupplier) {
            final Bundle arguments = new Bundle();
            arguments.putBundle("command", command.toBundle());
            recordEventInternal("onHandleCommand", resultSupplier, arguments);
        }

        void onInputViewLayoutChanged(@NonNull ImeLayoutInfo imeLayoutInfo,
                @NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            imeLayoutInfo.writeToBundle(arguments);
            recordEventInternal("onInputViewLayoutChanged", runnable, arguments);
        }

        void onStrictModeViolated(@NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            recordEventInternal("onStrictModeViolated", runnable, arguments);
        }

        InlineSuggestionsRequest onCreateInlineSuggestionsRequest(
                @NonNull Supplier<InlineSuggestionsRequest> supplier) {
            return recordEventInternal("onCreateInlineSuggestionsRequest", supplier);
        }

        boolean onInlineSuggestionsResponse(@NonNull InlineSuggestionsResponse response,
                @NonNull BooleanSupplier supplier) {
            final Bundle arguments = new Bundle();
            arguments.putParcelable("response", response);
            return recordEventInternal("onInlineSuggestionsResponse", supplier::getAsBoolean,
                    arguments);
        }

        void onInlineSuggestionClickedEvent(@NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            recordEventInternal("onInlineSuggestionClickedEvent", runnable, arguments);
        }

        void onInlineSuggestionLongClickedEvent(@NonNull Runnable runnable) {
            final Bundle arguments = new Bundle();
            recordEventInternal("onInlineSuggestionLongClickedEvent", runnable, arguments);
        }

        void onConfigurationChanged(@NonNull Runnable runnable, Configuration configuration) {
            final Bundle arguments = new Bundle();
            arguments.putParcelable("Configuration", configuration);
            arguments.putInt("ConfigUpdates", configuration.diff(
                    mIme.mLastDispatchedConfiguration));
            recordEventInternal("onConfigurationChanged", runnable, arguments);
        }
    }
}
