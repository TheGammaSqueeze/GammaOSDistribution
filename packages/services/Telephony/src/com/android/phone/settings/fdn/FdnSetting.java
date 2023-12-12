/*
 * Copyright (C) 2008 The Android Open Source Project
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

package com.android.phone.settings.fdn;

import android.app.ActionBar;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.AsyncResult;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceActivity;
import android.preference.PreferenceScreen;
import android.util.Log;
import android.view.MenuItem;
import android.widget.Toast;

import com.android.internal.telephony.CommandException;
import com.android.internal.telephony.Phone;
import com.android.phone.CallFeaturesSetting;
import com.android.phone.PhoneGlobals;
import com.android.phone.R;
import com.android.phone.SubscriptionInfoHelper;

/**
 * FDN settings UI for the Phone app.
 * Rewritten to look and behave closer to the other preferences.
 */
public class FdnSetting extends PreferenceActivity
        implements EditPinPreference.OnPinEnteredListener, Pin2LockedDialogFragment.Listener {

    private static final String LOG_TAG = PhoneGlobals.LOG_TAG;
    private static final boolean DBG = false;

    private SubscriptionInfoHelper mSubscriptionInfoHelper;
    private Phone mPhone;

    /**
     * Events we handle.
     * The first is used for toggling FDN enable, the second for the PIN change.
     */
    private static final int EVENT_PIN2_ENTRY_COMPLETE = 100;
    private static final int EVENT_PIN2_CHANGE_COMPLETE = 200;
    private static final int EVENT_PIN2_CHANGE_COMPLETE_TOGGLE_FDN = 300;

    // String keys for preference lookup
    private static final String BUTTON_FDN_ENABLE_KEY = "button_fdn_enable_key";
    private static final String BUTTON_CHANGE_PIN2_KEY = "button_change_pin2_key";
    private static final String FDN_LIST_PREF_SCREEN_KEY = "fdn_list_pref_screen_key";

    private EditPinPreference mButtonEnableFDN;
    private EditPinPreference mButtonChangePin2;

    // State variables
    private String mOldPin;
    private String mNewPin;
    private String mPuk2;
    private static final int PIN_CHANGE_OLD = 0;
    private static final int PIN_CHANGE_NEW = 1;
    private static final int PIN_CHANGE_REENTER = 2;
    private static final int PIN_CHANGE_PUK = 3;
    private static final int PIN_CHANGE_NEW_PIN_FOR_PUK = 4;
    private static final int PIN_CHANGE_REENTER_PIN_FOR_PUK = 5;
    private int mPinChangeState;
    private boolean mIsPuk2Locked;    // Indicates we know that we are PUK2 blocked.

    private static final String SKIP_OLD_PIN_KEY = "skip_old_pin_key";
    private static final String PIN_CHANGE_STATE_KEY = "pin_change_state_key";
    private static final String OLD_PIN_KEY = "old_pin_key";
    private static final String NEW_PIN_KEY = "new_pin_key";
    private static final String PUK_KEY = "puk_key";
    private static final String DIALOG_MESSAGE_KEY = "dialog_message_key";
    private static final String DIALOG_PIN_ENTRY_KEY = "dialog_pin_entry_key";
    private static final String FDN_DIALOG_MESSAGE_KEY = "fdn_dialog_message_key";
    private static final String FDN_DIALOG_PIN_ENTRY_KEY = "fdn_dialog_pin_entry_key";

    // size limits for the pin.
    private static final int MIN_PIN_LENGTH = 4;
    private static final int MAX_PIN_LENGTH = 8;

    /**
     * Delegate to the respective handlers.
     */
    @Override
    public void onPinEntered(EditPinPreference preference, boolean positiveResult) {
        if (preference == mButtonEnableFDN && (!mIsPuk2Locked || !positiveResult)) {
            toggleFDNEnable(positiveResult);
        } else {
            updatePINChangeState(preference, positiveResult);
        }
    }

    /**
     * Attempt to toggle FDN activation.
     */
    private void toggleFDNEnable(boolean positiveResult) {
        if (!positiveResult) {
            // reset the state on cancel, either to expect PUK2 or PIN2
            if (!mIsPuk2Locked) {
                resetPinChangeState();
            } else {
                resetPinChangeStateForPUK2();
            }
            return;
        }

        // validate the pin first, before submitting it to the RIL for FDN enable.
        String password = mButtonEnableFDN.getText();
        if (validatePin (password, false)) {
            // get the relevant data for the icc call
            boolean isEnabled = mPhone.getIccCard().getIccFdnEnabled();
            Message onComplete = mFDNHandler.obtainMessage(EVENT_PIN2_ENTRY_COMPLETE);

            // make fdn request
            mPhone.getIccCard().setIccFdnEnabled(!isEnabled, password, onComplete);
        } else {
            // throw up error if the pin is invalid.
            displayMessage(R.string.invalidPin2);
        }

        mButtonEnableFDN.setText("");
    }

    /**
     * Attempt to change the pin.
     */
    private void updatePINChangeState(EditPinPreference button, boolean positiveResult) {
        if (DBG) log("updatePINChangeState positive=" + positiveResult
                + " mPinChangeState=" + mPinChangeState
                + " mIsPuk2Locked=" + mIsPuk2Locked);

        if (!positiveResult) {
            // reset the state on cancel, either to expect PUK2 or PIN2
            if (!mIsPuk2Locked) {
                resetPinChangeState();
            } else {
                resetPinChangeStateForPUK2();
            }
            return;
        }

        // Progress through the dialog states, generally in this order:
        //   1. Enter old pin
        //   2. Enter new pin
        //   3. Re-Enter new pin
        // While handling any error conditions that may show up in between.
        // Also handle the PUK2 entry, if it is requested.
        //
        // In general, if any invalid entries are made, the dialog re-
        // appears with text to indicate what the issue is.
        switch (mPinChangeState) {
            case PIN_CHANGE_OLD:
                mOldPin = button.getText();
                button.setText("");
                // if the pin is not valid, display a message and reset the state.
                if (validatePin (mOldPin, false)) {
                    mPinChangeState = PIN_CHANGE_NEW;
                    displayPinChangeDialog(button);
                } else {
                    displayPinChangeDialog(button, R.string.invalidPin2, true);
                }
                break;
            case PIN_CHANGE_NEW:
                mNewPin = button.getText();
                button.setText("");
                // if the new pin is not valid, display a message and reset the state.
                if (validatePin (mNewPin, false)) {
                    mPinChangeState = PIN_CHANGE_REENTER;
                    displayPinChangeDialog(button);
                } else {
                    displayPinChangeDialog(button, R.string.invalidPin2, true);
                }
                break;
            case PIN_CHANGE_REENTER:
                if (validatePin(button.getText(), false)) {
                    // if the re-entered pin is not valid, display a message and reset the state.
                    if (!mNewPin.equals(button.getText())) {
                        mPinChangeState = PIN_CHANGE_NEW;
                        button.setText("");
                        displayPinChangeDialog(button, R.string.mismatchPin2, true);
                    } else {
                        // If the PIN is valid, then we submit the change PIN request or
                        // display the PUK2 dialog if we KNOW that we're PUK2 locked.
                        button.setText("");
                        Message onComplete = mFDNHandler.obtainMessage(
                                EVENT_PIN2_CHANGE_COMPLETE);
                        if (!mIsPuk2Locked) {
                            mPhone.getIccCard().changeIccFdnPassword(mOldPin,
                                    mNewPin, onComplete);
                        } else {
                            mPhone.getIccCard().supplyPuk2(mPuk2, mNewPin,
                                    onComplete);
                        }
                    }
                } else {
                    button.setText("");
                    displayPinChangeDialog(button, R.string.invalidPin2, true);
                }
                break;
            case PIN_CHANGE_PUK:
                // Doh! too many incorrect requests, PUK requested.
                mPuk2 = button.getText();
                button.setText("");
                // if the puk is not valid, display
                // a message and reset the state.
                if (validatePin(mPuk2, true)) {
                    mPinChangeState = PIN_CHANGE_NEW_PIN_FOR_PUK;
                    displayPinChangeDialog(button);
                } else {
                    displayPinChangeDialog(button, R.string.invalidPuk2, true);
                }
                break;
            case PIN_CHANGE_NEW_PIN_FOR_PUK:
                mNewPin = button.getText();
                button.setText("");
                // if the new pin is not valid, display
                // a message and reset the state.
                if (validatePin (mNewPin, false)) {
                    mPinChangeState = PIN_CHANGE_REENTER_PIN_FOR_PUK;
                    displayPinChangeDialog(button);
                } else {
                    displayPinChangeDialog(button, R.string.invalidPin2, true);
                }
                break;
            case PIN_CHANGE_REENTER_PIN_FOR_PUK:
                // if the re-entered pin is not valid, display
                // a message and reset the state.
                if (!mNewPin.equals(button.getText())) {
                    mPinChangeState = PIN_CHANGE_NEW_PIN_FOR_PUK;
                    button.setText("");
                    displayPinChangeDialog(button, R.string.mismatchPin2, true);
                } else {
                    // Both puk2 and new pin2 are ready to submit
                    Message onComplete = null;
                    if (button == mButtonChangePin2) {
                        button.setText("");
                        onComplete = mFDNHandler.obtainMessage(EVENT_PIN2_CHANGE_COMPLETE);
                    } else {
                        onComplete = mFDNHandler.obtainMessage(
                                EVENT_PIN2_CHANGE_COMPLETE_TOGGLE_FDN);
                    }
                    mPhone.getIccCard().supplyPuk2(mPuk2, mNewPin, onComplete);
                }
                break;
        }
    }

    /**
     * Handler for asynchronous replies from the sim.
     */
    private final Handler mFDNHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {

                // when we are enabling FDN, either we are unsuccessful and display
                // a toast, or just update the UI.
                case EVENT_PIN2_ENTRY_COMPLETE: {
                        if (DBG) log("Handle EVENT_PIN2_ENTRY_COMPLETE");
                        AsyncResult ar = (AsyncResult) msg.obj;
                        if (ar.exception != null) {
                            if (ar.exception instanceof CommandException) {
                                int attemptsRemaining = msg.arg1;
                                // see if PUK2 is requested and alert the user accordingly.
                                CommandException.Error e =
                                        ((CommandException) ar.exception).getCommandError();
                                switch (e) {
                                    case SIM_PUK2:
                                        showPin2OrPuk2LockedDialog(Pin2LockedDialogFragment
                                                .DIALOG_ID_PUK2_REQUESTED_ON_PIN_ENTRY);
                                        break;
                                    case PASSWORD_INCORRECT:
                                        displayMessage(R.string.pin2_invalid, attemptsRemaining);
                                        break;
                                    default:
                                        displayMessage(R.string.fdn_failed, attemptsRemaining);
                                        break;
                                }
                            } else {
                                displayMessage(R.string.pin2_error_exception);
                            }
                        }
                        updateEnableFDN();
                    }
                    break;

                // when changing the pin we need to pay attention to whether or not
                // the error requests a PUK (usually after too many incorrect tries)
                // Set the state accordingly.
                case EVENT_PIN2_CHANGE_COMPLETE:
                case EVENT_PIN2_CHANGE_COMPLETE_TOGGLE_FDN: {
                        if (DBG)
                            log("Handle EVENT_PIN2_CHANGE_COMPLETE");
                        AsyncResult ar = (AsyncResult) msg.obj;
                        if (ar.exception != null) {
                            if (ar.exception instanceof CommandException) {
                                int attemptsRemaining = msg.arg1;
                                log("Handle EVENT_PIN2_CHANGE_COMPLETE attemptsRemaining="
                                        + attemptsRemaining);
                                CommandException ce = (CommandException) ar.exception;
                                if (ce.getCommandError() == CommandException.Error.SIM_PUK2) {
                                    // throw an alert dialog on the screen, displaying the
                                    // request for a PUK2.
                                    showPin2OrPuk2LockedDialog(Pin2LockedDialogFragment
                                            .DIALOG_ID_PUK2_REQUESTED_ON_PIN_CHANGED);
                                } else {
                                    if (mIsPuk2Locked && attemptsRemaining == 0) {
                                        showPin2OrPuk2LockedDialog(Pin2LockedDialogFragment
                                                .DIALOG_ID_PUK2_LOCKED_OUT);
                                    } else {
                                        // set the correct error message depending upon the state.
                                        // Reset the state depending upon or knowledge of the PUK
                                        // state.
                                        if (!mIsPuk2Locked) {
                                            displayMessage(R.string.badPin2, attemptsRemaining);
                                            resetPinChangeState();
                                        } else {
                                            displayMessage(R.string.badPuk2, attemptsRemaining);
                                            resetPinChangeStateForPUK2();
                                        }
                                    }
                                }
                            } else {
                                displayMessage(R.string.pin2_error_exception);
                            }
                        } else {
                            if (mPinChangeState == PIN_CHANGE_PUK) {
                                displayMessage(R.string.pin2_unblocked);
                            } else {
                                displayMessage(R.string.pin2_changed);
                            }

                            // reset to normal behaviour on successful change.
                            if (msg.what == EVENT_PIN2_CHANGE_COMPLETE_TOGGLE_FDN) {
                                log("Handle EVENT_PIN2_CHANGE_COMPLETE_TOGGLE_FDN");
                                // activate/deactivate FDN
                                toggleFDNEnable(true);
                            }
                            resetPinChangeState();
                        }
                    }
                    mButtonChangePin2.setText("");
                    mButtonEnableFDN.setText("");
                    break;
            }
        }
    };

    /**
     * Display a toast for message, like the rest of the settings.
     */
    private void displayMessage(int strId, int attemptsRemaining) {
        String s = getString(strId);
        if ((strId == R.string.badPin2) || (strId == R.string.badPuk2) ||
                (strId == R.string.pin2_invalid)) {
            if (attemptsRemaining >= 0) {
                s = getString(strId) + getString(R.string.pin2_attempts, attemptsRemaining);
            } else {
                s = getString(strId);
            }
        }
        log("displayMessage: attemptsRemaining=" + attemptsRemaining + " s=" + s);
        Toast.makeText(this, s, Toast.LENGTH_SHORT).show();
    }

    private void displayMessage(int strId) {
        displayMessage(strId, -1);
    }

    /**
     * The next two functions are for updating the message field on the dialog.
     */
    private void displayPinChangeDialog(EditPinPreference button) {
        displayPinChangeDialog(button, 0, true);
    }

    private void displayPinChangeDialog(EditPinPreference button,
            int strId, boolean shouldDisplay) {
        int msgId;
        switch (mPinChangeState) {
            case PIN_CHANGE_OLD:
                if (button == mButtonEnableFDN) {
                    msgId = R.string.enter_pin2_text;
                } else {
                    msgId = R.string.oldPin2Label;
                }
                break;
            case PIN_CHANGE_NEW:
            case PIN_CHANGE_NEW_PIN_FOR_PUK:
                msgId = R.string.newPin2Label;
                break;
            case PIN_CHANGE_REENTER:
            case PIN_CHANGE_REENTER_PIN_FOR_PUK:
                msgId = R.string.confirmPin2Label;
                break;
            case PIN_CHANGE_PUK:
            default:
                msgId = R.string.label_puk2_code;
                break;
        }

        // append the note / additional message, if needed.
        if (strId != 0) {
            button.setDialogMessage(getText(msgId) + "\n" + getText(strId));
        } else {
            button.setDialogMessage(msgId);
        }

        // only display if requested.
        if (shouldDisplay) {
            button.showPinDialog();
        }
    }

    /**
     * Reset the state of the pin change dialog.
     */
    private final void resetPinChangeState() {
        if (DBG) log("resetPinChangeState");
        mPinChangeState = PIN_CHANGE_OLD;
        displayPinChangeDialog(mButtonEnableFDN, 0, false);
        displayPinChangeDialog(mButtonChangePin2, 0, false);
        mOldPin = mNewPin = "";
        mIsPuk2Locked = false;
    }

    /**
     * Reset the state of the pin change dialog solely for PUK2 use.
     */
    private final void resetPinChangeStateForPUK2() {
        if (DBG) log("resetPinChangeStateForPUK2");
        mPinChangeState = PIN_CHANGE_PUK;
        displayPinChangeDialog(mButtonEnableFDN, 0, false);
        displayPinChangeDialog(mButtonChangePin2, 0, false);
        mOldPin = mNewPin = mPuk2 = "";
        mIsPuk2Locked = true;
    }

    /**
     * Validate the pin entry.
     *
     * @param pin This is the pin to validate
     * @param isPuk Boolean indicating whether we are to treat
     * the pin input as a puk.
     */
    private boolean validatePin(String pin, boolean isPuk) {

        // for pin, we have 4-8 numbers, or puk, we use only 8.
        int pinMinimum = isPuk ? MAX_PIN_LENGTH : MIN_PIN_LENGTH;

        // check validity
        if (pin == null || pin.length() < pinMinimum || pin.length() > MAX_PIN_LENGTH) {
            return false;
        } else {
            return true;
        }
    }

    /**
     * Reflect the updated FDN state in the UI.
     */
    private void updateEnableFDN() {
        if (mPhone.getIccCard().getIccFdnEnabled()) {
            mButtonEnableFDN.setTitle(R.string.enable_fdn_ok);
            mButtonEnableFDN.setSummary(R.string.fdn_enabled);
            mButtonEnableFDN.setDialogTitle(R.string.disable_fdn);
        } else {
            mButtonEnableFDN.setTitle(R.string.disable_fdn_ok);
            mButtonEnableFDN.setSummary(R.string.fdn_disabled);
            mButtonEnableFDN.setDialogTitle(R.string.enable_fdn);
        }
    }

    /**
    * Reflect the updated change PIN2 state in the UI.
    */
    private void updateChangePIN2() {
        if (mPhone.getIccCard().getIccPuk2Blocked()) {
            showPin2OrPuk2LockedDialog(Pin2LockedDialogFragment.DIALOG_ID_PUK2_LOCKED_OUT);
            resetPinChangeStateForPUK2();
        } else if (mPhone.getIccCard().getIccPin2Blocked()) {
            // If the pin2 is blocked, the state of the change pin2 dialog
            // should be set for puk2 use (that is, the user should be prompted
            // to enter puk2 code instead of old pin2).
            resetPinChangeStateForPUK2();
        } else {
            resetPinChangeState();
        }
    }

    @Override
    protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);

        mSubscriptionInfoHelper = new SubscriptionInfoHelper(this, getIntent());
        mPhone = mSubscriptionInfoHelper.getPhone();

        addPreferencesFromResource(R.xml.fdn_setting);

        //get UI object references
        PreferenceScreen prefSet = getPreferenceScreen();
        mButtonEnableFDN = (EditPinPreference) prefSet.findPreference(BUTTON_FDN_ENABLE_KEY);
        mButtonChangePin2 = (EditPinPreference) prefSet.findPreference(BUTTON_CHANGE_PIN2_KEY);

        //assign click listener and update state
        mButtonEnableFDN.setOnPinEnteredListener(this);
        updateEnableFDN();

        mButtonChangePin2.setOnPinEnteredListener(this);

        PreferenceScreen fdnListPref =
                (PreferenceScreen) prefSet.findPreference(FDN_LIST_PREF_SCREEN_KEY);
        fdnListPref.setIntent(mSubscriptionInfoHelper.getIntent(FdnList.class));

        // Only reset the pin change dialog if we're not in the middle of changing it.
        if (icicle == null) {
            resetPinChangeState();
        } else {
            mIsPuk2Locked = icicle.getBoolean(SKIP_OLD_PIN_KEY);
            mPinChangeState = icicle.getInt(PIN_CHANGE_STATE_KEY);
            mOldPin = icicle.getString(OLD_PIN_KEY);
            mNewPin = icicle.getString(NEW_PIN_KEY);
            mPuk2 = icicle.getString(PUK_KEY);
            mButtonChangePin2.setDialogMessage(
                    icicle.getString(DIALOG_MESSAGE_KEY));
            mButtonChangePin2.setText(
                    icicle.getString(DIALOG_PIN_ENTRY_KEY));
            mButtonEnableFDN.setDialogMessage(
                    icicle.getString(FDN_DIALOG_MESSAGE_KEY));
            mButtonEnableFDN.setText(icicle.getString(FDN_DIALOG_PIN_ENTRY_KEY));
        }

        ActionBar actionBar = getActionBar();
        if (actionBar != null) {
            // android.R.id.home will be triggered in onOptionsItemSelected()
            actionBar.setDisplayHomeAsUpEnabled(true);
            mSubscriptionInfoHelper.setActionBarTitle(
                    actionBar, getResources(), R.string.fdn_with_label);
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        mPhone = mSubscriptionInfoHelper.getPhone();
        updateEnableFDN();
        updateChangePIN2();
    }

    /**
     * Save the state of the pin change.
     */
    @Override
    protected void onSaveInstanceState(Bundle out) {
        super.onSaveInstanceState(out);
        out.putBoolean(SKIP_OLD_PIN_KEY, mIsPuk2Locked);
        out.putInt(PIN_CHANGE_STATE_KEY, mPinChangeState);
        out.putString(OLD_PIN_KEY, mOldPin);
        out.putString(NEW_PIN_KEY, mNewPin);
        out.putString(PUK_KEY, mPuk2);
        if (mButtonChangePin2.isEnabled()) {
            out.putString(DIALOG_MESSAGE_KEY, mButtonChangePin2.getDialogMessage().toString());
            out.putString(DIALOG_PIN_ENTRY_KEY, mButtonChangePin2.getText());
        }
        if (mButtonEnableFDN.isEnabled()) {
            CharSequence dialogMsg = mButtonEnableFDN.getDialogMessage();
            if (dialogMsg != null) {
                out.putString(FDN_DIALOG_MESSAGE_KEY,
                        mButtonEnableFDN.getDialogMessage().toString());
            }
            out.putString(FDN_DIALOG_PIN_ENTRY_KEY, mButtonEnableFDN.getText());
        }
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        final int itemId = item.getItemId();
        if (itemId == android.R.id.home) {  // See ActionBar#setDisplayHomeAsUpEnabled()
            CallFeaturesSetting.goUpToTopLevelSetting(this, mSubscriptionInfoHelper);
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    private void log(String msg) {
        Log.d(LOG_TAG, "FdnSetting: " + msg);
    }

    @Override
    public void onRequestPuk2(int id) {
        resetPinChangeStateForPUK2();
        final EditPinPreference button =
                (id == Pin2LockedDialogFragment.DIALOG_ID_PUK2_REQUESTED_ON_PIN_CHANGED)
                        ? mButtonChangePin2 : mButtonEnableFDN;
        displayPinChangeDialog(button, 0, true);
    }

    private void showPin2OrPuk2LockedDialog(int id) {
        final FragmentManager fragmentManager = getFragmentManager();
        Pin2LockedDialogFragment dialogFragment = (Pin2LockedDialogFragment) fragmentManager
                .findFragmentByTag(Pin2LockedDialogFragment.TAG_PIN2_LOCKED_DIALOG);
        if (dialogFragment == null) {
            dialogFragment = new Pin2LockedDialogFragment();
            Bundle args = new Bundle();
            args.putInt(Pin2LockedDialogFragment.KEY_DIALOG_ID, id);
            dialogFragment.setArguments(args);
            dialogFragment.show(fragmentManager, Pin2LockedDialogFragment.TAG_PIN2_LOCKED_DIALOG);
        } else {
            FragmentTransaction transaction = fragmentManager.beginTransaction();
            transaction.show(dialogFragment);
            transaction.commitNow();
        }
    }
}

