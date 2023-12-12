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

const METHOD_HCI_HAL_FACADE_SEND_COMMAND: ::grpcio::Method<super::common::Data, super::empty::Empty> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hal.HciHalFacade/SendCommand",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_HAL_FACADE_STREAM_EVENTS: ::grpcio::Method<super::empty::Empty, super::common::Data> = ::grpcio::Method {
    ty: ::grpcio::MethodType::ServerStreaming,
    name: "/bluetooth.hal.HciHalFacade/StreamEvents",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_HAL_FACADE_SEND_ACL: ::grpcio::Method<super::common::Data, super::empty::Empty> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hal.HciHalFacade/SendAcl",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_HAL_FACADE_STREAM_ACL: ::grpcio::Method<super::empty::Empty, super::common::Data> = ::grpcio::Method {
    ty: ::grpcio::MethodType::ServerStreaming,
    name: "/bluetooth.hal.HciHalFacade/StreamAcl",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_HAL_FACADE_SEND_SCO: ::grpcio::Method<super::common::Data, super::empty::Empty> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hal.HciHalFacade/SendSco",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_HAL_FACADE_STREAM_SCO: ::grpcio::Method<super::empty::Empty, super::common::Data> = ::grpcio::Method {
    ty: ::grpcio::MethodType::ServerStreaming,
    name: "/bluetooth.hal.HciHalFacade/StreamSco",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_HAL_FACADE_SEND_ISO: ::grpcio::Method<super::common::Data, super::empty::Empty> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hal.HciHalFacade/SendIso",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_HAL_FACADE_STREAM_ISO: ::grpcio::Method<super::empty::Empty, super::common::Data> = ::grpcio::Method {
    ty: ::grpcio::MethodType::ServerStreaming,
    name: "/bluetooth.hal.HciHalFacade/StreamIso",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

#[derive(Clone)]
pub struct HciHalFacadeClient {
    client: ::grpcio::Client,
}

impl HciHalFacadeClient {
    pub fn new(channel: ::grpcio::Channel) -> Self {
        HciHalFacadeClient {
            client: ::grpcio::Client::new(channel),
        }
    }

    pub fn send_command_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::empty::Empty> {
        self.client.unary_call(&METHOD_HCI_HAL_FACADE_SEND_COMMAND, req, opt)
    }

    pub fn send_command(&self, req: &super::common::Data) -> ::grpcio::Result<super::empty::Empty> {
        self.send_command_opt(req, ::grpcio::CallOption::default())
    }

    pub fn send_command_async_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.client.unary_call_async(&METHOD_HCI_HAL_FACADE_SEND_COMMAND, req, opt)
    }

    pub fn send_command_async(&self, req: &super::common::Data) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.send_command_async_opt(req, ::grpcio::CallOption::default())
    }

    pub fn stream_events_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.client.server_streaming(&METHOD_HCI_HAL_FACADE_STREAM_EVENTS, req, opt)
    }

    pub fn stream_events(&self, req: &super::empty::Empty) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.stream_events_opt(req, ::grpcio::CallOption::default())
    }

    pub fn send_acl_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::empty::Empty> {
        self.client.unary_call(&METHOD_HCI_HAL_FACADE_SEND_ACL, req, opt)
    }

    pub fn send_acl(&self, req: &super::common::Data) -> ::grpcio::Result<super::empty::Empty> {
        self.send_acl_opt(req, ::grpcio::CallOption::default())
    }

    pub fn send_acl_async_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.client.unary_call_async(&METHOD_HCI_HAL_FACADE_SEND_ACL, req, opt)
    }

    pub fn send_acl_async(&self, req: &super::common::Data) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.send_acl_async_opt(req, ::grpcio::CallOption::default())
    }

    pub fn stream_acl_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.client.server_streaming(&METHOD_HCI_HAL_FACADE_STREAM_ACL, req, opt)
    }

    pub fn stream_acl(&self, req: &super::empty::Empty) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.stream_acl_opt(req, ::grpcio::CallOption::default())
    }

    pub fn send_sco_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::empty::Empty> {
        self.client.unary_call(&METHOD_HCI_HAL_FACADE_SEND_SCO, req, opt)
    }

    pub fn send_sco(&self, req: &super::common::Data) -> ::grpcio::Result<super::empty::Empty> {
        self.send_sco_opt(req, ::grpcio::CallOption::default())
    }

    pub fn send_sco_async_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.client.unary_call_async(&METHOD_HCI_HAL_FACADE_SEND_SCO, req, opt)
    }

    pub fn send_sco_async(&self, req: &super::common::Data) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.send_sco_async_opt(req, ::grpcio::CallOption::default())
    }

    pub fn stream_sco_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.client.server_streaming(&METHOD_HCI_HAL_FACADE_STREAM_SCO, req, opt)
    }

    pub fn stream_sco(&self, req: &super::empty::Empty) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.stream_sco_opt(req, ::grpcio::CallOption::default())
    }

    pub fn send_iso_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::empty::Empty> {
        self.client.unary_call(&METHOD_HCI_HAL_FACADE_SEND_ISO, req, opt)
    }

    pub fn send_iso(&self, req: &super::common::Data) -> ::grpcio::Result<super::empty::Empty> {
        self.send_iso_opt(req, ::grpcio::CallOption::default())
    }

    pub fn send_iso_async_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.client.unary_call_async(&METHOD_HCI_HAL_FACADE_SEND_ISO, req, opt)
    }

    pub fn send_iso_async(&self, req: &super::common::Data) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.send_iso_async_opt(req, ::grpcio::CallOption::default())
    }

    pub fn stream_iso_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.client.server_streaming(&METHOD_HCI_HAL_FACADE_STREAM_ISO, req, opt)
    }

    pub fn stream_iso(&self, req: &super::empty::Empty) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.stream_iso_opt(req, ::grpcio::CallOption::default())
    }
    pub fn spawn<F>(&self, f: F) where F: ::futures::Future<Output = ()> + Send + 'static {
        self.client.spawn(f)
    }
}

pub trait HciHalFacade {
    fn send_command(&mut self, ctx: ::grpcio::RpcContext, req: super::common::Data, sink: ::grpcio::UnarySink<super::empty::Empty>);
    fn stream_events(&mut self, ctx: ::grpcio::RpcContext, req: super::empty::Empty, sink: ::grpcio::ServerStreamingSink<super::common::Data>);
    fn send_acl(&mut self, ctx: ::grpcio::RpcContext, req: super::common::Data, sink: ::grpcio::UnarySink<super::empty::Empty>);
    fn stream_acl(&mut self, ctx: ::grpcio::RpcContext, req: super::empty::Empty, sink: ::grpcio::ServerStreamingSink<super::common::Data>);
    fn send_sco(&mut self, ctx: ::grpcio::RpcContext, req: super::common::Data, sink: ::grpcio::UnarySink<super::empty::Empty>);
    fn stream_sco(&mut self, ctx: ::grpcio::RpcContext, req: super::empty::Empty, sink: ::grpcio::ServerStreamingSink<super::common::Data>);
    fn send_iso(&mut self, ctx: ::grpcio::RpcContext, req: super::common::Data, sink: ::grpcio::UnarySink<super::empty::Empty>);
    fn stream_iso(&mut self, ctx: ::grpcio::RpcContext, req: super::empty::Empty, sink: ::grpcio::ServerStreamingSink<super::common::Data>);
}

pub fn create_hci_hal_facade<S: HciHalFacade + Send + Clone + 'static>(s: S) -> ::grpcio::Service {
    let mut builder = ::grpcio::ServiceBuilder::new();
    let mut instance = s.clone();
    builder = builder.add_unary_handler(&METHOD_HCI_HAL_FACADE_SEND_COMMAND, move |ctx, req, resp| {
        instance.send_command(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_server_streaming_handler(&METHOD_HCI_HAL_FACADE_STREAM_EVENTS, move |ctx, req, resp| {
        instance.stream_events(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_unary_handler(&METHOD_HCI_HAL_FACADE_SEND_ACL, move |ctx, req, resp| {
        instance.send_acl(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_server_streaming_handler(&METHOD_HCI_HAL_FACADE_STREAM_ACL, move |ctx, req, resp| {
        instance.stream_acl(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_unary_handler(&METHOD_HCI_HAL_FACADE_SEND_SCO, move |ctx, req, resp| {
        instance.send_sco(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_server_streaming_handler(&METHOD_HCI_HAL_FACADE_STREAM_SCO, move |ctx, req, resp| {
        instance.stream_sco(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_unary_handler(&METHOD_HCI_HAL_FACADE_SEND_ISO, move |ctx, req, resp| {
        instance.send_iso(ctx, req, resp)
    });
    let mut instance = s;
    builder = builder.add_server_streaming_handler(&METHOD_HCI_HAL_FACADE_STREAM_ISO, move |ctx, req, resp| {
        instance.stream_iso(ctx, req, resp)
    });
    builder.build()
}
