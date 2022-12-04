#pragma once
#include "CommandCreator.h"
#include "Redo.h"

class RedoCreator final : public CommandCreator{
public:
    RedoCreator(RedoDTO dto) noexcept;
    ~RedoCreator() noexcept override = default;

    [[nodiscard]] std::unique_ptr<CommandInterface> createCommand() const override;
private:
    RedoDTO DTO;
};