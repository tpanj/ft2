cmake_minimum_required(VERSION 3.7)

project(ft2-clone VERSION 1.10)

set(SDL_SHARED_ENABLED_BY_DEFAULT OFF)
add_subdirectory(include/SDL2 EXCLUDE_FROM_ALL)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ft2-clone_BINARY_DIR}/release/${CMAKE_SYSTEM_NAME}/")

file(GLOB ft2-clone_SRC
    "${ft2-clone_SOURCE_DIR}/src/rtmidi/*.cpp"
    "${ft2-clone_SOURCE_DIR}/src/*.c"
    "${ft2-clone_SOURCE_DIR}/src/gfxdata/*.c" 
    if (WIN32)
      "${ft2-clone_SOURCE_DIR}/src/ft2-clone.rc"
    endif (WIN32)
)

add_executable(ft2-clone ${ft2-clone_SRC})

if (WIN32)
  set(CMAKE_MFC_FLAG 1)
  if (MINGW)
    set(CMAKE_C_FLAGS "-msse2 -msse3")
  endif ()
  target_compile_definitions(ft2-clone PRIVATE "BUILDER_STATIC_DEFINE;__WINDOWS_MM__;_CRTDBG_MAP_ALLOC;WIN32;_CRT_SECURE_NO_WARNINGS;_USE_MATH_DEFINES;HAVE_M_PI")
  target_link_libraries(ft2-clone PRIVATE SDL2-static SDL2main "shlwapi") # static
else ()
  target_compile_definitions(ft2-clone PRIVATE __LINUX_ALSA__ )
  target_link_libraries(ft2-clone
    PRIVATE m asound pthread SDL2-static SDL2main)
endif ()

install(TARGETS ft2-clone
        RUNTIME DESTINATION bin )

# CPack support
set(CPACK_GENERATOR "ZIP;TGZ")
include (CPack)
