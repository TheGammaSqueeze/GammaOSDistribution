#!/vendor/bin/sh
# Copyright (c) 2020 The Linux Foundation. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above
#       copyright notice, this list of conditions and the following
#       disclaimer in the documentation and/or other materials provided
#       with the distribution.
#     * Neither the name of The Linux Foundation nor the names of its
#       contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
# ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
# BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
# OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
# IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

# Enable various ftrace debugging events
tracefs=/sys/kernel/tracing

if [ -d $tracefs ]; then
    mkdir $tracefs/instances/usb

    # dwc3
    echo 1 > $tracefs/instances/usb/events/dwc3/dwc3_complete_trb/enable
    echo 1 > $tracefs/instances/usb/events/dwc3/dwc3_ctrl_req/enable
    echo 1 > $tracefs/instances/usb/events/dwc3/dwc3_ep_dequeue/enable
    echo 1 > $tracefs/instances/usb/events/dwc3/dwc3_ep_queue/enable
    echo 1 > $tracefs/instances/usb/events/dwc3/dwc3_gadget_ep_cmd/enable
    echo 1 > $tracefs/instances/usb/events/dwc3/dwc3_gadget_ep_disable/enable
    echo 1 > $tracefs/instances/usb/events/dwc3/dwc3_gadget_ep_enable/enable
    echo 1 > $tracefs/instances/usb/events/dwc3/dwc3_gadget_giveback/enable
    echo 1 > $tracefs/instances/usb/events/dwc3/dwc3_prepare_trb/enable

    # ucsi
    echo 1 > $tracefs/instances/usb/events/ucsi/ucsi_connector_change/enable
    echo 1 > $tracefs/instances/usb/events/ucsi/ucsi_reset_ppm/enable
    echo 1 > $tracefs/instances/usb/events/ucsi/ucsi_run_command/enable

    echo 1 > $tracefs/instances/usb/tracing_on
fi
