cmake_minimum_required(VERSION 3.8)
project(GoogleTest)
set(TARGET mytest)

# get list of source files
file(GLOB_RECURSE Sources *.cpp *.cc)

# exclude build folder
set (EXCLUDE_DIR build)
foreach (TMP_PATH ${Sources})
    string (FIND ${TMP_PATH} ${EXCLUDE_DIR} EXCLUDE_DIR_FOUND)
    if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
        list (REMOVE_ITEM Sources ${TMP_PATH})
    endif ()
endforeach (TMP_PATH)

#remove *_main.c*
foreach (TMP_PATH ${Sources})
    string (FIND ${TMP_PATH} _main.c EXCLUDE_MAIN_FOUND)
    if (NOT ${EXCLUDE_MAIN_FOUND} EQUAL -1)
        list (REMOVE_ITEM Sources ${TMP_PATH})
    endif()
endforeach (TMP_PATH)

# get list of header files
file(GLOB_RECURSE Headers *.h *.hpp)
set (INCLUDE_DIRS "")
foreach (_headerFile ${Headers})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach ()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

# create executable for Google Test
add_executable(${TARGET} ${Sources})
target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIRS})
target_link_libraries(${TARGET} PRIVATE gtest_main gtest gmock pthread)

#remove *_test.c*
foreach (TMP_PATH ${Sources})
    string (FIND ${TMP_PATH} _test.c EXCLUDE_MAIN_FOUND)
    if (NOT ${EXCLUDE_MAIN_FOUND} EQUAL -1)
        list (REMOVE_ITEM Sources ${TMP_PATH})
    endif()
endforeach (TMP_PATH)
# create executable for each _main.cpp
file(GLOB_RECURSE MainFiles *_main.cpp *_main.cc)
foreach (mainfile ${MainFiles})
    get_filename_component(execname ${mainfile} NAME_WE)
    add_executable(${execname} ${mainfile} ${Sources})
    target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIRS})
    target_link_libraries(${TARGET} PRIVATE gtest_main gtest gmock pthread)
endforeach (mainfile ${MainFiles})
