/*
 * Copyright (C) 2017 The Android Open Source Project
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

#include <set>
#include <string>
#include <vector>

#include <netinet/in.h>

#include <params.h>

#include "IPrivateDnsServer.h"

namespace android {
namespace net {

// DnsTlsServer represents a recursive resolver that supports, or may support, a
// secure protocol.
struct DnsTlsServer : public IPrivateDnsServer {
    // Default constructor.
    DnsTlsServer() {}

    // Allow sockaddr_storage to be promoted to DnsTlsServer automatically.
    DnsTlsServer(const sockaddr_storage& ss) : ss(ss) {}

    // The server location, including IP and port.
    // TODO: make it const.
    sockaddr_storage ss = {};

    // The server's hostname.  If this string is nonempty, the server must present a
    // certificate that indicates this name and has a valid chain to a trusted root CA.
    // TODO: make it const.
    std::string name;

    // The certificate of the CA that signed the server's certificate.
    // It is used to store temporary test CA certificate for internal tests.
    // TODO: make it const.
    std::string certificate;

    // Placeholder.  More protocols might be defined in the future.
    // TODO: make it const.
    int protocol = IPPROTO_TCP;

    // Exact comparison of DnsTlsServer objects
    bool operator<(const DnsTlsServer& other) const;
    bool operator==(const DnsTlsServer& other) const;

    bool wasExplicitlyConfigured() const;
    std::string toIpString() const;

    PrivateDnsTransport transport() const override { return PrivateDnsTransport::kDot; }
    std::string provider() const override { return name; }
    netdutils::IPSockAddr addr() const override { return netdutils::IPSockAddr::toIPSockAddr(ss); }
    uint32_t validationMark() const override { return mark; }

    Validation validationState() const override { return mValidation; }
    void setValidationState(Validation val) override { mValidation = val; }
    bool probe() override {
        // TODO: implement it.
        return false;
    }

    // The socket mark used for validation.
    // Note that the mark of a connection to which the DnsResolver sends app's DNS requests can
    // be different.
    // TODO: make it const.
    uint32_t mark = 0;

    // Return whether or not the server can be used for a network. It depends on
    // the resolver configuration.
    bool active() const override { return mActive; }
    void setActive(bool val) override { mActive = val; }

  private:
    // State, unrelated to the comparison of DnsTlsServer objects.
    Validation mValidation = Validation::unknown_server;
    bool mActive = false;
};

// This comparison only checks the IP address.  It ignores ports, names, and fingerprints.
struct AddressComparator {
    bool operator()(const DnsTlsServer& x, const DnsTlsServer& y) const;
};

}  // namespace net
}  // namespace android
