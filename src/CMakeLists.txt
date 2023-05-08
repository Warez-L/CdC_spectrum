add_executable(LV_Spectrum main.c ui_init.c)

target_include_directories(LV_Spectrum PUBLIC ${CMAKE_SOURCE_DIR}/include/)


target_link_libraries(
        LV_Spectrum

        ${SDL2_LIBRARIES}

        lvgl::lvgl
        lvgl::examples
        lvgl::demos
        lvgl::drivers

        -lm
)

