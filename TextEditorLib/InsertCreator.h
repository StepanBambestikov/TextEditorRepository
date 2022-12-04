#pragma once
#include "CommandCreator.h"
#include "Insert.h"

class InsertCreator final : public CommandCreator{
public:
    InsertCreator(InsertDTO dto) noexcept;
    ~InsertCreator() noexcept override = default;

    [[nodiscard]] std::unique_ptr<CommandInterface> createCommand() const override;
private:
    InsertDTO DTO;
};
