project(List)                               # project name
cmake_minimum_required(VERSION 3.5)         # minimum version
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)       # for clang-tidy

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_EXTENSIONS)

set(MY_PROJECT_FILES
    include/*.hpp
    include/implementation/*.i.hpp
    src/*.cpp
)


# Options for compiler used
if (CMAKE_COMPILER_IS_GNUCXX)
    message(GCC)
elseif (CMAKE_COMPILER_ID EQUAL "Clang")
    message(Clang)
endif()


# Compile options
add_compile_options("-Wall")
add_compile_options("-Wextra")
add_compile_options("-Wpedantic")
add_compile_options("-Werror")


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


# Build
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)
STRING(TOLOWER "${PROJECT_NAME}" exec_name)
add_executable(${exec_name} ${SRCS})


# Test


# Install
add_custom_target(  install-lib
                    COMMAND mkdir -p ${PROJECT_SOURCE_DIR}/bin/
                    COMMAND mv ${PROJECT_SOURCE_DIR}/build/${exec_name} ${PROJECT_SOURCE_DIR}/bin/
                    COMMENT "Create executable"
)


# Clean
add_custom_target(  clean-all
                    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/build/*
                    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/doc
                    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/bin
                    COMMENT "Clean build, bin and doc directory"
)


# Cloc stats
find_program(CLOC_FOUND cloc)
if (CLOC_FOUND)
    add_custom_target(stats
                    COMMAND cloc   ${PROJECT_SOURCE_DIR}/src
                                   ${PROJECT_SOURCE_DIR}/include
                                   ${PROJECT_SOURCE_DIR}/test
                    COMMENT "Code statistics"
    )
endif()


# Lyzard stats
find_program(LYZARD_FOUND lizard)
if (LYZARD_FOUND)
    add_custom_target(cyclo
                    COMMAND lizard ${PROJECT_SOURCE_DIR}/src/
                                     ${PROJECT_SOURCE_DIR}/include/
                    COMMENT "Code Complexity")
endif()


# Doxygen
find_program(DOXYGEN_FOUND doxygen)
if (DOXYGEN_FOUND)
    add_custom_target(doc
                    COMMAND mkdir -p ${PROJECT_SOURCE_DIR}/doc/
                    COMMAND doxygen ${PROJECT_SOURCE_DIR}/doxygen.cfg
                    COMMENT "Create code documentation")
endif()


# Clang-format
find_program(CLANG-FORMAT_FOUND clang-format)
if (CLANG-FORMAT_FOUND)
    add_custom_target(format
                    COMMAND clang-format -i ${PROJECT_SOURCE_DIR}/include/*.hpp
                    COMMAND clang-format -i ${PROJECT_SOURCE_DIR}/include/implementation/*.i.hpp
                    COMMAND clang-format -i ${PROJECT_SOURCE_DIR}/src/*.cpp
                    COMMENT "Do clang format")
endif()


# Clang-tidy
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    find_program(SCANBUILD_FOUND scan-build)
    if (SCANBUILD_FOUND)
        add_custom_target(scan
                          COMMAND make clean
                          COMMAND scan-build make
                          COMMENT "Do scan-build Static Analysis")
    endif()

    find_program(CLANGTIDY_FOUND clang-tidy)
    if (CLANGTIDY_FOUND)
        add_custom_target(tidy
                          COMMAND clang-tidy -p=.
                                  ../src/*.cpp ../test/*.cpp
                          COMMENT "Do clang-tidy Linter")
    endif()
endif()