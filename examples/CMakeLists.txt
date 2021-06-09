include_directories("../include")
#include_directories("common")

# Setup MSVC parallelized builds
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Function to generate an example project with extra libraries
function (example_project_extra project_name source_code extra_libs)
    message("Adding new example project ${project_name}, sources: ${source_code}, extra_libs: ${extra_libs}")
    file (GLOB example_project_sources ${source_code} "common/*.h" "common/*.cc"  "common/*.cpp")
    add_executable(${project_name} ${example_project_sources})

    set_target_properties(${project_name} PROPERTIES FOLDER examples)

	if (MSCV AND (NOT (MSVC_VERSION LESS 1910)))
		target_link_libraries(${project_name} legacy_stdio_definitions)
	endif ()

    target_link_libraries(${project_name} dfapi ${extra_libs})
endfunction ()

# Function to generate a simple example project
function (example_project project_name source_code)
    example_project_extra(${project_name} ${source_code} "")
endfunction ()

example_project(bot_simple "bot_simple.cpp")
