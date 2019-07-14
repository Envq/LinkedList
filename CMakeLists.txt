project(LinkedList)                         # project name
cmake_minimum_required(VERSION 3.5)         # minimum version
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)       # for clang-tidy


# Support for c++14
# CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
# if (COMPILER_SUPPORTS_CXX14)
#     add_compile_options("-std=c++14")
# else()
#     message(FATAL_ERROR "Compiler ${CMAKE_CXX_COMPILER} has no C++14 support.")
# endif()



# Options for compiler used
if (CMAKE_COMPILER_IS_GNUCXX)
    message(GCC)
elseif (CMAKE_COMPILER_ID EQUAL "Clang")
    message(Clang)
endif()



# Mode selected
if (CMAKE_BUILD_TYPE STREQUAL "release")
    add_compile_options("-O2")

elseif (CMAKE_BUILD_TYPE STREQUAL "debug")
    add_compile_options("-g")
    add_compile_options("-01")

    if (CMAKE_COMPILER_IS_GNUCXX)
        add_compile_options("-ggdb3")
    elseif (CMAKE_COMPILER_ID EQUAL "Clang")
        add_compile_options("-fsanitize=address")
        add_compile_options("-fno-omit-frame-pointer")
    endif()
endif()



# BUild
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(exe ${SRCS})



# CUSTOM TARGES
add_custom_target(  rm
                    COMMAND rm -rf *.o
                    COMMENT "Clear buld directory"
)



# TEST


