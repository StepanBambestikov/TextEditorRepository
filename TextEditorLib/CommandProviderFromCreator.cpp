#include "CommandProviderFromCreator.h"

CommandProviderFromCreator::CommandProviderFromCreator(std::unique_ptr<CreatorProvider> _provider) : provider(std::move(_provider)) {}

std::unique_ptr<CommandInterface> CommandProviderFromCreator::getCommand(){
    if (!provider->hasNext()){
        return{};
    }
    auto creatorPtr = provider->getCreator();
    if (creatorPtr){
        return creatorPtr->createCommand();
    }
    return {};
}

bool CommandProviderFromCreator::hasNext() const{
    return provider->hasNext();
}