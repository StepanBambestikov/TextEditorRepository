#include "Redo.h"

void Redo::redo(StringEditor& editor) const noexcept{
    editor.tryRedo();
}
