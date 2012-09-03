## Copyright 2012 Mo McRoberts.
##
##  Licensed under the Apache License, Version 2.0 (the "License");
##  you may not use this file except in compliance with the License.
##  You may obtain a copy of the License at
##
##      http://www.apache.org/licenses/LICENSE-2.0
##
##  Unless required by applicable law or agreed to in writing, software
##  distributed under the License is distributed on an "AS IS" BASIS,
##  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
##  See the License for the specific language governing permissions and
##  limitations under the License.

AC_INIT([echo],[master])

AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE

AC_CONFIG_HEADER([config.h])

AC_PROG_CC

AC_ARG_ENABLE([docs],[AS_HELP_STRING([--disable-docs],[disable re-building documentation (default=auto)])],[build_docs=$enableval],[build_docs=auto])

if test x"$build_docs" = x"yes" || test x"$build_docs" = x"auto" ; then
   AC_CHECK_PROGS([XSLTPROC],[xsltproc],[false])
   if test x"$XSLTPROC" = x"false" ; then
   	  if test x"$build_docs" = x"yes" ; then
	  	 AC_MSG_ERROR([re-building documentation was requested, but the xsltproc utility cannot be found])
	  fi
	  build_docs=no
   else
      build_docs=yes
   fi
else
   build_docs=no
fi

AC_MSG_CHECKING([whether to re-build documentation if needed])
AC_MSG_RESULT([$build_docs])

AM_CONDITIONAL([BUILD_DOCS],[test x"$build_docs" = x"yes"])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
