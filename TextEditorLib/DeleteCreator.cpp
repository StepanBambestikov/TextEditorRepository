#include "DeleteCreator.h"

DeleteCreator::DeleteCreator(DeleteDTO dto) noexcept : DTO(std::move(dto)) {}

std::unique_ptr<CommandInterface> DeleteCreator::createCommand() const{
    return std::make_unique<Delete>(DTO.getIdx1(), DTO.getIdx2());
}
