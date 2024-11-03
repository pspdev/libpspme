# Example executable
project(basicME)

# Collect source files for the example program
file(GLOB EXAMPLE_SOURCES *.c)

# Define the executable target
add_executable(basicME ${EXAMPLE_SOURCES})

# Link against the static library
target_link_libraries(basicME pspme_static)

# TODO: Copy the generated PRX pspme_prx module to the bin directory
# add_custom_command(
#     TARGET basicME POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:pspme_prx> ${CMAKE_BINARY_DIR}/bin
# )

# Set output name to "basicME.elf"
set_target_properties(basicME PROPERTIES OUTPUT_NAME "basicME")
target_include_directories(basicME PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Use create_pbp_file to generate a PBP file after building basicME.elf
create_pbp_file(
    TARGET basicME
    ICON_PATH NULL
    BACKGROUND_PATH NULL
    PREVIEW_PATH NULL
    TITLE "basicME"
)