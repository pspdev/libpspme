cmake_minimum_required(VERSION 3.0)
project(libpspme)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/module)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories for each component
add_subdirectory(src/lib)         # Static library
add_subdirectory(src/module)      # PRX module
add_subdirectory(src/example)     # Example program