#include "UndoCreator.h"

UndoCreator::UndoCreator(const CommandDTO& dto) {
    if (dto.getCommandName() != Commands::UNDO){
        throw InvalidDTOForUndoCreator();
    }
}

std::unique_ptr<UserCommand> UndoCreator::tryCreateUserCommand() const noexcept{
    return {};
}
std::unique_ptr<ServiceCommand> UndoCreator::tryCreateServiceCommand() const noexcept{
    return std::make_unique<Undo>();
}