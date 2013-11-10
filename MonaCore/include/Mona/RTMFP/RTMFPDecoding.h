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
#include "Mona/Decoding.h"

namespace Mona {


class RTMFPDecoding : public Decoding, virtual Object {
public:
	RTMFPDecoding(const std::shared_ptr<Buffer<UInt8> >& pBuffer, TaskHandler& taskHandler) : Decoding(pBuffer, taskHandler) {}

	RTMFPEngine	  decoder;

private:
	bool		  decode(Exception& ex, MemoryReader& reader) { reader.next(4); return RTMFP::Decode(ex,decoder, reader); }

};



} // namespace Mona
