///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2014 $organization$
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
///   File: main.hpp
///
/// Author: $author$
///   Date: 9/7/2014
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_HPP
#define _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_HPP

#include "xos/base/getopt/main.hpp"
#include "xos/base/getopt/main_opt.hpp"
#include "xos/network/unix/socket.hpp"
#include "xos/network/ip/v6/udp/transport.hpp"
#include "xos/network/ip/v6/tcp/transport.hpp"
#include "xos/network/ip/v6/endpoint.hpp"
#include "xos/network/ip/v4/udp/transport.hpp"
#include "xos/network/ip/v4/tcp/transport.hpp"
#include "xos/network/ip/v4/endpoint.hpp"
#include "xos/base/types.hpp"

#define XOS_APP_CONSOLE_HELLO_PORTNO 8080
#define XOS_APP_CONSOLE_HELLO_PORT XOS_BASE_2STRING(XOS_APP_CONSOLE_HELLO_PORTNO)
#define XOS_APP_CONSOLE_HELLO_HOST "localhost"
#define XOS_APP_CONSOLE_HELLO_MESSAGE "Hello"
#define XOS_APP_CONSOLE_HELLO_MESSAGE_SEND_SEPARATOR "\r\n"
#define XOS_APP_CONSOLE_HELLO_MESSAGE_SEND_SUFFIX "\r\n\r\n"

#include "xos/app/console/hello/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace hello {

typedef base::getopt::main_implement main_implement;
typedef base::getopt::main main_extend;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implement, public main_extend {
public:
    typedef main_implement Implements;
    typedef main_extend Extends;
    typedef main Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : run_(0),
      ep_(&Derives::ip_v4_ep),
      tp_(&Derives::ip_v4_tcp_tp),
      portno_(XOS_APP_CONSOLE_HELLO_PORTNO),
      port_(XOS_APP_CONSOLE_HELLO_PORT),
      host_(XOS_APP_CONSOLE_HELLO_HOST),
      message_(XOS_APP_CONSOLE_HELLO_MESSAGE),
      message_send_separator_(XOS_APP_CONSOLE_HELLO_MESSAGE_SEND_SEPARATOR),
      message_send_suffix_(XOS_APP_CONSOLE_HELLO_MESSAGE_SEND_SUFFIX) {
    }
    virtual ~main() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        if ((run_)) {
            return (this->*run_)(argc, argv, env);
        } else {
            const char_t* arg = (argc>optind)?(argv[optind]):(0);
            const char_t* chars = message_.chars();
            outf("%s%s%s\n", (chars)?(chars):(""), (arg)?(" "):(""), (arg)?(arg):(""));
        }
        return 0;
    }
    virtual int client_run(int argc, char_t** argv, char_t** env) {
        string_t message("GET /source/ HTTP/1.1\r\nHost: localhost\r\n\r\n");
        const char* chars = 0;
        size_t length = 0;
        if ((chars = client_message(length, message, argc, argv, env))) {
            network::endpoint* ep = 0;

            if ((ep_) && (ep = ((this->*ep_)()))) {
                network::transport* tp = 0;

                if ((tp_) && (tp = (this->*tp_)())) {
                    network::unix::socket s;

                    if ((s.open(*tp))) {
                        if ((s.connect(*ep))) {
                            ssize_t count;

                            XOS_LOG_MESSAGE_DEBUG("sending \"" << chars << "\"...");
                            if (0 < (count = s.send(chars, length, 0))) {

                                XOS_LOG_MESSAGE_DEBUG("...sent \"" << chars << "\"");
                                do {

                                    XOS_LOG_MESSAGE_DEBUG("recv[" << sizeof(chars_) << "]...");
                                    if (0 < (count = s.recv(chars_, sizeof(chars_), 0))) {

                                        XOS_LOG_MESSAGE_DEBUG("...recv[" << count << "]");
                                        out(chars_, count);
                                        continue;
                                    } else {
                                        XOS_LOG_MESSAGE_DEBUG("...failed with recv[" << count << "]");
                                    }
                                    break;
                                } while (0 < count);
                            } else {
                                XOS_LOG_MESSAGE_ERROR("... failed to send \"" << chars << "\"");
                            }
                        }
                        s.close();
                    }
                    delete tp;
                }
                delete ep;
            }
        }
        return 0;
    }
    virtual const char_t* client_message
    (size_t& length, string_t& message, int argc, char_t** argv, char_t** env) {
        if ((message_.has_chars())) {
            message.assign(message_);
            for (int arg = optind; arg < argc; ++arg) {
                const char_t* chars;
                if (((chars = argv[arg])[0])) {
                    message.append(message_send_separator_);
                    message.append(chars);
                }
            }
            message.append(message_send_suffix_);
        }
        return message.has_chars(length);
    }
    virtual int server_run(int argc, char_t** argv, char_t** env) {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::transport* ip_v4_tcp_tp() {
        network::transport* tp = new network::ip::v4::tcp::transport();
        return tp;
    }
    virtual network::transport* ip_v4_udp_tp() {
        network::transport* tp = new network::ip::v4::udp::transport();
        return tp;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::transport* ip_v6_tcp_tp() {
        network::transport* tp = new network::ip::v6::tcp::transport();
        return tp;
    }
    virtual network::transport* ip_v6_udp_tp() {
        network::transport* tp = new network::ip::v6::udp::transport();
        return tp;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::endpoint* ip_v4_ep() {
        const char_t* host;
        ushort port;
        if ((host = host_.has_chars()) && (0 < (port = portno_))) {
            network::endpoint* ep = new network::ip::v4::endpoint(host, port);
            return ep;
        }
        return 0;
    }
    virtual network::endpoint* ip_v6_ep() {
        const char_t* host;
        ushort port;
        if ((host = host_.has_chars()) && (0 < (port = portno_))) {
            network::endpoint* ep = new network::ip::v6::endpoint(host, port);
            return ep;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_client() {
        run_ = &Derives::client_run;
    }
    virtual void set_server() {
        run_ = &Derives::server_run;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_message(const char_t* to) {
        message_.assign(to);
    }
    virtual void set_message_file(const char_t* to) {
        message_file_name_.assign(to);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_host(const char_t* to) {
        host_.assign(to);
    }
    virtual void set_port(const char_t* to) {
        std::stringstream ss(to);
        int no;
        if (0 < (ss >> no)) {
            portno_ = no;
            port_.assign(to);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_family(const char_t* to) {
        if ((to) && (to[0])) {
            if (!((to[1]) || (XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_IPV4[1] != to[0]))
                || !(xos::base::chars_t::compare
                     (XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_IPV4+2, to))) {
                set_family_ip_v4();
            } else {
                if (!((to[1]) || (XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_IPV6[1] != to[0]))
                    || !(xos::base::chars_t::compare
                         (XOS_APP_CONSOLE_HELLO_MAIN_FAMILY_OPTARG_IPV6+2, to))) {
                    set_family_ip_v6();
                } else {
                }
            }
        }
    }
    virtual void set_transport(const char_t* to) {
        if (!((to[1]) || (XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTARG_TCP[1] != to[0]))
            || !(xos::base::chars_t::compare
                 (XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTARG_TCP+2, to))) {
            set_transport_tcp();
        } else {
            if (!((to[1]) || (XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTARG_UDP[1] != to[0]))
                || !(xos::base::chars_t::compare
                     (XOS_APP_CONSOLE_HELLO_MAIN_TRANSPORT_OPTARG_UDP+2, to))) {
                set_transport_udp();
            } else {
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_transport_tcp() {
        if ((&Derives::ip_v4_ep == ep_)) {
            tp_ = &Derives::ip_v4_tcp_tp;
        } else {
            if ((&Derives::ip_v6_ep == ep_)) {
                tp_ = &Derives::ip_v6_tcp_tp;
            } else {
            }
        }
    }
    virtual void set_transport_udp() {
        if ((&Derives::ip_v4_ep == ep_)) {
            tp_ = &Derives::ip_v4_udp_tp;
        } else {
            if ((&Derives::ip_v6_ep == ep_)) {
                tp_ = &Derives::ip_v6_udp_tp;
            } else {
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_family_ip_v4() {
        ep_ = &Derives::ip_v4_ep;
        if ((&Derives::ip_v4_tcp_tp == tp_) || (&Derives::ip_v6_tcp_tp == tp_)) {
            tp_ = &Derives::ip_v4_tcp_tp;
        } else {
            if ((&Derives::ip_v4_udp_tp == tp_) || (&Derives::ip_v6_udp_tp == tp_)) {
                tp_ = &Derives::ip_v4_udp_tp;
            } else {
            }
        }
    }
    virtual void set_family_ip_v6() {
        ep_ = &Derives::ip_v6_ep;
        if ((&Derives::ip_v4_tcp_tp == tp_) || (&Derives::ip_v6_tcp_tp == tp_)) {
            tp_ = &Derives::ip_v6_tcp_tp;
        } else {
            if ((&Derives::ip_v4_udp_tp == tp_) || (&Derives::ip_v6_udp_tp == tp_)) {
                tp_ = &Derives::ip_v6_udp_tp;
            } else {
            }
        }
    }
#include "xos/app/console/hello/main_opt.cpp"

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef int (Derives::*run_t)(int argc, char_t** argv, char_t** env);
    typedef network::endpoint* (Derives::*endpoint_t)();
    typedef network::transport* (Derives::*transport_t)();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    run_t run_;
    endpoint_t ep_;
    transport_t tp_;
    ushort portno_;
    string_t port_, host_,
             message_, message_send_separator_,
             message_send_suffix_, message_file_name_;
    char_t chars_[4096];
};

} // namespace hello 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_NADIR_XOS_APP_CONSOLE_HELLO_MAIN_HPP 
