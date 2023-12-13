#pragma once

#include <android/binder_to_string.h>
#include <android/net/ResolverOptionsParcel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace net {

class ResolverParamsParcel : public ::android::Parcelable {
public:
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

  int32_t netId = int32_t(0);
  int32_t sampleValiditySeconds = int32_t(0);
  int32_t successThreshold = int32_t(0);
  int32_t minSamples = int32_t(0);
  int32_t maxSamples = int32_t(0);
  int32_t baseTimeoutMsec = int32_t(0);
  int32_t retryCount = int32_t(0);
  ::std::vector<::std::string> servers;
  ::std::vector<::std::string> domains;
  ::std::string tlsName;
  ::std::vector<::std::string> tlsServers;
  ::std::vector<::std::string> tlsFingerprints = ::std::vector<::std::string>({});
  ::std::string caCertificate = ::std::string("");
  int32_t tlsConnectTimeoutMs = int32_t(0);
  ::android::net::ResolverOptionsParcel resolverOptions;
  ::std::vector<int32_t> transportTypes = ::std::vector<int32_t>({});
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.ResolverParamsParcel");
    return DESCIPTOR;
  }
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
};  // class ResolverParamsParcel

}  // namespace net

}  // namespace android
