cmake_minimum_required(VERSION 3.4) 
option(BUILD_API_EXAMPLES "Build Examples" ON)
option(BUILD_API_TESTS "Build Tests" ON)
project(df-api)


message(STATUS "COMPILER_ID=${CMAKE_CXX_COMPILER_ID}")
if (UNIX)
  if (NOT DEFINED ENV{CC})
    find_program(CMAKE_C_COMPILER clang-10 clang)
  endif ()
  if (NOT DEFINED ENV{CXX})
    find_program(CMAKE_CXX_COMPILER clang++-10 clang++)
  endif ()
endif ()

message(STATUS "COMPILER_ID=${CMAKE_CXX_COMPILER_ID}")
# Use bin as the directory for all executables.
# This will make protoc easy to find.
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Windows builds subdirectories Debug/Release.
# These variables will overwrite that and put binaries in bin.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${PROJECT_BINARY_DIR}/bin)

add_compile_options (-Werror=switch)

# Build with c++14 support.
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${PLATFORM_LINK_FLAGS}")

# Disable default libraries in visual studio
if (MSVC)
    # Default to statically-linked runtime.
    if("${MSVC_RUNTIME}" STREQUAL "")
        set(MSVC_RUNTIME "static")
    endif()

    # Set compiler options.
    set(variables
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_MINSIZEREL
        CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_RELWITHDEBINFO
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_MINSIZEREL
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_RELWITHDEBINFO
    )
    if(${MSVC_RUNTIME} STREQUAL "static")
        message(STATUS
          "MSVC -> forcing use of statically-linked runtime."
        )
        foreach(variable ${variables})
            if(${variable} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
            endif()
        endforeach()
    else()
        message(STATUS
            "MSVC -> forcing use of dynamically-linked runtime."
        )
        foreach(variable ${variables})
            if(${variable} MATCHES "/MT")
                string(REGEX REPLACE "/MT" "/MD" ${variable} "${${variable}}")
            endif()
        endforeach()
    endif()
endif ()

# Allow creating filters for projects in visual studio.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory("external")
add_subdirectory("src")

if (BUILD_API_EXAMPLES)
    add_subdirectory("examples")
endif ()

if (BUILD_API_TESTS)
    add_subdirectory("tests")
endif ()
