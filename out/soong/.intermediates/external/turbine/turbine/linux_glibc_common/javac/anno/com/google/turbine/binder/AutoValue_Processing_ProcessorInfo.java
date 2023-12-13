package com.google.turbine.binder;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import javax.annotation.processing.Generated;
import javax.annotation.processing.Processor;
import javax.lang.model.SourceVersion;
import org.checkerframework.checker.nullness.qual.Nullable;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_Processing_ProcessorInfo extends Processing.ProcessorInfo {

  private final ImmutableList<Processor> processors;

  private final @Nullable ClassLoader loader;

  private final ImmutableMap<String, String> options;

  private final SourceVersion sourceVersion;

  AutoValue_Processing_ProcessorInfo(
      ImmutableList<Processor> processors,
      @Nullable ClassLoader loader,
      ImmutableMap<String, String> options,
      SourceVersion sourceVersion) {
    if (processors == null) {
      throw new NullPointerException("Null processors");
    }
    this.processors = processors;
    this.loader = loader;
    if (options == null) {
      throw new NullPointerException("Null options");
    }
    this.options = options;
    if (sourceVersion == null) {
      throw new NullPointerException("Null sourceVersion");
    }
    this.sourceVersion = sourceVersion;
  }

  @Override
  ImmutableList<Processor> processors() {
    return processors;
  }

  @Override
  @Nullable ClassLoader loader() {
    return loader;
  }

  @Override
  ImmutableMap<String, String> options() {
    return options;
  }

  @Override
  public SourceVersion sourceVersion() {
    return sourceVersion;
  }

  @Override
  public String toString() {
    return "ProcessorInfo{"
        + "processors=" + processors + ", "
        + "loader=" + loader + ", "
        + "options=" + options + ", "
        + "sourceVersion=" + sourceVersion
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof Processing.ProcessorInfo) {
      Processing.ProcessorInfo that = (Processing.ProcessorInfo) o;
      return this.processors.equals(that.processors())
          && (this.loader == null ? that.loader() == null : this.loader.equals(that.loader()))
          && this.options.equals(that.options())
          && this.sourceVersion.equals(that.sourceVersion());
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= processors.hashCode();
    h$ *= 1000003;
    h$ ^= (loader == null) ? 0 : loader.hashCode();
    h$ *= 1000003;
    h$ ^= options.hashCode();
    h$ *= 1000003;
    h$ ^= sourceVersion.hashCode();
    return h$;
  }

}
