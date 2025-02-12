cmake_minimum_required(VERSION 3.10)
project(tgcrypto C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set default build type to Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Create shared library
add_library(tgcrypto SHARED
    tgcrypto.c
    aes256.c
    ige256.c
    ctr256.c
    cbc256.c
)

# Include directories
target_include_directories(tgcrypto PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Platform-specific settings
if(WIN32)
    set_target_properties(tgcrypto PROPERTIES
        PREFIX ""
        SUFFIX ".pyd"  # Use .pyd instead of .dll for Python compatibility
    )
    if(MSVC)
        target_compile_options(tgcrypto PRIVATE /W3 /O2)
    else()
        target_compile_options(tgcrypto PRIVATE -Wall -O3)
    endif()
else()
    set_target_properties(tgcrypto PROPERTIES
        PREFIX ""  # Remove 'lib' prefix
        SUFFIX ".so"
    )
    target_compile_options(tgcrypto PRIVATE -Wall -O3 -fPIC)
endif()

# Install rules
install(TARGETS tgcrypto
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib)
