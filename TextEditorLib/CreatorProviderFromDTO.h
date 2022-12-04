#pragma once
#include "CreatorProvider.h"
#include "DTOProvider.h"
#include "CommandCreator.h"

class CreatorProviderFromDTO final : public CreatorProvider{
public:
    CreatorProviderFromDTO(std::unique_ptr<DTOProvider> _provider);
    std::unique_ptr<CommandCreator> getCreator() override;
    [[nodiscard]] bool hasNext() const override;
private:
    std::unique_ptr<DTOProvider> provider;
};