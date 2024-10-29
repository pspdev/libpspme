# PRX Module
project(pspme_prx)

# Collect source files for the PRX module
file(GLOB MODULE_SOURCES *.c)

# Set BUILD_PRX variable to ON
set(BUILD_PRX ON)
set(PRX_EXPORTS exports.exp)

# TODO: Improve .cmake file to handle PRX exports

# # Define the PRX target
# add_executable(pspme_prx ${MODULE_SOURCES})

# # Set output name to "pspme.prx"
# set_target_properties(pspme_prx PROPERTIES OUTPUT_NAME "pspme")
# target_include_directories(pspme_prx PUBLIC ${CMAKE_SOURCE_DIR}/include)
