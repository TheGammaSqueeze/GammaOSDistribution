dnl
dnl Launch-on-demand/startup stuff for CUPS.
dnl
dnl Copyright 2007-2017 by Apple Inc.
dnl Copyright 1997-2005 by Easy Software Products, all rights reserved.
dnl
dnl Licensed under Apache License v2.0.  See the file "LICENSE" for more information.
dnl

ONDEMANDFLAGS=""
ONDEMANDLIBS=""
AC_SUBST(ONDEMANDFLAGS)
AC_SUBST(ONDEMANDLIBS)

dnl Launchd is used on macOS/Darwin...
AC_ARG_ENABLE(launchd, [  --disable-launchd       disable launchd support])
LAUNCHD_DIR=""
AC_SUBST(LAUNCHD_DIR)

if test x$enable_launchd != xno; then
	AC_CHECK_FUNC(launch_activate_socket, [
		AC_DEFINE(HAVE_LAUNCHD)
		AC_DEFINE(HAVE_ONDEMAND)])
	AC_CHECK_HEADER(launch.h, AC_DEFINE(HAVE_LAUNCH_H))

	if test "$host_os_name" = darwin; then
	        LAUNCHD_DIR="/System/Library/LaunchDaemons"
		# liblaunch is already part of libSystem
	fi
fi

dnl Systemd is used on Linux...
AC_ARG_ENABLE(systemd, [  --disable-systemd       disable systemd support])
AC_ARG_WITH(systemd, [  --with-systemd          set directory for systemd service files],
        SYSTEMD_DIR="$withval", SYSTEMD_DIR="")
AC_SUBST(SYSTEMD_DIR)

if test x$enable_systemd != xno; then
	if test "x$PKGCONFIG" = x; then
        	if test x$enable_systemd = xyes; then
	        	AC_MSG_ERROR(Need pkg-config to enable systemd support.)
                fi
        else
        	have_systemd=no
        	AC_MSG_CHECKING(for libsystemd)
                if $PKGCONFIG --exists libsystemd; then
                        AC_MSG_RESULT(yes)
                        have_systemd=yes
                        ONDEMANDFLAGS=`$PKGCONFIG --cflags libsystemd`
                        ONDEMANDLIBS=`$PKGCONFIG --libs libsystemd`
		elif $PKGCONFIG --exists libsystemd-daemon; then
			AC_MSG_RESULT(yes - legacy)
                        have_systemd=yes
			ONDEMANDFLAGS=`$PKGCONFIG --cflags libsystemd-daemon`
			ONDEMANDLIBS=`$PKGCONFIG --libs libsystemd-daemon`

			if $PKGCONFIG --exists libsystemd-journal; then
				ONDEMANDFLAGS="$ONDEMANDFLAGS `$PKGCONFIG --cflags libsystemd-journal`"
				ONDEMANDLIBS="$ONDEMANDLIBS `$PKGCONFIG --libs libsystemd-journal`"
			fi
                else
                        AC_MSG_RESULT(no)
                fi

		if test $have_systemd = yes; then
                        AC_DEFINE(HAVE_SYSTEMD)
                        AC_DEFINE(HAVE_ONDEMAND)
			AC_CHECK_HEADER(systemd/sd-journal.h,AC_DEFINE(HAVE_SYSTEMD_SD_JOURNAL_H))
			if test "x$SYSTEMD_DIR" = x; then
			        SYSTEMD_DIR="`$PKGCONFIG --variable=systemdsystemunitdir systemd`"
                        fi
                fi
        fi
fi

dnl Upstart is also used on Linux (e.g., Chrome OS)
AC_ARG_ENABLE(upstart, [  --enable-upstart        enable upstart support])
if test "x$enable_upstart" = "xyes"; then
	if test "x$have_systemd" = "xyes"; then
		AC_MSG_ERROR(Cannot support both systemd and upstart.)
	fi
	AC_DEFINE(HAVE_UPSTART)
	AC_DEFINE(HAVE_ONDEMAND)
fi

dnl Solaris uses smf
SMFMANIFESTDIR=""
AC_SUBST(SMFMANIFESTDIR)
AC_ARG_WITH(smfmanifestdir, [  --with-smfmanifestdir   set path for Solaris SMF manifest],SMFMANIFESTDIR="$withval")

dnl Use init on other platforms...
AC_ARG_WITH(rcdir, [  --with-rcdir            set path for rc scripts],rcdir="$withval",rcdir="")
AC_ARG_WITH(rclevels, [  --with-rclevels         set run levels for rc scripts],rclevels="$withval",rclevels="2 3 5")
AC_ARG_WITH(rcstart, [  --with-rcstart          set start number for rc scripts],rcstart="$withval",rcstart="")
AC_ARG_WITH(rcstop, [  --with-rcstop           set stop number for rc scripts],rcstop="$withval",rcstop="")

if test x$rcdir = x; then
	if test x$LAUNCHD_DIR = x -a x$SYSTEMD_DIR = x -a x$SMFMANIFESTDIR = x; then
                # Fall back on "init", the original service startup interface...
                if test -d /sbin/init.d; then
                        # SuSE
                        rcdir="/sbin/init.d"
                elif test -d /etc/init.d; then
                        # Others
                        rcdir="/etc"
                else
                        # RedHat, NetBSD
                        rcdir="/etc/rc.d"
                fi
        else
        	rcdir="no"
	fi
fi

if test "x$rcstart" = x; then
	case "$host_os_name" in
        	linux* | gnu*)
                	# Linux
                        rcstart="81"
                      	;;

		sunos*)
			# Solaris
                        rcstart="81"
			;;

                *)
                        # Others
                        rcstart="99"
                        ;;
	esac
fi

if test "x$rcstop" = x; then
	case "$host_os_name" in
        	linux* | gnu*)
                	# Linux
                        rcstop="36"
                      	;;

                *)
                        # Others
                        rcstop="00"
                        ;;
	esac
fi

INITDIR=""
INITDDIR=""
RCLEVELS="$rclevels"
RCSTART="$rcstart"
RCSTOP="$rcstop"
AC_SUBST(INITDIR)
AC_SUBST(INITDDIR)
AC_SUBST(RCLEVELS)
AC_SUBST(RCSTART)
AC_SUBST(RCSTOP)

if test "x$rcdir" != xno; then
	if test "x$rclevels" = x; then
		INITDDIR="$rcdir"
	else
		INITDIR="$rcdir"
	fi
fi

dnl Xinetd support...
AC_ARG_WITH(xinetd, [  --with-xinetd           set path for xinetd config files],xinetd="$withval",xinetd="")
XINETD=""
AC_SUBST(XINETD)

if test "x$xinetd" = x; then
	if test ! -x /sbin/launchd; then
                for dir in /etc/xinetd.d /usr/local/etc/xinetd.d; do
                        if test -d $dir; then
                                XINETD="$dir"
                                break
                        fi
                done
        fi
elif test "x$xinetd" != xno; then
	XINETD="$xinetd"
fi
