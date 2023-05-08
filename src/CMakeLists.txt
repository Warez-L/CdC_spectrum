add_executable(LV_Spectrum main.c)
target_link_libraries(
        LV_Spectrum
        ${SDL2_LIBRARIES}
        lvgl::lvgl
        lvgl::examples lvgl::demos
)
