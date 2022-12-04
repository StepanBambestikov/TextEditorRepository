#include "InsertCreator.h"

InsertCreator::InsertCreator(InsertDTO dto) noexcept : DTO(std::move(dto)) {}

std::unique_ptr<CommandInterface> InsertCreator::createCommand() const{
    return std::make_unique<Insert>(DTO.getString(), DTO.getPosition());
}
