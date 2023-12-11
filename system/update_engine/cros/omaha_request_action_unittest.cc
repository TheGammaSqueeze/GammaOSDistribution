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

#include "update_engine/cros/omaha_request_action.h"

#include <stdint.h>

#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include <base/bind.h>
#include <base/files/file_util.h>
#include <base/files/scoped_temp_dir.h>
#include <base/memory/ptr_util.h>
#include <base/strings/string_number_conversions.h>
#include <base/strings/string_util.h>
#include <base/strings/stringprintf.h>
#include <base/time/time.h>
#include <brillo/message_loops/fake_message_loop.h>
#include <brillo/message_loops/message_loop.h>
#include <brillo/message_loops/message_loop_utils.h>
#include <expat.h>
#include <gtest/gtest.h>
#include <policy/libpolicy.h>
#include <policy/mock_libpolicy.h>

#include "update_engine/common/action_pipe.h"
#include "update_engine/common/constants.h"
#include "update_engine/common/fake_prefs.h"
#include "update_engine/common/hash_calculator.h"
#include "update_engine/common/metrics_reporter_interface.h"
#include "update_engine/common/mock_excluder.h"
#include "update_engine/common/mock_http_fetcher.h"
#include "update_engine/common/platform_constants.h"
#include "update_engine/common/prefs.h"
#include "update_engine/common/test_utils.h"
#include "update_engine/cros/fake_system_state.h"
#include "update_engine/cros/mock_connection_manager.h"
#include "update_engine/cros/mock_payload_state.h"
#include "update_engine/cros/omaha_request_builder_xml.h"
#include "update_engine/cros/omaha_request_params.h"
#include "update_engine/cros/omaha_utils.h"
#include "update_engine/update_manager/rollback_prefs.h"

using base::Time;
using base::TimeDelta;
using chromeos_update_manager::kRollforwardInfinity;
using std::pair;
using std::string;
using std::vector;
using testing::_;
using testing::AllOf;
using testing::AnyNumber;
using testing::DoAll;
using testing::Ge;
using testing::Le;
using testing::NiceMock;
using testing::Return;
using testing::ReturnPointee;
using testing::ReturnRef;
using testing::SaveArg;
using testing::SetArgPointee;
using testing::StrictMock;

namespace {

static_assert(kRollforwardInfinity == 0xfffffffe,
              "Don't change the value of kRollforward infinity unless its "
              "size has been changed in firmware.");

const char kCurrentVersion[] = "0.1.0.0";
const char kTestAppId[] = "test-app-id";
const char kTestAppId2[] = "test-app2-id";
const char kTestAppIdSkipUpdatecheck[] = "test-app-id-skip-updatecheck";
const char kDlcId1[] = "dlc-id-1";
const char kDlcId2[] = "dlc-id-2";

// This is a helper struct to allow unit tests build an update response with the
// values they care about.
struct FakeUpdateResponse {
  string GetRollbackVersionAttributes() const {
    string num_milestones;
    num_milestones = base::NumberToString(rollback_allowed_milestones);
    const string rollback_version =
        " _firmware_version_" + num_milestones + "=\"" +
        past_rollback_key_version.first + "\"" + " _kernel_version_" +
        num_milestones + "=\"" + past_rollback_key_version.second + "\"";

    return (rollback ? " _rollback=\"true\"" : "") + rollback_version +
           (!rollback_firmware_version.empty()
                ? " _firmware_version=\"" + rollback_firmware_version + "\""
                : "") +
           (!rollback_kernel_version.empty()
                ? " _kernel_version=\"" + rollback_kernel_version + "\""
                : "");
  }

  string GetNoUpdateResponse() const {
    string entity_str;
    if (include_entity)
      entity_str = "<!DOCTYPE response [<!ENTITY CrOS \"ChromeOS\">]>";
    return "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" + entity_str +
           "<response protocol=\"3.0\">"
           "<daystart elapsed_seconds=\"100\"/>"
           "<app appid=\"" +
           app_id + "\" " +
           (include_cohorts
                ? "cohort=\"" + cohort + "\" cohorthint=\"" + cohorthint +
                      "\" cohortname=\"" + cohortname + "\" "
                : "") +
           " status=\"ok\">"
           "<ping status=\"ok\"/>"
           "<updatecheck status=\"noupdate\"/></app>" +
           (multi_app_no_update
                ? "<app appid=\"" + app_id2 +
                      "\"><updatecheck status=\"noupdate\"/></app>"
                : "") +
           "</response>";
  }

  string GetUpdateResponse() const {
    chromeos_update_engine::OmahaRequestParams request_params;
    request_params.set_app_id(app_id);
    return "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response "
           "protocol=\"3.0\">"
           "<daystart elapsed_seconds=\"100\"" +
           (elapsed_days.empty() ? ""
                                 : (" elapsed_days=\"" + elapsed_days + "\"")) +
           "/>"
           "<app appid=\"" +
           app_id + "\" " +
           (include_cohorts
                ? "cohort=\"" + cohort + "\" cohorthint=\"" + cohorthint +
                      "\" cohortname=\"" + cohortname + "\" "
                : "") +
           " status=\"ok\">"
           "<ping status=\"ok\"/><updatecheck status=\"ok\"" +
           GetRollbackVersionAttributes() + ">" + "<urls><url codebase=\"" +
           codebase +
           "\"/></urls>"
           "<manifest version=\"" +
           version +
           "\">"
           "<packages><package hash=\"not-used\" name=\"" +
           filename + "\" size=\"" + base::NumberToString(size) + "\" fp=\"" +
           fp + "\" hash_sha256=\"" + hash + "\"/>" +
           (multi_package ? "<package name=\"package2\" size=\"222\" fp=\"" +
                                fp2 + "\" hash_sha256=\"hash2\"/>"
                          : "") +
           "</packages>"
           "<actions><action event=\"postinstall\" MetadataSize=\"11" +
           (multi_package ? ":22" : "") + "\" MoreInfo=\"" + more_info_url +
           "\" Prompt=\"" + prompt +
           "\" "
           "IsDeltaPayload=\"true" +
           (multi_package ? ":false" : "") +
           "\" "
           "MaxDaysToScatter=\"" +
           max_days_to_scatter +
           "\" "
           "sha256=\"not-used\" " +
           (deadline.empty() ? "" : ("deadline=\"" + deadline + "\" ")) +
           (disable_p2p_for_downloading ? "DisableP2PForDownloading=\"true\" "
                                        : "") +
           (disable_p2p_for_sharing ? "DisableP2PForSharing=\"true\" " : "") +
           (powerwash ? "Powerwash=\"true\" " : "") +
           "/></actions></manifest></updatecheck></app>" +
           (multi_app
                ? "<app appid=\"" + app_id2 + "\"" +
                      (include_cohorts ? " cohort=\"cohort2\"" : "") +
                      "><updatecheck status=\"ok\"><urls><url codebase=\"" +
                      codebase2 + "\"/></urls><manifest version=\"" + version2 +
                      "\"><packages>"
                      "<package name=\"package3\" size=\"333\" fp=\"" +
                      fp2 +
                      "\" hash_sha256=\"hash3\"/></packages>"
                      "<actions><action event=\"postinstall\" " +
                      (multi_app_self_update
                           ? "noupdate=\"true\" IsDeltaPayload=\"true\" "
                           : "IsDeltaPayload=\"false\" ") +
                      "MetadataSize=\"33\"/></actions>"
                      "</manifest></updatecheck></app>"
                : "") +
           (multi_app_no_update
                ? "<app><updatecheck status=\"noupdate\"/></app>"
                : "") +
           (multi_app_skip_updatecheck
                ? "<app appid=\"" + app_id_skip_updatecheck + "\"></app>"
                : "") +
           (dlc_app_update
                ? "<app appid=\"" + request_params.GetDlcAppId(kDlcId1) +
                      "\" " +
                      (include_dlc_cohorts
                           ? "cohort=\"" + dlc_cohort + "\" cohorthint=\"" +
                                 dlc_cohorthint + "\" cohortname=\"" +
                                 dlc_cohortname + "\" "
                           : "") +
                      "status=\"ok\">"
                      "<updatecheck status=\"ok\"><urls><url codebase=\"" +
                      codebase + "\"/><url codebase=\"" + codebase2 +
                      "\"/></urls><manifest version=\"" + version +
                      "\"><packages><package name=\"package3\" size=\"333\" "
                      "fp=\"" +
                      fp2 +
                      "\" hash_sha256=\"hash3\"/></packages>"
                      "<actions><action event=\"install\" run=\".signed\"/>"
                      "<action event=\"postinstall\" MetadataSize=\"33\"/>"
                      "</actions></manifest></updatecheck></app>"
                : "") +
           (dlc_app_no_update
                ? "<app appid=\"" + request_params.GetDlcAppId(kDlcId2) +
                      +"\" " +
                      (include_dlc_cohorts
                           ? "cohort=\"" + dlc_cohort + "\" cohorthint=\"" +
                                 dlc_cohorthint + "\" cohortname=\"" +
                                 dlc_cohortname + "\" "
                           : "") +
                      "><updatecheck status=\"noupdate\"/></app>"
                : "") +
           "</response>";
  }

  // Return the payload URL, which is split in two fields in the XML response.
  string GetPayloadUrl() { return codebase + filename; }

  string app_id = kTestAppId;
  string app_id2 = kTestAppId2;
  string app_id_skip_updatecheck = kTestAppIdSkipUpdatecheck;
  string version = "1.2.3.4";
  string version2 = "2.3.4.5";
  string more_info_url = "http://more/info";
  string prompt = "true";
  string codebase = "http://code/base/";
  string codebase2 = "http://code/base/2/";
  string filename = "file.signed";
  string hash = "4841534831323334";
  string fp = "3.98ba213e";
  string fp2 = "3.755aff78e";
  uint64_t size = 123;
  string deadline = "";
  string max_days_to_scatter = "7";
  string elapsed_days = "42";

  // P2P setting defaults to allowed.
  bool disable_p2p_for_downloading = false;
  bool disable_p2p_for_sharing = false;

  bool powerwash = false;

  // Omaha cohorts settings.
  bool include_cohorts = false;
  string cohort = "";
  string cohorthint = "";
  string cohortname = "";
  // Whether to include Omaha cohorts for DLC apps.
  bool include_dlc_cohorts = false;
  string dlc_cohort = "";
  string dlc_cohorthint = "";
  string dlc_cohortname = "";

  // Whether to include the CrOS <!ENTITY> in the XML response.
  bool include_entity = false;

  // Whether to include more than one app.
  bool multi_app = false;
  // Whether to include an app with noupdate="true".
  bool multi_app_self_update = false;
  // Whether to include an additional app with status="noupdate".
  bool multi_app_no_update = false;
  // Whether to include an additional app with no updatecheck tag.
  bool multi_app_skip_updatecheck = false;
  // Whether to include more than one package in an app.
  bool multi_package = false;
  // Whether to include a DLC app with updatecheck tag.
  bool dlc_app_update = false;
  // Whether to include a DLC app with no updatecheck tag.
  bool dlc_app_no_update = false;

  // Whether the payload is a rollback.
  bool rollback = false;
  // The verified boot firmware key version for the rollback image.
  string rollback_firmware_version = "";
  // The verified boot kernel key version for the rollback image.
  string rollback_kernel_version = "";
  // The number of milestones back that the verified boot key version has been
  // supplied.
  uint32_t rollback_allowed_milestones = 0;
  // The verified boot key version for the
  // |current - rollback_allowed_milestones| most recent release.
  // The pair contains <firmware_key_version, kernel_key_version> each
  // of which is in the form "key_version.version".
  pair<string, string> past_rollback_key_version;
};

}  // namespace

namespace chromeos_update_engine {

class OmahaRequestActionTestProcessorDelegate : public ActionProcessorDelegate {
 public:
  OmahaRequestActionTestProcessorDelegate()
      : expected_code_(ErrorCode::kSuccess),
        interactive_(false),
        test_http_fetcher_headers_(false) {}
  ~OmahaRequestActionTestProcessorDelegate() override = default;

  void ProcessingDone(const ActionProcessor* processor,
                      ErrorCode code) override {
    brillo::MessageLoop::current()->BreakLoop();
  }

  void ActionCompleted(ActionProcessor* processor,
                       AbstractAction* action,
                       ErrorCode code) override {
    // Make sure actions always succeed.
    if (action->Type() == OmahaRequestAction::StaticType()) {
      EXPECT_EQ(expected_code_, code);
      // Check that the headers were set in the fetcher during the action. Note
      // that we set this request as "interactive".
      auto fetcher = static_cast<const MockHttpFetcher*>(
          static_cast<OmahaRequestAction*>(action)->http_fetcher_.get());

      if (test_http_fetcher_headers_) {
        EXPECT_EQ(interactive_ ? "fg" : "bg",
                  fetcher->GetHeader("X-Goog-Update-Interactivity"));
        EXPECT_EQ(kTestAppId, fetcher->GetHeader("X-Goog-Update-AppId"));
        EXPECT_NE("", fetcher->GetHeader("X-Goog-Update-Updater"));
      }
      post_data_ = fetcher->post_data();
    } else if (action->Type() ==
               ObjectCollectorAction<OmahaResponse>::StaticType()) {
      EXPECT_EQ(ErrorCode::kSuccess, code);
      auto collector_action =
          static_cast<ObjectCollectorAction<OmahaResponse>*>(action);
      omaha_response_.reset(new OmahaResponse(collector_action->object()));
      EXPECT_TRUE(omaha_response_);
    } else {
      EXPECT_EQ(ErrorCode::kSuccess, code);
    }
  }
  ErrorCode expected_code_;
  brillo::Blob post_data_;
  bool interactive_;
  bool test_http_fetcher_headers_;
  std::unique_ptr<OmahaResponse> omaha_response_;
};

struct TestUpdateCheckParams {
  string http_response;
  int fail_http_response_code;
  bool ping_only;
  bool is_consumer_device;
  int rollback_allowed_milestones;
  bool is_policy_loaded;
  ErrorCode expected_code;
  metrics::CheckResult expected_check_result;
  metrics::CheckReaction expected_check_reaction;
  metrics::DownloadErrorCode expected_download_error_code;
  string session_id;
};

class OmahaRequestActionTest : public ::testing::Test {
 protected:
  void SetUp() override {
    FakeSystemState::CreateInstance();

    request_params_.set_os_sp("service_pack");
    request_params_.set_os_board("x86-generic");
    request_params_.set_app_id(kTestAppId);
    request_params_.set_app_version(kCurrentVersion);
    request_params_.set_app_lang("en-US");
    request_params_.set_current_channel("unittest");
    request_params_.set_target_channel("unittest");
    request_params_.set_hwid("OEM MODEL 09235 7471");
    request_params_.set_delta_okay(true);
    request_params_.set_interactive(false);
    request_params_.set_update_url("http://url");
    request_params_.set_target_version_prefix("");
    request_params_.set_rollback_allowed(false);
    request_params_.set_is_powerwash_allowed(false);
    request_params_.set_is_install(false);
    request_params_.set_dlc_apps_params({});

    FakeSystemState::Get()->set_request_params(&request_params_);
    fake_prefs_ = FakeSystemState::Get()->fake_prefs();

    // Setting the default update check params. Lookup |TestUpdateCheck()|.
    tuc_params_ = {
        .http_response = "",
        .fail_http_response_code = -1,
        .ping_only = false,
        .is_consumer_device = true,
        .rollback_allowed_milestones = 0,
        .is_policy_loaded = false,
        .expected_code = ErrorCode::kSuccess,
        .expected_check_result = metrics::CheckResult::kUpdateAvailable,
        .expected_check_reaction = metrics::CheckReaction::kUpdating,
        .expected_download_error_code = metrics::DownloadErrorCode::kUnset,
    };

    ON_CALL(*FakeSystemState::Get()->mock_update_attempter(), GetExcluder())
        .WillByDefault(Return(&mock_excluder_));
  }

  // This function uses the parameters in |tuc_params_| to do an update check.
  // It will fill out |post_str_| with the result data and |response| with
  // |OmahaResponse|. Returns true iff an output response was obtained from the
  // |OmahaRequestAction|. If |fail_http_response_code| is non-negative, the
  // transfer will fail with that code. |ping_only| is passed through to the
  // |OmahaRequestAction| constructor.
  //
  // The |expected_check_result|, |expected_check_reaction| and
  // |expected_error_code| parameters are for checking expectations about
  // reporting UpdateEngine.Check.{Result,Reaction,DownloadError} UMA
  // statistics. Use the appropriate ::kUnset value to specify that the given
  // metric should not be reported.
  bool TestUpdateCheck();

  // Tests events using |event| and |https_response|. It will fill up
  // |post_str_| with the result data.
  void TestEvent(OmahaEvent* event, const string& http_response);

  // Runs and checks a ping test. |ping_only| indicates whether it should send
  // only a ping or also an updatecheck.
  void PingTest(bool ping_only);

  // InstallDate test helper function.
  bool InstallDateParseHelper(const string& elapsed_days,
                              OmahaResponse* response);

  // P2P test helper function.
  void P2PTest(bool initial_allow_p2p_for_downloading,
               bool initial_allow_p2p_for_sharing,
               bool omaha_disable_p2p_for_downloading,
               bool omaha_disable_p2p_for_sharing,
               bool payload_state_allow_p2p_attempt,
               bool expect_p2p_client_lookup,
               const string& p2p_client_result_url,
               bool expected_allow_p2p_for_downloading,
               bool expected_allow_p2p_for_sharing,
               const string& expected_p2p_url);

  StrictMock<MockExcluder> mock_excluder_;
  FakeUpdateResponse fake_update_response_;
  // Used by all tests.
  OmahaRequestParams request_params_;

  FakePrefs* fake_prefs_;

  OmahaRequestActionTestProcessorDelegate delegate_;

  bool test_http_fetcher_headers_{false};

  TestUpdateCheckParams tuc_params_;

  OmahaResponse response_;
  string post_str_;
};

class OmahaRequestActionDlcPingTest : public OmahaRequestActionTest {
 protected:
  void SetUp() override {
    OmahaRequestActionTest::SetUp();
    dlc_id_ = "dlc0";
    active_key_ = PrefsInterface::CreateSubKey(
        {kDlcPrefsSubDir, dlc_id_, kPrefsPingActive});
    last_active_key_ = PrefsInterface::CreateSubKey(
        {kDlcPrefsSubDir, dlc_id_, kPrefsPingLastActive});
    last_rollcall_key_ = PrefsInterface::CreateSubKey(
        {kDlcPrefsSubDir, dlc_id_, kPrefsPingLastRollcall});

    tuc_params_.http_response =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response "
        "protocol=\"3.0\"><daystart elapsed_days=\"4763\" "
        "elapsed_seconds=\"36540\"/><app appid=\"test-app-id\" status=\"ok\">\""
        "<updatecheck status=\"noupdate\"/></app><app "
        "appid=\"test-app-id_dlc0\" "
        "status=\"ok\"><ping status=\"ok\"/><updatecheck status=\"noupdate\"/>"
        "</app></response>";
    tuc_params_.expected_check_result =
        metrics::CheckResult::kNoUpdateAvailable;
    tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;
  }

  std::string dlc_id_;
  std::string active_key_;
  std::string last_active_key_;
  std::string last_rollcall_key_;
};

bool OmahaRequestActionTest::TestUpdateCheck() {
  brillo::FakeMessageLoop loop(nullptr);
  loop.SetAsCurrent();
  auto fetcher =
      std::make_unique<MockHttpFetcher>(tuc_params_.http_response.data(),
                                        tuc_params_.http_response.size(),
                                        nullptr);
  if (tuc_params_.fail_http_response_code >= 0) {
    fetcher->FailTransfer(tuc_params_.fail_http_response_code);
  }
  // This ensures the tests didn't forget to update |FakeSystemState| if they
  // are not using the default |request_params_|.
  EXPECT_EQ(&request_params_, FakeSystemState::Get()->request_params());

  auto omaha_request_action =
      std::make_unique<OmahaRequestAction>(nullptr,
                                           std::move(fetcher),
                                           tuc_params_.ping_only,
                                           tuc_params_.session_id);

  auto mock_policy_provider =
      std::make_unique<NiceMock<policy::MockPolicyProvider>>();
  EXPECT_CALL(*mock_policy_provider, IsConsumerDevice())
      .WillRepeatedly(Return(tuc_params_.is_consumer_device));

  EXPECT_CALL(*mock_policy_provider, device_policy_is_loaded())
      .WillRepeatedly(Return(tuc_params_.is_policy_loaded));

  const policy::MockDevicePolicy device_policy;
  const bool get_allowed_milestone_succeeds =
      tuc_params_.rollback_allowed_milestones >= 0;
  EXPECT_CALL(device_policy, GetRollbackAllowedMilestones(_))
      .WillRepeatedly(
          DoAll(SetArgPointee<0>(tuc_params_.rollback_allowed_milestones),
                Return(get_allowed_milestone_succeeds)));

  EXPECT_CALL(*mock_policy_provider, GetDevicePolicy())
      .WillRepeatedly(ReturnRef(device_policy));
  omaha_request_action->policy_provider_ = std::move(mock_policy_provider);

  delegate_.expected_code_ = tuc_params_.expected_code;
  delegate_.interactive_ = request_params_.interactive();
  delegate_.test_http_fetcher_headers_ = test_http_fetcher_headers_;
  ActionProcessor processor;
  processor.set_delegate(&delegate_);

  auto collector_action =
      std::make_unique<ObjectCollectorAction<OmahaResponse>>();
  BondActions(omaha_request_action.get(), collector_action.get());
  processor.EnqueueAction(std::move(omaha_request_action));
  processor.EnqueueAction(std::move(collector_action));

  EXPECT_CALL(*FakeSystemState::Get()->mock_metrics_reporter(),
              ReportUpdateCheckMetrics(_, _, _))
      .Times(AnyNumber());

  EXPECT_CALL(
      *FakeSystemState::Get()->mock_metrics_reporter(),
      ReportUpdateCheckMetrics(tuc_params_.expected_check_result,
                               tuc_params_.expected_check_reaction,
                               tuc_params_.expected_download_error_code))
      .Times(tuc_params_.ping_only ? 0 : 1);

  loop.PostTask(base::Bind(
      [](ActionProcessor* processor) { processor->StartProcessing(); },
      base::Unretained(&processor)));
  loop.Run();
  EXPECT_FALSE(loop.PendingTasks());
  if (delegate_.omaha_response_)
    response_ = *delegate_.omaha_response_;
  post_str_ = string(delegate_.post_data_.begin(), delegate_.post_data_.end());
  return delegate_.omaha_response_ != nullptr;
}

// Tests Event requests -- they should always succeed. |out_post_data| may be
// null; if non-null, the post-data received by the mock HttpFetcher is
// returned.
void OmahaRequestActionTest::TestEvent(OmahaEvent* event,
                                       const string& http_response) {
  brillo::FakeMessageLoop loop(nullptr);
  loop.SetAsCurrent();

  auto action = std::make_unique<OmahaRequestAction>(
      event,
      std::make_unique<MockHttpFetcher>(
          http_response.data(), http_response.size(), nullptr),
      false,
      "");
  ActionProcessor processor;
  processor.set_delegate(&delegate_);
  processor.EnqueueAction(std::move(action));

  loop.PostTask(base::Bind(
      [](ActionProcessor* processor) { processor->StartProcessing(); },
      base::Unretained(&processor)));
  loop.Run();
  EXPECT_FALSE(loop.PendingTasks());

  post_str_ = string(delegate_.post_data_.begin(), delegate_.post_data_.end());
}

TEST_F(OmahaRequestActionTest, RejectEntities) {
  fake_update_response_.include_entity = true;
  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLHasEntityDecl;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, NoUpdateTest) {
  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, MultiAppNoUpdateTest) {
  fake_update_response_.multi_app_no_update = true;
  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, MultiAppNoPartialUpdateTest) {
  fake_update_response_.multi_app_no_update = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, NoSelfUpdateTest) {
  tuc_params_.http_response =
      "<response><app><updatecheck status=\"ok\"><manifest><actions><action "
      "event=\"postinstall\" noupdate=\"true\"/></actions>"
      "</manifest></updatecheck></app></response>";
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

// Test that all the values in the response are parsed in a normal update
// response_.
TEST_F(OmahaRequestActionTest, ValidUpdateTest) {
  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ(fake_update_response_.version, response_.version);
  EXPECT_EQ(fake_update_response_.GetPayloadUrl(),
            response_.packages[0].payload_urls[0]);
  EXPECT_EQ(fake_update_response_.more_info_url, response_.more_info_url);
  EXPECT_EQ(fake_update_response_.hash, response_.packages[0].hash);
  EXPECT_EQ(fake_update_response_.size, response_.packages[0].size);
  EXPECT_EQ(fake_update_response_.fp, response_.packages[0].fp);
  EXPECT_EQ(true, response_.packages[0].is_delta);
  EXPECT_EQ(fake_update_response_.prompt == "true", response_.prompt);
  EXPECT_EQ(fake_update_response_.deadline, response_.deadline);
  EXPECT_FALSE(response_.powerwash_required);
  // Omaha cohort attributes are not set in the response, so they should not be
  // persisted.
  EXPECT_FALSE(fake_prefs_->Exists(kPrefsOmahaCohort));
  EXPECT_FALSE(fake_prefs_->Exists(kPrefsOmahaCohortHint));
  EXPECT_FALSE(fake_prefs_->Exists(kPrefsOmahaCohortName));
}

TEST_F(OmahaRequestActionTest, MultiPackageUpdateTest) {
  fake_update_response_.multi_package = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ(fake_update_response_.version, response_.version);
  EXPECT_EQ(fake_update_response_.GetPayloadUrl(),
            response_.packages[0].payload_urls[0]);
  EXPECT_EQ(fake_update_response_.codebase + "package2",
            response_.packages[1].payload_urls[0]);
  EXPECT_EQ(fake_update_response_.hash, response_.packages[0].hash);
  EXPECT_EQ(fake_update_response_.size, response_.packages[0].size);
  EXPECT_EQ(fake_update_response_.fp, response_.packages[0].fp);
  EXPECT_EQ(true, response_.packages[0].is_delta);
  EXPECT_EQ(11u, response_.packages[0].metadata_size);
  ASSERT_EQ(2u, response_.packages.size());
  EXPECT_EQ(string("hash2"), response_.packages[1].hash);
  EXPECT_EQ(222u, response_.packages[1].size);
  EXPECT_EQ(fake_update_response_.fp2, response_.packages[1].fp);
  EXPECT_EQ(22u, response_.packages[1].metadata_size);
  EXPECT_EQ(false, response_.packages[1].is_delta);
}

TEST_F(OmahaRequestActionTest, MultiAppUpdateTest) {
  fake_update_response_.multi_app = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ(fake_update_response_.version, response_.version);
  EXPECT_EQ(fake_update_response_.GetPayloadUrl(),
            response_.packages[0].payload_urls[0]);
  EXPECT_EQ(fake_update_response_.codebase2 + "package3",
            response_.packages[1].payload_urls[0]);
  EXPECT_EQ(fake_update_response_.hash, response_.packages[0].hash);
  EXPECT_EQ(fake_update_response_.size, response_.packages[0].size);
  EXPECT_EQ(fake_update_response_.fp, response_.packages[0].fp);
  EXPECT_EQ(11u, response_.packages[0].metadata_size);
  EXPECT_EQ(true, response_.packages[0].is_delta);
  ASSERT_EQ(2u, response_.packages.size());
  EXPECT_EQ(string("hash3"), response_.packages[1].hash);
  EXPECT_EQ(333u, response_.packages[1].size);
  EXPECT_EQ(fake_update_response_.fp2, response_.packages[1].fp);
  EXPECT_EQ(33u, response_.packages[1].metadata_size);
  EXPECT_EQ(false, response_.packages[1].is_delta);
}

TEST_F(OmahaRequestActionTest, MultiAppPartialUpdateTest) {
  fake_update_response_.multi_app = true;
  fake_update_response_.multi_app_self_update = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ(fake_update_response_.version, response_.version);
  EXPECT_EQ(fake_update_response_.GetPayloadUrl(),
            response_.packages[0].payload_urls[0]);
  EXPECT_EQ(fake_update_response_.hash, response_.packages[0].hash);
  EXPECT_EQ(fake_update_response_.size, response_.packages[0].size);
  EXPECT_EQ(fake_update_response_.fp, response_.packages[0].fp);
  EXPECT_EQ(11u, response_.packages[0].metadata_size);
  ASSERT_EQ(2u, response_.packages.size());
  EXPECT_EQ(string("hash3"), response_.packages[1].hash);
  EXPECT_EQ(333u, response_.packages[1].size);
  EXPECT_EQ(fake_update_response_.fp2, response_.packages[1].fp);
  EXPECT_EQ(33u, response_.packages[1].metadata_size);
  EXPECT_EQ(true, response_.packages[1].is_delta);
}

TEST_F(OmahaRequestActionTest, MultiAppMultiPackageUpdateTest) {
  fake_update_response_.multi_app = true;
  fake_update_response_.multi_package = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ(fake_update_response_.version, response_.version);
  EXPECT_EQ(fake_update_response_.GetPayloadUrl(),
            response_.packages[0].payload_urls[0]);
  EXPECT_EQ(fake_update_response_.codebase + "package2",
            response_.packages[1].payload_urls[0]);
  EXPECT_EQ(fake_update_response_.codebase2 + "package3",
            response_.packages[2].payload_urls[0]);
  EXPECT_EQ(fake_update_response_.hash, response_.packages[0].hash);
  EXPECT_EQ(fake_update_response_.size, response_.packages[0].size);
  EXPECT_EQ(fake_update_response_.fp, response_.packages[0].fp);
  EXPECT_EQ(11u, response_.packages[0].metadata_size);
  EXPECT_EQ(true, response_.packages[0].is_delta);
  ASSERT_EQ(3u, response_.packages.size());
  EXPECT_EQ(string("hash2"), response_.packages[1].hash);
  EXPECT_EQ(222u, response_.packages[1].size);
  EXPECT_EQ(fake_update_response_.fp2, response_.packages[1].fp);
  EXPECT_EQ(22u, response_.packages[1].metadata_size);
  EXPECT_EQ(false, response_.packages[1].is_delta);
  EXPECT_EQ(string("hash3"), response_.packages[2].hash);
  EXPECT_EQ(333u, response_.packages[2].size);
  EXPECT_EQ(fake_update_response_.fp2, response_.packages[2].fp);
  EXPECT_EQ(33u, response_.packages[2].metadata_size);
  EXPECT_EQ(false, response_.packages[2].is_delta);
}

TEST_F(OmahaRequestActionTest, PowerwashTest) {
  fake_update_response_.powerwash = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
  EXPECT_TRUE(response_.powerwash_required);
}

TEST_F(OmahaRequestActionTest, ExtraHeadersSentInteractiveTest) {
  request_params_.set_interactive(true);
  test_http_fetcher_headers_ = true;
  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, ExtraHeadersSentNoInteractiveTest) {
  request_params_.set_interactive(false);
  test_http_fetcher_headers_ = true;
  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, ValidUpdateBlockedByConnection) {
  // Set up a connection manager that doesn't allow a valid update over
  // the current ethernet connection.
  MockConnectionManager mock_cm;
  FakeSystemState::Get()->set_connection_manager(&mock_cm);

  EXPECT_CALL(mock_cm, GetConnectionProperties(_, _))
      .WillRepeatedly(DoAll(SetArgPointee<0>(ConnectionType::kEthernet),
                            SetArgPointee<1>(ConnectionTethering::kUnknown),
                            Return(true)));
  EXPECT_CALL(mock_cm, IsUpdateAllowedOver(ConnectionType::kEthernet, _))
      .WillRepeatedly(Return(false));

  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kOmahaUpdateIgnoredPerPolicy;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kIgnored;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, ValidUpdateOverCellularAllowedByDevicePolicy) {
  // This test tests that update over cellular is allowed as device policy
  // says yes.
  MockConnectionManager mock_cm;
  FakeSystemState::Get()->set_connection_manager(&mock_cm);

  EXPECT_CALL(mock_cm, GetConnectionProperties(_, _))
      .WillRepeatedly(DoAll(SetArgPointee<0>(ConnectionType::kCellular),
                            SetArgPointee<1>(ConnectionTethering::kUnknown),
                            Return(true)));
  EXPECT_CALL(mock_cm, IsAllowedConnectionTypesForUpdateSet())
      .WillRepeatedly(Return(true));
  EXPECT_CALL(mock_cm, IsUpdateAllowedOver(ConnectionType::kCellular, _))
      .WillRepeatedly(Return(true));

  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, ValidUpdateOverCellularBlockedByDevicePolicy) {
  // This test tests that update over cellular is blocked as device policy
  // says no.
  MockConnectionManager mock_cm;
  FakeSystemState::Get()->set_connection_manager(&mock_cm);

  EXPECT_CALL(mock_cm, GetConnectionProperties(_, _))
      .WillRepeatedly(DoAll(SetArgPointee<0>(ConnectionType::kCellular),
                            SetArgPointee<1>(ConnectionTethering::kUnknown),
                            Return(true)));
  EXPECT_CALL(mock_cm, IsAllowedConnectionTypesForUpdateSet())
      .WillRepeatedly(Return(true));
  EXPECT_CALL(mock_cm, IsUpdateAllowedOver(ConnectionType::kCellular, _))
      .WillRepeatedly(Return(false));

  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kOmahaUpdateIgnoredPerPolicy;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kIgnored;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest,
       ValidUpdateOverCellularAllowedByUserPermissionTrue) {
  // This test tests that, when device policy is not set, update over cellular
  // is allowed as permission for update over cellular is set to true.
  MockConnectionManager mock_cm;
  fake_prefs_->SetBoolean(kPrefsUpdateOverCellularPermission, true);
  FakeSystemState::Get()->set_connection_manager(&mock_cm);

  EXPECT_CALL(mock_cm, GetConnectionProperties(_, _))
      .WillRepeatedly(DoAll(SetArgPointee<0>(ConnectionType::kCellular),
                            SetArgPointee<1>(ConnectionTethering::kUnknown),
                            Return(true)));
  EXPECT_CALL(mock_cm, IsAllowedConnectionTypesForUpdateSet())
      .WillRepeatedly(Return(false));
  EXPECT_CALL(mock_cm, IsUpdateAllowedOver(ConnectionType::kCellular, _))
      .WillRepeatedly(Return(true));

  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest,
       ValidUpdateOverCellularBlockedByUpdateTargetNotMatch) {
  // This test tests that, when device policy is not set and permission for
  // update over cellular is set to false or does not exist, update over
  // cellular is blocked as update target does not match the omaha response.
  MockConnectionManager mock_cm;
  // A version different from the version in omaha response.
  string diff_version = "99.99.99";
  // A size different from the size in omaha response.
  int64_t diff_size = 999;

  fake_prefs_->SetString(kPrefsUpdateOverCellularTargetVersion, diff_version);
  fake_prefs_->SetInt64(kPrefsUpdateOverCellularTargetSize, diff_size);
  // This test tests cellular (3G) being the only connection type being allowed.
  FakeSystemState::Get()->set_connection_manager(&mock_cm);

  EXPECT_CALL(mock_cm, GetConnectionProperties(_, _))
      .WillRepeatedly(DoAll(SetArgPointee<0>(ConnectionType::kCellular),
                            SetArgPointee<1>(ConnectionTethering::kUnknown),
                            Return(true)));
  EXPECT_CALL(mock_cm, IsAllowedConnectionTypesForUpdateSet())
      .WillRepeatedly(Return(false));
  EXPECT_CALL(mock_cm, IsUpdateAllowedOver(ConnectionType::kCellular, _))
      .WillRepeatedly(Return(true));

  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kOmahaUpdateIgnoredOverCellular;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kIgnored;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest,
       ValidUpdateOverCellularAllowedByUpdateTargetMatch) {
  // This test tests that, when device policy is not set and permission for
  // update over cellular is set to false or does not exist, update over
  // cellular is allowed as update target matches the omaha response.
  MockConnectionManager mock_cm;
  // A version same as the version in omaha response.
  string new_version = fake_update_response_.version;
  // A size same as the size in omaha response.
  int64_t new_size = fake_update_response_.size;

  fake_prefs_->SetString(kPrefsUpdateOverCellularTargetVersion, new_version);
  fake_prefs_->SetInt64(kPrefsUpdateOverCellularTargetSize, new_size);
  FakeSystemState::Get()->set_connection_manager(&mock_cm);

  EXPECT_CALL(mock_cm, GetConnectionProperties(_, _))
      .WillRepeatedly(DoAll(SetArgPointee<0>(ConnectionType::kCellular),
                            SetArgPointee<1>(ConnectionTethering::kUnknown),
                            Return(true)));
  EXPECT_CALL(mock_cm, IsAllowedConnectionTypesForUpdateSet())
      .WillRepeatedly(Return(false));
  EXPECT_CALL(mock_cm, IsUpdateAllowedOver(ConnectionType::kCellular, _))
      .WillRepeatedly(Return(true));

  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, ValidUpdateBlockedByRollback) {
  string rollback_version = "1234.0.0";
  MockPayloadState mock_payload_state;
  FakeSystemState::Get()->set_payload_state(&mock_payload_state);
  fake_update_response_.version = rollback_version;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kOmahaUpdateIgnoredPerPolicy;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kIgnored;

  EXPECT_CALL(mock_payload_state, GetRollbackVersion())
      .WillRepeatedly(Return(rollback_version));

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

// Verify that update checks called during OOBE will not try to download an
// update if the response doesn't include the deadline field.
TEST_F(OmahaRequestActionTest, SkipNonCriticalUpdatesBeforeOOBE) {
  FakeSystemState::Get()->fake_hardware()->UnsetIsOOBEComplete();
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kNonCriticalUpdateInOOBE;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  // TODO(senj): set better default value for metrics::checkresult in
  // OmahaRequestAction::ActionCompleted.
  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

// Verify that the IsOOBEComplete() value is ignored when the OOBE flow is not
// enabled.
TEST_F(OmahaRequestActionTest, SkipNonCriticalUpdatesBeforeOOBEDisabled) {
  FakeSystemState::Get()->fake_hardware()->UnsetIsOOBEComplete();
  FakeSystemState::Get()->fake_hardware()->SetIsOOBEEnabled(false);
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

// Verify that update checks called during OOBE will still try to download an
// update if the response includes the deadline field.
TEST_F(OmahaRequestActionTest, SkipNonCriticalUpdatesBeforeOOBEDeadlineSet) {
  FakeSystemState::Get()->fake_hardware()->UnsetIsOOBEComplete();
  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

// Verify that update checks called during OOBE will not try to download an
// update if a rollback happened, even when the response includes the deadline
// field.
TEST_F(OmahaRequestActionTest, SkipNonCriticalUpdatesBeforeOOBERollback) {
  FakeSystemState::Get()->fake_hardware()->UnsetIsOOBEComplete();
  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kNonCriticalUpdateInOOBE;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  EXPECT_CALL(*(FakeSystemState::Get()->mock_payload_state()),
              GetRollbackHappened())
      .WillOnce(Return(true));

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

// Verify that non-critical updates are skipped by reporting the
// kNonCriticalUpdateInOOBE error code when attempted over cellular network -
// i.e. when the update would need user permission. Note that reporting
// kOmahaUpdateIgnoredOverCellular error in this case  might cause undesired UX
// in OOBE (warning the user about an update that will be skipped).
TEST_F(OmahaRequestActionTest, SkipNonCriticalUpdatesInOOBEOverCellular) {
  FakeSystemState::Get()->fake_hardware()->UnsetIsOOBEComplete();

  MockConnectionManager mock_cm;
  FakeSystemState::Get()->set_connection_manager(&mock_cm);
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kNonCriticalUpdateInOOBE;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  EXPECT_CALL(mock_cm, GetConnectionProperties(_, _))
      .WillRepeatedly(DoAll(SetArgPointee<0>(ConnectionType::kCellular),
                            SetArgPointee<1>(ConnectionTethering::kUnknown),
                            Return(true)));
  EXPECT_CALL(mock_cm, IsAllowedConnectionTypesForUpdateSet())
      .WillRepeatedly(Return(false));

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, WallClockBasedWaitAloneCausesScattering) {
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_update_check_count_wait_enabled(false);
  request_params_.set_waiting_period(TimeDelta::FromDays(2));
  FakeSystemState::Get()->fake_clock()->SetWallclockTime(Time::Now());
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kOmahaUpdateDeferredPerPolicy;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kDeferring;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest,
       WallClockBasedWaitAloneCausesScatteringInteractive) {
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_update_check_count_wait_enabled(false);
  request_params_.set_waiting_period(TimeDelta::FromDays(2));
  request_params_.set_interactive(true);
  FakeSystemState::Get()->fake_clock()->SetWallclockTime(Time::Now());
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  // Verify if we are interactive check we don't defer.
  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, NoWallClockBasedWaitCausesNoScattering) {
  request_params_.set_wall_clock_based_wait_enabled(false);
  request_params_.set_waiting_period(TimeDelta::FromDays(2));
  request_params_.set_update_check_count_wait_enabled(true);
  request_params_.set_min_update_checks_needed(1);
  request_params_.set_max_update_checks_allowed(8);
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, ZeroMaxDaysToScatterCausesNoScattering) {
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_waiting_period(TimeDelta::FromDays(2));
  request_params_.set_update_check_count_wait_enabled(true);
  request_params_.set_min_update_checks_needed(1);
  request_params_.set_max_update_checks_allowed(8);
  fake_update_response_.max_days_to_scatter = "0";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, ZeroUpdateCheckCountCausesNoScattering) {
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_waiting_period(TimeDelta());
  request_params_.set_update_check_count_wait_enabled(true);
  request_params_.set_min_update_checks_needed(0);
  request_params_.set_max_update_checks_allowed(0);
  FakeSystemState::Get()->fake_clock()->SetWallclockTime(Time::Now());
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  int64_t count;
  ASSERT_TRUE(fake_prefs_->GetInt64(kPrefsUpdateCheckCount, &count));
  ASSERT_EQ(count, 0);
  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, NonZeroUpdateCheckCountCausesScattering) {
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_waiting_period(TimeDelta());
  request_params_.set_update_check_count_wait_enabled(true);
  request_params_.set_min_update_checks_needed(1);
  request_params_.set_max_update_checks_allowed(8);
  FakeSystemState::Get()->fake_clock()->SetWallclockTime(Time::Now());
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kOmahaUpdateDeferredPerPolicy;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kDeferring;

  ASSERT_FALSE(TestUpdateCheck());

  int64_t count;
  ASSERT_TRUE(fake_prefs_->GetInt64(kPrefsUpdateCheckCount, &count));
  ASSERT_GT(count, 0);
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest,
       NonZeroUpdateCheckCountCausesScatteringInteractive) {
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_waiting_period(TimeDelta());
  request_params_.set_update_check_count_wait_enabled(true);
  request_params_.set_min_update_checks_needed(1);
  request_params_.set_max_update_checks_allowed(8);
  request_params_.set_interactive(true);
  FakeSystemState::Get()->fake_clock()->SetWallclockTime(Time::Now());
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  // Verify if we are interactive check we don't defer.
  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, ExistingUpdateCheckCountCausesScattering) {
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_waiting_period(TimeDelta());
  request_params_.set_update_check_count_wait_enabled(true);
  request_params_.set_min_update_checks_needed(1);
  request_params_.set_max_update_checks_allowed(8);
  FakeSystemState::Get()->fake_clock()->SetWallclockTime(Time::Now());
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kOmahaUpdateDeferredPerPolicy;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kDeferring;

  ASSERT_TRUE(fake_prefs_->SetInt64(kPrefsUpdateCheckCount, 5));
  ASSERT_FALSE(TestUpdateCheck());

  int64_t count;
  ASSERT_TRUE(fake_prefs_->GetInt64(kPrefsUpdateCheckCount, &count));
  // |count| remains the same, as the decrementing happens in update_attempter
  // which this test doesn't exercise.
  ASSERT_EQ(count, 5);
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest,
       ExistingUpdateCheckCountCausesScatteringInteractive) {
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_waiting_period(TimeDelta());
  request_params_.set_update_check_count_wait_enabled(true);
  request_params_.set_min_update_checks_needed(1);
  request_params_.set_max_update_checks_allowed(8);
  request_params_.set_interactive(true);
  FakeSystemState::Get()->fake_clock()->SetWallclockTime(Time::Now());
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(fake_prefs_->SetInt64(kPrefsUpdateCheckCount, 5));

  // Verify if we are interactive check we don't defer.
  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, StagingTurnedOnCausesScattering) {
  // If staging is on, the value for max days to scatter should be ignored, and
  // staging's scatter value should be used.
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_waiting_period(TimeDelta::FromDays(6));
  request_params_.set_update_check_count_wait_enabled(false);
  FakeSystemState::Get()->fake_clock()->SetWallclockTime(Time::Now());

  ASSERT_TRUE(fake_prefs_->SetInt64(kPrefsWallClockStagingWaitPeriod, 6));
  // This should not prevent scattering due to staging.
  fake_update_response_.max_days_to_scatter = "0";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kOmahaUpdateDeferredPerPolicy;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kDeferring;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);

  // Interactive updates should not be affected.
  request_params_.set_interactive(true);
  tuc_params_.expected_code = ErrorCode::kSuccess;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUpdating;

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, CohortsArePersisted) {
  fake_update_response_.include_cohorts = true;
  fake_update_response_.cohort = "s/154454/8479665";
  fake_update_response_.cohorthint = "please-put-me-on-beta";
  fake_update_response_.cohortname = "stable";
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(kDlcId1), {.name = kDlcId1}}});
  fake_update_response_.dlc_app_update = true;
  fake_update_response_.include_dlc_cohorts = true;
  fake_update_response_.dlc_cohort = "s/154454/8479665/dlc";
  fake_update_response_.dlc_cohorthint = "please-put-me-on-beta-dlc";
  fake_update_response_.dlc_cohortname = "stable-dlc";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  EXPECT_CALL(mock_excluder_, IsExcluded(_)).WillRepeatedly(Return(false));
  ASSERT_TRUE(TestUpdateCheck());

  string value;
  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohort, &value));
  EXPECT_EQ(fake_update_response_.cohort, value);

  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohortHint, &value));
  EXPECT_EQ(fake_update_response_.cohorthint, value);

  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohortName, &value));
  EXPECT_EQ(fake_update_response_.cohortname, value);

  EXPECT_TRUE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey({kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohort}),
      &value));
  EXPECT_EQ(fake_update_response_.dlc_cohort, value);

  EXPECT_TRUE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey(
          {kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohortHint}),
      &value));
  EXPECT_EQ(fake_update_response_.dlc_cohorthint, value);

  EXPECT_TRUE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey(
          {kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohortName}),
      &value));
  EXPECT_EQ(fake_update_response_.dlc_cohortname, value);
}

TEST_F(OmahaRequestActionTest, CohortsAreUpdated) {
  EXPECT_TRUE(fake_prefs_->SetString(kPrefsOmahaCohort, "old_value"));
  EXPECT_TRUE(fake_prefs_->SetString(kPrefsOmahaCohortHint, "old_hint"));
  EXPECT_TRUE(fake_prefs_->SetString(kPrefsOmahaCohortName, "old_name"));
  const string dlc_cohort_key =
      fake_prefs_->CreateSubKey({kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohort});
  const string dlc_cohort_hint_key = fake_prefs_->CreateSubKey(
      {kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohortHint});
  const string dlc_cohort_name_key = fake_prefs_->CreateSubKey(
      {kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohortName});
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(kDlcId1), {.name = kDlcId1}}});
  EXPECT_TRUE(fake_prefs_->SetString(dlc_cohort_key, "old_value_dlc"));
  EXPECT_TRUE(fake_prefs_->SetString(dlc_cohort_hint_key, "old_hint_dlc"));
  EXPECT_TRUE(fake_prefs_->SetString(dlc_cohort_name_key, "old_name_dlc"));
  fake_update_response_.include_cohorts = true;
  fake_update_response_.cohort = "s/154454/8479665";
  fake_update_response_.cohorthint = "please-put-me-on-beta";
  fake_update_response_.cohortname = "";
  fake_update_response_.dlc_app_update = true;
  fake_update_response_.include_dlc_cohorts = true;
  fake_update_response_.dlc_cohort = "s/154454/8479665/dlc";
  fake_update_response_.dlc_cohorthint = "please-put-me-on-beta-dlc";
  fake_update_response_.dlc_cohortname = "";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  EXPECT_CALL(mock_excluder_, IsExcluded(_)).WillRepeatedly(Return(false));
  ASSERT_TRUE(TestUpdateCheck());

  string value;
  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohort, &value));
  EXPECT_EQ(fake_update_response_.cohort, value);

  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohortHint, &value));
  EXPECT_EQ(fake_update_response_.cohorthint, value);

  EXPECT_FALSE(fake_prefs_->GetString(kPrefsOmahaCohortName, &value));

  EXPECT_TRUE(fake_prefs_->GetString(dlc_cohort_key, &value));
  EXPECT_EQ(fake_update_response_.dlc_cohort, value);

  EXPECT_TRUE(fake_prefs_->GetString(dlc_cohort_hint_key, &value));
  EXPECT_EQ(fake_update_response_.dlc_cohorthint, value);

  EXPECT_FALSE(fake_prefs_->GetString(dlc_cohort_name_key, &value));
}

TEST_F(OmahaRequestActionTest, CohortsAreNotModifiedWhenMissing) {
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  EXPECT_TRUE(fake_prefs_->SetString(kPrefsOmahaCohort, "old_value"));
  const string dlc_cohort_key =
      fake_prefs_->CreateSubKey({kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohort});
  EXPECT_TRUE(fake_prefs_->SetString(dlc_cohort_key, "old_value_dlc"));
  ASSERT_TRUE(TestUpdateCheck());

  string value;
  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohort, &value));
  EXPECT_EQ("old_value", value);

  EXPECT_FALSE(fake_prefs_->GetString(kPrefsOmahaCohortHint, &value));
  EXPECT_FALSE(fake_prefs_->GetString(kPrefsOmahaCohortName, &value));

  EXPECT_TRUE(fake_prefs_->GetString(dlc_cohort_key, &value));
  EXPECT_EQ("old_value_dlc", value);

  EXPECT_FALSE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey(
          {kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohortHint}),
      &value));
  EXPECT_FALSE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey(
          {kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohortName}),
      &value));
}

TEST_F(OmahaRequestActionTest, CohortsArePersistedWhenNoUpdate) {
  fake_update_response_.include_cohorts = true;
  fake_update_response_.cohort = "s/154454/8479665";
  fake_update_response_.cohorthint = "please-put-me-on-beta";
  fake_update_response_.cohortname = "stable";
  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  string value;
  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohort, &value));
  EXPECT_EQ(fake_update_response_.cohort, value);

  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohortHint, &value));
  EXPECT_EQ(fake_update_response_.cohorthint, value);

  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohortName, &value));
  EXPECT_EQ(fake_update_response_.cohortname, value);
}

TEST_F(OmahaRequestActionTest, MultiAppCohortTest) {
  fake_update_response_.multi_app = true;
  fake_update_response_.include_cohorts = true;
  fake_update_response_.cohort = "s/154454/8479665";
  fake_update_response_.cohorthint = "please-put-me-on-beta";
  fake_update_response_.cohortname = "stable";
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(kDlcId1), {.name = kDlcId1}},
       {request_params_.GetDlcAppId(kDlcId2), {.name = kDlcId2}}});
  fake_update_response_.dlc_app_update = true;
  fake_update_response_.dlc_app_no_update = true;
  fake_update_response_.include_dlc_cohorts = true;
  fake_update_response_.dlc_cohort = "s/154454/8479665/dlc";
  fake_update_response_.dlc_cohorthint = "please-put-me-on-beta-dlc";
  fake_update_response_.dlc_cohortname = "stable-dlc";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  EXPECT_CALL(mock_excluder_, IsExcluded(_)).WillRepeatedly(Return(false));
  ASSERT_TRUE(TestUpdateCheck());

  string value;
  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohort, &value));
  EXPECT_EQ(fake_update_response_.cohort, value);

  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohortHint, &value));
  EXPECT_EQ(fake_update_response_.cohorthint, value);

  EXPECT_TRUE(fake_prefs_->GetString(kPrefsOmahaCohortName, &value));
  EXPECT_EQ(fake_update_response_.cohortname, value);

  EXPECT_TRUE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey({kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohort}),
      &value));
  EXPECT_EQ(fake_update_response_.dlc_cohort, value);
  EXPECT_TRUE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey({kDlcPrefsSubDir, kDlcId2, kPrefsOmahaCohort}),
      &value));
  EXPECT_EQ(fake_update_response_.dlc_cohort, value);

  EXPECT_TRUE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey(
          {kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohortHint}),
      &value));
  EXPECT_EQ(fake_update_response_.dlc_cohorthint, value);
  EXPECT_TRUE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey(
          {kDlcPrefsSubDir, kDlcId2, kPrefsOmahaCohortHint}),
      &value));
  EXPECT_EQ(fake_update_response_.dlc_cohorthint, value);

  EXPECT_TRUE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey(
          {kDlcPrefsSubDir, kDlcId1, kPrefsOmahaCohortName}),
      &value));
  EXPECT_EQ(fake_update_response_.dlc_cohortname, value);
  EXPECT_TRUE(fake_prefs_->GetString(
      fake_prefs_->CreateSubKey(
          {kDlcPrefsSubDir, kDlcId2, kPrefsOmahaCohortName}),
      &value));
  EXPECT_EQ(fake_update_response_.dlc_cohortname, value);
}

TEST_F(OmahaRequestActionTest, NoOutputPipeTest) {
  const string http_response(fake_update_response_.GetNoUpdateResponse());
  brillo::FakeMessageLoop loop(nullptr);
  loop.SetAsCurrent();

  auto action = std::make_unique<OmahaRequestAction>(
      nullptr,
      std::make_unique<MockHttpFetcher>(
          http_response.data(), http_response.size(), nullptr),
      false,
      "");
  ActionProcessor processor;
  processor.set_delegate(&delegate_);
  processor.EnqueueAction(std::move(action));

  loop.PostTask(base::Bind(
      [](ActionProcessor* processor) { processor->StartProcessing(); },
      base::Unretained(&processor)));
  loop.Run();
  EXPECT_FALSE(loop.PendingTasks());
  EXPECT_FALSE(processor.IsRunning());
}

TEST_F(OmahaRequestActionTest, InvalidXmlTest) {
  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, EmptyResponseTest) {
  tuc_params_.expected_code = ErrorCode::kOmahaRequestEmptyResponseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, MissingStatusTest) {
  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response protocol=\"3.0\">"
      "<daystart elapsed_seconds=\"100\"/>"
      "<app appid=\"foo\" status=\"ok\">"
      "<ping status=\"ok\"/>"
      "<updatecheck/></app></response>";
  tuc_params_.expected_code = ErrorCode::kOmahaResponseInvalid;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, InvalidStatusTest) {
  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response protocol=\"3.0\">"
      "<daystart elapsed_seconds=\"100\"/>"
      "<app appid=\"foo\" status=\"ok\">"
      "<ping status=\"ok\"/>"
      "<updatecheck status=\"InvalidStatusTest\"/></app></response>";
  tuc_params_.expected_code = ErrorCode::kOmahaResponseInvalid;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, MissingNodesetTest) {
  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response protocol=\"3.0\">"
      "<daystart elapsed_seconds=\"100\"/>"
      "<app appid=\"foo\" status=\"ok\">"
      "<ping status=\"ok\"/>"
      "</app></response>";
  tuc_params_.expected_code = ErrorCode::kOmahaResponseInvalid;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, MissingFieldTest) {
  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response protocol=\"3.0\">"
      "<daystart elapsed_seconds=\"100\"/>"
      // the appid needs to match that in the request params
      "<app appid=\"" +
      fake_update_response_.app_id +
      "\" status=\"ok\">"
      "<updatecheck status=\"ok\">"
      "<urls><url codebase=\"http://missing/field/test/\"/></urls>"
      "<manifest version=\"10.2.3.4\">"
      "<packages><package hash=\"not-used\" name=\"f\" "
      "size=\"587\" fp=\"3.789\" hash_sha256=\"lkq34j5345\"/></packages>"
      "<actions><action event=\"postinstall\" "
      "Prompt=\"false\" "
      "IsDeltaPayload=\"false\" "
      "sha256=\"not-used\" "
      "/></actions></manifest></updatecheck></app></response>";

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ("10.2.3.4", response_.version);
  EXPECT_EQ("http://missing/field/test/f",
            response_.packages[0].payload_urls[0]);
  EXPECT_EQ("", response_.more_info_url);
  EXPECT_EQ("lkq34j5345", response_.packages[0].hash);
  EXPECT_EQ(string("3.789"), response_.packages[0].fp);
  EXPECT_EQ(587u, response_.packages[0].size);
  EXPECT_FALSE(response_.prompt);
  EXPECT_TRUE(response_.deadline.empty());
}

namespace {
class TerminateEarlyTestProcessorDelegate : public ActionProcessorDelegate {
 public:
  void ProcessingStopped(const ActionProcessor* processor) {
    brillo::MessageLoop::current()->BreakLoop();
  }
};

void TerminateTransferTestStarter(ActionProcessor* processor) {
  processor->StartProcessing();
  CHECK(processor->IsRunning());
  processor->StopProcessing();
}
}  // namespace

TEST_F(OmahaRequestActionTest, TerminateTransferTest) {
  brillo::FakeMessageLoop loop(nullptr);
  loop.SetAsCurrent();

  string http_response("doesn't matter");
  auto action = std::make_unique<OmahaRequestAction>(
      nullptr,
      std::make_unique<MockHttpFetcher>(
          http_response.data(), http_response.size(), nullptr),
      false,
      "");
  TerminateEarlyTestProcessorDelegate delegate;
  ActionProcessor processor;
  processor.set_delegate(&delegate);
  processor.EnqueueAction(std::move(action));

  loop.PostTask(base::Bind(&TerminateTransferTestStarter, &processor));
  loop.Run();
  EXPECT_FALSE(loop.PendingTasks());
}

TEST_F(OmahaRequestActionTest, XmlEncodeIsUsedForParams) {
  // Make sure XML Encode is being called on the params.
  request_params_.set_os_sp("testtheservice_pack>");
  request_params_.set_os_board("x86 generic<id");
  request_params_.set_current_channel("unittest_track&lt;");
  request_params_.set_target_channel("unittest_track&lt;");
  request_params_.set_lts_tag("unittest_hint&lt;");
  request_params_.set_hwid("<OEM MODEL>");
  fake_prefs_->SetString(kPrefsOmahaCohort, "evil\nstring");
  fake_prefs_->SetString(kPrefsOmahaCohortHint, "evil&string\\");
  fake_prefs_->SetString(
      kPrefsOmahaCohortName,
      base::JoinString(vector<string>(100, "My spoon is too big."), " "));
  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_NE(string::npos, post_str_.find("testtheservice_pack&gt;"));
  EXPECT_EQ(string::npos, post_str_.find("testtheservice_pack>"));
  EXPECT_NE(string::npos, post_str_.find("x86 generic&lt;id"));
  EXPECT_EQ(string::npos, post_str_.find("x86 generic<id"));
  EXPECT_NE(string::npos, post_str_.find("unittest_track&amp;lt;"));
  EXPECT_EQ(string::npos, post_str_.find("unittest_track&lt;"));
  EXPECT_NE(string::npos, post_str_.find("unittest_hint&amp;lt;"));
  EXPECT_EQ(string::npos, post_str_.find("unittest_hint&lt;"));
  EXPECT_NE(string::npos, post_str_.find("&lt;OEM MODEL&gt;"));
  EXPECT_EQ(string::npos, post_str_.find("<OEM MODEL>"));
  EXPECT_NE(string::npos, post_str_.find("cohort=\"evil\nstring\""));
  EXPECT_EQ(string::npos, post_str_.find("cohorthint=\"evil&string\\\""));
  EXPECT_NE(string::npos, post_str_.find("cohorthint=\"evil&amp;string\\\""));
  // Values from Prefs that are too big are removed from the XML instead of
  // encoded.
  EXPECT_EQ(string::npos, post_str_.find("cohortname="));
}

TEST_F(OmahaRequestActionTest, XmlDecodeTest) {
  fake_update_response_.deadline = "&lt;20110101";
  fake_update_response_.more_info_url = "testthe&lt;url";
  fake_update_response_.codebase = "testthe&amp;codebase/";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_EQ("testthe<url", response_.more_info_url);
  EXPECT_EQ("testthe&codebase/file.signed",
            response_.packages[0].payload_urls[0]);
  EXPECT_EQ("<20110101", response_.deadline);
}

TEST_F(OmahaRequestActionTest, ParseIntTest) {
  // overflows int32_t:
  fake_update_response_.size = 123123123123123ull;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_EQ(fake_update_response_.size, response_.packages[0].size);
}

TEST_F(OmahaRequestActionTest, FormatUpdateCheckOutputTest) {
  NiceMock<MockPrefs> prefs;
  FakeSystemState::Get()->set_prefs(&prefs);
  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  EXPECT_CALL(prefs, GetString(kPrefsPreviousVersion, _))
      .WillOnce(DoAll(SetArgPointee<1>(string("")), Return(true)));
  // An existing but empty previous version means that we didn't reboot to a new
  // update, therefore, no need to update the previous version.
  EXPECT_CALL(prefs, SetString(kPrefsPreviousVersion, _)).Times(0);
  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_NE(
      post_str_.find("        <ping active=\"1\" a=\"-1\" r=\"-1\"></ping>\n"
                     "        <updatecheck></updatecheck>\n"),
      string::npos);
  EXPECT_NE(post_str_.find("hardware_class=\"OEM MODEL 09235 7471\""),
            string::npos);
  // No <event> tag should be sent if we didn't reboot to an update.
  EXPECT_EQ(post_str_.find("<event"), string::npos);
}

TEST_F(OmahaRequestActionTest, FormatSuccessEventOutputTest) {
  TestEvent(new OmahaEvent(OmahaEvent::kTypeUpdateDownloadStarted),
            "invalid xml>");

  string expected_event = base::StringPrintf(
      "        <event eventtype=\"%d\" eventresult=\"%d\"></event>\n",
      OmahaEvent::kTypeUpdateDownloadStarted,
      OmahaEvent::kResultSuccess);
  EXPECT_NE(post_str_.find(expected_event), string::npos);
  EXPECT_EQ(post_str_.find("ping"), string::npos);
  EXPECT_EQ(post_str_.find("updatecheck"), string::npos);
}

TEST_F(OmahaRequestActionTest, FormatErrorEventOutputTest) {
  TestEvent(new OmahaEvent(OmahaEvent::kTypeDownloadComplete,
                           OmahaEvent::kResultError,
                           ErrorCode::kError),
            "invalid xml>");

  string expected_event = base::StringPrintf(
      "        <event eventtype=\"%d\" eventresult=\"%d\" "
      "errorcode=\"%d\"></event>\n",
      OmahaEvent::kTypeDownloadComplete,
      OmahaEvent::kResultError,
      static_cast<int>(ErrorCode::kError));
  EXPECT_NE(post_str_.find(expected_event), string::npos);
  EXPECT_EQ(post_str_.find("updatecheck"), string::npos);
}

TEST_F(OmahaRequestActionTest, IsEventTest) {
  string http_response("doesn't matter");
  OmahaRequestAction update_check_action(
      nullptr,
      std::make_unique<MockHttpFetcher>(
          http_response.data(), http_response.size(), nullptr),
      false,
      "");
  EXPECT_FALSE(update_check_action.IsEvent());

  OmahaRequestAction event_action(
      new OmahaEvent(OmahaEvent::kTypeUpdateComplete),
      std::make_unique<MockHttpFetcher>(
          http_response.data(), http_response.size(), nullptr),
      false,
      "");
  EXPECT_TRUE(event_action.IsEvent());
}

TEST_F(OmahaRequestActionTest, FormatDeltaOkayOutputTest) {
  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  for (int i = 0; i < 2; i++) {
    bool delta_okay = i == 1;
    const char* delta_okay_str = delta_okay ? "true" : "false";
    request_params_.set_delta_okay(delta_okay);

    ASSERT_FALSE(TestUpdateCheck());
    EXPECT_NE(post_str_.find(
                  base::StringPrintf(" delta_okay=\"%s\"", delta_okay_str)),
              string::npos)
        << "i = " << i;
  }
}

TEST_F(OmahaRequestActionTest, FormatInteractiveOutputTest) {
  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  for (int i = 0; i < 2; i++) {
    bool interactive = i == 1;
    const char* interactive_str = interactive ? "ondemandupdate" : "scheduler";
    request_params_.set_interactive(interactive);

    ASSERT_FALSE(TestUpdateCheck());
    EXPECT_NE(post_str_.find(
                  base::StringPrintf("installsource=\"%s\"", interactive_str)),
              string::npos)
        << "i = " << i;
  }
}

TEST_F(OmahaRequestActionTest, FormatTargetVersionPrefixOutputTest) {
  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  for (int i = 0; i < 2; i++) {
    bool target_version_set = i == 1;
    const char* target_version_prefix = target_version_set ? "10032." : "";
    request_params_.set_target_version_prefix(target_version_prefix);

    ASSERT_FALSE(TestUpdateCheck());
    if (target_version_set) {
      EXPECT_NE(post_str_.find("<updatecheck targetversionprefix=\"10032.\">"),
                string::npos)
          << "i = " << i;
    } else {
      EXPECT_EQ(post_str_.find("targetversionprefix"), string::npos)
          << "i = " << i;
    }
  }
}

TEST_F(OmahaRequestActionTest, FormatRollbackAllowedOutputTest) {
  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  for (int i = 0; i < 4; i++) {
    bool rollback_allowed = i / 2 == 0;
    bool target_version_set = i % 2 == 0;
    request_params_.set_target_version_prefix(target_version_set ? "10032."
                                                                 : "");
    request_params_.set_rollback_allowed(rollback_allowed);

    ASSERT_FALSE(TestUpdateCheck());
    if (rollback_allowed && target_version_set) {
      EXPECT_NE(post_str_.find("rollback_allowed=\"true\""), string::npos)
          << "i = " << i;
    } else {
      EXPECT_EQ(post_str_.find("rollback_allowed"), string::npos)
          << "i = " << i;
    }
  }
}

TEST_F(OmahaRequestActionTest, OmahaEventTest) {
  OmahaEvent default_event;
  EXPECT_EQ(OmahaEvent::kTypeUnknown, default_event.type);
  EXPECT_EQ(OmahaEvent::kResultError, default_event.result);
  EXPECT_EQ(ErrorCode::kError, default_event.error_code);

  OmahaEvent success_event(OmahaEvent::kTypeUpdateDownloadStarted);
  EXPECT_EQ(OmahaEvent::kTypeUpdateDownloadStarted, success_event.type);
  EXPECT_EQ(OmahaEvent::kResultSuccess, success_event.result);
  EXPECT_EQ(ErrorCode::kSuccess, success_event.error_code);

  OmahaEvent error_event(OmahaEvent::kTypeUpdateDownloadFinished,
                         OmahaEvent::kResultError,
                         ErrorCode::kError);
  EXPECT_EQ(OmahaEvent::kTypeUpdateDownloadFinished, error_event.type);
  EXPECT_EQ(OmahaEvent::kResultError, error_event.result);
  EXPECT_EQ(ErrorCode::kError, error_event.error_code);
}

TEST_F(OmahaRequestActionTest, DeviceQuickFixBuildTokenIsSetTest) {
  // If DeviceQuickFixBuildToken value is set it takes precedence over pref
  // value.
  constexpr char autoupdate_token[] = "autoupdate_token>";
  constexpr char xml_encoded_autoupdate_token[] = "autoupdate_token&gt;";
  constexpr char omaha_cohort_hint[] = "cohort_hint";

  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;
  request_params_.set_autoupdate_token(autoupdate_token);
  fake_prefs_->SetString(kPrefsOmahaCohortHint, omaha_cohort_hint);

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_NE(string::npos,
            post_str_.find("cohorthint=\"" +
                           string(xml_encoded_autoupdate_token) + "\""));
  EXPECT_EQ(string::npos, post_str_.find(autoupdate_token));
  EXPECT_EQ(string::npos, post_str_.find(omaha_cohort_hint));
}

TEST_F(OmahaRequestActionTest, DeviceQuickFixBuildTokenIsNotSetTest) {
  // If DeviceQuickFixBuildToken is not set, pref value will be provided in
  // cohorthint attribute.
  constexpr char omaha_cohort_hint[] = "evil_string>";
  constexpr char xml_encoded_cohort_hint[] = "evil_string&gt;";

  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;
  fake_prefs_->SetString(kPrefsOmahaCohortHint, omaha_cohort_hint);

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_NE(
      string::npos,
      post_str_.find("cohorthint=\"" + string(xml_encoded_cohort_hint) + "\""));
  EXPECT_EQ(string::npos, post_str_.find(omaha_cohort_hint));
}

TEST_F(OmahaRequestActionTest, TargetChannelHintTest) {
  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;
  request_params_.set_lts_tag("hint>");

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_NE(string::npos, post_str_.find("ltstag=\"hint&gt;\""));
}

void OmahaRequestActionTest::PingTest(bool ping_only) {
  NiceMock<MockPrefs> prefs;
  FakeSystemState::Get()->set_prefs(&prefs);
  EXPECT_CALL(prefs, GetInt64(kPrefsMetricsCheckLastReportingTime, _))
      .Times(AnyNumber());
  EXPECT_CALL(prefs, SetInt64(_, _)).Times(AnyNumber());
  // Add a few hours to the day difference to test no rounding, etc.
  int64_t five_days_ago =
      (Time::Now() - TimeDelta::FromHours(5 * 24 + 13)).ToInternalValue();
  int64_t six_days_ago =
      (Time::Now() - TimeDelta::FromHours(6 * 24 + 11)).ToInternalValue();
  EXPECT_CALL(prefs, GetInt64(kPrefsInstallDateDays, _))
      .WillOnce(DoAll(SetArgPointee<1>(0), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastActivePingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(six_days_ago), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastRollCallPingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(five_days_ago), Return(true)));

  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.ping_only = ping_only;
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_NE(post_str_.find("<ping active=\"1\" a=\"6\" r=\"5\"></ping>"),
            string::npos);
  if (ping_only) {
    EXPECT_EQ(post_str_.find("updatecheck"), string::npos);
    EXPECT_EQ(post_str_.find("previousversion"), string::npos);
  } else {
    EXPECT_NE(post_str_.find("updatecheck"), string::npos);
    EXPECT_NE(post_str_.find("previousversion"), string::npos);
  }
}

TEST_F(OmahaRequestActionTest, PingTestSendOnlyAPing) {
  PingTest(true /* ping_only */);
}

TEST_F(OmahaRequestActionTest, PingTestSendAlsoAnUpdateCheck) {
  PingTest(false /* ping_only */);
}

TEST_F(OmahaRequestActionTest, ActivePingTest) {
  NiceMock<MockPrefs> prefs;
  FakeSystemState::Get()->set_prefs(&prefs);
  EXPECT_CALL(prefs, GetInt64(kPrefsMetricsCheckLastReportingTime, _))
      .Times(AnyNumber());
  EXPECT_CALL(prefs, SetInt64(_, _)).Times(AnyNumber());
  int64_t three_days_ago =
      (Time::Now() - TimeDelta::FromHours(3 * 24 + 12)).ToInternalValue();
  int64_t now = Time::Now().ToInternalValue();
  EXPECT_CALL(prefs, GetInt64(kPrefsInstallDateDays, _))
      .WillOnce(DoAll(SetArgPointee<1>(0), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastActivePingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(three_days_ago), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastRollCallPingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(now), Return(true)));

  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_NE(post_str_.find("<ping active=\"1\" a=\"3\"></ping>"), string::npos);
}

TEST_F(OmahaRequestActionTest, RollCallPingTest) {
  NiceMock<MockPrefs> prefs;
  FakeSystemState::Get()->set_prefs(&prefs);
  EXPECT_CALL(prefs, GetInt64(kPrefsMetricsCheckLastReportingTime, _))
      .Times(AnyNumber());
  EXPECT_CALL(prefs, SetInt64(_, _)).Times(AnyNumber());
  int64_t four_days_ago =
      (Time::Now() - TimeDelta::FromHours(4 * 24)).ToInternalValue();
  int64_t now = Time::Now().ToInternalValue();
  EXPECT_CALL(prefs, GetInt64(kPrefsInstallDateDays, _))
      .WillOnce(DoAll(SetArgPointee<1>(0), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastActivePingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(now), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastRollCallPingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(four_days_ago), Return(true)));

  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_NE(post_str_.find("<ping active=\"1\" r=\"4\"></ping>\n"),
            string::npos);
}

TEST_F(OmahaRequestActionTest, NoPingTest) {
  NiceMock<MockPrefs> prefs;
  FakeSystemState::Get()->set_prefs(&prefs);
  EXPECT_CALL(prefs, GetInt64(kPrefsMetricsCheckLastReportingTime, _))
      .Times(AnyNumber());
  EXPECT_CALL(prefs, SetInt64(_, _)).Times(AnyNumber());
  int64_t one_hour_ago =
      (Time::Now() - TimeDelta::FromHours(1)).ToInternalValue();
  EXPECT_CALL(prefs, GetInt64(kPrefsInstallDateDays, _))
      .WillOnce(DoAll(SetArgPointee<1>(0), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastActivePingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(one_hour_ago), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastRollCallPingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(one_hour_ago), Return(true)));
  // LastActivePingDay and PrefsLastRollCallPingDay are set even if we didn't
  // send a ping.
  EXPECT_CALL(prefs, SetInt64(kPrefsLastActivePingDay, _))
      .WillOnce(Return(true));
  EXPECT_CALL(prefs, SetInt64(kPrefsLastRollCallPingDay, _))
      .WillOnce(Return(true));

  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_EQ(post_str_.find("ping"), string::npos);
}

TEST_F(OmahaRequestActionTest, IgnoreEmptyPingTest) {
  // This test ensures that we ignore empty ping only requests.
  NiceMock<MockPrefs> prefs;
  FakeSystemState::Get()->set_prefs(&prefs);
  int64_t now = Time::Now().ToInternalValue();
  EXPECT_CALL(prefs, GetInt64(kPrefsLastActivePingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(now), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastRollCallPingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(now), Return(true)));
  EXPECT_CALL(prefs, SetInt64(kPrefsLastActivePingDay, _)).Times(0);
  EXPECT_CALL(prefs, SetInt64(kPrefsLastRollCallPingDay, _)).Times(0);

  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.ping_only = true;
  tuc_params_.expected_check_result = metrics::CheckResult::kUnset;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  EXPECT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(post_str_.empty());
}

TEST_F(OmahaRequestActionTest, BackInTimePingTest) {
  NiceMock<MockPrefs> prefs;
  FakeSystemState::Get()->set_prefs(&prefs);
  EXPECT_CALL(prefs, GetInt64(kPrefsMetricsCheckLastReportingTime, _))
      .Times(AnyNumber());
  EXPECT_CALL(prefs, SetInt64(_, _)).Times(AnyNumber());
  int64_t future =
      (Time::Now() + TimeDelta::FromHours(3 * 24 + 4)).ToInternalValue();
  EXPECT_CALL(prefs, GetInt64(kPrefsInstallDateDays, _))
      .WillOnce(DoAll(SetArgPointee<1>(0), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastActivePingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(future), Return(true)));
  EXPECT_CALL(prefs, GetInt64(kPrefsLastRollCallPingDay, _))
      .WillOnce(DoAll(SetArgPointee<1>(future), Return(true)));
  EXPECT_CALL(prefs, SetInt64(kPrefsLastActivePingDay, _))
      .WillOnce(Return(true));
  EXPECT_CALL(prefs, SetInt64(kPrefsLastRollCallPingDay, _))
      .WillOnce(Return(true));

  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response "
      "protocol=\"3.0\"><daystart elapsed_seconds=\"100\"/>"
      "<app appid=\"foo\" status=\"ok\"><ping status=\"ok\"/>"
      "<updatecheck status=\"noupdate\"/></app></response>";
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_EQ(post_str_.find("ping"), string::npos);
}

TEST_F(OmahaRequestActionTest, LastPingDayUpdateTest) {
  // This test checks that the action updates the last ping day to now
  // minus 200 seconds with a slack of 5 seconds. Therefore, the test
  // may fail if it runs for longer than 5 seconds. It shouldn't run
  // that long though.
  int64_t midnight =
      (Time::Now() - TimeDelta::FromSeconds(200)).ToInternalValue();
  int64_t midnight_slack =
      (Time::Now() - TimeDelta::FromSeconds(195)).ToInternalValue();
  NiceMock<MockPrefs> prefs;
  FakeSystemState::Get()->set_prefs(&prefs);
  EXPECT_CALL(prefs, GetInt64(_, _)).Times(AnyNumber());
  EXPECT_CALL(prefs, SetInt64(_, _)).Times(AnyNumber());
  EXPECT_CALL(prefs,
              SetInt64(kPrefsLastActivePingDay,
                       AllOf(Ge(midnight), Le(midnight_slack))))
      .WillOnce(Return(true));
  EXPECT_CALL(prefs,
              SetInt64(kPrefsLastRollCallPingDay,
                       AllOf(Ge(midnight), Le(midnight_slack))))
      .WillOnce(Return(true));

  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response "
      "protocol=\"3.0\"><daystart elapsed_seconds=\"200\"/>"
      "<app appid=\"foo\" status=\"ok\"><ping status=\"ok\"/>"
      "<updatecheck status=\"noupdate\"/></app></response>";
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());
}

TEST_F(OmahaRequestActionTest, NoElapsedSecondsTest) {
  NiceMock<MockPrefs> prefs;
  FakeSystemState::Get()->set_prefs(&prefs);
  EXPECT_CALL(prefs, GetInt64(_, _)).Times(AnyNumber());
  EXPECT_CALL(prefs, SetInt64(_, _)).Times(AnyNumber());
  EXPECT_CALL(prefs, SetInt64(kPrefsLastActivePingDay, _)).Times(0);
  EXPECT_CALL(prefs, SetInt64(kPrefsLastRollCallPingDay, _)).Times(0);

  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response "
      "protocol=\"3.0\"><daystart blah=\"200\"/>"
      "<app appid=\"foo\" status=\"ok\"><ping status=\"ok\"/>"
      "<updatecheck status=\"noupdate\"/></app></response>";
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());
}

TEST_F(OmahaRequestActionTest, BadElapsedSecondsTest) {
  NiceMock<MockPrefs> prefs;
  FakeSystemState::Get()->set_prefs(&prefs);
  EXPECT_CALL(prefs, GetInt64(_, _)).Times(AnyNumber());
  EXPECT_CALL(prefs, SetInt64(_, _)).Times(AnyNumber());
  EXPECT_CALL(prefs, SetInt64(kPrefsLastActivePingDay, _)).Times(0);
  EXPECT_CALL(prefs, SetInt64(kPrefsLastRollCallPingDay, _)).Times(0);

  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response "
      "protocol=\"3.0\"><daystart elapsed_seconds=\"x\"/>"
      "<app appid=\"foo\" status=\"ok\"><ping status=\"ok\"/>"
      "<updatecheck status=\"noupdate\"/></app></response>";
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());
}

TEST_F(OmahaRequestActionTest, NoUniqueIDTest) {
  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_EQ(post_str_.find("machineid="), string::npos);
  EXPECT_EQ(post_str_.find("userid="), string::npos);
}

TEST_F(OmahaRequestActionTest, NetworkFailureTest) {
  const int http_error_code =
      static_cast<int>(ErrorCode::kOmahaRequestHTTPResponseBase) + 501;
  tuc_params_.fail_http_response_code = 501;
  tuc_params_.expected_code = static_cast<ErrorCode>(http_error_code);
  tuc_params_.expected_check_result = metrics::CheckResult::kDownloadError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;
  tuc_params_.expected_download_error_code =
      static_cast<metrics::DownloadErrorCode>(501);

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, NetworkFailureBadHTTPCodeTest) {
  const int http_error_code =
      static_cast<int>(ErrorCode::kOmahaRequestHTTPResponseBase) + 999;

  tuc_params_.fail_http_response_code = 1500;
  tuc_params_.expected_code = static_cast<ErrorCode>(http_error_code);
  tuc_params_.expected_check_result = metrics::CheckResult::kDownloadError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;
  tuc_params_.expected_download_error_code =
      metrics::DownloadErrorCode::kHttpStatusOther;

  ASSERT_FALSE(TestUpdateCheck());
  EXPECT_FALSE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, TestUpdateFirstSeenAtGetsPersistedFirstTime) {
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_waiting_period(TimeDelta().FromDays(1));
  request_params_.set_update_check_count_wait_enabled(false);

  Time arbitrary_date;
  ASSERT_TRUE(Time::FromString("6/4/1989", &arbitrary_date));
  FakeSystemState::Get()->fake_clock()->SetWallclockTime(arbitrary_date);

  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_code = ErrorCode::kOmahaUpdateDeferredPerPolicy;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kDeferring;

  ASSERT_FALSE(TestUpdateCheck());

  int64_t timestamp = 0;
  ASSERT_TRUE(fake_prefs_->GetInt64(kPrefsUpdateFirstSeenAt, &timestamp));
  EXPECT_EQ(arbitrary_date.ToInternalValue(), timestamp);
  EXPECT_FALSE(response_.update_exists);

  // Verify if we are interactive check we don't defer.
  request_params_.set_interactive(true);
  tuc_params_.expected_code = ErrorCode::kSuccess;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUpdating;

  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, TestUpdateFirstSeenAtGetsUsedIfAlreadyPresent) {
  request_params_.set_wall_clock_based_wait_enabled(true);
  request_params_.set_waiting_period(TimeDelta().FromDays(1));
  request_params_.set_update_check_count_wait_enabled(false);

  Time t1, t2;
  ASSERT_TRUE(Time::FromString("1/1/2012", &t1));
  ASSERT_TRUE(Time::FromString("1/3/2012", &t2));
  ASSERT_TRUE(
      fake_prefs_->SetInt64(kPrefsUpdateFirstSeenAt, t1.ToInternalValue()));
  FakeSystemState::Get()->fake_clock()->SetWallclockTime(t2);

  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);

  // Make sure the timestamp t1 is unchanged showing that it was reused.
  int64_t timestamp = 0;
  ASSERT_TRUE(fake_prefs_->GetInt64(kPrefsUpdateFirstSeenAt, &timestamp));
  ASSERT_TRUE(timestamp == t1.ToInternalValue());
}

TEST_F(OmahaRequestActionTest, TestChangingToMoreStableChannel) {
  // Create a uniquely named test directory.
  base::ScopedTempDir tempdir;
  ASSERT_TRUE(tempdir.CreateUniqueTempDir());

  request_params_.set_root(tempdir.GetPath().value());
  request_params_.set_app_id("{22222222-2222-2222-2222-222222222222}");
  request_params_.set_app_version("1.2.3.4");
  request_params_.set_product_components("o.bundle=1");
  request_params_.set_current_channel("canary-channel");
  EXPECT_TRUE(
      request_params_.SetTargetChannel("stable-channel", true, nullptr));
  request_params_.UpdateDownloadChannel();
  EXPECT_TRUE(request_params_.ShouldPowerwash());

  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_NE(string::npos,
            post_str_.find(
                "appid=\"{22222222-2222-2222-2222-222222222222}\" "
                "version=\"0.0.0.0\" from_version=\"1.2.3.4\" "
                "track=\"stable-channel\" from_track=\"canary-channel\" "));
  EXPECT_EQ(string::npos, post_str_.find("o.bundle"));
}

TEST_F(OmahaRequestActionTest, TestChangingToLessStableChannel) {
  // Create a uniquely named test directory.
  base::ScopedTempDir tempdir;
  ASSERT_TRUE(tempdir.CreateUniqueTempDir());

  request_params_.set_root(tempdir.GetPath().value());
  request_params_.set_app_id("{11111111-1111-1111-1111-111111111111}");
  request_params_.set_app_version("5.6.7.8");
  request_params_.set_product_components("o.bundle=1");
  request_params_.set_current_channel("stable-channel");
  EXPECT_TRUE(
      request_params_.SetTargetChannel("canary-channel", false, nullptr));
  request_params_.UpdateDownloadChannel();
  EXPECT_FALSE(request_params_.ShouldPowerwash());

  tuc_params_.http_response = "invalid xml>";
  tuc_params_.expected_code = ErrorCode::kOmahaRequestXMLParseError;
  tuc_params_.expected_check_result = metrics::CheckResult::kParsingError;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_FALSE(TestUpdateCheck());

  EXPECT_NE(
      string::npos,
      post_str_.find("appid=\"{11111111-1111-1111-1111-111111111111}\" "
                     "version=\"5.6.7.8\" "
                     "track=\"canary-channel\" from_track=\"stable-channel\""));
  EXPECT_EQ(string::npos, post_str_.find("from_version"));
  EXPECT_NE(string::npos, post_str_.find("o.bundle.version=\"1\""));
}

// Checks that the initial ping with a=-1 r=-1 is not send when the device
// was powerwashed.
TEST_F(OmahaRequestActionTest, PingWhenPowerwashed) {
  fake_prefs_->SetString(kPrefsPreviousVersion, "");

  // Flag that the device was powerwashed in the past.
  FakeSystemState::Get()->fake_hardware()->SetPowerwashCount(1);
  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  // We shouldn't send a ping in this case since powerwash > 0.
  EXPECT_EQ(string::npos, post_str_.find("<ping"));
}

// Checks that the initial ping with a=-1 r=-1 is not send when the device
// first_active_omaha_ping_sent is set.
TEST_F(OmahaRequestActionTest, PingWhenFirstActiveOmahaPingIsSent) {
  fake_prefs_->SetString(kPrefsPreviousVersion, "");

  // Flag that the device was not powerwashed in the past.
  FakeSystemState::Get()->fake_hardware()->SetPowerwashCount(0);

  // Flag that the device has sent first active ping in the past.
  FakeSystemState::Get()->fake_hardware()->SetFirstActiveOmahaPingSent();

  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  // We shouldn't send a ping in this case since
  // first_active_omaha_ping_sent=true
  EXPECT_EQ(string::npos, post_str_.find("<ping"));
}

// Checks that the event 54 is sent on a reboot to a new update.
TEST_F(OmahaRequestActionTest, RebootAfterUpdateEvent) {
  // Flag that the device was updated in a previous boot.
  fake_prefs_->SetString(kPrefsPreviousVersion, "1.2.3.4");

  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  // An event 54 is included and has the right version.
  EXPECT_NE(
      string::npos,
      post_str_.find(base::StringPrintf("<event eventtype=\"%d\"",
                                        OmahaEvent::kTypeRebootedAfterUpdate)));
  EXPECT_NE(string::npos,
            post_str_.find("previousversion=\"1.2.3.4\"></event>"));

  // The previous version flag should have been removed.
  EXPECT_TRUE(fake_prefs_->Exists(kPrefsPreviousVersion));
  string prev_version;
  EXPECT_TRUE(fake_prefs_->GetString(kPrefsPreviousVersion, &prev_version));
  EXPECT_TRUE(prev_version.empty());
}

void OmahaRequestActionTest::P2PTest(bool initial_allow_p2p_for_downloading,
                                     bool initial_allow_p2p_for_sharing,
                                     bool omaha_disable_p2p_for_downloading,
                                     bool omaha_disable_p2p_for_sharing,
                                     bool payload_state_allow_p2p_attempt,
                                     bool expect_p2p_client_lookup,
                                     const string& p2p_client_result_url,
                                     bool expected_allow_p2p_for_downloading,
                                     bool expected_allow_p2p_for_sharing,
                                     const string& expected_p2p_url) {
  bool actual_allow_p2p_for_downloading = initial_allow_p2p_for_downloading;
  bool actual_allow_p2p_for_sharing = initial_allow_p2p_for_sharing;
  string actual_p2p_url;

  MockPayloadState mock_payload_state;
  FakeSystemState::Get()->set_payload_state(&mock_payload_state);
  EXPECT_CALL(mock_payload_state, P2PAttemptAllowed())
      .WillRepeatedly(Return(payload_state_allow_p2p_attempt));
  EXPECT_CALL(mock_payload_state, GetUsingP2PForDownloading())
      .WillRepeatedly(ReturnPointee(&actual_allow_p2p_for_downloading));
  EXPECT_CALL(mock_payload_state, GetUsingP2PForSharing())
      .WillRepeatedly(ReturnPointee(&actual_allow_p2p_for_sharing));
  EXPECT_CALL(mock_payload_state, SetUsingP2PForDownloading(_))
      .WillRepeatedly(SaveArg<0>(&actual_allow_p2p_for_downloading));
  EXPECT_CALL(mock_payload_state, SetUsingP2PForSharing(_))
      .WillRepeatedly(SaveArg<0>(&actual_allow_p2p_for_sharing));
  EXPECT_CALL(mock_payload_state, SetP2PUrl(_))
      .WillRepeatedly(SaveArg<0>(&actual_p2p_url));

  MockP2PManager mock_p2p_manager;
  FakeSystemState::Get()->set_p2p_manager(&mock_p2p_manager);
  mock_p2p_manager.fake().SetLookupUrlForFileResult(p2p_client_result_url);

  TimeDelta timeout = TimeDelta::FromSeconds(kMaxP2PNetworkWaitTimeSeconds);
  EXPECT_CALL(mock_p2p_manager, LookupUrlForFile(_, _, timeout, _))
      .Times(expect_p2p_client_lookup ? 1 : 0);

  fake_update_response_.disable_p2p_for_downloading =
      omaha_disable_p2p_for_downloading;
  fake_update_response_.disable_p2p_for_sharing = omaha_disable_p2p_for_sharing;

  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kUpdateAvailable;

  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);

  EXPECT_EQ(omaha_disable_p2p_for_downloading,
            response_.disable_p2p_for_downloading);
  EXPECT_EQ(omaha_disable_p2p_for_sharing, response_.disable_p2p_for_sharing);

  EXPECT_EQ(expected_allow_p2p_for_downloading,
            actual_allow_p2p_for_downloading);
  EXPECT_EQ(expected_allow_p2p_for_sharing, actual_allow_p2p_for_sharing);
  EXPECT_EQ(expected_p2p_url, actual_p2p_url);
}

TEST_F(OmahaRequestActionTest, P2PWithPeer) {
  P2PTest(true,                   // initial_allow_p2p_for_downloading
          true,                   // initial_allow_p2p_for_sharing
          false,                  // omaha_disable_p2p_for_downloading
          false,                  // omaha_disable_p2p_for_sharing
          true,                   // payload_state_allow_p2p_attempt
          true,                   // expect_p2p_client_lookup
          "http://1.3.5.7/p2p",   // p2p_client_result_url
          true,                   // expected_allow_p2p_for_downloading
          true,                   // expected_allow_p2p_for_sharing
          "http://1.3.5.7/p2p");  // expected_p2p_url
}

TEST_F(OmahaRequestActionTest, P2PWithoutPeer) {
  P2PTest(true,   // initial_allow_p2p_for_downloading
          true,   // initial_allow_p2p_for_sharing
          false,  // omaha_disable_p2p_for_downloading
          false,  // omaha_disable_p2p_for_sharing
          true,   // payload_state_allow_p2p_attempt
          true,   // expect_p2p_client_lookup
          "",     // p2p_client_result_url
          false,  // expected_allow_p2p_for_downloading
          true,   // expected_allow_p2p_for_sharing
          "");    // expected_p2p_url
}

TEST_F(OmahaRequestActionTest, P2PDownloadNotAllowed) {
  P2PTest(false,    // initial_allow_p2p_for_downloading
          true,     // initial_allow_p2p_for_sharing
          false,    // omaha_disable_p2p_for_downloading
          false,    // omaha_disable_p2p_for_sharing
          true,     // payload_state_allow_p2p_attempt
          false,    // expect_p2p_client_lookup
          "unset",  // p2p_client_result_url
          false,    // expected_allow_p2p_for_downloading
          true,     // expected_allow_p2p_for_sharing
          "");      // expected_p2p_url
}

TEST_F(OmahaRequestActionTest, P2PWithPeerDownloadDisabledByOmaha) {
  P2PTest(true,     // initial_allow_p2p_for_downloading
          true,     // initial_allow_p2p_for_sharing
          true,     // omaha_disable_p2p_for_downloading
          false,    // omaha_disable_p2p_for_sharing
          true,     // payload_state_allow_p2p_attempt
          false,    // expect_p2p_client_lookup
          "unset",  // p2p_client_result_url
          false,    // expected_allow_p2p_for_downloading
          true,     // expected_allow_p2p_for_sharing
          "");      // expected_p2p_url
}

TEST_F(OmahaRequestActionTest, P2PWithPeerSharingDisabledByOmaha) {
  P2PTest(true,                   // initial_allow_p2p_for_downloading
          true,                   // initial_allow_p2p_for_sharing
          false,                  // omaha_disable_p2p_for_downloading
          true,                   // omaha_disable_p2p_for_sharing
          true,                   // payload_state_allow_p2p_attempt
          true,                   // expect_p2p_client_lookup
          "http://1.3.5.7/p2p",   // p2p_client_result_url
          true,                   // expected_allow_p2p_for_downloading
          false,                  // expected_allow_p2p_for_sharing
          "http://1.3.5.7/p2p");  // expected_p2p_url
}

TEST_F(OmahaRequestActionTest, P2PWithPeerBothDisabledByOmaha) {
  P2PTest(true,     // initial_allow_p2p_for_downloading
          true,     // initial_allow_p2p_for_sharing
          true,     // omaha_disable_p2p_for_downloading
          true,     // omaha_disable_p2p_for_sharing
          true,     // payload_state_allow_p2p_attempt
          false,    // expect_p2p_client_lookup
          "unset",  // p2p_client_result_url
          false,    // expected_allow_p2p_for_downloading
          false,    // expected_allow_p2p_for_sharing
          "");      // expected_p2p_url
}

bool OmahaRequestActionTest::InstallDateParseHelper(const string& elapsed_days,
                                                    OmahaResponse* response) {
  fake_update_response_.elapsed_days = elapsed_days;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  return TestUpdateCheck();
}

TEST_F(OmahaRequestActionTest, ParseInstallDateFromResponse) {
  // Simulate a successful update check that happens during OOBE.  The
  // deadline in the response is needed to force the update attempt to
  // occur; responses without a deadline seen during OOBE will normally
  // return ErrorCode::kNonCriticalUpdateInOOBE.
  FakeSystemState::Get()->fake_hardware()->UnsetIsOOBEComplete();
  fake_update_response_.deadline = "20101020";

  // Check that we parse elapsed_days in the Omaha Response correctly.
  // and that the kPrefsInstallDateDays value is written to.
  EXPECT_FALSE(fake_prefs_->Exists(kPrefsInstallDateDays));
  EXPECT_TRUE(InstallDateParseHelper("42", &response_));
  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ(42, response_.install_date_days);
  EXPECT_TRUE(fake_prefs_->Exists(kPrefsInstallDateDays));
  int64_t prefs_days;
  EXPECT_TRUE(fake_prefs_->GetInt64(kPrefsInstallDateDays, &prefs_days));
  EXPECT_EQ(prefs_days, 42);

  // If there already is a value set, we shouldn't do anything.
  EXPECT_TRUE(InstallDateParseHelper("7", &response_));
  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ(7, response_.install_date_days);
  EXPECT_TRUE(fake_prefs_->GetInt64(kPrefsInstallDateDays, &prefs_days));
  EXPECT_EQ(prefs_days, 42);

  // Note that elapsed_days is not necessarily divisible by 7 so check
  // that we round down correctly when populating kPrefsInstallDateDays.
  EXPECT_TRUE(fake_prefs_->Delete(kPrefsInstallDateDays));
  EXPECT_TRUE(InstallDateParseHelper("23", &response_));
  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ(23, response_.install_date_days);
  EXPECT_TRUE(fake_prefs_->GetInt64(kPrefsInstallDateDays, &prefs_days));
  EXPECT_EQ(prefs_days, 21);

  // Check that we correctly handle elapsed_days not being included in
  // the Omaha Response_.
  EXPECT_TRUE(InstallDateParseHelper("", &response_));
  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ(-1, response_.install_date_days);
}

// If there is no prefs and OOBE is not complete, we should not
// report anything to Omaha.
TEST_F(OmahaRequestActionTest, GetInstallDateWhenNoPrefsNorOOBE) {
  FakeSystemState::Get()->fake_hardware()->UnsetIsOOBEComplete();
  EXPECT_EQ(OmahaRequestAction::GetInstallDate(), -1);
  EXPECT_FALSE(fake_prefs_->Exists(kPrefsInstallDateDays));
}

// If OOBE is complete and happened on a valid date (e.g. after Jan
// 1 2007 0:00 PST), that date should be used and written to
// prefs. However, first try with an invalid date and check we do
// nothing.
TEST_F(OmahaRequestActionTest, GetInstallDateWhenOOBECompletedWithInvalidDate) {
  Time oobe_date = Time::FromTimeT(42);  // Dec 31, 1969 16:00:42 PST.
  FakeSystemState::Get()->fake_hardware()->SetIsOOBEComplete(oobe_date);
  EXPECT_EQ(OmahaRequestAction::GetInstallDate(), -1);
  EXPECT_FALSE(fake_prefs_->Exists(kPrefsInstallDateDays));
}

// Then check with a valid date. The date Jan 20, 2007 0:00 PST
// should yield an InstallDate of 14.
TEST_F(OmahaRequestActionTest, GetInstallDateWhenOOBECompletedWithValidDate) {
  Time oobe_date = Time::FromTimeT(1169280000);  // Jan 20, 2007 0:00 PST.
  FakeSystemState::Get()->fake_hardware()->SetIsOOBEComplete(oobe_date);
  EXPECT_EQ(OmahaRequestAction::GetInstallDate(), 14);
  EXPECT_TRUE(fake_prefs_->Exists(kPrefsInstallDateDays));

  int64_t prefs_days;
  EXPECT_TRUE(fake_prefs_->GetInt64(kPrefsInstallDateDays, &prefs_days));
  EXPECT_EQ(prefs_days, 14);
}

// Now that we have a valid date in prefs, check that we keep using
// that even if OOBE date reports something else. The date Jan 30,
// 2007 0:00 PST should yield an InstallDate of 28... but since
// there's a prefs file, we should still get 14.
TEST_F(OmahaRequestActionTest, GetInstallDateWhenOOBECompletedDateChanges) {
  // Set a valid date in the prefs first.
  EXPECT_TRUE(fake_prefs_->SetInt64(kPrefsInstallDateDays, 14));

  Time oobe_date = Time::FromTimeT(1170144000);  // Jan 30, 2007 0:00 PST.
  FakeSystemState::Get()->fake_hardware()->SetIsOOBEComplete(oobe_date);
  EXPECT_EQ(OmahaRequestAction::GetInstallDate(), 14);

  int64_t prefs_days;
  EXPECT_TRUE(fake_prefs_->GetInt64(kPrefsInstallDateDays, &prefs_days));
  EXPECT_EQ(prefs_days, 14);

  // If we delete the prefs file, we should get 28 days.
  EXPECT_TRUE(fake_prefs_->Delete(kPrefsInstallDateDays));
  EXPECT_EQ(OmahaRequestAction::GetInstallDate(), 28);
  EXPECT_TRUE(fake_prefs_->GetInt64(kPrefsInstallDateDays, &prefs_days));
  EXPECT_EQ(prefs_days, 28);
}

// Verifies that a device with no device policy, and is not a consumer
// device sets the max kernel key version to the current version.
// ie. the same behavior as if rollback is enabled.
TEST_F(OmahaRequestActionTest, NoPolicyEnterpriseDevicesSetMaxRollback) {
  FakeHardware* fake_hw = FakeSystemState::Get()->fake_hardware();

  // Setup and verify some initial default values for the kernel TPM
  // values that control verified boot and rollback.
  const int min_kernel_version = 4;
  fake_hw->SetMinKernelKeyVersion(min_kernel_version);
  fake_hw->SetMaxKernelKeyRollforward(kRollforwardInfinity);
  EXPECT_EQ(min_kernel_version, fake_hw->GetMinKernelKeyVersion());
  EXPECT_EQ(kRollforwardInfinity, fake_hw->GetMaxKernelKeyRollforward());

  EXPECT_CALL(
      *FakeSystemState::Get()->mock_metrics_reporter(),
      ReportKeyVersionMetrics(min_kernel_version, min_kernel_version, true))
      .Times(1);

  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.is_consumer_device = false;
  tuc_params_.rollback_allowed_milestones = 3;

  EXPECT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);

  // Verify kernel_max_rollforward was set to the current minimum
  // kernel key version. This has the effect of freezing roll
  // forwards indefinitely. This will hold the rollback window
  // open until a future change will be able to move this forward
  // relative the configured window.
  EXPECT_EQ(min_kernel_version, fake_hw->GetMinKernelKeyVersion());
  EXPECT_EQ(min_kernel_version, fake_hw->GetMaxKernelKeyRollforward());
}

// Verifies that a conmsumer device with no device policy sets the
// max kernel key version to the current version. ie. the same
// behavior as if rollback is enabled.
TEST_F(OmahaRequestActionTest, NoPolicyConsumerDevicesSetMaxRollback) {
  FakeHardware* fake_hw = FakeSystemState::Get()->fake_hardware();

  // Setup and verify some initial default values for the kernel TPM
  // values that control verified boot and rollback.
  const int min_kernel_version = 3;
  fake_hw->SetMinKernelKeyVersion(min_kernel_version);
  fake_hw->SetMaxKernelKeyRollforward(kRollforwardInfinity);
  EXPECT_EQ(min_kernel_version, fake_hw->GetMinKernelKeyVersion());
  EXPECT_EQ(kRollforwardInfinity, fake_hw->GetMaxKernelKeyRollforward());

  EXPECT_CALL(
      *FakeSystemState::Get()->mock_metrics_reporter(),
      ReportKeyVersionMetrics(min_kernel_version, kRollforwardInfinity, true))
      .Times(1);

  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.is_consumer_device = true;
  tuc_params_.rollback_allowed_milestones = 3;

  EXPECT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);

  // Verify that with rollback disabled that kernel_max_rollforward
  // was set to logical infinity. This is the expected behavior for
  // consumer devices and matches the existing behavior prior to the
  // rollback features.
  EXPECT_EQ(min_kernel_version, fake_hw->GetMinKernelKeyVersion());
  EXPECT_EQ(kRollforwardInfinity, fake_hw->GetMaxKernelKeyRollforward());
}

// Verifies that a device with rollback enabled sets kernel_max_rollforward
// in the TPM to prevent roll forward.
TEST_F(OmahaRequestActionTest, RollbackEnabledDevicesSetMaxRollback) {
  FakeHardware* fake_hw = FakeSystemState::Get()->fake_hardware();

  // Setup and verify some initial default values for the kernel TPM
  // values that control verified boot and rollback.
  const int allowed_milestones = 4;
  const int min_kernel_version = 3;
  fake_hw->SetMinKernelKeyVersion(min_kernel_version);
  fake_hw->SetMaxKernelKeyRollforward(kRollforwardInfinity);
  EXPECT_EQ(min_kernel_version, fake_hw->GetMinKernelKeyVersion());
  EXPECT_EQ(kRollforwardInfinity, fake_hw->GetMaxKernelKeyRollforward());

  EXPECT_CALL(
      *FakeSystemState::Get()->mock_metrics_reporter(),
      ReportKeyVersionMetrics(min_kernel_version, min_kernel_version, true))
      .Times(1);

  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.is_consumer_device = false;
  tuc_params_.rollback_allowed_milestones = allowed_milestones;
  tuc_params_.is_policy_loaded = true;

  EXPECT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);

  // Verify that with rollback enabled that kernel_max_rollforward
  // was set to the current minimum kernel key version. This has
  // the effect of freezing roll forwards indefinitely. This will
  // hold the rollback window open until a future change will
  // be able to move this forward relative the configured window.
  EXPECT_EQ(min_kernel_version, fake_hw->GetMinKernelKeyVersion());
  EXPECT_EQ(min_kernel_version, fake_hw->GetMaxKernelKeyRollforward());
}

// Verifies that a device with rollback disabled sets kernel_max_rollforward
// in the TPM to logical infinity, to allow roll forward.
TEST_F(OmahaRequestActionTest, RollbackDisabledDevicesSetMaxRollback) {
  FakeHardware* fake_hw = FakeSystemState::Get()->fake_hardware();

  // Setup and verify some initial default values for the kernel TPM
  // values that control verified boot and rollback.
  const int allowed_milestones = 0;
  const int min_kernel_version = 3;
  fake_hw->SetMinKernelKeyVersion(min_kernel_version);
  fake_hw->SetMaxKernelKeyRollforward(kRollforwardInfinity);
  EXPECT_EQ(min_kernel_version, fake_hw->GetMinKernelKeyVersion());
  EXPECT_EQ(kRollforwardInfinity, fake_hw->GetMaxKernelKeyRollforward());

  EXPECT_CALL(
      *FakeSystemState::Get()->mock_metrics_reporter(),
      ReportKeyVersionMetrics(min_kernel_version, kRollforwardInfinity, true))
      .Times(1);

  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.is_consumer_device = false;
  tuc_params_.rollback_allowed_milestones = allowed_milestones;
  tuc_params_.is_policy_loaded = true;

  EXPECT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);

  // Verify that with rollback disabled that kernel_max_rollforward
  // was set to logical infinity.
  EXPECT_EQ(min_kernel_version, fake_hw->GetMinKernelKeyVersion());
  EXPECT_EQ(kRollforwardInfinity, fake_hw->GetMaxKernelKeyRollforward());
}

TEST_F(OmahaRequestActionTest, RollbackResponseParsedNoEntries) {
  fake_update_response_.rollback = true;
  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.is_consumer_device = false;
  tuc_params_.rollback_allowed_milestones = 4;
  tuc_params_.is_policy_loaded = true;

  EXPECT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);
  EXPECT_TRUE(response_.is_rollback);
}

TEST_F(OmahaRequestActionTest, RollbackResponseValidVersionsParsed) {
  fake_update_response_.rollback_firmware_version = "1.2";
  fake_update_response_.rollback_kernel_version = "3.4";
  fake_update_response_.rollback = true;
  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.is_consumer_device = false;
  tuc_params_.rollback_allowed_milestones = 4;
  tuc_params_.is_policy_loaded = true;

  EXPECT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);
  EXPECT_TRUE(response_.is_rollback);
  EXPECT_EQ(1, response_.rollback_key_version.firmware_key);
  EXPECT_EQ(2, response_.rollback_key_version.firmware);
  EXPECT_EQ(3, response_.rollback_key_version.kernel_key);
  EXPECT_EQ(4, response_.rollback_key_version.kernel);
}

TEST_F(OmahaRequestActionTest,
       TestUpdateFirstSeenAtPrefPersistedIfUpdateExists) {
  FakeClock fake_clock;
  Time now = Time::Now();
  fake_clock.SetWallclockTime(now);
  FakeSystemState::Get()->set_clock(&fake_clock);
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
  EXPECT_TRUE(fake_prefs_->Exists(kPrefsUpdateFirstSeenAt));

  int64_t stored_first_seen_at_time;
  EXPECT_TRUE(fake_prefs_->GetInt64(kPrefsUpdateFirstSeenAt,
                                    &stored_first_seen_at_time));
  EXPECT_EQ(now.ToInternalValue(), stored_first_seen_at_time);
}

TEST_F(OmahaRequestActionTest,
       TestUpdateFirstSeenAtPrefNotPersistedIfUpdateFails) {
  FakeClock fake_clock;
  Time now = Time::Now();
  fake_clock.SetWallclockTime(now);
  FakeSystemState::Get()->set_clock(&fake_clock);

  tuc_params_.http_response = fake_update_response_.GetNoUpdateResponse();
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_FALSE(response_.update_exists);
  EXPECT_FALSE(fake_prefs_->Exists(kPrefsUpdateFirstSeenAt));
}

TEST_F(OmahaRequestActionTest, InstallTest) {
  request_params_.set_is_install(true);
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId("dlc_no_0"), {.name = "dlc_no_0"}},
       {request_params_.GetDlcAppId("dlc_no_1"), {.name = "dlc_no_1"}}});
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  for (const auto& it : request_params_.dlc_apps_params()) {
    EXPECT_NE(string::npos, post_str_.find("appid=\"" + it.first + "\""));
  }
  EXPECT_NE(string::npos,
            post_str_.find("appid=\"" + fake_update_response_.app_id + "\""));

  // Count number of updatecheck tag in response_.
  int updatecheck_count = 0;
  size_t pos = 0;
  while ((pos = post_str_.find("<updatecheck", pos)) != string::npos) {
    updatecheck_count++;
    pos++;
  }
  EXPECT_EQ(request_params_.dlc_apps_params().size(), updatecheck_count);
  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, InstallMissingPlatformVersionTest) {
  fake_update_response_.multi_app_skip_updatecheck = true;
  fake_update_response_.multi_app_no_update = false;
  request_params_.set_is_install(true);
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId("dlc_no_0"), {.name = "dlc_no_0"}},
       {request_params_.GetDlcAppId("dlc_no_1"), {.name = "dlc_no_1"}}});
  request_params_.set_app_id(fake_update_response_.app_id_skip_updatecheck);
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
  EXPECT_EQ(fake_update_response_.version, response_.version);
}

TEST_F(OmahaRequestActionTest, UpdateWithDlcTest) {
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(kDlcId1), {.name = kDlcId1}}});
  fake_update_response_.dlc_app_update = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  EXPECT_CALL(mock_excluder_, IsExcluded(_)).WillRepeatedly(Return(false));
  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_EQ(response_.packages.size(), 2u);
  // Two candidate URLs.
  EXPECT_EQ(response_.packages[1].payload_urls.size(), 2u);
  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, UpdateWithPartiallyExcludedDlcTest) {
  const string kDlcAppId = request_params_.GetDlcAppId(kDlcId1);
  request_params_.set_dlc_apps_params({{kDlcAppId, {.name = kDlcId1}}});
  fake_update_response_.dlc_app_update = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  // The first DLC candidate URL is excluded.
  EXPECT_CALL(mock_excluder_, IsExcluded(_))
      .WillOnce(Return(true))
      .WillOnce(Return(false));
  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_EQ(response_.packages.size(), 2u);
  // One candidate URL.
  EXPECT_EQ(response_.packages[1].payload_urls.size(), 1u);
  EXPECT_TRUE(response_.update_exists);
  EXPECT_TRUE(request_params_.dlc_apps_params().at(kDlcAppId).updated);
}

TEST_F(OmahaRequestActionTest, UpdateWithExcludedDlcTest) {
  const string kDlcAppId = request_params_.GetDlcAppId(kDlcId1);
  request_params_.set_dlc_apps_params({{kDlcAppId, {.name = kDlcId1}}});
  fake_update_response_.dlc_app_update = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  // Both DLC candidate URLs are excluded.
  EXPECT_CALL(mock_excluder_, IsExcluded(_))
      .WillOnce(Return(true))
      .WillOnce(Return(true));
  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_EQ(response_.packages.size(), 1u);
  EXPECT_TRUE(response_.update_exists);
  EXPECT_FALSE(request_params_.dlc_apps_params().at(kDlcAppId).updated);
}

TEST_F(OmahaRequestActionTest, UpdateWithDeprecatedDlcTest) {
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(kDlcId2), {.name = kDlcId2}}});
  fake_update_response_.dlc_app_no_update = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  EXPECT_CALL(mock_excluder_, IsExcluded(_)).WillRepeatedly(Return(false));
  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, UpdateWithDlcAndDeprecatedDlcTest) {
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(kDlcId1), {.name = kDlcId1}},
       {request_params_.GetDlcAppId(kDlcId2), {.name = kDlcId2}}});
  fake_update_response_.dlc_app_update = true;
  fake_update_response_.dlc_app_no_update = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  EXPECT_CALL(mock_excluder_, IsExcluded(_)).WillRepeatedly(Return(false));
  ASSERT_TRUE(TestUpdateCheck());

  EXPECT_TRUE(response_.update_exists);
}

TEST_F(OmahaRequestActionTest, PastRollbackVersionsNoEntries) {
  fake_update_response_.rollback = true;
  fake_update_response_.rollback_allowed_milestones = 4;
  request_params_.set_rollback_allowed_milestones(4);
  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.is_consumer_device = false;
  tuc_params_.rollback_allowed_milestones = 4;
  tuc_params_.is_policy_loaded = true;

  EXPECT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);
  EXPECT_TRUE(response_.is_rollback);
  EXPECT_EQ(std::numeric_limits<uint16_t>::max(),
            response_.past_rollback_key_version.firmware_key);
  EXPECT_EQ(std::numeric_limits<uint16_t>::max(),
            response_.past_rollback_key_version.firmware);
  EXPECT_EQ(std::numeric_limits<uint16_t>::max(),
            response_.past_rollback_key_version.kernel_key);
  EXPECT_EQ(std::numeric_limits<uint16_t>::max(),
            response_.past_rollback_key_version.kernel);
}

TEST_F(OmahaRequestActionTest, PastRollbackVersionsValidEntries) {
  request_params_.set_rollback_allowed_milestones(4);
  fake_update_response_.rollback = true;
  fake_update_response_.rollback_allowed_milestones = 4;
  fake_update_response_.rollback_firmware_version = "4.3";
  fake_update_response_.rollback_kernel_version = "2.1";
  fake_update_response_.past_rollback_key_version =
      std::make_pair("16.15", "14.13");
  fake_update_response_.deadline = "20101020";
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.is_consumer_device = false;
  tuc_params_.rollback_allowed_milestones = 4;
  tuc_params_.is_policy_loaded = true;

  EXPECT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);
  EXPECT_TRUE(response_.is_rollback);
  EXPECT_EQ(16, response_.past_rollback_key_version.firmware_key);
  EXPECT_EQ(15, response_.past_rollback_key_version.firmware);
  EXPECT_EQ(14, response_.past_rollback_key_version.kernel_key);
  EXPECT_EQ(13, response_.past_rollback_key_version.kernel);
}

TEST_F(OmahaRequestActionTest, MismatchNumberOfVersions) {
  fake_update_response_.rollback = true;
  fake_update_response_.rollback_allowed_milestones = 2;
  fake_update_response_.deadline = "20101020";
  request_params_.set_rollback_allowed_milestones(4);

  // Since |request_params_.rollback_allowed_milestones| is 4 but the response
  // is constructed with |fake_update_response_.rollback_allowed_milestones| set
  // to 2, OmahaRequestAction will look for the key values of N-4 version but
  // only the N-2 version will exist.
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  tuc_params_.is_consumer_device = false;
  tuc_params_.rollback_allowed_milestones = 2;
  tuc_params_.is_policy_loaded = true;

  EXPECT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(response_.update_exists);
  EXPECT_TRUE(response_.is_rollback);
  EXPECT_EQ(std::numeric_limits<uint16_t>::max(),
            response_.past_rollback_key_version.firmware_key);
  EXPECT_EQ(std::numeric_limits<uint16_t>::max(),
            response_.past_rollback_key_version.firmware);
  EXPECT_EQ(std::numeric_limits<uint16_t>::max(),
            response_.past_rollback_key_version.kernel_key);
  EXPECT_EQ(std::numeric_limits<uint16_t>::max(),
            response_.past_rollback_key_version.kernel);
}

TEST_F(OmahaRequestActionTest, IncludeRequisitionTest) {
  request_params_.set_device_requisition("remora");
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_NE(string::npos, post_str_.find("requisition=\"remora\""));
}

TEST_F(OmahaRequestActionTest, NoIncludeRequisitionTest) {
  request_params_.set_device_requisition("");
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();
  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_EQ(string::npos, post_str_.find("requisition"));
}

TEST_F(OmahaRequestActionTest, PersistEolDateTest) {
  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response "
      "protocol=\"3.0\"><app appid=\"test-app-id\" status=\"ok\">"
      "<ping status=\"ok\"/><updatecheck status=\"noupdate\" "
      "_eol_date=\"200\" _foo=\"bar\"/></app></response>";
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  string eol_date;
  EXPECT_TRUE(FakeSystemState::Get()->prefs()->GetString(kPrefsOmahaEolDate,
                                                         &eol_date));
  EXPECT_EQ("200", eol_date);
}

TEST_F(OmahaRequestActionTest, PersistEolMissingDateTest) {
  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response "
      "protocol=\"3.0\"><app appid=\"test-app-id\" status=\"ok\">"
      "<ping status=\"ok\"/><updatecheck status=\"noupdate\" "
      "_foo=\"bar\"/></app></response>";
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  const string kDate = "123";
  FakeSystemState::Get()->prefs()->SetString(kPrefsOmahaEolDate, kDate);

  ASSERT_TRUE(TestUpdateCheck());

  string eol_date;
  EXPECT_TRUE(FakeSystemState::Get()->prefs()->GetString(kPrefsOmahaEolDate,
                                                         &eol_date));
  EXPECT_EQ(kDate, eol_date);
}

TEST_F(OmahaRequestActionTest, PersistEolBadDateTest) {
  tuc_params_.http_response =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?><response "
      "protocol=\"3.0\"><app appid=\"test-app-id\" status=\"ok\">"
      "<ping status=\"ok\"/><updatecheck status=\"noupdate\" "
      "_eol_date=\"bad\" foo=\"bar\"/></app></response>";
  tuc_params_.expected_check_result = metrics::CheckResult::kNoUpdateAvailable;
  tuc_params_.expected_check_reaction = metrics::CheckReaction::kUnset;

  ASSERT_TRUE(TestUpdateCheck());

  string eol_date;
  EXPECT_TRUE(FakeSystemState::Get()->prefs()->GetString(kPrefsOmahaEolDate,
                                                         &eol_date));
  EXPECT_EQ(kEolDateInvalid, StringToEolDate(eol_date));
}

TEST_F(OmahaRequestActionDlcPingTest, StorePingReplyNoPing) {
  OmahaRequestParams::AppParams app_param = {.name = dlc_id_};
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(dlc_id_), app_param}});

  ASSERT_TRUE(TestUpdateCheck());

  int64_t temp_int;
  // If there was no ping, the metadata files shouldn't exist yet.
  EXPECT_FALSE(fake_prefs_->GetInt64(active_key_, &temp_int));
  EXPECT_FALSE(fake_prefs_->GetInt64(last_active_key_, &temp_int));
  EXPECT_FALSE(fake_prefs_->GetInt64(last_rollcall_key_, &temp_int));
}

TEST_F(OmahaRequestActionDlcPingTest, StorePingReplyActiveTest) {
  // Create Active value
  fake_prefs_->SetInt64(active_key_, 0);

  OmahaRequestParams::AppParams app_param = {
      .active_counting_type = OmahaRequestParams::kDateBased,
      .name = dlc_id_,
      .ping_active = 1,
      .send_ping = true};
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(dlc_id_), app_param}});

  int64_t temp_int;
  string temp_str;
  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(fake_prefs_->GetInt64(active_key_, &temp_int));
  EXPECT_EQ(temp_int, kPingInactiveValue);
  EXPECT_TRUE(fake_prefs_->GetString(last_active_key_, &temp_str));
  EXPECT_EQ(temp_str, "4763");
  EXPECT_TRUE(fake_prefs_->GetString(last_rollcall_key_, &temp_str));
  EXPECT_EQ(temp_str, "4763");
}

TEST_F(OmahaRequestActionDlcPingTest, StorePingReplyInactiveTest) {
  // Create Active value
  fake_prefs_->SetInt64(active_key_, 0);

  OmahaRequestParams::AppParams app_param = {
      .active_counting_type = OmahaRequestParams::kDateBased,
      .name = dlc_id_,
      .ping_active = 0,
      .send_ping = true};
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(dlc_id_), app_param}});

  // Set the previous active value to an older value than 4763.
  fake_prefs_->SetString(last_active_key_, "555");

  int64_t temp_int;
  ASSERT_TRUE(TestUpdateCheck());
  EXPECT_TRUE(fake_prefs_->GetInt64(active_key_, &temp_int));
  EXPECT_EQ(temp_int, kPingInactiveValue);
  string temp_str;
  EXPECT_TRUE(fake_prefs_->GetString(last_active_key_, &temp_str));
  EXPECT_EQ(temp_str, "555");
  EXPECT_TRUE(fake_prefs_->GetString(last_rollcall_key_, &temp_str));
  EXPECT_EQ(temp_str, "4763");
}

TEST_F(OmahaRequestActionTest, OmahaResponseUpdateCanExcludeCheck) {
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(kDlcId1), {.name = kDlcId1}}});
  fake_update_response_.dlc_app_update = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  EXPECT_CALL(mock_excluder_, IsExcluded(_)).WillRepeatedly(Return(false));
  ASSERT_TRUE(TestUpdateCheck());
  ASSERT_TRUE(delegate_.omaha_response_);
  const auto& packages = delegate_.omaha_response_->packages;
  ASSERT_EQ(packages.size(), 2);

  EXPECT_FALSE(packages[0].can_exclude);
  EXPECT_TRUE(packages[1].can_exclude);
}

TEST_F(OmahaRequestActionTest, OmahaResponseInstallCannotExcludeCheck) {
  request_params_.set_is_install(true);
  request_params_.set_dlc_apps_params(
      {{request_params_.GetDlcAppId(kDlcId1), {.name = kDlcId1}}});
  fake_update_response_.dlc_app_update = true;
  tuc_params_.http_response = fake_update_response_.GetUpdateResponse();

  EXPECT_CALL(mock_excluder_, IsExcluded(_)).WillRepeatedly(Return(false));
  ASSERT_TRUE(TestUpdateCheck());
  ASSERT_TRUE(delegate_.omaha_response_);
  const auto& packages = delegate_.omaha_response_->packages;
  ASSERT_EQ(packages.size(), 2);

  EXPECT_FALSE(packages[0].can_exclude);
  EXPECT_FALSE(packages[1].can_exclude);
}

}  // namespace chromeos_update_engine
