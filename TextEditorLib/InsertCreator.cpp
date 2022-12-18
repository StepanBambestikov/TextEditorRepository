#include "InsertCreator.h"

InsertCreator::InsertCreator(const CommandDTO& dto) {
    if (dto.getCommandName() != Commands::INSERT || !dto.getString() || !dto.getIdx1()){
        throw InvalidDTOForInsertCreator();
    }
    position = *dto.getIdx1();
    string = *dto.getString();
}

std::unique_ptr<UserCommand> InsertCreator::tryCreateUserCommand() const noexcept{
    return std::make_unique<Insert>(string, position);
}

std::unique_ptr<ServiceCommand> InsertCreator::tryCreateServiceCommand() const noexcept{
    return {};
}

