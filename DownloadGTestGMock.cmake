set(NONOGRAM_PROJECT "googletest")
set(NONOGRAM_GIT_REPOSITORY "https://github.com/google/googletest.git")
set(NONOGRAM_GIT_TAG "master")
set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
set(NONOGRAM_DOWNLOAD_DIR "${CMAKE_BINARY_DIR}/${NONOGRAM_PROJECT}-download")
set(NONOGRAM_SOURCE_DIR "${CMAKE_BINARY_DIR}/${NONOGRAM_PROJECT}-src")
set(NONOGRAM_BINARY_DIR "${CMAKE_BINARY_DIR}/${NONOGRAM_PROJECT}-build")

set(${NONOGRAM_PROJECT}_SOURCE_DIR "${NONOGRAM_SOURCE_DIR}")
set(${NONOGRAM_PROJECT}_BINARY_DIR "${NONOGRAM_BINARY_DIR}")

configure_file(GTestGMock.CMakeLists.cmake.in
               "${NONOGRAM_DOWNLOAD_DIR}/CMakeLists.txt"
)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}"
                    -D "CMAKE_MAKE_PROGRAM:FILE=${CMAKE_MAKE_PROGRAM}"
                    .
                RESULT_VARIABLE result
                WORKING_DIRECTORY "${NONOGRAM_DOWNLOAD_DIR}"
)
if(result)
    message(FATAL_ERROR "CMake step for ${NONOGRAM_PROJECT} failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY "${NONOGRAM_DOWNLOAD_DIR}"
)
if(result)
    message(FATAL_ERROR "Build step for ${NONOGRAM_PROJECT} failed: ${result}")
endif()
