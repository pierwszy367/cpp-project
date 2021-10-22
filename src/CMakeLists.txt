option(CPP_PROJECT_USE_FLTK "Enable compilation of FLTK sample" OFF)
option(CPP_PROJECT_USE_GTKMM "Enable compilation of GTKMM sample" OFF)
option(CPP_PROJECT_USE_IMGUI_GL "Enable compilation of ImGui (OpenGL + GLFW) sample" OFF)
option(CPP_PROJECT_USE_IMGUI_SFML "Enable compilation of ImGui (SFML) sample" OFF)
option(CPP_PROJECT_USE_NANA "Enable compilation of Nana GUI sample" OFF)


add_executable(main main.cpp)
target_link_libraries(main PRIVATE project_options project_warnings)


# fltk
if(CPP_PROJECT_USE_FLTK)
    find_package(FLTK REQUIRED)
    add_executable(test_fltk fltk/main.cpp)
    target_include_directories(test_fltk SYSTEM PRIVATE ${FLTK_INCLUDE_DIR})
    target_link_libraries(test_fltk PRIVATE project_options project_warnings ${FLTK_LIBRARIES})
endif()


# gtkmm
if(CPP_PROJECT_USE_GTKMM)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTKMM REQUIRED gtkmm-3.0) # if it doesn't find configs set PKG_CONFIG_PATH in console
    add_executable(test_gtkmm gtkmm/main.cpp gtkmm/helloworld.cpp)
    target_include_directories(test_gtkmm SYSTEM PRIVATE ${GTKMM_INCLUDE_DIRS})
    target_link_libraries(test_gtkmm PRIVATE project_options project_warnings ${GTKMM_LIBRARIES})
endif()


# imgui - opengl + glfw
if(CPP_PROJECT_USE_IMGUI_GL)
    find_package(OpenGL)
    find_package(GLFW3)

    add_library(imgui_gl 
                imgui/lib/imgui.cpp 
                imgui/lib/imgui_draw.cpp 
                imgui/lib/imgui_widgets.cpp 
                imgui/lib/imgui_tables.cpp 
                imgui/lib/imgui_demo.cpp
                imgui/lib/imgui_impl_opengl3.cpp
                imgui/lib/imgui_impl_glfw.cpp
                )
    target_include_directories(imgui_gl PRIVATE imgui/lib ${GLFW3_INCLUDE_DIR})
    target_link_libraries(imgui_gl INTERFACE OpenGL::GL ${GLFW3_LIBRARY})

    add_executable(test_imgui_gl imgui/imgui_gl.cpp)
    target_include_directories(test_imgui_gl SYSTEM PRIVATE imgui/lib ${GLFW3_INCLUDE_DIR})
    target_link_libraries(test_imgui_gl PRIVATE project_options project_warnings imgui_gl)
endif()


# imgui - sfml
if(CPP_PROJECT_USE_IMGUI_SFML)
    find_package(SFML COMPONENTS graphics window system)
    find_package(OpenGL)

    add_library(imgui_sfml 
                imgui/lib/imgui.cpp 
                imgui/lib/imgui_draw.cpp 
                imgui/lib/imgui_widgets.cpp 
                imgui/lib/imgui_tables.cpp 
                imgui/lib/imgui-SFML.cpp
                )
    target_include_directories(imgui_sfml PRIVATE ${SFML_INCLUDE_DIR} imgui/lib)
    target_link_libraries(imgui_sfml INTERFACE ${SFML_LIBRARIES} ${OPENGL_gl_LIBRARY})

    add_executable(test_imgui_sfml imgui/imgui_sfml.cpp)
    target_include_directories(test_imgui_sfml SYSTEM PRIVATE imgui/lib ${SFML_INCLUDE_DIR})
    target_link_libraries(test_imgui_sfml PRIVATE project_options project_warnings imgui_sfml)
endif()


# nana
if(CPP_PROJECT_USE_NANA)
    include(ExternalProject)
    ExternalProject_Add(
        nana
        GIT_REPOSITORY   https://github.com/cnjinhao/nana.git
        GIT_TAG          v1.7.3
        CMAKE_CACHE_ARGS
            -DNANA_CMAKE_NANA_FILESYSTEM_FORCE:BOOL=ON
        INSTALL_COMMAND  ""
    )
    ExternalProject_Get_Property(nana SOURCE_DIR BINARY_DIR)

    add_executable(test_nana nana/main.cpp)
    target_compile_options(test_nana PRIVATE -DNANA_FILESYSTEM_FORCE)
    target_include_directories(test_nana SYSTEM PRIVATE ${SOURCE_DIR}/include)
    target_link_libraries(test_nana PRIVATE project_options project_warnings ${BINARY_DIR}/libnana.a)
endif()
