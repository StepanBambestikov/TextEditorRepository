#pragma once
#include "CommandInterface.h"

CommandInterface::CommandInterface(std::shared_ptr<StringBuffer> _strBuf) noexcept : strBuf(std::move(_strBuf)){}


