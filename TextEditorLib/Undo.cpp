#include "Undo.h"

void Undo::redo(StringEditor& editor) const{
    editor.tryUndo();
}
