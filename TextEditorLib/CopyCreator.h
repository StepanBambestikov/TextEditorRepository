#pragma once
#include "CommandCreator.h"
#include "Copy.h"

#include <array>

class CopyCreator final : public CommandCreator{
public:
    CopyCreator(CopyDTO dto) noexcept;
    ~CopyCreator() noexcept override = default;

    [[nodiscard]] std::unique_ptr<CommandInterface> createCommand() const override;
private:
    CopyDTO DTO;
};