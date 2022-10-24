#include <gtest/gtest.h>
#include "linkedhashset.h"
#include <string>

//student.h

//constructor

TEST(ConstructorStudentTest, Declaration) {
    student student1(18, "Alina Vasilyeva");
    EXPECT_EQ(student1.name_, "Alina Vasilyeva");
    EXPECT_EQ(student1.age_, 18);
}

//operator!=()

TEST(OperatorNotEqStudentsTest, NotEqStudents) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    students.insert(student2);
    bool s1 = student1.age_ == student2.age_ && student1.name_ == student2.name_;
    bool s2 = student1 != student2;
    EXPECT_FALSE(s1 == s2);
}

//operator==()

TEST(OperatorEqStudentsTest, EqStudents) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    std::string name2 = "Sasha Ivanov";
    student student2(18, name2);
    students.insert(student2);
    bool s1 = student1.age_ == student2.age_ && student1.name_ == student2.name_;
    bool s2 = student1 == student2;
    EXPECT_TRUE(s1 == s2);
}

//linkedhs.h

//operator==()

TEST(OperatorEqListsTest, EqListInTheSameOrder) {
    linkedhs students1;
    student student11(18, "Sasha Ivanov");
    students1.insert(student11);
    student student21(15, "Nastya Kim");
    students1.insert(student21);
    student student31(18, "Katya Kim");
    students1.insert(student31);
    student student41(19, "Rimma Kats");
    students1.insert(student41);
    linkedhs students2;
    student student12(18, "Sasha Ivanov");
    students2.insert(student12);
    student student22(15, "Nastya Kim");
    students2.insert(student22);
    student student32(18, "Katya Kim");
    students2.insert(student32);
    student student42(19, "Rimma Kats");
    students2.insert(student42);
    bool s1 = students1 == students2;
    EXPECT_TRUE(s1);
}

TEST(OperatorEqListsTest, EqListNotInTheSameOrder) {
    linkedhs students1;
    student student11(18, "Sasha Ivanov");
    students1.insert(student11);
    student student21(15, "Nastya Kim");
    students1.insert(student21);
    student student31(18, "Katya Kim");
    students1.insert(student31);
    student student41(19, "Rimma Kats");
    students1.insert(student41);
    linkedhs students2;
    student student32(18, "Katya Kim");
    students2.insert(student32);
    student student42(19, "Rimma Kats");
    students2.insert(student42);
    student student22(15, "Nastya Kim");
    students2.insert(student22);
    student student12(18, "Sasha Ivanov");
    students2.insert(student12);
    bool s1 = students1 == students2;
    EXPECT_TRUE(s1);
}

//operator!=()

TEST(OperatorNotEqListsTest, NotEqList) {
    linkedhs students1;
    student student11(18, "Sasha Ivanov");
    students1.insert(student11);
    student student21(15, "Nastya Kim");
    students1.insert(student21);
    student student31(18, "Katya Kim");
    students1.insert(student31);
    student student41(19, "Rimma Kats");
    students1.insert(student41);
    linkedhs students2;
    student student12(18, "Sasha Ivanov");
    students2.insert(student12);
    student student22(15, "Nastya Ivanova");
    students2.insert(student22);
    student student32(18, "Katya Kim");
    students2.insert(student32);
    student student42(19, "Rimma Kats");
    students2.insert(student42);
    bool s1 = students1 == students2;
    EXPECT_FALSE(s1);
}

//clear()

TEST(ClearTest, ClearList) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    students.insert(student4);
    students.clear();
    bool s1 = students.contains(student1);
    bool s2 = students.contains(student2);
    bool s3 = students.contains(student3);
    bool s4 = students.contains(student4);
    EXPECT_FALSE(s1);
    EXPECT_FALSE(s2);
    EXPECT_FALSE(s3);
    EXPECT_FALSE(s4);
    EXPECT_EQ(students.size(), 0);
}

//size()  ПРОВЕРЬ КОГДА РЕМУВ

TEST(SizeTest, SizeOfList) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);

    EXPECT_EQ(students.size(), 3);
}

TEST(SizeTest, SizeOfListAfterRemoving) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(13, "Katya Kim");
    students.insert(student3);
    students.remove(student3);
    EXPECT_EQ(students.size(), 2);
}

TEST(SizeTest, SizeOfListAfterClearing) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(13, "Katya Kim");
    students.insert(student3);
    EXPECT_EQ(students.size(), 3);
    students.clear();
    EXPECT_EQ(students.size(), 0);
}

TEST(SizeTest, SizeOfListInCaseDoubling) {
    linkedhs students;
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student3(18, "Sasha Ivanov");
    students.insert(student3);
    EXPECT_EQ(students.size(), 2);
}

TEST(SizeTest, SizeOfEmptyList) {
    linkedhs students;
    EXPECT_EQ(students.size(), 0);
}

//copy constructor

TEST(CopyConstructorLinkedhsTest, CopyList) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    students.insert(student4);
    linkedhs studentsCopy(students);
    EXPECT_TRUE(studentsCopy == students);
}


TEST(CopyConstructorLinkedhsTest, CopiedListUfterRemovingInTheFirtst) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    students.insert(student4);
    linkedhs studentsCopy(students);
    students.remove(student2);
    EXPECT_EQ(students.size(), 3);
    EXPECT_EQ(studentsCopy.size(), 4);
    EXPECT_FALSE(studentsCopy == students);
}

TEST(CopyConstructorLinkedhsTest, CopiedListUfterRemovingInTheCopy) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    students.insert(student4);
    linkedhs studentsCopy(students);
    studentsCopy.remove(student2);
    EXPECT_EQ(students.size(), 4);
    EXPECT_EQ(studentsCopy.size(), 3);
    EXPECT_FALSE(studentsCopy == students);
}

//operator=

TEST(OperatorAssigningTest, AssigningToList) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    students.insert(student4);
    linkedhs studentsCopy = students;
    EXPECT_TRUE(studentsCopy == students);
}

//swap()

TEST(SwapTest, SwapingLists) {
    linkedhs students1;
    student student11(18, "Sasha Ivanov");
    students1.insert(student11);
    student student21(15, "Nastya Kim");
    students1.insert(student21);
    student student31(18, "Katya Kim");
    students1.insert(student31);
    student student41(19, "Rimma Kats");
    students1.insert(student41);
    linkedhs students2;
    student student12(18, "Sasha Ivanov");
    students2.insert(student12);
    student student22(15, "Nastya Ivanova");
    students2.insert(student22);
    student student32(18, "Katya Kim");
    students2.insert(student32);
    student student42(19, "Rimma Kats");
    students2.insert(student42);
    linkedhs tmp1(students1);
    linkedhs tmp2(students2);
    students1.swap(students2);
    EXPECT_TRUE(students1 == tmp2);
    EXPECT_TRUE(students2 == tmp1);
    EXPECT_FALSE(students1 == tmp1);
    EXPECT_FALSE(students2 == tmp2);
}

//contains()

TEST(ContainsTest, IfCOntainingCertainElement) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    bool s1 = students.contains(student2);
    bool s2 = students.contains(student4);
    EXPECT_TRUE(s1);
    EXPECT_FALSE(s2);
}

TEST(ContainsTest, IfEmptyList) {
    linkedhs students;
    student student1(19, "Rimma Kats");
    bool s1 = students.contains(student1);
    EXPECT_FALSE(s1);
}

//remove()

class RemoveTest : public ::testing::Test {
protected:
    void SetUp() {
        student1 = student(18, "Sasha Ivanov");
        students.insert(student1);
        student2 = student(15, "Nastya Kim");
        students.insert(student2);
        student3 = student(18, "Katya Kim");
        students.insert(student3);
        student4 = student(19, "Rimma Kats");
        students.insert(student4);
    }

    linkedhs students;
    student student1, student2, student3, student4;
};

TEST_F(RemoveTest, RemovingTheFirstElement) {
    bool s1 = students.contains(student1);
    size_t size1 = students.size();
    bool returnRemove = students.remove(student1);
    size_t size2 = students.size();
    bool s2 = students.contains(student1);
    EXPECT_TRUE(s1);
    EXPECT_EQ(size1, 4);
    EXPECT_EQ(size2, 3);
    EXPECT_FALSE(s2);
    EXPECT_TRUE(returnRemove);
}

TEST_F(RemoveTest, RemovingTheLastElement) {
    bool s1 = students.contains(student4);
    size_t size1 = students.size();
    bool returnRemove = students.remove(student4);
    size_t size2 = students.size();
    bool s2 = students.contains(student4);
    EXPECT_TRUE(s1);
    EXPECT_EQ(size1, 4);
    EXPECT_EQ(size2, 3);
    EXPECT_FALSE(s2);
    EXPECT_TRUE(returnRemove);
}

TEST_F(RemoveTest, RemovingUnexistedElement) {
    student student6 = student(17, "Olga Pogibelnaya");
    bool returnRemove = students.remove(student6);
    size_t size2 = students.size();
    EXPECT_FALSE(returnRemove);
    EXPECT_EQ(size2, 4);
}

TEST_F(RemoveTest, RemovingTheMiddleElement) {
    bool s1 = students.contains(student3);
    size_t size1 = students.size();
    bool returnRemove = students.remove(student3);
    size_t size2 = students.size();
    bool s2 = students.contains(student3);
    EXPECT_TRUE(s1);
    EXPECT_EQ(size1, 4);
    EXPECT_EQ(size2, 3);
    EXPECT_FALSE(s2);
    EXPECT_TRUE(returnRemove);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
