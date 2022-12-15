#include "DeleteCreator.h"

DeleteCreator::DeleteCreator(CommandDTO dto) noexcept : DTO(std::move(dto)) {}

std::unique_ptr<UserCommand> DeleteCreator::tryCreateUserCommand() const noexcept{
    if (!DTO.getIdx1() || !DTO.getIdx2()){
        return {};
    }
    return std::make_unique<Delete>(*DTO.getIdx1(), *DTO.getIdx2());
}

std::unique_ptr<ServiceCommand> DeleteCreator::tryCreateServiceCommand() const noexcept{
    return {};
}
