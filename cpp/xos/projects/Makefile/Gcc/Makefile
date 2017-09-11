########################################################################
# Copyright (c) 1988-2017 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 8/30/2017
#
# generic Gcc Makefile for nadir
########################################################################
NADIR_PKG = ${PKG}
NADIR_SRC = ${NADIR_PKG}/src
NADIR_BLD = ${NADIR_PKG}/${BLD}/${BUILD_TYPE}
NADIR_LIB = ${NADIR_BLD}/lib
NADIR_BIN = ${NADIR_BLD}/bin

########################################################################
# rostra
ROSTRA_PKG = ${NADIR_PKG}/../../../rostra/cpp/xos
ROSTRA_SRC = ${ROSTRA_PKG}/src
ROSTRA_BLD = ${ROSTRA_PKG}/${BLD}/${BUILD_TYPE}
ROSTRA_LIB = ${ROSTRA_BLD}/lib
ROSTRA_BIN = ${ROSTRA_BLD}/bin

########################################################################
# nadir
nadir_USRDEFINES += \

nadir_USRINCLUDES += \
-I${NADIR_SRC} \
-I${ROSTRA_SRC} \

nadir_USRCXXFLAGS += \
-std=c++0x \

nadir_USRLIBDIRS += \
-L${NADIR_LIB} \

nadir_LIBS += \
-lnadir \

########################################################################

