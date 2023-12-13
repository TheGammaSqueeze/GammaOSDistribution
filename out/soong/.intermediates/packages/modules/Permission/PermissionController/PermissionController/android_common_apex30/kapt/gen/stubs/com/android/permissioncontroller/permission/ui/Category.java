package com.android.permissioncontroller.permission.ui;

import java.lang.System;

/**
 * A class representing the grant states of a permission, which correspond to the keys of the
 * preferences in the allowed_denied.xml file.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0007\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006j\u0002\b\u0007j\u0002\b\bj\u0002\b\tj\u0002\b\n"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/Category;", "", "categoryName", "", "(Ljava/lang/String;ILjava/lang/String;)V", "getCategoryName", "()Ljava/lang/String;", "ALLOWED", "ALLOWED_FOREGROUND", "ASK", "DENIED"})
public enum Category {
    /*public static final*/ ALLOWED /* = new ALLOWED(null) */,
    /*public static final*/ ALLOWED_FOREGROUND /* = new ALLOWED_FOREGROUND(null) */,
    /*public static final*/ ASK /* = new ASK(null) */,
    /*public static final*/ DENIED /* = new DENIED(null) */;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String categoryName = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getCategoryName() {
        return null;
    }
    
    Category(java.lang.String categoryName) {
    }
}