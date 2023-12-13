package com.android.imsserviceentitlement.ts43;

import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Ts43VolteStatus extends Ts43VolteStatus {

  private final int entitlementStatus;

  private AutoValue_Ts43VolteStatus(
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
    if (o instanceof Ts43VolteStatus) {
      Ts43VolteStatus that = (Ts43VolteStatus) o;
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

  static final class Builder extends Ts43VolteStatus.Builder {
    private Integer entitlementStatus;
    Builder() {
    }
    @Override
    public Ts43VolteStatus.Builder setEntitlementStatus(int entitlementStatus) {
      this.entitlementStatus = entitlementStatus;
      return this;
    }
    @Override
    public Ts43VolteStatus build() {
      String missing = "";
      if (this.entitlementStatus == null) {
        missing += " entitlementStatus";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_Ts43VolteStatus(
          this.entitlementStatus);
    }
  }

}
