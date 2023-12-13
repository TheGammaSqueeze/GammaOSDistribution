package dagger.internal.codegen.kotlin;

import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import java.util.Optional;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_KotlinMetadata_ClassMetadata extends KotlinMetadata.ClassMetadata {

  private final int flags;

  private final String name;

  private final Optional<String> companionObjectName;

  private final ImmutableSet<KotlinMetadata.FunctionMetadata> constructors;

  private final ImmutableMap<String, KotlinMetadata.FunctionMetadata> functionsBySignature;

  private final ImmutableMap<String, KotlinMetadata.PropertyMetadata> propertiesByFieldSignature;

  private AutoValue_KotlinMetadata_ClassMetadata(
      int flags,
      String name,
      Optional<String> companionObjectName,
      ImmutableSet<KotlinMetadata.FunctionMetadata> constructors,
      ImmutableMap<String, KotlinMetadata.FunctionMetadata> functionsBySignature,
      ImmutableMap<String, KotlinMetadata.PropertyMetadata> propertiesByFieldSignature) {
    this.flags = flags;
    this.name = name;
    this.companionObjectName = companionObjectName;
    this.constructors = constructors;
    this.functionsBySignature = functionsBySignature;
    this.propertiesByFieldSignature = propertiesByFieldSignature;
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
  Optional<String> companionObjectName() {
    return companionObjectName;
  }

  @Override
  ImmutableSet<KotlinMetadata.FunctionMetadata> constructors() {
    return constructors;
  }

  @Override
  ImmutableMap<String, KotlinMetadata.FunctionMetadata> functionsBySignature() {
    return functionsBySignature;
  }

  @Override
  ImmutableMap<String, KotlinMetadata.PropertyMetadata> propertiesByFieldSignature() {
    return propertiesByFieldSignature;
  }

  @Override
  public String toString() {
    return "ClassMetadata{"
        + "flags=" + flags + ", "
        + "name=" + name + ", "
        + "companionObjectName=" + companionObjectName + ", "
        + "constructors=" + constructors + ", "
        + "functionsBySignature=" + functionsBySignature + ", "
        + "propertiesByFieldSignature=" + propertiesByFieldSignature
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof KotlinMetadata.ClassMetadata) {
      KotlinMetadata.ClassMetadata that = (KotlinMetadata.ClassMetadata) o;
      return this.flags == that.flags()
          && this.name.equals(that.name())
          && this.companionObjectName.equals(that.companionObjectName())
          && this.constructors.equals(that.constructors())
          && this.functionsBySignature.equals(that.functionsBySignature())
          && this.propertiesByFieldSignature.equals(that.propertiesByFieldSignature());
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
    h$ ^= companionObjectName.hashCode();
    h$ *= 1000003;
    h$ ^= constructors.hashCode();
    h$ *= 1000003;
    h$ ^= functionsBySignature.hashCode();
    h$ *= 1000003;
    h$ ^= propertiesByFieldSignature.hashCode();
    return h$;
  }

  static final class Builder extends KotlinMetadata.ClassMetadata.Builder {
    private Integer flags;
    private String name;
    private Optional<String> companionObjectName = Optional.empty();
    private ImmutableSet.Builder<KotlinMetadata.FunctionMetadata> constructorsBuilder$;
    private ImmutableSet<KotlinMetadata.FunctionMetadata> constructors;
    private ImmutableMap.Builder<String, KotlinMetadata.FunctionMetadata> functionsBySignatureBuilder$;
    private ImmutableMap<String, KotlinMetadata.FunctionMetadata> functionsBySignature;
    private ImmutableMap.Builder<String, KotlinMetadata.PropertyMetadata> propertiesByFieldSignatureBuilder$;
    private ImmutableMap<String, KotlinMetadata.PropertyMetadata> propertiesByFieldSignature;
    Builder() {
    }
    @Override
    public KotlinMetadata.ClassMetadata.Builder flags(int flags) {
      this.flags = flags;
      return this;
    }
    @Override
    public KotlinMetadata.ClassMetadata.Builder name(String name) {
      if (name == null) {
        throw new NullPointerException("Null name");
      }
      this.name = name;
      return this;
    }
    @Override
    KotlinMetadata.ClassMetadata.Builder companionObjectName(String companionObjectName) {
      this.companionObjectName = Optional.of(companionObjectName);
      return this;
    }
    @Override
    ImmutableSet.Builder<KotlinMetadata.FunctionMetadata> constructorsBuilder() {
      if (constructorsBuilder$ == null) {
        constructorsBuilder$ = ImmutableSet.builder();
      }
      return constructorsBuilder$;
    }
    @Override
    ImmutableMap.Builder<String, KotlinMetadata.FunctionMetadata> functionsBySignatureBuilder() {
      if (functionsBySignatureBuilder$ == null) {
        functionsBySignatureBuilder$ = ImmutableMap.builder();
      }
      return functionsBySignatureBuilder$;
    }
    @Override
    ImmutableMap.Builder<String, KotlinMetadata.PropertyMetadata> propertiesByFieldSignatureBuilder() {
      if (propertiesByFieldSignatureBuilder$ == null) {
        propertiesByFieldSignatureBuilder$ = ImmutableMap.builder();
      }
      return propertiesByFieldSignatureBuilder$;
    }
    @Override
    KotlinMetadata.ClassMetadata build() {
      if (constructorsBuilder$ != null) {
        this.constructors = constructorsBuilder$.build();
      } else if (this.constructors == null) {
        this.constructors = ImmutableSet.of();
      }
      if (functionsBySignatureBuilder$ != null) {
        this.functionsBySignature = functionsBySignatureBuilder$.build();
      } else if (this.functionsBySignature == null) {
        this.functionsBySignature = ImmutableMap.of();
      }
      if (propertiesByFieldSignatureBuilder$ != null) {
        this.propertiesByFieldSignature = propertiesByFieldSignatureBuilder$.build();
      } else if (this.propertiesByFieldSignature == null) {
        this.propertiesByFieldSignature = ImmutableMap.of();
      }
      String missing = "";
      if (this.flags == null) {
        missing += " flags";
      }
      if (this.name == null) {
        missing += " name";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_KotlinMetadata_ClassMetadata(
          this.flags,
          this.name,
          this.companionObjectName,
          this.constructors,
          this.functionsBySignature,
          this.propertiesByFieldSignature);
    }
  }

}
