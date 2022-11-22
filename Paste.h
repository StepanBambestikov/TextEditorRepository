#pragma once
#include "CommandInterface.h"

class Paste final : public CommandInterface{
public:
    Paste(std::shared_ptr<StringBuffer> _str, std::shared_ptr<StringBuffer> _buffer, size_t _position);
    void undo() override;
    void redo() override;
private:
    std::shared_ptr<StringBuffer> bufferPtr;
    size_t position;
    size_t len;
};