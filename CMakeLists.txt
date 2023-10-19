cmake_minimum_required(VERSION 3.5)
project(GRCPCSolutions)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# Include directories
include_directories(include)

# Add your source files
set(SOURCES
    src/main.cpp

	src/problem1/problem1.cpp
	src/problem2/problem2.cpp
	src/problem1/utils.cpp
)

# Add your header files
set(HEADERS
	src/problem1/utils.h
    include/problems.h
    include/timer.h
)

set(TESTS
)

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${TESTS})


# Add any additional libraries or dependencies
# Example:
# find_package(OpenCV REQUIRED)
# target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# Set compiler flags (optional)
# Example:
# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

# Set output directory (optional)
# Example:
# set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

