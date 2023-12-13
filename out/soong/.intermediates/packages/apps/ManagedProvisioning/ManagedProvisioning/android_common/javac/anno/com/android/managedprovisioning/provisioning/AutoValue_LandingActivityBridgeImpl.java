package com.android.managedprovisioning.provisioning;

import com.android.managedprovisioning.common.AccessibilityContextMenuMaker;
import com.android.managedprovisioning.common.InitializeLayoutConsumerHandler;
import com.android.managedprovisioning.common.Utils;
import com.android.managedprovisioning.model.ProvisioningParams;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_LandingActivityBridgeImpl extends LandingActivityBridgeImpl {

  private final Utils utils;

  private final ProvisioningParams params;

  private final LandingActivityBridgeCallbacks bridgeCallbacks;

  private final AccessibilityContextMenuMaker accessibilityContextMenuMaker;

  private final InitializeLayoutConsumerHandler initializeLayoutParamsConsumer;

  private AutoValue_LandingActivityBridgeImpl(
      Utils utils,
      ProvisioningParams params,
      LandingActivityBridgeCallbacks bridgeCallbacks,
      AccessibilityContextMenuMaker accessibilityContextMenuMaker,
      InitializeLayoutConsumerHandler initializeLayoutParamsConsumer) {
    this.utils = utils;
    this.params = params;
    this.bridgeCallbacks = bridgeCallbacks;
    this.accessibilityContextMenuMaker = accessibilityContextMenuMaker;
    this.initializeLayoutParamsConsumer = initializeLayoutParamsConsumer;
  }

  @Override
  Utils getUtils() {
    return utils;
  }

  @Override
  ProvisioningParams getParams() {
    return params;
  }

  @Override
  LandingActivityBridgeCallbacks getBridgeCallbacks() {
    return bridgeCallbacks;
  }

  @Override
  AccessibilityContextMenuMaker getAccessibilityContextMenuMaker() {
    return accessibilityContextMenuMaker;
  }

  @Override
  InitializeLayoutConsumerHandler getInitializeLayoutParamsConsumer() {
    return initializeLayoutParamsConsumer;
  }

  @Override
  public String toString() {
    return "LandingActivityBridgeImpl{"
        + "utils=" + utils + ", "
        + "params=" + params + ", "
        + "bridgeCallbacks=" + bridgeCallbacks + ", "
        + "accessibilityContextMenuMaker=" + accessibilityContextMenuMaker + ", "
        + "initializeLayoutParamsConsumer=" + initializeLayoutParamsConsumer
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof LandingActivityBridgeImpl) {
      LandingActivityBridgeImpl that = (LandingActivityBridgeImpl) o;
      return this.utils.equals(that.getUtils())
          && this.params.equals(that.getParams())
          && this.bridgeCallbacks.equals(that.getBridgeCallbacks())
          && this.accessibilityContextMenuMaker.equals(that.getAccessibilityContextMenuMaker())
          && this.initializeLayoutParamsConsumer.equals(that.getInitializeLayoutParamsConsumer());
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
    h$ ^= bridgeCallbacks.hashCode();
    h$ *= 1000003;
    h$ ^= accessibilityContextMenuMaker.hashCode();
    h$ *= 1000003;
    h$ ^= initializeLayoutParamsConsumer.hashCode();
    return h$;
  }

  static final class Builder extends LandingActivityBridgeImpl.Builder {
    private Utils utils;
    private ProvisioningParams params;
    private LandingActivityBridgeCallbacks bridgeCallbacks;
    private AccessibilityContextMenuMaker accessibilityContextMenuMaker;
    private InitializeLayoutConsumerHandler initializeLayoutParamsConsumer;
    Builder() {
    }
    @Override
    LandingActivityBridgeImpl.Builder setUtils(Utils utils) {
      if (utils == null) {
        throw new NullPointerException("Null utils");
      }
      this.utils = utils;
      return this;
    }
    @Override
    LandingActivityBridgeImpl.Builder setParams(ProvisioningParams params) {
      if (params == null) {
        throw new NullPointerException("Null params");
      }
      this.params = params;
      return this;
    }
    @Override
    LandingActivityBridgeImpl.Builder setBridgeCallbacks(LandingActivityBridgeCallbacks bridgeCallbacks) {
      if (bridgeCallbacks == null) {
        throw new NullPointerException("Null bridgeCallbacks");
      }
      this.bridgeCallbacks = bridgeCallbacks;
      return this;
    }
    @Override
    LandingActivityBridgeImpl.Builder setAccessibilityContextMenuMaker(AccessibilityContextMenuMaker accessibilityContextMenuMaker) {
      if (accessibilityContextMenuMaker == null) {
        throw new NullPointerException("Null accessibilityContextMenuMaker");
      }
      this.accessibilityContextMenuMaker = accessibilityContextMenuMaker;
      return this;
    }
    @Override
    LandingActivityBridgeImpl.Builder setInitializeLayoutParamsConsumer(InitializeLayoutConsumerHandler initializeLayoutParamsConsumer) {
      if (initializeLayoutParamsConsumer == null) {
        throw new NullPointerException("Null initializeLayoutParamsConsumer");
      }
      this.initializeLayoutParamsConsumer = initializeLayoutParamsConsumer;
      return this;
    }
    @Override
    LandingActivityBridgeImpl build() {
      String missing = "";
      if (this.utils == null) {
        missing += " utils";
      }
      if (this.params == null) {
        missing += " params";
      }
      if (this.bridgeCallbacks == null) {
        missing += " bridgeCallbacks";
      }
      if (this.accessibilityContextMenuMaker == null) {
        missing += " accessibilityContextMenuMaker";
      }
      if (this.initializeLayoutParamsConsumer == null) {
        missing += " initializeLayoutParamsConsumer";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_LandingActivityBridgeImpl(
          this.utils,
          this.params,
          this.bridgeCallbacks,
          this.accessibilityContextMenuMaker,
          this.initializeLayoutParamsConsumer);
    }
  }

}
