#include "CreatorProviderFromDTO.h"

CreatorProviderFromDTO::CreatorProviderFromDTO(std::unique_ptr<DTOProvider> _provider) : provider(std::move(_provider)) {}

std::unique_ptr<CommandCreator> CreatorProviderFromDTO::getCreator(){
    if (!provider->hasNext()){
        return{};
    }
    auto DTOPtr = provider->getDTO();
    if (DTOPtr){
        return CommandCreator::createCreator(std::move(DTOPtr));
    }
    return {};
}

bool CreatorProviderFromDTO::hasNext() const{
    return provider->hasNext();
}