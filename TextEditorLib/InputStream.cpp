#include "InputStream.h"

InputStream::InputStream(std::unique_ptr<std::istream> _is) : is(std::move(_is)) {}