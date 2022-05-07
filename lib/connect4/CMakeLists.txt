
project(connect4)

add_library(${PROJECT_NAME}
	connect4.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(${PROJECT_NAME}
	PRIVATE
		cxx_std_11
)