package com.android.systemui.controls.controller;

import android.app.backup.BackupManager;
import android.content.ComponentName;
import android.util.AtomicFile;
import android.util.Log;
import android.util.Xml;
import com.android.systemui.backup.BackupHelper;
import libcore.io.IoUtils;
import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.concurrent.Executor;

/**
 * Manages persistence of favorite controls.
 *
 * This class uses an [AtomicFile] to serialize the favorite controls to an xml.
 * @property file a file location for storing/reading the favorites.
 * @property executor an executor in which to execute storing the favorites.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u0000 \u001a2\u00020\u0001:\u0001\u001aB!\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\n\b\u0002\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u00a2\u0006\u0002\u0010\bJ\u0018\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00032\b\u0010\u0010\u001a\u0004\u0018\u00010\u0007J\u0006\u0010\u0011\u001a\u00020\u000eJ\u0016\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00140\u00132\u0006\u0010\u0015\u001a\u00020\u0016H\u0002J\f\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\u00140\u0013J\u0014\u0010\u0018\u001a\u00020\u000e2\f\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u00140\u0013R\u0010\u0010\u0006\u001a\u0004\u0018\u00010\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\t\u001a\u00020\n8F\u00a2\u0006\u0006\u001a\u0004\b\u000b\u0010\f"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsFavoritePersistenceWrapper;", "", "file", "Ljava/io/File;", "executor", "Ljava/util/concurrent/Executor;", "backupManager", "Landroid/app/backup/BackupManager;", "(Ljava/io/File;Ljava/util/concurrent/Executor;Landroid/app/backup/BackupManager;)V", "fileExists", "", "getFileExists", "()Z", "changeFileAndBackupManager", "", "fileName", "newBackupManager", "deleteFile", "parseXml", "", "Lcom/android/systemui/controls/controller/StructureInfo;", "parser", "Lorg/xmlpull/v1/XmlPullParser;", "readFavorites", "storeFavorites", "structures", "Companion"})
public final class ControlsFavoritePersistenceWrapper {
    private java.io.File file;
    private final java.util.concurrent.Executor executor = null;
    private android.app.backup.BackupManager backupManager;
    private static final java.lang.String TAG = "ControlsFavoritePersistenceWrapper";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String FILE_NAME = "controls_favorites.xml";
    private static final java.lang.String TAG_CONTROLS = "controls";
    private static final java.lang.String TAG_STRUCTURES = "structures";
    private static final java.lang.String TAG_STRUCTURE = "structure";
    private static final java.lang.String TAG_CONTROL = "control";
    private static final java.lang.String TAG_COMPONENT = "component";
    private static final java.lang.String TAG_ID = "id";
    private static final java.lang.String TAG_TITLE = "title";
    private static final java.lang.String TAG_SUBTITLE = "subtitle";
    private static final java.lang.String TAG_TYPE = "type";
    private static final java.lang.String TAG_VERSION = "version";
    private static final int VERSION = 1;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.controller.ControlsFavoritePersistenceWrapper.Companion Companion = null;
    
    /**
     * Change the file location for storing/reading the favorites and the [BackupManager]
     *
     * @param fileName new location
     * @param newBackupManager new [BackupManager]. Pass null to not trigger backups.
     */
    public final void changeFileAndBackupManager(@org.jetbrains.annotations.NotNull()
    java.io.File fileName, @org.jetbrains.annotations.Nullable()
    android.app.backup.BackupManager newBackupManager) {
    }
    
    public final boolean getFileExists() {
        return false;
    }
    
    public final void deleteFile() {
    }
    
    /**
     * Stores the list of favorites in the corresponding file.
     *
     * @param list a list of favorite controls. The list will be stored in the same order.
     */
    public final void storeFavorites(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.controls.controller.StructureInfo> structures) {
    }
    
    /**
     * Stores the list of favorites in the corresponding file.
     *
     * @return a list of stored favorite controls. Return an empty list if the file is not found
     * @throws [IllegalStateException] if there is an error while reading the file
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.controls.controller.StructureInfo> readFavorites() {
        return null;
    }
    
    private final java.util.List<com.android.systemui.controls.controller.StructureInfo> parseXml(org.xmlpull.v1.XmlPullParser parser) {
        return null;
    }
    
    public ControlsFavoritePersistenceWrapper(@org.jetbrains.annotations.NotNull()
    java.io.File file, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.Nullable()
    android.app.backup.BackupManager backupManager) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\f\n\u0002\u0010\b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsFavoritePersistenceWrapper$Companion;", "", "()V", "FILE_NAME", "", "TAG", "TAG_COMPONENT", "TAG_CONTROL", "TAG_CONTROLS", "TAG_ID", "TAG_STRUCTURE", "TAG_STRUCTURES", "TAG_SUBTITLE", "TAG_TITLE", "TAG_TYPE", "TAG_VERSION", "VERSION", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}