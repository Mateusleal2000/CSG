cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

include(CMakePrintHelpers)



project(modelagem LANGUAGES CXX)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets OpenGLWidgets)
find_package(glm)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

qt_add_executable(
    csg
    interface/InputWidget.cpp
    interface/MainWidget.cpp

    
    tracer/Material.hpp
    tracer/Ray.cpp
    tracer/GLView.cpp
    tracer/Canvas.cpp
    tracer/GLProgram.cpp
    tracer/GLObject.hpp

    
    nodes/Node.hpp
    nodes/OpNode.cpp
    nodes/SolidNode.cpp
    nodes/TransNode.cpp
    nodes/World.cpp
    
    
    operations/Union.cpp
    operations/Operation.hpp

    transformations/Scale.cpp
    transformations/Rotation.cpp
    transformations/Transformation.hpp
    transformations/Translation.cpp
    
    solids/Solid.hpp
    solids/Sphere.cpp
    
    CSGTree.cpp
    Vertex.cpp
    VertexList.cpp


    main.cpp
)

target_link_libraries(csg PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGLWidgets)