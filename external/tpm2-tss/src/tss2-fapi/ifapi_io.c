/* SPDX-License-Identifier: BSD-2-Clause */
/*******************************************************************************
 * Copyright 2018-2019, Fraunhofer SIT sponsored by Infineon Technologies AG
 * All rights reserved.
 *******************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
/* Need for some libc-versions */
#ifndef __FreeBSD__
#include <malloc.h>
#endif

#include "tss2_common.h"
#include "ifapi_io.h"
#include "ifapi_helpers.h"
#include "ifapi_macros.h"
#define LOGMODULE fapi
#include "util/log.h"
#include "util/aux_util.h"

/** Start reading a file's complete content into memory in an asynchronous way.
 *
 * @param[in,out] io The input/output context being used for file I/O.
 * @param[in] filename The name of the file to be read into memory.
 * @retval TSS2_RC_SUCCESS: if the function call was a success.
 * @retval TSS2_FAPI_RC_IO_ERROR: if an I/O error was encountered; such as the file was not found.
 * @retval TSS2_FAPI_RC_MEMORY: if memory could not be allocated to hold the read data.
 */
TSS2_RC
ifapi_io_read_async(
    struct IFAPI_IO *io,
    const char *filename)
{
    if (io->char_rbuffer) {
        LOG_ERROR("rbuffer still in use; maybe use of old API.");
        return TSS2_FAPI_RC_IO_ERROR;
    }

    io->stream = fopen(filename, "rt");
    if (io->stream == NULL) {
        LOG_ERROR("File \"%s\" not found.", filename);
        return TSS2_FAPI_RC_IO_ERROR;
    }
    /* Locking the file. Lock will be release upon close */
    if (lockf(fileno(io->stream), F_TLOCK, 0) == -1 && errno == EAGAIN) {
        LOG_ERROR("File %s currently locked.", filename);
        fclose(io->stream);
        return TSS2_FAPI_RC_IO_ERROR;
    }

    fseek(io->stream, 0L, SEEK_END);
    long length = ftell(io->stream);
    fclose(io->stream);

    io->stream = fopen(filename, "rt");
    io->char_rbuffer = malloc (length + 1);
    if (io->char_rbuffer == NULL) {
        fclose(io->stream);
        io->stream = NULL;
        LOG_ERROR("Memory could not be allocated. %li bytes requested", length + 1);
        return TSS2_FAPI_RC_MEMORY;
    }

    int rc, flags = fcntl(fileno(io->stream), F_GETFL, 0);
    rc = fcntl(fileno(io->stream), F_SETFL, flags | O_NONBLOCK);
    if (rc < 0) {
        LOG_ERROR("fcntl failed with %d", errno);
        return TSS2_FAPI_RC_IO_ERROR;
    }

    io->buffer_length = length;
    io->buffer_idx = 0;
    io->char_rbuffer[length] = '\0';

    return TSS2_RC_SUCCESS;
}

/** Finish reading a file's complete content into memory in an asynchronous way.
 *
 * This function needs to be called repeatedly until it does not return TSS2_FAPI_RC_TRY_AGAIN.
 *
 * @param[in,out] io The input/output context being used for file I/O.
 * @param[out] buffer The data that was read from file. (callee-allocated; use free())
 * @param[out] length The length of the data that was read from file.
 * @retval TSS2_RC_SUCCESS: if the function call was a success.
 * @retval TSS2_FAPI_RC_IO_ERROR: if an I/O error was encountered; such as the file was not found.
 * @retval TSS2_FAPI_RC_TRY_AGAIN: if the asynchronous operation is not yet complete.
 *         Call this function again later.
 */
TSS2_RC
ifapi_io_read_finish(
    struct IFAPI_IO *io,
    uint8_t **buffer,
    size_t *length)
{
    io->pollevents = POLLIN;
    if (_ifapi_io_retry-- > 0)
        return TSS2_FAPI_RC_TRY_AGAIN;
    else
        _ifapi_io_retry = _IFAPI_IO_RETRIES;

    ssize_t ret = read(fileno(io->stream),
                       &io->char_rbuffer[io->buffer_idx],
                       io->buffer_length - io->buffer_idx);
    if (ret < 0 && (errno == EINTR || errno == EAGAIN))
        return TSS2_FAPI_RC_TRY_AGAIN;

    if (ret < 0) {
        LOG_ERROR("Error reading from file: %i.", errno);
        fclose(io->stream);
        io->pollevents = 0;
        SAFE_FREE(io->char_rbuffer);
        return TSS2_FAPI_RC_IO_ERROR;
    }

    io->pollevents = 0;
    io->buffer_idx += ret;
    if (io->buffer_idx < io->buffer_length)
        return TSS2_FAPI_RC_TRY_AGAIN;

    fclose(io->stream);

    if (!buffer) {
        LOG_WARNING("The old file read API is still being used");
        return TSS2_RC_SUCCESS;
    }
    *buffer = (uint8_t *)io->char_rbuffer;
    io->char_rbuffer = NULL;

    if (length)
        *length = io->buffer_length;

    return TSS2_RC_SUCCESS;
}

/** Start writing a buffer into a file in an asynchronous way.
 *
 * @param[in,out] io The input/output context being used for file I/O.
 * @param[in] filename The name of the file to be read into memory.
 * @param[in] buffer The buffer to be written.
 * @param[in] length The number of bytes to be written.
 * @retval TSS2_RC_SUCCESS: if the function call was a success.
 * @retval TSS2_FAPI_RC_IO_ERROR: if an I/O error was encountered; such as the file was not found.
 * @retval TSS2_FAPI_RC_MEMORY: if memory could not be allocated to hold the read data.
 */
TSS2_RC
ifapi_io_write_async(
    struct IFAPI_IO *io,
    const char *filename,
    const uint8_t *buffer,
    size_t length)
{
    if (io->char_rbuffer) {
        LOG_ERROR("rbuffer still in use; maybe use of old API.");
        return TSS2_FAPI_RC_IO_ERROR;
    }

    io->buffer_length = length;
    io->buffer_idx = 0;
    io->char_rbuffer = malloc(length);
    if (io->char_rbuffer == NULL) {
        LOG_ERROR("Memory could not be allocated. %zi bytes requested", length);
        return TSS2_FAPI_RC_MEMORY;
    }
    memcpy(io->char_rbuffer, buffer, length);

    io->stream = fopen(filename, "wt");
    if (io->stream == NULL) {
        SAFE_FREE(io->char_rbuffer);
        LOG_ERROR("Could not open file \"%s\" for writing.", filename);
        return TSS2_FAPI_RC_IO_ERROR;
    }
    /* Locking the file. Lock will be release upon close */
    if (lockf(fileno(io->stream), F_TLOCK, 0) == -1 && errno == EAGAIN) {
        LOG_ERROR("File %s currently locked.", filename);
        fclose(io->stream);
        return TSS2_FAPI_RC_IO_ERROR;
    }

    /* Use non blocking IO, so asynchronous write will be needed */
    int rc, flags = fcntl(fileno(io->stream), F_GETFL, 0);
    rc = fcntl(fileno(io->stream), F_SETFL, flags | O_NONBLOCK);
    if (rc < 0) {
        LOG_ERROR("fcntl failed with %d", errno);
        return TSS2_FAPI_RC_IO_ERROR;
    }
    return TSS2_RC_SUCCESS;
}

/** Finish writing a buffer into a file in an asynchronous way.
 *
 * This function needs to be called repeatedly until it does not return TSS2_FAPI_RC_TRY_AGAIN.
 *
 * @param[in,out] io The input/output context being used for file I/O.
 * @retval TSS2_RC_SUCCESS: if the function call was a success.
 * @retval TSS2_FAPI_RC_IO_ERROR: if an I/O error was encountered; such as the file was not found.
 * @retval TSS2_FAPI_RC_TRY_AGAIN: if the asynchronous operation is not yet complete.
 *         Call this function again later.
 */
TSS2_RC
ifapi_io_write_finish(
    struct IFAPI_IO *io)
{
    io->pollevents = POLLOUT;
    if (_ifapi_io_retry-- > 0)
        return TSS2_FAPI_RC_TRY_AGAIN;
    else
        _ifapi_io_retry = _IFAPI_IO_RETRIES;

    ssize_t ret = write(fileno(io->stream),
                        &io->char_rbuffer[io->buffer_idx],
                        io->buffer_length - io->buffer_idx);
    if (ret < 0 && (errno == EINTR || errno == EAGAIN))
        return TSS2_FAPI_RC_TRY_AGAIN;

    if (ret < 0) {
        LOG_ERROR("Error writing to file: %i.", errno);
        fclose(io->stream);
        io->pollevents = 0;
        SAFE_FREE(io->char_rbuffer);
        return TSS2_FAPI_RC_IO_ERROR;
    }

    io->pollevents = 0;
    io->buffer_idx += ret;
    if (io->buffer_idx < io->buffer_length)
        return TSS2_FAPI_RC_TRY_AGAIN;

    SAFE_FREE(io->char_rbuffer);
    fclose(io->stream);

    return TSS2_RC_SUCCESS;
}

/** Check whether a file is writeable.
 *
 * @param[in] file  The name of the fileto be checked.
 * @retval TSS2_RC_SUCCESS if the directories existed or were successfully created
 * @retval TSS2_FAPI_RC_IO_ERROR if an I/O error occurred
 */
TSS2_RC
ifapi_io_check_file_writeable(
    const char *file)
{
    /* Check access rights to file  */
    if (access(file, W_OK)) {
        return_error2(TSS2_FAPI_RC_IO_ERROR, "File %s is not writeable.", file);
    }
    return TSS2_RC_SUCCESS;
}

/** Check for the existence of a directory and create it if it does not yet exist.
 *
 * @param[in] dirname The name of the directory to be checked / created
 * @retval TSS2_RC_SUCCESS if the directories existed or were successfully created
 * @retval TSS2_FAPI_RC_IO_ERROR if an I/O error occurred
 * @retval TSS2_FAPI_RC_MEMORY if not enough memory can be allocated.
 * @retval TSS2_FAPI_RC_BAD_VALUE if an invalid value was passed into
 *         the function.
 */
TSS2_RC
ifapi_io_check_create_dir(
    const char *dirname)
{
    TSS2_RC r;
    struct stat fbuffer;

    /* Check existence of dirname and try to create it otherwise */
    if (stat(dirname, &fbuffer)) {
        LOG_WARNING("Directory %s does not exist, creating", dirname);

        r = ifapi_create_dirs("", dirname);
        return_if_error2(r, "Directory %s can't be created.", dirname);

        LOG_DEBUG("Created directory: %s", dirname);
    }

    /* Check access rights to dirname */
    if (access(dirname, W_OK)) {
        return_error2(TSS2_FAPI_RC_IO_ERROR, "Directory %s is not writeable.", dirname);
    }

    return TSS2_RC_SUCCESS;
}

/** Remove a file.
 *
 * @param[in] file The absolute path of the file to be removed.
 * @retval TSS2_RC_SUCCESS If the file was successfully removed
 * @retval TSS2_FAPI_RC_IO_ERROR If the file could not be removed.
 */
TSS2_RC
ifapi_io_remove_file(const char *file)
{
    if (remove(file) != 0) {
        LOG_ERROR("File: %s can't be deleted.", file);
        return TSS2_FAPI_RC_IO_ERROR;
    }
    return TSS2_RC_SUCCESS;
}

/** Remove a directory recursively; i.e. including its subdirectories.
 *
 * @param[in] dirname The directory to be removed
 * @retval TSS2_RC_SUCCESS if the directories were successfully removed
 * @retval TSS2_FAPI_RC_IO_ERROR if an I/O error occurred
 * @retval TSS2_FAPI_RC_MEMORY: if memory could not be allocated to hold the read data.
 */
TSS2_RC
ifapi_io_remove_directories(
    const char *dirname)
{
    DIR *dir;
    struct dirent *entry;
    TSS2_RC r;
    char *path;

    LOG_TRACE("Removing directory: %s", dirname);

    if (!(dir = opendir(dirname))) {
        return_error2(TSS2_FAPI_RC_IO_ERROR, "Could not open directory: %s",
                      dirname);
    }

    /* Iterating through the list of entries inside the directory. */
    while ((entry = readdir(dir)) != NULL) {
        LOG_TRACE("Deleting directory entry %s", entry->d_name);

        /* Entries . and .. are obviously ignored */
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        /* If an entry is a directory then we call ourself recursively to remove those */
        if (entry->d_type == DT_DIR) {
            r = ifapi_asprintf(&path, "%s/%s", dirname, entry->d_name);
            goto_if_error(r, "Out of memory", error_cleanup);

            r = ifapi_io_remove_directories(path);
            free(path);
            goto_if_error(r, "remove directories.", error_cleanup);

            continue;
        }

        /* If an entry is a file or symlink or anything else, we remove it */
        r = ifapi_asprintf(&path, "%s/%s", dirname, entry->d_name);
        goto_if_error(r, "Out of memory", error_cleanup);

        LOG_WARNING("Found a file in directory; removing: %s", path);

        if (remove(path) != 0) {
            free(path);
            closedir(dir);
            return_error2(TSS2_FAPI_RC_IO_ERROR, "Removing file");
        }

        free(path);
    }
    closedir(dir);
    LOG_TRACE("Removing target directory %s", dirname);

    if (rmdir(dirname) != 0)
        return_error2(TSS2_FAPI_RC_IO_ERROR, "Removing directory: %s", dirname);

    LOG_TRACE("SUCCESS");
    return TSS2_RC_SUCCESS;

error_cleanup:
    closedir(dir);
    return r;
}

/** Enumerate the list of files in a directory.
 *
 * Enumerage the regular files (no directories, symlinks etc) from a given directory.
 *
 * @param[in] dirname The directory to list files from.
 * @param[out] files The list of file names.
 * @param[out] numfiles The size of files.
 * @retval TSS2_RC_SUCCESS if the directories were successfully removed
 * @retval TSS2_FAPI_RC_IO_ERROR if an I/O error occurred
 * @retval TSS2_FAPI_RC_MEMORY: if memory could not be allocated to hold the read data.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 */
TSS2_RC
ifapi_io_dirfiles(
    const char *dirname,
    char ***files,
    size_t *numfiles)
{
    DIR *dir;
    struct dirent *entry;
    char **paths;
    size_t numpaths = 0;
    check_not_null(dirname);
    check_not_null(files);
    check_not_null(numfiles);

    LOG_TRACE("Removing directory: %s", dirname);

    paths = calloc(10, sizeof(*paths));
    check_oom(paths);

    if (!(dir = opendir(dirname))) {
        free(paths);
        return_error2(TSS2_FAPI_RC_IO_ERROR, "Could not open directory: %s",
                      dirname);
    }

    /* Iterating through the list of entries inside the directory. */
    while ((entry = readdir(dir)) != NULL) {
        LOG_TRACE("Looking at %s", entry->d_name);
        if (entry->d_type != DT_REG)
            continue;

        if (numpaths % 10 == 9) {
#ifdef HAVE_REALLOCARRAY
            paths = reallocarray(paths, numpaths + 10, sizeof(*paths));
#else /* HAVE_REALLOCARRAY */
            paths = realloc(paths, (numpaths + 10) * sizeof(*paths));
#endif /* HAVE_REALLOCARRAY */
            if (!paths)
                closedir(dir);
            check_oom(paths);
        }

        paths[numpaths] = strdup(entry->d_name);
        if (!paths[numpaths])
            goto error_oom;

        LOG_TRACE("Added %s to the list at index %zi", paths[numpaths], numpaths);
        numpaths += 1;
    }
    closedir(dir);

    *files = paths;
    *numfiles = numpaths;

    return TSS2_RC_SUCCESS;

error_oom:
    closedir(dir);
    LOG_ERROR("Out of memory");
    for (size_t i = 0; i < numpaths; i++)
        free(paths[i]);
    free(paths);
    return TSS2_FAPI_RC_MEMORY;
}

/** Get a linked list of files in a directory and all sub directories.
 *
 * Enumerage the regular files (no directories, symlinks etc) from a given directory.
 *
 * @param[in]  dir_name The directory to list files from.
 * @param[out] list  The linked list with the file names.
 * @param[out] n The number of filesl
 * @retval TSS2_RC_SUCCESS if the directories were successfully removed
 * @retval TSS2_FAPI_RC_MEMORY: if memory could not be allocated to hold the read data.
 */
static TSS2_RC
dirfiles_all(const char *dir_name, NODE_OBJECT_T **list, size_t *n)
{
    DIR *dir;
    struct dirent *entry;
    TSS2_RC r;
    char *path;
    NODE_OBJECT_T *second;

    if (!(dir = opendir(dir_name))) {
        return TSS2_RC_SUCCESS;
    }

    /* Iterating through the list of entries inside the directory. */
    while ((entry = readdir(dir)) != NULL) {
        path = NULL;
        if (entry->d_type == DT_DIR) {
            /* Recursive call for sub directories */
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            r = ifapi_asprintf(&path, "%s/%s", dir_name, entry->d_name);
            if (r)
                closedir(dir);
            return_if_error(r, "Out of memory");

            LOG_TRACE("Directory: %s", path);
            r = dirfiles_all(path, list, n);
            SAFE_FREE(path);
            if (r)
                closedir(dir);
            return_if_error(r, "get_entities");

        } else {
            r = ifapi_asprintf(&path, "%s/%s", dir_name, entry->d_name);
            if (r)
                closedir(dir);
            return_if_error(r, "Out of memory");

            NODE_OBJECT_T *file_obj = calloc(sizeof(NODE_OBJECT_T), 1);
            if (!file_obj) {
                LOG_ERROR("Out of memory.");
                SAFE_FREE(path);
                closedir(dir);
                return TSS2_FAPI_RC_MEMORY;
            }

            *n += 1;
            /* Add file name to linked list */
            file_obj->object = strdup(path);
            if (file_obj->object == NULL) {
                LOG_ERROR("Out of memory.");
                SAFE_FREE(file_obj);
                SAFE_FREE(path);
                closedir(dir);
                return TSS2_FAPI_RC_MEMORY;
            }
            if (*list != NULL) {
                second = *list;
                file_obj->next = second;
            }
            *list = file_obj;
            LOG_TRACE("File: %s", path);
            SAFE_FREE(path);
        }
    }
    closedir(dir);
    return TSS2_RC_SUCCESS;
}


/** Recursive enumerate the list of files in a directory.
 *
 * Enumerage the regular files (no directories, symlinks etc) from a given directory.
 *
 * @param[in] searchPath The directory to list files from.
 * @param[out] pathlist The list of file names.
 * @param[out] numPaths The size of files.
 * @retval TSS2_RC_SUCCESS if the directories were successfully removed
 * @retval TSS2_FAPI_RC_IO_ERROR if an I/O error occurred
 * @retval TSS2_FAPI_RC_MEMORY: if memory could not be allocated to hold the read data.
 */
TSS2_RC
ifapi_io_dirfiles_all(
    const char *searchPath,
    char ***pathlist,
    size_t *numPaths)
{
    TSS2_RC r;
    size_t n;
    NODE_OBJECT_T *head;

    *numPaths = 0;
    char **pathlist2;

    NODE_OBJECT_T *file_list = NULL;
    r = dirfiles_all(searchPath, &file_list, numPaths);
    goto_if_error(r, "get all sub files of directory", cleanup);

    if (*numPaths > 0) {
        size_t size_path_list = *numPaths * sizeof(char *);
        pathlist2 = calloc(1, size_path_list);
        goto_if_null2(pathlist2, "Out of memory.", r, TSS2_FAPI_RC_MEMORY,
                      cleanup);
        n = *numPaths;

        /* Move file names from list to array */
        while (n > 0 && file_list) {
            n -= 1;
            pathlist2[n] = file_list->object;
            head = file_list;
            file_list = file_list->next;
            SAFE_FREE(head);
        }
        *pathlist = pathlist2;
    }
cleanup:
    /* Free linked list with file names */
    while (file_list) {
        head = file_list;
        file_list = file_list->next;
        SAFE_FREE(head);
    }
    return r;
}

/** Determine whether a path exists.
 *
 * @param[in] path The absolute path of the file.
 * @retval true The file exists.
 * @retval false The file does not exist.
 */
bool
ifapi_io_path_exists(const char *path)
{
    struct stat fbuffer;

    if (stat(path, &fbuffer) == 0)
        return true;
    else
        return false;
}


/** Wait for file I/O to be ready.
 *
 * If FAPI state automata are in a file I/O state it will be waited for an
 * event on a file descriptor.
 *
 * @param[in] io The input/output context being used for file I/O.
 * @retval TSS2_RC_SUCCESS After the end of the wait.
 * @retval TSS2_FAPI_RC_IO_ERROR if the poll function returns an error.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 */
TSS2_RC
ifapi_io_poll(IFAPI_IO * io) {
    int rc;
    /* Check for NULL parameters */
    check_not_null(io);

    if (io->pollevents) {
        struct pollfd fds;
        fds.events = io->pollevents;
        fds.fd = fileno(io->stream);
        LOG_TRACE("Waiting for fd %i with event %i", fds.fd, fds.events);
        rc = poll(&fds, 1, -1);
        if (rc < 0) {
            LOG_ERROR("Poll failed with %d", errno);
            return TSS2_FAPI_RC_IO_ERROR;
        }
    }
    return TSS2_RC_SUCCESS;
}

/**  Get a list of poll handles.
 *
 * @param[in] io The input/output context being used for file I/O.
 * @param[out] handles The array with the poll handles.
 * @param[out] num_handles The number of poll handles.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_NO_HANDLE In no poll events are stored in IO context.
 * @retval TSS2_FAPI_RC_MEMORY If the output data cannot be allocated.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 */
TSS2_RC
ifapi_io_poll_handles(IFAPI_IO *io, FAPI_POLL_HANDLE **handles, size_t *num_handles) {
    /* Check for NULL parameters */
    check_not_null(io);
    check_not_null(handles);
    check_not_null(num_handles);

    if (!io->pollevents) {
        /* We're not spilling out error here, because this is called in the
           functional path of Fapi_GetPollHandles(). */
        LOG_DEBUG("No pollable operation in progress.");
        return TSS2_FAPI_RC_NO_HANDLE;
    }

    *handles = calloc(1, sizeof(**handles));
    check_oom(*handles);
    (*handles)->events = io->pollevents;
    (*handles)->fd = fileno(io->stream);
    *num_handles = 1;

    LOG_TRACE("Returning %zi poll handles for fd %i with event %i",
              *num_handles, (*handles)->fd, (*handles)->events);

    return TSS2_RC_SUCCESS;
}
