#include "UndoCreator.h"

UndoCreator::UndoCreator(CommandDTO dto) noexcept {}

std::unique_ptr<UserCommand> UndoCreator::tryCreateUserCommand() const noexcept{
    return {};
}
std::unique_ptr<ServiceCommand> UndoCreator::tryCreateServiceCommand() const noexcept{
    return std::make_unique<Undo>();
}