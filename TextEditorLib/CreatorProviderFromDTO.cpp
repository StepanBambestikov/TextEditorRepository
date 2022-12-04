#include "CreatorProvider.h"

CreatorProvider::CreatorProvider(std::shared_ptr<DTOProviderFromParser> _provider) : provider(_provider) {}

std::unique_ptr<CommandCreator> CreatorProvider::getCreator(){
    if (!provider->hasNext()){
        return{};
    }
    auto DTOPtr = provider->getDTO();
    if (DTOPtr){
        return CommandCreator::createCreator(std::move(DTOPtr));
    }
    return {};
}

bool CreatorProvider::hasNext() const{
    return provider->hasNext();
}