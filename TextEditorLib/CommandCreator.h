#pragma once
#include "CommandDTO.h"
#include "UserCommand.h"
#include "ServiceCommand.h"

class CopyCreator;
class PasteCreator;
class InsertCreator;
class DeleteCreator;
class UndoCreator;
class RedoCreator;

class CommandCreator {
public:
    static std::unique_ptr<CommandCreator> createCreator(std::unique_ptr<CommandDTO> _dtoPtr);
    CommandCreator() noexcept = default;
    virtual ~CommandCreator() noexcept = default;

    [[nodiscard]] virtual std::unique_ptr<UserCommand> tryCreateUserCommand() const = 0;
    [[nodiscard]] virtual std::unique_ptr<ServiceCommand> tryCreateServiceCommand() const = 0;
};
