#include "DeleteDTO.h"

DeleteDTO::DeleteDTO(size_t _idx1, size_t _idx2) : idx1(_idx1), idx2(_idx2) {}

size_t DeleteDTO::getIdx1() const{
    return idx1;
}
size_t DeleteDTO::getIdx2() const{
    return idx2;
}