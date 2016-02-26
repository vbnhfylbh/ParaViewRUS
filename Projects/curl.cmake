if(BUILD_SHARED_LIBS)
  set(shared_args -DBUILD_SHARED_LIBS:BOOL=ON -DCURL_STATICLIB:BOOL=OFF)
else()
  set(shared_args -DBUILD_SHARED_LIBS:BOOL=OFF -DCURL_STATICLIB:BOOL=ON)
endif()

add_external_project_or_use_system(curl

   GIT_REPOSITORY https://github.com/bagder/curl.git
   GIT_TAG "curl-7_31_0"

   CMAKE_ARGS
        -DBUILD_CURL_EXE:BOOL=OFF
        -DBUILD_CURL_TESTS:BOOL=OFF
        -DBUILD_DASHBOARD_REPORTS:BOOL=OFF
        -DCURL_USE_ARES:BOOL=OFF
        -DCURL_ZLIB:BOOL=${zlib_ENABLED}

        -DCMAKE_BUILD_TYPE:STRING=Release

        -DCMAKE_OSX_SYSROOT:PATH=${CMAKE_OSX_SYSROOT}
        -DCMAKE_OSX_ARCHITECTURES:STRING=${CMAKE_OSX_ARCHITECTURES}
        -DCMAKE_OSX_DEPLOYMENT_TARGET:STRING=${CMAKE_OSX_DEPLOYMENT_TARGET}

        ${shared_args}
)