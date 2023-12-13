// @Soong generated Source
pub mod common;
pub mod controller_facade;
pub mod controller_facade_grpc;
pub mod hci_facade;
pub mod hci_facade_grpc;
pub mod hal_facade;
pub mod hal_facade_grpc;
pub mod rootservice;
pub mod rootservice_grpc;
pub mod empty {
    pub use protobuf::well_known_types::Empty;
}
