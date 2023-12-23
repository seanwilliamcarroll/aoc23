file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.hpp)

add_custom_target(
        cppcheck
        COMMAND /opt/local/bin/cppcheck
        --enable=warning,performance,portability,information,missingInclude
        --std=c++17
        --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
        --verbose
        --quiet
        ${ALL_SOURCE_FILES}
)