package com.android.libraries.entitlement;

import android.net.Network;
import androidx.annotation.Nullable;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_CarrierConfig extends CarrierConfig {

  private final String serverUrl;

  private final int timeoutInSec;

  private final Network network;

  private AutoValue_CarrierConfig(
      String serverUrl,
      int timeoutInSec,
      @Nullable Network network) {
    this.serverUrl = serverUrl;
    this.timeoutInSec = timeoutInSec;
    this.network = network;
  }

  @Override
  public String serverUrl() {
    return serverUrl;
  }

  @Override
  public int timeoutInSec() {
    return timeoutInSec;
  }

  @Nullable
  @Override
  public Network network() {
    return network;
  }

  @Override
  public String toString() {
    return "CarrierConfig{"
        + "serverUrl=" + serverUrl + ", "
        + "timeoutInSec=" + timeoutInSec + ", "
        + "network=" + network
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof CarrierConfig) {
      CarrierConfig that = (CarrierConfig) o;
      return this.serverUrl.equals(that.serverUrl())
          && this.timeoutInSec == that.timeoutInSec()
          && (this.network == null ? that.network() == null : this.network.equals(that.network()));
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= serverUrl.hashCode();
    h$ *= 1000003;
    h$ ^= timeoutInSec;
    h$ *= 1000003;
    h$ ^= (network == null) ? 0 : network.hashCode();
    return h$;
  }

  static final class Builder extends CarrierConfig.Builder {
    private String serverUrl;
    private Integer timeoutInSec;
    private Network network;
    Builder() {
    }
    @Override
    public CarrierConfig.Builder setServerUrl(String serverUrl) {
      if (serverUrl == null) {
        throw new NullPointerException("Null serverUrl");
      }
      this.serverUrl = serverUrl;
      return this;
    }
    @Override
    public CarrierConfig.Builder setTimeoutInSec(int timeoutInSec) {
      this.timeoutInSec = timeoutInSec;
      return this;
    }
    @Override
    public CarrierConfig.Builder setNetwork(Network network) {
      this.network = network;
      return this;
    }
    @Override
    public CarrierConfig build() {
      String missing = "";
      if (this.serverUrl == null) {
        missing += " serverUrl";
      }
      if (this.timeoutInSec == null) {
        missing += " timeoutInSec";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_CarrierConfig(
          this.serverUrl,
          this.timeoutInSec,
          this.network);
    }
  }

}
