#include "gmock/gmock.h"
#include "utils.h"
using namespace testing;

TEST(GetFileSize_TEST, GetFileSize_TEST_on_Exist_True)
{
    std::string f_name = "addresses.txt";
    ASSERT_NO_THROW(getFileSize(f_name));
}

TEST(GetFileSize_TEST, GetFileSize_TEST_File_Size)
{
    std::string f_name = "addresses.txt";
    ASSERT_EQ(getFileSize(f_name), 132);
}

TEST(SplitFile_TEST, SplitFile_Test_on_Exist_True)
{
    std::string f_name = "addresses.txt";
    std::size_t parts = 3;
    ASSERT_NO_THROW(splitFile(f_name, parts));
}

TEST(SplitFile_TEST, SplitFile_Test_on_Exist_False)
{
    std::string f_name = "addresses.txt1";
    std::size_t parts = 3;
    ASSERT_ANY_THROW(splitFile(f_name, parts));
}

TEST(SplitFile_TEST, SplitFile_Test_on_split)
{
}