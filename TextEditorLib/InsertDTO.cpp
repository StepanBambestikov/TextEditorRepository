#include "InsertDTO.h"

InsertDTO::InsertDTO(StringBuffer _str, size_t _position) : str(std::move(_str)), position(_position) {}

size_t InsertDTO::getPosition() const{
    return position;
}
StringBuffer InsertDTO::getString() const{
    return str;
}