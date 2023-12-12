package com.android.libraries.entitlement;

import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_EsimOdsaOperation extends EsimOdsaOperation {

  private final String operation;

  private final int operationType;

  private final String companionTerminalId;

  private final String companionTerminalVendor;

  private final String companionTerminalModel;

  private final String companionTerminalSoftwareVersion;

  private final String companionTerminalFriendlyName;

  private final String companionTerminalService;

  private final String companionTerminalIccid;

  private final String companionTerminalEid;

  private final String terminalIccid;

  private final String terminalEid;

  private final String targetTerminalId;

  private final String targetTerminalIccid;

  private final String targetTerminalEid;

  private AutoValue_EsimOdsaOperation(
      String operation,
      int operationType,
      String companionTerminalId,
      String companionTerminalVendor,
      String companionTerminalModel,
      String companionTerminalSoftwareVersion,
      String companionTerminalFriendlyName,
      String companionTerminalService,
      String companionTerminalIccid,
      String companionTerminalEid,
      String terminalIccid,
      String terminalEid,
      String targetTerminalId,
      String targetTerminalIccid,
      String targetTerminalEid) {
    this.operation = operation;
    this.operationType = operationType;
    this.companionTerminalId = companionTerminalId;
    this.companionTerminalVendor = companionTerminalVendor;
    this.companionTerminalModel = companionTerminalModel;
    this.companionTerminalSoftwareVersion = companionTerminalSoftwareVersion;
    this.companionTerminalFriendlyName = companionTerminalFriendlyName;
    this.companionTerminalService = companionTerminalService;
    this.companionTerminalIccid = companionTerminalIccid;
    this.companionTerminalEid = companionTerminalEid;
    this.terminalIccid = terminalIccid;
    this.terminalEid = terminalEid;
    this.targetTerminalId = targetTerminalId;
    this.targetTerminalIccid = targetTerminalIccid;
    this.targetTerminalEid = targetTerminalEid;
  }

  @Override
  public String operation() {
    return operation;
  }

  @Override
  public int operationType() {
    return operationType;
  }

  @Override
  public String companionTerminalId() {
    return companionTerminalId;
  }

  @Override
  public String companionTerminalVendor() {
    return companionTerminalVendor;
  }

  @Override
  public String companionTerminalModel() {
    return companionTerminalModel;
  }

  @Override
  public String companionTerminalSoftwareVersion() {
    return companionTerminalSoftwareVersion;
  }

  @Override
  public String companionTerminalFriendlyName() {
    return companionTerminalFriendlyName;
  }

  @Override
  public String companionTerminalService() {
    return companionTerminalService;
  }

  @Override
  public String companionTerminalIccid() {
    return companionTerminalIccid;
  }

  @Override
  public String companionTerminalEid() {
    return companionTerminalEid;
  }

  @Override
  public String terminalIccid() {
    return terminalIccid;
  }

  @Override
  public String terminalEid() {
    return terminalEid;
  }

  @Override
  public String targetTerminalId() {
    return targetTerminalId;
  }

  @Override
  public String targetTerminalIccid() {
    return targetTerminalIccid;
  }

  @Override
  public String targetTerminalEid() {
    return targetTerminalEid;
  }

  @Override
  public String toString() {
    return "EsimOdsaOperation{"
        + "operation=" + operation + ", "
        + "operationType=" + operationType + ", "
        + "companionTerminalId=" + companionTerminalId + ", "
        + "companionTerminalVendor=" + companionTerminalVendor + ", "
        + "companionTerminalModel=" + companionTerminalModel + ", "
        + "companionTerminalSoftwareVersion=" + companionTerminalSoftwareVersion + ", "
        + "companionTerminalFriendlyName=" + companionTerminalFriendlyName + ", "
        + "companionTerminalService=" + companionTerminalService + ", "
        + "companionTerminalIccid=" + companionTerminalIccid + ", "
        + "companionTerminalEid=" + companionTerminalEid + ", "
        + "terminalIccid=" + terminalIccid + ", "
        + "terminalEid=" + terminalEid + ", "
        + "targetTerminalId=" + targetTerminalId + ", "
        + "targetTerminalIccid=" + targetTerminalIccid + ", "
        + "targetTerminalEid=" + targetTerminalEid
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof EsimOdsaOperation) {
      EsimOdsaOperation that = (EsimOdsaOperation) o;
      return this.operation.equals(that.operation())
          && this.operationType == that.operationType()
          && this.companionTerminalId.equals(that.companionTerminalId())
          && this.companionTerminalVendor.equals(that.companionTerminalVendor())
          && this.companionTerminalModel.equals(that.companionTerminalModel())
          && this.companionTerminalSoftwareVersion.equals(that.companionTerminalSoftwareVersion())
          && this.companionTerminalFriendlyName.equals(that.companionTerminalFriendlyName())
          && this.companionTerminalService.equals(that.companionTerminalService())
          && this.companionTerminalIccid.equals(that.companionTerminalIccid())
          && this.companionTerminalEid.equals(that.companionTerminalEid())
          && this.terminalIccid.equals(that.terminalIccid())
          && this.terminalEid.equals(that.terminalEid())
          && this.targetTerminalId.equals(that.targetTerminalId())
          && this.targetTerminalIccid.equals(that.targetTerminalIccid())
          && this.targetTerminalEid.equals(that.targetTerminalEid());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= operation.hashCode();
    h$ *= 1000003;
    h$ ^= operationType;
    h$ *= 1000003;
    h$ ^= companionTerminalId.hashCode();
    h$ *= 1000003;
    h$ ^= companionTerminalVendor.hashCode();
    h$ *= 1000003;
    h$ ^= companionTerminalModel.hashCode();
    h$ *= 1000003;
    h$ ^= companionTerminalSoftwareVersion.hashCode();
    h$ *= 1000003;
    h$ ^= companionTerminalFriendlyName.hashCode();
    h$ *= 1000003;
    h$ ^= companionTerminalService.hashCode();
    h$ *= 1000003;
    h$ ^= companionTerminalIccid.hashCode();
    h$ *= 1000003;
    h$ ^= companionTerminalEid.hashCode();
    h$ *= 1000003;
    h$ ^= terminalIccid.hashCode();
    h$ *= 1000003;
    h$ ^= terminalEid.hashCode();
    h$ *= 1000003;
    h$ ^= targetTerminalId.hashCode();
    h$ *= 1000003;
    h$ ^= targetTerminalIccid.hashCode();
    h$ *= 1000003;
    h$ ^= targetTerminalEid.hashCode();
    return h$;
  }

  static final class Builder extends EsimOdsaOperation.Builder {
    private String operation;
    private Integer operationType;
    private String companionTerminalId;
    private String companionTerminalVendor;
    private String companionTerminalModel;
    private String companionTerminalSoftwareVersion;
    private String companionTerminalFriendlyName;
    private String companionTerminalService;
    private String companionTerminalIccid;
    private String companionTerminalEid;
    private String terminalIccid;
    private String terminalEid;
    private String targetTerminalId;
    private String targetTerminalIccid;
    private String targetTerminalEid;
    Builder() {
    }
    @Override
    public EsimOdsaOperation.Builder setOperation(String operation) {
      if (operation == null) {
        throw new NullPointerException("Null operation");
      }
      this.operation = operation;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setOperationType(int operationType) {
      this.operationType = operationType;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setCompanionTerminalId(String companionTerminalId) {
      if (companionTerminalId == null) {
        throw new NullPointerException("Null companionTerminalId");
      }
      this.companionTerminalId = companionTerminalId;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setCompanionTerminalVendor(String companionTerminalVendor) {
      if (companionTerminalVendor == null) {
        throw new NullPointerException("Null companionTerminalVendor");
      }
      this.companionTerminalVendor = companionTerminalVendor;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setCompanionTerminalModel(String companionTerminalModel) {
      if (companionTerminalModel == null) {
        throw new NullPointerException("Null companionTerminalModel");
      }
      this.companionTerminalModel = companionTerminalModel;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setCompanionTerminalSoftwareVersion(String companionTerminalSoftwareVersion) {
      if (companionTerminalSoftwareVersion == null) {
        throw new NullPointerException("Null companionTerminalSoftwareVersion");
      }
      this.companionTerminalSoftwareVersion = companionTerminalSoftwareVersion;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setCompanionTerminalFriendlyName(String companionTerminalFriendlyName) {
      if (companionTerminalFriendlyName == null) {
        throw new NullPointerException("Null companionTerminalFriendlyName");
      }
      this.companionTerminalFriendlyName = companionTerminalFriendlyName;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setCompanionTerminalService(String companionTerminalService) {
      if (companionTerminalService == null) {
        throw new NullPointerException("Null companionTerminalService");
      }
      this.companionTerminalService = companionTerminalService;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setCompanionTerminalIccid(String companionTerminalIccid) {
      if (companionTerminalIccid == null) {
        throw new NullPointerException("Null companionTerminalIccid");
      }
      this.companionTerminalIccid = companionTerminalIccid;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setCompanionTerminalEid(String companionTerminalEid) {
      if (companionTerminalEid == null) {
        throw new NullPointerException("Null companionTerminalEid");
      }
      this.companionTerminalEid = companionTerminalEid;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setTerminalIccid(String terminalIccid) {
      if (terminalIccid == null) {
        throw new NullPointerException("Null terminalIccid");
      }
      this.terminalIccid = terminalIccid;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setTerminalEid(String terminalEid) {
      if (terminalEid == null) {
        throw new NullPointerException("Null terminalEid");
      }
      this.terminalEid = terminalEid;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setTargetTerminalId(String targetTerminalId) {
      if (targetTerminalId == null) {
        throw new NullPointerException("Null targetTerminalId");
      }
      this.targetTerminalId = targetTerminalId;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setTargetTerminalIccid(String targetTerminalIccid) {
      if (targetTerminalIccid == null) {
        throw new NullPointerException("Null targetTerminalIccid");
      }
      this.targetTerminalIccid = targetTerminalIccid;
      return this;
    }
    @Override
    public EsimOdsaOperation.Builder setTargetTerminalEid(String targetTerminalEid) {
      if (targetTerminalEid == null) {
        throw new NullPointerException("Null targetTerminalEid");
      }
      this.targetTerminalEid = targetTerminalEid;
      return this;
    }
    @Override
    public EsimOdsaOperation build() {
      String missing = "";
      if (this.operation == null) {
        missing += " operation";
      }
      if (this.operationType == null) {
        missing += " operationType";
      }
      if (this.companionTerminalId == null) {
        missing += " companionTerminalId";
      }
      if (this.companionTerminalVendor == null) {
        missing += " companionTerminalVendor";
      }
      if (this.companionTerminalModel == null) {
        missing += " companionTerminalModel";
      }
      if (this.companionTerminalSoftwareVersion == null) {
        missing += " companionTerminalSoftwareVersion";
      }
      if (this.companionTerminalFriendlyName == null) {
        missing += " companionTerminalFriendlyName";
      }
      if (this.companionTerminalService == null) {
        missing += " companionTerminalService";
      }
      if (this.companionTerminalIccid == null) {
        missing += " companionTerminalIccid";
      }
      if (this.companionTerminalEid == null) {
        missing += " companionTerminalEid";
      }
      if (this.terminalIccid == null) {
        missing += " terminalIccid";
      }
      if (this.terminalEid == null) {
        missing += " terminalEid";
      }
      if (this.targetTerminalId == null) {
        missing += " targetTerminalId";
      }
      if (this.targetTerminalIccid == null) {
        missing += " targetTerminalIccid";
      }
      if (this.targetTerminalEid == null) {
        missing += " targetTerminalEid";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_EsimOdsaOperation(
          this.operation,
          this.operationType,
          this.companionTerminalId,
          this.companionTerminalVendor,
          this.companionTerminalModel,
          this.companionTerminalSoftwareVersion,
          this.companionTerminalFriendlyName,
          this.companionTerminalService,
          this.companionTerminalIccid,
          this.companionTerminalEid,
          this.terminalIccid,
          this.terminalEid,
          this.targetTerminalId,
          this.targetTerminalIccid,
          this.targetTerminalEid);
    }
  }

}
