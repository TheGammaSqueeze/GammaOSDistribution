/*
 * Copyright 2021 The Android Open Source Project
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

#include "stack/include/bt_types.h"
#include "stack/include/hcidefs.h"

/**
 * Create a bitmask of packet types from the remote feature
 */
class PeerPacketTypes {
 public:
  struct {
    uint16_t supported{0};
    uint16_t unsupported{0};
  } acl, sco;

  PeerPacketTypes(const BD_FEATURES& features) {
    /* 3 and 5 slot packets? */
    if (HCI_3_SLOT_PACKETS_SUPPORTED(features))
      acl.supported |= (HCI_PKT_TYPES_MASK_DH3 | HCI_PKT_TYPES_MASK_DM3);

    if (HCI_5_SLOT_PACKETS_SUPPORTED(features))
      acl.supported |= HCI_PKT_TYPES_MASK_DH5 | HCI_PKT_TYPES_MASK_DM5;

    /* 2 and 3 MPS support? */
    if (!HCI_EDR_ACL_2MPS_SUPPORTED(features))
      /* Not supported. Add 'not_supported' mask for all 2MPS packet types */
      acl.unsupported |=
          (HCI_PKT_TYPES_MASK_NO_2_DH1 | HCI_PKT_TYPES_MASK_NO_2_DH3 |
           HCI_PKT_TYPES_MASK_NO_2_DH5);

    if (!HCI_EDR_ACL_3MPS_SUPPORTED(features))
      /* Not supported. Add 'not_supported' mask for all 3MPS packet types */
      acl.unsupported |=
          (HCI_PKT_TYPES_MASK_NO_3_DH1 | HCI_PKT_TYPES_MASK_NO_3_DH3 |
           HCI_PKT_TYPES_MASK_NO_3_DH5);

    /* EDR 3 and 5 slot support? */
    if (HCI_EDR_ACL_2MPS_SUPPORTED(features) ||
        HCI_EDR_ACL_3MPS_SUPPORTED(features)) {
      if (!HCI_3_SLOT_EDR_ACL_SUPPORTED(features))
        /* Not supported. Add 'not_supported' mask for all 3-slot EDR packet
         * types
         */
        acl.unsupported |=
            (HCI_PKT_TYPES_MASK_NO_2_DH3 | HCI_PKT_TYPES_MASK_NO_3_DH3);

      if (!HCI_5_SLOT_EDR_ACL_SUPPORTED(features))
        /* Not supported. Add 'not_supported' mask for all 5-slot EDR packet
         * types
         */
        acl.unsupported |=
            (HCI_PKT_TYPES_MASK_NO_2_DH5 | HCI_PKT_TYPES_MASK_NO_3_DH5);
    }
  }
};
