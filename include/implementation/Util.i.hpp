#include <cstdlib>  // std::exit, EXIT_FAILURE
#include <iostream> // std::cerr

namespace list {


[[noreturn]]
inline void error(const char* err) {
    std::cerr << "ERROR! -> " << err << std::endl;
    std::exit(EXIT_FAILURE);
}


} // namespace list