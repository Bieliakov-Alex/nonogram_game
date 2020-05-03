cmake_minimum_required(VERSION 3.10.0)

project(nonogram_gui)

add_definitions(-DBOOST_LOG_DYN_LINK)
find_package(Boost 1.65.0 COMPONENTS log REQUIRED)
find_package(Threads)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)

qt5_add_resources(QT_RESOURCES qml.qrc)

include_directories(include
                    src/incl
)

add_executable(${PROJECT_NAME} src/impl/main.cpp
                               src/impl/nonogram_rect_model.cpp
                               src/impl/nonogram_wrapper.cpp
                               src/impl/column_numbers_model.cpp
                               src/impl/row_numbers_model.cpp
                               src/impl/nonogram_field_model.cpp
                               src/incl/nonogram_rect_model.hpp
                               src/incl/nonogram_wrapper.hpp
                               src/incl/column_numbers_model.hpp
                               src/incl/row_numbers_model.hpp
                               src/incl/nonogram_field_model.hpp
                               ${QT_RESOURCES}
)

target_link_libraries(${PROJECT_NAME} nonogram
                                      ${Boost_LOG_LIBRARY}
                                      ${CMAKE_THREAD_LIBS_INIT}
                                      Qt5::Widgets
                                      Qt5::Qml
                                      Qt5::Quick
)
