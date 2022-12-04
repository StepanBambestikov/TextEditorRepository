#include "UndoCreator.h"

UndoCreator::UndoCreator(UndoDTO dto) noexcept {}

std::unique_ptr<CommandInterface> UndoCreator::createCommand() const{
    return std::make_unique<Undo>();
}