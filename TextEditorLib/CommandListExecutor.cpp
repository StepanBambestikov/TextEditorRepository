#include "CommandListExecutor.h"

CommandListExecutor::CommandListExecutor(std::unique_ptr<CommandProvider> _provider) noexcept
        : provider(std::move(_provider)) {}

StringBuffer CommandListExecutor::runAllAndGetString(std::unique_ptr<StringEditor> editorPtr){
    while(true){
        auto userCommandPtr = provider->tryGetUserCommand();
        if (userCommandPtr){
            editorPtr->tryAddAndExecuteCommand(std::move(userCommandPtr));
        }
        else{
            auto serviceCommandPtr = provider->tryGetServiceCommand();
            if (serviceCommandPtr){
                serviceCommandPtr->redo(*editorPtr);
            }
            else{
                break;
            }
        }
    }
    return editorPtr->getString();
}