#include "Delete.h"

Delete::Delete(size_t _begin, size_t _end) noexcept {
    begin = _begin;
    end = _end;
}

void Delete::redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer){
    deletedStr = str->getSubStringInRange(begin, end);
    str->deleteStringInRange(begin, end);
    positionOfDeleted = begin;
}

void Delete::undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer){
    if (!deletedStr.size()){
        return;
    }
    str->pasteInPosition(positionOfDeleted, deletedStr);
}


