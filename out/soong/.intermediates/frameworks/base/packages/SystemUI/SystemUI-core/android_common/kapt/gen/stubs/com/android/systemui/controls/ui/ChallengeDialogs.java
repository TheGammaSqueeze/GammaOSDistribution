package com.android.systemui.controls.ui;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.service.controls.actions.BooleanAction;
import android.service.controls.actions.CommandAction;
import android.service.controls.actions.ControlAction;
import android.service.controls.actions.FloatAction;
import android.service.controls.actions.ModeAction;
import android.text.InputType;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.WindowManager;
import android.view.inputmethod.InputMethodManager;
import android.widget.CheckBox;
import android.widget.EditText;
import com.android.systemui.R;

/**
 * Creates all dialogs for challengeValues that can occur from a call to
 * [ControlsProviderService#performControlAction]. The types of challenge responses are listed in
 * [ControlAction.ResponseResult].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000H\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\u00072\u0006\u0010\t\u001a\u00020\nH\u0002J\u001e\u0010\u000b\u001a\u0004\u0018\u00010\f2\u0006\u0010\r\u001a\u00020\u000e2\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010J.\u0010\u0012\u001a\u0004\u0018\u00010\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00142\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010J\u0018\u0010\u0016\u001a\u00020\u00112\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u0014H\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/ChallengeDialogs;", "", "()V", "STYLE", "", "WINDOW_TYPE", "addChallengeValue", "Landroid/service/controls/actions/ControlAction;", "action", "challengeValue", "", "createConfirmationDialog", "Landroid/app/Dialog;", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "onCancel", "Lkotlin/Function0;", "", "createPinDialog", "useAlphaNumeric", "", "useRetryStrings", "setInputType", "editText", "Landroid/widget/EditText;", "useTextInput"})
public final class ChallengeDialogs {
    private static final int WINDOW_TYPE = android.view.WindowManager.LayoutParams.TYPE_VOLUME_OVERLAY;
    private static final int STYLE = android.R.style.Theme_DeviceDefault_Dialog_Alert;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.ui.ChallengeDialogs INSTANCE = null;
    
    /**
     * AlertDialogs to handle [ControlAction#RESPONSE_CHALLENGE_PIN] and
     * [ControlAction#RESPONSE_CHALLENGE_PIN] responses, decided by the useAlphaNumeric
     * parameter.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.app.Dialog createPinDialog(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, boolean useAlphaNumeric, boolean useRetryStrings, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> onCancel) {
        return null;
    }
    
    /**
     * AlertDialogs to handle [ControlAction#RESPONSE_CHALLENGE_ACK] response type.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.app.Dialog createConfirmationDialog(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> onCancel) {
        return null;
    }
    
    private final void setInputType(android.widget.EditText editText, boolean useTextInput) {
    }
    
    private final android.service.controls.actions.ControlAction addChallengeValue(android.service.controls.actions.ControlAction action, java.lang.String challengeValue) {
        return null;
    }
    
    private ChallengeDialogs() {
        super();
    }
}