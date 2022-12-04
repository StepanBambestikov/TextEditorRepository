#include "StringEditor.h"

StringEditor::StringEditor(std::shared_ptr<StringBuffer> _str) noexcept
: str(_str) {}

bool StringEditor::addAndExecuteCommand(std::unique_ptr<CommandInterface> cmdPtr){
    try{
        cmdPtr->redo(str, buffer);
        commands.emplace_back(std::move(cmdPtr));
        canceledCmd.reset();
        return true;
    }
    catch (CommandException& except){
        return false;
    }
}

bool StringEditor::undo(){
    if (commands.empty()){
        throw UndoEditorException();
    }
    try{
        commands.back()->undo(str, buffer);
        canceledCmd = std::move(commands.back());
        commands.pop_back();
        return true;
    }
    catch (CommandException& except){
        return false;
    }
}

bool StringEditor::redo(){
    if (!canceledCmd){
        throw RedoEditorException();
    }
    try{
        canceledCmd->redo(str, buffer);
        commands.push_back(std::move(canceledCmd));
        return true;
    }
    catch (CommandException& except){
        return false;
    }
}

//TODO try is bad!