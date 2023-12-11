
#pragma once

#include <cstdint>
#include <functional>
#include <sstream>
#include <string>
#include <type_traits>

#include "os/log.h"
#include "packet/base_packet_builder.h"
#include "packet/bit_inserter.h"
#include "packet/custom_field_fixed_size_interface.h"
#include "packet/iterator.h"
#include "packet/packet_builder.h"
#include "packet/packet_struct.h"
#include "packet/packet_view.h"

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
#include "packet/raw_builder.h"
#endif
#include "packet/parser/checksum_type_checker.h"
#include "packet/parser/custom_type_checker.h"

#include "hci/address.h"


namespace bluetooth {
namespace security {


using ::bluetooth::hci::Address;

using ::bluetooth::packet::BasePacketBuilder;
using ::bluetooth::packet::BitInserter;
using ::bluetooth::packet::CustomFieldFixedSizeInterface;
using ::bluetooth::packet::CustomTypeChecker;
using ::bluetooth::packet::Iterator;
using ::bluetooth::packet::kLittleEndian;
using ::bluetooth::packet::PacketBuilder;
using ::bluetooth::packet::PacketStruct;
using ::bluetooth::packet::PacketView;

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
using ::bluetooth::packet::RawBuilder;
#endif

using ::bluetooth::packet::parser::ChecksumTypeChecker;

enum class Code : uint8_t {PAIRING_REQUEST = 0x1,PAIRING_RESPONSE = 0x2,PAIRING_CONFIRM = 0x3,PAIRING_RANDOM = 0x4,PAIRING_FAILED = 0x5,ENCRYPTION_INFORMATION = 0x6,CENTRAL_IDENTIFICATION = 0x7,IDENTITY_INFORMATION = 0x8,IDENTITY_ADDRESS_INFORMATION = 0x9,SIGNING_INFORMATION = 0xa,SECURITY_REQUEST = 0xb,PAIRING_PUBLIC_KEY = 0xc,PAIRING_DH_KEY_CHECK = 0xd,PAIRING_KEYPRESS_NOTIFICATION = 0xe,};


enum class IoCapability : uint8_t {DISPLAY_ONLY = 0x0,DISPLAY_YES_NO = 0x1,KEYBOARD_ONLY = 0x2,NO_INPUT_NO_OUTPUT = 0x3,KEYBOARD_DISPLAY = 0x4,};


enum class OobDataFlag : uint8_t {NOT_PRESENT = 0x0,PRESENT = 0x1,};


enum class BondingFlags : uint8_t {NO_BONDING = 0x0,BONDING = 0x1,};


enum class PairingFailedReason : uint8_t {PASSKEY_ENTRY_FAILED = 0x1,OOB_NOT_AVAILABLE = 0x2,AUTHENTICATION_REQUIREMENTS = 0x3,CONFIRM_VALUE_FAILED = 0x4,PAIRING_NOT_SUPPORTED = 0x5,ENCRYPTION_KEY_SIZE = 0x6,COMMAND_NOT_SUPPORTED = 0x7,UNSPECIFIED_REASON = 0x8,REPEATED_ATTEMPTS = 0x9,INVALID_PARAMETERS = 0xa,DHKEY_CHECK_FAILED = 0xb,NUMERIC_COMPARISON_FAILED = 0xc,BR_EDR_PAIRING_IN_PROGRESS = 0xd,CROSS_TRANSPORT_KEY_DERIVATION_NOT_ALLOWED = 0xe,};


enum class AddrType : uint8_t {PUBLIC = 0x0,STATIC_RANDOM = 0x1,};


enum class KeypressNotificationType : uint8_t {ENTRY_STARTED = 0x0,DIGIT_ENTERED = 0x1,DIGIT_ERASED = 0x2,CLEARED = 0x3,ENTRY_COMPLETED = 0x4,};


inline std::string CodeText(const Code& param) {switch (param) {case Code::PAIRING_REQUEST:  return "PAIRING_REQUEST";case Code::PAIRING_RESPONSE:  return "PAIRING_RESPONSE";case Code::PAIRING_CONFIRM:  return "PAIRING_CONFIRM";case Code::PAIRING_RANDOM:  return "PAIRING_RANDOM";case Code::PAIRING_FAILED:  return "PAIRING_FAILED";case Code::ENCRYPTION_INFORMATION:  return "ENCRYPTION_INFORMATION";case Code::CENTRAL_IDENTIFICATION:  return "CENTRAL_IDENTIFICATION";case Code::IDENTITY_INFORMATION:  return "IDENTITY_INFORMATION";case Code::IDENTITY_ADDRESS_INFORMATION:  return "IDENTITY_ADDRESS_INFORMATION";case Code::SIGNING_INFORMATION:  return "SIGNING_INFORMATION";case Code::SECURITY_REQUEST:  return "SECURITY_REQUEST";case Code::PAIRING_PUBLIC_KEY:  return "PAIRING_PUBLIC_KEY";case Code::PAIRING_DH_KEY_CHECK:  return "PAIRING_DH_KEY_CHECK";case Code::PAIRING_KEYPRESS_NOTIFICATION:  return "PAIRING_KEYPRESS_NOTIFICATION";default:  return std::string("Unknown Code: ") + std::to_string(static_cast<int>(param));}}

inline std::ostream& operator<<(std::ostream& os, const Code& param) {  return os << CodeText(param);}


inline std::string IoCapabilityText(const IoCapability& param) {switch (param) {case IoCapability::DISPLAY_ONLY:  return "DISPLAY_ONLY";case IoCapability::DISPLAY_YES_NO:  return "DISPLAY_YES_NO";case IoCapability::KEYBOARD_ONLY:  return "KEYBOARD_ONLY";case IoCapability::NO_INPUT_NO_OUTPUT:  return "NO_INPUT_NO_OUTPUT";case IoCapability::KEYBOARD_DISPLAY:  return "KEYBOARD_DISPLAY";default:  return std::string("Unknown IoCapability: ") + std::to_string(static_cast<int>(param));}}

inline std::ostream& operator<<(std::ostream& os, const IoCapability& param) {  return os << IoCapabilityText(param);}


inline std::string OobDataFlagText(const OobDataFlag& param) {switch (param) {case OobDataFlag::NOT_PRESENT:  return "NOT_PRESENT";case OobDataFlag::PRESENT:  return "PRESENT";default:  return std::string("Unknown OobDataFlag: ") + std::to_string(static_cast<int>(param));}}

inline std::ostream& operator<<(std::ostream& os, const OobDataFlag& param) {  return os << OobDataFlagText(param);}


inline std::string BondingFlagsText(const BondingFlags& param) {switch (param) {case BondingFlags::NO_BONDING:  return "NO_BONDING";case BondingFlags::BONDING:  return "BONDING";default:  return std::string("Unknown BondingFlags: ") + std::to_string(static_cast<int>(param));}}

inline std::ostream& operator<<(std::ostream& os, const BondingFlags& param) {  return os << BondingFlagsText(param);}


inline std::string PairingFailedReasonText(const PairingFailedReason& param) {switch (param) {case PairingFailedReason::PASSKEY_ENTRY_FAILED:  return "PASSKEY_ENTRY_FAILED";case PairingFailedReason::OOB_NOT_AVAILABLE:  return "OOB_NOT_AVAILABLE";case PairingFailedReason::AUTHENTICATION_REQUIREMENTS:  return "AUTHENTICATION_REQUIREMENTS";case PairingFailedReason::CONFIRM_VALUE_FAILED:  return "CONFIRM_VALUE_FAILED";case PairingFailedReason::PAIRING_NOT_SUPPORTED:  return "PAIRING_NOT_SUPPORTED";case PairingFailedReason::ENCRYPTION_KEY_SIZE:  return "ENCRYPTION_KEY_SIZE";case PairingFailedReason::COMMAND_NOT_SUPPORTED:  return "COMMAND_NOT_SUPPORTED";case PairingFailedReason::UNSPECIFIED_REASON:  return "UNSPECIFIED_REASON";case PairingFailedReason::REPEATED_ATTEMPTS:  return "REPEATED_ATTEMPTS";case PairingFailedReason::INVALID_PARAMETERS:  return "INVALID_PARAMETERS";case PairingFailedReason::DHKEY_CHECK_FAILED:  return "DHKEY_CHECK_FAILED";case PairingFailedReason::NUMERIC_COMPARISON_FAILED:  return "NUMERIC_COMPARISON_FAILED";case PairingFailedReason::BR_EDR_PAIRING_IN_PROGRESS:  return "BR_EDR_PAIRING_IN_PROGRESS";case PairingFailedReason::CROSS_TRANSPORT_KEY_DERIVATION_NOT_ALLOWED:  return "CROSS_TRANSPORT_KEY_DERIVATION_NOT_ALLOWED";default:  return std::string("Unknown PairingFailedReason: ") + std::to_string(static_cast<int>(param));}}

inline std::ostream& operator<<(std::ostream& os, const PairingFailedReason& param) {  return os << PairingFailedReasonText(param);}


inline std::string AddrTypeText(const AddrType& param) {switch (param) {case AddrType::PUBLIC:  return "PUBLIC";case AddrType::STATIC_RANDOM:  return "STATIC_RANDOM";default:  return std::string("Unknown AddrType: ") + std::to_string(static_cast<int>(param));}}

inline std::ostream& operator<<(std::ostream& os, const AddrType& param) {  return os << AddrTypeText(param);}


inline std::string KeypressNotificationTypeText(const KeypressNotificationType& param) {switch (param) {case KeypressNotificationType::ENTRY_STARTED:  return "ENTRY_STARTED";case KeypressNotificationType::DIGIT_ENTERED:  return "DIGIT_ENTERED";case KeypressNotificationType::DIGIT_ERASED:  return "DIGIT_ERASED";case KeypressNotificationType::CLEARED:  return "CLEARED";case KeypressNotificationType::ENTRY_COMPLETED:  return "ENTRY_COMPLETED";default:  return std::string("Unknown KeypressNotificationType: ") + std::to_string(static_cast<int>(param));}}

inline std::ostream& operator<<(std::ostream& os, const KeypressNotificationType& param) {  return os << KeypressNotificationTypeText(param);}



/* Done ChecksumChecks */
static_assert(std::is_base_of_v<CustomFieldFixedSizeInterface<Address>, Address>, "Address is not a valid fixed size custom field type. Please see README for more details.");static_assert(CustomFieldFixedSizeInterface<Address>::length() * 8 == 48, "CustomFieldFixedSizeInterface<Address>::length * 8 should match PDL defined size (in bits) 48");


class CommandView : public PacketView<kLittleEndian> { public:static CommandView Create(PacketView<kLittleEndian> packet) { return CommandView(std::move(packet)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static CommandView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return CommandView::Create(PacketView<kLittleEndian>(vec));}
#endif
Code GetCode() const {ASSERT(was_validated_);auto to_bound = begin();auto code_it = to_bound + (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;Code code_value{};Code* code_ptr = &code_value;auto extracted_value = code_it.extract<uint8_t>();*code_ptr = static_cast<Code>(extracted_value);return code_value;}
PacketView<kLittleEndian> GetPayload() const {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;auto payload_it = to_bound.Subrange(field_begin, field_end - field_begin); return GetLittleEndianSubview(field_begin, field_end);}

PacketView<!kLittleEndian> GetPayloadBigEndian() const {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;auto payload_it = to_bound.Subrange(field_begin, field_end - field_begin); return GetBigEndianSubview(field_begin, field_end);}

virtual bool IsValid()  {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {auto it = begin() + (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;it += 1 /* Total size of the fixed fields */;if (it > end()) return false;

return true;}
bool was_validated_{false};

 public:virtual std::string ToString()  {std::stringstream ss;ss << std::showbase << std::hex << "Command { ";ss << ""  << "code = " << CodeText(GetCode()) << ", payload = " << "PAYLOAD[]";ss << " }";return ss.str();}

 protected:
explicit CommandView(PacketView<kLittleEndian> packet)  : PacketView<kLittleEndian>(packet) { was_validated_ = false;}};


class PairingRequestView : public CommandView { public:static PairingRequestView Create(CommandView parent){ return PairingRequestView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static PairingRequestView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return PairingRequestView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
IoCapability GetIoCapability() const {ASSERT(was_validated_);auto to_bound = begin();auto io_capability_it = to_bound + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;IoCapability io_capability_value{};IoCapability* io_capability_ptr = &io_capability_value;auto extracted_value = io_capability_it.extract<uint8_t>();*io_capability_ptr = static_cast<IoCapability>(extracted_value);return io_capability_value;}
OobDataFlag GetOobDataFlag() const {ASSERT(was_validated_);auto to_bound = begin();auto oob_data_flag_it = to_bound + (/* Bits: */ 16 + /* Dynamic: */ 0) / 8;OobDataFlag oob_data_flag_value{};OobDataFlag* oob_data_flag_ptr = &oob_data_flag_value;auto extracted_value = oob_data_flag_it.extract<uint8_t>();*oob_data_flag_ptr = static_cast<OobDataFlag>(extracted_value);return oob_data_flag_value;}
uint8_t GetAuthReq() const {ASSERT(was_validated_);auto to_bound = begin();auto auth_req_it = to_bound + (/* Bits: */ 24 + /* Dynamic: */ 0) / 8;uint8_t auth_req_value{};uint8_t* auth_req_ptr = &auth_req_value;auto extracted_value = auth_req_it.extract<uint8_t>();*auth_req_ptr = static_cast<uint8_t>(extracted_value);return auth_req_value;}
uint8_t GetMaximumEncryptionKeySize() const {ASSERT(was_validated_);auto to_bound = begin();auto maximum_encryption_key_size_it = to_bound + (/* Bits: */ 32 + /* Dynamic: */ 0) / 8;uint8_t maximum_encryption_key_size_value{};uint8_t* maximum_encryption_key_size_ptr = &maximum_encryption_key_size_value;auto extracted_value = maximum_encryption_key_size_it.extract<uint8_t>();extracted_value &= 0x1f;*maximum_encryption_key_size_ptr = static_cast<uint8_t>(extracted_value);return maximum_encryption_key_size_value;}

uint8_t GetInitiatorKeyDistribution() const {ASSERT(was_validated_);auto to_bound = begin();auto initiator_key_distribution_it = to_bound + (/* Bits: */ 40 + /* Dynamic: */ 0) / 8;uint8_t initiator_key_distribution_value{};uint8_t* initiator_key_distribution_ptr = &initiator_key_distribution_value;auto extracted_value = initiator_key_distribution_it.extract<uint8_t>();*initiator_key_distribution_ptr = static_cast<uint8_t>(extracted_value);return initiator_key_distribution_value;}
uint8_t GetResponderKeyDistribution() const {ASSERT(was_validated_);auto to_bound = begin();auto responder_key_distribution_it = to_bound + (/* Bits: */ 48 + /* Dynamic: */ 0) / 8;uint8_t responder_key_distribution_value{};uint8_t* responder_key_distribution_ptr = &responder_key_distribution_value;auto extracted_value = responder_key_distribution_it.extract<uint8_t>();*responder_key_distribution_ptr = static_cast<uint8_t>(extracted_value);return responder_key_distribution_value;}
virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 6 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::PAIRING_REQUEST) return false;






return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "PairingRequest { ";ss << ""  << "io_capability = " << IoCapabilityText(GetIoCapability()) << ", oob_data_flag = " << OobDataFlagText(GetOobDataFlag()) << ", auth_req = " << +GetAuthReq() << ", maximum_encryption_key_size = " << +GetMaximumEncryptionKeySize() << ", initiator_key_distribution = " << +GetInitiatorKeyDistribution() << ", responder_key_distribution = " << +GetResponderKeyDistribution();ss << " }";return ss.str();}

 protected:
explicit PairingRequestView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class PairingResponseView : public CommandView { public:static PairingResponseView Create(CommandView parent){ return PairingResponseView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static PairingResponseView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return PairingResponseView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
IoCapability GetIoCapability() const {ASSERT(was_validated_);auto to_bound = begin();auto io_capability_it = to_bound + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;IoCapability io_capability_value{};IoCapability* io_capability_ptr = &io_capability_value;auto extracted_value = io_capability_it.extract<uint8_t>();*io_capability_ptr = static_cast<IoCapability>(extracted_value);return io_capability_value;}
OobDataFlag GetOobDataFlag() const {ASSERT(was_validated_);auto to_bound = begin();auto oob_data_flag_it = to_bound + (/* Bits: */ 16 + /* Dynamic: */ 0) / 8;OobDataFlag oob_data_flag_value{};OobDataFlag* oob_data_flag_ptr = &oob_data_flag_value;auto extracted_value = oob_data_flag_it.extract<uint8_t>();*oob_data_flag_ptr = static_cast<OobDataFlag>(extracted_value);return oob_data_flag_value;}
uint8_t GetAuthReq() const {ASSERT(was_validated_);auto to_bound = begin();auto auth_req_it = to_bound + (/* Bits: */ 24 + /* Dynamic: */ 0) / 8;uint8_t auth_req_value{};uint8_t* auth_req_ptr = &auth_req_value;auto extracted_value = auth_req_it.extract<uint8_t>();*auth_req_ptr = static_cast<uint8_t>(extracted_value);return auth_req_value;}
uint8_t GetMaximumEncryptionKeySize() const {ASSERT(was_validated_);auto to_bound = begin();auto maximum_encryption_key_size_it = to_bound + (/* Bits: */ 32 + /* Dynamic: */ 0) / 8;uint8_t maximum_encryption_key_size_value{};uint8_t* maximum_encryption_key_size_ptr = &maximum_encryption_key_size_value;auto extracted_value = maximum_encryption_key_size_it.extract<uint8_t>();extracted_value &= 0x1f;*maximum_encryption_key_size_ptr = static_cast<uint8_t>(extracted_value);return maximum_encryption_key_size_value;}

uint8_t GetInitiatorKeyDistribution() const {ASSERT(was_validated_);auto to_bound = begin();auto initiator_key_distribution_it = to_bound + (/* Bits: */ 40 + /* Dynamic: */ 0) / 8;uint8_t initiator_key_distribution_value{};uint8_t* initiator_key_distribution_ptr = &initiator_key_distribution_value;auto extracted_value = initiator_key_distribution_it.extract<uint8_t>();*initiator_key_distribution_ptr = static_cast<uint8_t>(extracted_value);return initiator_key_distribution_value;}
uint8_t GetResponderKeyDistribution() const {ASSERT(was_validated_);auto to_bound = begin();auto responder_key_distribution_it = to_bound + (/* Bits: */ 48 + /* Dynamic: */ 0) / 8;uint8_t responder_key_distribution_value{};uint8_t* responder_key_distribution_ptr = &responder_key_distribution_value;auto extracted_value = responder_key_distribution_it.extract<uint8_t>();*responder_key_distribution_ptr = static_cast<uint8_t>(extracted_value);return responder_key_distribution_value;}
virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 6 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::PAIRING_RESPONSE) return false;






return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "PairingResponse { ";ss << ""  << "io_capability = " << IoCapabilityText(GetIoCapability()) << ", oob_data_flag = " << OobDataFlagText(GetOobDataFlag()) << ", auth_req = " << +GetAuthReq() << ", maximum_encryption_key_size = " << +GetMaximumEncryptionKeySize() << ", initiator_key_distribution = " << +GetInitiatorKeyDistribution() << ", responder_key_distribution = " << +GetResponderKeyDistribution();ss << " }";return ss.str();}

 protected:
explicit PairingResponseView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class PairingConfirmView : public CommandView { public:static PairingConfirmView Create(CommandView parent){ return PairingConfirmView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static PairingConfirmView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return PairingConfirmView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
std::array<uint8_t,16> GetConfirmValue() {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_sized_end = field_begin + (/* Bits: */ 128 + /* Dynamic: */ 0) / 8;if (field_sized_end < field_end) { field_end = field_sized_end; }auto confirm_value_it = to_bound.Subrange(field_begin, field_end - field_begin); std::array<uint8_t,16> confirm_value_value{};std::array<uint8_t,16>* confirm_value_ptr = &confirm_value_value;std::array<uint8_t,16>::iterator ret_it = confirm_value_ptr->begin();auto val_it = confirm_value_it;while (val_it.NumBytesRemaining() >= 1 && ret_it < confirm_value_ptr->end()) {auto val_ptr = ret_it;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);ret_it++;}return confirm_value_value;}

virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 16 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::PAIRING_CONFIRM) return false;
return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "PairingConfirm { ";ss << ""  << "confirm_value = " << "ARRAY[";/* uint8_t   ScalarField */for (size_t index = 0; index < 16; index++) {ss << ((index == 0) ? "" : ", ") << +(GetConfirmValue()[index]);}ss << "]";ss << " }";return ss.str();}

 protected:
explicit PairingConfirmView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class PairingRandomView : public CommandView { public:static PairingRandomView Create(CommandView parent){ return PairingRandomView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static PairingRandomView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return PairingRandomView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
std::array<uint8_t,16> GetRandomValue() {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_sized_end = field_begin + (/* Bits: */ 128 + /* Dynamic: */ 0) / 8;if (field_sized_end < field_end) { field_end = field_sized_end; }auto random_value_it = to_bound.Subrange(field_begin, field_end - field_begin); std::array<uint8_t,16> random_value_value{};std::array<uint8_t,16>* random_value_ptr = &random_value_value;std::array<uint8_t,16>::iterator ret_it = random_value_ptr->begin();auto val_it = random_value_it;while (val_it.NumBytesRemaining() >= 1 && ret_it < random_value_ptr->end()) {auto val_ptr = ret_it;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);ret_it++;}return random_value_value;}

virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 16 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::PAIRING_RANDOM) return false;
return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "PairingRandom { ";ss << ""  << "random_value = " << "ARRAY[";/* uint8_t   ScalarField */for (size_t index = 0; index < 16; index++) {ss << ((index == 0) ? "" : ", ") << +(GetRandomValue()[index]);}ss << "]";ss << " }";return ss.str();}

 protected:
explicit PairingRandomView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class PairingFailedView : public CommandView { public:static PairingFailedView Create(CommandView parent){ return PairingFailedView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static PairingFailedView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return PairingFailedView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
PairingFailedReason GetReason() const {ASSERT(was_validated_);auto to_bound = begin();auto reason_it = to_bound + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;PairingFailedReason reason_value{};PairingFailedReason* reason_ptr = &reason_value;auto extracted_value = reason_it.extract<uint8_t>();*reason_ptr = static_cast<PairingFailedReason>(extracted_value);return reason_value;}
virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 1 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::PAIRING_FAILED) return false;
return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "PairingFailed { ";ss << ""  << "reason = " << PairingFailedReasonText(GetReason());ss << " }";return ss.str();}

 protected:
explicit PairingFailedView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class EncryptionInformationView : public CommandView { public:static EncryptionInformationView Create(CommandView parent){ return EncryptionInformationView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static EncryptionInformationView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return EncryptionInformationView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
std::array<uint8_t,16> GetLongTermKey() {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_sized_end = field_begin + (/* Bits: */ 128 + /* Dynamic: */ 0) / 8;if (field_sized_end < field_end) { field_end = field_sized_end; }auto long_term_key_it = to_bound.Subrange(field_begin, field_end - field_begin); std::array<uint8_t,16> long_term_key_value{};std::array<uint8_t,16>* long_term_key_ptr = &long_term_key_value;std::array<uint8_t,16>::iterator ret_it = long_term_key_ptr->begin();auto val_it = long_term_key_it;while (val_it.NumBytesRemaining() >= 1 && ret_it < long_term_key_ptr->end()) {auto val_ptr = ret_it;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);ret_it++;}return long_term_key_value;}

virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 16 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::ENCRYPTION_INFORMATION) return false;
return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "EncryptionInformation { ";ss << ""  << "long_term_key = " << "ARRAY[";/* uint8_t   ScalarField */for (size_t index = 0; index < 16; index++) {ss << ((index == 0) ? "" : ", ") << +(GetLongTermKey()[index]);}ss << "]";ss << " }";return ss.str();}

 protected:
explicit EncryptionInformationView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class CentralIdentificationView : public CommandView { public:static CentralIdentificationView Create(CommandView parent){ return CentralIdentificationView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static CentralIdentificationView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return CentralIdentificationView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
uint16_t GetEdiv() const {ASSERT(was_validated_);auto to_bound = begin();auto ediv_it = to_bound + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;uint16_t ediv_value{};uint16_t* ediv_ptr = &ediv_value;auto extracted_value = ediv_it.extract<uint16_t>();*ediv_ptr = static_cast<uint16_t>(extracted_value);return ediv_value;}
std::array<uint8_t,8> GetRand() {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 24 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_sized_end = field_begin + (/* Bits: */ 64 + /* Dynamic: */ 0) / 8;if (field_sized_end < field_end) { field_end = field_sized_end; }auto rand_it = to_bound.Subrange(field_begin, field_end - field_begin); std::array<uint8_t,8> rand_value{};std::array<uint8_t,8>* rand_ptr = &rand_value;std::array<uint8_t,8>::iterator ret_it = rand_ptr->begin();auto val_it = rand_it;while (val_it.NumBytesRemaining() >= 1 && ret_it < rand_ptr->end()) {auto val_ptr = ret_it;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);ret_it++;}return rand_value;}

virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 10 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::CENTRAL_IDENTIFICATION) return false;

return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "CentralIdentification { ";ss << ""  << "ediv = " << +GetEdiv() << ", rand = " << "ARRAY[";/* uint8_t   ScalarField */for (size_t index = 0; index < 8; index++) {ss << ((index == 0) ? "" : ", ") << +(GetRand()[index]);}ss << "]";ss << " }";return ss.str();}

 protected:
explicit CentralIdentificationView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class IdentityInformationView : public CommandView { public:static IdentityInformationView Create(CommandView parent){ return IdentityInformationView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static IdentityInformationView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return IdentityInformationView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
std::array<uint8_t,16> GetIdentityResolvingKey() {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_sized_end = field_begin + (/* Bits: */ 128 + /* Dynamic: */ 0) / 8;if (field_sized_end < field_end) { field_end = field_sized_end; }auto identity_resolving_key_it = to_bound.Subrange(field_begin, field_end - field_begin); std::array<uint8_t,16> identity_resolving_key_value{};std::array<uint8_t,16>* identity_resolving_key_ptr = &identity_resolving_key_value;std::array<uint8_t,16>::iterator ret_it = identity_resolving_key_ptr->begin();auto val_it = identity_resolving_key_it;while (val_it.NumBytesRemaining() >= 1 && ret_it < identity_resolving_key_ptr->end()) {auto val_ptr = ret_it;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);ret_it++;}return identity_resolving_key_value;}

virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 16 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::IDENTITY_INFORMATION) return false;
return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "IdentityInformation { ";ss << ""  << "identity_resolving_key = " << "ARRAY[";/* uint8_t   ScalarField */for (size_t index = 0; index < 16; index++) {ss << ((index == 0) ? "" : ", ") << +(GetIdentityResolvingKey()[index]);}ss << "]";ss << " }";return ss.str();}

 protected:
explicit IdentityInformationView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class IdentityAddressInformationView : public CommandView { public:static IdentityAddressInformationView Create(CommandView parent){ return IdentityAddressInformationView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static IdentityAddressInformationView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return IdentityAddressInformationView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
AddrType GetAddrType() const {ASSERT(was_validated_);auto to_bound = begin();auto addr_type_it = to_bound + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;AddrType addr_type_value{};AddrType* addr_type_ptr = &addr_type_value;auto extracted_value = addr_type_it.extract<uint8_t>();*addr_type_ptr = static_cast<AddrType>(extracted_value);return addr_type_value;}
Address GetBdAddr() const {ASSERT(was_validated_);auto to_bound = begin();auto bd_addr_it = to_bound + (/* Bits: */ 16 + /* Dynamic: */ 0) / 8;Address bd_addr_value{};Address* bd_addr_ptr = &bd_addr_value;*bd_addr_ptr = bd_addr_it.extract<Address>();return bd_addr_value;}
virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 7 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::IDENTITY_ADDRESS_INFORMATION) return false;

return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "IdentityAddressInformation { ";ss << ""  << "addr_type = " << AddrTypeText(GetAddrType()) << ", bd_addr = " << GetBdAddr().ToString();ss << " }";return ss.str();}

 protected:
explicit IdentityAddressInformationView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class SigningInformationView : public CommandView { public:static SigningInformationView Create(CommandView parent){ return SigningInformationView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static SigningInformationView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return SigningInformationView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
std::array<uint8_t,16> GetSignatureKey() {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_sized_end = field_begin + (/* Bits: */ 128 + /* Dynamic: */ 0) / 8;if (field_sized_end < field_end) { field_end = field_sized_end; }auto signature_key_it = to_bound.Subrange(field_begin, field_end - field_begin); std::array<uint8_t,16> signature_key_value{};std::array<uint8_t,16>* signature_key_ptr = &signature_key_value;std::array<uint8_t,16>::iterator ret_it = signature_key_ptr->begin();auto val_it = signature_key_it;while (val_it.NumBytesRemaining() >= 1 && ret_it < signature_key_ptr->end()) {auto val_ptr = ret_it;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);ret_it++;}return signature_key_value;}

virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 16 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::SIGNING_INFORMATION) return false;
return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "SigningInformation { ";ss << ""  << "signature_key = " << "ARRAY[";/* uint8_t   ScalarField */for (size_t index = 0; index < 16; index++) {ss << ((index == 0) ? "" : ", ") << +(GetSignatureKey()[index]);}ss << "]";ss << " }";return ss.str();}

 protected:
explicit SigningInformationView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class SecurityRequestView : public CommandView { public:static SecurityRequestView Create(CommandView parent){ return SecurityRequestView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static SecurityRequestView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return SecurityRequestView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
uint8_t GetAuthReq() const {ASSERT(was_validated_);auto to_bound = begin();auto auth_req_it = to_bound + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;uint8_t auth_req_value{};uint8_t* auth_req_ptr = &auth_req_value;auto extracted_value = auth_req_it.extract<uint8_t>();*auth_req_ptr = static_cast<uint8_t>(extracted_value);return auth_req_value;}
virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 1 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::SECURITY_REQUEST) return false;
return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "SecurityRequest { ";ss << ""  << "auth_req = " << +GetAuthReq();ss << " }";return ss.str();}

 protected:
explicit SecurityRequestView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class PairingPublicKeyView : public CommandView { public:static PairingPublicKeyView Create(CommandView parent){ return PairingPublicKeyView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static PairingPublicKeyView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return PairingPublicKeyView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
std::array<uint8_t,32> GetPublicKeyX() {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 256 + /* Dynamic: */ 0) / 8;size_t field_sized_end = field_begin + (/* Bits: */ 256 + /* Dynamic: */ 0) / 8;if (field_sized_end < field_end) { field_end = field_sized_end; }auto public_key_x_it = to_bound.Subrange(field_begin, field_end - field_begin); std::array<uint8_t,32> public_key_x_value{};std::array<uint8_t,32>* public_key_x_ptr = &public_key_x_value;std::array<uint8_t,32>::iterator ret_it = public_key_x_ptr->begin();auto val_it = public_key_x_it;while (val_it.NumBytesRemaining() >= 1 && ret_it < public_key_x_ptr->end()) {auto val_ptr = ret_it;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);ret_it++;}return public_key_x_value;}

std::array<uint8_t,32> GetPublicKeyY() {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 264 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_sized_end = field_begin + (/* Bits: */ 256 + /* Dynamic: */ 0) / 8;if (field_sized_end < field_end) { field_end = field_sized_end; }auto public_key_y_it = to_bound.Subrange(field_begin, field_end - field_begin); std::array<uint8_t,32> public_key_y_value{};std::array<uint8_t,32>* public_key_y_ptr = &public_key_y_value;std::array<uint8_t,32>::iterator ret_it = public_key_y_ptr->begin();auto val_it = public_key_y_it;while (val_it.NumBytesRemaining() >= 1 && ret_it < public_key_y_ptr->end()) {auto val_ptr = ret_it;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);ret_it++;}return public_key_y_value;}

virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 64 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::PAIRING_PUBLIC_KEY) return false;

return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "PairingPublicKey { ";ss << ""  << "public_key_x = " << "ARRAY[";/* uint8_t   ScalarField */for (size_t index = 0; index < 32; index++) {ss << ((index == 0) ? "" : ", ") << +(GetPublicKeyX()[index]);}ss << "]" << ", public_key_y = " << "ARRAY[";/* uint8_t   ScalarField */for (size_t index = 0; index < 32; index++) {ss << ((index == 0) ? "" : ", ") << +(GetPublicKeyY()[index]);}ss << "]";ss << " }";return ss.str();}

 protected:
explicit PairingPublicKeyView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class PairingDhKeyCheckView : public CommandView { public:static PairingDhKeyCheckView Create(CommandView parent){ return PairingDhKeyCheckView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static PairingDhKeyCheckView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return PairingDhKeyCheckView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
std::array<uint8_t,16> GetDhKeyCheck() {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_sized_end = field_begin + (/* Bits: */ 128 + /* Dynamic: */ 0) / 8;if (field_sized_end < field_end) { field_end = field_sized_end; }auto dh_key_check_it = to_bound.Subrange(field_begin, field_end - field_begin); std::array<uint8_t,16> dh_key_check_value{};std::array<uint8_t,16>* dh_key_check_ptr = &dh_key_check_value;std::array<uint8_t,16>::iterator ret_it = dh_key_check_ptr->begin();auto val_it = dh_key_check_it;while (val_it.NumBytesRemaining() >= 1 && ret_it < dh_key_check_ptr->end()) {auto val_ptr = ret_it;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);ret_it++;}return dh_key_check_value;}

virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 16 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::PAIRING_DH_KEY_CHECK) return false;
return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "PairingDhKeyCheck { ";ss << ""  << "dh_key_check = " << "ARRAY[";/* uint8_t   ScalarField */for (size_t index = 0; index < 16; index++) {ss << ((index == 0) ? "" : ", ") << +(GetDhKeyCheck()[index]);}ss << "]";ss << " }";return ss.str();}

 protected:
explicit PairingDhKeyCheckView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class PairingKeypressNotificationView : public CommandView { public:static PairingKeypressNotificationView Create(CommandView parent){ return PairingKeypressNotificationView(std::move(parent)); }
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static PairingKeypressNotificationView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return PairingKeypressNotificationView::Create(CommandView::Create(PacketView<kLittleEndian>(vec)));}
#endif
KeypressNotificationType GetNotificationType() const {ASSERT(was_validated_);auto to_bound = begin();auto notification_type_it = to_bound + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;KeypressNotificationType notification_type_value{};KeypressNotificationType* notification_type_ptr = &notification_type_value;auto extracted_value = notification_type_it.extract<uint8_t>();*notification_type_ptr = static_cast<KeypressNotificationType>(extracted_value);return notification_type_value;}
virtual bool IsValid()  override {if (was_validated_) { return true; } else { was_validated_ = true; was_validated_ = IsValid_(); return was_validated_; }}protected:virtual bool IsValid_() const {if (!CommandView::IsValid_()) { return false; } auto it = begin() + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;it += 1 /* Total size of the fixed fields */;if (it > end()) return false;if (GetCode() != Code::PAIRING_KEYPRESS_NOTIFICATION) return false;
return true;}

 public:virtual std::string ToString()  override {std::stringstream ss;ss << std::showbase << std::hex << "PairingKeypressNotification { ";ss << ""  << "notification_type = " << KeypressNotificationTypeText(GetNotificationType());ss << " }";return ss.str();}

 protected:
explicit PairingKeypressNotificationView(CommandView parent) : CommandView(std::move(parent)) { was_validated_ = false; }};


class CommandBuilder : public PacketBuilder<kLittleEndian> { public:  virtual ~CommandBuilder() = default;static std::unique_ptr<CommandBuilder> Create(Code code, std::unique_ptr<BasePacketBuilder> payload) {auto builder = std::unique_ptr<CommandBuilder>(new CommandBuilder(code));builder->payload_ = std::move(payload);return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<CommandBuilder> FromView(CommandView view) {return CommandBuilder::Create(view.GetCode(), std::make_unique<RawBuilder>(std::vector<uint8_t>(view.GetPayload().begin(), view.GetPayload().end())));}
#endif

protected:void SerializeHeader(BitInserter& i ) const {insert(static_cast<uint8_t>(code_), i, 8);}

void SerializeFooter(BitInserter&) const {}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);payload_->Serialize(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + /* Bits: */ 8 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0;}

size_t GetPayloadSize() const {if (payload_ != nullptr) {return payload_->size();}else { return size() - (BitsOfHeader() + BitsOfFooter()) / 8;};}

public:virtual size_t size() const override {return (BitsOfHeader() / 8)+ payload_->size() + (BitsOfFooter() / 8);}

 protected:
explicit CommandBuilder(Code code) :code_(code) {}


Code code_{};std::unique_ptr<BasePacketBuilder> payload_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_CommandReflectionTest(...)class CommandReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {CommandView view = CommandView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = CommandBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(CommandReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(Command_reflection, CommandReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_CommandReflectionFuzzTest() void RunCommandReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);CommandView view = CommandView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = CommandBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_CommandReflectionFuzzTest(REGISTRY) DEFINE_CommandReflectionFuzzTest(); class CommandReflectionFuzzTestRegistrant {public: explicit CommandReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunCommandReflectionFuzzTest);}}; CommandReflectionFuzzTestRegistrant Command_reflection_fuzz_test_registrant(REGISTRY);
#endif


class PairingRequestBuilder : public CommandBuilder { public:  virtual ~PairingRequestBuilder() = default;static std::unique_ptr<PairingRequestBuilder> Create(IoCapability io_capability, OobDataFlag oob_data_flag, uint8_t auth_req, uint8_t maximum_encryption_key_size, uint8_t initiator_key_distribution, uint8_t responder_key_distribution) {auto builder = std::unique_ptr<PairingRequestBuilder>(new PairingRequestBuilder(io_capability, oob_data_flag, auth_req, maximum_encryption_key_size, initiator_key_distribution, responder_key_distribution));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<PairingRequestBuilder> FromView(PairingRequestView view) {return PairingRequestBuilder::Create(view.GetIoCapability(), view.GetOobDataFlag(), view.GetAuthReq(), view.GetMaximumEncryptionKeySize(), view.GetInitiatorKeyDistribution(), view.GetResponderKeyDistribution());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);insert(static_cast<uint8_t>(io_capability_), i, 8);insert(static_cast<uint8_t>(oob_data_flag_), i, 8);i.insert_byte(auth_req_);insert(maximum_encryption_key_size_, i,5);insert(static_cast<uint8_t>(0) /* Reserved */, i, 3 );
i.insert_byte(initiator_key_distribution_);i.insert_byte(responder_key_distribution_);}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 5 + /* Dynamic: */ 0 + /* Bits: */ 3 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit PairingRequestBuilder(IoCapability io_capability, OobDataFlag oob_data_flag, uint8_t auth_req, uint8_t maximum_encryption_key_size, uint8_t initiator_key_distribution, uint8_t responder_key_distribution) :CommandBuilder(Code::PAIRING_REQUEST/* code_ */) ,io_capability_(io_capability),oob_data_flag_(oob_data_flag),auth_req_(auth_req),maximum_encryption_key_size_(maximum_encryption_key_size),initiator_key_distribution_(initiator_key_distribution),responder_key_distribution_(responder_key_distribution) {CheckParameterValues(maximum_encryption_key_size_);}

void CheckParameterValues(uint8_t maximum_encryption_key_size) {ASSERT(maximum_encryption_key_size < (static_cast<uint64_t>(1) << 5));}

IoCapability io_capability_{};OobDataFlag oob_data_flag_{};uint8_t auth_req_{};uint8_t maximum_encryption_key_size_{};uint8_t initiator_key_distribution_{};uint8_t responder_key_distribution_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_PairingRequestReflectionTest(...)class PairingRequestReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {PairingRequestView view = PairingRequestView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = PairingRequestBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(PairingRequestReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(PairingRequest_reflection, PairingRequestReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_PairingRequestReflectionFuzzTest() void RunPairingRequestReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);PairingRequestView view = PairingRequestView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = PairingRequestBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_PairingRequestReflectionFuzzTest(REGISTRY) DEFINE_PairingRequestReflectionFuzzTest(); class PairingRequestReflectionFuzzTestRegistrant {public: explicit PairingRequestReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunPairingRequestReflectionFuzzTest);}}; PairingRequestReflectionFuzzTestRegistrant PairingRequest_reflection_fuzz_test_registrant(REGISTRY);
#endif


class PairingResponseBuilder : public CommandBuilder { public:  virtual ~PairingResponseBuilder() = default;static std::unique_ptr<PairingResponseBuilder> Create(IoCapability io_capability, OobDataFlag oob_data_flag, uint8_t auth_req, uint8_t maximum_encryption_key_size, uint8_t initiator_key_distribution, uint8_t responder_key_distribution) {auto builder = std::unique_ptr<PairingResponseBuilder>(new PairingResponseBuilder(io_capability, oob_data_flag, auth_req, maximum_encryption_key_size, initiator_key_distribution, responder_key_distribution));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<PairingResponseBuilder> FromView(PairingResponseView view) {return PairingResponseBuilder::Create(view.GetIoCapability(), view.GetOobDataFlag(), view.GetAuthReq(), view.GetMaximumEncryptionKeySize(), view.GetInitiatorKeyDistribution(), view.GetResponderKeyDistribution());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);insert(static_cast<uint8_t>(io_capability_), i, 8);insert(static_cast<uint8_t>(oob_data_flag_), i, 8);i.insert_byte(auth_req_);insert(maximum_encryption_key_size_, i,5);insert(static_cast<uint8_t>(0) /* Reserved */, i, 3 );
i.insert_byte(initiator_key_distribution_);i.insert_byte(responder_key_distribution_);}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 5 + /* Dynamic: */ 0 + /* Bits: */ 3 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit PairingResponseBuilder(IoCapability io_capability, OobDataFlag oob_data_flag, uint8_t auth_req, uint8_t maximum_encryption_key_size, uint8_t initiator_key_distribution, uint8_t responder_key_distribution) :CommandBuilder(Code::PAIRING_RESPONSE/* code_ */) ,io_capability_(io_capability),oob_data_flag_(oob_data_flag),auth_req_(auth_req),maximum_encryption_key_size_(maximum_encryption_key_size),initiator_key_distribution_(initiator_key_distribution),responder_key_distribution_(responder_key_distribution) {CheckParameterValues(maximum_encryption_key_size_);}

void CheckParameterValues(uint8_t maximum_encryption_key_size) {ASSERT(maximum_encryption_key_size < (static_cast<uint64_t>(1) << 5));}

IoCapability io_capability_{};OobDataFlag oob_data_flag_{};uint8_t auth_req_{};uint8_t maximum_encryption_key_size_{};uint8_t initiator_key_distribution_{};uint8_t responder_key_distribution_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_PairingResponseReflectionTest(...)class PairingResponseReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {PairingResponseView view = PairingResponseView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = PairingResponseBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(PairingResponseReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(PairingResponse_reflection, PairingResponseReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_PairingResponseReflectionFuzzTest() void RunPairingResponseReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);PairingResponseView view = PairingResponseView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = PairingResponseBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_PairingResponseReflectionFuzzTest(REGISTRY) DEFINE_PairingResponseReflectionFuzzTest(); class PairingResponseReflectionFuzzTestRegistrant {public: explicit PairingResponseReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunPairingResponseReflectionFuzzTest);}}; PairingResponseReflectionFuzzTestRegistrant PairingResponse_reflection_fuzz_test_registrant(REGISTRY);
#endif


class PairingConfirmBuilder : public CommandBuilder { public:  virtual ~PairingConfirmBuilder() = default;static std::unique_ptr<PairingConfirmBuilder> Create(const std::array<uint8_t,16>& confirm_value) {auto builder = std::unique_ptr<PairingConfirmBuilder>(new PairingConfirmBuilder(confirm_value));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<PairingConfirmBuilder> FromView(PairingConfirmView view) {return PairingConfirmBuilder::Create(view.GetConfirmValue());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);for (const auto& val_ : confirm_value_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 128 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit PairingConfirmBuilder(const std::array<uint8_t,16>& confirm_value) :CommandBuilder(Code::PAIRING_CONFIRM/* code_ */) ,confirm_value_(confirm_value) {}


std::array<uint8_t,16> confirm_value_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_PairingConfirmReflectionTest(...)class PairingConfirmReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {PairingConfirmView view = PairingConfirmView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = PairingConfirmBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(PairingConfirmReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(PairingConfirm_reflection, PairingConfirmReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_PairingConfirmReflectionFuzzTest() void RunPairingConfirmReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);PairingConfirmView view = PairingConfirmView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = PairingConfirmBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_PairingConfirmReflectionFuzzTest(REGISTRY) DEFINE_PairingConfirmReflectionFuzzTest(); class PairingConfirmReflectionFuzzTestRegistrant {public: explicit PairingConfirmReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunPairingConfirmReflectionFuzzTest);}}; PairingConfirmReflectionFuzzTestRegistrant PairingConfirm_reflection_fuzz_test_registrant(REGISTRY);
#endif


class PairingRandomBuilder : public CommandBuilder { public:  virtual ~PairingRandomBuilder() = default;static std::unique_ptr<PairingRandomBuilder> Create(const std::array<uint8_t,16>& random_value) {auto builder = std::unique_ptr<PairingRandomBuilder>(new PairingRandomBuilder(random_value));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<PairingRandomBuilder> FromView(PairingRandomView view) {return PairingRandomBuilder::Create(view.GetRandomValue());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);for (const auto& val_ : random_value_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 128 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit PairingRandomBuilder(const std::array<uint8_t,16>& random_value) :CommandBuilder(Code::PAIRING_RANDOM/* code_ */) ,random_value_(random_value) {}


std::array<uint8_t,16> random_value_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_PairingRandomReflectionTest(...)class PairingRandomReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {PairingRandomView view = PairingRandomView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = PairingRandomBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(PairingRandomReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(PairingRandom_reflection, PairingRandomReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_PairingRandomReflectionFuzzTest() void RunPairingRandomReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);PairingRandomView view = PairingRandomView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = PairingRandomBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_PairingRandomReflectionFuzzTest(REGISTRY) DEFINE_PairingRandomReflectionFuzzTest(); class PairingRandomReflectionFuzzTestRegistrant {public: explicit PairingRandomReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunPairingRandomReflectionFuzzTest);}}; PairingRandomReflectionFuzzTestRegistrant PairingRandom_reflection_fuzz_test_registrant(REGISTRY);
#endif


class PairingFailedBuilder : public CommandBuilder { public:  virtual ~PairingFailedBuilder() = default;static std::unique_ptr<PairingFailedBuilder> Create(PairingFailedReason reason) {auto builder = std::unique_ptr<PairingFailedBuilder>(new PairingFailedBuilder(reason));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<PairingFailedBuilder> FromView(PairingFailedView view) {return PairingFailedBuilder::Create(view.GetReason());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);insert(static_cast<uint8_t>(reason_), i, 8);}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 8 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit PairingFailedBuilder(PairingFailedReason reason) :CommandBuilder(Code::PAIRING_FAILED/* code_ */) ,reason_(reason) {}


PairingFailedReason reason_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_PairingFailedReflectionTest(...)class PairingFailedReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {PairingFailedView view = PairingFailedView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = PairingFailedBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(PairingFailedReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(PairingFailed_reflection, PairingFailedReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_PairingFailedReflectionFuzzTest() void RunPairingFailedReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);PairingFailedView view = PairingFailedView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = PairingFailedBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_PairingFailedReflectionFuzzTest(REGISTRY) DEFINE_PairingFailedReflectionFuzzTest(); class PairingFailedReflectionFuzzTestRegistrant {public: explicit PairingFailedReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunPairingFailedReflectionFuzzTest);}}; PairingFailedReflectionFuzzTestRegistrant PairingFailed_reflection_fuzz_test_registrant(REGISTRY);
#endif


class EncryptionInformationBuilder : public CommandBuilder { public:  virtual ~EncryptionInformationBuilder() = default;static std::unique_ptr<EncryptionInformationBuilder> Create(const std::array<uint8_t,16>& long_term_key) {auto builder = std::unique_ptr<EncryptionInformationBuilder>(new EncryptionInformationBuilder(long_term_key));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<EncryptionInformationBuilder> FromView(EncryptionInformationView view) {return EncryptionInformationBuilder::Create(view.GetLongTermKey());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);for (const auto& val_ : long_term_key_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 128 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit EncryptionInformationBuilder(const std::array<uint8_t,16>& long_term_key) :CommandBuilder(Code::ENCRYPTION_INFORMATION/* code_ */) ,long_term_key_(long_term_key) {}


std::array<uint8_t,16> long_term_key_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_EncryptionInformationReflectionTest(...)class EncryptionInformationReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {EncryptionInformationView view = EncryptionInformationView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = EncryptionInformationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(EncryptionInformationReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(EncryptionInformation_reflection, EncryptionInformationReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_EncryptionInformationReflectionFuzzTest() void RunEncryptionInformationReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);EncryptionInformationView view = EncryptionInformationView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = EncryptionInformationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_EncryptionInformationReflectionFuzzTest(REGISTRY) DEFINE_EncryptionInformationReflectionFuzzTest(); class EncryptionInformationReflectionFuzzTestRegistrant {public: explicit EncryptionInformationReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunEncryptionInformationReflectionFuzzTest);}}; EncryptionInformationReflectionFuzzTestRegistrant EncryptionInformation_reflection_fuzz_test_registrant(REGISTRY);
#endif


class CentralIdentificationBuilder : public CommandBuilder { public:  virtual ~CentralIdentificationBuilder() = default;static std::unique_ptr<CentralIdentificationBuilder> Create(uint16_t ediv, const std::array<uint8_t,8>& rand) {auto builder = std::unique_ptr<CentralIdentificationBuilder>(new CentralIdentificationBuilder(ediv, rand));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<CentralIdentificationBuilder> FromView(CentralIdentificationView view) {return CentralIdentificationBuilder::Create(view.GetEdiv(), view.GetRand());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);insert(ediv_, i,16);for (const auto& val_ : rand_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 16 + /* Dynamic: */ 0 + /* Bits: */ 64 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit CentralIdentificationBuilder(uint16_t ediv, const std::array<uint8_t,8>& rand) :CommandBuilder(Code::CENTRAL_IDENTIFICATION/* code_ */) ,ediv_(ediv),rand_(rand) {}


uint16_t ediv_{};std::array<uint8_t,8> rand_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_CentralIdentificationReflectionTest(...)class CentralIdentificationReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {CentralIdentificationView view = CentralIdentificationView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = CentralIdentificationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(CentralIdentificationReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(CentralIdentification_reflection, CentralIdentificationReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_CentralIdentificationReflectionFuzzTest() void RunCentralIdentificationReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);CentralIdentificationView view = CentralIdentificationView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = CentralIdentificationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_CentralIdentificationReflectionFuzzTest(REGISTRY) DEFINE_CentralIdentificationReflectionFuzzTest(); class CentralIdentificationReflectionFuzzTestRegistrant {public: explicit CentralIdentificationReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunCentralIdentificationReflectionFuzzTest);}}; CentralIdentificationReflectionFuzzTestRegistrant CentralIdentification_reflection_fuzz_test_registrant(REGISTRY);
#endif


class IdentityInformationBuilder : public CommandBuilder { public:  virtual ~IdentityInformationBuilder() = default;static std::unique_ptr<IdentityInformationBuilder> Create(const std::array<uint8_t,16>& identity_resolving_key) {auto builder = std::unique_ptr<IdentityInformationBuilder>(new IdentityInformationBuilder(identity_resolving_key));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<IdentityInformationBuilder> FromView(IdentityInformationView view) {return IdentityInformationBuilder::Create(view.GetIdentityResolvingKey());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);for (const auto& val_ : identity_resolving_key_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 128 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit IdentityInformationBuilder(const std::array<uint8_t,16>& identity_resolving_key) :CommandBuilder(Code::IDENTITY_INFORMATION/* code_ */) ,identity_resolving_key_(identity_resolving_key) {}


std::array<uint8_t,16> identity_resolving_key_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_IdentityInformationReflectionTest(...)class IdentityInformationReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {IdentityInformationView view = IdentityInformationView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = IdentityInformationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(IdentityInformationReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(IdentityInformation_reflection, IdentityInformationReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_IdentityInformationReflectionFuzzTest() void RunIdentityInformationReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);IdentityInformationView view = IdentityInformationView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = IdentityInformationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_IdentityInformationReflectionFuzzTest(REGISTRY) DEFINE_IdentityInformationReflectionFuzzTest(); class IdentityInformationReflectionFuzzTestRegistrant {public: explicit IdentityInformationReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunIdentityInformationReflectionFuzzTest);}}; IdentityInformationReflectionFuzzTestRegistrant IdentityInformation_reflection_fuzz_test_registrant(REGISTRY);
#endif


class IdentityAddressInformationBuilder : public CommandBuilder { public:  virtual ~IdentityAddressInformationBuilder() = default;static std::unique_ptr<IdentityAddressInformationBuilder> Create(AddrType addr_type, Address bd_addr) {auto builder = std::unique_ptr<IdentityAddressInformationBuilder>(new IdentityAddressInformationBuilder(addr_type, bd_addr));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<IdentityAddressInformationBuilder> FromView(IdentityAddressInformationView view) {return IdentityAddressInformationBuilder::Create(view.GetAddrType(), view.GetBdAddr());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);insert(static_cast<uint8_t>(addr_type_), i, 8);insert(bd_addr_, i);}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 48 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit IdentityAddressInformationBuilder(AddrType addr_type, Address bd_addr) :CommandBuilder(Code::IDENTITY_ADDRESS_INFORMATION/* code_ */) ,addr_type_(addr_type),bd_addr_(bd_addr) {}


AddrType addr_type_{};Address bd_addr_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_IdentityAddressInformationReflectionTest(...)class IdentityAddressInformationReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {IdentityAddressInformationView view = IdentityAddressInformationView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = IdentityAddressInformationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(IdentityAddressInformationReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(IdentityAddressInformation_reflection, IdentityAddressInformationReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_IdentityAddressInformationReflectionFuzzTest() void RunIdentityAddressInformationReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);IdentityAddressInformationView view = IdentityAddressInformationView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = IdentityAddressInformationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_IdentityAddressInformationReflectionFuzzTest(REGISTRY) DEFINE_IdentityAddressInformationReflectionFuzzTest(); class IdentityAddressInformationReflectionFuzzTestRegistrant {public: explicit IdentityAddressInformationReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunIdentityAddressInformationReflectionFuzzTest);}}; IdentityAddressInformationReflectionFuzzTestRegistrant IdentityAddressInformation_reflection_fuzz_test_registrant(REGISTRY);
#endif


class SigningInformationBuilder : public CommandBuilder { public:  virtual ~SigningInformationBuilder() = default;static std::unique_ptr<SigningInformationBuilder> Create(const std::array<uint8_t,16>& signature_key) {auto builder = std::unique_ptr<SigningInformationBuilder>(new SigningInformationBuilder(signature_key));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<SigningInformationBuilder> FromView(SigningInformationView view) {return SigningInformationBuilder::Create(view.GetSignatureKey());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);for (const auto& val_ : signature_key_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 128 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit SigningInformationBuilder(const std::array<uint8_t,16>& signature_key) :CommandBuilder(Code::SIGNING_INFORMATION/* code_ */) ,signature_key_(signature_key) {}


std::array<uint8_t,16> signature_key_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_SigningInformationReflectionTest(...)class SigningInformationReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {SigningInformationView view = SigningInformationView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = SigningInformationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(SigningInformationReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(SigningInformation_reflection, SigningInformationReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_SigningInformationReflectionFuzzTest() void RunSigningInformationReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);SigningInformationView view = SigningInformationView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = SigningInformationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_SigningInformationReflectionFuzzTest(REGISTRY) DEFINE_SigningInformationReflectionFuzzTest(); class SigningInformationReflectionFuzzTestRegistrant {public: explicit SigningInformationReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunSigningInformationReflectionFuzzTest);}}; SigningInformationReflectionFuzzTestRegistrant SigningInformation_reflection_fuzz_test_registrant(REGISTRY);
#endif


class SecurityRequestBuilder : public CommandBuilder { public:  virtual ~SecurityRequestBuilder() = default;static std::unique_ptr<SecurityRequestBuilder> Create(uint8_t auth_req) {auto builder = std::unique_ptr<SecurityRequestBuilder>(new SecurityRequestBuilder(auth_req));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<SecurityRequestBuilder> FromView(SecurityRequestView view) {return SecurityRequestBuilder::Create(view.GetAuthReq());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);i.insert_byte(auth_req_);}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 8 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit SecurityRequestBuilder(uint8_t auth_req) :CommandBuilder(Code::SECURITY_REQUEST/* code_ */) ,auth_req_(auth_req) {}


uint8_t auth_req_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_SecurityRequestReflectionTest(...)class SecurityRequestReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {SecurityRequestView view = SecurityRequestView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = SecurityRequestBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(SecurityRequestReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(SecurityRequest_reflection, SecurityRequestReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_SecurityRequestReflectionFuzzTest() void RunSecurityRequestReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);SecurityRequestView view = SecurityRequestView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = SecurityRequestBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_SecurityRequestReflectionFuzzTest(REGISTRY) DEFINE_SecurityRequestReflectionFuzzTest(); class SecurityRequestReflectionFuzzTestRegistrant {public: explicit SecurityRequestReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunSecurityRequestReflectionFuzzTest);}}; SecurityRequestReflectionFuzzTestRegistrant SecurityRequest_reflection_fuzz_test_registrant(REGISTRY);
#endif


class PairingPublicKeyBuilder : public CommandBuilder { public:  virtual ~PairingPublicKeyBuilder() = default;static std::unique_ptr<PairingPublicKeyBuilder> Create(const std::array<uint8_t,32>& public_key_x, const std::array<uint8_t,32>& public_key_y) {auto builder = std::unique_ptr<PairingPublicKeyBuilder>(new PairingPublicKeyBuilder(public_key_x, public_key_y));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<PairingPublicKeyBuilder> FromView(PairingPublicKeyView view) {return PairingPublicKeyBuilder::Create(view.GetPublicKeyX(), view.GetPublicKeyY());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);for (const auto& val_ : public_key_x_) {i.insert_byte(val_);}
for (const auto& val_ : public_key_y_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 256 + /* Dynamic: */ 0 + /* Bits: */ 256 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit PairingPublicKeyBuilder(const std::array<uint8_t,32>& public_key_x, const std::array<uint8_t,32>& public_key_y) :CommandBuilder(Code::PAIRING_PUBLIC_KEY/* code_ */) ,public_key_x_(public_key_x),public_key_y_(public_key_y) {}


std::array<uint8_t,32> public_key_x_{};std::array<uint8_t,32> public_key_y_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_PairingPublicKeyReflectionTest(...)class PairingPublicKeyReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {PairingPublicKeyView view = PairingPublicKeyView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = PairingPublicKeyBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(PairingPublicKeyReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(PairingPublicKey_reflection, PairingPublicKeyReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_PairingPublicKeyReflectionFuzzTest() void RunPairingPublicKeyReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);PairingPublicKeyView view = PairingPublicKeyView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = PairingPublicKeyBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_PairingPublicKeyReflectionFuzzTest(REGISTRY) DEFINE_PairingPublicKeyReflectionFuzzTest(); class PairingPublicKeyReflectionFuzzTestRegistrant {public: explicit PairingPublicKeyReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunPairingPublicKeyReflectionFuzzTest);}}; PairingPublicKeyReflectionFuzzTestRegistrant PairingPublicKey_reflection_fuzz_test_registrant(REGISTRY);
#endif


class PairingDhKeyCheckBuilder : public CommandBuilder { public:  virtual ~PairingDhKeyCheckBuilder() = default;static std::unique_ptr<PairingDhKeyCheckBuilder> Create(const std::array<uint8_t,16>& dh_key_check) {auto builder = std::unique_ptr<PairingDhKeyCheckBuilder>(new PairingDhKeyCheckBuilder(dh_key_check));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<PairingDhKeyCheckBuilder> FromView(PairingDhKeyCheckView view) {return PairingDhKeyCheckBuilder::Create(view.GetDhKeyCheck());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);for (const auto& val_ : dh_key_check_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 128 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit PairingDhKeyCheckBuilder(const std::array<uint8_t,16>& dh_key_check) :CommandBuilder(Code::PAIRING_DH_KEY_CHECK/* code_ */) ,dh_key_check_(dh_key_check) {}


std::array<uint8_t,16> dh_key_check_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_PairingDhKeyCheckReflectionTest(...)class PairingDhKeyCheckReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {PairingDhKeyCheckView view = PairingDhKeyCheckView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = PairingDhKeyCheckBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(PairingDhKeyCheckReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(PairingDhKeyCheck_reflection, PairingDhKeyCheckReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_PairingDhKeyCheckReflectionFuzzTest() void RunPairingDhKeyCheckReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);PairingDhKeyCheckView view = PairingDhKeyCheckView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = PairingDhKeyCheckBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_PairingDhKeyCheckReflectionFuzzTest(REGISTRY) DEFINE_PairingDhKeyCheckReflectionFuzzTest(); class PairingDhKeyCheckReflectionFuzzTestRegistrant {public: explicit PairingDhKeyCheckReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunPairingDhKeyCheckReflectionFuzzTest);}}; PairingDhKeyCheckReflectionFuzzTestRegistrant PairingDhKeyCheck_reflection_fuzz_test_registrant(REGISTRY);
#endif


class PairingKeypressNotificationBuilder : public CommandBuilder { public:  virtual ~PairingKeypressNotificationBuilder() = default;static std::unique_ptr<PairingKeypressNotificationBuilder> Create(KeypressNotificationType notification_type) {auto builder = std::unique_ptr<PairingKeypressNotificationBuilder>(new PairingKeypressNotificationBuilder(notification_type));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<PairingKeypressNotificationBuilder> FromView(PairingKeypressNotificationView view) {return PairingKeypressNotificationBuilder::Create(view.GetNotificationType());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {CommandBuilder::SerializeHeader(i);insert(static_cast<uint8_t>(notification_type_), i, 8);}

void SerializeFooter(BitInserter& i ) const {CommandBuilder::SerializeFooter(i);}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + CommandBuilder::BitsOfHeader()  + /* Bits: */ 8 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0 + CommandBuilder::BitsOfFooter() ;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit PairingKeypressNotificationBuilder(KeypressNotificationType notification_type) :CommandBuilder(Code::PAIRING_KEYPRESS_NOTIFICATION/* code_ */) ,notification_type_(notification_type) {}


KeypressNotificationType notification_type_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_PairingKeypressNotificationReflectionTest(...)class PairingKeypressNotificationReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {PairingKeypressNotificationView view = PairingKeypressNotificationView::FromBytes(captured_packet);if (!view.IsValid()) { LOG_INFO("Invalid Packet Bytes (size = %zu)", view.size());for (size_t i = 0; i < view.size(); i++) { LOG_INFO("%5zd:%02X", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = PairingKeypressNotificationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(PairingKeypressNotificationReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(PairingKeypressNotification_reflection, PairingKeypressNotificationReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_PairingKeypressNotificationReflectionFuzzTest() void RunPairingKeypressNotificationReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);PairingKeypressNotificationView view = PairingKeypressNotificationView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = PairingKeypressNotificationBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif
#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_PairingKeypressNotificationReflectionFuzzTest(REGISTRY) DEFINE_PairingKeypressNotificationReflectionFuzzTest(); class PairingKeypressNotificationReflectionFuzzTestRegistrant {public: explicit PairingKeypressNotificationReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunPairingKeypressNotificationReflectionFuzzTest);}}; PairingKeypressNotificationReflectionFuzzTestRegistrant PairingKeypressNotification_reflection_fuzz_test_registrant(REGISTRY);
#endif


}  //namespace security
}  //namespace bluetooth
