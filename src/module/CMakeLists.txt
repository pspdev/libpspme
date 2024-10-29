# PRX Module
project(pspme_prx)

# Collect source files for the PRX module
file(GLOB MODULE_SOURCES *.c)

# Define the PRX target
add_library(pspme_module MODULE ${MODULE_SOURCES})

# Set output name to "pspme.prx"
set_target_properties(pspme_module PROPERTIES OUTPUT_NAME "pspme")
target_include_directories(pspme_module PUBLIC ${CMAKE_SOURCE_DIR}/include)