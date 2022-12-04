#pragma once
#include "CommandProvider.h"
#include "CreatorProvider.h"

class CommandProviderFromCreator : public CommandProvider{
public:
    CommandProviderFromCreator(std::unique_ptr<CreatorProvider> _provider);
    virtual std::unique_ptr<CommandInterface> getCommand() override;
    virtual bool hasNext() const override;
private:
    std::unique_ptr<CreatorProvider> provider;
};
