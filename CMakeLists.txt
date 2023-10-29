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
    nodes/Node.hpp
    operations/Operation.hpp
    tracer/Material.hpp
    solids/Solid.hpp
    CSGTree.cpp
    main.cpp
    nodes/OpNode.cpp
    nodes/SolidNode.cpp
    solids/Sphere.cpp
    nodes/TransNode.cpp
    operations/Union.cpp
    nodes/World.cpp
    transformations/Transformation.hpp
    transformations/Translation.cpp
    transformations/Scale.cpp
    transformations/Rotation.cpp
    Vertex.cpp
    VertexList.cpp
)

target_link_libraries(csg PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)