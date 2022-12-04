cmake_minimum_required(VERSION 3.20)
project(TextEditor)

set(CMAKE_CXX_STANDARD 23)
add_subdirectory(google_test/googletest)
include_directories(google_test/googletest/googletest/include)
include_directories(C:/Users/Admin/CLionProjects/TextEditor/Tests)
include_directories(C:/Users/Admin/CLionProjects/TextEditor/TextEditorLib)

add_executable(TextEditor TextEditorLib/StringEditor.h TextEditorLib/CommandInterface.h
        TextEditorLib/CommandListExecutor.h TextEditorLib/Copy.h TextEditorLib/CommandCreator.h
        TextEditorLib/Insert.h TextEditorLib/StringBuffer.h TextEditorLib/Paste.h TextEditorLib/Delete.h
        TextEditorLib/CopyCreator.h TextEditorLib/PasteCreator.h TextEditorLib/DeleteCreator.h
        TextEditorLib/InsertCreator.h TextEditorLib/Creators.h TextEditorLib/StringBuffer.cpp Tests/StringBuffer_tests.h
        TextEditorLib/Exceptions.cpp TextEditorLib/Exceptions.h
        TextEditorLib/Copy.cpp TextEditorLib/Paste.cpp TextEditorLib/Insert.cpp
        TextEditorLib/Delete.cpp TextEditorLib/Commands.h Tests/CommandsTests.h TextEditorLib/CommandCreator.h
        TextEditorLib/CopyCreator.h Tests/CommandsTests.h Tests/CreatorsTests.h
        TextEditorLib/StringEditor.cpp Tests/StringEditorTests.h TextEditorLib/CommandListExecutor.cpp
        Tests/CommandListExecutorTests.h Tests/main.cpp TextEditorLib/CommandDTO.h TextEditorLib/CopyDTO.h
        TextEditorLib/PasteDTO.h TextEditorLib/InsertDTO.h TextEditorLib/DeleteDTO.h TextEditorLib/CopyDTO.cpp
        TextEditorLib/PasteDTO.cpp TextEditorLib/InsertDTO.cpp TextEditorLib/DeleteDTO.cpp
        Tests/CommandsDTOTests.h Tests/InputStreamTests.h TextEditorLib/InputStream.h TextEditorLib/CommandParser.h
        TextEditorLib/DTO.h Tests/CommandParserTests.h TextEditorLib/CommandParser.cpp TextEditorLib/InputStream.cpp
        TextEditorLib/CommandCreator.cpp TextEditorLib/UndoDTO.h TextEditorLib/RedoDTO.h TextEditorLib/UndoDTO.h
        TextEditorLib/RedoCreator.h TextEditorLib/Redo.h TextEditorLib/Undo.h TextEditorLib/CommandProvider.h
        TextEditorLib/CommandProviderFromCreator.cpp TextEditorLib/CreatorProvider.h TextEditorLib/CreatorProviderFromDTO.cpp
        TextEditorLib/DTOProvider.h TextEditorLib/DTOProviderFromParser.cpp TextEditorLib/Parser.h TextEditorLib/Parser.cpp
        TextEditorLib/InsertCreator.cpp TextEditorLib/CopyCreator.cpp TextEditorLib/PasteCreator.cpp TextEditorLib/DeleteCreator.cpp
        TextEditorLib/UndoCreator.cpp TextEditorLib/RedoCreator.cpp Tests/ParserTests.h
        Tests/DTOProviderTests.h Tests/CreatorProviderTests.h Tests/CommandProviderTests.h
        TextEditorLib/DTOProviderFromParser.h TextEditorLib/CreatorProviderFromDTO.h TextEditorLib/CommandProviderFromCreator.h)


target_link_libraries(TextEditor gtest gtest_main)