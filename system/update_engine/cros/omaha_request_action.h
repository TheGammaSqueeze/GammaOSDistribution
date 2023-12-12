//
// Copyright (C) 2012 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef UPDATE_ENGINE_CROS_OMAHA_REQUEST_ACTION_H_
#define UPDATE_ENGINE_CROS_OMAHA_REQUEST_ACTION_H_

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <gtest/gtest_prod.h>  // for FRIEND_TEST

#include <base/optional.h>
#include <brillo/secure_blob.h>
#include <curl/curl.h>

#include "update_engine/common/action.h"
#include "update_engine/common/http_fetcher.h"
#include "update_engine/cros/omaha_request_builder_xml.h"
#include "update_engine/cros/omaha_response.h"

// The Omaha Request action makes a request to Omaha and can output
// the response on the output ActionPipe.

namespace policy {
class PolicyProvider;
}

namespace chromeos_update_engine {

class NoneType;
class OmahaRequestAction;
class OmahaRequestParams;

// This struct is declared in the .cc file.
struct OmahaParserData;

template <>
class ActionTraits<OmahaRequestAction> {
 public:
  // Takes parameters on the input pipe.
  typedef NoneType InputObjectType;
  // On UpdateCheck success, puts the Omaha response on output. Event
  // requests do not have an output pipe.
  typedef OmahaResponse OutputObjectType;
};

class OmahaRequestAction : public Action<OmahaRequestAction>,
                           public HttpFetcherDelegate {
 public:
  static const int kPingTimeJump = -2;
  // We choose this value of 3 as a heuristic for a work day in trying
  // each URL, assuming we check roughly every 45 mins. This is a good time to
  // wait so we don't give up the preferred URLs, but allow using the URL that
  // appears earlier in list for every payload before resorting to the fallback
  // URLs in the candiate URL list.
  static const int kDefaultMaxFailureCountPerUrl = 3;

  // If staging is enabled, set the maximum wait time to 28 days, since that is
  // the predetermined wait time for staging.
  static const int kMaxWaitTimeStagingInDays = 28;

  // These are the possible outcome upon checking whether we satisfied
  // the wall-clock-based-wait.
  enum WallClockWaitResult {
    kWallClockWaitNotSatisfied,
    kWallClockWaitDoneButUpdateCheckWaitRequired,
    kWallClockWaitDoneAndUpdateCheckWaitNotRequired,
  };

  // The ctor takes in all the parameters that will be used for making
  // the request to Omaha. For some of them we have constants that
  // should be used.
  //
  // Takes ownership of the passed in HttpFetcher. Useful for testing.
  //
  // Takes ownership of the passed in OmahaEvent. If |event| is null,
  // this is an UpdateCheck request, otherwise it's an Event request.
  // Event requests always succeed.
  //
  // A good calling pattern is:
  // OmahaRequestAction(..., new OmahaEvent(...), new WhateverHttpFetcher);
  // or
  // OmahaRequestAction(..., nullptr, new WhateverHttpFetcher);
  OmahaRequestAction(OmahaEvent* event,
                     std::unique_ptr<HttpFetcher> http_fetcher,
                     bool ping_only,
                     const std::string& session_id);
  ~OmahaRequestAction() override;
  typedef ActionTraits<OmahaRequestAction>::InputObjectType InputObjectType;
  typedef ActionTraits<OmahaRequestAction>::OutputObjectType OutputObjectType;
  void PerformAction() override;
  void TerminateProcessing() override;
  void ActionCompleted(ErrorCode code) override;

  int GetHTTPResponseCode() { return http_fetcher_->http_response_code(); }

  // Debugging/logging
  static std::string StaticType() { return "OmahaRequestAction"; }
  std::string Type() const override { return StaticType(); }

  // Delegate methods (see http_fetcher.h)
  bool ReceivedBytes(HttpFetcher* fetcher,
                     const void* bytes,
                     size_t length) override;

  void TransferComplete(HttpFetcher* fetcher, bool successful) override;

  // Returns true if this is an Event request, false if it's an UpdateCheck.
  bool IsEvent() const { return event_.get() != nullptr; }

 private:
  friend class OmahaRequestActionTest;
  friend class OmahaRequestActionTestProcessorDelegate;
  FRIEND_TEST(OmahaRequestActionTest, GetInstallDateWhenNoPrefsNorOOBE);
  FRIEND_TEST(OmahaRequestActionTest,
              GetInstallDateWhenOOBECompletedWithInvalidDate);
  FRIEND_TEST(OmahaRequestActionTest,
              GetInstallDateWhenOOBECompletedWithValidDate);
  FRIEND_TEST(OmahaRequestActionTest,
              GetInstallDateWhenOOBECompletedDateChanges);
  friend class UpdateAttempterTest;
  FRIEND_TEST(UpdateAttempterTest, SessionIdTestEnforceEmptyStrPingOmaha);
  FRIEND_TEST(UpdateAttempterTest, SessionIdTestConsistencyInUpdateFlow);

  // Enumeration used in PersistInstallDate().
  enum InstallDateProvisioningSource {
    kProvisionedFromOmahaResponse,
    kProvisionedFromOOBEMarker,

    // kProvisionedMax is the count of the number of enums above. Add
    // any new enums above this line only.
    kProvisionedMax
  };

  // Gets the install date, expressed as the number of PST8PDT
  // calendar weeks since January 1st 2007, times seven. Returns -1 if
  // unknown. See http://crbug.com/336838 for details about this value.
  static int GetInstallDate();

  // Parses the Omaha Response in |doc| and sets the
  // |install_date_days| field of |output_object| to the value of the
  // elapsed_days attribute of the daystart element. Returns True if
  // the value was set, False if it wasn't found.
  static bool ParseInstallDate(OmahaParserData* parser_data,
                               OmahaResponse* output_object);

  // Returns True if the kPrefsInstallDateDays state variable is set,
  // False otherwise.
  static bool HasInstallDate();

  // Writes |install_date_days| into the kPrefsInstallDateDays state
  // variable and emits an UMA stat for the |source| used. Returns
  // True if the value was written, False if an error occurred.
  static bool PersistInstallDate(int install_date_days,
                                 InstallDateProvisioningSource source);

  // Persist the new cohort value received in the XML file in the |prefs_key|
  // preference file. If the |new_value| is empty, do nothing. If the
  // |new_value| stores and empty value, the currently stored value will be
  // deleted. Don't call this function with an empty |new_value| if the value
  // was not set in the XML, since that would delete the stored value.
  void PersistCohortData(const std::string& prefs_key,
                         const base::Optional<std::string>& new_value);

  // Parses and persists the cohorts sent back in the updatecheck tag
  // attributes.
  void PersistCohorts(const OmahaParserData& parser_data);

  // If this is an update check request, initializes
  // |ping_active_days_| and |ping_roll_call_days_| to values that may
  // be sent as pings to Omaha.
  void InitPingDays();

  // Based on the persistent preference store values, calculates the
  // number of days since the last ping sent for |key|.
  int CalculatePingDays(const std::string& key);

  // Returns whether we have "active_days" or "roll_call_days" ping values to
  // send to Omaha and thus we should include them in the response.
  bool ShouldPing() const;

  // Process Omaha's response to a ping request and store the results in the DLC
  // metadata directory.
  void StorePingReply(const OmahaParserData& parser_data) const;

  // Returns true if the download of a new update should be deferred.
  // False if the update can be downloaded.
  bool ShouldDeferDownload(OmahaResponse* output_object);

  // Returns true if the basic wall-clock-based waiting period has been
  // satisfied based on the scattering policy setting. False otherwise.
  // If true, it also indicates whether the additional update-check-count-based
  // waiting period also needs to be satisfied before the download can begin.
  WallClockWaitResult IsWallClockBasedWaitingSatisfied(
      OmahaResponse* output_object);

  // Returns true if the update-check-count-based waiting period has been
  // satisfied. False otherwise.
  bool IsUpdateCheckCountBasedWaitingSatisfied();

  // Parses the response from Omaha that's available in |doc| using the other
  // helper methods below and populates the |output_object| with the relevant
  // values. Returns true if we should continue the parsing.  False otherwise,
  // in which case it sets any error code using |completer|.
  bool ParseResponse(OmahaParserData* parser_data,
                     OmahaResponse* output_object,
                     ScopedActionCompleter* completer);

  // Parses the status property in the given update_check_node and populates
  // |output_object| if valid. Returns true if we should continue the parsing.
  // False otherwise, in which case it sets any error code using |completer|.
  bool ParseStatus(OmahaParserData* parser_data,
                   OmahaResponse* output_object,
                   ScopedActionCompleter* completer);

  // Parses the URL nodes in the given XML document and populates
  // |output_object| if valid. Returns true if we should continue the parsing.
  // False otherwise, in which case it sets any error code using |completer|.
  bool ParseUrls(OmahaParserData* parser_data,
                 OmahaResponse* output_object,
                 ScopedActionCompleter* completer);

  // Parses the other parameters in the given XML document and populates
  // |output_object| if valid. Returns true if we should continue the parsing.
  // False otherwise, in which case it sets any error code using |completer|.
  bool ParseParams(OmahaParserData* parser_data,
                   OmahaResponse* output_object,
                   ScopedActionCompleter* completer);

  // Called by TransferComplete() to complete processing, either
  // asynchronously after looking up resources via p2p or directly.
  void CompleteProcessing();

  // Helper to asynchronously look up payload on the LAN.
  void LookupPayloadViaP2P(const OmahaResponse& response);

  // Callback used by LookupPayloadViaP2P().
  void OnLookupPayloadViaP2PCompleted(const std::string& url);

  // Returns true if the current update should be ignored.
  bool ShouldIgnoreUpdate(const OmahaResponse& response,
                          ErrorCode* error) const;

  // Return true if updates are allowed by user preferences.
  bool IsUpdateAllowedOverCellularByPrefs(const OmahaResponse& response) const;

  // Returns true if updates are allowed over the current type of connection.
  // False otherwise.
  bool IsUpdateAllowedOverCurrentConnection(
      ErrorCode* error, const OmahaResponse& response) const;

  // Returns true if rollback is enabled. Always returns false for consumer
  // devices.
  bool IsRollbackEnabled() const;

  // Sets the appropriate max kernel key version based on whether rollback is
  // enabled.
  void SetMaxKernelKeyVersionForRollback() const;

  // Reads and returns the kPrefsUpdateFirstSeenAt pref if the pref currently
  // exists. Otherwise saves the current wallclock time to the
  // kPrefsUpdateFirstSeenAt pref and returns it as a base::Time object.
  base::Time LoadOrPersistUpdateFirstSeenAtPref() const;

  // Pointer to the OmahaEvent info. This is an UpdateCheck request if null.
  std::unique_ptr<OmahaEvent> event_;

  // pointer to the HttpFetcher that does the http work
  std::unique_ptr<HttpFetcher> http_fetcher_;

  // Used for fetching information about the device policy.
  std::unique_ptr<policy::PolicyProvider> policy_provider_;

  // If true, only include the <ping> element in the request.
  bool ping_only_;

  // Stores the response from the omaha server
  brillo::Blob response_buffer_;

  // Initialized by InitPingDays to values that may be sent to Omaha
  // as part of a ping message. Note that only positive values and -1
  // are sent to Omaha.
  int ping_active_days_;
  int ping_roll_call_days_;

  std::string session_id_;

  DISALLOW_COPY_AND_ASSIGN(OmahaRequestAction);
};

}  // namespace chromeos_update_engine

#endif  // UPDATE_ENGINE_CROS_OMAHA_REQUEST_ACTION_H_
