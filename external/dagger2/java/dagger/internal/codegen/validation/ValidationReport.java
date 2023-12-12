/*
 * Copyright (C) 2014 The Dagger Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package dagger.internal.codegen.validation;

import static dagger.internal.codegen.base.ElementFormatter.elementToString;
import static dagger.internal.codegen.extension.DaggerStreams.toImmutableSet;
import static javax.tools.Diagnostic.Kind.ERROR;
import static javax.tools.Diagnostic.Kind.NOTE;
import static javax.tools.Diagnostic.Kind.WARNING;

import com.google.auto.value.AutoValue;
import com.google.common.collect.ImmutableSet;
import com.google.common.graph.Traverser;
import com.google.errorprone.annotations.CanIgnoreReturnValue;
import com.google.errorprone.annotations.CheckReturnValue;
import java.util.Optional;
import javax.annotation.processing.Messager;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.AnnotationValue;
import javax.lang.model.element.Element;
import javax.tools.Diagnostic;
import javax.tools.Diagnostic.Kind;

/** A collection of issues to report for source code. */
public final class ValidationReport<T extends Element> {
  private static final Traverser<ValidationReport<?>> SUBREPORTS =
      Traverser.forTree(report -> report.subreports);

  private final T subject;
  private final ImmutableSet<Item> items;
  private final ImmutableSet<ValidationReport<?>> subreports;
  private final boolean markedDirty;
  private boolean hasPrintedErrors;

  private ValidationReport(
      T subject,
      ImmutableSet<Item> items,
      ImmutableSet<ValidationReport<?>> subreports,
      boolean markedDirty) {
    this.subject = subject;
    this.items = items;
    this.subreports = subreports;
    this.markedDirty = markedDirty;
  }

  /** Returns the items from this report and all transitive subreports. */
  public ImmutableSet<Item> allItems() {
    return ImmutableSet.copyOf(SUBREPORTS.depthFirstPreOrder(this))
        .stream()
        .flatMap(report -> report.items.stream())
        .collect(toImmutableSet());
  }

  /**
   * Returns {@code true} if there are no errors in this report or any subreports and markedDirty is
   * {@code false}.
   */
  public boolean isClean() {
    if (markedDirty) {
      return false;
    }
    for (Item item : items) {
      switch (item.kind()) {
        case ERROR:
          return false;
        default:
          break;
      }
    }
    for (ValidationReport<?> subreport : subreports) {
      if (!subreport.isClean()) {
        return false;
      }
    }
    return true;
  }

  /**
   * Prints all messages to {@code messager} (and recurs for subreports). If a
   * message's {@linkplain Item#element() element} is contained within the report's subject,
   * associates the message with the message's element. Otherwise, since {@link Diagnostic}
   * reporting is expected to be associated with elements that are currently being compiled,
   * associates the message with the subject itself and prepends a reference to the item's element.
   */
  public void printMessagesTo(Messager messager) {
    if (hasPrintedErrors) {
      // Avoid printing the errors from this validation report more than once.
      return;
    }
    hasPrintedErrors = true;
    for (Item item : items) {
      if (isEnclosedIn(subject, item.element())) {
        if (item.annotation().isPresent()) {
          if (item.annotationValue().isPresent()) {
            messager.printMessage(
                item.kind(),
                item.message(),
                item.element(),
                item.annotation().get(),
                item.annotationValue().get());
          } else {
            messager.printMessage(
                item.kind(), item.message(), item.element(), item.annotation().get());
          }
        } else {
          messager.printMessage(item.kind(), item.message(), item.element());
        }
      } else {
        String message = String.format("[%s] %s", elementToString(item.element()), item.message());
        messager.printMessage(item.kind(), message, subject);
      }
    }
    for (ValidationReport<?> subreport : subreports) {
      subreport.printMessagesTo(messager);
    }
  }

  private static boolean isEnclosedIn(Element parent, Element child) {
    Element current = child;
    while (current != null) {
      if (current.equals(parent)) {
        return true;
      }
      current = current.getEnclosingElement();
    }
    return false;
  }

  /** Metadata about a {@link ValidationReport} item. */
  @AutoValue
  public abstract static class Item {
    public abstract String message();
    public abstract Kind kind();
    public abstract Element element();
    public abstract Optional<AnnotationMirror> annotation();
    abstract Optional<AnnotationValue> annotationValue();
  }

  public static <T extends Element> Builder<T> about(T subject) {
    return new Builder<>(subject);
  }

  /** A {@link ValidationReport} builder. */
  @CanIgnoreReturnValue
  public static final class Builder<T extends Element> {
    private final T subject;
    private final ImmutableSet.Builder<Item> items = ImmutableSet.builder();
    private final ImmutableSet.Builder<ValidationReport<?>> subreports = ImmutableSet.builder();
    private boolean markedDirty;

    private Builder(T subject) {
      this.subject = subject;
    }

    @CheckReturnValue
    T getSubject() {
      return subject;
    }

    Builder<T> addItems(Iterable<Item> newItems) {
      items.addAll(newItems);
      return this;
    }

    public Builder<T> addError(String message) {
      return addError(message, subject);
    }

    public Builder<T> addError(String message, Element element) {
      return addItem(message, ERROR, element);
    }

    public Builder<T> addError(String message, Element element, AnnotationMirror annotation) {
      return addItem(message, ERROR, element, annotation);
    }

    public Builder<T> addError(
        String message,
        Element element,
        AnnotationMirror annotation,
        AnnotationValue annotationValue) {
      return addItem(message, ERROR, element, annotation, annotationValue);
    }

    Builder<T> addWarning(String message) {
      return addWarning(message, subject);
    }

    Builder<T> addWarning(String message, Element element) {
      return addItem(message, WARNING, element);
    }

    Builder<T> addWarning(String message, Element element, AnnotationMirror annotation) {
      return addItem(message, WARNING, element, annotation);
    }

    Builder<T> addWarning(
        String message,
        Element element,
        AnnotationMirror annotation,
        AnnotationValue annotationValue) {
      return addItem(message, WARNING, element, annotation, annotationValue);
    }

    Builder<T> addNote(String message) {
      return addNote(message, subject);
    }

    Builder<T> addNote(String message, Element element) {
      return addItem(message, NOTE, element);
    }

    Builder<T> addNote(String message, Element element, AnnotationMirror annotation) {
      return addItem(message, NOTE, element, annotation);
    }

    Builder<T> addNote(
        String message,
        Element element,
        AnnotationMirror annotation,
        AnnotationValue annotationValue) {
      return addItem(message, NOTE, element, annotation, annotationValue);
    }

    Builder<T> addItem(String message, Kind kind, Element element) {
      return addItem(message, kind, element, Optional.empty(), Optional.empty());
    }

    Builder<T> addItem(String message, Kind kind, Element element, AnnotationMirror annotation) {
      return addItem(message, kind, element, Optional.of(annotation), Optional.empty());
    }

    Builder<T> addItem(
        String message,
        Kind kind,
        Element element,
        AnnotationMirror annotation,
        AnnotationValue annotationValue) {
      return addItem(message, kind, element, Optional.of(annotation), Optional.of(annotationValue));
    }

    private Builder<T> addItem(
        String message,
        Kind kind,
        Element element,
        Optional<AnnotationMirror> annotation,
        Optional<AnnotationValue> annotationValue) {
      items.add(
          new AutoValue_ValidationReport_Item(message, kind, element, annotation, annotationValue));
      return this;
    }

    /**
     * If called, then {@link #isClean()} will return {@code false} even if there are no error items
     * in the report.
     */
    void markDirty() {
      this.markedDirty = true;
    }

    public Builder<T> addSubreport(ValidationReport<?> subreport) {
      subreports.add(subreport);
      return this;
    }

    @CheckReturnValue
    public ValidationReport<T> build() {
      return new ValidationReport<>(subject, items.build(), subreports.build(), markedDirty);
    }
  }
}
