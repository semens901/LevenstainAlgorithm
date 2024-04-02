cmake_minimum_required(VERSION 3.5)

project(LivenstainProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LivenstainProject main.cpp)

include(GNUInstallDirs)
install(TARGETS LivenstainProject
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
