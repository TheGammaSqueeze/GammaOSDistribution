#pragma once

#include <X11/Xlib.h>
#include <GL/glx.h>

#include "base/export.h"

// GLX
#define LIST_GLX_FUNCS(f) \
    f(glXQueryVersion) \
    f(glXGetFBConfigs) \
    f(glXGetFBConfigAttrib) \
    f(glXCreatePbuffer) \
    f(glXDestroyPbuffer) \
    f(glXCreateNewContext) \
    f(glXDestroyContext) \
    f(glXMakeContextCurrent) \
    f(glXSwapBuffers) \

#define LIST_GLX_FUNCTYPES(f) \
f( Bool, glXQueryVersion, ( Display *dpy, int *maj, int *min )) \
f( GLXFBConfig*, glXGetFBConfigs, ( Display *dpy, int screen, int *nelements )) \
f( int, glXGetFBConfigAttrib, ( Display *dpy, GLXFBConfig config, int attribute, int *value )) \
f( GLXPbuffer, glXCreatePbuffer, ( Display *dpy, GLXFBConfig config, const int *attribList )) \
f( void, glXDestroyPbuffer, ( Display *dpy, GLXPbuffer pbuf )) \
f( GLXContext, glXCreateNewContext, ( Display *dpy, GLXFBConfig config, int renderType, GLXContext shareList, Bool direct )) \
f( void, glXDestroyContext, ( Display *dpy, GLXContext ctx )) \
f( Bool, glXMakeContextCurrent, ( Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx )) \
f( void, glXSwapBuffers, (Display *dpy, GLXDrawable drawable )) \

// X11
#define LIST_XLIB_FUNCS(f) \
    f(XOpenDisplay) \
    f(XCreateWindow) \
    f(XMapWindow) \
    f(XSetWindowBackground) \
    f(XIfEvent) \
    f(XDestroyWindow) \
    f(XGetWindowAttributes) \
    f(XSetWindowBackgroundPixmap) \
    f(XMoveResizeWindow) \
    f(XCloseDisplay) \
    f(XGetGeometry) \
    f(XFree) \
    f(XSync) \
    f(XSetErrorHandler) \

#define LIST_XLIB_FUNCTYPES(f) \
f( Display*, XOpenDisplay, (_Xconst char*)) \
f( Window, XCreateWindow, ( \
    Display*		/* display */, \
    Window		/* parent */, \
    int			/* x */, \
    int			/* y */, \
    unsigned int	/* width */, \
    unsigned int	/* height */, \
    unsigned int	/* border_width */, \
    int			/* depth */, \
    unsigned int	/* class */, \
    Visual*		/* visual */, \
    unsigned long	/* valuemask */, \
    XSetWindowAttributes*	/* attributes */)) \
f( int, XMapWindow, ( \
    Display*		/* display */, \
    Window		/* w */ \
    )) \
f( int, XSetWindowBackground, ( \
    Display*		/* display */, \
    Window		/* w */, \
    unsigned long	/* background_pixel */ \
    )) \
f( int, XIfEvent, ( \
    Display*		/* display */, \
    XEvent*		/* event_return */, \
    Bool (*) ( \
	       Display*			/* display */, \
               XEvent*			/* event */, \
               XPointer			/* arg */ \
             )		/* predicate */, \
    XPointer		/* arg */ \
 )) \
f( int, XDestroyWindow, ( \
    Display*		/* display */, \
    Window		/* w */ \
    )) \
f( Status, XGetWindowAttributes, ( \
    Display*		/* display */, \
    Window		/* w */, \
    XWindowAttributes*	/* window_attributes_return */ \
    )) \
f( int, XSetWindowBackgroundPixmap, ( \
    Display*		/* display */, \
    Window		/* w */, \
    Pixmap		/* background_pixmap */ \
    )) \
f( int, XMoveResizeWindow, ( \
    Display*		/* display */, \
    Window		/* w */, \
    int			/* x */, \
    int			/* y */, \
    unsigned int	/* width */, \
    unsigned int	/* height */ \
    )) \
f( int, XCloseDisplay, ( \
    Display*		/* display */ \
    )) \
f( Status, XGetGeometry, ( \
    Display*		/* display */, \
    Drawable		/* d */, \
    Window*		/* root_return */, \
    int*		/* x_return */, \
    int*		/* y_return */, \
    unsigned int*	/* width_return */, \
    unsigned int*	/* height_return */, \
    unsigned int*	/* border_width_return */, \
    unsigned int*	/* depth_return */ \
    )) \
f( int, XFree, (void*)) \
f( int, XSync, (Display*, Bool)) \
f( XErrorHandler, XSetErrorHandler, (XErrorHandler)) \

#define DECLARE_FUNCTION_TYPEDEF(rettype, name, args) \
    typedef rettype (*name##_t)args;

#define DECLARE_API_STRUCT_MEMBER(funcname) \
    funcname##_t funcname;

LIST_XLIB_FUNCTYPES(DECLARE_FUNCTION_TYPEDEF)

LIST_GLX_FUNCTYPES(DECLARE_FUNCTION_TYPEDEF)

struct X11Api {
LIST_XLIB_FUNCS(DECLARE_API_STRUCT_MEMBER)
};

struct GlxApi {
LIST_GLX_FUNCS(DECLARE_API_STRUCT_MEMBER)
};

AEMU_EXPORT struct X11Api* getX11Api();
AEMU_EXPORT struct GlxApi* getGlxApi();
