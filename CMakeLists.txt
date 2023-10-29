cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

include(CMakePrintHelpers)



project(modelagem LANGUAGES CXX)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(glm)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

qt_add_executable(
    csg
    interface/GraphicsSceneWidget.cpp
    interface/GraphicsViewWidget.cpp
    interface/InputWidget.cpp
    interface/MainWidget.cpp
    Node.hpp
    Operation.hpp
    tracer/Material.hpp
    Solid.hpp
    CSGTree.cpp
    main.cpp
    OpNode.cpp
    SolidNode.cpp
    Sphere.cpp
    TransNode.cpp
    Union.cpp
    World.cpp
    Transformation.hpp
    Translation.cpp
    Scale.cpp
    Rotation.cpp
    Vertex.cpp
    VertexList.cpp
)

target_link_libraries(csg PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)