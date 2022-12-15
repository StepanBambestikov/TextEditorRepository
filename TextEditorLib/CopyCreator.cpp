#include "CopyCreator.h"

CopyCreator::CopyCreator(CommandDTO dto) noexcept : DTO(std::move(dto)) {};

std::unique_ptr<UserCommand> CopyCreator::tryCreateUserCommand() const noexcept{
    if (!DTO.getIdx1() || !DTO.getIdx2()){
        return {};
    }
    return std::make_unique<Copy>(*DTO.getIdx1(), *DTO.getIdx2());
}

std::unique_ptr<ServiceCommand> CopyCreator::tryCreateServiceCommand() const noexcept{
    return {};
}