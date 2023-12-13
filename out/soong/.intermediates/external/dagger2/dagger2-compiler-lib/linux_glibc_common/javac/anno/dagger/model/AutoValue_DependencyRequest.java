package dagger.model;

import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.Element;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_DependencyRequest extends DependencyRequest {

  private final RequestKind kind;

  private final Key key;

  private final Optional<Element> requestElement;

  private final boolean isNullable;

  private AutoValue_DependencyRequest(
      RequestKind kind,
      Key key,
      Optional<Element> requestElement,
      boolean isNullable) {
    this.kind = kind;
    this.key = key;
    this.requestElement = requestElement;
    this.isNullable = isNullable;
  }

  @Override
  public RequestKind kind() {
    return kind;
  }

  @Override
  public Key key() {
    return key;
  }

  @Override
  public Optional<Element> requestElement() {
    return requestElement;
  }

  @Override
  public boolean isNullable() {
    return isNullable;
  }

  @Override
  public String toString() {
    return "DependencyRequest{"
        + "kind=" + kind + ", "
        + "key=" + key + ", "
        + "requestElement=" + requestElement + ", "
        + "isNullable=" + isNullable
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof DependencyRequest) {
      DependencyRequest that = (DependencyRequest) o;
      return this.kind.equals(that.kind())
          && this.key.equals(that.key())
          && this.requestElement.equals(that.requestElement())
          && this.isNullable == that.isNullable();
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= kind.hashCode();
    h$ *= 1000003;
    h$ ^= key.hashCode();
    h$ *= 1000003;
    h$ ^= requestElement.hashCode();
    h$ *= 1000003;
    h$ ^= isNullable ? 1231 : 1237;
    return h$;
  }

  static final class Builder extends DependencyRequest.Builder {
    private RequestKind kind;
    private Key key;
    private Optional<Element> requestElement = Optional.empty();
    private Boolean isNullable;
    Builder() {
    }
    @Override
    public DependencyRequest.Builder kind(RequestKind kind) {
      if (kind == null) {
        throw new NullPointerException("Null kind");
      }
      this.kind = kind;
      return this;
    }
    @Override
    public DependencyRequest.Builder key(Key key) {
      if (key == null) {
        throw new NullPointerException("Null key");
      }
      this.key = key;
      return this;
    }
    @Override
    public DependencyRequest.Builder requestElement(Element requestElement) {
      this.requestElement = Optional.of(requestElement);
      return this;
    }
    @Override
    public DependencyRequest.Builder isNullable(boolean isNullable) {
      this.isNullable = isNullable;
      return this;
    }
    @Override
    public DependencyRequest build() {
      String missing = "";
      if (this.kind == null) {
        missing += " kind";
      }
      if (this.key == null) {
        missing += " key";
      }
      if (this.isNullable == null) {
        missing += " isNullable";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_DependencyRequest(
          this.kind,
          this.key,
          this.requestElement,
          this.isNullable);
    }
  }

}
