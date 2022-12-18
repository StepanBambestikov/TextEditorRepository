#include "StringEditor.h"

StringEditor::StringEditor(std::unique_ptr<StringBuffer> _str) noexcept
: str(std::move(_str)) {}

StringBuffer StringEditor::getString() const{
    return *str;
}

bool StringEditor::tryAddAndExecuteCommand(std::unique_ptr<UserCommand> cmdPtr){
    if (!cmdPtr){
        throw NullPtrCommandException();
    }
    try{
        cmdPtr->redo(str);
        commands.emplace_back(std::move(cmdPtr));
        canceledCmd.reset();
        return true;
    }
    catch (CommandException& except){
        return false;
    }
    catch (StringBufferException& except){
        return false;
    }
}

bool StringEditor::tryUndo(){
    if (commands.empty()){
        throw UndoEditorException();
    }
    try{
        commands.back()->undo(str);
        canceledCmd = std::move(commands.back());
        commands.pop_back();
        return true;
    }
    catch (CommandException& except){
        return false;
    }
    catch (StringBufferException& except){
        return false;
    }
}

bool StringEditor::tryRedo(){
    if (!canceledCmd){
        throw RedoEditorException();
    }
    try{
        canceledCmd->redo(str);
        commands.push_back(std::move(canceledCmd));
        return true;
    }
    catch (CommandException& except){
        return false;
    }
    catch (StringBufferException& except){
        return false;
    }
}