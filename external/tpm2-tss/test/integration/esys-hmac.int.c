/* SPDX-License-Identifier: BSD-2-Clause */
/*******************************************************************************
 * Copyright 2017-2018, Fraunhofer SIT sponsored by Infineon Technologies AG
 * All rights reserved.
 *******************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdlib.h>

#include "tss2_esys.h"

#include "esys_iutil.h"
#define LOGMODULE test
#include "util/log.h"
#include "util/aux_util.h"

/** This test is intended to test the ESAPI command  Esys_HMAC with password
 *  authentication.
 *
 * We create a symmetric HMAC key signing key which will be used
 * for signing. This key will be used to create the HMAC for a test
 * buffer.
 *
 * Tested ESAPI commands:
 *  - Esys_CreatePrimary() (M)
 *  - Esys_FlushContext() (M)
 *  - Esys_HMAC() (O)
 *
 * @param[in,out] esys_context The ESYS_CONTEXT.
 * @retval EXIT_FAILURE
 * @retval EXIT_SUCCESS
 */

int
test_esys_hmac(ESYS_CONTEXT * esys_context)
{
    TSS2_RC r;
    ESYS_TR primaryHandle = ESYS_TR_NONE;

    TPM2B_PUBLIC *outPublic = NULL;
    TPM2B_CREATION_DATA *creationData = NULL;
    TPM2B_DIGEST *creationHash = NULL;
    TPMT_TK_CREATION *creationTicket = NULL;
    TPM2B_DIGEST *outHMAC = NULL;

    TPM2B_AUTH authValuePrimary = {
        .size = 5,
        .buffer = {1, 2, 3, 4, 5}
    };

    TPM2B_SENSITIVE_CREATE inSensitivePrimary = {
        .size = 0,
        .sensitive = {
            .userAuth = {
                 .size = 0,
                 .buffer = {0 },
             },
            .data = {
                 .size = 0,
                 .buffer = {0},
             },
        },
    };
    inSensitivePrimary.sensitive.userAuth = authValuePrimary;
    TPM2B_PUBLIC inPublic = { 0 };

    TPM2B_DATA outsideInfo = {
        .size = 0,
        .buffer = {},
    };
    TPML_PCR_SELECTION creationPCR = {
        .count = 0,
    };

    inPublic.publicArea.nameAlg = TPM2_ALG_SHA1;
    inPublic.publicArea.type = TPM2_ALG_KEYEDHASH;
    inPublic.publicArea.objectAttributes |= TPMA_OBJECT_SIGN_ENCRYPT;
    inPublic.publicArea.objectAttributes |= TPMA_OBJECT_USERWITHAUTH;
    inPublic.publicArea.objectAttributes |= TPMA_OBJECT_SENSITIVEDATAORIGIN;
    inPublic.publicArea.parameters.keyedHashDetail.scheme.scheme = TPM2_ALG_HMAC;
    inPublic.publicArea.parameters.keyedHashDetail.scheme.details.hmac.hashAlg = TPM2_ALG_SHA1;

    r = Esys_CreatePrimary(esys_context, ESYS_TR_RH_OWNER, ESYS_TR_PASSWORD,
                           ESYS_TR_NONE, ESYS_TR_NONE, &inSensitivePrimary,
                           &inPublic, &outsideInfo, &creationPCR,
                           &primaryHandle, &outPublic, &creationData,
                           &creationHash, &creationTicket);
    goto_if_error(r, "Error: CreatePrimary", error);

    r = Esys_TR_SetAuth(esys_context, primaryHandle, &authValuePrimary);
    goto_if_error(r, "Error: TR_SetAuth", error);

    TPM2B_MAX_BUFFER test_buffer = { .size = 20,
                                     .buffer={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
                                              1, 2, 3, 4, 5, 6, 7, 8, 9}} ;
    r = Esys_HMAC(
        esys_context,
        primaryHandle,
        ESYS_TR_PASSWORD,
        ESYS_TR_NONE,
        ESYS_TR_NONE,
        &test_buffer,
        TPM2_ALG_SHA1,
        &outHMAC);
    goto_if_error(r, "Error: HMAC", error);

    r = Esys_FlushContext(esys_context, primaryHandle);
    goto_if_error(r, "Error: FlushContext", error);

    Esys_Free(outPublic);
    Esys_Free(creationData);
    Esys_Free(creationHash);
    Esys_Free(creationTicket);
    Esys_Free(outHMAC);
    return EXIT_SUCCESS;

 error:

    if (primaryHandle != ESYS_TR_NONE) {
        if (Esys_FlushContext(esys_context, primaryHandle) != TSS2_RC_SUCCESS) {
            LOG_ERROR("Cleanup primaryHandle failed.");
        }
    }

    Esys_Free(outPublic);
    Esys_Free(creationData);
    Esys_Free(creationHash);
    Esys_Free(creationTicket);
    Esys_Free(outHMAC);
    return EXIT_FAILURE;
}

int
test_invoke_esapi(ESYS_CONTEXT * esys_context) {
    return test_esys_hmac(esys_context);
}
