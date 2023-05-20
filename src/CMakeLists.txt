add_executable(LV_Spectrum main.c ui.c)

target_include_directories(LV_Spectrum PRIVATE ${CMAKE_SOURCE_DIR}a/include)

target_link_libraries(
        LV_Spectrum

        ${SDL2_LIBRARIES}

        lvgl::lvgl
        lvgl::examples
        lvgl::demos
        lvgl::drivers

        kissfft::kissfft

        -lm
)

