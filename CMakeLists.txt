cmake_minimum_required(VERSION 3.1)

include(CheckFunctionExists)

project(mdstool C CXX ASM)

find_package(Threads)

file(GLOB SOURCES "source/*.c")

add_definitions(-DNK_INCLUDE_DEFAULT_ALLOCATOR)
add_definitions(-DNK_INCLUDE_COMMAND_USERDATA)

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
	file(GLOB FILES "source/x86/gcc/*.c")
    message("x86/gcc/*.c Files are: " ${FILES})
	list(APPEND SOURCES ${FILES})
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	add_definitions(-DUNICODE)
	file(GLOB FILES "source/x86/msvc/*.c")
    message("x86/msvc/*.c Files are: " ${FILES})
	list(APPEND SOURCES ${FILES})
endif()


if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	file(GLOB FILES "source/msw/*.c")
    message("msw/*.c Files are: " ${FILES})
	list(APPEND SOURCES ${FILES})
elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
	file(GLOB FILES "source/unix/*.c")
    message("unix/*.c Files are: " ${FILES})
	list(APPEND SOURCES ${FILES})
	file(GLOB FILES "source/linux/*.c")
    message("linux/*.c Files are: " ${FILES})
	list(APPEND SOURCES ${FILES})
endif()

file(GLOB FILES "source/x86/*.c")
message("x86/*.c Files are: " ${FILES})
list(APPEND SOURCES ${FILES})

check_function_exists(asprintf HAVE_ASPRINTF)
check_function_exists(clock_nanosleep HAVE_CLOCK_NANOSLEEP)
check_function_exists(nanosleep HAVE_NANOSLEEP)
check_function_exists(usleep HAVE_USLEEP)

if(HAVE_CLOCK_NANOSLEEP)
	add_definitions(-DHAVE_CLOCK_NANOSLEEP)
endif()

if (NOT HAVE_ASPRINTF)
	list(APPEND SOURCES "source/compat/asprintf.c")
endif()

if (${CMAKE_SYSTEM_NAME} STREQUAL Windows)
	add_definitions(-D_WIN32_WINNT=0x601)
	add_definitions(-DUNICODE)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
else ()
	add_definitions(-D_GNU_SOURCE)
endif()

add_executable(mdstool ${SOURCES})

include_directories(include)
target_link_libraries(mdstool ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})

if (${CMAKE_SYSTEM_NAME} STREQUAL Windows)
	target_link_libraries(mdstool ntdll shlwapi)
else()
	target_link_libraries(mdstool m)
endif()
