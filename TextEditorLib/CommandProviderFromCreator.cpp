#include "CommandProvider.h"

CommandProvider::CommandProvider(std::shared_ptr<CreatorProvider> _provider) : provider(_provider) {}

std::unique_ptr<CommandInterface> CommandProvider::getCommand(){
    if (!provider->hasNext()){
        return{};
    }
    auto creatorPtr = provider->getCreator();
    if (creatorPtr){
        return creatorPtr->createCommand();
    }
    return {};
}

bool CommandProvider::hasNext() const{
    return provider->hasNext();
}