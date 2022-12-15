#include "Paste.h"

Paste::Paste(size_t _position) noexcept{
    position = _position;
}

void Paste::redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) noexcept{
    str->pasteInPosition(position, *_buffer);
    len = _buffer->size();
}

void Paste::undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) noexcept{
    str->deleteStringInRange(position, len + position);
}

