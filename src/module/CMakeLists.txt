# PRX Module
project(pspme_prx)

# Collect source files for the PRX module
file(GLOB MODULE_SOURCES *.c)

# Find all .exp files in the directory
file(GLOB EXP_FILES *.exp)

add_prx_module(
    TARGET pspme_prx
    SRC_FILES ${MODULE_SOURCES}
    EXP_FILES ${EXP_FILES}
)

# Set output name to "pspme.prx"
set_target_properties(pspme_prx PROPERTIES OUTPUT_NAME "pspme")
target_include_directories(pspme_prx PUBLIC ${CMAKE_SOURCE_DIR}/include)
