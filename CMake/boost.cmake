
add_external_project(boost
  DEPENDS zlib
  CMAKE_ARGS
    -DBUILD_EXAMPLES:BOOL=OFF
    -DBUILD_TESTING:BOOL=OFF
    -DENABLE_STATIC:BOOL=ON
		-DENABLE_SHARED:BOOL=ON
    -DWITH_BZIP2:BOOL=OFF
    -DWITH_DOXYGEN:BOOL=OFF
    -DWITH_EXPAT:BOOL=OFF
    -DWITH_MPI:BOOL=OFF
    -DWITH_PYTHON:BOOL=OFF
)

