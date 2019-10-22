PROJECT(simplecollectionmanager)
FIND_PATH(RESTBED_INCLUDE_DIR restbed)
FIND_LIBRARY(RESTBED_LIBRARY restbed)
find_package(jsoncpp CONFIG REQUIRED)

INCLUDE_DIRECTORIES(${RESTBED_INCLUDE_DIR})

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main ${RESTBED_LIBRARY})
target_link_libraries(main PRIVATE jsoncpp_lib)