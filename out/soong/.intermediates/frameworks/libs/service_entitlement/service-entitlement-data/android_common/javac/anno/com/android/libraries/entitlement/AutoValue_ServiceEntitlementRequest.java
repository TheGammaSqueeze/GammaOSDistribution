package com.android.libraries.entitlement;

import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_ServiceEntitlementRequest extends ServiceEntitlementRequest {

  private final int configurationVersion;

  private final String entitlementVersion;

  private final String authenticationToken;

  private final String terminalId;

  private final String terminalVendor;

  private final String terminalModel;

  private final String terminalSoftwareVersion;

  private final String appName;

  private final String appVersion;

  private final String notificationToken;

  private final int notificationAction;

  private final String acceptContentType;

  private AutoValue_ServiceEntitlementRequest(
      int configurationVersion,
      String entitlementVersion,
      String authenticationToken,
      String terminalId,
      String terminalVendor,
      String terminalModel,
      String terminalSoftwareVersion,
      String appName,
      String appVersion,
      String notificationToken,
      int notificationAction,
      String acceptContentType) {
    this.configurationVersion = configurationVersion;
    this.entitlementVersion = entitlementVersion;
    this.authenticationToken = authenticationToken;
    this.terminalId = terminalId;
    this.terminalVendor = terminalVendor;
    this.terminalModel = terminalModel;
    this.terminalSoftwareVersion = terminalSoftwareVersion;
    this.appName = appName;
    this.appVersion = appVersion;
    this.notificationToken = notificationToken;
    this.notificationAction = notificationAction;
    this.acceptContentType = acceptContentType;
  }

  @Override
  public int configurationVersion() {
    return configurationVersion;
  }

  @Override
  public String entitlementVersion() {
    return entitlementVersion;
  }

  @Override
  public String authenticationToken() {
    return authenticationToken;
  }

  @Override
  public String terminalId() {
    return terminalId;
  }

  @Override
  public String terminalVendor() {
    return terminalVendor;
  }

  @Override
  public String terminalModel() {
    return terminalModel;
  }

  @Override
  public String terminalSoftwareVersion() {
    return terminalSoftwareVersion;
  }

  @Override
  public String appName() {
    return appName;
  }

  @Override
  public String appVersion() {
    return appVersion;
  }

  @Override
  public String notificationToken() {
    return notificationToken;
  }

  @Override
  public int notificationAction() {
    return notificationAction;
  }

  @Override
  public String acceptContentType() {
    return acceptContentType;
  }

  @Override
  public String toString() {
    return "ServiceEntitlementRequest{"
        + "configurationVersion=" + configurationVersion + ", "
        + "entitlementVersion=" + entitlementVersion + ", "
        + "authenticationToken=" + authenticationToken + ", "
        + "terminalId=" + terminalId + ", "
        + "terminalVendor=" + terminalVendor + ", "
        + "terminalModel=" + terminalModel + ", "
        + "terminalSoftwareVersion=" + terminalSoftwareVersion + ", "
        + "appName=" + appName + ", "
        + "appVersion=" + appVersion + ", "
        + "notificationToken=" + notificationToken + ", "
        + "notificationAction=" + notificationAction + ", "
        + "acceptContentType=" + acceptContentType
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ServiceEntitlementRequest) {
      ServiceEntitlementRequest that = (ServiceEntitlementRequest) o;
      return this.configurationVersion == that.configurationVersion()
          && this.entitlementVersion.equals(that.entitlementVersion())
          && this.authenticationToken.equals(that.authenticationToken())
          && this.terminalId.equals(that.terminalId())
          && this.terminalVendor.equals(that.terminalVendor())
          && this.terminalModel.equals(that.terminalModel())
          && this.terminalSoftwareVersion.equals(that.terminalSoftwareVersion())
          && this.appName.equals(that.appName())
          && this.appVersion.equals(that.appVersion())
          && this.notificationToken.equals(that.notificationToken())
          && this.notificationAction == that.notificationAction()
          && this.acceptContentType.equals(that.acceptContentType());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= configurationVersion;
    h$ *= 1000003;
    h$ ^= entitlementVersion.hashCode();
    h$ *= 1000003;
    h$ ^= authenticationToken.hashCode();
    h$ *= 1000003;
    h$ ^= terminalId.hashCode();
    h$ *= 1000003;
    h$ ^= terminalVendor.hashCode();
    h$ *= 1000003;
    h$ ^= terminalModel.hashCode();
    h$ *= 1000003;
    h$ ^= terminalSoftwareVersion.hashCode();
    h$ *= 1000003;
    h$ ^= appName.hashCode();
    h$ *= 1000003;
    h$ ^= appVersion.hashCode();
    h$ *= 1000003;
    h$ ^= notificationToken.hashCode();
    h$ *= 1000003;
    h$ ^= notificationAction;
    h$ *= 1000003;
    h$ ^= acceptContentType.hashCode();
    return h$;
  }

  static final class Builder extends ServiceEntitlementRequest.Builder {
    private Integer configurationVersion;
    private String entitlementVersion;
    private String authenticationToken;
    private String terminalId;
    private String terminalVendor;
    private String terminalModel;
    private String terminalSoftwareVersion;
    private String appName;
    private String appVersion;
    private String notificationToken;
    private Integer notificationAction;
    private String acceptContentType;
    Builder() {
    }
    @Override
    public ServiceEntitlementRequest.Builder setConfigurationVersion(int configurationVersion) {
      this.configurationVersion = configurationVersion;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setEntitlementVersion(String entitlementVersion) {
      if (entitlementVersion == null) {
        throw new NullPointerException("Null entitlementVersion");
      }
      this.entitlementVersion = entitlementVersion;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setAuthenticationToken(String authenticationToken) {
      if (authenticationToken == null) {
        throw new NullPointerException("Null authenticationToken");
      }
      this.authenticationToken = authenticationToken;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setTerminalId(String terminalId) {
      if (terminalId == null) {
        throw new NullPointerException("Null terminalId");
      }
      this.terminalId = terminalId;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setTerminalVendor(String terminalVendor) {
      if (terminalVendor == null) {
        throw new NullPointerException("Null terminalVendor");
      }
      this.terminalVendor = terminalVendor;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setTerminalModel(String terminalModel) {
      if (terminalModel == null) {
        throw new NullPointerException("Null terminalModel");
      }
      this.terminalModel = terminalModel;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setTerminalSoftwareVersion(String terminalSoftwareVersion) {
      if (terminalSoftwareVersion == null) {
        throw new NullPointerException("Null terminalSoftwareVersion");
      }
      this.terminalSoftwareVersion = terminalSoftwareVersion;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setAppName(String appName) {
      if (appName == null) {
        throw new NullPointerException("Null appName");
      }
      this.appName = appName;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setAppVersion(String appVersion) {
      if (appVersion == null) {
        throw new NullPointerException("Null appVersion");
      }
      this.appVersion = appVersion;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setNotificationToken(String notificationToken) {
      if (notificationToken == null) {
        throw new NullPointerException("Null notificationToken");
      }
      this.notificationToken = notificationToken;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setNotificationAction(int notificationAction) {
      this.notificationAction = notificationAction;
      return this;
    }
    @Override
    public ServiceEntitlementRequest.Builder setAcceptContentType(String acceptContentType) {
      if (acceptContentType == null) {
        throw new NullPointerException("Null acceptContentType");
      }
      this.acceptContentType = acceptContentType;
      return this;
    }
    @Override
    public ServiceEntitlementRequest build() {
      String missing = "";
      if (this.configurationVersion == null) {
        missing += " configurationVersion";
      }
      if (this.entitlementVersion == null) {
        missing += " entitlementVersion";
      }
      if (this.authenticationToken == null) {
        missing += " authenticationToken";
      }
      if (this.terminalId == null) {
        missing += " terminalId";
      }
      if (this.terminalVendor == null) {
        missing += " terminalVendor";
      }
      if (this.terminalModel == null) {
        missing += " terminalModel";
      }
      if (this.terminalSoftwareVersion == null) {
        missing += " terminalSoftwareVersion";
      }
      if (this.appName == null) {
        missing += " appName";
      }
      if (this.appVersion == null) {
        missing += " appVersion";
      }
      if (this.notificationToken == null) {
        missing += " notificationToken";
      }
      if (this.notificationAction == null) {
        missing += " notificationAction";
      }
      if (this.acceptContentType == null) {
        missing += " acceptContentType";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_ServiceEntitlementRequest(
          this.configurationVersion,
          this.entitlementVersion,
          this.authenticationToken,
          this.terminalId,
          this.terminalVendor,
          this.terminalModel,
          this.terminalSoftwareVersion,
          this.appName,
          this.appVersion,
          this.notificationToken,
          this.notificationAction,
          this.acceptContentType);
    }
  }

}
