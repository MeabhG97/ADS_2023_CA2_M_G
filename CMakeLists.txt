cmake_minimum_required(VERSION 3.22)
project(
    FileManagement 
    VERSION 1.0 
    LANGUAGES CXX
)

include(CTest)

add_subdirectory(app)
add_subdirectory(src)
add_subdirectory(test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
