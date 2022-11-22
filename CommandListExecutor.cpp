#pragma once
#include "CommandListExecutor.h"

CommandListExecutor::CommandListExecutor(const Parser& _commandList, const StringBuffer& _str) noexcept : commandList(_commandList){
    strPtr = std::make_shared<StringBuffer>(_str);
}

StringBuffer CommandListExecutor::runAllAndGetString(){
    using IteratorType = std::vector<std::string>::iterator;
    auto bufferPtr = std::make_shared<StringBuffer>();
    while(!commandList.eof()){
        auto args = commandList.getSplitString();
        if (!args){
            return *strPtr;
        }
        if (args.value().empty()){
            return *strPtr;
        }
        if (args.value()[0] == "redo"){
            editor.redo();
        }
        else if (args.value()[0] == "undo"){
            editor.undo();
        }
        else{
            try{
                auto creatorPtr = CommandCreator<IteratorType>::createCreator(args.value().begin(), args.value().end());
                if (*creatorPtr){
                    editor.addAndExecuteCommand(creatorPtr->createCommand(strPtr, bufferPtr));
                }
            }
            catch(...){
                continue;
            }
        }
    }
    return *strPtr;
}