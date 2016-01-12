%########################################################################
%# Copyright (c) 1988-2016 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: thirdparty-xos-hpp.t
%#
%# Author: $author$
%#   Date: 1/7/2016
%########################################################################
%with(%
%section,%(%else-then(%section%,%(base)%)%)%,%
%Section,%(%else-then(%Section%,%(%section%)%)%)%,%
%SECTION,%(%else-then(%SECTION%,%(%toupper(%Section%)%)%)%)%,%
%section,%(%else-then(%_Section%,%(%tolower(%Section%)%)%)%)%,%
%name,%(%else-then(%name%,%(Name)%)%)%,%
%Name,%(%else-then(%Name%,%(%name%)%)%)%,%
%NAME,%(%else-then(%NAME%,%(%toupper(%Name%)%)%)%)%,%
%name,%(%else-then(%_Name%,%(%tolower(%Name%)%)%)%)%,%
%%(%
%///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-%year()% $organization$
///
/// This software is provided by the author and contributors ``as is''
/// and any express or implied warranties, including, but not limited to,
/// the implied warranties of merchantability and fitness for a particular
/// purpose are disclaimed. In no event shall the author or contributors
/// be liable for any direct, indirect, incidental, special, exemplary,
/// or consequential damages (including, but not limited to, procurement
/// of substitute goods or services; loss of use, data, or profits; or
/// business interruption) however caused and on any theory of liability,
/// whether in contract, strict liability, or tort (including negligence
/// or otherwise) arising in any way out of the use of this software,
/// even if advised of the possibility of such damage.
///
///   File: %Name%.hpp
///
/// Author: $author$
///   Date: %date()%
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_THIRDPARTY_XOS_%SECTION%_%NAME%_HPP
#define _XOS_NADIR_THIRDPARTY_XOS_%SECTION%_%NAME%_HPP

#include "../../../../../../xos/src/xos/%Section%/%Name%.hpp"
#include "../../../../xos/%section%/%name%.hpp"

namespace xos {
namespace thirdparty {
namespace xos {
namespace %section% {

} // namespace %section%
} // namespace xos
} // namespace thirdparty
} // namespace xos

#endif // _XOS_NADIR_THIRDPARTY_XOS_%SECTION%_%NAME%_HPP
%
%)%)%