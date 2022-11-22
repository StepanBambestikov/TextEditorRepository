#include "Parser_tests.h"
#include "StringBuffer_tests.h"
#include "Commands_tests.h"
#include "Creators_tests.h"
#include "StringEditorTests.h"
#include "Tests/CommandListExecutorTests.h"

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
