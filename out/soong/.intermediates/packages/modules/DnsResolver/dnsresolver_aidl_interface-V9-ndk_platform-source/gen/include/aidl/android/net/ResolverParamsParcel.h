#pragma once
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <aidl/android/net/ResolverOptionsParcel.h>
namespace aidl {
namespace android {
namespace net {
class ResolverParamsParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t netId = 0;
  int32_t sampleValiditySeconds = 0;
  int32_t successThreshold = 0;
  int32_t minSamples = 0;
  int32_t maxSamples = 0;
  int32_t baseTimeoutMsec = 0;
  int32_t retryCount = 0;
  std::vector<std::string> servers;
  std::vector<std::string> domains;
  std::string tlsName;
  std::vector<std::string> tlsServers;
  std::vector<std::string> tlsFingerprints = {};
  std::string caCertificate = "";
  int32_t tlsConnectTimeoutMs = 0;
  std::optional<::aidl::android::net::ResolverOptionsParcel> resolverOptions;
  std::vector<int32_t> transportTypes = {};

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const ResolverParamsParcel& rhs) const {
    return std::tie(netId, sampleValiditySeconds, successThreshold, minSamples, maxSamples, baseTimeoutMsec, retryCount, servers, domains, tlsName, tlsServers, tlsFingerprints, caCertificate, tlsConnectTimeoutMs, resolverOptions, transportTypes) != std::tie(rhs.netId, rhs.sampleValiditySeconds, rhs.successThreshold, rhs.minSamples, rhs.maxSamples, rhs.baseTimeoutMsec, rhs.retryCount, rhs.servers, rhs.domains, rhs.tlsName, rhs.tlsServers, rhs.tlsFingerprints, rhs.caCertificate, rhs.tlsConnectTimeoutMs, rhs.resolverOptions, rhs.transportTypes);
  }
  inline bool operator<(const ResolverParamsParcel& rhs) const {
    return std::tie(netId, sampleValiditySeconds, successThreshold, minSamples, maxSamples, baseTimeoutMsec, retryCount, servers, domains, tlsName, tlsServers, tlsFingerprints, caCertificate, tlsConnectTimeoutMs, resolverOptions, transportTypes) < std::tie(rhs.netId, rhs.sampleValiditySeconds, rhs.successThreshold, rhs.minSamples, rhs.maxSamples, rhs.baseTimeoutMsec, rhs.retryCount, rhs.servers, rhs.domains, rhs.tlsName, rhs.tlsServers, rhs.tlsFingerprints, rhs.caCertificate, rhs.tlsConnectTimeoutMs, rhs.resolverOptions, rhs.transportTypes);
  }
  inline bool operator<=(const ResolverParamsParcel& rhs) const {
    return std::tie(netId, sampleValiditySeconds, successThreshold, minSamples, maxSamples, baseTimeoutMsec, retryCount, servers, domains, tlsName, tlsServers, tlsFingerprints, caCertificate, tlsConnectTimeoutMs, resolverOptions, transportTypes) <= std::tie(rhs.netId, rhs.sampleValiditySeconds, rhs.successThreshold, rhs.minSamples, rhs.maxSamples, rhs.baseTimeoutMsec, rhs.retryCount, rhs.servers, rhs.domains, rhs.tlsName, rhs.tlsServers, rhs.tlsFingerprints, rhs.caCertificate, rhs.tlsConnectTimeoutMs, rhs.resolverOptions, rhs.transportTypes);
  }
  inline bool operator==(const ResolverParamsParcel& rhs) const {
    return std::tie(netId, sampleValiditySeconds, successThreshold, minSamples, maxSamples, baseTimeoutMsec, retryCount, servers, domains, tlsName, tlsServers, tlsFingerprints, caCertificate, tlsConnectTimeoutMs, resolverOptions, transportTypes) == std::tie(rhs.netId, rhs.sampleValiditySeconds, rhs.successThreshold, rhs.minSamples, rhs.maxSamples, rhs.baseTimeoutMsec, rhs.retryCount, rhs.servers, rhs.domains, rhs.tlsName, rhs.tlsServers, rhs.tlsFingerprints, rhs.caCertificate, rhs.tlsConnectTimeoutMs, rhs.resolverOptions, rhs.transportTypes);
  }
  inline bool operator>(const ResolverParamsParcel& rhs) const {
    return std::tie(netId, sampleValiditySeconds, successThreshold, minSamples, maxSamples, baseTimeoutMsec, retryCount, servers, domains, tlsName, tlsServers, tlsFingerprints, caCertificate, tlsConnectTimeoutMs, resolverOptions, transportTypes) > std::tie(rhs.netId, rhs.sampleValiditySeconds, rhs.successThreshold, rhs.minSamples, rhs.maxSamples, rhs.baseTimeoutMsec, rhs.retryCount, rhs.servers, rhs.domains, rhs.tlsName, rhs.tlsServers, rhs.tlsFingerprints, rhs.caCertificate, rhs.tlsConnectTimeoutMs, rhs.resolverOptions, rhs.transportTypes);
  }
  inline bool operator>=(const ResolverParamsParcel& rhs) const {
    return std::tie(netId, sampleValiditySeconds, successThreshold, minSamples, maxSamples, baseTimeoutMsec, retryCount, servers, domains, tlsName, tlsServers, tlsFingerprints, caCertificate, tlsConnectTimeoutMs, resolverOptions, transportTypes) >= std::tie(rhs.netId, rhs.sampleValiditySeconds, rhs.successThreshold, rhs.minSamples, rhs.maxSamples, rhs.baseTimeoutMsec, rhs.retryCount, rhs.servers, rhs.domains, rhs.tlsName, rhs.tlsServers, rhs.tlsFingerprints, rhs.caCertificate, rhs.tlsConnectTimeoutMs, rhs.resolverOptions, rhs.transportTypes);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "ResolverParamsParcel{";
    os << "netId: " << ::android::internal::ToString(netId);
    os << ", sampleValiditySeconds: " << ::android::internal::ToString(sampleValiditySeconds);
    os << ", successThreshold: " << ::android::internal::ToString(successThreshold);
    os << ", minSamples: " << ::android::internal::ToString(minSamples);
    os << ", maxSamples: " << ::android::internal::ToString(maxSamples);
    os << ", baseTimeoutMsec: " << ::android::internal::ToString(baseTimeoutMsec);
    os << ", retryCount: " << ::android::internal::ToString(retryCount);
    os << ", servers: " << ::android::internal::ToString(servers);
    os << ", domains: " << ::android::internal::ToString(domains);
    os << ", tlsName: " << ::android::internal::ToString(tlsName);
    os << ", tlsServers: " << ::android::internal::ToString(tlsServers);
    os << ", tlsFingerprints: " << ::android::internal::ToString(tlsFingerprints);
    os << ", caCertificate: " << ::android::internal::ToString(caCertificate);
    os << ", tlsConnectTimeoutMs: " << ::android::internal::ToString(tlsConnectTimeoutMs);
    os << ", resolverOptions: " << ::android::internal::ToString(resolverOptions);
    os << ", transportTypes: " << ::android::internal::ToString(transportTypes);
    os << "}";
    return os.str();
  }
};
}  // namespace net
}  // namespace android
}  // namespace aidl
