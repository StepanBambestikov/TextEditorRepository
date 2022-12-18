#pragma once
#include "CommandCreator.h"
#include "Undo.h"

class UndoCreator final : public CommandCreator{
public:
    UndoCreator(const CommandDTO& dto);
    ~UndoCreator() noexcept override = default;

    [[nodiscard]] std::unique_ptr<UserCommand> tryCreateUserCommand() const noexcept override;
    [[nodiscard]] std::unique_ptr<ServiceCommand> tryCreateServiceCommand() const noexcept override;
};