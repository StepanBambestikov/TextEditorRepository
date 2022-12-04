#pragma once
#include "CommandCreator.h"
#include "Delete.h"
#include <array>


class DeleteCreator final : public CommandCreator{
public:
    DeleteCreator(DeleteDTO dto) noexcept;
    ~DeleteCreator() override = default;

    [[nodiscard]] std::unique_ptr<CommandInterface> createCommand() const override;
private:
    DeleteDTO DTO;
};