include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(tests
    XMLValidationTests.cpp
    TreeTests.cpp
    ConstructTreeTests.cpp
)

target_link_libraries(
    tests
    GTest::gtest_main
    src
)

include(GoogleTest)
gtest_discover_tests(tests)
