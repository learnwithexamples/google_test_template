# How to use Google Test: template 1

**This template is good for module-level tests. There is no main function defined for end-to-end case.**

## This template has two types of files:
1. the files that contain code-under-test. E.g., class_a, class_b, class_c
2. the files that contains test-code. E.g., template_test.cpp, and the test codes under samples folder.

## This template does not have:
- user defined main function

## how to use
place your code anywhere under the template1 folder (ok inside sub-folders), it'll be automatically detected by cmake.

### compile the code
- ```cd build```
- ```cmake ..```
- ```make```

**Note: use ```cmake -D CMAKE_BUILD_TYPE=Debug ..``` to generate debug build.**

### run the code
- ```./mytest```

**for more google test templates, visit [google_test_template](https://github.com/learnwithexamples/google_test_template)**