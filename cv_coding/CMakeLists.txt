cmake_minimum_required(VERSION 2.8.3)
project(CV_CODING)

## Compile as C++11, supported in ROS Kinetic and newer
#add_compile_options(-std#=c++11)
set(CMAKE_BUILD_TYPE Debug)
option(TESTS "build tests" ON)

set(CATKIN_ENABLE_TESTING ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package( OpenCV REQUIRED highgui imgproc core videoio imgcodecs )

include_directories( ${OpenCV_INCLUDE_DIRS} )



add_executable(cv src/main.cpp)
target_link_libraries(cv
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)


if(TESTS)

  enable_testing()

  # Process the CMakeLists.txt in third-party/googletest, sets project(gtest) and
  # project(gmock), gives access to ${gtest_SOURCE_DIR} and ${gmock_SOURCE_DIR}.
  add_subdirectory(googletest)

  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

  find_package( OpenCV REQUIRED )

  include_directories( ${OpenCV_INCLUDE_DIRS})

  #link_directories(${Boost_LIBRARY_DIRS})

  # Tests. *-test.cpp should be added here.
  add_executable(tests
    ./test/ImageClassTest.cpp)
  # Link core, pthread and gtest to tests.
  target_link_libraries(tests
    pthread
    gtest
    gtest_main
    ${OpenCV_LIBS})


endif()