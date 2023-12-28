cmake_minimum_required(VERSION 3.10)

# version
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})


#--------------------------------------------------------------------------------------------------
# variables
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(PROJECT_NAME helloworld )
set(TEST_NAME unittest)


#--------------------------------------------------------------------------------------------------
# project
project(${PROJECT_NAME} VERSION 0.0.${PATCH_VERSION})

# config
configure_file(${SRC_DIR}/version.h.in ${SRC_DIR}/version.h)


#--------------------------------------------------------------------------------------------------
# builds
add_executable(${PROJECT_NAME}
	${SRC_DIR}/lib.cpp
	${SRC_DIR}/main.cpp
)

add_executable(${TEST_NAME} 
	${TEST_DIR}/test_version.cpp
)

# properties
set_target_properties(${PROJECT_NAME} ${TEST_NAME} 
	PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)


#--------------------------------------------------------------------------------------------------
# gtest
#
find_package(GTest)

# build googletest
add_subdirectory(
	${CMAKE_CURRENT_SOURCE_DIR}/googletest
)

# add src to the include directories for the test target
target_include_directories(${TEST_NAME} 
	PRIVATE
	${SRC_DIR}
	${GTEST_INCLUDE_DIRS}
)

# link test target against gtest libraries
target_link_libraries(${TEST_NAME} 
	PRIVATE
	${GTEST_BOOTH_LIBRARIES}
	gmock
	gmock_main
	gtest 
	gtest_main
)


#--------------------------------------------------------------------------------------------------
# compiler settings
if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

	target_compile_options(${PROJECT_NAME} PRIVATE
		/W4
	)
	target_compile_options(${TEST_NAME} PRIVATE
		/W4
	)
else ()
	target_compile_options(${PROJECT_NAME} PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
	target_compile_options(${TEST_NAME} PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
endif()


#--------------------------------------------------------------------------------------------------
# deb pkg
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT 155024765+ProphetRu@users.noreply.github.com)

include(CPack)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})