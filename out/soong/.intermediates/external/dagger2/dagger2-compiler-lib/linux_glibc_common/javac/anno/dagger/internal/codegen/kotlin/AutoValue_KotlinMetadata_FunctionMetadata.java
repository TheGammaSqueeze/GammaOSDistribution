package dagger.internal.codegen.kotlin;

import com.google.common.collect.ImmutableList;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_KotlinMetadata_FunctionMetadata extends KotlinMetadata.FunctionMetadata {

  private final int flags;

  private final String name;

  private final String signature;

  private final ImmutableList<KotlinMetadata.ValueParameterMetadata> parameters;

  private AutoValue_KotlinMetadata_FunctionMetadata(
      int flags,
      String name,
      String signature,
      ImmutableList<KotlinMetadata.ValueParameterMetadata> parameters) {
    this.flags = flags;
    this.name = name;
    this.signature = signature;
    this.parameters = parameters;
  }

  @Override
  int flags() {
    return flags;
  }

  @Override
  String name() {
    return name;
  }

  @Override
  String signature() {
    return signature;
  }

  @Override
  ImmutableList<KotlinMetadata.ValueParameterMetadata> parameters() {
    return parameters;
  }

  @Override
  public String toString() {
    return "FunctionMetadata{"
        + "flags=" + flags + ", "
        + "name=" + name + ", "
        + "signature=" + signature + ", "
        + "parameters=" + parameters
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof KotlinMetadata.FunctionMetadata) {
      KotlinMetadata.FunctionMetadata that = (KotlinMetadata.FunctionMetadata) o;
      return this.flags == that.flags()
          && this.name.equals(that.name())
          && this.signature.equals(that.signature())
          && this.parameters.equals(that.parameters());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= flags;
    h$ *= 1000003;
    h$ ^= name.hashCode();
    h$ *= 1000003;
    h$ ^= signature.hashCode();
    h$ *= 1000003;
    h$ ^= parameters.hashCode();
    return h$;
  }

  static final class Builder extends KotlinMetadata.FunctionMetadata.Builder {
    private Integer flags;
    private String name;
    private String signature;
    private ImmutableList.Builder<KotlinMetadata.ValueParameterMetadata> parametersBuilder$;
    private ImmutableList<KotlinMetadata.ValueParameterMetadata> parameters;
    Builder() {
    }
    @Override
    public KotlinMetadata.FunctionMetadata.Builder flags(int flags) {
      this.flags = flags;
      return this;
    }
    @Override
    public KotlinMetadata.FunctionMetadata.Builder name(String name) {
      if (name == null) {
        throw new NullPointerException("Null name");
      }
      this.name = name;
      return this;
    }
    @Override
    KotlinMetadata.FunctionMetadata.Builder signature(String signature) {
      if (signature == null) {
        throw new NullPointerException("Null signature");
      }
      this.signature = signature;
      return this;
    }
    @Override
    ImmutableList.Builder<KotlinMetadata.ValueParameterMetadata> parametersBuilder() {
      if (parametersBuilder$ == null) {
        parametersBuilder$ = ImmutableList.builder();
      }
      return parametersBuilder$;
    }
    @Override
    KotlinMetadata.FunctionMetadata build() {
      if (parametersBuilder$ != null) {
        this.parameters = parametersBuilder$.build();
      } else if (this.parameters == null) {
        this.parameters = ImmutableList.of();
      }
      String missing = "";
      if (this.flags == null) {
        missing += " flags";
      }
      if (this.name == null) {
        missing += " name";
      }
      if (this.signature == null) {
        missing += " signature";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_KotlinMetadata_FunctionMetadata(
          this.flags,
          this.name,
          this.signature,
          this.parameters);
    }
  }

}
