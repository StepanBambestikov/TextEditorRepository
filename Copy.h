#pragma once
#include "CommandInterface.h"

class Copy final : public CommandInterface{
public:
    Copy(std::shared_ptr<StringBuffer> str,std::shared_ptr<StringBuffer> _buffer, size_t _begin, size_t _end) noexcept;
    void undo() noexcept override;
    void redo() override;
private:
    std::shared_ptr<StringBuffer> bufferPtr;
    size_t begin;
    size_t end;
};


