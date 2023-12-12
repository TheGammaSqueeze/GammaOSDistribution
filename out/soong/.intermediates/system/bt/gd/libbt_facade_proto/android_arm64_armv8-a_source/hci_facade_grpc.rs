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

const METHOD_HCI_FACADE_SEND_COMMAND: ::grpcio::Method<super::common::Data, super::empty::Empty> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hci.HciFacade/SendCommand",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_FACADE_REQUEST_EVENT: ::grpcio::Method<super::hci_facade::EventRequest, super::empty::Empty> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hci.HciFacade/RequestEvent",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_FACADE_STREAM_EVENTS: ::grpcio::Method<super::empty::Empty, super::common::Data> = ::grpcio::Method {
    ty: ::grpcio::MethodType::ServerStreaming,
    name: "/bluetooth.hci.HciFacade/StreamEvents",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_FACADE_REQUEST_LE_SUBEVENT: ::grpcio::Method<super::hci_facade::EventRequest, super::empty::Empty> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hci.HciFacade/RequestLeSubevent",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_FACADE_STREAM_LE_SUBEVENTS: ::grpcio::Method<super::empty::Empty, super::common::Data> = ::grpcio::Method {
    ty: ::grpcio::MethodType::ServerStreaming,
    name: "/bluetooth.hci.HciFacade/StreamLeSubevents",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_FACADE_SEND_ACL: ::grpcio::Method<super::common::Data, super::empty::Empty> = ::grpcio::Method {
    ty: ::grpcio::MethodType::Unary,
    name: "/bluetooth.hci.HciFacade/SendAcl",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

const METHOD_HCI_FACADE_STREAM_ACL: ::grpcio::Method<super::empty::Empty, super::common::Data> = ::grpcio::Method {
    ty: ::grpcio::MethodType::ServerStreaming,
    name: "/bluetooth.hci.HciFacade/StreamAcl",
    req_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
    resp_mar: ::grpcio::Marshaller { ser: ::grpcio::pb_ser, de: ::grpcio::pb_de },
};

#[derive(Clone)]
pub struct HciFacadeClient {
    client: ::grpcio::Client,
}

impl HciFacadeClient {
    pub fn new(channel: ::grpcio::Channel) -> Self {
        HciFacadeClient {
            client: ::grpcio::Client::new(channel),
        }
    }

    pub fn send_command_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::empty::Empty> {
        self.client.unary_call(&METHOD_HCI_FACADE_SEND_COMMAND, req, opt)
    }

    pub fn send_command(&self, req: &super::common::Data) -> ::grpcio::Result<super::empty::Empty> {
        self.send_command_opt(req, ::grpcio::CallOption::default())
    }

    pub fn send_command_async_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.client.unary_call_async(&METHOD_HCI_FACADE_SEND_COMMAND, req, opt)
    }

    pub fn send_command_async(&self, req: &super::common::Data) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.send_command_async_opt(req, ::grpcio::CallOption::default())
    }

    pub fn request_event_opt(&self, req: &super::hci_facade::EventRequest, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::empty::Empty> {
        self.client.unary_call(&METHOD_HCI_FACADE_REQUEST_EVENT, req, opt)
    }

    pub fn request_event(&self, req: &super::hci_facade::EventRequest) -> ::grpcio::Result<super::empty::Empty> {
        self.request_event_opt(req, ::grpcio::CallOption::default())
    }

    pub fn request_event_async_opt(&self, req: &super::hci_facade::EventRequest, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.client.unary_call_async(&METHOD_HCI_FACADE_REQUEST_EVENT, req, opt)
    }

    pub fn request_event_async(&self, req: &super::hci_facade::EventRequest) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.request_event_async_opt(req, ::grpcio::CallOption::default())
    }

    pub fn stream_events_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.client.server_streaming(&METHOD_HCI_FACADE_STREAM_EVENTS, req, opt)
    }

    pub fn stream_events(&self, req: &super::empty::Empty) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.stream_events_opt(req, ::grpcio::CallOption::default())
    }

    pub fn request_le_subevent_opt(&self, req: &super::hci_facade::EventRequest, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::empty::Empty> {
        self.client.unary_call(&METHOD_HCI_FACADE_REQUEST_LE_SUBEVENT, req, opt)
    }

    pub fn request_le_subevent(&self, req: &super::hci_facade::EventRequest) -> ::grpcio::Result<super::empty::Empty> {
        self.request_le_subevent_opt(req, ::grpcio::CallOption::default())
    }

    pub fn request_le_subevent_async_opt(&self, req: &super::hci_facade::EventRequest, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.client.unary_call_async(&METHOD_HCI_FACADE_REQUEST_LE_SUBEVENT, req, opt)
    }

    pub fn request_le_subevent_async(&self, req: &super::hci_facade::EventRequest) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.request_le_subevent_async_opt(req, ::grpcio::CallOption::default())
    }

    pub fn stream_le_subevents_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.client.server_streaming(&METHOD_HCI_FACADE_STREAM_LE_SUBEVENTS, req, opt)
    }

    pub fn stream_le_subevents(&self, req: &super::empty::Empty) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.stream_le_subevents_opt(req, ::grpcio::CallOption::default())
    }

    pub fn send_acl_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<super::empty::Empty> {
        self.client.unary_call(&METHOD_HCI_FACADE_SEND_ACL, req, opt)
    }

    pub fn send_acl(&self, req: &super::common::Data) -> ::grpcio::Result<super::empty::Empty> {
        self.send_acl_opt(req, ::grpcio::CallOption::default())
    }

    pub fn send_acl_async_opt(&self, req: &super::common::Data, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.client.unary_call_async(&METHOD_HCI_FACADE_SEND_ACL, req, opt)
    }

    pub fn send_acl_async(&self, req: &super::common::Data) -> ::grpcio::Result<::grpcio::ClientUnaryReceiver<super::empty::Empty>> {
        self.send_acl_async_opt(req, ::grpcio::CallOption::default())
    }

    pub fn stream_acl_opt(&self, req: &super::empty::Empty, opt: ::grpcio::CallOption) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.client.server_streaming(&METHOD_HCI_FACADE_STREAM_ACL, req, opt)
    }

    pub fn stream_acl(&self, req: &super::empty::Empty) -> ::grpcio::Result<::grpcio::ClientSStreamReceiver<super::common::Data>> {
        self.stream_acl_opt(req, ::grpcio::CallOption::default())
    }
    pub fn spawn<F>(&self, f: F) where F: ::futures::Future<Output = ()> + Send + 'static {
        self.client.spawn(f)
    }
}

pub trait HciFacade {
    fn send_command(&mut self, ctx: ::grpcio::RpcContext, req: super::common::Data, sink: ::grpcio::UnarySink<super::empty::Empty>);
    fn request_event(&mut self, ctx: ::grpcio::RpcContext, req: super::hci_facade::EventRequest, sink: ::grpcio::UnarySink<super::empty::Empty>);
    fn stream_events(&mut self, ctx: ::grpcio::RpcContext, req: super::empty::Empty, sink: ::grpcio::ServerStreamingSink<super::common::Data>);
    fn request_le_subevent(&mut self, ctx: ::grpcio::RpcContext, req: super::hci_facade::EventRequest, sink: ::grpcio::UnarySink<super::empty::Empty>);
    fn stream_le_subevents(&mut self, ctx: ::grpcio::RpcContext, req: super::empty::Empty, sink: ::grpcio::ServerStreamingSink<super::common::Data>);
    fn send_acl(&mut self, ctx: ::grpcio::RpcContext, req: super::common::Data, sink: ::grpcio::UnarySink<super::empty::Empty>);
    fn stream_acl(&mut self, ctx: ::grpcio::RpcContext, req: super::empty::Empty, sink: ::grpcio::ServerStreamingSink<super::common::Data>);
}

pub fn create_hci_facade<S: HciFacade + Send + Clone + 'static>(s: S) -> ::grpcio::Service {
    let mut builder = ::grpcio::ServiceBuilder::new();
    let mut instance = s.clone();
    builder = builder.add_unary_handler(&METHOD_HCI_FACADE_SEND_COMMAND, move |ctx, req, resp| {
        instance.send_command(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_unary_handler(&METHOD_HCI_FACADE_REQUEST_EVENT, move |ctx, req, resp| {
        instance.request_event(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_server_streaming_handler(&METHOD_HCI_FACADE_STREAM_EVENTS, move |ctx, req, resp| {
        instance.stream_events(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_unary_handler(&METHOD_HCI_FACADE_REQUEST_LE_SUBEVENT, move |ctx, req, resp| {
        instance.request_le_subevent(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_server_streaming_handler(&METHOD_HCI_FACADE_STREAM_LE_SUBEVENTS, move |ctx, req, resp| {
        instance.stream_le_subevents(ctx, req, resp)
    });
    let mut instance = s.clone();
    builder = builder.add_unary_handler(&METHOD_HCI_FACADE_SEND_ACL, move |ctx, req, resp| {
        instance.send_acl(ctx, req, resp)
    });
    let mut instance = s;
    builder = builder.add_server_streaming_handler(&METHOD_HCI_FACADE_STREAM_ACL, move |ctx, req, resp| {
        instance.stream_acl(ctx, req, resp)
    });
    builder.build()
}
