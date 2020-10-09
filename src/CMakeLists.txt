target_sources(main_lib
    PUBLIC
        AddMenu.cpp
        aes.c
        Crypto.cpp
        ListMenu.cpp
        LoginInfo.cpp
        MainMenu.cpp
        Menu.cpp
        MenuContext.cpp
        SessionInfo.cpp
        SettingsMenu.cpp
        sha256.c
        StartMenu.cpp
        ViewMenu.cpp
)

target_include_directories(main_lib
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
)

target_compile_options(main_lib
    PRIVATE
        -Wall -Wextra
)

target_link_libraries(main_lib
    PRIVATE
        stdc++fs
)
