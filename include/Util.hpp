/**
 * @file Util.hpp
 * @author Enrico Sgarbanti
 * @brief Utils for project
 * @version 1.0
 * @date 2019-07-25
 *
 * @copyright Copyright (c) 2019 Enrico Sgarbanti. All rights reserved.
 * @license GNU GPL v3
 *
 */

#pragma once

/// @brief Namespace for list
namespace list {

/**
 * @brief Print the error
 * @param err: Text of the error
 */
[[noreturn]] inline void error(const char *err);

} // namespace list
#include "implementation/Util.i.hpp"