#pragma once
#include "StringBuffer.h"

class EditorBuffer final{
public:
    static EditorBuffer& getInstance();
    void setString(StringBuffer newString);
    [[nodiscard]] StringBuffer getString() const;

    EditorBuffer(const EditorBuffer&) = delete;
    void operator=(const EditorBuffer&) = delete;
private:
    StringBuffer string;

    EditorBuffer() = default;
};