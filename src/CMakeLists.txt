project(src)

add_executable(${PROJECT_NAME}
	main.c
)

target_link_libraries(${PROJECT_NAME}
	connect4
)