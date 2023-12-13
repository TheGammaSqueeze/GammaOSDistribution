package dagger.internal.codegen.binding;

import dagger.model.DependencyRequest;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.ExecutableElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_ComponentDescriptor_ComponentMethodDescriptor extends ComponentDescriptor.ComponentMethodDescriptor {

  private final ExecutableElement methodElement;

  private final Optional<DependencyRequest> dependencyRequest;

  private final Optional<ComponentDescriptor> subcomponent;

  private AutoValue_ComponentDescriptor_ComponentMethodDescriptor(
      ExecutableElement methodElement,
      Optional<DependencyRequest> dependencyRequest,
      Optional<ComponentDescriptor> subcomponent) {
    this.methodElement = methodElement;
    this.dependencyRequest = dependencyRequest;
    this.subcomponent = subcomponent;
  }

  @Override
  public ExecutableElement methodElement() {
    return methodElement;
  }

  @Override
  public Optional<DependencyRequest> dependencyRequest() {
    return dependencyRequest;
  }

  @Override
  public Optional<ComponentDescriptor> subcomponent() {
    return subcomponent;
  }

  @Override
  public String toString() {
    return "ComponentMethodDescriptor{"
        + "methodElement=" + methodElement + ", "
        + "dependencyRequest=" + dependencyRequest + ", "
        + "subcomponent=" + subcomponent
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof ComponentDescriptor.ComponentMethodDescriptor) {
      ComponentDescriptor.ComponentMethodDescriptor that = (ComponentDescriptor.ComponentMethodDescriptor) o;
      return this.methodElement.equals(that.methodElement())
          && this.dependencyRequest.equals(that.dependencyRequest())
          && this.subcomponent.equals(that.subcomponent());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= methodElement.hashCode();
    h$ *= 1000003;
    h$ ^= dependencyRequest.hashCode();
    h$ *= 1000003;
    h$ ^= subcomponent.hashCode();
    return h$;
  }

  static final class Builder implements ComponentDescriptor.ComponentMethodDescriptor.Builder {
    private ExecutableElement methodElement;
    private Optional<DependencyRequest> dependencyRequest = Optional.empty();
    private Optional<ComponentDescriptor> subcomponent = Optional.empty();
    Builder() {
    }
    @Override
    public ComponentDescriptor.ComponentMethodDescriptor.Builder methodElement(ExecutableElement methodElement) {
      if (methodElement == null) {
        throw new NullPointerException("Null methodElement");
      }
      this.methodElement = methodElement;
      return this;
    }
    @Override
    public ComponentDescriptor.ComponentMethodDescriptor.Builder dependencyRequest(DependencyRequest dependencyRequest) {
      this.dependencyRequest = Optional.of(dependencyRequest);
      return this;
    }
    @Override
    public ComponentDescriptor.ComponentMethodDescriptor.Builder subcomponent(ComponentDescriptor subcomponent) {
      this.subcomponent = Optional.of(subcomponent);
      return this;
    }
    @Override
    public ComponentDescriptor.ComponentMethodDescriptor build() {
      String missing = "";
      if (this.methodElement == null) {
        missing += " methodElement";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_ComponentDescriptor_ComponentMethodDescriptor(
          this.methodElement,
          this.dependencyRequest,
          this.subcomponent);
    }
  }

}
