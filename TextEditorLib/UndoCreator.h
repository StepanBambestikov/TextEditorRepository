#pragma once
#include "CommandCreator.h"
#include "Undo.h"

class UndoCreator final : public CommandCreator{
public:
    UndoCreator(UndoDTO dto) noexcept;
    ~UndoCreator() noexcept override = default;

    [[nodiscard]] std::unique_ptr<CommandInterface> createCommand() const override;
private:
    UndoDTO DTO;
};