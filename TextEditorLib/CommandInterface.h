#pragma once
#include <memory>
#include "StringBuffer.h"

class CommandInterface {
public:
    explicit CommandInterface(std::shared_ptr<StringBuffer> _strBuf) noexcept;
    virtual ~CommandInterface() = default;

    virtual void undo() = 0;
    virtual void redo() = 0;

protected:
    std::shared_ptr<StringBuffer> strBuf;
};