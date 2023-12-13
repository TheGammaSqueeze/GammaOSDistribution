//! Hci shim

use crate::bridge::ffi;
use bt_facade_helpers::U8SliceRunnable;
use bt_hci::facade::HciFacadeService;
use bt_packets::hci::{AclPacket, CommandPacket, Packet};
use std::sync::Arc;
use tokio::runtime::Runtime;

// we take ownership when we get the callbacks
unsafe impl Send for ffi::u8SliceCallback {}
unsafe impl Send for ffi::u8SliceOnceCallback {}

struct CallbackWrapper {
    cb: cxx::UniquePtr<ffi::u8SliceCallback>,
}

impl U8SliceRunnable for CallbackWrapper {
    fn run(&self, data: &[u8]) {
        self.cb.Run(data);
    }
}

pub struct Hci {
    internal: HciFacadeService,
    rt: Arc<Runtime>,
}

impl Hci {
    pub fn new(rt: Arc<Runtime>, internal: HciFacadeService) -> Self {
        Self { rt, internal }
    }
}

pub fn hci_send_command(
    hci: &mut Hci,
    data: &[u8],
    callback: cxx::UniquePtr<ffi::u8SliceOnceCallback>,
) {
    log::error!("sending command: {:02x?}", data);
    match CommandPacket::parse(data) {
        Ok(packet) => {
            let mut commands = hci.internal.commands.clone();
            hci.rt.spawn(async move {
                let resp = commands.send(packet).await.unwrap();
                callback.Run(&resp.to_bytes());
            });
        }
        Err(e) => panic!("could not parse command: {:?} {:02x?}", e, data),
    }
}

pub fn hci_send_acl(hci: &mut Hci, data: &[u8]) {
    match AclPacket::parse(data) {
        Ok(packet) => {
            let tx = hci.internal.acl_tx.clone();
            hci.rt.spawn(async move {
                tx.send(packet).await.unwrap();
            });
        }
        Err(e) => panic!("could not parse acl: {:?} {:02x?}", e, data),
    }
}

pub fn hci_register_event(hci: &mut Hci, event: u8) {
    let mut hci_facade = hci.internal.clone();
    hci.rt.spawn(async move {
        hci_facade.register_event(event.into()).await;
    });
}

pub fn hci_register_le_event(hci: &mut Hci, subevent: u8) {
    let mut hci_facade = hci.internal.clone();
    hci.rt.spawn(async move {
        hci_facade.register_le_event(subevent.into()).await;
    });
}

pub fn hci_set_acl_callback(hci: &mut Hci, cb: cxx::UniquePtr<ffi::u8SliceCallback>) {
    hci.internal.acl_rx.stream_runnable(&hci.rt, CallbackWrapper { cb });
}

pub fn hci_set_evt_callback(hci: &mut Hci, cb: cxx::UniquePtr<ffi::u8SliceCallback>) {
    hci.internal.evt_rx.stream_runnable(&hci.rt, CallbackWrapper { cb });
}

pub fn hci_set_le_evt_callback(hci: &mut Hci, cb: cxx::UniquePtr<ffi::u8SliceCallback>) {
    hci.internal.le_evt_rx.stream_runnable(&hci.rt, CallbackWrapper { cb });
}
