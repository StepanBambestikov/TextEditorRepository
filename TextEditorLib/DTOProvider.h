#pragma once
#include "CommandDTO.h"
#include "memory"

class DTOProvider {
public:
    DTOProvider() = default;
    virtual ~DTOProvider() = default;
    virtual std::unique_ptr<CommandDTO> getDTO() = 0;
    virtual bool hasNext() const = 0;
};
