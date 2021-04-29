**This repository provides three templates to use google test framework:**

1. **unit-test only**: "code-under-test" and "test-code" mixed in same folder. There is no "user-defined main function".
    - the unit-test executable is build/mytest
2. **unit-test and end-to-end simulation**: "code-under-test", "test-code", "user-defined main function" all mixed in same folder. Using different file names to separate:
    - "*main.cc" or "*main.cpp": user-defined main function.
    - "*test.cc" or "*test.cpp": test-code.
    - everything else: code-under-test
        - the unit-test executable is build/mytest
        - the end-to-end executable is build/${filename} where "filename" is the name of the file that contains user-defined main function.
3. **unit-test and end-to-end simulation**: similar as 2, but use a dedicated folder "test" to contain all test-code. No need for specific file naming convention.
    - the unit-test executable is build/test/mytest
    - the end-to-end executable is build/mymain
    

For all templates, to build the code:
- ```cd build```
- ```cmake ..```
- ```make```

**Note: use ```cmake -D CMAKE_BUILD_TYPE=Debug ..``` to generate debug build.**
