// Copyright (C) 2019 Google LLC
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

#include "icing/scoring/scorer.h"

#include <memory>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "icing/document-builder.h"
#include "icing/file/filesystem.h"
#include "icing/index/hit/doc-hit-info.h"
#include "icing/proto/document.pb.h"
#include "icing/proto/schema.pb.h"
#include "icing/proto/scoring.pb.h"
#include "icing/schema-builder.h"
#include "icing/schema/schema-store.h"
#include "icing/store/document-id.h"
#include "icing/store/document-store.h"
#include "icing/testing/common-matchers.h"
#include "icing/testing/fake-clock.h"
#include "icing/testing/tmp-directory.h"

namespace icing {
namespace lib {

namespace {
using ::testing::Eq;

constexpr PropertyConfigProto_DataType_Code TYPE_STRING =
    PropertyConfigProto_DataType_Code_STRING;

constexpr PropertyConfigProto_Cardinality_Code CARDINALITY_REQUIRED =
    PropertyConfigProto_Cardinality_Code_REQUIRED;

class ScorerTest : public testing::Test {
 protected:
  ScorerTest()
      : test_dir_(GetTestTempDir() + "/icing"),
        doc_store_dir_(test_dir_ + "/doc_store"),
        schema_store_dir_(test_dir_ + "/schema_store") {}

  void SetUp() override {
    filesystem_.DeleteDirectoryRecursively(test_dir_.c_str());
    filesystem_.CreateDirectoryRecursively(doc_store_dir_.c_str());
    filesystem_.CreateDirectoryRecursively(schema_store_dir_.c_str());

    fake_clock1_.SetSystemTimeMilliseconds(1571100000000);
    fake_clock2_.SetSystemTimeMilliseconds(1572200000000);

    ICING_ASSERT_OK_AND_ASSIGN(
        schema_store_,
        SchemaStore::Create(&filesystem_, schema_store_dir_, &fake_clock1_));

    ICING_ASSERT_OK_AND_ASSIGN(
        DocumentStore::CreateResult create_result,
        DocumentStore::Create(&filesystem_, doc_store_dir_, &fake_clock1_,
                              schema_store_.get()));
    document_store_ = std::move(create_result.document_store);

    // Creates a simple email schema
    SchemaProto test_email_schema =
        SchemaBuilder()
            .AddType(SchemaTypeConfigBuilder().SetType("email").AddProperty(
                PropertyConfigBuilder()
                    .SetName("subject")
                    .SetDataType(TYPE_STRING)
                    .SetCardinality(CARDINALITY_REQUIRED)))
            .Build();

    ICING_ASSERT_OK(schema_store_->SetSchema(test_email_schema));
  }

  void TearDown() override {
    document_store_.reset();
    schema_store_.reset();
    filesystem_.DeleteDirectoryRecursively(test_dir_.c_str());
  }

  DocumentStore* document_store() { return document_store_.get(); }

  const FakeClock& fake_clock1() { return fake_clock1_; }

  const FakeClock& fake_clock2() { return fake_clock2_; }

  void SetFakeClock1Time(int64_t new_time) {
    fake_clock1_.SetSystemTimeMilliseconds(new_time);
  }

 private:
  const std::string test_dir_;
  const std::string doc_store_dir_;
  const std::string schema_store_dir_;
  Filesystem filesystem_;
  std::unique_ptr<SchemaStore> schema_store_;
  std::unique_ptr<DocumentStore> document_store_;
  FakeClock fake_clock1_;
  FakeClock fake_clock2_;
};

UsageReport CreateUsageReport(std::string name_space, std::string uri,
                              int64 timestamp_ms,
                              UsageReport::UsageType usage_type) {
  UsageReport usage_report;
  usage_report.set_document_namespace(name_space);
  usage_report.set_document_uri(uri);
  usage_report.set_usage_timestamp_ms(timestamp_ms);
  usage_report.set_usage_type(usage_type);
  return usage_report;
}

TEST_F(ScorerTest, CreationWithNullPointerShouldFail) {
  EXPECT_THAT(Scorer::Create(ScoringSpecProto::RankingStrategy::DOCUMENT_SCORE,
                             /*default_score=*/0, /*document_store=*/nullptr),
              StatusIs(libtextclassifier3::StatusCode::FAILED_PRECONDITION));
}

TEST_F(ScorerTest, ShouldGetDefaultScoreIfDocumentDoesntExist) {
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer,
      Scorer::Create(ScoringSpecProto::RankingStrategy::DOCUMENT_SCORE,
                     /*default_score=*/10, document_store()));

  // Non existent document id
  DocHitInfo docHitInfo = DocHitInfo(/*document_id_in=*/1);
  // The caller-provided default score is returned
  EXPECT_THAT(scorer->GetScore(docHitInfo), Eq(10));
}

TEST_F(ScorerTest, ShouldGetDefaultScoreIfDocumentIsDeleted) {
  // Creates a test document with a provided score
  DocumentProto test_document = DocumentBuilder()
                                    .SetKey("icing", "email/1")
                                    .SetSchema("email")
                                    .AddStringProperty("subject", "subject foo")
                                    .SetScore(42)
                                    .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));

  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer,
      Scorer::Create(ScoringSpecProto::RankingStrategy::DOCUMENT_SCORE,
                     /*default_score=*/10, document_store()));

  DocHitInfo docHitInfo = DocHitInfo(document_id);

  // The document's score is returned
  EXPECT_THAT(scorer->GetScore(docHitInfo), Eq(42));

  // Delete the document and check that the caller-provided default score is
  // returned
  EXPECT_THAT(document_store()->Delete(document_id), IsOk());
  EXPECT_THAT(scorer->GetScore(docHitInfo), Eq(10));
}

TEST_F(ScorerTest, ShouldGetDefaultScoreIfDocumentIsExpired) {
  // Creates a test document with a provided score
  int64_t creation_time = fake_clock1().GetSystemTimeMilliseconds();
  int64_t ttl = 100;
  DocumentProto test_document = DocumentBuilder()
                                    .SetKey("icing", "email/1")
                                    .SetSchema("email")
                                    .AddStringProperty("subject", "subject foo")
                                    .SetScore(42)
                                    .SetCreationTimestampMs(creation_time)
                                    .SetTtlMs(ttl)
                                    .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));

  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer,
      Scorer::Create(ScoringSpecProto::RankingStrategy::DOCUMENT_SCORE,
                     /*default_score=*/10, document_store()));

  DocHitInfo docHitInfo = DocHitInfo(document_id);

  // The document's score is returned since the document hasn't expired yet.
  EXPECT_THAT(scorer->GetScore(docHitInfo), Eq(42));

  // Expire the document and check that the caller-provided default score is
  // returned
  SetFakeClock1Time(creation_time + ttl + 10);
  EXPECT_THAT(scorer->GetScore(docHitInfo), Eq(10));
}

TEST_F(ScorerTest, ShouldGetDefaultDocumentScore) {
  // Creates a test document with the default document score 0
  DocumentProto test_document =
      DocumentBuilder()
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock1().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer,
      Scorer::Create(ScoringSpecProto::RankingStrategy::DOCUMENT_SCORE,
                     /*default_score=*/10, document_store()));

  DocHitInfo docHitInfo = DocHitInfo(document_id);
  EXPECT_THAT(scorer->GetScore(docHitInfo), Eq(0));
}

TEST_F(ScorerTest, ShouldGetCorrectDocumentScore) {
  // Creates a test document with document score 5
  DocumentProto test_document =
      DocumentBuilder()
          .SetScore(5)
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock2().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer,
      Scorer::Create(ScoringSpecProto::RankingStrategy::DOCUMENT_SCORE,
                     /*default_score=*/0, document_store()));

  DocHitInfo docHitInfo = DocHitInfo(document_id);
  EXPECT_THAT(scorer->GetScore(docHitInfo), Eq(5));
}

// See scoring-processor_test.cc and icing-search-engine_test.cc for better
// Bm25F scoring tests.
TEST_F(ScorerTest, QueryIteratorNullRelevanceScoreShouldReturnDefaultScore) {
  // Creates a test document with document score 5
  DocumentProto test_document =
      DocumentBuilder()
          .SetScore(5)
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock2().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer,
      Scorer::Create(ScoringSpecProto::RankingStrategy::RELEVANCE_SCORE,
                     /*default_score=*/10, document_store()));

  DocHitInfo docHitInfo = DocHitInfo(document_id);
  EXPECT_THAT(scorer->GetScore(docHitInfo), Eq(10));
}

TEST_F(ScorerTest, ShouldGetCorrectCreationTimestampScore) {
  // Creates test_document1 with fake timestamp1
  DocumentProto test_document1 =
      DocumentBuilder()
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock1().GetSystemTimeMilliseconds())
          .Build();
  // Creates test_document2 with fake timestamp2
  DocumentProto test_document2 =
      DocumentBuilder()
          .SetKey("icing", "email/2")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo 2")
          .SetCreationTimestampMs(fake_clock2().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id1,
                             document_store()->Put(test_document1));
  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id2,
                             document_store()->Put(test_document2));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer,
      Scorer::Create(ScoringSpecProto::RankingStrategy::CREATION_TIMESTAMP,
                     /*default_score=*/0, document_store()));

  DocHitInfo docHitInfo1 = DocHitInfo(document_id1);
  DocHitInfo docHitInfo2 = DocHitInfo(document_id2);
  EXPECT_THAT(scorer->GetScore(docHitInfo1),
              Eq(fake_clock1().GetSystemTimeMilliseconds()));
  EXPECT_THAT(scorer->GetScore(docHitInfo2),
              Eq(fake_clock2().GetSystemTimeMilliseconds()));
}

TEST_F(ScorerTest, ShouldGetCorrectUsageCountScoreForType1) {
  DocumentProto test_document =
      DocumentBuilder()
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock1().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));

  // Create 3 scorers for 3 different usage types.
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer1,
      Scorer::Create(ScoringSpecProto::RankingStrategy::USAGE_TYPE1_COUNT,
                     /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer2,
      Scorer::Create(ScoringSpecProto::RankingStrategy::USAGE_TYPE2_COUNT,
                     /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer3,
      Scorer::Create(ScoringSpecProto::RankingStrategy::USAGE_TYPE3_COUNT,
                     /*default_score=*/0, document_store()));
  DocHitInfo docHitInfo = DocHitInfo(document_id);
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));

  // Report a type1 usage.
  UsageReport usage_report_type1 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/0,
      UsageReport::USAGE_TYPE1);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type1));

  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(1));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));
}

TEST_F(ScorerTest, ShouldGetCorrectUsageCountScoreForType2) {
  DocumentProto test_document =
      DocumentBuilder()
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock1().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));

  // Create 3 scorers for 3 different usage types.
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer1,
      Scorer::Create(ScoringSpecProto::RankingStrategy::USAGE_TYPE1_COUNT,
                     /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer2,
      Scorer::Create(ScoringSpecProto::RankingStrategy::USAGE_TYPE2_COUNT,
                     /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer3,
      Scorer::Create(ScoringSpecProto::RankingStrategy::USAGE_TYPE3_COUNT,
                     /*default_score=*/0, document_store()));
  DocHitInfo docHitInfo = DocHitInfo(document_id);
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));

  // Report a type2 usage.
  UsageReport usage_report_type2 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/0,
      UsageReport::USAGE_TYPE2);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type2));

  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(1));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));
}

TEST_F(ScorerTest, ShouldGetCorrectUsageCountScoreForType3) {
  DocumentProto test_document =
      DocumentBuilder()
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock1().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));

  // Create 3 scorers for 3 different usage types.
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer1,
      Scorer::Create(ScoringSpecProto::RankingStrategy::USAGE_TYPE1_COUNT,
                     /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer2,
      Scorer::Create(ScoringSpecProto::RankingStrategy::USAGE_TYPE2_COUNT,
                     /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer3,
      Scorer::Create(ScoringSpecProto::RankingStrategy::USAGE_TYPE3_COUNT,
                     /*default_score=*/0, document_store()));
  DocHitInfo docHitInfo = DocHitInfo(document_id);
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));

  // Report a type1 usage.
  UsageReport usage_report_type3 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/0,
      UsageReport::USAGE_TYPE3);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type3));

  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(1));
}

TEST_F(ScorerTest, ShouldGetCorrectUsageTimestampScoreForType1) {
  DocumentProto test_document =
      DocumentBuilder()
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock1().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));

  // Create 3 scorers for 3 different usage types.
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer1,
      Scorer::Create(
          ScoringSpecProto::RankingStrategy::USAGE_TYPE1_LAST_USED_TIMESTAMP,
          /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer2,
      Scorer::Create(
          ScoringSpecProto::RankingStrategy::USAGE_TYPE2_LAST_USED_TIMESTAMP,
          /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer3,
      Scorer::Create(
          ScoringSpecProto::RankingStrategy::USAGE_TYPE3_LAST_USED_TIMESTAMP,
          /*default_score=*/0, document_store()));
  DocHitInfo docHitInfo = DocHitInfo(document_id);
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));

  UsageReport usage_report_type1_time1 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/1000,
      UsageReport::USAGE_TYPE1);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type1_time1));
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(1000));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));

  // Report usage with timestamp = 5000ms, score should be updated.
  UsageReport usage_report_type1_time5 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/5000,
      UsageReport::USAGE_TYPE1);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type1_time5));
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(5000));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));

  // Report usage with timestamp = 3000ms, score should not be updated.
  UsageReport usage_report_type1_time3 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/3000,
      UsageReport::USAGE_TYPE1);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type1_time3));
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(5000));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));
}

TEST_F(ScorerTest, ShouldGetCorrectUsageTimestampScoreForType2) {
  DocumentProto test_document =
      DocumentBuilder()
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock1().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));

  // Create 3 scorers for 3 different usage types.
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer1,
      Scorer::Create(
          ScoringSpecProto::RankingStrategy::USAGE_TYPE1_LAST_USED_TIMESTAMP,
          /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer2,
      Scorer::Create(
          ScoringSpecProto::RankingStrategy::USAGE_TYPE2_LAST_USED_TIMESTAMP,
          /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer3,
      Scorer::Create(
          ScoringSpecProto::RankingStrategy::USAGE_TYPE3_LAST_USED_TIMESTAMP,
          /*default_score=*/0, document_store()));
  DocHitInfo docHitInfo = DocHitInfo(document_id);
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));

  UsageReport usage_report_type2_time1 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/1000,
      UsageReport::USAGE_TYPE2);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type2_time1));
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(1000));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));

  // Report usage with timestamp = 5000ms, score should be updated.
  UsageReport usage_report_type2_time5 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/5000,
      UsageReport::USAGE_TYPE2);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type2_time5));
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(5000));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));

  // Report usage with timestamp = 3000ms, score should not be updated.
  UsageReport usage_report_type2_time3 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/3000,
      UsageReport::USAGE_TYPE2);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type2_time3));
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(5000));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));
}

TEST_F(ScorerTest, ShouldGetCorrectUsageTimestampScoreForType3) {
  DocumentProto test_document =
      DocumentBuilder()
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock1().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));

  // Create 3 scorers for 3 different usage types.
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer1,
      Scorer::Create(
          ScoringSpecProto::RankingStrategy::USAGE_TYPE1_LAST_USED_TIMESTAMP,
          /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer2,
      Scorer::Create(
          ScoringSpecProto::RankingStrategy::USAGE_TYPE2_LAST_USED_TIMESTAMP,
          /*default_score=*/0, document_store()));
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer3,
      Scorer::Create(
          ScoringSpecProto::RankingStrategy::USAGE_TYPE3_LAST_USED_TIMESTAMP,
          /*default_score=*/0, document_store()));
  DocHitInfo docHitInfo = DocHitInfo(document_id);
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(0));

  UsageReport usage_report_type3_time1 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/1000,
      UsageReport::USAGE_TYPE3);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type3_time1));
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(1000));

  // Report usage with timestamp = 5000ms, score should be updated.
  UsageReport usage_report_type3_time5 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/5000,
      UsageReport::USAGE_TYPE3);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type3_time5));
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(5000));

  // Report usage with timestamp = 3000ms, score should not be updated.
  UsageReport usage_report_type3_time3 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1", /*timestamp_ms=*/3000,
      UsageReport::USAGE_TYPE3);
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type3_time3));
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer2->GetScore(docHitInfo), Eq(0));
  EXPECT_THAT(scorer3->GetScore(docHitInfo), Eq(5000));
}

TEST_F(ScorerTest, NoScorerShouldAlwaysReturnDefaultScore) {
  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer,
      Scorer::Create(ScoringSpecProto::RankingStrategy::NONE,
                     /*default_score=*/3, document_store()));

  DocHitInfo docHitInfo1 = DocHitInfo(/*document_id_in=*/0);
  DocHitInfo docHitInfo2 = DocHitInfo(/*document_id_in=*/1);
  DocHitInfo docHitInfo3 = DocHitInfo(/*document_id_in=*/2);
  EXPECT_THAT(scorer->GetScore(docHitInfo1), Eq(3));
  EXPECT_THAT(scorer->GetScore(docHitInfo2), Eq(3));
  EXPECT_THAT(scorer->GetScore(docHitInfo3), Eq(3));

  ICING_ASSERT_OK_AND_ASSIGN(
      scorer, Scorer::Create(ScoringSpecProto::RankingStrategy::NONE,
                             /*default_score=*/111, document_store()));

  docHitInfo1 = DocHitInfo(/*document_id_in=*/4);
  docHitInfo2 = DocHitInfo(/*document_id_in=*/5);
  docHitInfo3 = DocHitInfo(/*document_id_in=*/6);
  EXPECT_THAT(scorer->GetScore(docHitInfo1), Eq(111));
  EXPECT_THAT(scorer->GetScore(docHitInfo2), Eq(111));
  EXPECT_THAT(scorer->GetScore(docHitInfo3), Eq(111));
}

TEST_F(ScorerTest, ShouldScaleUsageTimestampScoreForMaxTimestamp) {
  DocumentProto test_document =
      DocumentBuilder()
          .SetKey("icing", "email/1")
          .SetSchema("email")
          .AddStringProperty("subject", "subject foo")
          .SetCreationTimestampMs(fake_clock1().GetSystemTimeMilliseconds())
          .Build();

  ICING_ASSERT_OK_AND_ASSIGN(DocumentId document_id,
                             document_store()->Put(test_document));

  ICING_ASSERT_OK_AND_ASSIGN(
      std::unique_ptr<Scorer> scorer1,
      Scorer::Create(
          ScoringSpecProto::RankingStrategy::USAGE_TYPE1_LAST_USED_TIMESTAMP,
          /*default_score=*/0, document_store()));
  DocHitInfo docHitInfo = DocHitInfo(document_id);

  // Create usage report for the maximum allowable timestamp.
  UsageReport usage_report_type1 = CreateUsageReport(
      /*name_space=*/"icing", /*uri=*/"email/1",
      /*timestamp_ms=*/std::numeric_limits<uint32_t>::max() * 1000.0,
      UsageReport::USAGE_TYPE1);

  double max_int_usage_timestamp_score =
      std::numeric_limits<uint32_t>::max() * 1000.0;
  ICING_ASSERT_OK(document_store()->ReportUsage(usage_report_type1));
  EXPECT_THAT(scorer1->GetScore(docHitInfo), Eq(max_int_usage_timestamp_score));
}

}  // namespace

}  // namespace lib
}  // namespace icing
