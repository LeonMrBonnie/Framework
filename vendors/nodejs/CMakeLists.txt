add_library(NodeJS INTERFACE)

if (CMAKE_CL_64)
    target_link_directories(NodeJS INTERFACE "../../vendors/nodejs/lib/win64")
    file(GLOB NODEJS_LIBS "../../vendors/nodejs/lib/win64/*.lib")
elseif (WIN32)
    target_link_directories(NodeJS INTERFACE "../../vendors/nodejs/lib/win32")
    file(GLOB NODEJS_LIBS "../../vendors/nodejs/lib/win32/*.lib")
elseif (APPLE)
    target_link_directories(NodeJS INTERFACE "../../vendors/nodejs/lib/osx")
    file(GLOB NODEJS_LIBS "../../vendors/nodejs/lib/osx/*.a")
elseif (UNIX)
    target_link_directories(NodeJS INTERFACE "../../vendors/nodejs/lib/linux")
    file(GLOB NODEJS_LIBS "../../vendors/nodejs/lib/linux/*.a")
endif ()

target_include_directories(NodeJS INTERFACE "include")
target_link_libraries(NodeJS INTERFACE ${NODEJS_LIBS})
