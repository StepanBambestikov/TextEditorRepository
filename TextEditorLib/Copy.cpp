#pragma once
#include "Copy.h"

Copy::Copy(std::shared_ptr<StringBuffer> _str,std::shared_ptr<StringBuffer> _buffer, size_t _begin, size_t _end) noexcept
: CommandInterface(std::move(_str)){
    begin = _begin;
    end = _end;
    bufferPtr = std::move(_buffer);
}

void Copy::redo(){
    *bufferPtr = StringBuffer(strBuf->getStringInRange(begin, end));
}

void Copy::undo() noexcept{}

