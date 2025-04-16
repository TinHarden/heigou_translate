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

find_package(Python3 3.12 REQUIRED COMPONENTS Interpreter Development)

include_directories(
        translate
        ui/main_ui
        translate_crawler
)

add_executable(heigou_translate
        main.cpp
        ui/main_ui/main_screen.cpp
        ui/main_ui/main_screen.h
        ui/main_ui/main_screen.ui
        google_translate_crawler/google_translate_crawler.cpp
        google_translate_crawler/google_translate_crawler.h
)
target_link_libraries(
        heigou_translate
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        Python3::Python
)
