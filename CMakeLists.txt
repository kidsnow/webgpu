add_executable(App main.cpp)

cmake_minimum_required(VERSION 3.0...3.25)
project(
    LearnWebGPU
    VERSION 0.1.0
    LANGUAGES CXX C
)

set_target_properties(App PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNING_AS_ERROR ON
)

# show as many warnings as possible
if (MSVC)
    target_compile_options(App PRIVATE /W4)
else ()
    target_compile_options(App PRIVATE -Wall -Wextra -pedantic)
endif()

# generate only one scheme for the main target
# and enable frame capture for GPU debugging
if (XCODE)
    set_target_properties(App PROPERTIES
        XCODE_GENERATE_SCHEME ON
        XCODE_SCHEME_ENABLE_GPU_FRAME_CAPTURE_MODE "Metal"
    )
endif()

# target implementation of webgpu
add_subdirectory(webgpu_impl)
target_include_directories(App PRIVATE webgpu_impl/include)
target_link_libraries(App PRIVATE webgpu)
target_copy_webgpu_binaries(App)