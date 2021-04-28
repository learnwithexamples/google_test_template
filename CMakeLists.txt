cmake_minimum_required(VERSION 3.8)
set(TARGET mymain)
set(TARGETLIB mylib)
#project(${TARGET} C CXX)
#project(${TARGETLIB} C CXX)
#set(CMAKE_CXX_STANDARD 17)
#enable_testing()

# get list of source files
file(GLOB_RECURSE Sources src/*.cpp)
# exclude test files, in case someone place test code inside src folder
file(GLOB_RECURSE Tests src/*_test.cpp)
foreach (TMP_PATH ${Tests})
	list (REMOVE_ITEM Sources ${TMP_PATH})
endforeach(TMP_PATH)

# get list of header files
set (LIB_EXCLUDE_DIR lib/)
file(GLOB_RECURSE Headers inc/*.h)
set (INCLUDE_DIRS "")
foreach (_headerFile ${Headers})
    get_filename_component(_dir ${_headerFile} PATH)
    string (FIND ${_dir} ${LIB_EXCLUDE_DIR} LIB_EXCLUDE_DIR_FOUND)
    if (${LIB_EXCLUDE_DIR_FOUND} EQUAL -1)
	    list (APPEND INCLUDE_DIRS ${_dir})
	endif ()
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)
#list(APPEND INCLUDE_DIRS explicit_inc/)

# create main executable
add_executable(${TARGET} ${Sources})
target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIRS})
#target_link_libraries(${TARGET} stdc++fs)

# create library for tests
# remove main
#file(GLOB_RECURSE Main src/*_main.cpp)
#foreach (TMP_PATH ${Main})
#	list (REMOVE_ITEM Sources ${TMP_PATH})
#endforeach(TMP_PATH)
add_library(${TARGETLIB} STATIC ${Sources} ${Headers})
target_include_directories(${TARGETLIB} PUBLIC ${INCLUDE_DIRS})

# now build in test folder
add_subdirectory(test)

#message("-- Sources: ${Sources}")
#message("-- Headers: ${Headers}")
#message("-- INCLUDE_DIRS: ${INCLUDE_DIRS}")


