#include "CommandListExecutor.h"

CommandListExecutor::CommandListExecutor(std::unique_ptr<CommandProvider> _provider, StringBuffer _str) noexcept
        : provider(std::move(_provider)), strPtr(std::make_shared<StringBuffer>(std::move(_str))), editor(strPtr){}

StringBuffer CommandListExecutor::runAllAndGetString(){
    while(provider->hasNext()){
        auto userCommandPtr = provider->tryGetUserCommand();
        if (userCommandPtr){
            editor.addAndExecuteCommand(std::move(userCommandPtr));
        }
        else{
            auto serviceCommandPtr = provider->tryGetServiceCommand();
            if (serviceCommandPtr){
                serviceCommandPtr->redo(editor);
            }
            else{
                throw InvalidCreatorException();
            }
        }
    }
    return *strPtr;
}