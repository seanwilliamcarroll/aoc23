file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h)

add_custom_target(
        clang-format
        COMMAND /opt/local/bin/clang-format-mp-17
        -style=LLVM
        -i
        ${ALL_SOURCE_FILES}
)