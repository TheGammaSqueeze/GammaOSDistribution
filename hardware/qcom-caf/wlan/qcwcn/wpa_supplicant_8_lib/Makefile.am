# Makefile.am - Automake script for wpa_supplicant_8_lib
ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS = -Wall

if DEBUG
AM_CFLAGS += -g
else
AM_CFLAGS += -O2
endif

AM_CFLAGS += -Wno-unused-parameter -Wno-int-to-pointer-cast \
             -Wno-maybe-uninitialized -Wno-parentheses \
             -DCONFIG_P2P -lcutils

h_sources = driver_cmd_nl80211_extn.h
library_includedir = $(pkgincludedir)
library_include_HEADERS = $(h_sources)

libwpa_supplicant_8_lib_la_SOURCES = driver_cmd_nl80211.c
libwpa_supplicant_8_lib_la_SOURCES += driver_cmd_nl80211_extn.c
libwpa_supplicant_8_lib_la_CFLAGS = ${AM_CFLAGS} ${LIBNL_CFLAGS}
libwpa_supplicant_8_lib_la_LIBADD = ${LIBNL_LIBS}
lib_LTLIBRARIES = libwpa_supplicant_8_lib.la

pkgconfigdir = $(libdir)/pkgconfig
