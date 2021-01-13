set(files "src/main.cpp"
        "src/util/IMem.cpp"
        "src/util/Log.cpp"
        "src/util/RenderUtils.cpp"
        "src/util/InputUtils.cpp"
        "src/util/VersionUtils.cpp"
        "src/hooks/UIContextHook.cpp"
        "src/hooks/ClientInstanceHook.cpp"
        "src/hooks/KeyHook.cpp"
        "src/hooks/MouseHook.cpp"
        "src/modules/impl/Keystrokes.cpp"
        "src/modules/impl/ModInfo.cpp"
        )

target_sources(Incudine PRIVATE ${files})
target_link_libraries(Incudine LINK_PUBLIC "Version.lib")