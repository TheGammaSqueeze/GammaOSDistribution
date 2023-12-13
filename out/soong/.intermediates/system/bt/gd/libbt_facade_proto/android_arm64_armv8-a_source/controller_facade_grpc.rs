// This file is generated. Do not edit
// @generated

// https://github.com/Manishearth/rust-clippy/issues/702
#![allow(unknown_lints)]
#![allow(clippy::all)]

#![allow(box_pointers)]
#![allow(dead_code)]
#![allow(missing_docs)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]
#![allow(trivial_casts)]
#![allow(unsafe_code)]
#![allow(unused_imports)]
#![allow(unused_results)]

const METHOD_CONTROLLER_FACADE_GET_MAC_ADDRESS: ::grpcio::Method<super::empty::Empty, super::controller_facade::AddressMsg> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hci.ControllerFacade/GetMacAddress",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_CONTROLLER_FACADE_WRITE_LOCAL_NAME: ::grpcio::Method<super::controller_facade::NameMsg, super::empty::Empty> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hci.ControllerFacade/WriteLocalName",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_CONTROLLER_FACADE_GET_LOCAL_NAME: ::grpcio::Method<super::empty::Empty, super::controller_facade::NameMsg> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hci.ControllerFacade/GetLocalName",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

#[derive(Clone)]
pub struct ControllerFacadeClient {
    client: ::grpcio::Client,
}

impl ControllerFacadeClient {
    pub fn new(channel: ::grpcio::Channel) -> Self {
        ControllerFacadeClient {
            client: ::grpcio::Client::new(channel),
        }
    }

    pub fn get_mac_address_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::controller_facade::AddressMsg> {
        self.client.unary_call(&METHOD_CONTROLLER_FACADE_GET_MAC_ADDRESS, req, opt)
    }

    pub fn get_mac_address(&self, req: &super::empty::Empty) -> ::grpcio::Result<super::controller_facade::AddressMsg> {
        self.get_mac_address_opt(req, ::grpcio::CallOption::default())
    }

    pub fn get_mac_address_async_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::controller_facade::AddressMsg>> {
        self.client.unary_call_async(&METHOD_CONTROLLER_FACADE_GET_MAC_ADDRESS, req, opt)
    }

    pub fn get_mac_address_async(&self, req: &super::empty::Empty) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::controller_facade::AddressMsg>> {
        self.get_mac_address_async_opt(req, ::grpcio::CallOption::default())
    }

    pub fn write_local_name_opt(&self, req: &super::controller_facade::NameMsg, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::empty::Empty> {
        self.client.unary_call(&METHOD_CONTROLLER_FACADE_WRITE_LOCAL_NAME, req, opt)
    }

    pub fn write_local_name(&self, req: &super::controller_facade::NameMsg) -> ::grpcio::Result<super::empty::Empty> {
        self.write_local_name_opt(req, ::grpcio::CallOption::default())
    }

    pub fn write_local_name_async_opt(&self, req: &super::controller_facade::NameMsg, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.client.unary_call_async(&METHOD_CONTROLLER_FACADE_WRITE_LOCAL_NAME, req, opt)
    }

    pub fn write_local_name_async(&self, req: &super::controller_facade::NameMsg) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.write_local_name_async_opt(req, ::grpcio::CallOption::default())
    }

    pub fn get_local_name_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::controller_facade::NameMsg> {
        self.client.unary_call(&METHOD_CONTROLLER_FACADE_GET_LOCAL_NAME, req, opt)
    }

    pub fn get_local_name(&self, req: &super::empty::Empty) -> ::grpcio::Result<super::controller_facade::NameMsg> {
        self.get_local_name_opt(req, ::grpcio::CallOption::default())
    }

    pub fn get_local_name_async_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::controller_facade::NameMsg>> {
        self.client.unary_call_async(&METHOD_CONTROLLER_FACADE_GET_LOCAL_NAME, req, opt)
    }

    pub fn get_local_name_async(&self, req: &super::empty::Empty) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::controller_facade::NameMsg>> {
        self.get_local_name_async_opt(req, ::grpcio::CallOption::default())
    }
    pub fn spawn<F>(&self, f: F) where F: ::futures::Future<Output = ()> + Send + 'static {
        self.client.spawn(f)
    }
}

pub trait ControllerFacade {
    fn get_mac_address(&mut self, ctx: ::grpcio::RpcContext, req: super::empty::Empty, sink: ::grpcio::UnarySink<super::controller_facade::AddressMsg>);
    fn write_local_name(&mut self, ctx: ::grpcio::RpcContext, req: super::controller_facade::NameMsg, sink: ::grpcio::UnarySink<super::empty::Empty>);
    fn get_local_name(&mut self, ctx: ::grpcio::RpcContext, req: super::empty::Empty, sink: ::grpcio::UnarySink<super::controller_facade::NameMsg>);
}

pub fn create_controller_facade<S: ControllerFacade + Send + Clone + 'static>(s: S) -> ::grpcio::Service {
    let mut builder = ::grpcio::ServiceBuilder::new();
    let mut instance = s.clone();
    builder = builder.add_unary_handler(&METHOD_CONTROLLER_FACADE_GET_MAC_ADDRESS, move |ctx, req, resp| {
        instance.get_mac_address(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_unary_handler(&METHOD_CONTROLLER_FACADE_WRITE_LOCAL_NAME, move |ctx, req, resp| {
        instance.write_local_name(ctx, req, resp)
    });
    let mut instance = s;
    builder = builder.add_unary_handler(&METHOD_CONTROLLER_FACADE_GET_LOCAL_NAME, move |ctx, req, resp| {
        instance.get_local_name(ctx, req, resp)
    });
    builder.build()
}
