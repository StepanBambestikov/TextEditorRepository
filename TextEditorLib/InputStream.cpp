#include "InputStream.h"

InputStream::InputStream(std::unique_ptr<std::istream> _is) noexcept : is(std::move(_is)) {}