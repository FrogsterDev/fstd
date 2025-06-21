file(GLOB_RECURSE TEST_SOURCES
    "fstd/**/*_test.cpp"
)

add_executable(fstd_tests
    ${TEST_SOURCES}
)

target_link_libraries(fstd_tests
    PRIVATE
        fstd
        GTest::gtest_main
)

add_test(
    NAME fstd_tests
    COMMAND fstd_tests
) 