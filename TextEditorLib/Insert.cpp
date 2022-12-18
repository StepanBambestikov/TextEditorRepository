#pragma once
#include "Insert.h"

Insert::Insert(StringBuffer _strForInsert, size_t _position) noexcept {
    strForInsert = std::move(_strForInsert);
    position = _position;
}

void Insert::redo(std::shared_ptr<StringBuffer> str){
    str->pasteInPosition(position, strForInsert);
    insertHappened = true;
}

void Insert::undo(std::shared_ptr<StringBuffer> str){
    if (!insertHappened){
        return;
    }
    str->deleteStringInRange(position, position + strForInsert.size());
    insertHappened = false;
}
