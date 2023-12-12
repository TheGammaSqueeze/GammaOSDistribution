package com.android.managedprovisioning.provisioning;

import androidx.annotation.StringRes;
import com.android.managedprovisioning.common.InitializeLayoutConsumerHandler;
import com.android.managedprovisioning.common.Utils;
import com.android.managedprovisioning.model.ProvisioningParams;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_ProvisioningActivityBridgeImpl extends ProvisioningActivityBridgeImpl {

  private final Utils utils;

  private final ProvisioningParams params;

  private final int provisioningMode;

  private final ProvisioningManager provisioningManager;

  private final TransitionAnimationHelper.TransitionAnimationCallback transitionAnimationCallback;

  private final InitializeLayoutConsumerHandler initializeLayoutParamsConsumer;

  private final boolean shouldSkipEducationScreens;

  private final int progressLabelResId;

  private final ProvisioningActivityBridgeCallbacks bridgeCallbacks;

  private final TransitionAnimationHelper.TransitionAnimationStateManager stateManager;

  private AutoValue_ProvisioningActivityBridgeImpl(
      Utils utils,
      ProvisioningParams params,
      int provisioningMode,
      ProvisioningManager provisioningManager,
      TransitionAnimationHelper.TransitionAnimationCallback transitionAnimationCallback,
      InitializeLayoutConsumerHandler initializeLayoutParamsConsumer,
      boolean shouldSkipEducationScreens,
      int progressLabelResId,
      ProvisioningActivityBridgeCallbacks bridgeCallbacks,
      TransitionAnimationHelper.TransitionAnimationStateManager stateManager) {
    this.utils = utils;
    this.params = params;
    this.provisioningMode = provisioningMode;
    this.provisioningManager = provisioningManager;
    this.transitionAnimationCallback = transitionAnimationCallback;
    this.initializeLayoutParamsConsumer = initializeLayoutParamsConsumer;
    this.shouldSkipEducationScreens = shouldSkipEducationScreens;
    this.progressLabelResId = progressLabelResId;
    this.bridgeCallbacks = bridgeCallbacks;
    this.stateManager = stateManager;
  }

  @Override
  Utils getUtils() {
    return utils;
  }

  @Override
  ProvisioningParams getParams() {
    return params;
  }

  @ProvisioningActivity.ProvisioningMode
  @Override
  int getProvisioningMode() {
    return provisioningMode;
  }

  @Override
  ProvisioningManager getProvisioningManager() {
    return provisioningManager;
  }

  @Override
  TransitionAnimationHelper.TransitionAnimationCallback getTransitionAnimationCallback() {
    return transitionAnimationCallback;
  }

  @Override
  InitializeLayoutConsumerHandler getInitializeLayoutParamsConsumer() {
    return initializeLayoutParamsConsumer;
  }

  @Override
  boolean getShouldSkipEducationScreens() {
    return shouldSkipEducationScreens;
  }

  @StringRes
  @Override
  int getProgressLabelResId() {
    return progressLabelResId;
  }

  @Override
  ProvisioningActivityBridgeCallbacks getBridgeCallbacks() {
    return bridgeCallbacks;
  }

  @Override
  TransitionAnimationHelper.TransitionAnimationStateManager getStateManager() {
    return stateManager;
  }

  @Override
  public String toString() {
    return "ProvisioningActivityBridgeImpl{"
        + "utils=" + utils + ", "
        + "params=" + params + ", "
        + "provisioningMode=" + provisioningMode + ", "
        + "provisioningManager=" + provisioningManager + ", "
        + "transitionAnimationCallback=" + transitionAnimationCallback + ", "
        + "initializeLayoutParamsConsumer=" + initializeLayoutParamsConsumer + ", "
        + "shouldSkipEducationScreens=" + shouldSkipEducationScreens + ", "
        + "progressLabelResId=" + progressLabelResId + ", "
        + "bridgeCallbacks=" + bridgeCallbacks + ", "
        + "stateManager=" + stateManager
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ProvisioningActivityBridgeImpl) {
      ProvisioningActivityBridgeImpl that = (ProvisioningActivityBridgeImpl) o;
      return this.utils.equals(that.getUtils())
          && this.params.equals(that.getParams())
          && this.provisioningMode == that.getProvisioningMode()
          && this.provisioningManager.equals(that.getProvisioningManager())
          && this.transitionAnimationCallback.equals(that.getTransitionAnimationCallback())
          && this.initializeLayoutParamsConsumer.equals(that.getInitializeLayoutParamsConsumer())
          && this.shouldSkipEducationScreens == that.getShouldSkipEducationScreens()
          && this.progressLabelResId == that.getProgressLabelResId()
          && this.bridgeCallbacks.equals(that.getBridgeCallbacks())
          && this.stateManager.equals(that.getStateManager());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= utils.hashCode();
    h$ *= 1000003;
    h$ ^= params.hashCode();
    h$ *= 1000003;
    h$ ^= provisioningMode;
    h$ *= 1000003;
    h$ ^= provisioningManager.hashCode();
    h$ *= 1000003;
    h$ ^= transitionAnimationCallback.hashCode();
    h$ *= 1000003;
    h$ ^= initializeLayoutParamsConsumer.hashCode();
    h$ *= 1000003;
    h$ ^= shouldSkipEducationScreens ? 1231 : 1237;
    h$ *= 1000003;
    h$ ^= progressLabelResId;
    h$ *= 1000003;
    h$ ^= bridgeCallbacks.hashCode();
    h$ *= 1000003;
    h$ ^= stateManager.hashCode();
    return h$;
  }

  static final class Builder extends ProvisioningActivityBridgeImpl.Builder {
    private Utils utils;
    private ProvisioningParams params;
    private Integer provisioningMode;
    private ProvisioningManager provisioningManager;
    private TransitionAnimationHelper.TransitionAnimationCallback transitionAnimationCallback;
    private InitializeLayoutConsumerHandler initializeLayoutParamsConsumer;
    private Boolean shouldSkipEducationScreens;
    private Integer progressLabelResId;
    private ProvisioningActivityBridgeCallbacks bridgeCallbacks;
    private TransitionAnimationHelper.TransitionAnimationStateManager stateManager;
    Builder() {
    }
    @Override
    ProvisioningActivityBridgeImpl.Builder setUtils(Utils utils) {
      if (utils == null) {
        throw new NullPointerException("Null utils");
      }
      this.utils = utils;
      return this;
    }
    @Override
    ProvisioningActivityBridgeImpl.Builder setParams(ProvisioningParams params) {
      if (params == null) {
        throw new NullPointerException("Null params");
      }
      this.params = params;
      return this;
    }
    @Override
    ProvisioningActivityBridgeImpl.Builder setProvisioningMode(int provisioningMode) {
      this.provisioningMode = provisioningMode;
      return this;
    }
    @Override
    ProvisioningActivityBridgeImpl.Builder setProvisioningManager(ProvisioningManager provisioningManager) {
      if (provisioningManager == null) {
        throw new NullPointerException("Null provisioningManager");
      }
      this.provisioningManager = provisioningManager;
      return this;
    }
    @Override
    ProvisioningActivityBridgeImpl.Builder setTransitionAnimationCallback(TransitionAnimationHelper.TransitionAnimationCallback transitionAnimationCallback) {
      if (transitionAnimationCallback == null) {
        throw new NullPointerException("Null transitionAnimationCallback");
      }
      this.transitionAnimationCallback = transitionAnimationCallback;
      return this;
    }
    @Override
    ProvisioningActivityBridgeImpl.Builder setInitializeLayoutParamsConsumer(InitializeLayoutConsumerHandler initializeLayoutParamsConsumer) {
      if (initializeLayoutParamsConsumer == null) {
        throw new NullPointerException("Null initializeLayoutParamsConsumer");
      }
      this.initializeLayoutParamsConsumer = initializeLayoutParamsConsumer;
      return this;
    }
    @Override
    ProvisioningActivityBridgeImpl.Builder setShouldSkipEducationScreens(boolean shouldSkipEducationScreens) {
      this.shouldSkipEducationScreens = shouldSkipEducationScreens;
      return this;
    }
    @Override
    ProvisioningActivityBridgeImpl.Builder setProgressLabelResId(int progressLabelResId) {
      this.progressLabelResId = progressLabelResId;
      return this;
    }
    @Override
    ProvisioningActivityBridgeImpl.Builder setBridgeCallbacks(ProvisioningActivityBridgeCallbacks bridgeCallbacks) {
      if (bridgeCallbacks == null) {
        throw new NullPointerException("Null bridgeCallbacks");
      }
      this.bridgeCallbacks = bridgeCallbacks;
      return this;
    }
    @Override
    ProvisioningActivityBridgeImpl.Builder setStateManager(TransitionAnimationHelper.TransitionAnimationStateManager stateManager) {
      if (stateManager == null) {
        throw new NullPointerException("Null stateManager");
      }
      this.stateManager = stateManager;
      return this;
    }
    @Override
    ProvisioningActivityBridgeImpl build() {
      String missing = "";
      if (this.utils == null) {
        missing += " utils";
      }
      if (this.params == null) {
        missing += " params";
      }
      if (this.provisioningMode == null) {
        missing += " provisioningMode";
      }
      if (this.provisioningManager == null) {
        missing += " provisioningManager";
      }
      if (this.transitionAnimationCallback == null) {
        missing += " transitionAnimationCallback";
      }
      if (this.initializeLayoutParamsConsumer == null) {
        missing += " initializeLayoutParamsConsumer";
      }
      if (this.shouldSkipEducationScreens == null) {
        missing += " shouldSkipEducationScreens";
      }
      if (this.progressLabelResId == null) {
        missing += " progressLabelResId";
      }
      if (this.bridgeCallbacks == null) {
        missing += " bridgeCallbacks";
      }
      if (this.stateManager == null) {
        missing += " stateManager";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_ProvisioningActivityBridgeImpl(
          this.utils,
          this.params,
          this.provisioningMode,
          this.provisioningManager,
          this.transitionAnimationCallback,
          this.initializeLayoutParamsConsumer,
          this.shouldSkipEducationScreens,
          this.progressLabelResId,
          this.bridgeCallbacks,
          this.stateManager);
    }
  }

}
