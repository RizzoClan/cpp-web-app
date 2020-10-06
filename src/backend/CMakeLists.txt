cmake_minimum_required(VERSION 2.8)
project (backend)

add_executable(web_app backendController.cpp)
target_link_libraries(web_app ${Boost_LIBRARIES})
target_link_libraries(web_app ${CMAKE_THREAD_LIBS_INIT})

# Google's implementation of Malloc that is "faster" -- optional
if (Tcmalloc_FOUND)
	target_link_libraries(web_app ${Tcmalloc_LIBRARIES})
	# Add other binaries that might use this
else()
	message(WARNING "Tcmalloc not found")
endif(Tcmalloc_FOUND)

#SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -pg" )
#SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -g -pg" )
