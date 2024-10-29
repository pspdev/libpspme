# Example executable
project(fooME)

# Collect source files for the example program
file(GLOB EXAMPLE_SOURCES *.c)

# Define the executable target
add_executable(fooME ${EXAMPLE_SOURCES})

# Link against the static library and the module
target_link_libraries(fooME pspme_static pspme_module)

# Set output name to "fooME.elf"
set_target_properties(fooME PROPERTIES OUTPUT_NAME "fooME")
target_include_directories(fooME PRIVATE ${CMAKE_SOURCE_DIR}/include)