#include "RedoCreator.h"

RedoCreator::RedoCreator(RedoDTO dto) noexcept {}

std::unique_ptr<CommandInterface> RedoCreator::createCommand() const{
    return std::make_unique<Redo>();
}