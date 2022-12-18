#include "Paste.h"

Paste::Paste(size_t _position) noexcept{
    position = _position;
}

void Paste::redo(std::shared_ptr<StringBuffer> str){
    auto& buf = EditorBuffer::getInstance();
    str->pasteInPosition(position, buf.getString());
    len = buf.getString().size();
}

void Paste::undo(std::shared_ptr<StringBuffer> str){
    str->deleteStringInRange(position, len + position);
}

