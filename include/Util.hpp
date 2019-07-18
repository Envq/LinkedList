#pragma once


namespace list {


/**
 * @brief
 * @param[in] err
 */
[[noreturn]]
inline void error(const char* err);


} // namespace list

#include "implementation/Util.i.hpp"