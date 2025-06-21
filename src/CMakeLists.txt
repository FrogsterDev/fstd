file(GLOB_RECURSE FSTD_SOURCES
    "fstd/*.cpp"
)

add_library(fstd STATIC
    ${FSTD_SOURCES}
)

target_include_directories(fstd
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>
) 