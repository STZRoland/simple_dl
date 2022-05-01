
# Include xtensor
#set(CMAKE_PREFIX_PATH "C:/CPP/xtl/build" "C:/CPP/xtensor/build")    # https://cmake.org/cmake/help/latest/variable/CMAKE_PREFIX_PATH.html

#set(CMAKE_FIND_DEBUG_MODE ON)

set(CMAKE_PREFIX_PATH
        "C:/Users/rstol/Anaconda3/envs/CPP/Library/lib/cmake/xtensor"
        "C:/Users/rstol/Anaconda3/envs/CPP/Library/lib/cmake/xtensor-io"
        "C:/Users/rstol/Anaconda3/envs/CPP/Library/include/xtensor"
        "C:/Users/rstol/Anaconda3/envs/CPP/Library/include/xtensor-io"
        "C:/Users/rstol/Anaconda3/envs/CPP/Library"
        )

message("cmake_prefix_path" ${CMAKE_PREFIX_PATH})

set(xtensor_io_INCLUDE_DIR1S "C:/Users/rstol/Anaconda3/envs/CPP/Library/include/xtensor-io")

#message(STATUS "xtl include location: ${xtl_INCLUDE_DIRS}")
#message(STATUS "xtensor include location: ${xtensor_INCLUDE_DIR}")
#message(STATUS "xtensor-io include location: ${xtensor_io_INCLUDE_DIRS}")

find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)
find_package(xtensor-io REQUIRED)

include_directories(${xtl_INCLUDE_DIRS})
include_directories(${xtensor_INCLUDE_DIRS})
include_directories(${xtensor_io_INCLUDE_DIRS})

set(NAME_EXE "dl_main")
add_executable(${NAME_EXE} main.cpp)

if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS /MANIFEST:NO)
endif()

target_link_libraries("${NAME_EXE}"
        PRIVATE simple_dl
        PUBLIC xtensor
        PUBLIC xtensor::optimize
#        PUBLIC xtensor::use_xsimd
        PUBLIC xtensor-io
        )