#pragma once
#include "Insert.h"

Insert::Insert(StringBuffer _strForInsert, size_t _position) noexcept {
    strForInsert = std::move(_strForInsert);
    position = _position;
}

void Insert::redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) noexcept{
    str->pasteInPosition(position, strForInsert);
    positionOfInserted = static_cast<int>(position);
}

void Insert::undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) noexcept{
    if (positionOfInserted == -1){
        return;
    }
    str->deleteStringInRange(positionOfInserted, positionOfInserted + strForInsert.size());
    positionOfInserted = -1;
}
