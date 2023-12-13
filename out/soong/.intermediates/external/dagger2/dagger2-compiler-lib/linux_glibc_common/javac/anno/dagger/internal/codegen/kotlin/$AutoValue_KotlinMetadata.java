package dagger.internal.codegen.kotlin;

import javax.annotation.Generated;
import javax.lang.model.element.TypeElement;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
abstract class $AutoValue_KotlinMetadata extends KotlinMetadata {

  private final TypeElement typeElement;

  private final KotlinMetadata.ClassMetadata classMetadata;

  $AutoValue_KotlinMetadata(
      TypeElement typeElement,
      KotlinMetadata.ClassMetadata classMetadata) {
    if (typeElement == null) {
      throw new NullPointerException("Null typeElement");
    }
    this.typeElement = typeElement;
    if (classMetadata == null) {
      throw new NullPointerException("Null classMetadata");
    }
    this.classMetadata = classMetadata;
  }

  @Override
  TypeElement typeElement() {
    return typeElement;
  }

  @Override
  KotlinMetadata.ClassMetadata classMetadata() {
    return classMetadata;
  }

  @Override
  public String toString() {
    return "KotlinMetadata{"
        + "typeElement=" + typeElement + ", "
        + "classMetadata=" + classMetadata
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof KotlinMetadata) {
      KotlinMetadata that = (KotlinMetadata) o;
      return this.typeElement.equals(that.typeElement())
          && this.classMetadata.equals(that.classMetadata());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= typeElement.hashCode();
    h$ *= 1000003;
    h$ ^= classMetadata.hashCode();
    return h$;
  }

}
