#include "PasteDTO.h"

PasteDTO::PasteDTO(size_t _position) : position(_position) {}

size_t PasteDTO::getPosition() const{
    return position;
}
