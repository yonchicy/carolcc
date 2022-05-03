cmake_minimum_required(VERSION 3.16)

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
      COMMENT "Generating token.cpp"
    )
ENDIF()

FILE(GLOB_RECURSE source_files "src/*.cpp")
ADD_COMPILE_OPTIONS(-g -std=c++17 -O2)

MESSAGE("source is ${source_files}")
SET(INCLUDE_DIRECTORIES ./ )
INCLUDE_DIRECTORIES(src/)



ADD_EXECUTABLE(${PROJECT_NAME} ${source_files} ${BISONOUTPUT} ${FLEXOUTPUT})

