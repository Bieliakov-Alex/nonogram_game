project(unit_tests_nonogram)

set(LIB_NAME nonogram_mocks)

add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/mocks_include)
target_link_libraries(${LIB_NAME} INTERFACE nonogram)
set(PRIVATE_HEADERS $<TARGET_PROPERTY:nonogram,INCLUDE_DIRECTORIES>)

add_executable(${PROJECT_NAME} nonogram_test.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${PRIVATE_HEADERS})

target_link_libraries(${PROJECT_NAME} gtest_main
                                      gmock_main
                                      ${LIB_NAME}
)
