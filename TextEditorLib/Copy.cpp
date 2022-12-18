#include "Copy.h"

Copy::Copy(size_t _begin, size_t _end) noexcept{
    begin = _begin;
    end = _end;
}

void Copy::redo(std::shared_ptr<StringBuffer> str){
    auto& buf = EditorBuffer::getInstance();
    buf.setString(StringBuffer(str->getSubStringInRange(begin, end)));
}

void Copy::undo(std::shared_ptr<StringBuffer> str) noexcept{}

