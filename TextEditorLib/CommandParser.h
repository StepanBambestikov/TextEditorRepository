#pragma once
#include <memory>

#include "InputStream.h"
#include "DTO.h"

std::unique_ptr<CommandDTO> parseStreamToDTO(InputStream stream);