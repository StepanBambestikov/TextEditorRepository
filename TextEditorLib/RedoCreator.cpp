#include "RedoCreator.h"

RedoCreator::RedoCreator(CommandDTO dto) noexcept {}

std::unique_ptr<UserCommand> RedoCreator::tryCreateUserCommand() const noexcept{
    return {};
}
std::unique_ptr<ServiceCommand> RedoCreator::tryCreateServiceCommand() const noexcept{
    return std::make_unique<Redo>();
}