dnl
dnl Common configuration stuff for CUPS.
dnl
dnl Copyright © 2007-2019 by Apple Inc.
dnl Copyright © 1997-2007 by Easy Software Products, all rights reserved.
dnl
dnl Licensed under Apache License v2.0.  See the file "LICENSE" for more
dnl information.
dnl

dnl Set the name of the config header file...
AC_CONFIG_HEADER(config.h)

dnl Version number information...
CUPS_VERSION="AC_PACKAGE_VERSION"
CUPS_REVISION=""
CUPS_BUILD="cups-$CUPS_VERSION"

AC_ARG_WITH(cups_build, [  --with-cups-build       set "cups-config --build" string ],
	CUPS_BUILD="$withval")

AC_SUBST(CUPS_VERSION)
AC_SUBST(CUPS_REVISION)
AC_SUBST(CUPS_BUILD)
AC_DEFINE_UNQUOTED(CUPS_SVERSION, "AC_PACKAGE_NAME v$CUPS_VERSION$CUPS_REVISION")
AC_DEFINE_UNQUOTED(CUPS_MINIMAL, "AC_PACKAGE_NAME/$CUPS_VERSION$CUPS_REVISION")

dnl Default compiler flags...
CFLAGS="${CFLAGS:=}"
CPPFLAGS="${CPPFLAGS:=}"
CXXFLAGS="${CXXFLAGS:=}"
LDFLAGS="${LDFLAGS:=}"

dnl Checks for programs...
AC_PROG_AWK
AC_PROG_CC(clang cc gcc)
AC_PROG_CPP
AC_PROG_CXX(clang++ c++ g++)
AC_PROG_RANLIB
AC_PATH_PROG(AR,ar)
AC_PATH_PROG(CHMOD,chmod)
AC_PATH_PROG(GZIPPROG,gzip)
AC_MSG_CHECKING(for install-sh script)
INSTALL="`pwd`/install-sh"
AC_SUBST(INSTALL)
AC_MSG_RESULT(using $INSTALL)
AC_PATH_PROG(LD,ld)
AC_PATH_PROG(LN,ln)
AC_PATH_PROG(MKDIR,mkdir)
AC_PATH_PROG(MV,mv)
AC_PATH_PROG(RM,rm)
AC_PATH_PROG(RMDIR,rmdir)
AC_PATH_PROG(SED,sed)
AC_PATH_PROG(XDGOPEN,xdg-open)

if test "x$XDGOPEN" = x; then
	CUPS_HTMLVIEW="htmlview"
else
	CUPS_HTMLVIEW="$XDGOPEN"
fi
AC_SUBST(CUPS_HTMLVIEW)

if test "x$AR" = x; then
	AC_MSG_ERROR([Unable to find required library archive command.])
fi
if test "x$CC" = x; then
	AC_MSG_ERROR([Unable to find required C compiler command.])
fi

dnl Static library option...
INSTALLSTATIC=""
AC_ARG_ENABLE(static, [  --enable-static         install static libraries])

if test x$enable_static = xyes; then
	echo Installing static libraries...
	INSTALLSTATIC="installstatic"
fi

AC_SUBST(INSTALLSTATIC)

dnl Check for pkg-config, which is used for some other tests later on...
AC_PATH_TOOL(PKGCONFIG, pkg-config)

dnl Check for libraries...
AC_SEARCH_LIBS(abs, m, AC_DEFINE(HAVE_ABS))
AC_SEARCH_LIBS(crypt, crypt)
AC_SEARCH_LIBS(fmod, m)
AC_SEARCH_LIBS(getspent, sec gen)

LIBMALLOC=""
AC_ARG_ENABLE(mallinfo, [  --enable-mallinfo       build with malloc debug logging])

if test x$enable_mallinfo = xyes; then
	SAVELIBS="$LIBS"
	LIBS=""
	AC_SEARCH_LIBS(mallinfo, malloc, AC_DEFINE(HAVE_MALLINFO))
	LIBMALLOC="$LIBS"
	LIBS="$SAVELIBS"
fi

AC_SUBST(LIBMALLOC)

dnl Check for libpaper support...
AC_ARG_ENABLE(libpaper, [  --enable-libpaper       build with libpaper support])

if test x$enable_libpaper = xyes; then
	AC_CHECK_LIB(paper,systempapername,
		AC_DEFINE(HAVE_LIBPAPER)
		LIBPAPER="-lpaper",
		LIBPAPER="")
else
	LIBPAPER=""
fi
AC_SUBST(LIBPAPER)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADER(stdlib.h,AC_DEFINE(HAVE_STDLIB_H))
AC_CHECK_HEADER(crypt.h,AC_DEFINE(HAVE_CRYPT_H))
AC_CHECK_HEADER(langinfo.h,AC_DEFINE(HAVE_LANGINFO_H))
AC_CHECK_HEADER(malloc.h,AC_DEFINE(HAVE_MALLOC_H))
AC_CHECK_HEADER(shadow.h,AC_DEFINE(HAVE_SHADOW_H))
AC_CHECK_HEADER(stdint.h,AC_DEFINE(HAVE_STDINT_H))
AC_CHECK_HEADER(string.h,AC_DEFINE(HAVE_STRING_H))
AC_CHECK_HEADER(strings.h,AC_DEFINE(HAVE_STRINGS_H))
AC_CHECK_HEADER(bstring.h,AC_DEFINE(HAVE_BSTRING_H))
AC_CHECK_HEADER(sys/ioctl.h,AC_DEFINE(HAVE_SYS_IOCTL_H))
AC_CHECK_HEADER(sys/param.h,AC_DEFINE(HAVE_SYS_PARAM_H))
AC_CHECK_HEADER(sys/ucred.h,AC_DEFINE(HAVE_SYS_UCRED_H))

dnl Checks for iconv.h and iconv_open
AC_CHECK_HEADER(iconv.h,
	SAVELIBS="$LIBS"
	LIBS=""
	AC_SEARCH_LIBS(iconv_open,iconv,
		AC_DEFINE(HAVE_ICONV_H)
		SAVELIBS="$SAVELIBS $LIBS")
	AC_SEARCH_LIBS(libiconv_open,iconv,
		AC_DEFINE(HAVE_ICONV_H)
		SAVELIBS="$SAVELIBS $LIBS")
	LIBS="$SAVELIBS")

dnl Checks for statfs and its many headers...
AC_CHECK_HEADER(sys/mount.h,AC_DEFINE(HAVE_SYS_MOUNT_H))
AC_CHECK_HEADER(sys/statfs.h,AC_DEFINE(HAVE_SYS_STATFS_H))
AC_CHECK_HEADER(sys/statvfs.h,AC_DEFINE(HAVE_SYS_STATVFS_H))
AC_CHECK_HEADER(sys/vfs.h,AC_DEFINE(HAVE_SYS_VFS_H))
AC_CHECK_FUNCS(statfs statvfs)

dnl Checks for string functions.
AC_CHECK_FUNCS(strdup strlcat strlcpy)
if test "$host_os_name" = "hp-ux" -a "$host_os_version" = "1020"; then
	echo Forcing snprintf emulation for HP-UX.
else
	AC_CHECK_FUNCS(snprintf vsnprintf)
fi

dnl Check for random number functions...
AC_CHECK_FUNCS(random lrand48 arc4random)

dnl Check for geteuid function.
AC_CHECK_FUNCS(geteuid)

dnl Check for setpgid function.
AC_CHECK_FUNCS(setpgid)

dnl Check for vsyslog function.
AC_CHECK_FUNCS(vsyslog)

dnl Checks for signal functions.
case "$host_os_name" in
	linux* | gnu*)
		# Do not use sigset on Linux or GNU HURD
		;;
	*)
		# Use sigset on other platforms, if available
		AC_CHECK_FUNCS(sigset)
		;;
esac

AC_CHECK_FUNCS(sigaction)

dnl Checks for wait functions.
AC_CHECK_FUNCS(waitpid wait3)

dnl Check for posix_spawn
AC_CHECK_FUNCS(posix_spawn)

dnl Check for getgrouplist
AC_CHECK_FUNCS(getgrouplist)

dnl See if the tm structure has the tm_gmtoff member...
AC_MSG_CHECKING(for tm_gmtoff member in tm structure)
AC_TRY_COMPILE([#include <time.h>],[struct tm t;
	int o = t.tm_gmtoff;],
	AC_MSG_RESULT(yes)
	AC_DEFINE(HAVE_TM_GMTOFF),
	AC_MSG_RESULT(no))

dnl See if the stat structure has the st_gen member...
AC_MSG_CHECKING(for st_gen member in stat structure)
AC_TRY_COMPILE([#include <sys/stat.h>],[struct stat t;
	int o = t.st_gen;],
	AC_MSG_RESULT(yes)
	AC_DEFINE(HAVE_ST_GEN),
	AC_MSG_RESULT(no))

dnl See if we have the removefile(3) function for securely removing files
AC_CHECK_FUNCS(removefile)

dnl See if we have libusb...
AC_ARG_ENABLE(libusb, [  --enable-libusb         use libusb for USB printing])

LIBUSB=""
USBQUIRKS=""
AC_SUBST(LIBUSB)
AC_SUBST(USBQUIRKS)

if test "x$PKGCONFIG" != x; then
	if test x$enable_libusb != xno -a $host_os_name != darwin; then
		AC_MSG_CHECKING(for libusb-1.0)
		if $PKGCONFIG --exists libusb-1.0; then
			AC_MSG_RESULT(yes)
			AC_DEFINE(HAVE_LIBUSB)
			CFLAGS="$CFLAGS `$PKGCONFIG --cflags libusb-1.0`"
			LIBUSB="`$PKGCONFIG --libs libusb-1.0`"
			USBQUIRKS="\$(DATADIR)/usb"
		else
			AC_MSG_RESULT(no)
			if test x$enable_libusb = xyes; then
				AC_MSG_ERROR(libusb required for --enable-libusb.)
			fi
		fi
	fi
elif test x$enable_libusb = xyes; then
	AC_MSG_ERROR(Need pkg-config to enable libusb support.)
fi

dnl See if we have libwrap for TCP wrappers support...
AC_ARG_ENABLE(tcp_wrappers, [  --enable-tcp-wrappers   use libwrap for TCP wrappers support])

LIBWRAP=""
AC_SUBST(LIBWRAP)

if test x$enable_tcp_wrappers = xyes; then
	AC_CHECK_LIB(wrap, hosts_access,[
		AC_CHECK_HEADER(tcpd.h,
			AC_DEFINE(HAVE_TCPD_H)
			LIBWRAP="-lwrap")])
fi

dnl ZLIB
INSTALL_GZIP=""
LIBZ=""
AC_CHECK_HEADER(zlib.h,
    AC_CHECK_LIB(z, gzgets,[
	AC_DEFINE(HAVE_LIBZ)
	LIBZ="-lz"
	LIBS="$LIBS -lz"
	AC_CHECK_LIB(z, inflateCopy, AC_DEFINE(HAVE_INFLATECOPY))
	if test "x$GZIPPROG" != x; then
		INSTALL_GZIP="-z"
	fi]))
AC_SUBST(INSTALL_GZIP)
AC_SUBST(LIBZ)

dnl Flags for "ar" command...
case $host_os_name in
        darwin* | *bsd*)
                ARFLAGS="-rcv"
                ;;
        *)
                ARFLAGS="crvs"
                ;;
esac

AC_SUBST(ARFLAGS)

dnl Prep libraries specifically for cupsd and backends...
BACKLIBS=""
SERVERLIBS=""
AC_SUBST(BACKLIBS)
AC_SUBST(SERVERLIBS)

dnl See if we have POSIX ACL support...
SAVELIBS="$LIBS"
LIBS=""
AC_ARG_ENABLE(acl, [  --enable-acl            build with POSIX ACL support])
if test "x$enable_acl" != xno; then
	AC_SEARCH_LIBS(acl_init, acl, AC_DEFINE(HAVE_ACL_INIT))
	SERVERLIBS="$SERVERLIBS $LIBS"
fi
LIBS="$SAVELIBS"

dnl Check for DBUS support
DBUSDIR=""
DBUS_NOTIFIER=""
DBUS_NOTIFIERLIBS=""

AC_ARG_ENABLE(dbus, [  --disable-dbus          build without DBUS support])
AC_ARG_WITH(dbusdir, [  --with-dbusdir          set DBUS configuration directory ],
	DBUSDIR="$withval")

if test "x$enable_dbus" != xno -a "x$PKGCONFIG" != x -a "x$host_os_name" != xdarwin; then
	AC_MSG_CHECKING(for DBUS)
	if $PKGCONFIG --exists dbus-1; then
		AC_MSG_RESULT(yes)
		AC_DEFINE(HAVE_DBUS)
		CFLAGS="$CFLAGS `$PKGCONFIG --cflags dbus-1` -DDBUS_API_SUBJECT_TO_CHANGE"
		SERVERLIBS="$SERVERLIBS `$PKGCONFIG --libs dbus-1`"
		DBUS_NOTIFIER="dbus"
		DBUS_NOTIFIERLIBS="`$PKGCONFIG --libs dbus-1`"
		SAVELIBS="$LIBS"
		LIBS="$LIBS $DBUS_NOTIFIERLIBS"
		AC_CHECK_FUNC(dbus_message_iter_init_append,
			      AC_DEFINE(HAVE_DBUS_MESSAGE_ITER_INIT_APPEND))
		AC_CHECK_FUNC(dbus_threads_init,
			      AC_DEFINE(HAVE_DBUS_THREADS_INIT))
		LIBS="$SAVELIBS"
		if test -d /etc/dbus-1 -a "x$DBUSDIR" = x; then
			DBUSDIR="/etc/dbus-1"
		fi
	else
		AC_MSG_RESULT(no)
	fi
fi

AC_SUBST(DBUSDIR)
AC_SUBST(DBUS_NOTIFIER)
AC_SUBST(DBUS_NOTIFIERLIBS)

dnl Extra platform-specific libraries...
CUPS_DEFAULT_PRINTOPERATOR_AUTH="@SYSTEM"
CUPS_DEFAULT_SYSTEM_AUTHKEY=""
CUPS_SYSTEM_AUTHKEY=""
INSTALLXPC=""

case $host_os_name in
        darwin*)
                BACKLIBS="$BACKLIBS -framework IOKit"
                SERVERLIBS="$SERVERLIBS -framework IOKit -weak_framework ApplicationServices"
                LIBS="-framework CoreFoundation -framework Security $LIBS"

		dnl Check for framework headers...
		AC_CHECK_HEADER(ApplicationServices/ApplicationServices.h,AC_DEFINE(HAVE_APPLICATIONSERVICES_H))
		AC_CHECK_HEADER(CoreFoundation/CoreFoundation.h,AC_DEFINE(HAVE_COREFOUNDATION_H))

		dnl Check for dynamic store function...
		SAVELIBS="$LIBS"
		LIBS="-framework SystemConfiguration $LIBS"
		AC_CHECK_FUNCS(SCDynamicStoreCopyComputerName,[
		    AC_DEFINE(HAVE_SCDYNAMICSTORECOPYCOMPUTERNAME)],[
		    LIBS="$SAVELIBS"])

		dnl Check for the new membership functions in MacOSX 10.4...
		AC_CHECK_HEADER(membership.h,AC_DEFINE(HAVE_MEMBERSHIP_H))
		AC_CHECK_FUNCS(mbr_uid_to_uuid)

		dnl Need <dlfcn.h> header...
		AC_CHECK_HEADER(dlfcn.h,AC_DEFINE(HAVE_DLFCN_H))

		dnl Check for notify_post support
		AC_CHECK_HEADER(notify.h,AC_DEFINE(HAVE_NOTIFY_H))
		AC_CHECK_FUNCS(notify_post)

		dnl Check for Authorization Services support
		AC_ARG_WITH(adminkey, [  --with-adminkey         set the default SystemAuthKey value],
			default_adminkey="$withval",
			default_adminkey="default")
 		AC_ARG_WITH(operkey, [  --with-operkey          set the default operator @AUTHKEY value],
			default_operkey="$withval",
			default_operkey="default")

		AC_CHECK_HEADER(Security/Authorization.h, [
			AC_DEFINE(HAVE_AUTHORIZATION_H)

			if test "x$default_adminkey" != xdefault; then
				CUPS_SYSTEM_AUTHKEY="SystemGroupAuthKey $default_adminkey"
				CUPS_DEFAULT_SYSTEM_AUTHKEY="$default_adminkey"
			else
				CUPS_SYSTEM_AUTHKEY="SystemGroupAuthKey system.print.admin"
				CUPS_DEFAULT_SYSTEM_AUTHKEY="system.print.admin"
			fi

			if test "x$default_operkey" != xdefault; then
				CUPS_DEFAULT_PRINTOPERATOR_AUTH="@AUTHKEY($default_operkey) @admin @lpadmin"
			else
				CUPS_DEFAULT_PRINTOPERATOR_AUTH="@AUTHKEY(system.print.operator) @admin @lpadmin"
			fi])

		dnl Check for sandbox/Seatbelt support
		if test $host_os_version -ge 100; then
			AC_CHECK_HEADER(sandbox.h,AC_DEFINE(HAVE_SANDBOX_H))
		fi
		if test $host_os_version -ge 110 -a $host_os_version -lt 120; then
			# Broken public headers in 10.7.x...
			AC_MSG_CHECKING(for sandbox/private.h presence)
			if test -f /usr/local/include/sandbox/private.h; then
				AC_MSG_RESULT(yes)
			else
				AC_MSG_RESULT(no)
				AC_MSG_ERROR(Run 'sudo mkdir -p /usr/local/include/sandbox' and 'sudo touch /usr/local/include/sandbox/private.h' to build CUPS.)
			fi
		fi

		dnl Check for XPC support
		AC_CHECK_HEADER(xpc/xpc.h,
			AC_DEFINE(HAVE_XPC)
			INSTALLXPC="install-xpc")
                ;;
esac

AC_SUBST(CUPS_DEFAULT_PRINTOPERATOR_AUTH)
AC_DEFINE_UNQUOTED(CUPS_DEFAULT_PRINTOPERATOR_AUTH, "$CUPS_DEFAULT_PRINTOPERATOR_AUTH")
AC_DEFINE_UNQUOTED(CUPS_DEFAULT_SYSTEM_AUTHKEY, "$CUPS_DEFAULT_SYSTEM_AUTHKEY")
AC_SUBST(CUPS_SYSTEM_AUTHKEY)
AC_SUBST(INSTALLXPC)

dnl Check for build components
COMPONENTS="all"

AC_ARG_WITH(components, [  --with-components       set components to build:
			    - "all" (default) builds everything
			    - "core" builds libcups and ipptool
			    - "libcups" builds just libcups
			    - "libcupslite" builds just libcups without driver support],
	COMPONENTS="$withval")

cupsimagebase="cupsimage"
IPPEVECOMMANDS="ippevepcl ippeveps"
LIBCUPSOBJS="\$(COREOBJS) \$(DRIVEROBJS)"
LIBHEADERS="\$(COREHEADERS) \$(DRIVERHEADERS)"
LIBHEADERSPRIV="\$(COREHEADERSPRIV) \$(DRIVERHEADERSPRIV)"

case "$COMPONENTS" in
	all)
		BUILDDIRS="tools filter backend berkeley cgi-bin monitor notifier ppdc scheduler systemv conf data desktop locale man doc examples templates"
		;;

	core)
		BUILDDIRS="tools examples locale"
		;;

	corelite)
		AC_DEFINE(CUPS_LITE)
		BUILDDIRS="tools examples locale"
		cupsimagebase=""
		LIBCUPSOBJS="\$(COREOBJS)"
		LIBHEADERS="\$(COREHEADERS)"
		LIBHEADERSPRIV="\$(COREHEADERSPRIV)"
		;;

	libcups)
		BUILDDIRS="locale"
		cupsimagebase=""
		;;

	libcupslite)
		AC_DEFINE(CUPS_LITE)
		BUILDDIRS="locale"
		cupsimagebase=""
		LIBCUPSOBJS="\$(COREOBJS)"
		LIBHEADERS="\$(COREHEADERS)"
		LIBHEADERSPRIV="\$(COREHEADERSPRIV)"
		;;

	*)
		AC_MSG_ERROR([Bad build component "$COMPONENT" specified!])
		;;
esac

AC_SUBST(BUILDDIRS)
AC_SUBST(IPPEVECOMMANDS)
AC_SUBST(LIBCUPSOBJS)
AC_SUBST(LIBHEADERS)
AC_SUBST(LIBHEADERSPRIV)
