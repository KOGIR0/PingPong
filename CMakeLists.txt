cmake_minimum_required(VERSION 3.2)
project(PingPong.exe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    PingPong.cpp
    Bar.cpp
    Ball.cpp
    UI/Menu.cpp
    UI/Button.cpp
    UI/Sprite.cpp
    UI/Text.cpp
)
list(TRANSFORM SOURCE_FILES PREPEND "source/")

add_executable(PingPong.exe ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR} include include/UI include/Network)
    target_link_libraries(PingPong.exe ${SFML_LIBRARIES})
endif()

file(COPY ./resources/MenuBtn.png DESTINATION .)
file(COPY ./resources/times-new-roman.ttf DESTINATION .)