cmake_minimum_required(VERSION 3.21)
project(sfml-dpad LANGUAGES CXX)

# sfml-dpad uses C++11 features
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Compile target
set(SOURCE_FILES
    "src/main.cpp"
    "src/Button.hpp"
    "src/Button.cpp"
    "src/Directable.hpp"
    "src/Directable.cpp"
    "src/DirectionalPad.hpp"
    "src/DirectionalPad.cpp")
add_executable(sfml-dpad ${SOURCE_FILES})
target_link_libraries(sfml-dpad PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_compile_features(sfml-dpad PRIVATE cxx_std_11)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET sfml-dpad POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:sfml-dpad> $<TARGET_FILE_DIR:sfml-dpad> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS sfml-dpad)
