cmake_minimum_required(VERSION 3.26)

# setting project name
project(TradingEngine)

# adding executable files
add_executable(test main.cpp src/order.cpp)

# Setting CPP Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
target_compile_features(test PRIVATE cxx_std_20)
# set(CMAKE_BUILD_TYPE Release)
