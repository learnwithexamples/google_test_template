cmake_minimum_required(VERSION 3.8)
set(TARGET mymain)
set(TARGETLIB mylib)

# get list of source files
file(GLOB_RECURSE Sources src/*.cpp src/*.cc)

# get list of header files
file(GLOB_RECURSE Headers inc/*.h inc/*.hpp)
set (INCLUDE_DIRS "")
foreach (_headerFile ${Headers})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

# create main executable
add_executable(${TARGET} ${Sources})
target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIRS})

# create library for tests
add_library(${TARGETLIB} STATIC ${Sources} ${Headers})
target_include_directories(${TARGETLIB} PUBLIC ${INCLUDE_DIRS})

# now build in test folder
add_subdirectory(test)
