package com.google.auto.factory.processor;

import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_PackageAndClass extends PackageAndClass {

  private final String packageName;

  private final String className;

  AutoValue_PackageAndClass(
      String packageName,
      String className) {
    if (packageName == null) {
      throw new NullPointerException("Null packageName");
    }
    this.packageName = packageName;
    if (className == null) {
      throw new NullPointerException("Null className");
    }
    this.className = className;
  }

  @Override
  String packageName() {
    return packageName;
  }

  @Override
  String className() {
    return className;
  }

  @Override
  public String toString() {
    return "PackageAndClass{"
        + "packageName=" + packageName + ", "
        + "className=" + className
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof PackageAndClass) {
      PackageAndClass that = (PackageAndClass) o;
      return this.packageName.equals(that.packageName())
          && this.className.equals(that.className());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= packageName.hashCode();
    h$ *= 1000003;
    h$ ^= className.hashCode();
    return h$;
  }

}
