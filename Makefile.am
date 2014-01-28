AUTOMAKE_OPTIONS    = subdir-objects
ACLOCAL_AMFLAGS     = -I m4
AM_CPPFLAGS         = $(DEPS_CFLAGS) $(BOOST_CFLAGS)
kissmq_LDADD        = $(DEPS_LIBS) $(BOOST_LIBS)
bin_PROGRAMS        = kissmq
kissmq_SOURCES      = src/handler_publish.cpp \
                      src/handler_publish.hpp \
                      src/kissmq.cpp \
                      src/kissmq.hpp \
                      src/main.cpp
dist_noinst_SCRIPTS = autogen.sh

