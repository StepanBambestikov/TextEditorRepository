#pragma once
#include "CommandInterface.h"

class Paste final : public CommandInterface{
public:
    Paste(size_t _position);
    void undo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) override;
    void redo(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer) override;
private:
    size_t position;
    size_t len = { 0 };
};