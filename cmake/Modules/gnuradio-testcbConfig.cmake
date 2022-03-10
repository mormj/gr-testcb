find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_TESTCB gnuradio-testcb)

FIND_PATH(
    GR_TESTCB_INCLUDE_DIRS
    NAMES gnuradio/testcb/api.h
    HINTS $ENV{TESTCB_DIR}/include
        ${PC_TESTCB_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_TESTCB_LIBRARIES
    NAMES gnuradio-testcb
    HINTS $ENV{TESTCB_DIR}/lib
        ${PC_TESTCB_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-testcbTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_TESTCB DEFAULT_MSG GR_TESTCB_LIBRARIES GR_TESTCB_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_TESTCB_LIBRARIES GR_TESTCB_INCLUDE_DIRS)
