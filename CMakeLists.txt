PROJECT(camera)

SET(QT_COMPONENT_LIST
        Core
        Multimedia

)

set(CMAKE_BUILD_TYPE Debug)


FIND_PACKAGE(Qt5 COMPONENTS  ${QT_COMPONENT_LIST} REQUIRED)
FIND_PACKAGE( OpenCV REQUIRED )



IF (${OpenCV_VERSION} VERSION_LESS 2.3.0)
	MESSAGE(FATAL_ERROR "OpenCV version is not compatible : ${OpenCV_VERSION}")
ENDIF()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(LINK_FLAGS "${LINK_FLAGS} -stdlib=libstdc++")

MESSAGE( ${OpenCV_LIBS} )




add_executable(camera main.cpp handGesture.cpp roi.cpp myImage.cpp)
QT5_USE_MODULES(camera ${QT_COMPONENT_LIST})
target_link_libraries(camera opencv_imgcodecs ${OpenCV_LIBS})
