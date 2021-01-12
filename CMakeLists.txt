cmake_minimum_required(VERSION 3.17)
project(Incudine)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options(
            $<$<CONFIG:>:/MT> #---------|
            $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
            $<$<CONFIG:Release>:/MT> #--|
    )
endif()

link_directories(PolyHook_2_0/_install/lib/)

add_library(Incudine SHARED)
add_subdirectory(Incudine)
target_link_libraries(Incudine PRIVATE PolyHook_2 capstone)
target_include_directories(Incudine PRIVATE "PolyHook_2_0/_install/include")

add_executable(Loader)
add_subdirectory(Loader)
