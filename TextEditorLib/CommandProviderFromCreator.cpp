#include "CommandProviderFromCreator.h"

void CommandProviderFromCreator::nextCreatorUpdate() noexcept {
    if (provider->hasNext()){
        nextCreatorPtr = provider->getCreator();
    }
    else{
        nextCreatorPtr = {};
    }
}

CommandProviderFromCreator::CommandProviderFromCreator(std::unique_ptr<CreatorProvider> _provider) noexcept : provider(std::move(_provider)) {
    nextCreatorUpdate();
}


std::unique_ptr<UserCommand> CommandProviderFromCreator::tryGetUserCommand() noexcept {
    auto commandPtr = nextCreatorPtr->tryCreateUserCommand();
    if (commandPtr){
        nextCreatorUpdate();
        return commandPtr;
    }
    return {};
}

std::unique_ptr<ServiceCommand> CommandProviderFromCreator::tryGetServiceCommand() noexcept {
    auto commandPtr = nextCreatorPtr->tryCreateServiceCommand();
    if (commandPtr){
        nextCreatorUpdate();
        return commandPtr;
    }
    return {};
}

bool CommandProviderFromCreator::hasNext() const noexcept {
    return nextCreatorPtr || provider->hasNext();
}