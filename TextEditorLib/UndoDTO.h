#pragma once
#include "CommandDTO.h"

class UndoDTO final : public CommandDTO{
public:
    UndoDTO() = default;
private:
    void unusedFunc() override{}
};