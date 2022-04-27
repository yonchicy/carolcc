cmake_minimum_required(VERSION 2.6)

PROJECT(compiler)

FIND_PACKAGE(BISON REQUIRED)
SET(BISONOUTPUT ${CMAKE_SOURCE_DIR}/src/frontend/parser.cpp)

IF(BISON_FOUND)
    ADD_CUSTOM_COMMAND(
      OUTPUT ${BISONOUTPUT}
      COMMAND ${BISON_EXECUTABLE}
              --defines=${CMAKE_SOURCE_DIR}/src/frontend/parser.h
              --output=${BISONOUTPUT}
              ${CMAKE_SOURCE_DIR}/src/frontend/parser.y
      COMMENT "Generating parser.cpp"
    )
ENDIF()

FIND_PACKAGE(FLEX REQUIRED)
SET(FLEXOUTPUT ${CMAKE_SOURCE_DIR}/src/frontend/token.cpp)
IF(FLEX_FOUND)
    ADD_CUSTOM_COMMAND(
      OUTPUT ${FLEXOUTPUT}
      COMMAND ${FLEX_EXECUTABLE}
              --outfile=${FLEXOUTPUT}
              ${CMAKE_SOURCE_DIR}/src/frontend/token.l
      COMMENT "Generating scanner.cpp"
    )
ENDIF()

file(GLOB_RECURSE source_files "src/*.cpp")
add_compile_options(-g -std=c++17 -O2)

message("source is ${source_files}")
include_directories(src)


add_executable(${PROJECT_NAME} ${source_files} ${BISONOUTPUT} ${FLEXOUTPUT})

