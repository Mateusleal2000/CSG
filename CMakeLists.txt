cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

include(CMakePrintHelpers)



project(modelagem LANGUAGES CXX)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets )


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

qt_add_executable(
    csg 
    main.cpp
    interface/GraphicsSceneWidget.cpp
    interface/GraphicsViewWidget.cpp 
    interface/InputWidget.cpp 
    interface/MainWidget.cpp
)

target_link_libraries(csg PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)