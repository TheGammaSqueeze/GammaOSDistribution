package dagger.internal.codegen.binding;

import com.google.common.base.Equivalence;
import dagger.model.Key;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_ComponentRequirement extends ComponentRequirement {

  private final ComponentRequirement.Kind kind;

  private final Equivalence.Wrapper<TypeMirror> wrappedType;

  private final Optional<ComponentRequirement.NullPolicy> overrideNullPolicy;

  private final Optional<Key> key;

  private final String variableName;

  AutoValue_ComponentRequirement(
      ComponentRequirement.Kind kind,
      Equivalence.Wrapper<TypeMirror> wrappedType,
      Optional<ComponentRequirement.NullPolicy> overrideNullPolicy,
      Optional<Key> key,
      String variableName) {
    if (kind == null) {
      throw new NullPointerException("Null kind");
    }
    this.kind = kind;
    if (wrappedType == null) {
      throw new NullPointerException("Null wrappedType");
    }
    this.wrappedType = wrappedType;
    if (overrideNullPolicy == null) {
      throw new NullPointerException("Null overrideNullPolicy");
    }
    this.overrideNullPolicy = overrideNullPolicy;
    if (key == null) {
      throw new NullPointerException("Null key");
    }
    this.key = key;
    if (variableName == null) {
      throw new NullPointerException("Null variableName");
    }
    this.variableName = variableName;
  }

  @Override
  public ComponentRequirement.Kind kind() {
    return kind;
  }

  @Override
  public Equivalence.Wrapper<TypeMirror> wrappedType() {
    return wrappedType;
  }

  @Override
  Optional<ComponentRequirement.NullPolicy> overrideNullPolicy() {
    return overrideNullPolicy;
  }

  @Override
  public Optional<Key> key() {
    return key;
  }

  @Override
  public String variableName() {
    return variableName;
  }

  @Override
  public String toString() {
    return "ComponentRequirement{"
        + "kind=" + kind + ", "
        + "wrappedType=" + wrappedType + ", "
        + "overrideNullPolicy=" + overrideNullPolicy + ", "
        + "key=" + key + ", "
        + "variableName=" + variableName
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ComponentRequirement) {
      ComponentRequirement that = (ComponentRequirement) o;
      return this.kind.equals(that.kind())
          && this.wrappedType.equals(that.wrappedType())
          && this.overrideNullPolicy.equals(that.overrideNullPolicy())
          && this.key.equals(that.key())
          && this.variableName.equals(that.variableName());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= kind.hashCode();
    h$ *= 1000003;
    h$ ^= wrappedType.hashCode();
    h$ *= 1000003;
    h$ ^= overrideNullPolicy.hashCode();
    h$ *= 1000003;
    h$ ^= key.hashCode();
    h$ *= 1000003;
    h$ ^= variableName.hashCode();
    return h$;
  }

}
