#include "StringEditor.h"

StringEditor::StringEditor() noexcept = default;

void StringEditor::addAndExecuteCommand(std::shared_ptr<CommandInterface> cmdPtr){
    cmdPtr->redo();
    commands.emplace_back(std::move(cmdPtr));
    currentCmd = static_cast<int>(commands.size() - 1);
}

void StringEditor::undo(){
    if (currentCmd < 0){
        throw UndoEditorException();
    }
    commands[currentCmd]->undo();
    canceledCmd = commands[currentCmd];
    --currentCmd;
}

void StringEditor::redo(){
    if (canceledCmd){
        canceledCmd->redo();
    }
    canceledCmd.reset();
}