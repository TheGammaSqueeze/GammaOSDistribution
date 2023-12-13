package com.android.imsserviceentitlement.ts43;

import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Ts43SmsOverIpStatus extends Ts43SmsOverIpStatus {

  private final int entitlementStatus;

  private AutoValue_Ts43SmsOverIpStatus(
      int entitlementStatus) {
    this.entitlementStatus = entitlementStatus;
  }

  @Override
  public int entitlementStatus() {
    return entitlementStatus;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Ts43SmsOverIpStatus) {
      Ts43SmsOverIpStatus that = (Ts43SmsOverIpStatus) o;
      return this.entitlementStatus == that.entitlementStatus();
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= entitlementStatus;
    return h$;
  }

  static final class Builder extends Ts43SmsOverIpStatus.Builder {
    private Integer entitlementStatus;
    Builder() {
    }
    @Override
    public Ts43SmsOverIpStatus.Builder setEntitlementStatus(int entitlementStatus) {
      this.entitlementStatus = entitlementStatus;
      return this;
    }
    @Override
    public Ts43SmsOverIpStatus build() {
      String missing = "";
      if (this.entitlementStatus == null) {
        missing += " entitlementStatus";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_Ts43SmsOverIpStatus(
          this.entitlementStatus);
    }
  }

}
