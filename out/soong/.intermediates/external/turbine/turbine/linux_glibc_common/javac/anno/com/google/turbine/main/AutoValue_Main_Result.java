package com.google.turbine.main;

import com.google.turbine.binder.Binder;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Main_Result extends Main.Result {

  private final boolean transitiveClasspathFallback;

  private final int transitiveClasspathLength;

  private final int reducedClasspathLength;

  private final Binder.Statistics processorStatistics;

  AutoValue_Main_Result(
      boolean transitiveClasspathFallback,
      int transitiveClasspathLength,
      int reducedClasspathLength,
      Binder.Statistics processorStatistics) {
    this.transitiveClasspathFallback = transitiveClasspathFallback;
    this.transitiveClasspathLength = transitiveClasspathLength;
    this.reducedClasspathLength = reducedClasspathLength;
    if (processorStatistics == null) {
      throw new NullPointerException("Null processorStatistics");
    }
    this.processorStatistics = processorStatistics;
  }

  @Override
  public boolean transitiveClasspathFallback() {
    return transitiveClasspathFallback;
  }

  @Override
  public int transitiveClasspathLength() {
    return transitiveClasspathLength;
  }

  @Override
  public int reducedClasspathLength() {
    return reducedClasspathLength;
  }

  @Override
  public Binder.Statistics processorStatistics() {
    return processorStatistics;
  }

  @Override
  public String toString() {
    return "Result{"
        + "transitiveClasspathFallback=" + transitiveClasspathFallback + ", "
        + "transitiveClasspathLength=" + transitiveClasspathLength + ", "
        + "reducedClasspathLength=" + reducedClasspathLength + ", "
        + "processorStatistics=" + processorStatistics
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Main.Result) {
      Main.Result that = (Main.Result) o;
      return this.transitiveClasspathFallback == that.transitiveClasspathFallback()
          && this.transitiveClasspathLength == that.transitiveClasspathLength()
          && this.reducedClasspathLength == that.reducedClasspathLength()
          && this.processorStatistics.equals(that.processorStatistics());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= transitiveClasspathFallback ? 1231 : 1237;
    h$ *= 1000003;
    h$ ^= transitiveClasspathLength;
    h$ *= 1000003;
    h$ ^= reducedClasspathLength;
    h$ *= 1000003;
    h$ ^= processorStatistics.hashCode();
    return h$;
  }

}
