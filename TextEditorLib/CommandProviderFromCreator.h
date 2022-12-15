#pragma once
#include "CommandProvider.h"
#include "CreatorProvider.h"

class CommandProviderFromCreator final : public CommandProvider{
public:
    CommandProviderFromCreator(std::unique_ptr<CreatorProvider> _provider) noexcept ;
    std::unique_ptr<UserCommand> tryGetUserCommand() noexcept override;
    std::unique_ptr<ServiceCommand> tryGetServiceCommand() noexcept override;
    [[nodiscard]] bool hasNext() const noexcept override;
private:
    std::unique_ptr<CreatorProvider> provider;
    std::unique_ptr<CommandCreator> nextCreatorPtr;

    void nextCreatorUpdate() noexcept;
};
