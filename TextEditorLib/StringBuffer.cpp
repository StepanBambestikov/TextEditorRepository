#include "StringBuffer.h"

StringBuffer::StringBuffer() noexcept = default;
StringBuffer::StringBuffer(std::string _str) noexcept : str(std::move(_str)){}

StringBuffer StringBuffer::getSubStringInRange(size_t begin, size_t end) const{
    if (begin > str.size()){
        throw IncorrectArgumentsGetStringInRange();
    }
    return StringBuffer(str.substr(begin, end - begin));
}

void StringBuffer::pasteInPosition(size_t position, const StringBuffer& strBuf){
    if (position > str.size()){
        throw IncorrectArgumentsPasteInPosition();
    }
    str.insert(position, strBuf.str);
}

void StringBuffer::deleteStringInRange(size_t begin, size_t end){
    if (begin > str.size()){
        throw IncorrectArgumentsdeleteStringInRange();
    }
    str.erase(begin, end - begin);
}

const std::string& StringBuffer::operator*() const noexcept{
    return str;
}

const std::string& StringBuffer::getString() const noexcept{
    return str;
}

size_t StringBuffer::size() const noexcept{
    return str.size();
}

