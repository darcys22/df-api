# All the source files for the df api
file(GLOB sources_df "dfapi/*.cpp" "dfapi/*.cc" "../include/dfapi/*.h")

# Setup MSVC parallelized builds
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Create the library
add_library(dfapi ${sources_df})

set_target_properties(dfapi PROPERTIES DEBUG_POSTFIX "d")

include_directories("../include")

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd /ZI /Od" CACHE STRING "" FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT" CACHE STRING "" FORCE)
else()
    set(CMAKE_CXX_FLAGS "-fpermissive")  
endif()

if (MSVC)
    set_target_properties(dfapi PROPERTIES COMPILE_FLAGS "/W4 /WX")
endif (MSVC)

target_link_libraries (dfapi wallet-core)
