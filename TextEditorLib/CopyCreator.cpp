#include "CopyCreator.h"

CopyCreator::CopyCreator(CopyDTO dto) noexcept : DTO(std::move(dto)) {};

std::unique_ptr<CommandInterface> CopyCreator::createCommand() const{
    return std::make_unique<Copy>(DTO.getIdx1(), DTO.getIdx2());
}