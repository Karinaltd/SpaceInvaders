cmake_minimum_required(VERSION 3.16)
project(MySFMLProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the executable output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Add the src folder as the source directory
file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
add_executable(MySFMLProject ${SRC_FILES})

set(SFML_DIR "C:/SFML/lib/cmake/SFML")

# Find SFML (Modify the path if SFML is not in default locations)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Link SFML libraries
target_link_libraries(MySFMLProject sfml-system sfml-window sfml-graphics)

if (WIN32)
    # Path to SFML DLLs (update this to your actual SFML/bin directory)
    set(SFML_DLL_DIR "C:/SFML/bin")

    # Glob all the DLLs in the SFML bin folder
    file(GLOB SFML_DLLS "${SFML_DLL_DIR}/*.dll")

    # Copy each DLL to the build directory
    foreach(DLL ${SFML_DLLS})
        add_custom_command(TARGET MySFMLProject POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${DLL} $<TARGET_FILE_DIR:MySFMLProject>)
    endforeach()
endif()
