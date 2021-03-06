///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: Writer.cpp
///
/// Author: $author$
///   Date: 10/6/2017
///////////////////////////////////////////////////////////////////////
#include "xos/io/crt/file/Writer.hpp"

namespace xos {
namespace io {
namespace crt {
namespace file {

} // namespace file 
} // namespace crt 
} // namespace io 
} // namespace xos 

#if defined(XOS_IO_CRT_FILE_WRITER_MAIN_MAIN)
int main(int argc, char **argv, char **env) {
    xos::io::crt::file::Writer writer;
    int err = 0;
    if ((writer.OpenPatterned("cgicatch-env.txt", "environment"))) {
        writer.Close();
    }
    return err;
}
#endif // defined(XOS_IO_CRT_FILE_WRITER_MAIN_MAIN)
