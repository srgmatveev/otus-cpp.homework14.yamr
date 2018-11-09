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

TEST(SplitFilePos_TEST, SplitFilePos_Test_on_Exist_True)
{
    std::string f_name = "addresses.txt";
    std::size_t parts = 3;
    ASSERT_NO_THROW(splitFilePos(f_name, parts));
}

TEST(SplitFilePos_TEST, SplitFilePos_Test_on_Exist_False)
{
    std::string f_name = "addresses.txt1";
    std::size_t parts = 3;
    ASSERT_ANY_THROW(splitFilePos(f_name, parts));
}

TEST(SplitFilePos_TEST, SplitFilePos_Test_on_split)
{

    std::vector<std::streampos> tmp_vec;
    std::vector<std::streampos> result_vec{0, 94, 132};
    std::string f_name = "addresses.txt";
    std::size_t parts = 3;
    tmp_vec = splitFilePos(f_name, parts);
    ASSERT_THAT(tmp_vec.size(), 3);
    for (auto i = 0; i < tmp_vec.size(); ++i)
    {
        ASSERT_THAT(tmp_vec.at(i), result_vec.at(i));
    }
}

TEST(SplitFilePos_TEST, SplitFilePos_Test_on_empty)
{
    std::vector<std::streampos> tmp_vec;
    std::string f_name = "addr_empty.txt";
    std::size_t parts = 3;
    tmp_vec = splitFilePos(f_name, parts);
    ASSERT_THAT(tmp_vec.size(), 1);
    ASSERT_THAT(tmp_vec.at(0), 0);
}

TEST(SplitFilePos_TEST, SplitFilePos_Test_on_small_file)
{
    std::vector<std::streampos> tmp_vec;
    std::vector<std::streampos> result_vec{0, 20};
    std::string f_name = "one_address.txt";
    std::size_t parts = 12;
    tmp_vec = splitFilePos(f_name, parts);
    ASSERT_THAT(tmp_vec.size(), 2);
    for (auto i = 0; i < tmp_vec.size(); ++i)
    {
        ASSERT_THAT(tmp_vec.at(i), result_vec.at(i));
    }
}