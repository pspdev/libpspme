# PRX Module
project(pspme_prx)

# Collect source files for the PRX module
file(GLOB MODULE_SOURCES *.c)

# Find all .exp files in the directory
file(GLOB EXP_FILES *.exp)

# Initialize a list to store generated .c files
set(GENERATED_C_FILES)

# Loop over each .exp file to set up a rule to generate a corresponding .c file
foreach(EXP_FILE ${EXP_FILES})
    # Get the filename without extension
    get_filename_component(EXP_FILE_NAME ${EXP_FILE} NAME_WE)

    # Define the output .c file path
    set(GENERATED_C_FILE ${CMAKE_BINARY_DIR}/${EXP_FILE_NAME}.c)

    # Add a custom command for each .exp file to generate a .c file
    add_custom_command(
        OUTPUT ${GENERATED_C_FILE}
        COMMAND psp-build-exports -b ${EXP_FILE} > ${GENERATED_C_FILE}
        DEPENDS ${EXP_FILE}
        COMMENT "Generating ${GENERATED_C_FILE} from ${EXP_FILE}"
    )

    # Add the generated .c file to the list
    list(APPEND GENERATED_C_FILES ${GENERATED_C_FILE})
endforeach()

# Define the PRX target
add_executable(pspme_prx ${MODULE_SOURCES} ${GENERATED_C_FILES})
target_link_options(pspme_prx PRIVATE -Wl,-q,-T${PSPDEV}/psp/sdk/lib/linkfile.prx -nostartfiles -Wl,-zmax-page-size=128)

# Set output name to "pspme.prx"
set_target_properties(pspme_prx PROPERTIES OUTPUT_NAME "pspme")
target_include_directories(pspme_prx PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Add a post-build command to run psp-fixup-imports on the generated ELF file
add_custom_command(
    TARGET pspme_prx
    POST_BUILD
    COMMAND psp-fixup-imports $<TARGET_FILE:pspme_prx>
    COMMAND psp-prxgen $<TARGET_FILE:pspme_prx> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<TARGET_FILE_NAME:pspme_prx>.prx
    COMMENT "Running psp-fixup-imports and psp-prxgen on $<TARGET_FILE_NAME:pspme_prx>"
)
