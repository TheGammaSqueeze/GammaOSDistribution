package dagger.internal.codegen.binding;

import dagger.model.Key;
import dagger.model.RequestKind;
import java.util.Optional;
import javax.annotation.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_BindingRequest extends BindingRequest {

  private final Key key;

  private final Optional<RequestKind> requestKind;

  private final Optional<FrameworkType> frameworkType;

  AutoValue_BindingRequest(
      Key key,
      Optional<RequestKind> requestKind,
      Optional<FrameworkType> frameworkType) {
    if (key == null) {
      throw new NullPointerException("Null key");
    }
    this.key = key;
    if (requestKind == null) {
      throw new NullPointerException("Null requestKind");
    }
    this.requestKind = requestKind;
    if (frameworkType == null) {
      throw new NullPointerException("Null frameworkType");
    }
    this.frameworkType = frameworkType;
  }

  @Override
  public Key key() {
    return key;
  }

  @Override
  public Optional<RequestKind> requestKind() {
    return requestKind;
  }

  @Override
  public Optional<FrameworkType> frameworkType() {
    return frameworkType;
  }

  @Override
  public String toString() {
    return "BindingRequest{"
        + "key=" + key + ", "
        + "requestKind=" + requestKind + ", "
        + "frameworkType=" + frameworkType
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof BindingRequest) {
      BindingRequest that = (BindingRequest) o;
      return this.key.equals(that.key())
          && this.requestKind.equals(that.requestKind())
          && this.frameworkType.equals(that.frameworkType());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= key.hashCode();
    h$ *= 1000003;
    h$ ^= requestKind.hashCode();
    h$ *= 1000003;
    h$ ^= frameworkType.hashCode();
    return h$;
  }

}
