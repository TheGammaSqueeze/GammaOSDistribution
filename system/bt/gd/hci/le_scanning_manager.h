/*
 * Copyright 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <memory>

#include "common/callback.h"
#include "hci/address_with_type.h"
#include "hci/hci_packets.h"
#include "hci/uuid.h"
#include "module.h"

namespace bluetooth {
namespace hci {

using ScannerId = uint8_t;

class AdvertisingFilterOnFoundOnLostInfo {
 public:
  uint8_t scanner_id;
  uint8_t filter_index;
  uint8_t advertiser_state;
  AdvtInfoPresent advertiser_info_present;
  Address advertiser_address;
  uint8_t advertiser_address_type;
  uint8_t tx_power;
  int8_t rssi;
  uint16_t time_stamp;
  std::vector<uint8_t> adv_packet;
  std::vector<uint8_t> scan_response;
};

class ScanningCallback {
 public:
  enum ScanningStatus {
    SUCCESS,
    NO_RESOURCES = 0x80,
    INTERNAL_ERROR = 0x85,
  };

  virtual ~ScanningCallback() = default;
  virtual void OnScannerRegistered(
      const bluetooth::hci::Uuid app_uuid, ScannerId scanner_id, ScanningStatus status) = 0;
  virtual void OnScanResult(
      uint16_t event_type,
      uint8_t address_type,
      Address address,
      uint8_t primary_phy,
      uint8_t secondary_phy,
      uint8_t advertising_sid,
      int8_t tx_power,
      int8_t rssi,
      uint16_t periodic_advertising_interval,
      std::vector<uint8_t> advertising_data) = 0;
  virtual void OnTrackAdvFoundLost(AdvertisingFilterOnFoundOnLostInfo on_found_on_lost_info) = 0;
  virtual void OnBatchScanReports(
      int client_if, int status, int report_format, int num_records, std::vector<uint8_t> data) = 0;
  virtual void OnBatchScanThresholdCrossed(int client_if) = 0;
  virtual void OnTimeout() = 0;
  virtual void OnFilterEnable(Enable enable, uint8_t status) = 0;
  virtual void OnFilterParamSetup(uint8_t available_spaces, ApcfAction action, uint8_t status) = 0;
  virtual void OnFilterConfigCallback(
      ApcfFilterType filter_type, uint8_t available_spaces, ApcfAction action, uint8_t status) = 0;
};

class AdvertisingPacketContentFilterCommand {
 public:
  ApcfFilterType filter_type;
  Address address;
  ApcfApplicationAddressType application_address_type;
  Uuid uuid;
  Uuid uuid_mask;
  std::vector<uint8_t> name;
  uint16_t company;
  uint16_t company_mask;
  std::vector<uint8_t> data;
  std::vector<uint8_t> data_mask;
};

class AdvertisingFilterParameter {
 public:
  uint16_t feature_selection;
  uint16_t list_logic_type;
  uint8_t filter_logic_type;
  uint8_t rssi_high_thresh;
  DeliveryMode delivery_mode;
  uint16_t onfound_timeout;
  uint8_t onfound_timeout_cnt;
  uint8_t rssi_low_thres;
  uint16_t onlost_timeout;
  uint16_t num_of_tracking_entries;
};

enum class BatchScanMode : uint8_t {
  DISABLE = 0,
  TRUNCATED = 1,
  FULL = 2,
  TRUNCATED_AND_FULL = 3,
};

class LeScanningManager : public bluetooth::Module {
 public:
  static constexpr uint8_t kMaxAppNum = 32;
  static constexpr uint8_t kAdvertisingDataInfoNotPresent = 0xff;
  static constexpr uint8_t kTxPowerInformationNotPresent = 0x7f;
  static constexpr uint8_t kNotPeriodicAdvertisement = 0x00;
  static constexpr ScannerId kInvalidScannerId = 0xFF;
  LeScanningManager();

  void RegisterScanner(const Uuid app_uuid);

  void Unregister(ScannerId scanner_id);

  void Scan(bool start);

  void SetScanParameters(LeScanType scan_type, uint16_t scan_interval, uint16_t scan_window);

  /* Scan filter */
  void ScanFilterEnable(bool enable);

  void ScanFilterParameterSetup(
      ApcfAction action, uint8_t filter_index, AdvertisingFilterParameter advertising_filter_parameter);

  void ScanFilterAdd(uint8_t filter_index, std::vector<AdvertisingPacketContentFilterCommand> filters);

  /*Batch Scan*/
  void BatchScanConifgStorage(
      uint8_t batch_scan_full_max,
      uint8_t batch_scan_truncated_max,
      uint8_t batch_scan_notify_threshold,
      ScannerId scanner_id);
  void BatchScanEnable(
      BatchScanMode scan_mode,
      uint32_t duty_cycle_scan_window_slots,
      uint32_t duty_cycle_scan_interval_slots,
      BatchScanDiscardRule batch_scan_discard_rule);
  void BatchScanDisable();
  void BatchScanReadReport(ScannerId scanner_id, BatchScanMode scan_mode);

  void TrackAdvertiser(ScannerId scanner_id);

  void RegisterScanningCallback(ScanningCallback* scanning_callback);

  static const ModuleFactory Factory;

 protected:
  void ListDependencies(ModuleList* list) override;

  void Start() override;

  void Stop() override;

  std::string ToString() const override;

 private:
  struct impl;
  std::unique_ptr<impl> pimpl_;
  DISALLOW_COPY_AND_ASSIGN(LeScanningManager);
};

}  // namespace hci
}  // namespace bluetooth
