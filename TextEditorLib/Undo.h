#pragma once
#include "CommandInterface.h"

class Undo final : public CommandInterface{
public:
    Undo() noexcept = default;
    void undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) override{}
    void redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) override{}
};