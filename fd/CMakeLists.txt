cmake_minimum_required(VERSION 3.0)
project(ImageProcessing)

# Locate OpenCV package
find_package(OpenCV REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)

# Set sources
set(SOURCES src/main.cpp src/image_processor.cpp src/ImageData.cpp)

# Executable
add_executable(image_processing ${SOURCES})

# Link libraries
target_link_libraries(image_processing ${OpenCV_LIBS})

