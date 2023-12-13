//
// Copyright (C) 2018 The Android Open Source Project
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

#ifndef UPDATE_ENGINE_PAYLOAD_CONSUMER_PAYLOAD_METADATA_H_
#define UPDATE_ENGINE_PAYLOAD_CONSUMER_PAYLOAD_METADATA_H_

#include <inttypes.h>

#include <string>
#include <vector>

#include <base/macros.h>
#include <brillo/secure_blob.h>

#include "update_engine/common/error_code.h"
#include "update_engine/common/platform_constants.h"
#include "update_engine/payload_consumer/payload_verifier.h"
#include "update_engine/update_metadata.pb.h"

namespace chromeos_update_engine {

enum class MetadataParseResult {
  kSuccess,
  kError,
  kInsufficientData,
};

// This class parses payload metadata and validate its signature.
class PayloadMetadata {
 public:
  static const uint64_t kDeltaVersionOffset;
  static const uint64_t kDeltaVersionSize;
  static const uint64_t kDeltaManifestSizeOffset;
  static const uint64_t kDeltaManifestSizeSize;
  static const uint64_t kDeltaMetadataSignatureSizeSize;

  PayloadMetadata() = default;

  // Attempts to parse the update payload header starting from the beginning of
  // |payload|. On success, returns kMetadataParseSuccess. Returns
  // kMetadataParseInsufficientData if more data is needed to parse the complete
  // metadata. Returns kMetadataParseError if the metadata can't be parsed given
  // the payload.
  MetadataParseResult ParsePayloadHeader(const brillo::Blob& payload,
                                         ErrorCode* error);
  MetadataParseResult ParsePayloadHeader(const unsigned char* payload,
                                         size_t size,
                                         ErrorCode* error);
  // Simpler version of the above, returns true on success.
  bool ParsePayloadHeader(const brillo::Blob& payload);

  // Given the |payload|, verifies that the signed hash of its metadata matches
  // |metadata_signature| (if present) or the metadata signature in payload
  // itself (if present). Returns ErrorCode::kSuccess on match or a suitable
  // error code otherwise. This method must be called before any part of the
  // metadata is parsed so that an on-path attack on the SSL connection
  // to the payload server doesn't exploit any vulnerability in the code that
  // parses the protocol buffer.
  ErrorCode ValidateMetadataSignature(
      const brillo::Blob& payload,
      const std::string& metadata_signature,
      const PayloadVerifier& payload_verifier) const;

  // Returns the major payload version. If the version was not yet parsed,
  // returns zero.
  uint64_t GetMajorVersion() const { return major_payload_version_; }

  // Returns the size of the payload metadata, which includes the payload header
  // and the manifest. If the header was not yet parsed, returns zero.
  uint64_t GetMetadataSize() const { return metadata_size_; }

  // Returns the size of the payload metadata signature. If the header was not
  // yet parsed, returns zero.
  uint32_t GetMetadataSignatureSize() const { return metadata_signature_size_; }

  // Set |*out_manifest| to the manifest in |payload|.
  // Returns true on success.
  bool GetManifest(const brillo::Blob& payload,
                   DeltaArchiveManifest* out_manifest) const;

  bool GetManifest(const unsigned char* payload,
                   size_t size,
                   DeltaArchiveManifest* out_manifest) const;

  // Parses a payload file |payload_path| and prepares the metadata properties,
  // manifest and metadata signatures. Can be used as an easy to use utility to
  // get the payload information without manually the process.
  bool ParsePayloadFile(const std::string& payload_path,
                        DeltaArchiveManifest* manifest,
                        Signatures* metadata_signatures);

 private:
  // Returns the byte offset at which the manifest protobuf begins in a payload.
  uint64_t GetManifestOffset() const;

  // Returns the byte offset where the size of the metadata signature is stored
  // in a payload.
  uint64_t GetMetadataSignatureSizeOffset() const;

  uint64_t metadata_size_{0};
  uint64_t manifest_size_{0};
  uint32_t metadata_signature_size_{0};
  uint64_t major_payload_version_{0};

  DISALLOW_COPY_AND_ASSIGN(PayloadMetadata);
};

}  // namespace chromeos_update_engine

#endif  // UPDATE_ENGINE_PAYLOAD_CONSUMER_PAYLOAD_METADATA_H_
