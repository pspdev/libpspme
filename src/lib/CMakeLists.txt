# Static library
project(libpspme_lib)

# Collect source files for the static library
file(GLOB LIB_SOURCES *.c)

# Define the static library target
add_library(pspme_static STATIC ${LIB_SOURCES})

# Set output name to "libpspme.a"
set_target_properties(pspme_static PROPERTIES OUTPUT_NAME "pspme")
target_include_directories(pspme_static PUBLIC ${CMAKE_SOURCE_DIR}/include)