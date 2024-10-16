cmake_minimum_required(VERSION 3.16)

project(AeroGestor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Defina os arquivos de origem do projeto
set(PROJECT_SOURCES
    src/main.cpp
    src/model/admin.cpp
    src/model/aeronave.cpp
    src/model/authSystem.cpp
    src/model/mechanic.cpp
    src/model/manager.cpp
    src/view/admin_interface.cpp
    src/view/loginWindow.cpp
    src/view/mainwindow.cpp
    src/view/manager_interface.cpp
    src/view/mechanic_interface.cpp
)

# Defina os arquivos de cabeçalho do projeto
set(PROJECT_HEADERS
    src/model/admin.h
    src/model/aeronave.h
    src/model/authSystem.h
    src/model/mechanic.h
    src/model/manager.h
    src/model/user.h
    src/view/admin_interface.h
    src/view/loginWindow.h
    src/view/mainwindow.h
    src/view/manager_interface.h
    src/view/mechanic_interface.h
)

# Defina os arquivos .ui do Qt
set(PROJECT_UI
    src/view/mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AeroGestor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
        ${PROJECT_UI}
    )
else()
    if(ANDROID)
        add_library(AeroGestor SHARED
            ${PROJECT_SOURCES}
            ${PROJECT_HEADERS}
            ${PROJECT_UI}
        )
    else()
        add_executable(AeroGestor
            ${PROJECT_SOURCES}
            ${PROJECT_HEADERS}
            ${PROJECT_UI}
        )
    endif()
endif()

target_link_libraries(AeroGestor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.AeroGestor)
endif()
set_target_properties(AeroGestor PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS AeroGestor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AeroGestor)
endif()
