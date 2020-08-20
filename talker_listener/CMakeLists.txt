cmake_minimum_required(VERSION 3.10)
project(talker_listener LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_USE_RELATIVE_PATHS True)
set(CMAKE_CXX_STANDARD 17)


find_package(nanoros REQUIRED)


include_directories(${nanoros_INCLUDE_DIR})
include_directories(${nanoros_PACKER_INCLUDE_DIR})
link_directories(${nanoros_LIB_DIR})

set(EXT_LIBRARIES nanoros)

function(add_app NAME)
add_executable(${NAME} ${NAME}.cpp)
target_link_libraries(${NAME} ${EXT_LIBRARIES})
set_target_properties(${NAME}
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${PKGNAME}"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${PKGNAME}"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${PKGNAME}" 
)
endfunction(add_app)


add_app(talker)
add_app(listener)

