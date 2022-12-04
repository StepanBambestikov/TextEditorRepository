#pragma once
#include "DTO.h"
#include "CommandInterface.h"

class CopyCreator;
class PasteCreator;
class InsertCreator;
class DeleteCreator;
class UndoCreator;
class RedoCreator;

class CommandCreator {
public:
    static std::unique_ptr<CommandCreator> createCreator(std::unique_ptr<CommandDTO> _DTOptr);
    CommandCreator() = default;
    virtual ~CommandCreator() = default;

    [[nodiscard]] virtual std::unique_ptr<CommandInterface> createCommand() const = 0;
};
