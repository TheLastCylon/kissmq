AC_INIT([kissmq], [0.1], [bothadjt@gmail.com], [kissmq], [http://djb.co.za/])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 -Wall no-define])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CXX
AC_CONFIG_MACRO_DIR([m4])

AX_BOOST_BASE([1.49.0])
AX_BOOST_ASIO
AX_BOOST_DATE_TIME
AX_BOOST_FILESYSTEM
AX_BOOST_REGEX
AX_BOOST_SYSTEM
AX_BOOST_THREAD

AC_ARG_WITH([boost-include-path],
            [AS_HELP_STRING([--with-boost-include-path], [location of the boost headers, defaults to /usr/include])],
            [BOOST_CFLAGS="-I$withval"],
            [BOOST_CFLAGS='-I/usr/include'])
AC_SUBST([BOOST_CFLAGS]) 

AC_ARG_WITH([boost-lib-path],
            [AS_HELP_STRING([--with-boost-lib-path], [location of the boost libraries])],
            [BOOST_LIBS="-L$withval -lboost_system -lboost_thread -lboost_filesystem -lboost_regex -lboost_date_time"],
            [BOOST_LIBS='-lboost_system -lboost_thread -lboost_filesystem -lboost_regex -lboost_date_time'])
AC_SUBST([BOOST_LIBS])

PKG_CHECK_MODULES([DEPS], [kisscpp-1 >= 0.5])

# Checks for header files.
#AC_CHECK_HEADERS([stdint.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
#AC_CHECK_HEADER_STDBOOL
#AC_TYPE_UINT32_T
#AC_TYPE_UINT8_T

AC_CONFIG_FILES([Makefile])

AC_OUTPUT

