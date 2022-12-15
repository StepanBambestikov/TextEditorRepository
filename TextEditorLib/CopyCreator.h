#pragma once
#include "CommandCreator.h"
#include "Copy.h"

#include <array>

class CopyCreator final : public CommandCreator{
public:
    CopyCreator(CommandDTO dto) noexcept;
    ~CopyCreator() noexcept override = default;
    [[nodiscard]] std::unique_ptr<UserCommand> tryCreateUserCommand() const noexcept override;
    [[nodiscard]] std::unique_ptr<ServiceCommand> tryCreateServiceCommand() const noexcept override;
private:
    CommandDTO DTO;
};