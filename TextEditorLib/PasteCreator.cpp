#include "PasteCreator.h"

PasteCreator::PasteCreator(PasteDTO dto) noexcept : DTO(std::move(dto)){}

std::unique_ptr<CommandInterface> PasteCreator::createCommand() const{
    return std::make_unique<Paste>(DTO.getPosition());
}
