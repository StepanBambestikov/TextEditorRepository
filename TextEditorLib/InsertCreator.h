#pragma once
#include "CommandCreator.h"
#include "Insert.h"

class InsertCreator final : public CommandCreator{
public:
    InsertCreator(const CommandDTO& dto);
    ~InsertCreator() noexcept override = default;

    [[nodiscard]] std::unique_ptr<UserCommand> tryCreateUserCommand() const noexcept override;
    [[nodiscard]] std::unique_ptr<ServiceCommand> tryCreateServiceCommand() const noexcept override;
private:
    StringBuffer string;
    size_t position;
};
