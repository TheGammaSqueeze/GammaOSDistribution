/* SPDX-License-Identifier: BSD-2-Clause */
/*******************************************************************************
 * Copyright 2018-2019, Fraunhofer SIT sponsored by Infineon Technologies AG
 * All rights reserved.
 *******************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <string.h>
#include <stdlib.h>

#include "tss2_mu.h"
#include "fapi_util.h"
#include "fapi_crypto.h"
//#include "fapi_policy.h"
#include "ifapi_policy_execute.h"
#include "ifapi_helpers.h"
#include "ifapi_json_deserialize.h"
#include "tpm_json_deserialize.h"
#include "ifapi_policy_callbacks.h"
#define LOGMODULE fapi
#include "util/log.h"
#include "util/aux_util.h"

/** Copy the policy digests from a branch list to a digest list.
 *
 * @param[in] branches The list of policy branches.
 * @param[in] current_hash_alg The hash algorithm used for computation.
 * @param[out] digest_list The list of policies computed for every branch.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_BAD_VALUE If no appropriate digest was found in
 *         the branch list.
 */
static TSS2_RC
compute_or_digest_list(
    TPML_POLICYBRANCHES *branches,
    TPMI_ALG_HASH current_hash_alg,
    TPML_DIGEST *digest_list)
{
    size_t i;
    size_t digest_idx, hash_size;
    bool digest_found = false;

    if (!(hash_size = ifapi_hash_get_digest_size(current_hash_alg))) {
        return_error2(TSS2_FAPI_RC_BAD_VALUE,
                      "Unsupported hash algorithm (%" PRIu16 ")",
                              current_hash_alg);
    }
    /* Determine digest values with appropriate hash alg */
    TPML_DIGEST_VALUES *branch_digests = &branches->authorizations[0].policyDigests;
    for (i = 0; i < branch_digests->count; i++) {
        if (branch_digests->digests[i].hashAlg == current_hash_alg) {
            digest_idx = i;
            digest_found = true;
            break;
        }
    }
    if (!digest_found) {
         return_error(TSS2_FAPI_RC_BAD_VALUE, "No digest found for hash alg");
    }

    digest_list->count = branches->count;
    for (i = 0; i < branches->count; i++) {
        if (i > 7) {
            return_error(TSS2_FAPI_RC_BAD_VALUE, "Too much or branches.");
        }
        digest_list->digests[i].size = hash_size;
        memcpy(&digest_list->digests[i].buffer[0],
               &branches->authorizations[i].policyDigests.
               digests[digest_idx].digest, hash_size);
        LOGBLOB_DEBUG(&digest_list->digests[i].buffer[0],
                      digest_list->digests[i].size, "Compute digest list");
    }
    return TSS2_RC_SUCCESS;
}

/** Add a new authorization to a policy.
 *
 * The the signed hash computed from the policy digest and the policyRef together with
 * the public key of the key used for signing will be stored in the policy.
 *
 * @param[in,out] policy The policy to be authorized.
 * @param[in] authorization The structure with the signature, the policyRef and
 *                          the public key.
 *
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_MEMORY If the memory for the authorization list cannot be
 *         allocated.
 */
TSS2_RC
ifapi_extend_authorization(
    TPMS_POLICY *policy,
    TPMS_POLICYAUTHORIZATION *authorization)
{
    TPML_POLICYAUTHORIZATIONS *save = NULL;
    size_t n = 0;
    size_t i;

    if (policy->policyAuthorizations) {
        /* Extend old authorizations */
        n = policy->policyAuthorizations->count;
        save = policy->policyAuthorizations;
        policy->policyAuthorizations =
            malloc((n + 1) * sizeof(TPMS_POLICYAUTHORIZATION)
                   + sizeof(TPML_POLICYAUTHORIZATIONS));
        return_if_null(policy->policyAuthorizations->authorizations,
                       "Out of memory.", TSS2_FAPI_RC_MEMORY);

        for (i = 0; i < n; i++)
            policy->policyAuthorizations->authorizations[i] =
                save->authorizations[i];
        policy->policyAuthorizations->authorizations[n] = *authorization;
        policy->policyAuthorizations->count = n + 1;
        SAFE_FREE(save);
    } else {
        /* No old authorizations exits */
        policy->policyAuthorizations = malloc(sizeof(TPMS_POLICYAUTHORIZATION)
                                               + sizeof(TPML_POLICYAUTHORIZATIONS));
        return_if_null(policy->policyAuthorizations->authorizations,
                       "Out of memory.", TSS2_FAPI_RC_MEMORY);

        policy->policyAuthorizations->count = 1;
        policy->policyAuthorizations->authorizations[0] = *authorization;
    }
    return TSS2_RC_SUCCESS;
}
/** Compute the index for the current digest list and clear the digest.
 *
 * The list entry with the appropriate hash algorithm will be searched.
 * The found digest will be set to zero.
 *
 * @param[in,out] digest_values The list of policy digests and corresponding
 *                hash algorithms.
 * @param[in] hashAlg The hash algorithm to be searched.
 * @param[out] idx The index of the found digest.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_BAD_VALUE If no appropriate digest was found in
 *         the digest list.
 */
TSS2_RC
get_policy_digest_idx(TPML_DIGEST_VALUES *digest_values, TPMI_ALG_HASH hashAlg,
                      size_t *idx)
{
    size_t i;
    for (i = 0; i < digest_values->count; i++) {
        /* Check whether current hashAlg is appropriate. */
        if (digest_values->digests[i].hashAlg == hashAlg) {
            *idx = i;
            return TSS2_RC_SUCCESS;
        }
    }

    if (i >= TPM2_NUM_PCR_BANKS) {
        return_error(TSS2_FAPI_RC_BAD_VALUE, "Table overflow");
    }
    digest_values->digests[i].hashAlg = hashAlg;
    memset(&digest_values->digests[i].digest, 0, sizeof(TPMU_HA));
    *idx = i;
    digest_values->count += 1;
    return TSS2_RC_SUCCESS;
}

/** Execute policy PCR.
 *
 * This command is used to cause conditional gating of a policy based on PCR.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The PCR policy which will be executed. The policy
 *                digest will be added to the policy.
 * @param[in]     current_hash_alg The hash algorithm wich will be used for
 *                policy computation.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_pcr(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYPCR *policy,
    TPMI_ALG_HASH current_hash_alg,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;
    TPML_PCR_SELECTION pcr_selection;
    TPM2B_DIGEST pcr_digest;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Compute PCR selection and pcr digest */
        r = ifapi_compute_policy_digest(policy->pcrs, &pcr_selection,
                                        current_hash_alg, &pcr_digest);
        return_if_error(r, "Compute policy digest and selection.");

        LOGBLOB_DEBUG(&pcr_digest.buffer[0], pcr_digest.size, "PCR Digest");

        /* Prepare the policy execution. */
        r = Esys_PolicyPCR_Async(esys_ctx,
                                 current_policy->session,
                                 ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                 &pcr_digest, &pcr_selection);
        return_if_error(r, "Execute PolicyPCR.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyPCR_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyPCR_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
    return r;
}

/** Execute policy duplicate.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The duplicate policy which will be executed. The policy
 *                digest will be added to the policy.
 * @param[in]     current_hash_alg The hash algorithm wich will be used for
 *                policy computation.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_duplicate(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYDUPLICATIONSELECT *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        ifapi_policyeval_EXEC_CB *cb = &current_policy->callbacks;
        r = cb->cbdup(&policy->objectName, cb->cbdup_userdata);
        return_if_error(r, "Get name for policy duplicate select.");

        /* Prepare the policy execution. */
        r = Esys_PolicyDuplicationSelect_Async(esys_ctx,
                                               current_policy->session,
                                               ESYS_TR_NONE, ESYS_TR_NONE,
                                               ESYS_TR_NONE,
                                               &policy->objectName,
                                               &policy->newParentName,
                                               policy->includeObject);
        return_if_error(r, "Execute PolicyDuplicatonSelect_Async.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyDuplicationSelect_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyDuplicationselect_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
    return r;
}

/** Execute policy NV.
 *
 * A policy based on the contents of an NV Index will be executed. The
 * NV authorization is done by a callback. For an example callback
 * implementation see ifapi_policyeval_cbauth()
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The NV policy which will be executed. The policy
 *                digest will be added to the policy.
 * @param[in]     current_hash_alg The hash algorithm wich will be used for
 *                policy computation.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_nv(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYNV *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        r = ifapi_nv_get_name(&policy->nvPublic, &current_policy->name);
        return_if_error(r, "Compute NV name");
        fallthrough;

    statecase(current_policy->state, POLICY_AUTH_CALLBACK)
        ifapi_policyeval_EXEC_CB *cb = &current_policy->callbacks;

        /* Authorize NV object. */
        r = cb->cbauth(&current_policy->name,
                       &current_policy->object_handle,
                       &current_policy->auth_handle,
                       &current_policy->auth_session, cb->cbauth_userdata);
        return_try_again(r);
        return_if_error(r, "Execute authorized policy.");

        /* Prepare the policy execution. */
        r = Esys_PolicyNV_Async(esys_ctx,
                                current_policy->object_handle,
                                current_policy->auth_handle,
                                current_policy->session,
                                current_policy->auth_session, ESYS_TR_NONE, ESYS_TR_NONE,
                                &policy->operandB, policy->offset,
                                policy->operation);
        return_if_error(r, "Execute PolicyNV_Async.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyNV_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyNV_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
    return r;
}

/** Execute policy for signature based authorization.
 *
 * A signed authorization is included in this policy. The authorization hash
 * of the policy data will be signed via a callback. For an example callback
 * implementation see ifapi_sign_buffer()
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy to be signed which will be executed. The policy
 *                digest will be added to the policy.
 * @param[in]     current_hash_alg The hash algorithm wich will be used for
 *                policy computation.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_MEMORY if not enough memory can be allocated.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_UNKNOWN if a required authorization callback
 *         is not set.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_signed(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYSIGNED *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;
    size_t offset = 0;
    //TPMT_SIGNATURE signature_tpm;
    size_t signature_size;
    uint8_t *signature_ossl = NULL;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT);
        current_policy->pem_key = NULL;
        current_policy->object_handle = ESYS_TR_NONE;
        current_policy->buffer_size = sizeof(INT32) + sizeof(TPM2B_NONCE)
            + policy->cpHashA.size + policy->policyRef.size;
        current_policy->buffer = malloc(current_policy->buffer_size);
        return_if_null(current_policy->buffer, "Out of memory.", TSS2_FAPI_RC_MEMORY);

        r = Esys_TRSess_GetNonceTPM(esys_ctx, current_policy->session,
                                    &current_policy->nonceTPM);
        return_if_error(r, "Get TPM nonce.");

        /* Concatenate objects needed for the authorization hash */
        memcpy(&current_policy->buffer[offset], &current_policy->nonceTPM->buffer[0],
               current_policy->nonceTPM->size);
        offset += current_policy->nonceTPM->size;
        memset(&current_policy->buffer[offset], 0, sizeof(INT32));
        offset += sizeof(INT32);
        memcpy(&current_policy->buffer[offset], &policy->cpHashA.buffer[0],
               policy->cpHashA.size);
        offset += policy->cpHashA.size;
        memcpy(&current_policy->buffer[offset], &policy->policyRef.buffer[0],
               policy->policyRef.size);
        offset += policy->policyRef.size;
        current_policy->buffer_size = offset;
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_CALLBACK);
        ifapi_policyeval_EXEC_CB *cb = &current_policy->callbacks;
        int pem_key_size;
        TPM2B_PUBLIC tpm_public;

        /* Recreate pem key from tpm public key */
        if (!current_policy->pem_key) {
            tpm_public.publicArea = policy->keyPublic;
            tpm_public.size = 0;
            r = ifapi_pub_pem_key_from_tpm(&tpm_public, &current_policy->pem_key,
                                       &pem_key_size);
            return_if_error(r, "Convert TPM public key into PEM key.");
        }

        /* Callback for signing the autorization hash. */
        r = cb->cbsign(current_policy->pem_key, policy->publicKeyHint,
                       policy->keyPEMhashAlg, current_policy->buffer,
                       current_policy->buffer_size,
                       &signature_ossl, &signature_size,
                       cb->cbsign_userdata);
        SAFE_FREE(current_policy->pem_key);
        SAFE_FREE(current_policy->buffer);
        try_again_or_error_goto(r, "Execute policy signature callback.", cleanup);

        /* Convert signature into TPM format */
        r = ifapi_der_sig_to_tpm(&policy->keyPublic, signature_ossl,
                                 signature_size, policy->keyPEMhashAlg,
                                 &policy->signature_tpm);
        goto_if_error2(r, "Convert der signature into TPM format", cleanup);

        SAFE_FREE(signature_ossl);

        TPM2B_PUBLIC inPublic;
        inPublic.size = 0;
        inPublic.publicArea = policy->keyPublic;

        /* Prepare the loading of the external public key, user for verificaton. */
        r = Esys_LoadExternal_Async(esys_ctx,
                                    ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                    NULL, &inPublic, TPM2_RH_OWNER);
        goto_if_error(r, "LoadExternal_Async", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_LOAD_KEY);
        r = Esys_LoadExternal_Finish(esys_ctx, &current_policy->object_handle);
        try_again_or_error(r, "Load external key.");

        /* Prepare the policy execution. */
        r = Esys_PolicySigned_Async(esys_ctx,
                                    current_policy->object_handle,
                                    current_policy->session,
                                    ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                    current_policy->nonceTPM,
                                    &policy->cpHashA,
                                    &policy->policyRef, 0, &policy->signature_tpm);
        SAFE_FREE(current_policy->nonceTPM);
        goto_if_error(r, "Execute PolicySigned.", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH);
        /* Finalize the policy execution if possible. */
        r = Esys_PolicySigned_Finish(esys_ctx, NULL, NULL);
        try_again_or_error(r, "Execute PolicySigned_Finish.");

        r = Esys_FlushContext_Async(esys_ctx, current_policy->object_handle);
        goto_if_error(r, "FlushContext_Async", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_FLUSH_KEY);
        r = Esys_FlushContext_Finish(esys_ctx);
        try_again_or_error(r, "Flush key finish.");

        current_policy->object_handle = ESYS_TR_NONE;
        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
cleanup:
    SAFE_FREE(current_policy->pem_key);
    SAFE_FREE(signature_ossl);
    SAFE_FREE(current_policy->buffer);
    SAFE_FREE(current_policy->pem_key);
    /* In error cases object might not have been flushed. */
    if (current_policy->object_handle != ESYS_TR_NONE)
        Esys_FlushContext(esys_ctx, current_policy->object_handle);
    return r;
}

/** Execute a policy that was signed by a certain key.
 *
 * All policies authorized by the key stored in the policy will be
 * retrieved and one policy will be selected via a branch selection callback
 * (see Fapi_SetBranchCB()) if more then one policy was found.
 * The selected policy will be executed via a callback. For an example callback
 * implementation see ifapi_exec_auth_policy().
 *
 * For an example callback implementation to executie of an authorized policy
 * ifapi_exec_auth_policy()
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy which defines the signing key and several
 *                additional parameters (nonce, policyRef ...). The policy
 *                digest will be added to the policy.
 * @param[in]     current_hash_alg The hash algorithm wich will be used for
 *                policy computation.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_BAD_VALUE if an invalid value was passed into
 *         the function.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_GENERAL_FAILURE if an internal error occured.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 * @retval TSS2_FAPI_RC_POLICY_UNKNOWN if policy search for a certain policy digest
 *         was not successful.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_UNKNOWN if a required authorization callback
 *         is not set.
 * @retval TSS2_FAPI_RC_MEMORY if not enough memory can be allocated.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_authorize(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYAUTHORIZE *policy,
    TPMI_ALG_HASH hash_alg,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;
    TPM2B_PUBLIC public2b;
    TPM2B_DIGEST aHash;
    IFAPI_CRYPTO_CONTEXT_BLOB *cryptoContext;
    size_t hash_size;
    size_t size;
    TPMT_TK_VERIFIED *ticket;
    TPM2B_NAME *tmp_name = NULL;

    LOG_TRACE("call");
    public2b.size = 0;
    if (!(hash_size = ifapi_hash_get_digest_size(hash_alg))) {
        goto_error(r, TSS2_FAPI_RC_BAD_VALUE,
                   "Unsupported hash algorithm (%" PRIu16 ")", cleanup,
                   hash_alg);
    }
    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT);
        current_policy->object_handle = ESYS_TR_NONE;
        /* Execute authorized policy. */
        ifapi_policyeval_EXEC_CB *cb = &current_policy->callbacks;
        r = cb->cbauthpol(&policy->keyPublic, hash_alg, &policy->approvedPolicy,
                          &policy->signature, cb->cbauthpol_userdata);
        return_try_again(r);
        goto_if_error(r, "Execute authorized policy.", cleanup);

        public2b.size = 0;
        public2b.publicArea = policy->keyPublic;
        r = Esys_LoadExternal_Async(esys_ctx,
                                    ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                    NULL,  &public2b, TPM2_RH_OWNER);
        goto_if_error(r, "LoadExternal_Async", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_LOAD_KEY);
        r = Esys_LoadExternal_Finish(esys_ctx, &current_policy->object_handle);
        try_again_or_error(r, "Load external key.");

        /* Save key name for policy execution */
        r = Esys_TR_GetName(esys_ctx, current_policy->object_handle, &tmp_name);
        return_if_error(r, "Get key name.");
        policy->keyName = *tmp_name;
        SAFE_FREE(tmp_name);

        /* Use policyRef and policy to compute authorization hash */
        r = ifapi_crypto_hash_start(&cryptoContext, hash_alg);
        return_if_error(r, "crypto hash start");

        HASH_UPDATE_BUFFER(cryptoContext, &policy->approvedPolicy.buffer[0],
                           hash_size, r, cleanup);
        HASH_UPDATE_BUFFER(cryptoContext, &policy->policyRef.buffer[0],
                           policy->policyRef.size, r, cleanup);
        r = ifapi_crypto_hash_finish(&cryptoContext,
                                     (uint8_t *) &aHash.buffer[0],
                                     &size);
        return_if_error(r, "crypto hash finish");

        aHash.size = size;
        LOGBLOB_TRACE(&policy->policyRef.buffer[0], policy->policyRef.size, "policyRef");
        LOGBLOB_TRACE(&aHash.buffer[0], aHash.size, "aHash");

        /* Verify the signature retrieved from the authorized policy against
           the computed ahash. */
        r = Esys_VerifySignature_Async(esys_ctx, current_policy->object_handle,
                                       ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                       &aHash,
                                       &policy->signature);
        goto_if_error(r, "Verify signature", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_VERIFY);
        r = Esys_VerifySignature_Finish(esys_ctx, &ticket);
        try_again_or_error(r, "Load external key.");

        /* Execute policy authorize */
        policy->checkTicket = *ticket;
        SAFE_FREE(ticket);
        r = Esys_PolicyAuthorize_Async(esys_ctx,
                                       current_policy->session,
                                       ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                       &policy->approvedPolicy,
                                       &policy->policyRef,
                                       &policy->keyName,
                                       &policy->checkTicket);
        goto_if_error(r, "Policy Authorize", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH);
        r = Esys_PolicyAuthorize_Finish(esys_ctx);
        try_again_or_error(r, "Load external key.");

        r = Esys_FlushContext_Async(esys_ctx, current_policy->object_handle);
        goto_if_error(r, "FlushContext_Async", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_FLUSH_KEY);
        /* Flush key used for verification. */
        r = Esys_FlushContext_Finish(esys_ctx);
        try_again_or_error(r, "Flush key finish.");

        current_policy->object_handle = ESYS_TR_NONE;
        current_policy->state = POLICY_EXECUTE_INIT;
        break;

    statecasedefault(current_policy->state);
    }
cleanup:
    /* In error cases object might not have been flushed. */
    if (current_policy->object_handle != ESYS_TR_NONE)
        Esys_FlushContext(esys_ctx, current_policy->object_handle);

    return r;
}

/** Execute a policy whose digest is stored in the NV ram.
 *
 * The policy will be retrieved from policy store based on the policy digest
 * stored in NV ram.
 * The authorization for the NV object, the policy retrieval, and the execution
 * is done via a callback. For an example callback implementation see
 * ifapi_exec_auth_nv_policy().
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy which defines the policy to be authorized
 *                and the used NV object.
 *                The policy digest will be added to the policy.
 * @param[in]     current_hash_alg The hash algorithm wich will be used for
 *                policy computation.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 * @retval TSS2_FAPI_RC_BAD_VALUE if an invalid value was passed into
 *         the function.
 * @retval TSS2_FAPI_RC_POLICY_UNKNOWN if policy search for a certain policy digest
 *         was not successful.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_authorize_nv(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYAUTHORIZENV *policy,
    TPMI_ALG_HASH hash_alg,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;
    ifapi_policyeval_EXEC_CB *cb;

    LOG_DEBUG("call");
    cb = &current_policy->callbacks;

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Execute the policy stored in the NV object. */
        r = cb->cbauthnv(&policy->nvPublic, hash_alg, cb->cbauthpol_userdata);
        try_again_or_error(r, "Execute policy authorize nv callback.");

        r = ifapi_nv_get_name(&policy->nvPublic, &current_policy->name);
        return_if_error(r, "Compute NV name");
        fallthrough;

    statecase(current_policy->state, POLICY_AUTH_CALLBACK)
        /* Authorize the NV object for policy execution. */
        r = cb->cbauth(&current_policy->name,
                       &current_policy->object_handle,
                       &current_policy->auth_handle,
                       &current_policy->auth_session, cb->cbauth_userdata);
        return_try_again(r);
        goto_if_error(r, "Execute authorized policy.", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_EXEC_ESYS)
        LOG_DEBUG("**STATE** POLICY_EXEC_ESYS");
        /* Prepare the policy execution. */
        r = Esys_PolicyAuthorizeNV_Async(esys_ctx,
                                         current_policy->auth_handle,
                                         current_policy->object_handle,
                                         current_policy->session,
                                         current_policy->auth_session, ESYS_TR_NONE,
                                         ESYS_TR_NONE);
        goto_if_error(r, "PolicyAuthorizeNV_Async", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_AUTH_SENT)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyAuthorizeNV_Finish(esys_ctx);
        return_try_again(r);
        goto_if_error(r, "FAPI PolicyAuthorizeNV_Finish", cleanup);
        break;

    statecasedefault(current_policy->state);
    }
cleanup:
    return r;
}

/** Execute  a policy based on a secret-based authorization.
 *
 * The policy defines an object whose secret is needed for policy execution.
 * The authorization of the object is done via a callback.
 * For an example callback implementation see ifapi_policyeval_cbauth;().
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy which defines the object whose secret
 *                is needed for policy execution.
 *                The policy digest will be added to the policy.
 * @param[in]     current_hash_alg The hash algorithm wich will be used for
 *                policy computation.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_secret(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYSECRET *policy,
    TPMI_ALG_HASH hash_alg,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;
    (void)hash_alg;

    LOG_DEBUG("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        ifapi_policyeval_EXEC_CB *cb = &current_policy->callbacks;
        /* Callback for the object authorization. */
        r = cb->cbauth(&policy->objectName,
                       &current_policy->object_handle,
                       &current_policy->auth_handle,
                   &current_policy->auth_session, cb->cbauth_userdata);
        return_try_again(r);
        goto_if_error(r, "Authorize object callback.", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_EXEC_ESYS)
        r = Esys_TRSess_GetNonceTPM(esys_ctx, current_policy->session,
                                    &current_policy->nonceTPM);
        goto_if_error(r, "Get TPM nonce.", cleanup);

        policy->nonceTPM = *(current_policy->nonceTPM);
        SAFE_FREE(current_policy->nonceTPM);

        /* Prepare the policy execution. */
        r = Esys_PolicySecret_Async(esys_ctx,
                                    current_policy->auth_handle,
                                    current_policy->session,
                                    current_policy->auth_session, ESYS_TR_NONE,
                                    ESYS_TR_NONE, &policy->nonceTPM,
                                    &policy->cpHashA, &policy->policyRef,
                                    0);
        goto_if_error(r, "PolicySecret_Async", cleanup);
        fallthrough;

    statecase(current_policy->state, POLICY_AUTH_SENT)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicySecret_Finish(esys_ctx, NULL,
                                     NULL);
        return_try_again(r);
        goto_if_error(r, "FAPI PolicyAuthorizeNV_Finish", cleanup);
        break;

    statecasedefault(current_policy->state);
    }

cleanup:
    return r;
}

/** Execute a policy depending on the TPM timers.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy which defines the values for the comparision
 *                with the TPM timers and the comparision operation.
 *                The policy digest will be added to the policy.
 * @param[in]     current_hash_alg The hash algorithm wich will be used for
 *                policy computation.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_counter_timer(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYCOUNTERTIMER *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Prepare the policy execution. */
        r = Esys_PolicyCounterTimer_Async(esys_ctx,
                                          current_policy->session,
                                          ESYS_TR_NONE, ESYS_TR_NONE,
                                          ESYS_TR_NONE,
                                          &policy->operandB,
                                          policy->offset,
                                          policy->operation);
        return_if_error(r, "Execute PolicyCounter.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyCounterTimer_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyCounterTImer_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
    return r;
}

/** Execute a policy depending on physical presence.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy indicating that physical presence is needed.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_physical_presence(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYPHYSICALPRESENCE *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;
    (void)policy;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Prepare the policy execution. */
        r = Esys_PolicyPhysicalPresence_Async(esys_ctx,
                                              current_policy->session,
                                              ESYS_TR_NONE, ESYS_TR_NONE,
                                              ESYS_TR_NONE);
        return_if_error(r, "Execute PolicyPhysicalpresence.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyPhysicalPresence_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyPhysicalPresence_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
    return r;
}

/** Execute a policy for binding a authorization value of the authorized entity.
 *
 * The authValue will be included in hmacKey of the session.

 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy indicating that a auth value is needed.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_auth_value(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYAUTHVALUE *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;
    (void)policy;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Prepare the policy execution. */
        r = Esys_PolicyAuthValue_Async(esys_ctx,
                                       current_policy->session,
                                       ESYS_TR_NONE, ESYS_TR_NONE,
                                       ESYS_TR_NONE);
        return_if_error(r, "Execute PolicyAuthValue.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyAuthValue_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyAuthValue_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
    return r;
}

/** Execute a policy for binding a authorization value of the authorized object.
 *
 * The authValue of the authorized object will be checked when the session is used
 * for authorization..
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy indicating that a auth value is needed.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_password(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYPASSWORD *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;
    (void)policy;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Prepare the policy execution. */
        r = Esys_PolicyPassword_Async(esys_ctx,
                                      current_policy->session,
                                      ESYS_TR_NONE, ESYS_TR_NONE,
                                      ESYS_TR_NONE);
        return_if_error(r, "Execute PolicyPassword.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyPassword_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyPassword_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
    return r;
}

/** Execute a policy to limit an authorization to a specific command code.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy with the command code used fo limitting.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_command_code(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYCOMMANDCODE *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Prepare the policy execution. */
        r = Esys_PolicyCommandCode_Async(esys_ctx,
                                         current_policy->session,
                                         ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                         policy->code);
        return_if_error(r, "Execute PolicyCommandCode.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyCommandCode_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyCommandCode_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state)
    }
    return r;
}

/** Execute a policy for binding the policy to a specific set of TPM entities.
 *
 * Up to three entity names can be defined in the policy.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy with the entity names.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_name_hash(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYNAMEHASH *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Prepare the policy execution. */
        r = Esys_PolicyNameHash_Async(esys_ctx,
                                      current_policy->session,
                                      ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                      &policy->nameHash);
        return_if_error(r, "Execute PolicyNameH.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyNameHash_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyNameHash_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state)
    }
    return r;
}

/** Execute a policy for binding the policy to command parameters.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy with the cp hash.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_cp_hash(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYCPHASH *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Prepare the policy execution. */
        r = Esys_PolicyCpHash_Async(esys_ctx,
                                    current_policy->session,
                                    ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                    &policy->cpHash);
        return_if_error(r, "Execute PolicyNameH.");

        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyCpHash_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyCpHash_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
    return r;
}

/** Execute a policy for binding the policy to a certain locality.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy with the locality.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_locality(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYLOCALITY *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Prepare the policy execution. */
        r = Esys_PolicyLocality_Async(esys_ctx,
                                      current_policy->session,
                                      ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                      policy->locality);
        return_if_error(r, "Execute PolicyLocality.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyLocality_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyNV_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
    return r;
}

/** Execute a policy for binding the policy to the NV written state.
 *
 * The state NV written yes or NV written no can be defined in the policy.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy with the NV written switch YES or NO.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_nv_written(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYNVWRITTEN *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Prepare the policy execution. */
        r = Esys_PolicyNvWritten_Async(esys_ctx,
                                       current_policy->session,
                                       ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                       policy->writtenSet);
        return_if_error(r, "Execute PolicyNvWritten.");
        fallthrough;

    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyNvWritten_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyNV_Finish.");

        current_policy->state = POLICY_EXECUTE_INIT;
        return r;

    statecasedefault(current_policy->state);
    }
    return r;
}

/** Execute a policy for binding the policy to the NV written state.
 *
 * The state NV written yes or NV written no can be defined in the policy.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy with the NV written switch YES or NO.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
static TSS2_RC
execute_policy_or(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYOR *policy,
    TPMI_ALG_HASH current_hash_alg,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;

    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT)
        /* Prepare the policy execution. */
        r = compute_or_digest_list(policy->branches, current_hash_alg,
                                      &current_policy->digest_list);
        return_if_error(r, "Compute policy or digest list.");

        r = Esys_PolicyOR_Async(esys_ctx,
                                current_policy->session,
                                ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                                &current_policy->digest_list);
        return_if_error(r, "Execute PolicyPCR.");
        fallthrough;
    statecase(current_policy->state, POLICY_EXECUTE_FINISH)
        /* Finalize the policy execution if possible. */
        r = Esys_PolicyOR_Finish(esys_ctx);
        try_again_or_error(r, "Execute PolicyPCR_Finish.");

        return r;

    statecasedefault(current_policy->state);
    }
}

/** Execute a policy for executing a callback during policy execution.
 *
 * The action name stored in the policy name will be passed do the callback
 * function. The policy action callback has to be set with the function:
 * Fapi_SetPolicyActionCB().
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy with action name.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_UNKNOWN if a required authorization callback
 *         is not set.
 */
static TSS2_RC
execute_policy_action(
    ESYS_CONTEXT *esys_ctx,
    TPMS_POLICYACTION *policy,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;
    (void)(esys_ctx);
    LOG_TRACE("call");

    switch (current_policy->state) {
    statecase(current_policy->state, POLICY_EXECUTE_INIT);
        ifapi_policyeval_EXEC_CB *cb = &current_policy->callbacks;

        /* Execute the callback and try it again if the callback is not finished. */
        r = cb->cbaction(policy->action, cb->cbaction_userdata);
        try_again_or_error(r, "Execute policy action callback.");
        return r;

    statecasedefault(current_policy->state);
    }
}

/** Execute a policy element depending on the type.
 *
 * @param[in,out] *esys_ctx The ESAPI context which is needed to execute the
 *                policy command.
 * @param[in,out] policy The policy element with the policy to be executed and
 *                the type of the policy.
 * @param[in,out] current_policy The policy context which stores the state
 *                of the policy execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_GENERAL_FAILURE if an internal error occured.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 */
static TSS2_RC
execute_policy_element(
    ESYS_CONTEXT *esys_ctx,
    TPMT_POLICYELEMENT *policy,
    TPMI_ALG_HASH hash_alg,
    IFAPI_POLICY_EXEC_CTX *current_policy)
{
    TSS2_RC r = TSS2_RC_SUCCESS;

    LOG_TRACE("call");

    switch (policy->type) {
    case POLICYSECRET:
        r = execute_policy_secret(esys_ctx,
                                  &policy->element.PolicySecret,
                                  hash_alg,
                                  current_policy);
        try_again_or_error_goto(r, "Execute policy authorize", error);
        break;
    case POLICYPCR:
        r = execute_policy_pcr(esys_ctx,
                               &policy->element.PolicyPCR,
                               hash_alg, current_policy);
        try_again_or_error_goto(r, "Execute policy pcr", error);
        break;
    case POLICYAUTHVALUE:
        r = execute_policy_auth_value(esys_ctx,
                                      &policy->element.PolicyAuthValue,
                                      current_policy);
        try_again_or_error_goto(r, "Execute policy auth value", error);
        break;
    case POLICYOR:
        r = execute_policy_or(esys_ctx,
                              &policy->element.PolicyOr,
                              hash_alg, current_policy);
        try_again_or_error_goto(r, "Execute policy or", error);
        break;
    case POLICYSIGNED:
        r = execute_policy_signed(esys_ctx,
                                  &policy->element.PolicySigned,
                                  current_policy);
        try_again_or_error_goto(r, "Execute policy signed", error);
        break;
    case POLICYAUTHORIZE:
        r = execute_policy_authorize(esys_ctx,
                                     &policy->element.PolicyAuthorize,
                                     hash_alg,
                                     current_policy);
        try_again_or_error_goto(r, "Execute policy authorize", error);
        break;
    case POLICYAUTHORIZENV:
        r = execute_policy_authorize_nv(esys_ctx,
                                        &policy->element.PolicyAuthorizeNv,
                                        hash_alg,
                                        current_policy);
        try_again_or_error_goto(r, "Execute policy authorize", error);
        break;
    case POLICYNV:
        r = execute_policy_nv(esys_ctx,
                              &policy->element.PolicyNV,
                              current_policy);
        try_again_or_error_goto(r, "Execute policy nv", error);
        break;
    case POLICYDUPLICATIONSELECT:
        r = execute_policy_duplicate(esys_ctx,
                                     &policy->element.PolicyDuplicationSelect,
                                     current_policy);
        try_again_or_error_goto(r, "Execute policy duplicate", error);
        break;
    case POLICYNVWRITTEN:
        r = execute_policy_nv_written(esys_ctx,
                                      &policy->element.PolicyNvWritten,
                                      current_policy);
        try_again_or_error_goto(r, "Execute policy nv written", error);
        break;
    case POLICYLOCALITY:
        r = execute_policy_locality(esys_ctx,
                                    &policy->element.PolicyLocality,
                                    current_policy);
        try_again_or_error_goto(r, "Execute policy locality", error);
        break;
    case POLICYCOMMANDCODE:
        r = execute_policy_command_code(esys_ctx,
                                        &policy->element.PolicyCommandCode,
                                        current_policy);
        try_again_or_error_goto(r, "Execute policy command code", error);
        break;
    case POLICYNAMEHASH:
        r = execute_policy_name_hash(esys_ctx,
                                     &policy->element.PolicyNameHash,
                                     current_policy);
            try_again_or_error_goto(r, "Execute policy name hash", error);
            break;
    case POLICYCPHASH:
        r = execute_policy_cp_hash(esys_ctx,
                                   &policy->element.PolicyCpHash,
                                   current_policy);
        try_again_or_error_goto(r, "Execute policy cp hash", error);
        break;
    case POLICYPHYSICALPRESENCE:
        r = execute_policy_physical_presence(esys_ctx,
                                             &policy->element.PolicyPhysicalPresence,
                                             current_policy);
        try_again_or_error_goto(r, "Execute policy physical presence", error);
            break;
    case POLICYPASSWORD:
        r = execute_policy_password(esys_ctx,
                                    &policy->element.PolicyPassword,
                                    current_policy);
        try_again_or_error_goto(r, "Execute policy password", error);
        break;
    case POLICYCOUNTERTIMER:
        r = execute_policy_counter_timer(esys_ctx,
                                         &policy->element.PolicyCounterTimer,
                                         current_policy);
        try_again_or_error_goto(r, "Execute policy counter timer", error);
        break;
    case POLICYACTION:
        r = execute_policy_action(esys_ctx,
                                  &policy->element.PolicyAction,
                                  current_policy);
        try_again_or_error_goto(r, "Execute policy action", error);
        break;

    default:
        return_error(TSS2_FAPI_RC_GENERAL_FAILURE,
                     "Policy not implemented");
        }
    return r;
error:
    return r;

    /* All policies executed successfully */
    return r;
}

/** Compute execution order for policies based on branch selection.
 *
 * To simplify asynncronous policy executiion a linked list of the policy structures
 * needed for execution based on the result of the  branch selection callbacks
 * is computed.
 * @retval TSS2_FAPI_RC_MEMORY if not enough memory can be allocated.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_UNKNOWN if a required authorization callback
 *         is not set.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_FAILED if the authorization attempt fails.
 */
static TSS2_RC
compute_policy_list(
    IFAPI_POLICY_EXEC_CTX *pol_ctx,
    TPML_POLICYELEMENTS *elements)
{
    TSS2_RC r = TSS2_RC_SUCCESS;
    TPML_POLICYBRANCHES *branches;
    TPML_POLICYELEMENTS *or_elements;
    size_t branch_idx, i;

    for (i = 0; i < elements->count; i++) {
        if (elements->elements[i].type == POLICYOR) {
            branches = elements->elements[i].element.PolicyOr.branches;
            r = pol_ctx->callbacks.cbpolsel(branches, &branch_idx,
                                            pol_ctx->callbacks.cbpolsel_userdata);
            return_if_error(r, "Select policy branch.");
            or_elements = branches->authorizations[branch_idx].policy;
            r = compute_policy_list(pol_ctx, or_elements);
            return_if_error(r, "Compute policy digest list for policy or.");
        }
        r = append_object_to_list(&elements->elements[i], &pol_ctx->policy_elements);
        return_if_error(r, "Extend policy list.");
    }
    return r;
}

/** Initialize policy element list to be executed and store policy in context.
 *
 * @param[in] pol_ctx Context for execution of a list of policy elements.
 * @param[in] hash_alg The hash algorithm used for the policy computation.
 * @param[in,out] policy The policy to be executed. Some policy elements will
 *                be used to store computed parameters needed for policy
 *                execution.
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_UNKNOWN If the callback for branch selection is
 *         not defined. This callback will be needed of or policies have to be
 *         executed.
 * @retval TSS2_FAPI_RC_BAD_VALUE If the computed branch index deliverd by the
 *         callback does not identify a branch.
 * @retval TSS2_FAPI_RC_MEMORY if not enough memory can be allocated.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_FAILED if the authorization attempt fails.
 */
TSS2_RC
ifapi_policyeval_execute_prepare(
    IFAPI_POLICY_EXEC_CTX *pol_ctx,
    TPMI_ALG_HASH hash_alg,
    TPMS_POLICY *policy)
{
    TSS2_RC r;

    pol_ctx->policy = policy;
    pol_ctx->hash_alg = hash_alg;
    r = compute_policy_list(pol_ctx, policy->policy);
    return_if_error(r, "Compute list of policy elements to be executed.");

    return TSS2_RC_SUCCESS;
}

/** Execute all policy commands defined by a list of policy elements.
 *
 * @retval TSS2_RC_SUCCESS on success.
 * @retval TSS2_FAPI_RC_MEMORY: if not enough memory can be allocated.
 * @retval TSS2_FAPI_RC_BAD_VALUE If wrong values are detected during execution.
 * @retval TSS2_FAPI_RC_IO_ERROR If an error occurs during access to the policy
 *         store.
 * @retval TSS2_FAPI_RC_POLICY_UNKNOWN If policy search for a certain policy digest was
 *         not successful.
 * @retval TSS2_FAPI_RC_BAD_TEMPLATE In a invalid policy is loaded during execution.
 * @retval TSS2_FAPI_RC_TRY_AGAIN if an I/O operation is not finished yet and
 *         this function needs to be called again.
 * @retval TSS2_FAPI_RC_GENERAL_FAILURE if an internal error occurred.
 * @retval TSS2_FAPI_RC_BAD_SEQUENCE if the context has an asynchronous
 *         operation already pending.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE a invalid null pointer is passed.
 * @retval TSS2_FAPI_RC_PATH_NOT_FOUND if a FAPI object path was not found
 *         during authorization.
 * @retval TSS2_FAPI_RC_KEY_NOT_FOUND if a key was not found.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_UNKNOWN if a required authorization callback
 *         is not set.
 * @retval TSS2_FAPI_RC_AUTHORIZATION_FAILED if the authorization attempt fails.
 * @retval TSS2_ESYS_RC_* possible error codes of ESAPI.
 */
TSS2_RC
ifapi_policyeval_execute(
    ESYS_CONTEXT *esys_ctx,
    IFAPI_POLICY_EXEC_CTX *current_policy)

{
    TSS2_RC r = TSS2_RC_SUCCESS;
    NODE_OBJECT_T *current_policy_element;

    LOG_DEBUG("call");

    while (current_policy->policy_elements) {
        r = execute_policy_element(esys_ctx,
                                   (TPMT_POLICYELEMENT *)
                                   current_policy->policy_elements->object,
                                   current_policy->hash_alg,
                                   current_policy);
        return_try_again(r);

        if (r != TSS2_RC_SUCCESS) {
            Esys_FlushContext(esys_ctx, current_policy->session);
            current_policy->session = ESYS_TR_NONE;
            ifapi_free_node_list(current_policy->policy_elements);

        }
        return_if_error(r, "Execute policy.");

        current_policy_element = current_policy->policy_elements;
        current_policy->policy_elements = current_policy->policy_elements->next;
        SAFE_FREE(current_policy_element);
    }
    return r;

}
