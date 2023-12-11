/*
 * ListenSoundModelLib.h
 *
 * This is the interface file of sound model library which provides
 * the APIs to get sound model information and merge, delete functionality
 * which will be used by STHAL.
 *
 * Copyright (c) 2019, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*======================================================================
DESCRIPTION : ListenSoundModelLibrary Version 3
====================================================================*/

#ifndef __LISTEN_SOUND_MODEL_LIB_V3_H__
#define __LISTEN_SOUND_MODEL_LIB_V3_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#if defined(_SML_NO_DLL)
#define DllFunc
#define CDECLARE
#elif defined(_MSC_VER) && defined(_EXPORT)
#define DllFunc   __declspec( dllexport )
#define CDECLARE    __cdecl
#elif defined(_MSC_VER)
#define DllFunc   __declspec( dllimport )
#define CDECLARE    __cdecl
#else   // For other compiler like gcc
#define DllFunc
#define CDECLARE
#endif

#define LSMLIB_VERSION 2 // %%% some unique number that changes when API changes
                         // %%% could be == SoundModel version supported for SVA 2.0

#define MAX_STRING_LEN (100 * 2)  // maximum byte size of string representing Unicode character string
// %%% NOTE: "MAX_STRING_LEN" replaces old constant "MAX_KEYWORD"


// SVA 2.0
// Keyword & User Identifier as zero terminated strings
typedef char * keywordId_t;
typedef char * userId_t;


typedef struct {
    //state machine parameters
    float minSnrOnset;                  // The minimum snr of frame that speech segment starts
    float minSnrLeave;                  // The minimum snr of frame that speech segment ends
    float snrFloor;                     // The minimum snr value assumed in the end point detector
    float snrThresholds;                // The minimum snr value of speech to verify
    float forgettingFactorNoise;        // The forgetting factor used for noise estimation
    int numFrameTransientFrame;         // the number of frames in the beginning that are used for noise estimate(valid only for online mode)
    float minEnergyFrameRatio;          // the number of frame are used for noise estimation = minenergyFrameRatio * #frames of input(valid only for batch mode)

    //post processing parameters
    //Note:
    int numMinFramesInPhrase;           // the minimum nubmer of samples for a speech phrase (targetted speech)
    int numMinFramesInSpeech;           //the minimum number of samples for a speech intereval
    int numMaxFrameInSpeechGap;         //the maximum allowable number of samples for a speech gap
    int numFramesInHead;                //the speech head
    int numFramesInTail;                //the speech tail
} listen_epd_params;

typedef struct {
    int16_t *data;              /* Audio samples ( in Raw PCM format: 16kHz, 16bit, mono ) */
    uint32_t n_samples;         /* number of audio samples */
} listen_user_recording;

typedef struct {
    uint8_t *data;              /* block of memory containing Model data */
    uint32_t size;              /* size of memory allocated for Model data */
} listen_language_model_type;

typedef struct {
    uint8_t *data;              /* block of memory containing Model data */
    uint32_t size;              /* size of memory allocated for Model data */
} listen_model_type;

// kwihyuk - comments will update
// %%% the numbering - names are up to you, as long as type + version is unique between SVA 1.0 and 2.0 SMs
typedef enum {
    kKeywordModel = 1,           /* Keyword model */
    kUserKeywordModel = 2,    /* Userkeyword model */
    kTargetSoundModel = 3,
    kMultiUserKeywordModel = 4, /* Multiple Keyword models */
    kKeywordModelWithVop = 5,   //kwihyuk
    kSecondStageKeywordModel = 6,   //kwihyuk
    kSecondStageKeywordModelWithVop = 7,    //kwihyuk
} listen_model_enum;

typedef enum {
    kSuccess = 0,
    kFailure = 1
} listen_detection_status_enum;

typedef struct {
    listen_model_enum type;     /* model type: Keyword, User, TargetSound */
    uint32_t          version;  /* model version */
    uint32_t          size;     /* total size of the model: header + payload size */
} listen_sound_model_info;


typedef struct {
    listen_detection_status_enum status; // SUCCESS or FAILURE
    uint32_t size;               // size in bytes of payload data
                                                 // just contains result confidence level values
    uint8_t *data;             // block of memory containing data payload
} listen_event_payload;

// SVA 2.0
typedef struct {
    uint16_t                numKeywords;  /* total number of keywords  */
    uint16_t                numUsers;    /* total number of users  */
    uint16_t                numActiveUserKeywordPairs;    /* total number of active user+keyword pairs in SM */
    bool                    isStripped; /* if corresponding keyword is stripped or not */
    uint16_t                *langPerKw; /* Language code of each keyword */
    /* number active Users per keyword - included as convenience */
    uint16_t                *numUsersSetPerKw;
    bool                    *isUserDefinedKeyword;
    /* Ordered 'truth' table of all possible pairs of users for each keyword.
    * Active entries marked with 1, inactive 0.keywordPhrase
    * 16-bit short (rather than boolean) is used to match SM model data size */
    uint16_t                **userKeywordPairFlags;
    uint16_t                model_indicator; /* for SM 3.0, indicate which models were combined */
} listen_sound_model_header;




// SVA 2.0
// %%% this should match the 'sensitivity' data structure input in VoiceWakeupParamType
typedef struct {
    uint8_t   size     ;  // number of keyword plus activePair confidence levels set d
    uint8_t   *pConfLevels;  // level of each keyword and each active user+keyword pair
} listen_confidence_levels ;

// SVA 2.0
typedef enum {
    kSingleKWDetectionEvent = 1,         /* SVA 1.0 model */
    kMultiKWDetectionEvent = 2,       /* SVA 2.0 model */
} listen_detection_type_enum;


// duplicates existing SVA1.0 typedef
// Do not include listen_detection_entry_v1 in SVA 1.0 header if both headers included
typedef struct {
    char keyword[MAX_STRING_LEN];
    uint16_t keywordConfidenceLevel;
    uint16_t userConfidenceLevel;
} listen_detection_event_v1;

// denotes that a particular entry in confidence level array is not active
static const uint8_t  NO_CONF_LEVEL = 0;

typedef struct {

    char     keywordPhrase[MAX_STRING_LEN]; /* string containing phrase string of keyword with highest confidence score */
    char     userName[MAX_STRING_LEN];  /* string containing name of user with highest confidence score */

    uint8_t  highestKeywordConfidenceLevel;  // set to zero if detection status is Failed
    uint8_t  highestUserConfidenceLevel;     // set to zero if detection status is Failed

    listen_confidence_levels  pairConfidenceLevels; // confidence levels of ALL pair (active or not)
} listen_detection_event_v2;

// modified for SVA 2.0 - this should override SVA 1.0 typedef
typedef struct {
    // %%% uint16_t version;
    listen_detection_type_enum   detection_data_type;
    // data structure filled is based on detection_data_type
    union {
        listen_detection_event_v1 event_v1;  // for SVA 1.0
        listen_detection_event_v2 event_v2;  // for SVA 2.0
    } event;
} listen_detection_event_type;

typedef enum {
    kSucess = 0,
    kFailed = 1,
    kBadParam,
    kKeywordNotFound,
    kUserNotFound,
    kUserKwPairNotActive,
    kSMVersionUnsupported,
    kUserDataForKwAlreadyPresent,
    kDuplicateKeyword,
    kDuplicateUserKeywordPair,
    kMaxKeywordsExceeded,
    kMaxUsersExceeded,
    kEventStructUnsupported,    // payload contains event data that can not be processed, or mismatches SM version
    kLastKeyword,
    kNoSignal,
    kLowSnr,
    kRecordingTooShort,
    kRecordingTooLong,
    kNeedRetrain,
    kUserUDKPairNotRemoved,
    kCannotCreateUserUDK,
    kOutputArrayTooSmall,
    kTooManyAbnormalUserScores,
    kWrongModel,
    kWrongModelAndIndicator,
    kDuplicateModel,
} listen_status_enum;

/*
*   Notes:
*       1. The client code that calls getKeywordPhrases(), getUserNames() must allocate DstStr as [MAX_STRING_LEN]
*       2. The client code that calls getUserKeywordModelSize(), createUserDefinedKeywordModel(),
*           createUserKeywordModel() should assign meaningful string for keywordId or userId, empty string is not recommended.
*       3. verifyUserRecording() should be called before calling createUserKeywordModel(). If pConfidenceLevel returned
*           in verifyUserRecording() is below a CONFIDENCE_THRESHOLD value, the recording should be rejected and not used
*           to a create user model. The client code should decide the CONFIDENCE_THRESHOLD value, a recommended value range for
*           CONFIDENCE_THRESHOLD is 60~70.
*
*/

    /*
    * findKeywordEndPosition
    *
    * Returns the keyword end position of user recordings from the keyword model
    * the keyword model finds the keyword end position by using keyword end finding algorithm inside SVA
    *
    * Param [in]  pKeywordModel - pointer to keyword model data which will be used to find keyword end
    * Param [in]  keywordId - null terminated string contains keyword phrase string
    * Param [in]  pUserRecording - a single recording of user speaking keyword
                                   other speech such as following command may follows
    * Param [out] pKendPosition - returns keyword end position from the start of user recording in number of samples
    *
    * Return - status
    *       kBadParam - When any input pointer (except pEpdParameter) is NULL
    *       kKeywordNotFound - When keywordId not exist in the model
    *       kSMVersionUnsupported - When pKeywordModel is not 2.0 model
    */
DllFunc listen_status_enum CDECLARE findKeywordEndPosition(
                listen_model_type           *pKeywordModel,
                keywordId_t                 keywordId,
                listen_user_recording       *pUserRecording,
                uint32_t                    *pKendPosition);

    /*
    * verifyUserRecording
    *
    * Returns the confidence level ( 0 ~ 100 ) that user recording matches keyword
    * User data is to be appended for a specific keyword in the model
    * // will be updated or removed
    * if input is SM 3.0 which combiend with GMM and other sound models,
    * then parsing to GMM model and run same procedure.
    *
    * Param [in]  pKeywordModel - pointer to user-independent keyword model data
    * Param [in]  keywordId - null terminated string contains keyword phrase string
    * Param [in]  listen_epd_params - epd parameter
                                      if null is passing, default epd parameter will be used internally
    * Param [in]  pUserRecording - a single recording of user speaking keyword
    * Param [out] pConfidenceLevel - returns confidence level returned by keyword detection
    *
    * Return - status
    *       kBadParam - When any input pointer (except pEpdParameter) is NULL
    *       kKeywordNotFound - When keywordId not exist in the model
    *       kSMVersionUnsupported - When pKeywordModel is not 2.0 (have to contain GMM) model
    *       kLowSnr - When user recording is too noisy
    *       kNoSignal - When user recording is non-speech
    */
DllFunc listen_status_enum CDECLARE verifyUserRecording(
        listen_model_type           *pKeywordModel,
        keywordId_t                 keywordId, // add for SVA 2.0
        listen_epd_params           *pEpdParameter,
        listen_user_recording       *pUserRecording,
        int16_t                     *pConfidenceLevel);

    /*
    * checkUserRecording
    *
    * Returns the status of user recordings that if user recording has problem with SNR(Signal Noise Ratio) and length
    *
    * Param [in]  pLanguageModel - pointer to language model
    * Param [in]  pEpdParameter - pointer to EPD parameters
    *                            Default parameter will be used if eEpdParameter is NULL
    * Param [in]  pUserRecording - User recording that is going to be tested
    * Param [out]  pOutSnr - SNR of user recording
    * Param [in]  maxPhonemeLength (optional parameter) - maximum phoneme length allowed for each user recording
    *                                                   - It is optional parameter, whose default value is 0.
    *
    * Return - status
    *       kBadParam - When any input pointer (except pEpdParameter) is NULL
    *         kLowSnr   - When user recording is too noisy
    *         kNoSignal - When user recording is non-speech
    *       kRecordingTooShort - When user recording is too short
    */
DllFunc listen_status_enum CDECLARE checkUserRecording(
        listen_language_model_type  *pLanguageModel,
        listen_epd_params           *pEpdParameter,
        listen_user_recording       *pUserRecording,
        float                       *pOutSnr,
        uint32_t                    maxPhonemeLength);

    /*
    * checkRecordingsQuality
    *
    * Returns the status of the last user recording in recording array that
    * if user recording has problem with SNR(Signal Noise Ratio) and length
    * Check the consistency of the input recordings if numUserRecording > 1
    *
    * Param [in]  pLanguageModel - pointer to language model
    * Param [in]  pEpdParameter - pointer to EPD parameters
    *                            Default parameter will be used if eEpdParameter is NULL
    * Param [in]  numUserRecording - number of input recordings
    * Param [in]  pUserRecordings - User recordings those are going to be tested
    * Param [out]  pOutSnr - SNR of user recording
    *
    * Return - status
    *       kBadParam - When any input pointer (except pEpdParameter) is NULL
    *         kLowSnr   - When user recording is too noisy
    *         kNoSignal - When user recording is non-speech
    *       kRecordingTooShort - When user recording is too short
    */

DllFunc listen_status_enum CDECLARE checkRecordingsQuality(
        listen_language_model_type  *pLanguageModel,
        listen_epd_params           *pEpdParameter,
        uint32_t                     numUserRecording,
        listen_user_recording       *pUserRecordings[],
        float                       *pOutSnr);

    /*
    * tuneUserDefinedKeywordModelThreshold
    *
    * This function tunes threshold of user defined keyword.
    *
    * This function can be used when programmer want to make testing stage after training stage of user defined keyword
    * even though threshold of user defined keyword is automatically tunned when create user defined keyword,
    * this function can be useful when tune more threshold of user defined keyword
    *
    * Param [in]  pUserDefinedKeyword - pointer to user defined keyword
    * Param [in]  keywordId - keyword spell
    * Param [in]  pUserRecording - user recording from testing stage
    * Param [out]  pOutputUserDefinedKeyword - tunned user defined keyword
    *
    * Return - listen_status_enum
    * Return - status
    *       kBadParam - When any input pointer is NULL, or pUserDefinedKeyword is not UDK
    *       kKeywordNotFound - When keywordId not exist in the model
    */
DllFunc listen_status_enum CDECLARE tuneUserDefinedKeywordModelThreshold(
        listen_model_type           *pUserDefinedKeyword,
        keywordId_t                 keywordId,
        listen_user_recording       *pUserRecording,
        listen_model_type           *pOutputUserDefinedKeyword);


    /*
    * getUserDefinedKeywordSize
    *
    * Get the size required to hold user defined keyword model that extends given keyword model
    * with give user data
    *
    * Param [in]  pUserDefinedKeyword - pointer to previous user defined keyword
                                        if pUserDefinedKeyword is NULL, this will create new user defined keyword model
                                        if pUserDefinedKeyword is not NULL, this will train incrementally ( not supported now )

    * Param [in]  keywordId - keyword spell of user defined keyword
    * Param [in]  userId - user spell of user defined keyword
    * Param [in]  pEpdParameter - epd parameter which is used for chopping user recording.
                                   if eEpdParameter is NULL, default parameter will be used
    * Param [in]  numUserRecording - number of user recording
    * Param [in]  pUserRecordings[] -  multiple recording of user speaking keyword
    * Param [in]  pLanguageModel - language model
    * Param [out]  pOutputSize - pointer to where output model size will be written
    *
    * Return - listen_status_enum
    * Return - status
    *       kBadParam - When any input pointer (except pUserDefinedKeyword, pEpdParameter) is NULL, or pLanguageModel is fake
    *       kNoSignal - When user recording is non-speech
    */
DllFunc listen_status_enum CDECLARE getUserDefinedKeywordSize(
        listen_model_type           *pUserDefinedKeyword,
        keywordId_t                 keywordId,
        userId_t                    userId,
        listen_epd_params           *pEpdParameter,
        uint32_t                    numUserRecording,
        listen_user_recording       *pUserRecordings[],
        listen_language_model_type  *pLanguageModel,
        uint32_t                    *pOutputSize);

    /*
    * getUserDefinedKeywordApproxSize
    *
    * Get the size required to hold user-keyword model that extends given keyword model
    * with give user data
    *
    * Param [in]  keywordId - null terminated string containing keyword phrase string
    * Param [in]  userId - null terminated string containing user name string
    * Param [in]  pLanguageModel - pointer to language model data
    * Param [out] pOutputSize - size of approximated output model
    * Param [in]  maxPhonemeLength (optional parameter) - maximum phoneme length allowed for each user recording
    *                                                   - It is optional parameter, whose default value is 0.
    *
    * Return - status
    *       kBadParam - When any input pointer is NULL
    */

DllFunc listen_status_enum CDECLARE getUserDefinedKeywordApproxSize(
    keywordId_t keywordId,
    userId_t userId,
    listen_language_model_type *pLanguageModel,
    uint32_t                        *pOutputSize,
    uint32_t                        maxPhonemeLength);

    /*
    * createUserDefinedKeywordModel
    *
    * Description : Create User Defined Keyword Model
    *
    * Param [in]  pUserDefinedKeyword - pointer to previous user defined keyword
                                        if pUserDefinedKeyword is NULL, this will create new user defined keyword model
                                        if pUserDefinedKeyword is not NULL, this will train incrementally ( not supported now )

    * Param [in]  keywordId - keyword spell of user defined keyword
    * Param [in]  userId - user spell of user defined keyword
    * Param [in]  pEpdParameter - epd parameter which is used for chopping user recording.
                                   if eEpdParameter is NULL, default parameter will be used
    * Param [in]  numUserRecording - number of user recording
    * Param [in]  pUserRecordings[] - multiple recording of user speaking keyword
    * Param [in]  pLanguageModel - language model
    * Param [out] pOutputUserDefinedKeyword - pointer to where output model will be written
    * Param [out] pMatchingScore - pointer to matching score
    *
    * Return - listen_status_enum
    * Return - status
    *       kBadParam - When any input pointer (except pUserDefinedKeyword, pEpdParameter) is NULL, or pLanguageModel is fake
    *       kNoSignal - When user recording is non-speech
    *       kCannotCreateUserUDK - When creation process fails somewhere
    *       kOutputArrayTooSmall - When output size is smaller than actual udk model size
    */
DllFunc listen_status_enum CDECLARE createUserDefinedKeywordModel(
        listen_model_type          *pUserDefinedKeyword,
        keywordId_t                 keywordId,
        userId_t                    userId,
        listen_epd_params           *pEpdParameter,
        uint32_t                     numUserRecording,
        listen_user_recording      *pUserRecordings[],
        listen_language_model_type  *pLanguageModel,
        listen_model_type           *pOutputUserDefinedKeyword,
        int16_t                     *pMatchingScore);

    /*
    * getStrippedUserKeywordModelSize
    *
    * Return stripped model size
    *
    * Param[in] pModel - pointer to (user)keyword model data
    * Param[out] nStrippedModelSize - return model size of stripped model
    *
    * Return - status
    *           kBadParam - When any input pointer is NULL
    *           kSMVersionUnsupported - When pModel is not 2.0 model
    *
    */
DllFunc listen_status_enum CDECLARE getStrippedUserKeywordModelSize(
        listen_model_type           *pModel,
        uint32_t                    *nStrippedModelSize);


    /*
    * stripUserKeywordModel
    *
    * Return stripped model
    *
    * Param[in] pModel - pointer to (user)keyword model data
    * Param[out] pStrippedModel - pointer to stripped model data
    *
    * Return - status
    *           kBadParam - When any input pointer is NULL
    *           kSMVersionUnsupported - When pModel is not 2.0 model
    *
    */
DllFunc listen_status_enum CDECLARE stripUserKeywordModel(
        listen_model_type           *pModel,
        listen_model_type           *pStrippedModel);

    /*
    * getUserKeywordModelSize
    *
    * Get the size required to hold user-keyword model that extends given keyword model
    * with give user data
    *
    * Param [in]  pKeywordModel - pointer to keyword model data
    * Param [in]  keywordId - null terminated string containing keyword phrase string
    * Param [in]  userId - null terminated string containing user name string
    * Param [out] nUserKeywordModelSize - size of user keyword model
    *
    * Return - status
    *       kBadParam - When any input pointer is NULL
    *       kKeywordNotFound - When keywordId not exist in the model
    *       kSMVersionUnsupported - When pKeywordModel is not 2.0/3.0 model
    */
DllFunc listen_status_enum CDECLARE getUserKeywordModelSize(
        listen_model_type           *pKeywordModel,
        keywordId_t                 keywordId, // add for SVA 2.0
        userId_t                    userId, // add for SVA 2.0
        uint32_t                    *nUserKeywordModelSize);

    /*
    * createUserKeywordModel
    *
    * Create a user keyword model
    * Writes the user keyword model into given memory location
    *
    * Param [in]  pKeywordModel - pointer to Keyword model  or User keyword model data
                                if it is keyword model, create user-keyword model
                                if it is user keyword model, incrementally train user keyword model
    * Param [in]  keywordId - user data is to be appended for keyword in model with given identifier
    * Param [in]  userId - identifier of user data is created
    *            If identifier is already used, will replace existing user data with newly created data.
    *            The User Name is passed to this function so that if this is the first time user data is
    *            being added for a new user, the User's Name can be stored in the SM
    * Param [in]  pEpdParameter - end point detection parameter
    *                             if eEpdParameter is NULL, default parameter will be used
    * Param [in]  numUserRecording - number of user recordings
    * Param [in]  pUserRecordings - multiple recording of user speaking keyword
    * Param [out] pUserKeywordModel - pointer to where user keyword model data is to be written
    * Param [out] pUserMatchingScore - pointer to user matching score
    * Return - status
    *       kBadParam - When any input pointer (except pEpdParameter) is NULL
    *       kKeywordNotFound - When keywordId not exist in the model
    *       kSMVersionUnsupported - When pKeywordModel is not 2.0 or 3.0 model
    *        kLowSnr    - When user recording is too noisy
    *        kNoSignal - When user recording is non-speech
    *       kCannotCreateUserUDK - When pKeywordModel is UDK model
    */
DllFunc listen_status_enum CDECLARE createUserKeywordModel(
        listen_model_type           *pKeywordModel,
        keywordId_t                 keywordId, // add for SVA 2.0
        userId_t                    userId, // add for SVA 2.0
        listen_epd_params           *pEpdParameter,
        uint32_t                    numUserRecording,
        listen_user_recording       *pUserRecordings[],
        listen_model_type           *pUserKeywordModel,
        int16_t                     *pUserMatchingScore);

// Since size of new SM after removing data will be less than or equal to size of
// input SM, this function could be optional and size of pInputModel could be used
// to allocate memory for pResultModel when deleteFromModel() called.
    /*
    * getSizeAfterDeleting
    *
    * Return the size of sound model after removing data from a given SM for either
    * a keyword, a user, or a specific user+keyword pair.
    *
    * Param [in]  pInputModel - pointer to sound model
    * Param [in]  keywordId - data for this keyword in model with given identifier is removed
    *           If userId is 'null', then all keyword-only data and all user data associated
    *           with the given non-null keywordId is removed.
    *           If userId is also non-null, then only data associated with the userId+keywordId
    *           pair is removed.
    * Param [in]  userId - all data for this user in model with given identifier is removed
    *           If keywordId is 'null', then all all user data for the given non-null userId
    *           is removed.
    *           If keywordId is also non-null, then only data associated with the userId+keywordId
    *           pair is removed.
    * Param [out]  nOutputModelSize - outputs size of resulting soundmodel after removing data.
    * Return - status
    *       kBadParam - When any input pointer (except keywordId, userId) is NULL
    *       kLastKeyword - When pInputModel has only one keyword
    *       kSMVersionUnsupported - When pInputModel is not 2.0 model
    *       kKeywordNotFound - When keywordId not exist in the model
    *       kUserNotFound - When userId not exist in the model
    *       kUserKWPairNotActive - When <keywordId, userId> pair not exist in the model
    *       kUserUDKPairNotRemoved - When <keywordId, userId> pair to delete is UDK
    */
DllFunc listen_status_enum CDECLARE getSizeAfterDeleting(
        listen_model_type           *pInputModel,
        keywordId_t                 keywordId, // add for SVA 2.0
        userId_t                    userId, // add for SVA 2.0
        uint32_t                    *nOutputModelSize);

// If getSizeAfterDeleting() supported, call it get size of new sound model after
// removing desired data from given input sound model, and
// allocate ResultModel with this size
// Otherwise, use size of input SoundModel since size of ResultModel will be
// less than or equal to size of input SoundModel.
    /*
    * deleteFromModel
    *
    * Return a new sound model after removing data from a given SM for a keyword, a user,
    * or a user+keyword pair.
    *
    * Param [in]  pInputModel - pointer to sound model
    * Param [in]  keywordId - data for this keyword in model with given identifier is removed
    *           If userId is 'null', then all keyword-only data and all user data associated
    *           with the given non-null keywordId is removed.
    *           If userId is also non-null, then only data associated with the userId+keywordId
    *           pair is removed.
    * Param [in]  userId - all data for this user in model with given identifier is removed
    *           If keywordId is 'null', then all all user data for the given non-null userId
    *           is removed.
    *           If keywordId is also non-null, then only data associated with the userId+keywordId
    *           pair is removed.
    * Param [out]  pResultModel - pointer to where user keyword model data is to be written
    * Return - status
    *       kBadParam - When any input pointer (except keywordId, userId) is NULL
    *       kLastKeyword - When pInputModel has only one keyword
    *       kSMVersionUnsupported - When pInputModel is not 2.0 or 3.0 model
    *       kKeywordNotFound - When keywordId not exist in the model
    *       kUserNotFound - When userId not exist in the model
    *       kUserKWPairNotActive - When <keywordId, userId> pair not exist in the model
    *       kUserUDKPairNotRemoved - When <keywordId, userId> pair to delete is UDK
    */
DllFunc listen_status_enum CDECLARE deleteFromModel(
        listen_model_type           *pInputModel,
        keywordId_t                 keywordId, // add for SVA 2.0
        userId_t                    userId, // add for SVA 2.0
        listen_model_type           *pResultModel);


    /*
    * getMergedModelSize
    *
    * Return the size of sound model after merging required models
    *
    * Param [in]  numModels - number of model files to be merged
    * Param [in]  pModels - array of pointers to Keyword or User keyword model data
    * Param [out]  nOutputModelSize - outputs size of resulting soundmodel after merging models
    *
    * Return - status
    *       kBadParam - When any input pointer is NULL
    *       kSMVersionUnsupported - When pInputModel is not 2.0 model
    *       kDuplicateKeyword - When same keywordId exists in more than 1 model
    *       kDuplicateUserKeywordPair
    *       kMaxKeywordsExceeded
    *       kMaxUsersExceeded,
    */
DllFunc listen_status_enum CDECLARE getMergedModelSize(
        uint16_t                    numModels,
        listen_model_type           *pModels[],
        uint32_t                    *nOutputModelSize);



    /*
    * mergeModels
    *
    * merges two or more Sound Models
    *
    * Writes the new merged model into given memory location
    *
    * Param [in]  numModels - number of model files to be merged
    * Param [in]  pModels - array of pointers to Keyword or User keyword model data
    * Param [out]  pMergedModel - pointer to where merged model data is to be written
    * Return - status
    *       kBadParam - When any input pointer is NULL
    *       kSMVersionUnsupported - When pInputModel is not 2.0 model
    *       kDuplicateKeyword - When same keywordId exists in more than 1 model
    *       kDuplicateUserKeywordPair - N/A to current version
    *       kMaxKeywordsExceeded - N/A to current version
    *       kMaxUsersExceeded - N/A to current version
    */
DllFunc listen_status_enum CDECLARE mergeModels(
        uint16_t                    numModels,
        listen_model_type       *pModels[],
        listen_model_type       *pMergedModel);



/* ParseFromBigSoundModel
*
* Parse the big 3.0 sound model to individual sub models
*
* Param [in]   *pSM3p0Model – The pointer to the big 3.0 sound model
* Param [out]  p1stStageModel - pointer to parsed 1stStageModel
* Param [out]  p2ndStageKWModel - pointer to parsed 2nd stage KW Model
* Param [out]  p2stStageVoPModel - pointer to parsed 2nd stage VoP Model
* Param [out]  indicator – returned indicator, indicating what types of models parsed/returned
* Return - status
*       kBadParam - When any input pointer is NULL
*       kSMVersionUnsupported - When pInputModel is not 3.0 model
*       kDuplicateKeyword - When same keywordId exists in more than 1 model
*       kWrongModel - when input is broken
*/

DllFunc listen_status_enum CDECLARE parseFromBigSoundModel(
        listen_model_type       *pSM3p0Model,
        listen_model_type       *p1stStageModel,
        listen_model_type       *p2ndStageKWModel,
        listen_model_type       *p2stStageVoPModel,
        uint16_t                *indicator );




    /*
    * parseDetectionEventData
    *
    * parse event payload into detection event.
    *
    * Version of input SM will detemine DetectionType created/returned
    *
    * Param [in]  pUserKeywordModel - pointer to keyword or user keyword model data
    * Param [in]  pEventPayload - pointer to received event payload data
    * Param [out] pDetectEvent - pointer to where detection event data is to be written
    * Return - status
    *       kBadParam - When any input pointer is NULL
    *       kSMVersionUnsupported - When pUserKeywordModel is not 2.0 model
    *       kEventStructUnsupported - When pEventPayload->size != numKeywords + numActiveUsers
    */

DllFunc listen_status_enum CDECLARE parseDetectionEventData(
        listen_model_type           *pUserKeywordModel,
        listen_event_payload        *pEventPayload,
        listen_detection_event_type *pDetectionEvent);


// Declared in both SVA 1.0 and SVA 2.0 versions and SML 3.0 of ListenSoundModelMLib
//
    /*
    * querySoundModel
    *
    * Returns the information about a sound model
    * Sound model could be of any type: Keyword, UserKeyword, TargetSound,...
    * Sound model could be any versions
    *
    * Param [in] pSoundModel - pointer to model data
    * Param [out] pListenSoundModelInfo - returns information about the give sound model
    *
    * Return - status
    *       kBadParam - When any input pointer is NULL
    *       kFailed - When input model failed to be decoded
    *        kSMVersionUnsupported - When pSoundModel is fake model (invalid model other than 1.0 model, 2.0 model and 3.0 model)
    */
DllFunc listen_status_enum CDECLARE querySoundModel(
        listen_model_type           *pSoundModel,
        listen_sound_model_info     *pListenSoundModelInfo);


    /*
    * getSoundModelHeader
    *
    * Returns additional information about the sound model
    * Sound model could be of any type: Keyword, UserKeyword, TargetSound,...
    * Keyword
    *
    * Param [in] pSoundModel - pointer to model data
    * Param [out] pListenSoundModelHeader - returns header field from sound model
    *
    * Return - status
    *       kBadParam - When any input pointer is NULL
    *       kSMVersionUnsupported - When pSoundModel is not 2.0 or 3.0 model
    */

DllFunc listen_status_enum CDECLARE getSoundModelHeader(
        listen_model_type           *pSoundModel,
        listen_sound_model_header   *pListenSoundModelHeader);


    /*
    * release sound model header
    *
    * deallocate sound model header
    * Return - status
    *       kBadParam - When any input pointer is NULL
    */
DllFunc listen_status_enum CDECLARE releaseSoundModelHeader(
        listen_sound_model_header   *pListenSoundModelHeader);


    /*
    * getKeywordPhrases
    *
    * Get keyword phrase string for all Keywords defined in given SM 2.0 / 3.0
    *
    * App calling this function must allocate memory for all phrases
    * by getting the number of keywords from querySoundModel() and allocating
    * totalNumKeywords*MAX_STRING_LEN
    * This function copies phrases into this allocated keywords array
    *
    * Param [in]  pSoundModel - pointer to model data
    * Param [in/out] numKeywords - [in]  number of string entries allocated in keywords array
    *                             [out] number of keyword phrase strings copied keyword array
    * Param [out] keywords - array of keyword phrase null-terminated strings
    *
    * Return - status
    *       kBadParam - When any input pointer is NULL, or numKeywords < real keywords number
    *       kSMVersionUnsupported - When pSoundModel is not 2.0 or 3.0 model
    */
DllFunc listen_status_enum CDECLARE getKeywordPhrases(
        listen_model_type           *pSoundModel,
        uint16_t                    *numKeywords,
        keywordId_t                 *keywords);


    /*
    * getUserNames
    *
    * Get user names for user data associated with a given SM 2.0 / 3.0
    *
    * App calling this function must allocate memory for all names
    * by getting the number of users  from querySoundModel() and allocating
    * totalNumUsers*MAX_STRING_LEN
    * This function copies names into this allocated keywords array
    *
    * Param [in]  pSoundModel - pointer to model data
    * Param [in/out] numUsers - [in]  number of string entries allocated in users array
    *                          [out] number of user name strings copied users array
    * Param [out] users - array of user name null-terminated strings
    *
    * Return - status
    *       kBadParam - When any input pointer is NULL, or numUsers < real users number, or pSoundModel is keyword-only model
    *       kSMVersionUnsupported - When pSoundModel is not 2.0 or 3.0 model
    */
DllFunc listen_status_enum CDECLARE getUserNames(
        listen_model_type           *pSoundModel,
        uint16_t                        *numUsers,
        userId_t                        *users);

    /*
    * loadConfParams
    *
    * Load configurable parameters to the sound model library
    *
    * Param [in] pConfData - pointer to param data
    * Param [in] confDataSize - size of memory allocated for param data
    *
    * Return - status
    *       kBadParam - When any input pointer is NULL
    */
DllFunc listen_status_enum CDECLARE loadConfParams(
        uint8_t                     *pConfData,
        uint32_t                    confDataSize);
    /*
    * getBinaryModelSize
    *
    * Return binary model size
    *
    * Param[in] pListenModel - pointer to (user)keyword model data
    * Param[out] nBinaryModelSize - return model size of binary model
    *
    * Return - status
    *           kBadParam - When any input pointer is NULL
    *           kSMVersionUnsupported - When pModel is not 2.0 or 3.0 model
    *
    */

DllFunc listen_status_enum CDECLARE getBinaryModelSize(
        listen_model_type           *pListenModel,
        uint32_t                    *nBinaryModelSize);

    /*
    * getSortedKeywordStatesUserKeywordModelSize
    *
    * Return sorted model size
    *
    * Param[in] pModel - pointer to (user)keyword model data
    * Param[out] nSortedModelSize - return model size of sorted keyword states model
    *
    * Return - status
    *           kBadParam - When any input pointer is NULL
    *
    */

DllFunc listen_status_enum CDECLARE getSortedKeywordStatesUserKeywordModelSize(
    listen_model_type           *pModel,
    uint32_t                    *nSortedModelSize);

    /*
    * sortKeywordStatesOfUserKeywordModel
    *
    * Return sorted model
    *
    * Param[in] pInputModel - pointer to (user)keyword model data
    * Param[out] pSortedModel - pointer to sorted keyword states model data
    *
    * Return - status
    *           kBadParam - When any input pointer is NULL
    *           kSMVersionUnsupported - when pModel is not 2.0 model
    *
    */

DllFunc listen_status_enum CDECLARE sortKeywordStatesOfUserKeywordModel(
        listen_model_type           *pInputModel,
        listen_model_type           *pSortedModel);


#ifdef __cplusplus
};
#endif

#endif /* __LISTEN_SOUND_MODEL_LIB_V3_H__ */

