// Copyright 2021 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

//! Library for implementing vhost-user device executables.
//!
//! This crate provides
//! * `VhostUserBackend` trait, which is a collection of methods to handle vhost-user requests, and
//! * `DeviceRequestHandler` struct, which makes a connection to a VMM and starts an event loop.
//!
//! They are expected to be used as follows:
//!
//! 1. Define a struct and implement `VhostUserBackend` for it.
//! 2. Create a `DeviceRequestHandler` with the backend struct.
//! 3. Drive the `DeviceRequestHandler::run` async fn with an executor.
//!
//! ```ignore
//! struct MyBackend {
//!   /* fields */
//! }
//!
//! impl VhostUserBackend for MyBackend {
//!   /* implement methods */
//! }
//!
//! fn main() -> Result<(), Box<dyn Error>> {
//!   let backend = MyBackend { /* initialize fields */ };
//!   let handler = DeviceRequestHandler::new(backend);
//!   let socket = std::path::Path("/path/to/socket");
//!   let ex = cros_async::Executor::new()?;
//!
//!   if let Err(e) = ex.run_until(handler.run(socket, &ex)) {
//!     eprintln!("error happened: {}", e);
//!   }
//!   Ok(())
//! }
//! ```
//!
// Implementation note:
// This code lets us take advantage of the vmm_vhost low level implementation of the vhost user
// protocol. DeviceRequestHandler implements the VhostUserSlaveReqHandlerMut trait from vmm_vhost,
// and includes some common code for setting up guest memory and managing partially configured
// vrings. DeviceRequestHandler::run watches the vhost-user socket and then calls handle_request()
// when it becomes readable. handle_request() reads and parses the message and then calls one of the
// VhostUserSlaveReqHandlerMut trait methods. These dispatch back to the supplied VhostUserBackend
// implementation (this is what our devices implement).

use std::convert::TryFrom;
use std::fs::File;
use std::num::Wrapping;
use std::os::unix::io::AsRawFd;
use std::path::Path;
use std::sync::Arc;

use base::{
    error, Event, FromRawDescriptor, IntoRawDescriptor, SafeDescriptor, SharedMemory,
    SharedMemoryUnix,
};
use cros_async::{AsyncError, AsyncWrapper, Executor};
use devices::virtio::{Queue, SignalableInterrupt};
use remain::sorted;
use sync::Mutex;
use sys_util::clear_fd_flags;
use thiserror::Error as ThisError;
use vm_memory::{GuestAddress, GuestMemory, MemoryRegion};
use vmm_vhost::vhost_user::message::{
    VhostUserConfigFlags, VhostUserInflight, VhostUserMemoryRegion, VhostUserProtocolFeatures,
    VhostUserSingleMemoryRegion, VhostUserVirtioFeatures, VhostUserVringAddrFlags,
    VhostUserVringState,
};
use vmm_vhost::vhost_user::{
    Error as VhostError, Listener, Result as VhostResult, SlaveListener,
    VhostUserSlaveReqHandlerMut,
};

/// An event to deliver an interrupt to the guest.
///
/// Unlike `devices::Interrupt`, this doesn't support interrupt status and signal resampling.
// TODO(b/187487351): To avoid sending unnecessary events, we might want to support interrupt
// status. For this purpose, we need a mechanism to share interrupt status between the vmm and the
// device process.
pub struct CallEvent(Event);

impl SignalableInterrupt for CallEvent {
    fn signal(&self, _vector: u16, _interrupt_status_mask: u32) {
        self.0.write(1).unwrap();
    }

    fn signal_config_changed(&self) {} // TODO(dgreid)

    fn get_resample_evt(&self) -> Option<&Event> {
        None
    }

    fn do_interrupt_resample(&self) {}
}

/// Keeps a mapping from the vmm's virtual addresses to guest addresses.
/// used to translate messages from the vmm to guest offsets.
#[derive(Default)]
struct MappingInfo {
    vmm_addr: u64,
    guest_phys: u64,
    size: u64,
}

fn vmm_va_to_gpa(maps: &[MappingInfo], vmm_va: u64) -> VhostResult<GuestAddress> {
    for map in maps {
        if vmm_va >= map.vmm_addr && vmm_va < map.vmm_addr + map.size {
            return Ok(GuestAddress(vmm_va - map.vmm_addr + map.guest_phys));
        }
    }
    Err(VhostError::InvalidMessage)
}

/// Trait for vhost-user backend.
pub trait VhostUserBackend
where
    Self: Sized,
    Self::Error: std::fmt::Display,
{
    const MAX_QUEUE_NUM: usize;
    const MAX_VRING_LEN: u16;

    /// Error type specific to this backend.
    type Error;

    /// The set of feature bits that this backend supports.
    fn features(&self) -> u64;

    /// Acknowledges that this set of features should be enabled.
    fn ack_features(&mut self, value: u64) -> std::result::Result<(), Self::Error>;

    /// Returns the set of enabled features.
    fn acked_features(&self) -> u64;

    /// The set of protocol feature bits that this backend supports.
    fn protocol_features(&self) -> VhostUserProtocolFeatures;

    /// Acknowledges that this set of protocol features should be enabled.
    fn ack_protocol_features(&mut self, _value: u64) -> std::result::Result<(), Self::Error>;

    /// Returns the set of enabled protocol features.
    fn acked_protocol_features(&self) -> u64;

    /// Reads this device configuration space at `offset`.
    fn read_config(&self, offset: u64, dst: &mut [u8]);

    /// Indicates that the backend should start processing requests for virtio queue number `idx`.
    /// This method must not block the current thread so device backends should either spawn an
    /// async task or another thread to handle messages from the Queue.
    fn start_queue(
        &mut self,
        idx: usize,
        queue: Queue,
        mem: GuestMemory,
        call_evt: Arc<Mutex<CallEvent>>,
        kick_evt: Event,
    ) -> std::result::Result<(), Self::Error>;

    /// Indicates that the backend should stop processing requests for virtio queue number `idx`.
    fn stop_queue(&mut self, idx: usize);

    /// Resets the vhost-user backend.
    fn reset(&mut self);
}

/// A virtio ring entry.
struct Vring {
    queue: Queue,
    call_evt: Option<Arc<Mutex<CallEvent>>>,
    enabled: bool,
}

impl Vring {
    fn new(max_size: u16) -> Self {
        Self {
            queue: Queue::new(max_size),
            call_evt: None,
            enabled: false,
        }
    }

    fn reset(&mut self) {
        self.queue.reset();
        self.call_evt = None;
        self.enabled = false;
    }
}

#[sorted]
#[derive(ThisError, Debug)]
pub enum HandlerError {
    /// Failed to accept an incoming connection.
    #[error("failed to accept an incoming connection: {0}")]
    AcceptConnection(VhostError),
    /// Failed to create an async source.
    #[error("failed to create an async source: {0}")]
    CreateAsyncSource(AsyncError),
    /// Failed to create a connection listener.
    #[error("failed to create a connection listener: {0}")]
    CreateConnectionListener(VhostError),
    /// Failed to create a UNIX domain socket listener.
    #[error("failed to create a UNIX domain socket listener: {0}")]
    CreateSocketListener(VhostError),
    /// Failed to handle a vhost-user request.
    #[error("failed to handle a vhost-user request: {0}")]
    HandleVhostUserRequest(VhostError),
    /// Failed to wait for the handler socket to become readable.
    #[error("failed to wait for the handler socket to become readable: {0}")]
    WaitForHandler(AsyncError),
}

type HandlerResult<T> = std::result::Result<T, HandlerError>;

/// Structure to have an event loop for interaction between a VMM and `VhostUserBackend`.
pub struct DeviceRequestHandler<B>
where
    B: 'static + VhostUserBackend,
{
    vrings: Vec<Vring>,
    owned: bool,
    vmm_maps: Option<Vec<MappingInfo>>,
    mem: Option<GuestMemory>,
    backend: B,
}

impl<B> DeviceRequestHandler<B>
where
    B: 'static + VhostUserBackend,
{
    /// Creates the handler instance for `backend`.
    pub fn new(backend: B) -> Self {
        let mut vrings = Vec::with_capacity(B::MAX_QUEUE_NUM);
        for _ in 0..B::MAX_QUEUE_NUM {
            vrings.push(Vring::new(B::MAX_VRING_LEN as u16));
        }

        DeviceRequestHandler {
            vrings,
            owned: false,
            vmm_maps: None,
            mem: None,
            backend,
        }
    }

    /// Creates a listening socket at `socket` and handles incoming messages from the VMM, which are
    /// dispatched to the device backend via the `VhostUserBackend` trait methods.
    pub async fn run<P: AsRef<Path>>(self, socket: P, ex: &Executor) -> HandlerResult<()> {
        let mut listener = Listener::new(socket, true)
            .map_err(HandlerError::CreateSocketListener)
            .and_then(|l| {
                SlaveListener::new(l, Arc::new(std::sync::Mutex::new(self)))
                    .map_err(HandlerError::CreateConnectionListener)
            })?;
        let mut req_handler = listener
            .accept()
            .map_err(HandlerError::AcceptConnection)?
            .expect("no incoming connection was detected");

        let h = SafeDescriptor::try_from(&req_handler as &dyn AsRawFd)
            .map(AsyncWrapper::new)
            .expect("failed to get safe descriptor for handler");
        let handler_source = ex.async_from(h).map_err(HandlerError::CreateAsyncSource)?;

        loop {
            handler_source
                .wait_readable()
                .await
                .map_err(HandlerError::WaitForHandler)?;
            req_handler
                .handle_request()
                .map_err(HandlerError::HandleVhostUserRequest)?;
        }
    }
}

impl<B: VhostUserBackend> VhostUserSlaveReqHandlerMut for DeviceRequestHandler<B> {
    fn set_owner(&mut self) -> VhostResult<()> {
        if self.owned {
            return Err(VhostError::InvalidOperation);
        }
        self.owned = true;
        Ok(())
    }

    fn reset_owner(&mut self) -> VhostResult<()> {
        self.owned = false;
        self.backend.reset();
        Ok(())
    }

    fn get_features(&mut self) -> VhostResult<u64> {
        let features = self.backend.features();
        Ok(features)
    }

    fn set_features(&mut self, features: u64) -> VhostResult<()> {
        if !self.owned {
            return Err(VhostError::InvalidOperation);
        }

        if (features & !(self.backend.features())) != 0 {
            return Err(VhostError::InvalidParam);
        }

        if let Err(e) = self.backend.ack_features(features) {
            error!("failed to acknowledge features 0x{:x}: {}", features, e);
            return Err(VhostError::InvalidOperation);
        }

        // If VHOST_USER_F_PROTOCOL_FEATURES has not been negotiated, the ring is initialized in an
        // enabled state.
        // If VHOST_USER_F_PROTOCOL_FEATURES has been negotiated, the ring is initialized in a
        // disabled state.
        // Client must not pass data to/from the backend until ring is enabled by
        // VHOST_USER_SET_VRING_ENABLE with parameter 1, or after it has been disabled by
        // VHOST_USER_SET_VRING_ENABLE with parameter 0.
        let acked_features = self.backend.acked_features();
        let vring_enabled = VhostUserVirtioFeatures::PROTOCOL_FEATURES.bits() & acked_features != 0;
        for v in &mut self.vrings {
            v.enabled = vring_enabled;
        }

        Ok(())
    }

    fn get_protocol_features(&mut self) -> VhostResult<VhostUserProtocolFeatures> {
        Ok(self.backend.protocol_features())
    }

    fn set_protocol_features(&mut self, features: u64) -> VhostResult<()> {
        if let Err(e) = self.backend.ack_protocol_features(features) {
            error!("failed to set protocol features 0x{:x}: {}", features, e);
            return Err(VhostError::InvalidOperation);
        }
        Ok(())
    }

    fn set_mem_table(
        &mut self,
        contexts: &[VhostUserMemoryRegion],
        files: Vec<File>,
    ) -> VhostResult<()> {
        if files.len() != contexts.len() {
            return Err(VhostError::InvalidParam);
        }

        let mut regions = Vec::with_capacity(files.len());
        for (region, file) in contexts.iter().zip(files.into_iter()) {
            let region = MemoryRegion::new(
                region.memory_size,
                GuestAddress(region.guest_phys_addr),
                region.mmap_offset,
                Arc::new(SharedMemory::from_safe_descriptor(SafeDescriptor::from(file)).unwrap()),
            )
            .map_err(|e| {
                error!("failed to create a memory region: {}", e);
                VhostError::InvalidOperation
            })?;
            regions.push(region);
        }
        let guest_mem = GuestMemory::from_regions(regions).map_err(|e| {
            error!("failed to create guest memory: {}", e);
            VhostError::InvalidOperation
        })?;

        let vmm_maps = contexts
            .iter()
            .map(|region| MappingInfo {
                vmm_addr: region.user_addr,
                guest_phys: region.guest_phys_addr,
                size: region.memory_size,
            })
            .collect();

        self.mem = Some(guest_mem);
        self.vmm_maps = Some(vmm_maps);
        Ok(())
    }

    fn get_queue_num(&mut self) -> VhostResult<u64> {
        Ok(self.vrings.len() as u64)
    }

    fn set_vring_num(&mut self, index: u32, num: u32) -> VhostResult<()> {
        if index as usize >= self.vrings.len() || num == 0 || num > B::MAX_VRING_LEN.into() {
            return Err(VhostError::InvalidParam);
        }
        self.vrings[index as usize].queue.size = num as u16;

        Ok(())
    }

    fn set_vring_addr(
        &mut self,
        index: u32,
        _flags: VhostUserVringAddrFlags,
        descriptor: u64,
        used: u64,
        available: u64,
        _log: u64,
    ) -> VhostResult<()> {
        if index as usize >= self.vrings.len() {
            return Err(VhostError::InvalidParam);
        }

        let vmm_maps = self.vmm_maps.as_ref().ok_or(VhostError::InvalidParam)?;
        let vring = &mut self.vrings[index as usize];
        vring.queue.desc_table = vmm_va_to_gpa(&vmm_maps, descriptor)?;
        vring.queue.avail_ring = vmm_va_to_gpa(&vmm_maps, available)?;
        vring.queue.used_ring = vmm_va_to_gpa(&vmm_maps, used)?;

        Ok(())
    }

    fn set_vring_base(&mut self, index: u32, base: u32) -> VhostResult<()> {
        if index as usize >= self.vrings.len() || base >= B::MAX_VRING_LEN.into() {
            return Err(VhostError::InvalidParam);
        }

        let vring = &mut self.vrings[index as usize];
        vring.queue.next_avail = Wrapping(base as u16);
        vring.queue.next_used = Wrapping(base as u16);

        Ok(())
    }

    fn get_vring_base(&mut self, index: u32) -> VhostResult<VhostUserVringState> {
        if index as usize >= self.vrings.len() {
            return Err(VhostError::InvalidParam);
        }

        // Quotation from vhost-user spec:
        // Client must start ring upon receiving a kick (that is, detecting
        // that file descriptor is readable) on the descriptor specified by
        // VHOST_USER_SET_VRING_KICK, and stop ring upon receiving
        // VHOST_USER_GET_VRING_BASE.
        self.backend.stop_queue(index as usize);

        let vring = &mut self.vrings[index as usize];
        vring.reset();

        Ok(VhostUserVringState::new(
            index,
            vring.queue.next_avail.0 as u32,
        ))
    }

    fn set_vring_kick(&mut self, index: u8, file: Option<File>) -> VhostResult<()> {
        if index as usize >= self.vrings.len() {
            return Err(VhostError::InvalidParam);
        }

        let vring = &mut self.vrings[index as usize];
        if vring.queue.ready {
            error!("kick fd cannot replaced after queue is started");
            return Err(VhostError::InvalidOperation);
        }

        if let Some(file) = file {
            // Remove O_NONBLOCK from kick_fd. Otherwise, uring_executor will fails when we read
            // values via `next_val()` later.
            if let Err(e) = clear_fd_flags(file.as_raw_fd(), libc::O_NONBLOCK) {
                error!("failed to remove O_NONBLOCK for kick fd: {}", e);
                return Err(VhostError::InvalidParam);
            }

            // Safe because we own the file.
            let kick_evt = unsafe { Event::from_raw_descriptor(file.into_raw_descriptor()) };

            let vring = &mut self.vrings[index as usize];
            vring.queue.ready = true;

            let queue = vring.queue.clone();
            let call_evt = vring
                .call_evt
                .as_ref()
                .ok_or(VhostError::InvalidOperation)?;
            let mem = self
                .mem
                .as_ref()
                .cloned()
                .ok_or(VhostError::InvalidOperation)?;

            if let Err(e) = self.backend.start_queue(
                index as usize,
                queue,
                mem,
                Arc::clone(&call_evt),
                kick_evt,
            ) {
                error!("Failed to start queue {}: {}", index, e);
                return Err(VhostError::SlaveInternalError);
            }
        }
        Ok(())
    }

    fn set_vring_call(&mut self, index: u8, file: Option<File>) -> VhostResult<()> {
        if index as usize >= self.vrings.len() {
            return Err(VhostError::InvalidParam);
        }

        if let Some(file) = file {
            // Safe because we own the file.
            let call_evt =
                CallEvent(unsafe { Event::from_raw_descriptor(file.into_raw_descriptor()) });
            match &self.vrings[index as usize].call_evt {
                None => {
                    self.vrings[index as usize].call_evt = Some(Arc::new(Mutex::new(call_evt)));
                }
                Some(cell) => {
                    let mut evt = cell.lock();
                    *evt = call_evt;
                }
            }
        }

        Ok(())
    }

    fn set_vring_err(&mut self, _index: u8, _fd: Option<File>) -> VhostResult<()> {
        // TODO
        Ok(())
    }

    fn set_vring_enable(&mut self, index: u32, enable: bool) -> VhostResult<()> {
        if index as usize >= self.vrings.len() {
            return Err(VhostError::InvalidParam);
        }

        // This request should be handled only when VHOST_USER_F_PROTOCOL_FEATURES
        // has been negotiated.
        if self.backend.acked_features() & VhostUserVirtioFeatures::PROTOCOL_FEATURES.bits() == 0 {
            return Err(VhostError::InvalidOperation);
        }

        // Slave must not pass data to/from the backend until ring is
        // enabled by VHOST_USER_SET_VRING_ENABLE with parameter 1,
        // or after it has been disabled by VHOST_USER_SET_VRING_ENABLE
        // with parameter 0.
        self.vrings[index as usize].enabled = enable;

        Ok(())
    }

    fn get_config(
        &mut self,
        offset: u32,
        size: u32,
        _flags: VhostUserConfigFlags,
    ) -> VhostResult<Vec<u8>> {
        if offset >= size {
            return Err(VhostError::InvalidParam);
        }

        let mut data = vec![0; size as usize];
        self.backend.read_config(u64::from(offset), &mut data);
        Ok(data)
    }

    fn set_config(
        &mut self,
        _offset: u32,
        _buf: &[u8],
        _flags: VhostUserConfigFlags,
    ) -> VhostResult<()> {
        // TODO
        Ok(())
    }

    fn set_slave_req_fd(&mut self, _vu_req: File) {
        // TODO
    }

    fn get_inflight_fd(
        &mut self,
        _inflight: &VhostUserInflight,
    ) -> VhostResult<(VhostUserInflight, File)> {
        unimplemented!("get_inflight_fd");
    }

    fn set_inflight_fd(&mut self, _inflight: &VhostUserInflight, _file: File) -> VhostResult<()> {
        unimplemented!("set_inflight_fd");
    }

    fn get_max_mem_slots(&mut self) -> VhostResult<u64> {
        //TODO
        Ok(0)
    }

    fn add_mem_region(
        &mut self,
        _region: &VhostUserSingleMemoryRegion,
        _fd: File,
    ) -> VhostResult<()> {
        //TODO
        Ok(())
    }

    fn remove_mem_region(&mut self, _region: &VhostUserSingleMemoryRegion) -> VhostResult<()> {
        //TODO
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    use std::sync::mpsc::channel;
    use std::sync::Barrier;

    use data_model::DataInit;
    use devices::virtio::vhost::user::VhostUserHandler;
    use tempfile::{Builder, TempDir};

    #[derive(ThisError, Debug)]
    enum FakeError {
        #[error("invalid features are given: 0x{features:x}")]
        InvalidFeatures { features: u64 },
        #[error("invalid protocol features are given: 0x{features:x}")]
        InvalidProtocolFeatures { features: u64 },
    }

    #[derive(Clone, Copy, Debug, PartialEq, Eq)]
    #[repr(C)]
    struct FakeConfig {
        x: u32,
        y: u64,
    }

    unsafe impl DataInit for FakeConfig {}

    const FAKE_CONFIG_DATA: FakeConfig = FakeConfig { x: 1, y: 2 };

    struct FakeBackend {
        avail_features: u64,
        acked_features: u64,
        acked_protocol_features: VhostUserProtocolFeatures,
    }

    impl FakeBackend {
        fn new() -> Self {
            Self {
                avail_features: VhostUserVirtioFeatures::PROTOCOL_FEATURES.bits(),
                acked_features: 0,
                acked_protocol_features: VhostUserProtocolFeatures::empty(),
            }
        }
    }

    impl VhostUserBackend for FakeBackend {
        const MAX_QUEUE_NUM: usize = 16;
        const MAX_VRING_LEN: u16 = 256;

        type Error = FakeError;

        fn features(&self) -> u64 {
            self.avail_features
        }

        fn ack_features(&mut self, value: u64) -> std::result::Result<(), Self::Error> {
            let unrequested_features = value & !self.avail_features;
            if unrequested_features != 0 {
                return Err(FakeError::InvalidFeatures {
                    features: unrequested_features,
                });
            }
            self.acked_features |= value;
            Ok(())
        }

        fn acked_features(&self) -> u64 {
            self.acked_features
        }

        fn protocol_features(&self) -> VhostUserProtocolFeatures {
            VhostUserProtocolFeatures::CONFIG
        }

        fn ack_protocol_features(&mut self, features: u64) -> std::result::Result<(), Self::Error> {
            let features = VhostUserProtocolFeatures::from_bits(features)
                .ok_or(FakeError::InvalidProtocolFeatures { features })?;
            let supported = self.protocol_features();
            self.acked_protocol_features = features & supported;
            Ok(())
        }

        fn acked_protocol_features(&self) -> u64 {
            self.acked_protocol_features.bits()
        }

        fn read_config(&self, offset: u64, dst: &mut [u8]) {
            dst.copy_from_slice(&FAKE_CONFIG_DATA.as_slice()[offset as usize..]);
        }

        fn reset(&mut self) {}

        fn start_queue(
            &mut self,
            _idx: usize,
            _queue: Queue,
            _mem: GuestMemory,
            _call_evt: Arc<Mutex<CallEvent>>,
            _kick_evt: Event,
        ) -> std::result::Result<(), Self::Error> {
            Ok(())
        }

        fn stop_queue(&mut self, _idx: usize) {}
    }

    fn temp_dir() -> TempDir {
        Builder::new().prefix("/tmp/vhost_test").tempdir().unwrap()
    }

    #[test]
    fn test_vhost_user_activate() {
        use vmm_vhost::vhost_user::{Listener, SlaveListener};

        const QUEUES_NUM: usize = 2;

        let dir = temp_dir();
        let mut path = dir.path().to_owned();
        path.push("sock");
        let listener = Listener::new(&path, true).unwrap();

        let vmm_bar = Arc::new(Barrier::new(2));
        let dev_bar = vmm_bar.clone();

        let (tx, rx) = channel();

        std::thread::spawn(move || {
            // VMM side
            rx.recv().unwrap(); // Ensure the device is ready.

            let allow_features = VhostUserVirtioFeatures::PROTOCOL_FEATURES.bits();
            let init_features = VhostUserVirtioFeatures::PROTOCOL_FEATURES.bits();
            let allow_protocol_features = VhostUserProtocolFeatures::CONFIG;
            let mut vmm_handler = VhostUserHandler::new_from_path(
                &path,
                QUEUES_NUM as u64,
                allow_features,
                init_features,
                allow_protocol_features,
            )
            .unwrap();

            println!("read_config");
            let mut buf = vec![0; std::mem::size_of::<FakeConfig>()];
            vmm_handler.read_config::<FakeConfig>(0, &mut buf).unwrap();
            // Check if the obtained config data is correct.
            let config = FakeConfig::from_slice(&buf).unwrap();
            assert_eq!(*config, FAKE_CONFIG_DATA);

            println!("set_mem_table");
            let mem = GuestMemory::new(&vec![(GuestAddress(0x0), 0x10000)]).unwrap();
            vmm_handler.set_mem_table(&mem).unwrap();

            for idx in 0..QUEUES_NUM {
                println!("activate_mem_table: queue_index={}", idx);
                let queue = Queue::new(0x10);
                let queue_evt = Event::new().unwrap();
                let irqfd = Event::new().unwrap();

                vmm_handler
                    .activate_vring(&mem, idx, &queue, &queue_evt, &irqfd)
                    .unwrap();
            }

            vmm_bar.wait();
        });

        // Device side
        let handler = Arc::new(std::sync::Mutex::new(DeviceRequestHandler::new(
            FakeBackend::new(),
        )));
        let mut listener = SlaveListener::new(listener, handler).unwrap();

        // Notify listener is ready.
        tx.send(()).unwrap();

        let mut listener = listener.accept().unwrap().unwrap();

        // VhostUserHandler::new()
        listener.handle_request().expect("set_owner");
        listener.handle_request().expect("get_features");
        listener.handle_request().expect("set_features");
        listener.handle_request().expect("get_protocol_features");
        listener.handle_request().expect("set_protocol_features");

        // VhostUserHandler::read_config()
        listener.handle_request().expect("get_config");

        // VhostUserHandler::set_mem_table()
        listener.handle_request().expect("set_mem_table");

        for _ in 0..QUEUES_NUM {
            // VhostUserHandler::activate_vring()
            listener.handle_request().expect("set_vring_num");
            listener.handle_request().expect("set_vring_addr");
            listener.handle_request().expect("set_vring_base");
            listener.handle_request().expect("set_vring_call");
            listener.handle_request().expect("set_vring_kick");
            listener.handle_request().expect("set_vring_enable");
        }

        dev_bar.wait();
    }
}
