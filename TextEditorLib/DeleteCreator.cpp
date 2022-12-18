#include "DeleteCreator.h"

DeleteCreator::DeleteCreator(const CommandDTO& dto) {
    if (dto.getCommandName() != Commands::DELETE || !dto.getIdx1() || !dto.getIdx2()){
        throw InvalidDTOForDeleteCreator();
    }
    idx1 = *dto.getIdx1();
    idx2 = *dto.getIdx2();
}

std::unique_ptr<UserCommand> DeleteCreator::tryCreateUserCommand() const noexcept{
    return std::make_unique<Delete>(idx1, idx2);
}

std::unique_ptr<ServiceCommand> DeleteCreator::tryCreateServiceCommand() const noexcept{
    return {};
}
