#include "CreatorProviderFromDTO.h"

CreatorProviderFromDTO::CreatorProviderFromDTO(std::unique_ptr<DTOProvider> _provider) noexcept : provider(std::move(_provider)) {}

std::unique_ptr<CommandCreator> CreatorProviderFromDTO::getCreator() noexcept{
    auto DTOPtr = provider->getDTO();
    if (DTOPtr){
        return CommandCreator::createCreator(std::move(DTOPtr));
    }
    return {};
}