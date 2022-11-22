cmake_minimum_required(VERSION 3.20)
project(TextEditor)

set(CMAKE_CXX_STANDARD 23)
add_subdirectory(google_test/googletest)
include_directories(google_test/googletest/googletest/include)
include_directories(C:/Users/Admin/CLionProjects/TextEditor/Tests)

add_executable(TextEditor main.cpp
        Parser.h StringEditor.h CommandInterface.h
        CommandListExecutor.h Copy.h CommandCreator.h
        Insert.h StringBuffer.h Paste.h Delete.h CopyCreator.h
        PasteCreator.h DeleteCreator.h InsertCreator.h Creators.h
        Parser.cpp Tests/Parser_tests.h StringBuffer.cpp Tests/StringBuffer_tests.h
        Exceptions.cpp Exceptions.h CommandInterface.cpp Copy.cpp Paste.cpp
        Insert.cpp Delete.cpp Commands.h Tests/Commands_tests.h CommandCreator.h
        CopyCreator.h Tests/Commands_tests.h Tests/Creators_tests.h
        StringEditor.cpp Tests/StringEditorTests.h CommandListExecutor.cpp
        Tests/CommandListExecutorTests.h)

target_link_libraries(TextEditor gtest gtest_main)