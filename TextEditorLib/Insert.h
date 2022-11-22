#pragma once
#include "CommandInterface.h"

class Insert final : public CommandInterface{
public:
    Insert(std::shared_ptr<StringBuffer> str, StringBuffer _strForInsert, size_t position) noexcept;
    void undo() override;
    void redo() override;
private:
    StringBuffer strForInsert;
    size_t position;
    int positionOfInserted = { -1 };
};
