add_executable(wolf_3d create_window.c errors.c events.c map.c ray.c wolf_3d.c draw_funcs.c tex.c)
target_link_libraries(wolf_3d ../libft/libft.a)