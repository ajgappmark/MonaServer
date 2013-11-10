/* 
	Copyright 2013 Mona - mathieu.poux[a]gmail.com
 
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License received along this program for more
	details (or else see http://www.gnu.org/licenses/).

	This file is a part of Mona.
*/

#pragma once

#include "Mona/Mona.h"
#include "Mona/Protocol.h"
#include "Mona/TCPServer.h"
#include "Mona/Logs.h"

namespace Mona {


class TCProtocol :public Protocol, protected TCPServer , virtual Object {
public:
	bool load(Exception& ex, const ProtocolParams& params);

protected:
	TCProtocol(const char* name, Invoker& invoker, Sessions& sessions) : TCPServer(invoker.sockets), Protocol(name, invoker, sessions) {}
	virtual ~TCProtocol() {stop();}


private:

	void	onError(const std::string& error) { WARN("Protocol ", name, ", ", error); }

	bool    onConnection(const SocketAddress& address) { return auth(address); }
};

inline bool TCProtocol::load(Exception& ex, const ProtocolParams& params) {
	SocketAddress address;
	if (!address.set(ex, params.host, params.port))
		return false;
	return start(ex, address);
}


} // namespace Mona
