package com.android.imsserviceentitlement.ts43;

import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Ts43VowifiStatus extends Ts43VowifiStatus {

  private final int entitlementStatus;

  private final int tcStatus;

  private final int addrStatus;

  private final int provStatus;

  private AutoValue_Ts43VowifiStatus(
      int entitlementStatus,
      int tcStatus,
      int addrStatus,
      int provStatus) {
    this.entitlementStatus = entitlementStatus;
    this.tcStatus = tcStatus;
    this.addrStatus = addrStatus;
    this.provStatus = provStatus;
  }

  @Override
  public int entitlementStatus() {
    return entitlementStatus;
  }

  @Override
  public int tcStatus() {
    return tcStatus;
  }

  @Override
  public int addrStatus() {
    return addrStatus;
  }

  @Override
  public int provStatus() {
    return provStatus;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Ts43VowifiStatus) {
      Ts43VowifiStatus that = (Ts43VowifiStatus) o;
      return this.entitlementStatus == that.entitlementStatus()
          && this.tcStatus == that.tcStatus()
          && this.addrStatus == that.addrStatus()
          && this.provStatus == that.provStatus();
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= entitlementStatus;
    h$ *= 1000003;
    h$ ^= tcStatus;
    h$ *= 1000003;
    h$ ^= addrStatus;
    h$ *= 1000003;
    h$ ^= provStatus;
    return h$;
  }

  static final class Builder extends Ts43VowifiStatus.Builder {
    private Integer entitlementStatus;
    private Integer tcStatus;
    private Integer addrStatus;
    private Integer provStatus;
    Builder() {
    }
    @Override
    public Ts43VowifiStatus.Builder setEntitlementStatus(int entitlementStatus) {
      this.entitlementStatus = entitlementStatus;
      return this;
    }
    @Override
    public Ts43VowifiStatus.Builder setTcStatus(int tcStatus) {
      this.tcStatus = tcStatus;
      return this;
    }
    @Override
    public Ts43VowifiStatus.Builder setAddrStatus(int addrStatus) {
      this.addrStatus = addrStatus;
      return this;
    }
    @Override
    public Ts43VowifiStatus.Builder setProvStatus(int provStatus) {
      this.provStatus = provStatus;
      return this;
    }
    @Override
    public Ts43VowifiStatus build() {
      String missing = "";
      if (this.entitlementStatus == null) {
        missing += " entitlementStatus";
      }
      if (this.tcStatus == null) {
        missing += " tcStatus";
      }
      if (this.addrStatus == null) {
        missing += " addrStatus";
      }
      if (this.provStatus == null) {
        missing += " provStatus";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_Ts43VowifiStatus(
          this.entitlementStatus,
          this.tcStatus,
          this.addrStatus,
          this.provStatus);
    }
  }

}
