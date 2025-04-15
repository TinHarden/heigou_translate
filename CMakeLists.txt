cmake_minimum_required(VERSION 3.30)
project(heigou_translate)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6
        COMPONENTS
        Core Gui Widgets Network
        REQUIRED)

set(CMAKE_PREFIX_PATH "/home/heiyt/Qt/6.9.0/gcc_64")

include_directories(
        translate
        ui/main_ui
        ui/settings_ui
)

add_executable(heigou_translate
        main.cpp
        ui/settings_ui/settings_screen.cpp
        ui/settings_ui/settings_screen.h
        ui/settings_ui/settings_screen.ui
        ui/main_ui/main_screen.cpp
        ui/main_ui/main_screen.h
        ui/main_ui/main_screen.ui
        translate/youdao_translate.cpp
        translate/youdao_translate.h
)
target_link_libraries(
        heigou_translate
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
)

