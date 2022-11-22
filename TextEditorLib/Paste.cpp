#pragma once
#include "Paste.h"

Paste::Paste(std::shared_ptr<StringBuffer> _str, std::shared_ptr<StringBuffer> _buffer, size_t _position) : CommandInterface(std::move(_str)){
    if (_position > strBuf->size()){
        throw IncorrectArgumentsInPasteRedo();
    }
    position = _position;
    len = _buffer->size();
    bufferPtr = std::move(_buffer);
}

void Paste::redo(){
    strBuf->pasteInPosition(position, *bufferPtr);
    len = bufferPtr->size();
}

void Paste::undo(){
    if (len < position){
        return;
    }
    strBuf->deleteStringInRange(position, len + position);
}

