package dagger.internal.codegen.writing;

import dagger.internal.codegen.base.OptionalType;
import dagger.internal.codegen.binding.FrameworkType;
import dagger.model.RequestKind;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_OptionalFactories_PresentFactorySpec extends OptionalFactories.PresentFactorySpec {

  private final FrameworkType frameworkType;

  private final OptionalType.OptionalKind optionalKind;

  private final RequestKind valueKind;

  AutoValue_OptionalFactories_PresentFactorySpec(
      FrameworkType frameworkType,
      OptionalType.OptionalKind optionalKind,
      RequestKind valueKind) {
    if (frameworkType == null) {
      throw new NullPointerException("Null frameworkType");
    }
    this.frameworkType = frameworkType;
    if (optionalKind == null) {
      throw new NullPointerException("Null optionalKind");
    }
    this.optionalKind = optionalKind;
    if (valueKind == null) {
      throw new NullPointerException("Null valueKind");
    }
    this.valueKind = valueKind;
  }

  @Override
  FrameworkType frameworkType() {
    return frameworkType;
  }

  @Override
  OptionalType.OptionalKind optionalKind() {
    return optionalKind;
  }

  @Override
  RequestKind valueKind() {
    return valueKind;
  }

  @Override
  public String toString() {
    return "PresentFactorySpec{"
        + "frameworkType=" + frameworkType + ", "
        + "optionalKind=" + optionalKind + ", "
        + "valueKind=" + valueKind
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof OptionalFactories.PresentFactorySpec) {
      OptionalFactories.PresentFactorySpec that = (OptionalFactories.PresentFactorySpec) o;
      return this.frameworkType.equals(that.frameworkType())
          && this.optionalKind.equals(that.optionalKind())
          && this.valueKind.equals(that.valueKind());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= frameworkType.hashCode();
    h$ *= 1000003;
    h$ ^= optionalKind.hashCode();
    h$ *= 1000003;
    h$ ^= valueKind.hashCode();
    return h$;
  }

}
