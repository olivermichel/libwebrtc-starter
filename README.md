# WebRTC Starter Project

## Setup

* clone libwebrtc:

```bash
mkdir webrtc-checkout
cd webrtc-checkout
fetch --nohooks webrtc
cd src
git checkout branch-heads/6030
gclient sync
```

* compile libwebrtc:

```bash
./build/install-build-deps.sh
gn gen out/Default --args='is_debug=false is_component_build=false rtc_include_tests=false use_custom_libcxx=false treat_warnings_as_errors=false use_ozone=true rtc_use_x11=false use_rtti=true rtc_build_examples=false'
ninja -C out/Default
```

* set path to libwebrtc in CMakeLists.txt, e.g.:

```cmake
set(LIBWEBRTC_DIR ${CMAKE_SOURCE_DIR}/../webrtc-checkout)
```
