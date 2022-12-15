#pragma once
#include "CreatorProvider.h"
#include "DTOProvider.h"
#include "CommandCreator.h"

class CreatorProviderFromDTO final : public CreatorProvider{
public:
    CreatorProviderFromDTO(std::unique_ptr<DTOProvider> _provider) noexcept;
    std::unique_ptr<CommandCreator> getCreator() noexcept override;
    [[nodiscard]] bool hasNext() const noexcept override;
private:
    std::unique_ptr<DTOProvider> provider;
};