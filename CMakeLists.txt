cmake_minimum_required(VERSION 3.29)
project(Lunia)

set(CMAKE_CXX_STANDARD 26)

find_package(raylib REQUIRED)

add_executable(LuniaClient WIN32
        src/AllM/XRated/Framework/Application.cpp
        src/AllM/XRated/Framework/Application.hpp
        src/AllM/XRated/Framework/IApplication.hpp
        src/AllM/XRated/Framework/ILayer.hpp
        src/AllM/XRated/Framework/ILayerSystem.hpp
        src/AllM/XRated/Framework/IModule.hpp
        src/AllM/XRated/Framework/IObject.hpp
        src/AllM/XRated/Framework/Layer.hpp
        src/AllM/XRated/Framework/LayerFactory.cpp
        src/AllM/XRated/Framework/LayerFactory.hpp
        src/AllM/XRated/Framework/LayerSystem.hpp
        src/AllM/XRated/Framework/System.hpp

        src/AllM/XRated/LuniaClient/Layers/ILobby.hpp
        src/AllM/XRated/LuniaClient/Layers/Lobby.cpp
        src/AllM/XRated/LuniaClient/Lunia.cpp
        src/AllM/XRated/LuniaClient/Lunia.rc
        src/AllM/XRated/LuniaClient/LuniaModule.cpp
        src/AllM/XRated/LuniaClient/LuniaModule.hpp)

target_link_libraries(LuniaClient PRIVATE raylib)
target_include_directories(LuniaClient PRIVATE src)
