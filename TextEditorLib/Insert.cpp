#pragma once
#include "Insert.h"

Insert::Insert(std::shared_ptr<StringBuffer> str,StringBuffer _strForInsert, size_t _position) noexcept : CommandInterface(std::move(str)){
    strForInsert = std::move(_strForInsert);
    position = _position;
}

void Insert::redo(){
    strBuf->pasteInPosition(position, strForInsert);
    positionOfInserted = static_cast<int>(position);
}

void Insert::undo(){
    if (positionOfInserted == -1){
        return;
    }
    strBuf->deleteStringInRange(positionOfInserted, positionOfInserted + strForInsert.size());
}
