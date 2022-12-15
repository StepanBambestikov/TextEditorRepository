#pragma once
#include "CommandCreator.h"
#include "Paste.h"


class PasteCreator final : public CommandCreator{
public:
    PasteCreator(CommandDTO ptr) noexcept;
    ~PasteCreator() noexcept override = default;

    [[nodiscard]] std::unique_ptr<UserCommand> tryCreateUserCommand() const noexcept override;
    [[nodiscard]] std::unique_ptr<ServiceCommand> tryCreateServiceCommand() const noexcept override;
private:
    CommandDTO DTO;
};
