#pragma once
#include "CommandCreator.h"
#include "Delete.h"
#include <array>


class DeleteCreator final : public CommandCreator{
public:
    DeleteCreator(CommandDTO dto) noexcept;
    ~DeleteCreator() noexcept override = default;

    [[nodiscard]] std::unique_ptr<UserCommand> tryCreateUserCommand() const noexcept override;
    [[nodiscard]] std::unique_ptr<ServiceCommand> tryCreateServiceCommand() const noexcept override;
private:
    CommandDTO DTO;
};