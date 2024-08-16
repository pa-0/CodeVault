cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(wx_cmake_fetchcontent_template LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(wxBUILD_SHARED OFF)

message(STATUS "Fetching wxWidgets...")

FetchContent_Declare(
   wxWidgets
   GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
   GIT_SHALLOW ON
)
FetchContent_MakeAvailable(wxWidgets)

set(SRCS App.cpp
        App.cpp
        App.h
        MainFrame.cpp
        MainFrame.cpp)

if(APPLE)
    # create bundle on apple compiles
    add_executable(App MACOSX_BUNDLE ${SRCS}
            App.h
            MainFrame.cpp
            MainFrame.cpp)

    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(App PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function. This is ignored on other systems,
    # so it works on all platforms
    add_executable(App WIN32 ${SRCS} main.exe.manifest
            App.h
            MainFrame.cpp
            MainFrame.cpp)
endif()

target_link_libraries(App PRIVATE wxcore wxnet)
