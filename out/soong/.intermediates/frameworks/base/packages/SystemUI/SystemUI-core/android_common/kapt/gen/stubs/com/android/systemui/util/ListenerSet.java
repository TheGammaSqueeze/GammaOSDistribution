package com.android.systemui.util;

import java.util.concurrent.CopyOnWriteArrayList;

/**
 * A collection of listeners, observers, callbacks, etc.
 *
 * This container is optimized for infrequent mutation and frequent iteration, with thread safety
 * and reentrant-safety guarantees as well.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u001c\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010(\n\u0000\u0018\u0000*\u0004\b\u0000\u0010\u00012\b\u0012\u0004\u0012\u0002H\u00010\u0002B\u0005\u00a2\u0006\u0002\u0010\u0003J\u0013\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00028\u0000\u00a2\u0006\u0002\u0010\tJ\u000f\u0010\n\u001a\b\u0012\u0004\u0012\u00028\u00000\u000bH\u0096\u0002J\u0013\u0010\f\u001a\u00020\u00072\u0006\u0010\b\u001a\u00028\u0000\u00a2\u0006\u0002\u0010\tR\u0014\u0010\u0004\u001a\b\u0012\u0004\u0012\u00028\u00000\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/util/ListenerSet;", "E", "", "()V", "listeners", "Ljava/util/concurrent/CopyOnWriteArrayList;", "addIfAbsent", "", "element", "(Ljava/lang/Object;)Z", "iterator", "", "remove"})
public final class ListenerSet<E extends java.lang.Object> implements java.lang.Iterable<E> {
    private final java.util.concurrent.CopyOnWriteArrayList<E> listeners = null;
    
    /**
     * A thread-safe, reentrant-safe method to add a listener.
     * Does nothing if the listener is already in the set.
     */
    public final boolean addIfAbsent(E element) {
        return false;
    }
    
    /**
     * A thread-safe, reentrant-safe method to remove a listener.
     */
    public final boolean remove(E element) {
        return false;
    }
    
    /**
     * Returns an iterator over the listeners currently in the set.  Note that to ensure
     * [ConcurrentModificationException] is never thrown, this iterator will not reflect changes
     * made to the set after the iterator is constructed.
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.Iterator<E> iterator() {
        return null;
    }
    
    public ListenerSet() {
        super();
    }
}