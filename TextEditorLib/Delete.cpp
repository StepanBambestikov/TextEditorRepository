#pragma once
#include "Delete.h"

Delete::Delete(std::shared_ptr<StringBuffer> str, size_t _begin, size_t _end) noexcept : CommandInterface(std::move(str)){
    begin = _begin;
    end = _end;
}

void Delete::redo(){
    deletedStr = strBuf->getStringInRange(begin, end);
    strBuf->deleteStringInRange(begin, end);
    positionOfDeleted = begin;
}

void Delete::undo(){
    if (!deletedStr.size()){
        return;
    }
    strBuf->pasteInPosition(positionOfDeleted, deletedStr);
}


