# How to use Google Test: template 3

**This template is good for module-level tests and end-to-end simulation.**

Difference from template2 is that, the test code is separated to a dedicated folder. Thus, not requiring specific file name conventions.
- code-under-test: located under **src** and **inc** folders. It can also include user-defined main functions.
- test-code: located under **test** folder. This is for module-level test with Google Test.

## This template has three types of files:
1. the files that contain code-under-test. E.g., class_a, class_b, class_c
2. the files that contains test-code. E.g., template_test.cpp, and other test cases under test/samples
3. user-defined main function. E.g., template_main.cpp.

## how to use
1. test-code: put in test folder.
2. code-under-test and user-defined main function: src and inc folder.
3. no need to name the files differently (as compared to template2)

### compile the code
- ```cd build```
- ```cmake ..```
- ```make```

**Note: use ```cmake -D CMAKE_BUILD_TYPE=Debug ..``` to generate debug build.**

### run the code
- Google Test: ```./test/mytest```
- End-to-end: ```./mymain```

**for more google test templates, visit [google_test_template](https://github.com/learnwithexamples/google_test_template)**