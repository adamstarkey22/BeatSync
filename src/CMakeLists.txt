set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(BeatSync
	BeatSync.cpp
	GenericButton.cpp
	Metronome.cpp
	MetronomeButton.cpp
	TempoText.cpp
)

target_include_directories(BeatSync PUBLIC "${PROJECT_SOURCE_DIR}/include")

find_package(SFML 2.5 COMPONENTS audio graphics REQUIRED)

if(SFML_FOUND)
	target_link_libraries(BeatSync sfml-audio sfml-graphics)
endif()