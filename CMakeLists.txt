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

# Set output names based on platform
if(WIN32)
    set_target_properties(tgcrypto PROPERTIES
        PREFIX ""
        OUTPUT_NAME "tgcrypto"
        SUFFIX ".dll"
    )
    if(MSVC)
        # Set MSVC-specific flags
        target_compile_options(tgcrypto PRIVATE /W3 /O2)
    else()
        # Set MinGW flags
        target_compile_options(tgcrypto PRIVATE -Wall -O3)
    endif()
else()
    set_target_properties(tgcrypto PROPERTIES
        PREFIX "lib"
        OUTPUT_NAME "tgcrypto"
        SUFFIX ".so"
    )
    # Set GCC/Clang flags for Linux/macOS
    target_compile_options(tgcrypto PRIVATE -Wall -O3 -fPIC)
endif()

# Install rules
install(TARGETS tgcrypto
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)