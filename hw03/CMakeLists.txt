# CMakeList.txt : CMake project for hw02, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(PATCH_VERSION 3.0)

set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project("allocator" VERSION ${PROJECT_VERSION})

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()




# Add source to this project's executable.
#add_executable (allocator "allocator.cpp")

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET allocator PROPERTY CXX_STANDARD 20)
#endif()

# TODO: Add tests and install targets if needed.

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

cmake_minimum_required(VERSION 3.14)

enable_testing()

add_executable(
  allocator_test
  "allocator_test.cpp"
 )
target_link_libraries(
  allocator_test
  gtest_main
  gmock_main
)

include(GoogleTest)
gtest_discover_tests(allocator_test)

set_property(TARGET allocator_test PROPERTY CXX_STANDARD 17)
set_property(TARGET allocator_test PROPERTY CXX_STANDARD_REQUIRED ON)
