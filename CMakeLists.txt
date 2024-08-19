
cmake_minimum_required(VERSION 3.10)
project(webrtc-starter)

set(CMAKE_CXX_STANDARD 17)

ADD_DEFINITIONS(-DWEBRTC_POSIX=1)
ADD_DEFINITIONS(-D__STDC_CONSTANT_MACROS=1)

set(LIBWEBRTC_DIR ${CMAKE_SOURCE_DIR}/../webrtcexample/webrtc-checkout)

add_executable(app app.cc)

target_include_directories(app PUBLIC
    ${LIBWEBRTC_DIR}/src
    ${LIBWEBRTC_DIR}/src/third_party/abseil-cpp
    ${LIBWEBRTC_DIR}/src/third_party/libyuv/include
)

target_link_libraries(app
    ${LIBWEBRTC_DIR}/src/out/Default/obj/libwebrtc.a
)
