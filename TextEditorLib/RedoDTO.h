#pragma once
#include "CommandDTO.h"

class RedoDTO final : public CommandDTO{
public:
    RedoDTO() = default;
private:
    void unusedFunc() override{}
};