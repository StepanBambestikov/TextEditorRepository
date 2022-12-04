#pragma once
#include <string>
#include "CommandDTO.h"

class InsertDTO final : public CommandDTO{
public:
    InsertDTO(StringBuffer _str, size_t _position);
    [[nodiscard]] size_t getPosition() const;
    [[nodiscard]] StringBuffer getString() const;
private:
    StringBuffer str;
    size_t position;

    void unusedFunc() override{}
};