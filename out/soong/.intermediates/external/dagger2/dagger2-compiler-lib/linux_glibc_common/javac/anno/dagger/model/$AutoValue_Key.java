package dagger.model;

import com.google.common.base.Equivalence;
import java.util.Optional;
import javax.annotation.Generated;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.type.TypeMirror;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_Key extends Key {

  private final Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedQualifier;

  private final Equivalence.Wrapper<TypeMirror> wrappedType;

  private final Optional<Key.MultibindingContributionIdentifier> multibindingContributionIdentifier;

  $AutoValue_Key(
      Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedQualifier,
      Equivalence.Wrapper<TypeMirror> wrappedType,
      Optional<Key.MultibindingContributionIdentifier> multibindingContributionIdentifier) {
    if (wrappedQualifier == null) {
      throw new NullPointerException("Null wrappedQualifier");
    }
    this.wrappedQualifier = wrappedQualifier;
    if (wrappedType == null) {
      throw new NullPointerException("Null wrappedType");
    }
    this.wrappedType = wrappedType;
    if (multibindingContributionIdentifier == null) {
      throw new NullPointerException("Null multibindingContributionIdentifier");
    }
    this.multibindingContributionIdentifier = multibindingContributionIdentifier;
  }

  @Override
  Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedQualifier() {
    return wrappedQualifier;
  }

  @Override
  Equivalence.Wrapper<TypeMirror> wrappedType() {
    return wrappedType;
  }

  @Override
  public Optional<Key.MultibindingContributionIdentifier> multibindingContributionIdentifier() {
    return multibindingContributionIdentifier;
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Key) {
      Key that = (Key) o;
      return this.wrappedQualifier.equals(that.wrappedQualifier())
          && this.wrappedType.equals(that.wrappedType())
          && this.multibindingContributionIdentifier.equals(that.multibindingContributionIdentifier());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= wrappedQualifier.hashCode();
    h$ *= 1000003;
    h$ ^= wrappedType.hashCode();
    h$ *= 1000003;
    h$ ^= multibindingContributionIdentifier.hashCode();
    return h$;
  }

  @Override
  public Key.Builder toBuilder() {
    return new Builder(this);
  }

  static class Builder extends Key.Builder {
    private Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedQualifier = Optional.empty();
    private Equivalence.Wrapper<TypeMirror> wrappedType;
    private Optional<Key.MultibindingContributionIdentifier> multibindingContributionIdentifier = Optional.empty();
    Builder() {
    }
    private Builder(Key source) {
      this.wrappedQualifier = source.wrappedQualifier();
      this.wrappedType = source.wrappedType();
      this.multibindingContributionIdentifier = source.multibindingContributionIdentifier();
    }
    @Override
    Key.Builder wrappedQualifier(Optional<Equivalence.Wrapper<AnnotationMirror>> wrappedQualifier) {
      if (wrappedQualifier == null) {
        throw new NullPointerException("Null wrappedQualifier");
      }
      this.wrappedQualifier = wrappedQualifier;
      return this;
    }
    @Override
    Key.Builder wrappedQualifier(Equivalence.Wrapper<AnnotationMirror> wrappedQualifier) {
      this.wrappedQualifier = Optional.of(wrappedQualifier);
      return this;
    }
    @Override
    Key.Builder wrappedType(Equivalence.Wrapper<TypeMirror> wrappedType) {
      if (wrappedType == null) {
        throw new NullPointerException("Null wrappedType");
      }
      this.wrappedType = wrappedType;
      return this;
    }
    @Override
    public Key.Builder multibindingContributionIdentifier(Optional<Key.MultibindingContributionIdentifier> multibindingContributionIdentifier) {
      if (multibindingContributionIdentifier == null) {
        throw new NullPointerException("Null multibindingContributionIdentifier");
      }
      this.multibindingContributionIdentifier = multibindingContributionIdentifier;
      return this;
    }
    @Override
    public Key.Builder multibindingContributionIdentifier(Key.MultibindingContributionIdentifier multibindingContributionIdentifier) {
      this.multibindingContributionIdentifier = Optional.of(multibindingContributionIdentifier);
      return this;
    }
    @Override
    public Key build() {
      String missing = "";
      if (this.wrappedType == null) {
        missing += " wrappedType";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_Key(
          this.wrappedQualifier,
          this.wrappedType,
          this.multibindingContributionIdentifier);
    }
  }

}
