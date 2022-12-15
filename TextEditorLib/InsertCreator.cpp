#include "InsertCreator.h"

InsertCreator::InsertCreator(CommandDTO dto) noexcept : DTO(std::move(dto)) {}

std::unique_ptr<UserCommand> InsertCreator::tryCreateUserCommand() const noexcept{
    if (!DTO.getString() || !DTO.getIdx1()){
        return {};
    }
    return std::make_unique<Insert>(*DTO.getString(), *DTO.getIdx1());
}

std::unique_ptr<ServiceCommand> InsertCreator::tryCreateServiceCommand() const noexcept{
    return {};
}

