/**
 * @file Util.i.hpp
 * @author Enrico Sgarbanti
 * @brief Implementation of methods for managing the utils for project
 * @version 1.0
 * @date 2019-07-25
 *
 * @copyright Copyright (c) 2019 Enrico Sgarbanti. All rights reserved.
 * @license GNU GPL v3
 *
 */

#pragma once

#include <cstdlib>  // std::exit, EXIT_FAILURE
#include <iostream> // std::cerr

/// @brief Namespace for list
namespace list {

[[noreturn]] inline void error(const char *err) {
    std::cerr << "ERROR! -> " << err << std::endl;
    std::exit(EXIT_FAILURE);
}

} // namespace list