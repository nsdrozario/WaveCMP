#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([WaveCMP], [1.0], [nsdrozario@gmail.com])
AM_INIT_AUTOMAKE
AC_OUTPUT([Makefile src/Makefile])
AC_CONFIG_SRCDIR([src/wavecmp.cpp])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AC_CHECK_LIB([gtkmm-3.0])
PKG_CHECK_MODULES([WaveCMP], [gtkmm-3.0 >= 3.8.0])

# Checks for header files.
AC_CHECK_HEADERS([gtkmm.h])
# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

AC_OUTPUT
