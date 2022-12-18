#include "EditorBuffer.h"

EditorBuffer& EditorBuffer::getInstance(){
    static EditorBuffer buf;
    return buf;
}

void EditorBuffer::setString(StringBuffer newString){
    string = std::move(newString);
}

StringBuffer EditorBuffer::getString() const{
    return string;
}

