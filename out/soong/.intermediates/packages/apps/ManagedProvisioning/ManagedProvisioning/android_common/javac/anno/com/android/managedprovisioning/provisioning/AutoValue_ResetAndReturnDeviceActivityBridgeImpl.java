package com.android.managedprovisioning.provisioning;

import com.android.managedprovisioning.common.InitializeLayoutConsumerHandler;
import com.android.managedprovisioning.common.Utils;
import com.android.managedprovisioning.model.ProvisioningParams;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_ResetAndReturnDeviceActivityBridgeImpl extends ResetAndReturnDeviceActivityBridgeImpl {

  private final Utils utils;

  private final ProvisioningParams params;

  private final ResetAndReturnDeviceActivityBridgeCallback bridgeCallback;

  private final InitializeLayoutConsumerHandler initializeLayoutParamsConsumer;

  private AutoValue_ResetAndReturnDeviceActivityBridgeImpl(
      Utils utils,
      ProvisioningParams params,
      ResetAndReturnDeviceActivityBridgeCallback bridgeCallback,
      InitializeLayoutConsumerHandler initializeLayoutParamsConsumer) {
    this.utils = utils;
    this.params = params;
    this.bridgeCallback = bridgeCallback;
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
  ResetAndReturnDeviceActivityBridgeCallback getBridgeCallback() {
    return bridgeCallback;
  }

  @Override
  InitializeLayoutConsumerHandler getInitializeLayoutParamsConsumer() {
    return initializeLayoutParamsConsumer;
  }

  @Override
  public String toString() {
    return "ResetAndReturnDeviceActivityBridgeImpl{"
        + "utils=" + utils + ", "
        + "params=" + params + ", "
        + "bridgeCallback=" + bridgeCallback + ", "
        + "initializeLayoutParamsConsumer=" + initializeLayoutParamsConsumer
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ResetAndReturnDeviceActivityBridgeImpl) {
      ResetAndReturnDeviceActivityBridgeImpl that = (ResetAndReturnDeviceActivityBridgeImpl) o;
      return this.utils.equals(that.getUtils())
          && this.params.equals(that.getParams())
          && this.bridgeCallback.equals(that.getBridgeCallback())
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
    h$ ^= bridgeCallback.hashCode();
    h$ *= 1000003;
    h$ ^= initializeLayoutParamsConsumer.hashCode();
    return h$;
  }

  static final class Builder extends ResetAndReturnDeviceActivityBridgeImpl.Builder {
    private Utils utils;
    private ProvisioningParams params;
    private ResetAndReturnDeviceActivityBridgeCallback bridgeCallback;
    private InitializeLayoutConsumerHandler initializeLayoutParamsConsumer;
    Builder() {
    }
    @Override
    ResetAndReturnDeviceActivityBridgeImpl.Builder setUtils(Utils utils) {
      if (utils == null) {
        throw new NullPointerException("Null utils");
      }
      this.utils = utils;
      return this;
    }
    @Override
    ResetAndReturnDeviceActivityBridgeImpl.Builder setParams(ProvisioningParams params) {
      if (params == null) {
        throw new NullPointerException("Null params");
      }
      this.params = params;
      return this;
    }
    @Override
    ResetAndReturnDeviceActivityBridgeImpl.Builder setBridgeCallback(ResetAndReturnDeviceActivityBridgeCallback bridgeCallback) {
      if (bridgeCallback == null) {
        throw new NullPointerException("Null bridgeCallback");
      }
      this.bridgeCallback = bridgeCallback;
      return this;
    }
    @Override
    ResetAndReturnDeviceActivityBridgeImpl.Builder setInitializeLayoutParamsConsumer(InitializeLayoutConsumerHandler initializeLayoutParamsConsumer) {
      if (initializeLayoutParamsConsumer == null) {
        throw new NullPointerException("Null initializeLayoutParamsConsumer");
      }
      this.initializeLayoutParamsConsumer = initializeLayoutParamsConsumer;
      return this;
    }
    @Override
    ResetAndReturnDeviceActivityBridgeImpl build() {
      String missing = "";
      if (this.utils == null) {
        missing += " utils";
      }
      if (this.params == null) {
        missing += " params";
      }
      if (this.bridgeCallback == null) {
        missing += " bridgeCallback";
      }
      if (this.initializeLayoutParamsConsumer == null) {
        missing += " initializeLayoutParamsConsumer";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_ResetAndReturnDeviceActivityBridgeImpl(
          this.utils,
          this.params,
          this.bridgeCallback,
          this.initializeLayoutParamsConsumer);
    }
  }

}
