cmake_minimum_required(VERSION 3.9)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)
if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})
endif()
set(MY_PROJECT_NAME yamr)

project(${MY_PROJECT_NAME})
find_package(Threads REQUIRED)

add_executable(${MY_PROJECT_NAME} main.cpp)

set_target_properties(${MY_PROJECT_NAME}  PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )
target_link_libraries(${MY_PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

set(BUILD_TEST ON)
if(${BUILD_TEST})
configure_file("${PROJECT_SOURCE_DIR}/${SRC_DIR}/tests/addresses.txt" "${PROJECT_BINARY_DIR}/tests/addresses.txt" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/${SRC_DIR}/tests/addr_empty.txt" "${PROJECT_BINARY_DIR}/tests/addr_empty.txt" COPYONLY)
configure_file("${PROJECT_SOURCE_DIR}/${SRC_DIR}/tests/one_address.txt" "${PROJECT_BINARY_DIR}/tests/one_address.txt" COPYONLY)
enable_testing()
include_directories(./)
add_subdirectory(tests)
endif()

install(TARGETS ${MY_PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE amd64)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${MY_PROJECT_NAME}")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Sergio Matveev aka Feiler e-mail: srgmatveev@gmail.com")
set(CPACK_PACKAGE_CONTACT srgmatveev@gmail.com)

include (CPack)