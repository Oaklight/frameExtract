cmake_minimum_required(VERSION 2.8)
project( frameExtract)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( frameExtract frameExtract.cpp )
target_link_libraries( frameExtract ${OpenCV_LIBS} )