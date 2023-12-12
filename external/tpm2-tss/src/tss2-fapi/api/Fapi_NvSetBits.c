/* SPDX-License-Identifier: BSD-2-Clause */
/*******************************************************************************
 * Copyright 2018-2019, Fraunhofer SIT sponsored by Infineon Technologies AG
 * All rights reserved.
 ******************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "tss2_fapi.h"
#include "fapi_int.h"
#include "fapi_util.h"
#include "tss2_esys.h"
#define LOGMODULE fapi
#include "util/log.h"
#include "util/aux_util.h"

/** One-Call function for Fapi_NvSetBits
 *
 * Sets bits in an NV index that was created as a bit field. Any number of bits
 * from 0 to 64 may be SET.
 *
 * @param[in,out] context The FAPI_CONTEXT
 * @param[in] nvPath The path to the NV index where bits are set
 * @param[in] bitmap The map of the bits to set
 *
 * @retval TSS2_RC_SUCCESS: if the function call was a success.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE: if context or nvPath is NULL.
 * @retval TSS2_FAPI_RC_BAD_CONTEXT: if context corruption is detected.
 * @retval TSS2_FAPI_RC_BAD_PATH: if nvPath is not found.
 * @retval TSS2_FAPI_RC_NV_WRONG_TYPE: if the NV index type is not
 *         TPM2_NT_COUNTER.
 * @retval TSS2_FAPI_RC_NV_NOT_WRITEABLE: if the NV is not a writeable index.
 * @retval TSS2_FAPI_RC_POLICY_UNKNOWN: if the policy is unknown.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE: if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_IO_ERROR: if the data cannot be saved.
 * @retval TSS2_FAPI_RC_MEMORY: if the FAPI cannot allocate enough memory for
 *         internal operations or return parameters.
 * @retval TSS2_FAPI_RC_NO_TPM if FAPI was initialized in no-TPM-mode via its
 *         config file.
 * @retval TSS2_FAPI_RC_PATH_NOT_FOUND if a FAPI object path was not found
 *         during authorization.
 * @retval TSS2_FAPI_RC_KEY_NOT_FOUND if a key was not found.
 * @retval TSS2_FAPI_RC_BAD_VALUE if an invalid value was passed into
 *         the function.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_GENERAL_FAILURE if an internal error occurred.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_UNKNOWN if a required authorization callback
 *         is not set.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_FAILED if the authorization attempt fails.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
TSS2_RC
Fapi_NvSetBits(
    FAPI_CONTEXT *context,
    char   const *nvPath,
    uint64_t      bitmap)
{
    LOG_TRACE("called for context:%p", context);

    TSS2_RC r, r2;

    /* Check for NULL parameters */
    check_not_null(context);
    check_not_null(nvPath);

    /* Check whether TCTI and ESYS are initialized */
    return_if_null(context->esys, "Command can't be executed in none TPM mode.",
                   TSS2_FAPI_RC_NO_TPM);

    /* If the async state automata of FAPI shall be tested, then we must not set
       the timeouts of ESYS to blocking mode.
       During testing, the mssim tcti will ensure multiple re-invocations.
       Usually however the synchronous invocations of FAPI shall instruct ESYS
       to block until a result is available. */
#ifndef TEST_FAPI_ASYNC
    r = Esys_SetTimeout(context->esys, TSS2_TCTI_TIMEOUT_BLOCK);
    return_if_error_reset_state(r, "Set Timeout to blocking");
#endif /* TEST_FAPI_ASYNC */

    r = Fapi_NvSetBits_Async(context, nvPath, bitmap);
    return_if_error_reset_state(r, "NV_SetBits");

    do {
        /* We wait for file I/O to be ready if the FAPI state automata
           are in a file I/O state. */
        r = ifapi_io_poll(&context->io);
        return_if_error(r, "Something went wrong with IO polling");

        /* Repeatedly call the finish function, until FAPI has transitioned
           through all execution stages / states of this invocation. */
        r = Fapi_NvSetBits_Finish(context);
    } while ((r & ~TSS2_RC_LAYER_MASK) == TSS2_BASE_RC_TRY_AGAIN);

    /* Reset the ESYS timeout to non-blocking, immediate response. */
    r2 = Esys_SetTimeout(context->esys, 0);
    return_if_error(r2, "Set Timeout to non-blocking");

    return_if_error_reset_state(r, "NV_SetBits");

    LOG_TRACE("finished");
    return TSS2_RC_SUCCESS;
}

/** Asynchronous function for Fapi_NvSetBits
 *
 * Sets bits in an NV index that was created as a bit field. Any number of bits
 * from 0 to 64 may be SET.
 *
 * Call Fapi_NvSetBits_Finish to finish the execution of this command.
 *
 * @param[in,out] context The FAPI_CONTEXT
 * @param[in] nvPath The path to the NV index where bits are set
 * @param[in] bitmap The map of the bits to set
 *
 * @retval TSS2_RC_SUCCESS: if the function call was a success.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE: if context or nvPath is NULL.
 * @retval TSS2_FAPI_RC_BAD_CONTEXT: if context corruption is detected.
 * @retval TSS2_FAPI_RC_BAD_PATH: if nvPath is not found.
 * @retval TSS2_FAPI_RC_NV_WRONG_TYPE: if the NV index type is not
 *         TPM2_NT_COUNTER.
 * @retval TSS2_FAPI_RC_NV_NOT_WRITEABLE: if the NV is not a writeable index.
 * @retval TSS2_FAPI_RC_POLICY_UNKNOWN: if the policy is unknown.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE: if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_IO_ERROR: if the data cannot be saved.
 * @retval TSS2_FAPI_RC_MEMORY: if the FAPI cannot allocate enough memory for
 *         internal operations or return parameters.
 * @retval TSS2_FAPI_RC_NO_TPM if FAPI was initialized in no-TPM-mode via its
 *         config file.
 * @retval TSS2_FAPI_RC_PATH_NOT_FOUND if a FAPI object path was not found
 *         during authorization.
 * @retval TSS2_FAPI_RC_KEY_NOT_FOUND if a key was not found.
 * @retval TSS2_FAPI_RC_BAD_VALUE if an invalid value was passed into
 *         the function.
 */
TSS2_RC
Fapi_NvSetBits_Async(
    FAPI_CONTEXT *context,
    char   const *nvPath,
    uint64_t      bitmap)
{
    LOG_TRACE("called for context:%p", context);
    LOG_TRACE("nvPath: %s", nvPath);
    LOG_TRACE("bitmap: 0x%" PRIx64, bitmap);

    TSS2_RC r;

    /* Check for NULL parameters */
    check_not_null(context);
    check_not_null(nvPath);

    /* Helpful alias pointers */
    IFAPI_NV_Cmds * command = &context->nv_cmd;

    /* Reset all context-internal session state information. */
    r = ifapi_session_init(context);
    return_if_error(r, "Initialize NV_SetBits");

    /* Store the parameter in the FAPI context */
    memset(&context->nv_cmd, 0, sizeof(IFAPI_NV_Cmds));
    memset(&command->nv_object, 0, sizeof(IFAPI_OBJECT));
    strdup_check(command->nvPath, nvPath, r, error_cleanup);
    command->bitmap = bitmap;
    command->rdata = NULL;

    /* Load the NV index metadata from keystore. */
    r = ifapi_keystore_load_async(&context->keystore, &context->io, command->nvPath);
    goto_if_error2(r, "Could not open: %s", error_cleanup, command->nvPath);

    /* Initialize the context state for this operation. */
    context->state = NV_SET_BITS_READ;
    LOG_TRACE("finished");
    return TSS2_RC_SUCCESS;

error_cleanup:
    /* Cleanup duplicated input parameters that were copied before. */
    SAFE_FREE(command->nvPath);
    return r;
}

/** Asynchronous finish function for Fapi_NnSetBits
 *
 * This function should be called after a previous Fapi_NvSetBIts_Async.
 *
 * @param[in,out] context The FAPI_CONTEXT
 *
 * @retval TSS2_RC_SUCCESS: if the function call was a success.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE: if context is NULL.
 * @retval TSS2_FAPI_RC_BAD_CONTEXT: if context corruption is detected.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE: if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_IO_ERROR: if the data cannot be saved.
 * @retval TSS2_FAPI_RC_MEMORY: if the FAPI cannot allocate enough memory for
 *         internal operations or return parameters.
 * @retval TSS2_FAPI_RC_TRY_AGAIN: if the asynchronous operation is not yet
 *         complete. Call this function again later.
 * @retval TSS2_FAPI_RC_BAD_PATH if the used path in inappropriate-
 * @retval TSS2_FAPI_RC_BAD_VALUE if an invalid value was passed into
 *         the function.
 * @retval TSS2_FAPI_RC_GENERAL_FAILURE if an internal error occurred.
 * @retval TSS2_FAPI_RC_PATH_NOT_FOUND if a FAPI object path was not found
 *         during authorization.
 * @retval TSS2_FAPI_RC_KEY_NOT_FOUND if a key was not found.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_UNKNOWN if a required authorization callback
 *         is not set.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_FAILED if the authorization attempt fails.
 * @retval TSS2_FAPI_RC_POLICY_UNKNOWN if policy search for a certain policy digest
 *         was not successful.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
TSS2_RC
Fapi_NvSetBits_Finish(
    FAPI_CONTEXT *context)
{
    LOG_TRACE("called for context:%p", context);

    TSS2_RC r;
    json_object *jso = NULL;
    ESYS_TR authIndex;
    ESYS_TR auth_session;

    /* Check for NULL parameters */
    check_not_null(context);

    /* Helpful alias pointers */
    IFAPI_NV_Cmds * command = &context->nv_cmd;
    IFAPI_OBJECT *object = &command->nv_object;
    ESYS_TR nvIndex = command->esys_handle;
    IFAPI_OBJECT *authObject = &command->auth_object;

    switch (context->state) {
    statecase(context->state, NV_SET_BITS_READ)
        /* First check whether the file in object store can be updated. */
        r = ifapi_keystore_check_writeable(&context->keystore, &context->io, command->nvPath);
        goto_if_error_reset_state(r, "Check whether update object store is possible.", error_cleanup);

        r = ifapi_keystore_load_finish(&context->keystore, &context->io, object);
        return_try_again(r);
        return_if_error_reset_state(r, "read_finish failed");

        if (object->objectType != IFAPI_NV_OBJ)
            goto_error(r, TSS2_FAPI_RC_BAD_PATH, "%s is no NV object.", error_cleanup,
                       command->nvPath);

        /* Initialize the NV index object for use with ESYS. */
        r = ifapi_initialize_object(context->esys, object);
        goto_if_error_reset_state(r, "Initialize NV object", error_cleanup);

        nvIndex = command->nv_object.handle;
        command->esys_handle = object->handle;
        command->nv_obj = object->misc.nv;

        /* Determine auth object */
        if (object->misc.nv.public.nvPublic.attributes & TPMA_NV_PPREAD) {
            ifapi_init_hierarchy_object(authObject, ESYS_TR_RH_PLATFORM);
            authIndex = ESYS_TR_RH_PLATFORM;
        } else {
            if (object->misc.nv.public.nvPublic.attributes & TPMA_NV_OWNERREAD) {
                ifapi_init_hierarchy_object(authObject, ESYS_TR_RH_OWNER);
                authIndex = ESYS_TR_RH_OWNER;
            } else {
                authIndex = nvIndex;
            }
            *authObject = *object;
        }
        command->auth_index = authIndex;
        context->primary_state = PRIMARY_INIT;

        /* Prepare session for authorization */
        r = ifapi_get_sessions_async(context,
                                     IFAPI_SESSION_GENEK | IFAPI_SESSION1,
                                     0, 0);
        goto_if_error_reset_state(r, "Create sessions", error_cleanup);

        fallthrough;

    statecase(context->state, NV_SET_BITS_WAIT_FOR_SESSION)
        r = ifapi_get_sessions_finish(context, &context->profiles.default_profile,
                                      object->misc.nv.public.nvPublic.nameAlg);
        return_try_again(r);

        goto_if_error_reset_state(r, " FAPI create session", error_cleanup);

        fallthrough;

    statecase(context->state, NV_SET_BITS_AUTHORIZE)
        /* Authorize the session to be used for accessing the NV index. */
        r = ifapi_authorize_object(context, authObject, &auth_session);
        return_try_again(r);
        goto_if_error(r, "Authorize NV object.", error_cleanup);

        /* Call the SetBit TPM operation. */
        r = Esys_NV_SetBits_Async(context->esys,  command->auth_index, nvIndex,
                                  auth_session,
                                  ESYS_TR_NONE, ESYS_TR_NONE,
                                  command->bitmap);

        goto_if_error_reset_state(r, " Fapi_NvSetBits_Async", error_cleanup);

        fallthrough;

    statecase(context->state, NV_SET_BITS_AUTH_SENT)
        r = Esys_NV_SetBits_Finish(context->esys);
        return_try_again(r);
        goto_if_error_reset_state(r, "FAPI NV_SetBits_Finish", error_cleanup);

        /* Serialize the ESYS object for updating the metadata in the keystore. */
        r = ifapi_esys_serialize_object(context->esys, object);
        goto_if_error(r, "Prepare serialization", error_cleanup);

        /* Start writing the NV object to the key store */
        r = ifapi_keystore_store_async(&context->keystore, &context->io,
                                       command->nvPath,
                                       object);
        goto_if_error_reset_state(r, "Could not open: %sh", error_cleanup,
                                  command->nvPath);
        fallthrough;

    statecase(context->state, NV_SET_BITS_WRITE)
        /* Finish writing the NV object to the key store */
        r = ifapi_keystore_store_finish(&context->keystore, &context->io);
        return_try_again(r);
        return_if_error_reset_state(r, "write_finish failed");

        fallthrough;

    statecase(context->state, NV_SET_BITS_CLEANUP)
        /* Cleanup the session used for authorization. */
        r = ifapi_cleanup_session(context);
        try_again_or_error_goto(r, "Cleanup", error_cleanup);

        context->state = _FAPI_STATE_INIT;
        LOG_DEBUG("success");

        break;

    statecasedefault(context->state);
    }

error_cleanup:
    /* Cleanup any intermediate results and state stored in the context. */
    SAFE_FREE(command->nvPath);
    SAFE_FREE(jso);
    ifapi_session_clean(context);
    ifapi_cleanup_ifapi_object(object);
    ifapi_cleanup_ifapi_object(&context->loadKey.auth_object);
    ifapi_cleanup_ifapi_object(context->loadKey.key_object);
    ifapi_cleanup_ifapi_object(&context->createPrimary.pkey_object);
    LOG_TRACE("finished");
    return r;
}
