#include "CommandListExecutor.h"

CommandListExecutor::CommandListExecutor(std::unique_ptr<CommandProvider> _provider, StringBuffer _str) noexcept
        : provider(std::move(_provider)), strPtr(std::make_shared<StringBuffer>(_str)), editor(strPtr){}

StringBuffer CommandListExecutor::runAllAndGetString(){
    while(provider->hasNext()){
        auto commandPtr = provider->getCommand();
        if (!commandPtr){
            continue;
        }
        if (dynamic_cast<Undo*>(commandPtr.get())){
            editor.undo();
        }
        else if (dynamic_cast<Redo*>(commandPtr.get())){
            editor.redo();
        }
        else{
            editor.addAndExecuteCommand(std::move(commandPtr));
        }
    }
    return *strPtr;
}