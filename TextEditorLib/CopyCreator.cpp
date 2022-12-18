#include "CopyCreator.h"

CopyCreator::CopyCreator(const CommandDTO& dto) {
    if (dto.getCommandName() != Commands::COPY || !dto.getIdx1() || !dto.getIdx2()){
        throw InvalidDTOForCopyCreator();
    }
    idx1 = *dto.getIdx1();
    idx2 = *dto.getIdx2();
}


std::unique_ptr<UserCommand> CopyCreator::tryCreateUserCommand() const noexcept{
    return std::make_unique<Copy>(idx1, idx2);
}

std::unique_ptr<ServiceCommand> CopyCreator::tryCreateServiceCommand() const noexcept{
    return {};
}