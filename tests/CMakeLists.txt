cmake_minimum_required(VERSION 3.25)


include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

aux_source_directory(dummy dummy_src)
aux_source_directory(fake fake_src)
aux_source_directory(spy spy_src)
aux_source_directory(stub stub_src)

enable_testing()
add_executable(tests test.cpp ${dummy_src} ${fake_src} ${spy_src} ${stub_src})
target_link_libraries(tests gtest_main gmock_main pthread)

target_include_directories(
        tests
        PUBLIC
        ${CMAKE_SOURCE_DIR}/source
)

