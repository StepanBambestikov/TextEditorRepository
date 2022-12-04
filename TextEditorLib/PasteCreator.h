#pragma once
#include "CommandCreator.h"
#include "Paste.h"


class PasteCreator final : public CommandCreator{
public:
    PasteCreator(PasteDTO ptr) noexcept;
    ~PasteCreator() noexcept override = default;

    [[nodiscard]] std::unique_ptr<CommandInterface> createCommand() const override;
private:
    PasteDTO DTO;
};
