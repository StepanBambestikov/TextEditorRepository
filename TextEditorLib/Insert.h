#pragma once
#include "CommandInterface.h"

class Insert final : public CommandInterface{
public:
    Insert(StringBuffer _strForInsert, size_t _position) noexcept;
    void undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) override;
    void redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) override;
private:
    StringBuffer strForInsert;
    size_t position;
    int positionOfInserted = { -1 };
};
