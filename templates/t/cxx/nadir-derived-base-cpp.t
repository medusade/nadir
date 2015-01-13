%########################################################################
%# Copyright (c) 1988-2014 $organization$
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
%#   File: nadir-derived-base-cpp.t
%#
%# Author: $author$
%#   Date: 12/15/2014
%########################################################################
%with(%
%_lt_,%(%if(%equal(%content_type%,text/html)%,%(&lt;)%,%(<)%)%)%,%
%_gt_,%(%if(%equal(%content_type%,text/html)%,%(&gt;)%,%(>)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%file,%(%else-then(%file%,%(base)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%File%)%)%)%)%,%
%File_base,%(%else-then(%File_base%,%(%file_base%)%)%)%,%
%FILE_BASE,%(%else-then(%FILE_BASE%,%(%toupper(%File_base%)%)%)%)%,%
%file_base,%(%else-then(%_File_base%,%(%tolower(%File_base%)%)%)%)%,%
%file_type,%(%else-then(%file_type%,%(hpp)%)%)%,%
%File_type,%(%else-then(%File_type%,%(%file_type%)%)%)%,%
%FILE_TYPE,%(%else-then(%FILE_TYPE%,%(%toupper(%File_type%)%)%)%)%,%
%file_type,%(%else-then(%_File_type%,%(%tolower(%File_type%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%File_type%)%)%)%,%
%File_extension,%(%else-then(%File_extension%,%(%file_extension%)%)%)%,%
%FILE_EXTENSION,%(%else-then(%FILE_EXTENSION%,%(%toupper(%File_extension%)%)%)%)%,%
%file_extension,%(%else-then(%_File_extension%,%(%tolower(%File_extension%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(%else-then(%class%,%(framework)%)%)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%base,%(%else-then(%base%,%(xos)%)%)%,%
%Base,%(%else-then(%Base%,%(%base%)%)%)%,%
%BASE,%(%else-then(%BASE%,%(%toupper(%Base%)%)%)%)%,%
%base,%(%else-then(%_Base%,%(%tolower(%Base%)%)%)%)%,%
%%(%
%%include(%filepath%/nadir-cpp-file-begin.t)%%
%%if(%equal(%file_type%,cpp)%,%(%
%#include "%Framework%/base/%File%.hpp"

namespace %Framework% {

} // namespace %Framework%
%
%)%,%(%
%#ifndef _%FRAMEWORK%_BASE_%FILE%_%FILE_EXTENSION%
#define _%FRAMEWORK%_BASE_%FILE%_%FILE_EXTENSION%

#include "%Base%/base/base.hpp"
#include "%Base%/base/string.hpp"
#include "%Base%/base/types.hpp"
#include "%Base%/io/read/file.hpp"
#include "%Base%/io/write/file.hpp"
#include "%Base%/io/logger.hpp"

#define %FRAMEWORK%_LOG_ANY %BASE%_LOG_ANY
#define %FRAMEWORK%_LOG_FATAL %BASE%_LOG_FATAL
#define %FRAMEWORK%_LOG_ERROR %BASE%_LOG_ERROR
#define %FRAMEWORK%_LOG_WARN %BASE%_LOG_WARN
#define %FRAMEWORK%_LOG_INFO %BASE%_LOG_INFO
#define %FRAMEWORK%_LOG_DEBUG %BASE%_LOG_DEBUG
#define %FRAMEWORK%_LOG_TRACE %BASE%_LOG_TRACE

#define %FRAMEWORK%_LOG_ANYF %BASE%_LOG_ANYF
#define %FRAMEWORK%_LOG_FATALF %BASE%_LOG_FATALF
#define %FRAMEWORK%_LOG_ERRORF %BASE%_LOG_ERRORF
#define %FRAMEWORK%_LOG_WARNF %BASE%_LOG_WARNF
#define %FRAMEWORK%_LOG_INFOF %BASE%_LOG_INFOF
#define %FRAMEWORK%_LOG_DEBUGF %BASE%_LOG_DEBUGF
#define %FRAMEWORK%_LOG_TRACEF %BASE%_LOG_TRACEF

#define %FRAMEWORK%_LOG_MESSAGE_ANY %BASE%_LOG_MESSAGE_ANY
#define %FRAMEWORK%_LOG_MESSAGE_FATAL %BASE%_LOG_MESSAGE_FATAL
#define %FRAMEWORK%_LOG_MESSAGE_ERROR %BASE%_LOG_MESSAGE_ERROR
#define %FRAMEWORK%_LOG_MESSAGE_WARN %BASE%_LOG_MESSAGE_WARN
#define %FRAMEWORK%_LOG_MESSAGE_INFO %BASE%_LOG_MESSAGE_INFO
#define %FRAMEWORK%_LOG_MESSAGE_DEBUG %BASE%_LOG_MESSAGE_DEBUG
#define %FRAMEWORK%_LOG_MESSAGE_TRACE %BASE%_LOG_MESSAGE_TRACE

#define %FRAMEWORK%_LOG_MESSAGE_ANYF %BASE%_LOG_MESSAGE_ANYF
#define %FRAMEWORK%_LOG_MESSAGE_FATALF %BASE%_LOG_MESSAGE_FATALF
#define %FRAMEWORK%_LOG_MESSAGE_ERRORF %BASE%_LOG_MESSAGE_ERRORF
#define %FRAMEWORK%_LOG_MESSAGE_WARNF %BASE%_LOG_MESSAGE_WARNF
#define %FRAMEWORK%_LOG_MESSAGE_INFOF %BASE%_LOG_MESSAGE_INFOF
#define %FRAMEWORK%_LOG_MESSAGE_DEBUGF %BASE%_LOG_MESSAGE_DEBUGF
#define %FRAMEWORK%_LOG_MESSAGE_TRACEF %BASE%_LOG_MESSAGE_TRACEF

namespace %Framework% {

typedef %Base%::base::implement_base implement_base;
typedef %Base%::base::base base;

///////////////////////////////////////////////////////////////////////
/// string
///////////////////////////////////////////////////////////////////////
typedef %Base%::base::string_implement string_implements;
#if !defined(CPP_11)
#error Requires C++11
#else // !defined(CPP_11)
template
%_lt_%typename TChar = char, typename TEnd = TChar, TEnd VEnd = 0,
 class TExtends = std::basic_string%_lt_%TChar%_gt_%, class TImplements = string_implements%_gt_%

using stringt = typename %Base%::base::stringt
%_lt_%TChar, TEnd, VEnd, TExtends, TImplements%_gt_%;
#endif // !defined(CPP_11)
typedef %Base%::base::string string_t;
typedef %Base%::base::tstring tstring_t;
typedef %Base%::base::wstring wstring_t;

///////////////////////////////////////////////////////////////////////
/// types
///////////////////////////////////////////////////////////////////////
#if !defined(CPP_11)
#error Requires C++11
#else // !defined(CPP_11)
template
%_lt_%class TWhat = char, class TEndWhat = TWhat, TEndWhat VEndWhat = 0,
 class TInt = int, class TUInt = unsigned, class TSize = size_t,
 class TLength = ssize_t, TLength VUndefinedLength = -1%_gt_%

using typest = typename %Base%::base::typest
%_lt_%TWhat, TEndWhat, VEndWhat, TInt, TUInt, TSize, TLength, VUndefinedLength%_gt_%;
#endif // !defined(CPP_11)
typedef %Base%::base::chars_t chars_t;
typedef %Base%::base::tchars_t tchars_t;
typedef %Base%::base::wchars_t wchars_t;
typedef %Base%::base::bytes_t bytes_t;

namespace io {
namespace read {
typedef %Base%::io::read::file file;
} // namespace read
namespace write {
typedef %Base%::io::write::file file;
} // namespace write
} // namespace io

} // namespace %Framework%

#endif // _%FRAMEWORK%_BASE_%FILE%_%FILE_EXTENSION%
%
%)%)%%
%%include(%filepath%/nadir-cpp-file-end.t)%%
%)%)%