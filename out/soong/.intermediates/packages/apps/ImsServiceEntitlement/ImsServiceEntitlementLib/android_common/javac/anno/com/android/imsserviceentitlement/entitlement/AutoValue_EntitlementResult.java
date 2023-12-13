package com.android.imsserviceentitlement.entitlement;

import com.android.imsserviceentitlement.ts43.Ts43SmsOverIpStatus;
import com.android.imsserviceentitlement.ts43.Ts43VolteStatus;
import com.android.imsserviceentitlement.ts43.Ts43VowifiStatus;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_EntitlementResult extends EntitlementResult {

  private final Ts43VowifiStatus vowifiStatus;

  private final Ts43VolteStatus volteStatus;

  private final Ts43SmsOverIpStatus smsoveripStatus;

  private final String emergencyAddressWebUrl;

  private final String emergencyAddressWebData;

  private final String termsAndConditionsWebUrl;

  private final long retryAfterSeconds;

  private AutoValue_EntitlementResult(
      Ts43VowifiStatus vowifiStatus,
      Ts43VolteStatus volteStatus,
      Ts43SmsOverIpStatus smsoveripStatus,
      String emergencyAddressWebUrl,
      String emergencyAddressWebData,
      String termsAndConditionsWebUrl,
      long retryAfterSeconds) {
    this.vowifiStatus = vowifiStatus;
    this.volteStatus = volteStatus;
    this.smsoveripStatus = smsoveripStatus;
    this.emergencyAddressWebUrl = emergencyAddressWebUrl;
    this.emergencyAddressWebData = emergencyAddressWebData;
    this.termsAndConditionsWebUrl = termsAndConditionsWebUrl;
    this.retryAfterSeconds = retryAfterSeconds;
  }

  @Override
  public Ts43VowifiStatus getVowifiStatus() {
    return vowifiStatus;
  }

  @Override
  public Ts43VolteStatus getVolteStatus() {
    return volteStatus;
  }

  @Override
  public Ts43SmsOverIpStatus getSmsoveripStatus() {
    return smsoveripStatus;
  }

  @Override
  public String getEmergencyAddressWebUrl() {
    return emergencyAddressWebUrl;
  }

  @Override
  public String getEmergencyAddressWebData() {
    return emergencyAddressWebData;
  }

  @Override
  public String getTermsAndConditionsWebUrl() {
    return termsAndConditionsWebUrl;
  }

  @Override
  public long getRetryAfterSeconds() {
    return retryAfterSeconds;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof EntitlementResult) {
      EntitlementResult that = (EntitlementResult) o;
      return this.vowifiStatus.equals(that.getVowifiStatus())
          && this.volteStatus.equals(that.getVolteStatus())
          && this.smsoveripStatus.equals(that.getSmsoveripStatus())
          && this.emergencyAddressWebUrl.equals(that.getEmergencyAddressWebUrl())
          && this.emergencyAddressWebData.equals(that.getEmergencyAddressWebData())
          && this.termsAndConditionsWebUrl.equals(that.getTermsAndConditionsWebUrl())
          && this.retryAfterSeconds == that.getRetryAfterSeconds();
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= vowifiStatus.hashCode();
    h$ *= 1000003;
    h$ ^= volteStatus.hashCode();
    h$ *= 1000003;
    h$ ^= smsoveripStatus.hashCode();
    h$ *= 1000003;
    h$ ^= emergencyAddressWebUrl.hashCode();
    h$ *= 1000003;
    h$ ^= emergencyAddressWebData.hashCode();
    h$ *= 1000003;
    h$ ^= termsAndConditionsWebUrl.hashCode();
    h$ *= 1000003;
    h$ ^= (int) ((retryAfterSeconds >>> 32) ^ retryAfterSeconds);
    return h$;
  }

  static final class Builder extends EntitlementResult.Builder {
    private Ts43VowifiStatus vowifiStatus;
    private Ts43VolteStatus volteStatus;
    private Ts43SmsOverIpStatus smsoveripStatus;
    private String emergencyAddressWebUrl;
    private String emergencyAddressWebData;
    private String termsAndConditionsWebUrl;
    private Long retryAfterSeconds;
    Builder() {
    }
    @Override
    public EntitlementResult.Builder setVowifiStatus(Ts43VowifiStatus vowifiStatus) {
      if (vowifiStatus == null) {
        throw new NullPointerException("Null vowifiStatus");
      }
      this.vowifiStatus = vowifiStatus;
      return this;
    }
    @Override
    public EntitlementResult.Builder setVolteStatus(Ts43VolteStatus volteStatus) {
      if (volteStatus == null) {
        throw new NullPointerException("Null volteStatus");
      }
      this.volteStatus = volteStatus;
      return this;
    }
    @Override
    public EntitlementResult.Builder setSmsoveripStatus(Ts43SmsOverIpStatus smsoveripStatus) {
      if (smsoveripStatus == null) {
        throw new NullPointerException("Null smsoveripStatus");
      }
      this.smsoveripStatus = smsoveripStatus;
      return this;
    }
    @Override
    public EntitlementResult.Builder setEmergencyAddressWebUrl(String emergencyAddressWebUrl) {
      if (emergencyAddressWebUrl == null) {
        throw new NullPointerException("Null emergencyAddressWebUrl");
      }
      this.emergencyAddressWebUrl = emergencyAddressWebUrl;
      return this;
    }
    @Override
    public EntitlementResult.Builder setEmergencyAddressWebData(String emergencyAddressWebData) {
      if (emergencyAddressWebData == null) {
        throw new NullPointerException("Null emergencyAddressWebData");
      }
      this.emergencyAddressWebData = emergencyAddressWebData;
      return this;
    }
    @Override
    public EntitlementResult.Builder setTermsAndConditionsWebUrl(String termsAndConditionsWebUrl) {
      if (termsAndConditionsWebUrl == null) {
        throw new NullPointerException("Null termsAndConditionsWebUrl");
      }
      this.termsAndConditionsWebUrl = termsAndConditionsWebUrl;
      return this;
    }
    @Override
    public EntitlementResult.Builder setRetryAfterSeconds(long retryAfterSeconds) {
      this.retryAfterSeconds = retryAfterSeconds;
      return this;
    }
    @Override
    public EntitlementResult build() {
      String missing = "";
      if (this.vowifiStatus == null) {
        missing += " vowifiStatus";
      }
      if (this.volteStatus == null) {
        missing += " volteStatus";
      }
      if (this.smsoveripStatus == null) {
        missing += " smsoveripStatus";
      }
      if (this.emergencyAddressWebUrl == null) {
        missing += " emergencyAddressWebUrl";
      }
      if (this.emergencyAddressWebData == null) {
        missing += " emergencyAddressWebData";
      }
      if (this.termsAndConditionsWebUrl == null) {
        missing += " termsAndConditionsWebUrl";
      }
      if (this.retryAfterSeconds == null) {
        missing += " retryAfterSeconds";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_EntitlementResult(
          this.vowifiStatus,
          this.volteStatus,
          this.smsoveripStatus,
          this.emergencyAddressWebUrl,
          this.emergencyAddressWebData,
          this.termsAndConditionsWebUrl,
          this.retryAfterSeconds);
    }
  }

}
