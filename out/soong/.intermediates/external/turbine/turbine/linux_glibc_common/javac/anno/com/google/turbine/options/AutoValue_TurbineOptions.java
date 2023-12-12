package com.google.turbine.options;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import java.util.Optional;
import javax.annotation.processing.Generated;

@Generated("com.google.auto.value.processor.AutoValueProcessor")
final class AutoValue_TurbineOptions extends TurbineOptions {

  private final ImmutableList<String> sources;

  private final ImmutableList<String> classPath;

  private final ImmutableSet<String> bootClassPath;

  private final Optional<String> release;

  private final Optional<String> system;

  private final Optional<String> output;

  private final ImmutableList<String> processorPath;

  private final ImmutableSet<String> processors;

  private final ImmutableSet<String> builtinProcessors;

  private final ImmutableList<String> sourceJars;

  private final Optional<String> outputDeps;

  private final Optional<String> outputManifest;

  private final ImmutableSet<String> directJars;

  private final Optional<String> targetLabel;

  private final Optional<String> injectingRuleKind;

  private final ImmutableList<String> depsArtifacts;

  private final boolean help;

  private final ImmutableList<String> javacOpts;

  private final TurbineOptions.ReducedClasspathMode reducedClasspathMode;

  private final Optional<String> profile;

  private final Optional<String> gensrcOutput;

  private final Optional<String> resourceOutput;

  private final int fullClasspathLength;

  private final int reducedClasspathLength;

  private AutoValue_TurbineOptions(
      ImmutableList<String> sources,
      ImmutableList<String> classPath,
      ImmutableSet<String> bootClassPath,
      Optional<String> release,
      Optional<String> system,
      Optional<String> output,
      ImmutableList<String> processorPath,
      ImmutableSet<String> processors,
      ImmutableSet<String> builtinProcessors,
      ImmutableList<String> sourceJars,
      Optional<String> outputDeps,
      Optional<String> outputManifest,
      ImmutableSet<String> directJars,
      Optional<String> targetLabel,
      Optional<String> injectingRuleKind,
      ImmutableList<String> depsArtifacts,
      boolean help,
      ImmutableList<String> javacOpts,
      TurbineOptions.ReducedClasspathMode reducedClasspathMode,
      Optional<String> profile,
      Optional<String> gensrcOutput,
      Optional<String> resourceOutput,
      int fullClasspathLength,
      int reducedClasspathLength) {
    this.sources = sources;
    this.classPath = classPath;
    this.bootClassPath = bootClassPath;
    this.release = release;
    this.system = system;
    this.output = output;
    this.processorPath = processorPath;
    this.processors = processors;
    this.builtinProcessors = builtinProcessors;
    this.sourceJars = sourceJars;
    this.outputDeps = outputDeps;
    this.outputManifest = outputManifest;
    this.directJars = directJars;
    this.targetLabel = targetLabel;
    this.injectingRuleKind = injectingRuleKind;
    this.depsArtifacts = depsArtifacts;
    this.help = help;
    this.javacOpts = javacOpts;
    this.reducedClasspathMode = reducedClasspathMode;
    this.profile = profile;
    this.gensrcOutput = gensrcOutput;
    this.resourceOutput = resourceOutput;
    this.fullClasspathLength = fullClasspathLength;
    this.reducedClasspathLength = reducedClasspathLength;
  }

  @Override
  public ImmutableList<String> sources() {
    return sources;
  }

  @Override
  public ImmutableList<String> classPath() {
    return classPath;
  }

  @Override
  public ImmutableSet<String> bootClassPath() {
    return bootClassPath;
  }

  @Override
  public Optional<String> release() {
    return release;
  }

  @Override
  public Optional<String> system() {
    return system;
  }

  @Override
  public Optional<String> output() {
    return output;
  }

  @Override
  public ImmutableList<String> processorPath() {
    return processorPath;
  }

  @Override
  public ImmutableSet<String> processors() {
    return processors;
  }

  @Override
  public ImmutableSet<String> builtinProcessors() {
    return builtinProcessors;
  }

  @Override
  public ImmutableList<String> sourceJars() {
    return sourceJars;
  }

  @Override
  public Optional<String> outputDeps() {
    return outputDeps;
  }

  @Override
  public Optional<String> outputManifest() {
    return outputManifest;
  }

  @Override
  public ImmutableSet<String> directJars() {
    return directJars;
  }

  @Override
  public Optional<String> targetLabel() {
    return targetLabel;
  }

  @Override
  public Optional<String> injectingRuleKind() {
    return injectingRuleKind;
  }

  @Override
  public ImmutableList<String> depsArtifacts() {
    return depsArtifacts;
  }

  @Override
  public boolean help() {
    return help;
  }

  @Override
  public ImmutableList<String> javacOpts() {
    return javacOpts;
  }

  @Override
  public TurbineOptions.ReducedClasspathMode reducedClasspathMode() {
    return reducedClasspathMode;
  }

  @Override
  public Optional<String> profile() {
    return profile;
  }

  @Override
  public Optional<String> gensrcOutput() {
    return gensrcOutput;
  }

  @Override
  public Optional<String> resourceOutput() {
    return resourceOutput;
  }

  @Override
  public int fullClasspathLength() {
    return fullClasspathLength;
  }

  @Override
  public int reducedClasspathLength() {
    return reducedClasspathLength;
  }

  @Override
  public String toString() {
    return "TurbineOptions{"
        + "sources=" + sources + ", "
        + "classPath=" + classPath + ", "
        + "bootClassPath=" + bootClassPath + ", "
        + "release=" + release + ", "
        + "system=" + system + ", "
        + "output=" + output + ", "
        + "processorPath=" + processorPath + ", "
        + "processors=" + processors + ", "
        + "builtinProcessors=" + builtinProcessors + ", "
        + "sourceJars=" + sourceJars + ", "
        + "outputDeps=" + outputDeps + ", "
        + "outputManifest=" + outputManifest + ", "
        + "directJars=" + directJars + ", "
        + "targetLabel=" + targetLabel + ", "
        + "injectingRuleKind=" + injectingRuleKind + ", "
        + "depsArtifacts=" + depsArtifacts + ", "
        + "help=" + help + ", "
        + "javacOpts=" + javacOpts + ", "
        + "reducedClasspathMode=" + reducedClasspathMode + ", "
        + "profile=" + profile + ", "
        + "gensrcOutput=" + gensrcOutput + ", "
        + "resourceOutput=" + resourceOutput + ", "
        + "fullClasspathLength=" + fullClasspathLength + ", "
        + "reducedClasspathLength=" + reducedClasspathLength
        + "}";
  }

  @Override
  public boolean equals(Object o) {
    if (o == this) {
      return true;
    }
    if (o instanceof TurbineOptions) {
      TurbineOptions that = (TurbineOptions) o;
      return this.sources.equals(that.sources())
          && this.classPath.equals(that.classPath())
          && this.bootClassPath.equals(that.bootClassPath())
          && this.release.equals(that.release())
          && this.system.equals(that.system())
          && this.output.equals(that.output())
          && this.processorPath.equals(that.processorPath())
          && this.processors.equals(that.processors())
          && this.builtinProcessors.equals(that.builtinProcessors())
          && this.sourceJars.equals(that.sourceJars())
          && this.outputDeps.equals(that.outputDeps())
          && this.outputManifest.equals(that.outputManifest())
          && this.directJars.equals(that.directJars())
          && this.targetLabel.equals(that.targetLabel())
          && this.injectingRuleKind.equals(that.injectingRuleKind())
          && this.depsArtifacts.equals(that.depsArtifacts())
          && this.help == that.help()
          && this.javacOpts.equals(that.javacOpts())
          && this.reducedClasspathMode.equals(that.reducedClasspathMode())
          && this.profile.equals(that.profile())
          && this.gensrcOutput.equals(that.gensrcOutput())
          && this.resourceOutput.equals(that.resourceOutput())
          && this.fullClasspathLength == that.fullClasspathLength()
          && this.reducedClasspathLength == that.reducedClasspathLength();
    }
    return false;
  }

  @Override
  public int hashCode() {
    int h$ = 1;
    h$ *= 1000003;
    h$ ^= sources.hashCode();
    h$ *= 1000003;
    h$ ^= classPath.hashCode();
    h$ *= 1000003;
    h$ ^= bootClassPath.hashCode();
    h$ *= 1000003;
    h$ ^= release.hashCode();
    h$ *= 1000003;
    h$ ^= system.hashCode();
    h$ *= 1000003;
    h$ ^= output.hashCode();
    h$ *= 1000003;
    h$ ^= processorPath.hashCode();
    h$ *= 1000003;
    h$ ^= processors.hashCode();
    h$ *= 1000003;
    h$ ^= builtinProcessors.hashCode();
    h$ *= 1000003;
    h$ ^= sourceJars.hashCode();
    h$ *= 1000003;
    h$ ^= outputDeps.hashCode();
    h$ *= 1000003;
    h$ ^= outputManifest.hashCode();
    h$ *= 1000003;
    h$ ^= directJars.hashCode();
    h$ *= 1000003;
    h$ ^= targetLabel.hashCode();
    h$ *= 1000003;
    h$ ^= injectingRuleKind.hashCode();
    h$ *= 1000003;
    h$ ^= depsArtifacts.hashCode();
    h$ *= 1000003;
    h$ ^= help ? 1231 : 1237;
    h$ *= 1000003;
    h$ ^= javacOpts.hashCode();
    h$ *= 1000003;
    h$ ^= reducedClasspathMode.hashCode();
    h$ *= 1000003;
    h$ ^= profile.hashCode();
    h$ *= 1000003;
    h$ ^= gensrcOutput.hashCode();
    h$ *= 1000003;
    h$ ^= resourceOutput.hashCode();
    h$ *= 1000003;
    h$ ^= fullClasspathLength;
    h$ *= 1000003;
    h$ ^= reducedClasspathLength;
    return h$;
  }

  static final class Builder extends TurbineOptions.Builder {
    private ImmutableList<String> sources;
    private ImmutableList<String> classPath;
    private ImmutableSet<String> bootClassPath;
    private Optional<String> release = Optional.empty();
    private Optional<String> system = Optional.empty();
    private Optional<String> output = Optional.empty();
    private ImmutableList<String> processorPath;
    private ImmutableSet<String> processors;
    private ImmutableSet<String> builtinProcessors;
    private ImmutableList<String> sourceJars;
    private Optional<String> outputDeps = Optional.empty();
    private Optional<String> outputManifest = Optional.empty();
    private ImmutableSet<String> directJars;
    private Optional<String> targetLabel = Optional.empty();
    private Optional<String> injectingRuleKind = Optional.empty();
    private ImmutableList<String> depsArtifacts;
    private Boolean help;
    private ImmutableList.Builder<String> javacOptsBuilder$;
    private ImmutableList<String> javacOpts;
    private TurbineOptions.ReducedClasspathMode reducedClasspathMode;
    private Optional<String> profile = Optional.empty();
    private Optional<String> gensrcOutput = Optional.empty();
    private Optional<String> resourceOutput = Optional.empty();
    private Integer fullClasspathLength;
    private Integer reducedClasspathLength;
    Builder() {
    }
    @Override
    public TurbineOptions.Builder setSources(ImmutableList<String> sources) {
      if (sources == null) {
        throw new NullPointerException("Null sources");
      }
      this.sources = sources;
      return this;
    }
    @Override
    public TurbineOptions.Builder setClassPath(ImmutableList<String> classPath) {
      if (classPath == null) {
        throw new NullPointerException("Null classPath");
      }
      this.classPath = classPath;
      return this;
    }
    @Override
    public TurbineOptions.Builder setBootClassPath(ImmutableList<String> bootClassPath) {
      this.bootClassPath = ImmutableSet.copyOf(bootClassPath);
      return this;
    }
    @Override
    public TurbineOptions.Builder setRelease(String release) {
      this.release = Optional.of(release);
      return this;
    }
    @Override
    public TurbineOptions.Builder setSystem(String system) {
      this.system = Optional.of(system);
      return this;
    }
    @Override
    public TurbineOptions.Builder setOutput(String output) {
      this.output = Optional.of(output);
      return this;
    }
    @Override
    public TurbineOptions.Builder setProcessorPath(ImmutableList<String> processorPath) {
      if (processorPath == null) {
        throw new NullPointerException("Null processorPath");
      }
      this.processorPath = processorPath;
      return this;
    }
    @Override
    public TurbineOptions.Builder setProcessors(ImmutableList<String> processors) {
      this.processors = ImmutableSet.copyOf(processors);
      return this;
    }
    @Override
    public TurbineOptions.Builder setBuiltinProcessors(ImmutableList<String> builtinProcessors) {
      this.builtinProcessors = ImmutableSet.copyOf(builtinProcessors);
      return this;
    }
    @Override
    public TurbineOptions.Builder setSourceJars(ImmutableList<String> sourceJars) {
      if (sourceJars == null) {
        throw new NullPointerException("Null sourceJars");
      }
      this.sourceJars = sourceJars;
      return this;
    }
    @Override
    public TurbineOptions.Builder setOutputDeps(String outputDeps) {
      this.outputDeps = Optional.of(outputDeps);
      return this;
    }
    @Override
    public TurbineOptions.Builder setOutputManifest(String outputManifest) {
      this.outputManifest = Optional.of(outputManifest);
      return this;
    }
    @Override
    public TurbineOptions.Builder setDirectJars(ImmutableList<String> directJars) {
      this.directJars = ImmutableSet.copyOf(directJars);
      return this;
    }
    @Override
    public TurbineOptions.Builder setTargetLabel(String targetLabel) {
      this.targetLabel = Optional.of(targetLabel);
      return this;
    }
    @Override
    public TurbineOptions.Builder setInjectingRuleKind(String injectingRuleKind) {
      this.injectingRuleKind = Optional.of(injectingRuleKind);
      return this;
    }
    @Override
    public TurbineOptions.Builder setDepsArtifacts(ImmutableList<String> depsArtifacts) {
      if (depsArtifacts == null) {
        throw new NullPointerException("Null depsArtifacts");
      }
      this.depsArtifacts = depsArtifacts;
      return this;
    }
    @Override
    public TurbineOptions.Builder setHelp(boolean help) {
      this.help = help;
      return this;
    }
    @Override
    ImmutableList.Builder<String> javacOptsBuilder() {
      if (javacOptsBuilder$ == null) {
        javacOptsBuilder$ = ImmutableList.builder();
      }
      return javacOptsBuilder$;
    }
    @Override
    public TurbineOptions.Builder setReducedClasspathMode(TurbineOptions.ReducedClasspathMode reducedClasspathMode) {
      if (reducedClasspathMode == null) {
        throw new NullPointerException("Null reducedClasspathMode");
      }
      this.reducedClasspathMode = reducedClasspathMode;
      return this;
    }
    @Override
    public TurbineOptions.Builder setProfile(String profile) {
      this.profile = Optional.of(profile);
      return this;
    }
    @Override
    public TurbineOptions.Builder setGensrcOutput(String gensrcOutput) {
      this.gensrcOutput = Optional.of(gensrcOutput);
      return this;
    }
    @Override
    public TurbineOptions.Builder setResourceOutput(String resourceOutput) {
      this.resourceOutput = Optional.of(resourceOutput);
      return this;
    }
    @Override
    public TurbineOptions.Builder setFullClasspathLength(int fullClasspathLength) {
      this.fullClasspathLength = fullClasspathLength;
      return this;
    }
    @Override
    public TurbineOptions.Builder setReducedClasspathLength(int reducedClasspathLength) {
      this.reducedClasspathLength = reducedClasspathLength;
      return this;
    }
    @Override
    public TurbineOptions build() {
      if (javacOptsBuilder$ != null) {
        this.javacOpts = javacOptsBuilder$.build();
      } else if (this.javacOpts == null) {
        this.javacOpts = ImmutableList.of();
      }
      String missing = "";
      if (this.sources == null) {
        missing += " sources";
      }
      if (this.classPath == null) {
        missing += " classPath";
      }
      if (this.bootClassPath == null) {
        missing += " bootClassPath";
      }
      if (this.processorPath == null) {
        missing += " processorPath";
      }
      if (this.processors == null) {
        missing += " processors";
      }
      if (this.builtinProcessors == null) {
        missing += " builtinProcessors";
      }
      if (this.sourceJars == null) {
        missing += " sourceJars";
      }
      if (this.directJars == null) {
        missing += " directJars";
      }
      if (this.depsArtifacts == null) {
        missing += " depsArtifacts";
      }
      if (this.help == null) {
        missing += " help";
      }
      if (this.reducedClasspathMode == null) {
        missing += " reducedClasspathMode";
      }
      if (this.fullClasspathLength == null) {
        missing += " fullClasspathLength";
      }
      if (this.reducedClasspathLength == null) {
        missing += " reducedClasspathLength";
      }
      if (!missing.isEmpty()) {
        throw new IllegalStateException("Missing required properties:" + missing);
      }
      return new AutoValue_TurbineOptions(
          this.sources,
          this.classPath,
          this.bootClassPath,
          this.release,
          this.system,
          this.output,
          this.processorPath,
          this.processors,
          this.builtinProcessors,
          this.sourceJars,
          this.outputDeps,
          this.outputManifest,
          this.directJars,
          this.targetLabel,
          this.injectingRuleKind,
          this.depsArtifacts,
          this.help,
          this.javacOpts,
          this.reducedClasspathMode,
          this.profile,
          this.gensrcOutput,
          this.resourceOutput,
          this.fullClasspathLength,
          this.reducedClasspathLength);
    }
  }

}
