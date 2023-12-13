package com.google.turbine.binder;

import com.google.common.collect.ImmutableMap;
import java.time.Duration;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Binder_Statistics extends Binder.Statistics {

  private final ImmutableMap<String, Duration> processingTime;

  private final ImmutableMap<String, byte[]> processorMetrics;

  AutoValue_Binder_Statistics(
      ImmutableMap<String, Duration> processingTime,
      ImmutableMap<String, byte[]> processorMetrics) {
    if (processingTime == null) {
      throw new NullPointerException("Null processingTime");
    }
    this.processingTime = processingTime;
    if (processorMetrics == null) {
      throw new NullPointerException("Null processorMetrics");
    }
    this.processorMetrics = processorMetrics;
  }

  @Override
  public ImmutableMap<String, Duration> processingTime() {
    return processingTime;
  }

  @Override
  public ImmutableMap<String, byte[]> processorMetrics() {
    return processorMetrics;
  }

  @Override
  public String toString() {
    return "Statistics{"
        + "processingTime=" + processingTime + ", "
        + "processorMetrics=" + processorMetrics
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Binder.Statistics) {
      Binder.Statistics that = (Binder.Statistics) o;
      return this.processingTime.equals(that.processingTime())
          && this.processorMetrics.equals(that.processorMetrics());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= processingTime.hashCode();
    h$ *= 1000003;
    h$ ^= processorMetrics.hashCode();
    return h$;
  }

}
