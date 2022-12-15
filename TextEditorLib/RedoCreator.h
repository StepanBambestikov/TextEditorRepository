#pragma once
#include "CommandCreator.h"
#include "Redo.h"

class RedoCreator final : public CommandCreator{
public:
    RedoCreator(CommandDTO dto) noexcept;
    ~RedoCreator() noexcept override = default;

    [[nodiscard]] std::unique_ptr<UserCommand> tryCreateUserCommand() const noexcept override;
    [[nodiscard]] std::unique_ptr<ServiceCommand> tryCreateServiceCommand() const noexcept override;
};