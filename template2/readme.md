# How to use Google Test: template 2

**This template is good for module-level tests and end-to-end simulation.**
- google test is used for module-level test
- user-defined main function is used for end-to-end simulation. This is the normal case without using Google Test

## This template has three types of files:
1. the files that contain code-under-test. E.g., class_a, class_b, class_c
2. the files that contains test-code. E.g., template_test.cpp. **naming convention for cpp file: \*test.cpp or \*test.cc**
3. user defined main function. E.g., template_main.cpp. **naming convention for main file: \*main.cpp or \*main.cc**

## how to use
place your code anywhere under the template1 folder (ok inside sub-folders), it'll be automatically detected by cmake.

### compile the code
- ```cd build```
- ```cmake ..```
- ```make```

**Note: use ```cmake -D CMAKE_BUILD_TYPE=Debug ..``` to generate debug build.**

### run the code
- Google Test: ```./mytest```
- End-to-end: ```./template_main```

**for more google test templates, visit [google_test_template](https://github.com/learnwithexamples/google_test_template)**