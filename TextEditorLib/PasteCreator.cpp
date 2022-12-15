#include "PasteCreator.h"

PasteCreator::PasteCreator(CommandDTO dto) noexcept : DTO(std::move(dto)){}

std::unique_ptr<UserCommand> PasteCreator::tryCreateUserCommand() const noexcept{
    if (!DTO.getIdx1()){
        return {};
    }
    return std::make_unique<Paste>(*DTO.getIdx1());
}

std::unique_ptr<ServiceCommand> PasteCreator::tryCreateServiceCommand() const noexcept{
    return {};
}
