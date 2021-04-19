

file(GLOB HEADER_LIST "${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}/*.hpp")
file(GLOB SOURCE_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)

# foreach(file ${CMAKE_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}/concepts)
#     source_group ("${CMAKE_PROJECT_NAME}/Header Files/concepts" FILES ${file})
#     # message (${file})
# endforeach()


set (self ${PROJECT_NAME})



add_library (${self} STATIC 
	${SOURCE_LIST}  ${HEADER_LIST} 
)
# file(GLOB_RECURSE CONCEPTS_LIST include/parser/concepts/*.hpp)

# source_group(TREE   ${CMAKE_CURRENT_SOURCE_DIR}
#                PREFIX "Magic\\Sources"
#                FILES  ${CONCEPTS_LIST}
# )
foreach (file ${PROJECT_SOURCE_DIR}/include/${self}/concepts)
    target_sources (${self} PRIVATE ${file})
    source_group("Header Files" FILES ${file})
endforeach ()

foreach (file ${PROJECT_SOURCE_DIR}/include/${self}/operators/comparison)
    target_sources (${self} PRIVATE ${file})
    source_group("Header Files" FILES ${file})
endforeach ()



# source_group (TREE ${PROJECT_SOURCE_DIR} FILES ${CONCEPTS_LIST})


ph_precompile (TARGET ${self} PUBLIC PCH ${std_pch})

add_library (ph::expression_templates ALIAS ${self})
# target_link_libraries (${self} PUBLIC ${Boost_LIBRARIES})
target_include_directories (${self} PUBLIC ${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})
# target_include_directories (${self} PUBLIC ph::coroutines)
target_compile_features (${self} PUBLIC cxx_std_20)


target_include_directories(${self} PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/${self}>
    $<INSTALL_INTERFACE:include/${self}>
)

target_include_directories(${self} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

else()
    set_target_properties(${PROJECT_NAME}          PROPERTIES FOLDER "dependencies/${PROJECT_NAME}")
endif()