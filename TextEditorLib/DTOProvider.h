#pragma once
#include "CommandDTO.h"
#include "memory"

class DTOProvider {
public:
    DTOProvider() noexcept = default;
    virtual ~DTOProvider() noexcept = default;
    virtual std::unique_ptr<CommandDTO> getDTO() = 0;
};
