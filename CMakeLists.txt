# Generated on 2023-8-20 16:20:40 by version 0.9.1 of mulle-xcode-to-cmake
# Command line:
#    mulle-xcode-to-cmake export FAT16MountBlocker.xcodeproj

cmake_minimum_required (VERSION 3.4)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_FILE_OFFSET_BITS=64")

project( FAT16MountBlocker C)

find_package(FUSE REQUIRED)

if( NOT CMAKE_OSX_DEPLOYMENT_TARGET)
     set(CMAKE_OSX_DEPLOYMENT_TARGET "10.6" CACHE STRING "Deployment target for OSX" FORCE)
endif()

set( CMAKE_POSITION_INDEPENDENT_CODE FALSE)
set( CMAKE_INSTALL_RPATH "@rpath/../lib")

set( BEGIN_ALL_LOAD "-all_load")
set( END_ALL_LOAD)

set( FAT16_MOUNT_BLOCKER_GLOBAL_RESOURCES
"Documents/App Icon/App Icon.icns"
README.markdown
ReleaseNotes.markdown
"Resources/StatusItem Disabled 1.png"
"Resources/StatusItem Disabled 2.png"
"Resources/StatusItem Green.png"
"Resources/StatusItem Orange.png"
"Resources/ToolbarItem Attach Disk Image.png"
"Resources/ToolbarItem Attach Disk Plug.png"
"Resources/ToolbarItem Eject.png"
"Resources/ToolbarItem Info.png"
"Resources/ToolbarItem Mount.png"
)

set( FAT16_MOUNT_BLOCKER_BASE_RESOURCES
Base.lproj/AttachDiskImageAccessory.xib
Base.lproj/DiskInfo.xib
Base.lproj/MainMenu.xib
Base.lproj/MountOptions.xib
Base.lproj/Preferences.xib
)

set( FAT16_MOUNT_BLOCKER_RESOURCES
   ${FAT16_MOUNT_BLOCKER_GLOBAL_RESOURCES}
   ${FAT16_MOUNT_BLOCKER_BASE_RESOURCES}
)

set( FAT16_MOUNT_BLOCKER_SOURCES
Source/AppError.m
Source/Arbitrator.m
Source/AttachDiskImageController.m
Source/Disk.m
Source/DiskArbitrationPrivateFunctions.m
Source/DiskCell.m
Source/DiskInfoController.m
Source/FAT16MountBlockerAppController+Toolbar.m
Source/FAT16MountBlockerAppController.m
Source/SheetController.m
Source/main.m
)

set( FAT16_MOUNT_BLOCKER_STATIC_DEPENDENCIES
)

if( NOT SKIP_FIND_COCOA_LIBRARY)
   find_library( COCOA_LIBRARY Cocoa)
   message( STATUS "COCOA_LIBRARY is ${COCOA_LIBRARY}")
endif()
if( NOT SKIP_FIND_DISK_ARBITRATION_LIBRARY)
   find_library( DISK_ARBITRATION_LIBRARY DiskArbitration)
   message( STATUS "DISK_ARBITRATION_LIBRARY is ${DISK_ARBITRATION_LIBRARY}")
endif()
if( NOT SKIP_FIND_FOUNDATION_LIBRARY)
   find_library( FOUNDATION_LIBRARY Foundation)
   message( STATUS "FOUNDATION_LIBRARY is ${FOUNDATION_LIBRARY}")
endif()
if( NOT SKIP_FIND_IOKIT_LIBRARY)
   find_library( IOKIT_LIBRARY IOKit)
   message( STATUS "IOKIT_LIBRARY is ${IOKIT_LIBRARY}")
endif()
if( NOT SKIP_FIND_SECURITY_LIBRARY)
   find_library( SECURITY_LIBRARY Security)
   message( STATUS "SECURITY_LIBRARY is ${SECURITY_LIBRARY}")
endif()
if( NOT SKIP_FIND_SECURITY_FOUNDATION_LIBRARY)
   find_library( SECURITY_FOUNDATION_LIBRARY SecurityFoundation)
   message( STATUS "SECURITY_FOUNDATION_LIBRARY is ${SECURITY_FOUNDATION_LIBRARY}")
endif()

set( FAT16_MOUNT_BLOCKER_DEPENDENCIES
${COCOA_LIBRARY}
${DISK_ARBITRATION_LIBRARY}
${FOUNDATION_LIBRARY}
${IOKIT_LIBRARY}
${SECURITY_LIBRARY}
${SECURITY_FOUNDATION_LIBRARY}
)

add_executable( FAT16MountBlocker MACOSX_BUNDLE
${FAT16_MOUNT_BLOCKER_SOURCES}
${FAT16_MOUNT_BLOCKER_PUBLIC_HEADERS}
${FAT16_MOUNT_BLOCKER_PROJECT_HEADERS}
${FAT16_MOUNT_BLOCKER_PRIVATE_HEADERS}
${FAT16_MOUNT_BLOCKER_RESOURCES}
)

target_link_libraries( FAT16MountBlocker
${BEGIN_ALL_LOAD}
${FAT16_MOUNT_BLOCKER_STATIC_DEPENDENCIES}
${END_ALL_LOAD}
${FAT16_MOUNT_BLOCKER_DEPENDENCIES}
${FUSE_LIBRARIES}
)

target_include_directories( FAT16MountBlocker PRIVATE ${FUSE_INCLUDE_DIR})

target_compile_definitions(FAT16MountBlocker PUBLIC FUSE_USE_VERSION=35)

set_source_files_properties(
${FAT16_MOUNT_BLOCKER_RESOURCES}
   PROPERTIES
      MACOSX_PACKAGE_LOCATION
      Resources
)

set_target_properties( FAT16MountBlocker PROPERTIES
MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/FAT16MountBlocker-Info.plist.in"
)

set( XIB_FILES
        Base.lproj/AttachDiskImageAccessory
        Base.lproj/DiskInfo
        Base.lproj/MainMenu
        Base.lproj/MountOptions
        Base.lproj/Preferences
)

find_program(IBTOOL ibtool REQUIRED)
foreach(XIBFILE ${XIB_FILES})
    add_custom_command(TARGET FAT16MountBlocker POST_BUILD
            COMMAND ${IBTOOL} --compile ${CMAKE_CURRENT_BINARY_DIR}/FAT16MountBlocker.app/Contents/Resources/${XIBFILE}.nib ${CMAKE_CURRENT_SOURCE_DIR}/${XIBFILE}.xib
            COMMENT "Compiling NIB file ${XIBFILE}.nib")
endforeach()

##
## Build FAT16 Mount Blocker DMG
##

# add_executable( Build-FAT16-Mount-Blocker-DMG MACOSX_BUNDLE
# ${BUILD__FAT16__MOUNT__BLOCKER__DMG_SOURCES}
# ${BUILD__FAT16__MOUNT__BLOCKER__DMG_PUBLIC_HEADERS}
# ${BUILD__FAT16__MOUNT__BLOCKER__DMG_PROJECT_HEADERS}
# ${BUILD__FAT16__MOUNT__BLOCKER__DMG_PRIVATE_HEADERS}
# ${BUILD__FAT16__MOUNT__BLOCKER__DMG_RESOURCES}
# )

# target_link_libraries( Build-FAT16-Mount-Blocker-DMG
# ${BEGIN_ALL_LOAD}
# ${BUILD__FAT16__MOUNT__BLOCKER__DMG_STATIC_DEPENDENCIES}
# ${END_ALL_LOAD}
# ${BUILD__FAT16__MOUNT__BLOCKER__DMG_DEPENDENCIES}
# )

# set_source_files_properties(
# ${BUILD__FAT16__MOUNT__BLOCKER__DMG_RESOURCES}
#    PROPERTIES
#       MACOSX_PACKAGE_LOCATION
#       Resources
# )
