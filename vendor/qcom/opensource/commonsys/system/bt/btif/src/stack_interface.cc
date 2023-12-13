/******************************************************************************
 *  Copyright (c) 2020, The Linux Foundation. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials provided
 *        with the distribution.
 *      * Neither the name of The Linux Foundation nor the names of its
 *        contributors may be used to endorse or promote products derived
 *        from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 *  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 *  ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 *  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 *  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 *  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#define LOG_TAG "bt_stack_interface"

#include "stack_interface.h"
#include "btif_common.h"
#include "osi/include/log.h"
#include "osi/include/osi.h"
#include "bt_features.h"
#ifdef ADV_AUDIO_FEATURE
#include "bluetooth_adv_audio.h"
#endif

class StackInterfaceImpl;
StackInterfaceImpl *instance = nullptr;

void init_external_interfaces(void) {
#ifdef ADV_AUDIO_FEATURE
  init_adv_audio_interfaces();
#endif
}

const void* get_external_profile_interface(const char* profile_id) {
#ifdef ADV_AUDIO_FEATURE
  return get_adv_audio_profile_interface(profile_id);
#endif
  return nullptr;
}

class StackInterfaceImpl : public StackInterface {
 public:
  StackInterfaceImpl(StackCallbacks* callback):
      callbacks(callback)  { }

  ~StackInterfaceImpl() override = default;

  void CleanUp () {

  }

  void OnDevUnPaired(const RawAddress& address) {
    callbacks->OnDevUnPaired(address);
  }

  void OnConfigCleared() {
    callbacks->OnConfigCleared();
  }

  void OnStackState(StackState state) {
    callbacks->OnStackState(state);
  }

 private:
  StackCallbacks *callbacks;
};

// Interface functions
void btif_stack_dev_unpaired(const RawAddress& address) {
  if (instance) {
    LOG(WARNING) << __func__ << " OnDevUnPaired";
    instance->OnDevUnPaired(address);
  }
}

void btif_stack_config_cleared(void) {
  if (instance) {
    LOG(WARNING) << __func__ << " OnConfigCleared";
    instance->OnConfigCleared();
  }
}

void btif_stack_state(StackState state) {
  if (instance) {
    LOG(WARNING) << __func__ << " OnStackState "
                 << loghex(static_cast<uint8_t> (state));
    instance->OnStackState(state);
  }
}

void StackInterface::Initialize(StackCallbacks* callbacks) {
  if (instance) {
    LOG(ERROR) << __func__ << " Already initialized!";
  } else {
    instance = new StackInterfaceImpl(callbacks);
  }
}

void StackInterface::CleanUp() {
  StackInterfaceImpl* ptr = instance;
  instance = nullptr;
  ptr->CleanUp();
  delete ptr;
}

StackInterface* StackInterface::Get() {
  CHECK(instance);
  return instance;
}