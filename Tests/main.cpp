#include "StringBuffer_tests.h"
#include "InputStreamTests.h"

#include "ParserTests.h"

#include "CommandsDTOTests.h"
#include "CreatorsTests.h"
#include "CommandsTests.h"

#include "StringEditorTests.h"

#include "DTOProviderTests.h"
#include "CreatorProviderTests.h"
#include "CommandProviderTests.h"
#include "CommandListExecutorTests.h"

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
