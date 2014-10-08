/*************************************************************************
 * libjson-rpc-cpp
 *************************************************************************
 * @file    httpclient.h
 * @date    02.01.2013
 * @author  Peter Spiess-Knafl <peter.knafl@gmail.com>
 * @license See attached LICENSE.txt
 ************************************************************************/

#ifndef JSONRPC_CPP_HTTPCLIENT_H_
#define JSONRPC_CPP_HTTPCLIENT_H_

#include "../abstractclientconnector.h"
#include <jsonrpccpp/common/exception.h>
#include <map>

namespace jsonrpc
{
    class HttpClient : public AbstractClientConnector
    {
        public:
            HttpClient(const std::string& url) throw (JsonRpcException);

            virtual void SendRPCMessage(const std::string& message, std::string& result) throw (JsonRpcException);

            void SetUrl(const std::string& url);

            void AddHeader(const std::string attr, const std::string val);
            void RemoveHeader(const std::string attr);

        private:
            std::map<std::string,std::string> headers;
            std::string url;
    };

} /* namespace jsonrpc */
#endif /* JSONRPC_CPP_HTTPCLIENT_H_ */
