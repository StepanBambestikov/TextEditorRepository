#include "CommandProviderFromCreator.h"

void CommandProviderFromCreator::nextCreatorUpdate() noexcept {
    nextCreatorPtr = provider->getCreator();
}

CommandProviderFromCreator::CommandProviderFromCreator(std::unique_ptr<CreatorProvider> _provider) noexcept : provider(std::move(_provider)) {
    nextCreatorUpdate();
}


std::unique_ptr<UserCommand> CommandProviderFromCreator::tryGetUserCommand() noexcept {
    if (!nextCreatorPtr){
        return {};
    }
    auto commandPtr = nextCreatorPtr->tryCreateUserCommand();
    if (commandPtr){
        nextCreatorUpdate();
        return commandPtr;
    }
    return {};
}

std::unique_ptr<ServiceCommand> CommandProviderFromCreator::tryGetServiceCommand() noexcept {
    if (!nextCreatorPtr){
        return {};
    }
    auto commandPtr = nextCreatorPtr->tryCreateServiceCommand();
    if (commandPtr){
        nextCreatorUpdate();
        return commandPtr;
    }
    return {};
}