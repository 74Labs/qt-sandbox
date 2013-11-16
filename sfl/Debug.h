#pragma once

#include <iostream>

namespace sfl {

#ifdef NDEBUG
#define DEBUG_COUT(xxx)
#else
#define DEBUG_COUT(xxx) std::cout << "DEBUG: " << xxx << std::endl
#endif

}
