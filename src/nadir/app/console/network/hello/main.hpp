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
///   File: main.hpp
///
/// Author: $author$
///   Date: 6/18/2017
///////////////////////////////////////////////////////////////////////
#ifndef _NADIR_APP_CONSOLE_NETWORK_HELLO_MAIN_HPP
#define _NADIR_APP_CONSOLE_NETWORK_HELLO_MAIN_HPP

#include "nadir/console/getopt/main.hpp"
#include "nadir/network/os/sockets.hpp"
#include "nadir/network/ip/v6/endpoint.hpp"
#include "nadir/network/ip/tcp/transport.hpp"
#include "nadir/base/array.hpp"

#ifndef _NADIR_APP_CONSOLE_NETWORK_MAIN_HPP
#define _NADIR_APP_CONSOLE_NETWORK_MAIN_HPP
#include "nadir/app/console/network/main_opt.hpp"
#endif // _NADIR_APP_CONSOLE_NETWORK_MAIN_HPP

namespace nadir {
namespace app {
namespace console {
namespace network {
namespace hello {

typedef nadir::console::getopt::maint_implements main_implements;
typedef nadir::console::getopt::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main()
    : client_request_("GET / HTTP/1.0\r\n\r\nHello"),
      server_response_("HTTP/1.0 200 Ok\r\n\r\nHello"),
      request_(1024), response_(1024),
      client_host_("localhost"), server_host_("localhost"),
      client_port_(80), server_port_(8080) {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int run(int argc, char_t **argv, char_t **env) {
        int err  = 0;
        try {
            nadir::network::os::sockets socks;
            err = run_tcp_server(argc, argv, env);
        } catch (const startup_exception& e) {
            const startup_status status = e.status();
            const char* status_chars = e.status_to_chars();
            LOG_ERROR("...caught const startup_exception& e = " << status << "\"" << status_chars << "\"")
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int run_tcp_server(int argc, char_t **argv, char_t **env) {
        int err  = 0;
        nadir::network::transport& tp = this->tp();
        nadir::network::endpoint& ep = this->ep();
        nadir::network::socket& sk = this->server_sk();

        if ((ep.attach(server_host_.has_chars(), server_port_))) {

            if ((sk.open(tp))) {

                if ((sk.listen(ep))) {
                    nadir::network::socket& cn = this->client_sk();
                    byte_array& rq = this->request();
                    char_string& rs = this->server_response();

                    if ((sk.accept(cn, ep))) {

                        if ((recv(rq, cn))) {
                            send(cn, rs);
                        }
                        cn.close();
                    }
                }
                sk.close();
            }
            ep.detach();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool send(nadir::network::socket& s, char_string& a) {
        const char* chars = 0; size_t length = 0;
        ssize_t count = 0, amount = 0;

        if ((chars = (a.chars())) && (0 < (length = a.length()))) {
            do {
                if (0 < (amount = s.send(chars, length, 0))) {
                    count += amount;
                } else {
                    break;
                }
            } while ((amount < length));
        }
        return true;
    }
    virtual bool recv(byte_array& a, nadir::network::socket& s) {
        byte_t* bytes = 0; size_t length = 0;
        ssize_t count = 0, amount = 0;

        if ((bytes = (a.elements())) && (1 < (length = a.length()))) {
            char* chars = (char*)bytes;
            size_t size = length-1;
            do {
                if (0 < (amount = s.recv(bytes, size, 0))) {
                    chars[amount] = 0;
                    count += amount;
                    LOG_DEBUG("...recved[" << amount << "] = \"" << chars << "\"");
                }
            } while ((amount == size));
        }
        return true;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual char_string& client_request() const {
        return (char_string&)client_request_;
    }
    virtual char_string& server_response() const {
        return (char_string&)server_response_;
    }
    virtual byte_array& request() const {
        return (byte_array&)request_;
    }
    virtual byte_array& response() const {
        return (byte_array&)response_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual nadir::network::socket& client_sk() const {
        return (nadir::network::socket&)client_sk_;
    }
    virtual nadir::network::socket& server_sk() const {
        return (nadir::network::socket&)server_sk_;
    }
    virtual nadir::network::endpoint& ep() const {
        return (nadir::network::endpoint&)ip4_ep_;
    }
    virtual nadir::network::transport& tp() const {
        return (nadir::network::transport&)tcp_tp_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    char_string client_request_, server_response_;
    char_string client_host_, server_host_;
    byte_array request_, response_;
    ushort client_port_, server_port_;
    nadir::network::ip::tcp::transport tcp_tp_;
    nadir::network::ip::v4::endpoint ip4_ep_;
    nadir::network::os::socket client_sk_, server_sk_;
};

} // namespace hello 
} // namespace network
} // namespace console 
} // namespace app 
} // namespace nadir 

#endif // _NADIR_APP_CONSOLE_NETWORK_HELLO_MAIN_HPP 
