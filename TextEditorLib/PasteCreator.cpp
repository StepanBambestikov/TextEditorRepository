#include "PasteCreator.h"

PasteCreator::PasteCreator(const CommandDTO& dto){
    if (dto.getCommandName() != Commands::PASTE || !dto.getIdx1()){
        throw InvalidDTOForPasteCreator();
    }
    position = *dto.getIdx1();
}

std::unique_ptr<UserCommand> PasteCreator::tryCreateUserCommand() const noexcept{
    return std::make_unique<Paste>(position);
}

std::unique_ptr<ServiceCommand> PasteCreator::tryCreateServiceCommand() const noexcept{
    return {};
}
