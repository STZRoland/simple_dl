# Add all the subdirectories
add_subdirectory(src/simple_dl/TestDir)

# Create the main library with the files
add_library(simple_dl
        src/simple_dl/simple_dl.h
        src/simple_dl/simple_dl.cpp
)
target_include_directories(simple_dl PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Link the sub folder libraries with the main library
target_link_libraries(simple_dl PUBLIC TestDir)