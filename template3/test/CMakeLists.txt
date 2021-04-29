cmake_minimum_required(VERSION 3.8)
set(TARGET mytest)

# get list of source files
file(GLOB_RECURSE Sources *.cpp *.cc)

# get list of header files
file(GLOB_RECURSE Headers *.h *.hpp)
set (INCLUDE_DIRS "")
foreach (_headerFile ${Headers})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

add_executable(${TARGET} ${Sources})
target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIRS})
target_link_libraries(${TARGET} PRIVATE gtest_main gtest gmock pthread ${TARGETLIB})
