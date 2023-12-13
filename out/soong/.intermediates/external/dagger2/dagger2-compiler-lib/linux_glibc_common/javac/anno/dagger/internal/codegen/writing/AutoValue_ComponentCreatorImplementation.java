package dagger.internal.codegen.writing;

import com.google.common.collect.ImmutableMap;
import com.squareup.javapoet.ClassName;
import com.squareup.javapoet.FieldSpec;
import com.squareup.javapoet.TypeSpec;
import dagger.internal.codegen.binding.ComponentRequirement;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_ComponentCreatorImplementation extends ComponentCreatorImplementation {

  private final TypeSpec spec;

  private final ClassName name;

  private final ImmutableMap<ComponentRequirement, FieldSpec> fields;

  AutoValue_ComponentCreatorImplementation(
      TypeSpec spec,
      ClassName name,
      ImmutableMap<ComponentRequirement, FieldSpec> fields) {
    if (spec == null) {
      throw new NullPointerException("Null spec");
    }
    this.spec = spec;
    if (name == null) {
      throw new NullPointerException("Null name");
    }
    this.name = name;
    if (fields == null) {
      throw new NullPointerException("Null fields");
    }
    this.fields = fields;
  }

  @Override
  public TypeSpec spec() {
    return spec;
  }

  @Override
  public ClassName name() {
    return name;
  }

  @Override
  ImmutableMap<ComponentRequirement, FieldSpec> fields() {
    return fields;
  }

  @Override
  public String toString() {
    return "ComponentCreatorImplementation{"
        + "spec=" + spec + ", "
        + "name=" + name + ", "
        + "fields=" + fields
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ComponentCreatorImplementation) {
      ComponentCreatorImplementation that = (ComponentCreatorImplementation) o;
      return this.spec.equals(that.spec())
          && this.name.equals(that.name())
          && this.fields.equals(that.fields());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= spec.hashCode();
    h$ *= 1000003;
    h$ ^= name.hashCode();
    h$ *= 1000003;
    h$ ^= fields.hashCode();
    return h$;
  }

}
