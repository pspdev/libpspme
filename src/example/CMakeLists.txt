# Example executable
project(fooME)

# Collect source files for the example program
file(GLOB EXAMPLE_SOURCES *.c)

# Define the executable target
add_executable(fooME ${EXAMPLE_SOURCES})

# Link against the static library
target_link_libraries(fooME pspme_static)

# TODO: Copy the generated PRX pspme_prx module to the bin directory
# add_custom_command(
#     TARGET fooME POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:pspme_prx> ${CMAKE_BINARY_DIR}/bin
# )

# Set output name to "fooME.elf"
set_target_properties(fooME PROPERTIES OUTPUT_NAME "fooME")
target_include_directories(fooME PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Use create_pbp_file to generate a PBP file after building fooME.elf
create_pbp_file(
    TARGET fooME
    ICON_PATH NULL
    BACKGROUND_PATH NULL
    PREVIEW_PATH NULL
    TITLE "fooME"
)