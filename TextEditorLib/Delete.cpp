#include "Delete.h"

Delete::Delete(size_t _begin, size_t _end) noexcept {
    begin = _begin;
    end = _end;
}

void Delete::redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) noexcept{
    deletedStr = str->getSubStringInRange(begin, end);
    str->deleteStringInRange(begin, end);
}

void Delete::undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) noexcept{
    if (!deletedStr.size()){
        return;
    }
    str->pasteInPosition(begin, deletedStr);
}


