#include <gtest/gtest.h>
#include "linkedhs.h"
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

//iterator

//operator*()

TEST(OperatorDereferenceListsTest, Dereference) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    linkedhs::iterator it = linkedhs::iterator(students.head_);
    EXPECT_TRUE(*it == student1);
}

//operator!=()

TEST(OperatorNotEqIteratorTest, NotEqIterators) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Sasha Ivanova";
    student student21(13, name21);
    students1.insert(student21);
    linkedhs::iterator it1(students1.head_);
    linkedhs::iterator it2(students1.head_->next_);
    EXPECT_FALSE(it1 == it2);
}

//operator==()

TEST(OperatorEqIteratorTest, EqIterators) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Sasha Ivanova";
    student student21(13, name21);
    students1.insert(student21);
    linkedhs::iterator it1(students1.head_->next_);
    linkedhs::iterator it2(students1.head_->next_);
    EXPECT_TRUE(it1 == it2);
}

//operator++(int)

TEST(PostfixIncrementTest, PostfixIncrementForIterator) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Sasha Ivanova";
    student student21(13, name21);
    students1.insert(student21);
    linkedhs::iterator it1(students1.head_);
    linkedhs::iterator it2 = it1++;
    linkedhs::iterator it3(students1.head_->next_);
    EXPECT_TRUE(it2 == linkedhs::iterator(students1.head_));
    EXPECT_TRUE(it1 == it3);
}

//operator++()

TEST(PrefixIncrementTest, PrefixIncrementForIterator) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Sasha Ivanova";
    student student21(13, name21);
    students1.insert(student21);
    linkedhs::iterator it1(students1.head_);
    linkedhs::iterator it2 = ++it1;
    linkedhs::iterator it3(students1.head_->next_);
    EXPECT_TRUE(it2 == it3);
    EXPECT_TRUE(it1 == it3);
}

//operator--(int)

TEST(PostfixDecrementTest, PostfixDecrementForIterator) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Sasha Ivanova";
    student student21(13, name21);
    students1.insert(student21);
    linkedhs::iterator it1(students1.head_->next_);
    linkedhs::iterator it2 = it1--;
    linkedhs::iterator it3(students1.head_);
    EXPECT_TRUE(it2 == linkedhs::iterator(students1.head_->next_));
    EXPECT_TRUE(it1 == it3);
}

//operator--()

TEST(PrefixDecrementTest, PrefixDecrementForIterator) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Sasha Ivanova";
    student student21(13, name21);
    students1.insert(student21);
    linkedhs::iterator it1(students1.head_->next_);
    linkedhs::iterator it2 = --it1;
    linkedhs::iterator it3(students1.head_);
    EXPECT_TRUE(it2 == it3);
    EXPECT_TRUE(it1 == it3);
}

//linkedhs.h

//operator==()

TEST(OperatorEqListsTest, EqListInTheSameOrder) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Nastya Kim";
    student student21(15, name21);
    students1.insert(student21);
    std::string name31 = "Katya Kim";
    student student31(18, name31);
    students1.insert(student31);
    std::string name41 = "Rimma Kats";
    student student41(19, name41);
    students1.insert(student41);
    linkedhs students2;
    std::string name12 = "Sasha Ivanov";
    student student12(18, name12);
    students2.insert(student12);
    std::string name22 = "Nastya Kim";
    student student22(15, name22);
    students2.insert(student22);
    std::string name32 = "Katya Kim";
    student student32(18, name32);
    students2.insert(student32);
    std::string name42 = "Rimma Kats";
    student student42(19, name42);
    students2.insert(student42);
    bool s1 = students1 == students2;
    EXPECT_TRUE(s1);
}

TEST(OperatorEqListsTest, EqListNotInTheSameOrder) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Nastya Kim";
    student student21(15, name21);
    students1.insert(student21);
    std::string name31 = "Katya Kim";
    student student31(18, name31);
    students1.insert(student31);
    std::string name41 = "Rimma Kats";
    student student41(19, name41);
    students1.insert(student41);
    linkedhs students2;
    std::string name32 = "Katya Kim";
    student student32(18, name32);
    students2.insert(student32);
    std::string name42 = "Rimma Kats";
    student student42(19, name42);
    students2.insert(student42);
    std::string name22 = "Nastya Kim";
    student student22(15, name22);
    students2.insert(student22);
    std::string name12 = "Sasha Ivanov";
    student student12(18, name12);
    students2.insert(student12);
    bool s1 = students1 == students2;
    EXPECT_TRUE(s1);
}

//operator!=()

TEST(OperatorNotEqListsTest, NotEqList) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Nastya Kim";
    student student21(15, name21);
    students1.insert(student21);
    std::string name31 = "Katya Kim";
    student student31(18, name31);
    students1.insert(student31);
    std::string name41 = "Rimma Kats";
    student student41(19, name41);
    students1.insert(student41);
    linkedhs students2;
    std::string name12 = "Sasha Ivanov";
    student student12(18, name12);
    students2.insert(student12);
    std::string name22 = "Nastya Ivanova";
    student student22(15, name22);
    students2.insert(student22);
    std::string name32 = "Katya Kim";
    student student32(18, name32);
    students2.insert(student32);
    std::string name42 = "Rimma Kats";
    student student42(19, name42);
    students2.insert(student42);
    bool s1 = students1 == students2;
    EXPECT_FALSE(s1);
}

//clear()

TEST(ClearTest, ClearList) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    students.insert(student2);
    std::string name3 = "Katya Kim";
    student student3(18, name3);
    students.insert(student3);
    std::string name4 = "Rimma Kats";
    student student4(19, name4);
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

//size()

TEST(SizeTest, SizeOfList) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    students.insert(student2);
    std::string name3 = "Katya Kim";
    student student3(18, name3);
    students.insert(student3);

    EXPECT_EQ(students.size(), 3);
}

TEST(SizeTest, SizeOfListInCaseDoubling) {
    linkedhs students;
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    students.insert(student2);
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    student student3(18, name1);
    students.insert(student3);

    EXPECT_EQ(students.size(), 2);
}

TEST(SizeTest, SizeOfEmptyList) {
    linkedhs students;
    EXPECT_EQ(students.size(), 0);
}

//constructor

TEST(ConstructorLinkedhsTest, Declaration) {
    linkedhs students;
    EXPECT_EQ(students.size(), 0);
    EXPECT_EQ(students.head_, nullptr);
    EXPECT_EQ(students.last_, nullptr);
}

//copy constructor

TEST(CopyConstructorLinkedhsTest, CopyList) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    students.insert(student2);
    std::string name3 = "Katya Kim";
    student student3(18, name3);
    students.insert(student3);
    std::string name4 = "Rimma Kats";
    student student4(19, name4);
    students.insert(student4);
    linkedhs studentsCopy(students);
    EXPECT_TRUE(studentsCopy == students);
}

TEST(CopyConstructorLinkedhsTest, CopiedListUfterRemovingInTheFirtst) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    students.insert(student2);
    std::string name3 = "Katya Kim";
    student student3(18, name3);
    students.insert(student3);
    std::string name4 = "Rimma Kats";
    student student4(19, name4);
    students.insert(student4);
    linkedhs studentsCopy(students);
    students.remove(student2);
    EXPECT_EQ(students.size(), 3);
    EXPECT_EQ(studentsCopy.size(), 4);
    EXPECT_FALSE(studentsCopy == students);
}

TEST(CopyConstructorLinkedhsTest, CopiedListUfterRemovingInTheCopy) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    students.insert(student2);
    std::string name3 = "Katya Kim";
    student student3(18, name3);
    students.insert(student3);
    std::string name4 = "Rimma Kats";
    student student4(19, name4);
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
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    students.insert(student2);
    std::string name3 = "Katya Kim";
    student student3(18, name3);
    students.insert(student3);
    std::string name4 = "Rimma Kats";
    student student4(19, name4);
    students.insert(student4);
    linkedhs studentsCopy = students;
    EXPECT_TRUE(studentsCopy == students);
}

//insert()

TEST(InsertTest, Empty) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    bool s1 = students.insert(student1);

    EXPECT_TRUE(s1);
    EXPECT_EQ(students.size(), 1);
    EXPECT_EQ(students.head_->data_->age_, 18);
    EXPECT_EQ(students.head_->data_->name_, name1);
    EXPECT_EQ(students.head_->next_, nullptr);
}

TEST(InsertTest, AddingStudents) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    bool s1 = students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    bool s2 = students.insert(student2);

    EXPECT_TRUE(s1);
    EXPECT_EQ(students.head_->data_->age_, 18);
    EXPECT_EQ(students.head_->data_->name_, name1);
    EXPECT_TRUE(s2);
    EXPECT_EQ(students.head_->next_->data_->age_, 15);
    EXPECT_EQ(students.head_->next_->data_->name_, name2);
    EXPECT_EQ(students.head_->next_->next_, nullptr);
    EXPECT_EQ(students.size(), 2);
}

TEST(InsertTest, Doubling1) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    bool s1 = students.insert(student1);
    student student2(18, name1);
    bool s2 = students.insert(student2);

    EXPECT_TRUE(s1);
    EXPECT_EQ(students.head_->data_->age_, 18);
    EXPECT_EQ(students.head_->data_->name_, name1);
    EXPECT_FALSE(s2);
    EXPECT_EQ(students.head_->next_, nullptr);
    EXPECT_EQ(students.size(), 1);
}

TEST(InsertTest, Doubling2) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    bool s1 = students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    bool s2 = students.insert(student2);
    student student3(18, name1);
    bool s3 = students.insert(student3);

    EXPECT_TRUE(s1);
    EXPECT_EQ(students.head_->data_->age_, 18);
    EXPECT_EQ(students.head_->data_->name_, name1);
    EXPECT_TRUE(s2);
    EXPECT_EQ(students.head_->next_->data_->age_, 15);
    EXPECT_EQ(students.head_->next_->data_->name_, name2);
    EXPECT_FALSE(s3);
    EXPECT_EQ(students.head_->next_->next_, nullptr);
    EXPECT_EQ(students.size(), 2);
}

TEST(InsertTest, Doubling3) {
    linkedhs students;
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    bool s1 = students.insert(student2);
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    bool s2 = students.insert(student1);
    student student3(18, name1);
    bool s3 = students.insert(student3);

    EXPECT_TRUE(s1);
    EXPECT_EQ(students.head_->data_->age_, 15);
    EXPECT_EQ(students.head_->data_->name_, name2);
    EXPECT_TRUE(s2);
    EXPECT_EQ(students.head_->next_->data_->age_, 18);
    EXPECT_EQ(students.head_->next_->data_->name_, name1);
    EXPECT_FALSE(s3);
    EXPECT_EQ(students.head_->next_->next_, nullptr);
    EXPECT_EQ(students.size(), 2);
}

//swap()

TEST(SwapTest, SwapingLists) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Nastya Kim";
    student student21(15, name21);
    students1.insert(student21);
    std::string name31 = "Katya Kim";
    student student31(18, name31);
    students1.insert(student31);
    std::string name41 = "Rimma Kats";
    student student41(19, name41);
    students1.insert(student41);
    linkedhs students2;
    std::string name12 = "Sasha Ivanov";
    student student12(18, name12);
    students2.insert(student12);
    std::string name22 = "Nastya Ivanova";
    student student22(15, name22);
    students2.insert(student22);
    std::string name32 = "Katya Kim";
    student student32(18, name32);
    students2.insert(student32);
    std::string name42 = "Rimma Kats";
    student student42(19, name42);
    students2.insert(student42);
    linkedhs tmp1(students1);
    linkedhs tmp2(students2);
    students1.swap(students2);
    EXPECT_TRUE(students1 == tmp2);
    EXPECT_TRUE(students2 == tmp1);
    EXPECT_FALSE(students1 == tmp1);
    EXPECT_FALSE(students2 == tmp2);
}

//find()

TEST(FindTest, FindingCertainElement) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    students.insert(student2);
    std::string name3 = "Katya Kim";
    student student3(18, name3);
    students.insert(student3);
    linkedhs::iterator certainStudent = students.find(student2);
    linkedhs::iterator student(students.head_->next_);
    EXPECT_TRUE(certainStudent == student);
}

//contains()

TEST(ContainsTest, IfCOntainingCertainElement) {
    linkedhs students;
    std::string name1 = "Sasha Ivanov";
    student student1(18, name1);
    students.insert(student1);
    std::string name2 = "Nastya Kim";
    student student2(15, name2);
    students.insert(student2);
    std::string name3 = "Katya Kim";
    student student3(18, name3);
    students.insert(student3);
    std::string name4 = "Rimma Kats";
    student student4(19, name4);
    bool s1 = students.contains(student2);
    bool s2 = students.contains(student4);
    EXPECT_TRUE(s1);
    EXPECT_FALSE(s2);
}

TEST(ContainsTest, IfEmptyList) {
    linkedhs students;
    std::string name4 = "Rimma Kats";
    student student4(19, name4);
    bool s1 = students.contains(student4);
    EXPECT_FALSE(s1);
}

//remove()

class RemoveTest : public ::testing::Test {
protected:
    void SetUp() {
        std::string name1 = "Sasha Ivanov";
        student1 = student(18, name1);
        students.insert(student1);
        std::string name2 = "Nastya Kim";
        student2 = student(15, name2);
        students.insert(student2);
        std::string name3 = "Katya Kim";
        student3 = student(18, name3);
        students.insert(student3);
        std::string name4 = "Rimma Kats";
        student4 = student(19, name4);
        students.insert(student4);
    }

    linkedhs students;
    student student1, student2, student3, student4;
};

TEST_F(RemoveTest, RemovingTheFirstElement) {
    bool s1 = students.contains(student1);
    size_t size1 = students.size();
    students.remove(student1);
    size_t size2 = students.size();
    bool s2 = students.contains(student1);
    EXPECT_TRUE(s1);
    EXPECT_EQ(size1, 4);
    EXPECT_EQ(size2, 3);
    EXPECT_FALSE(s2);
}

TEST_F(RemoveTest, RemovingTheLastElement) {
    bool s1 = students.contains(student4);
    size_t size1 = students.size();
    students.remove(student4);
    size_t size2 = students.size();
    bool s2 = students.contains(student4);
    EXPECT_TRUE(s1);
    EXPECT_EQ(size1, 4);
    EXPECT_EQ(size2, 3);
    EXPECT_FALSE(s2);
}

TEST_F(RemoveTest, RemovingTheMiddleElement) {
    bool s1 = students.contains(student3);
    size_t size1 = students.size();
    students.remove(student3);
    size_t size2 = students.size();
    bool s2 = students.contains(student3);
    EXPECT_TRUE(s1);
    EXPECT_EQ(size1, 4);
    EXPECT_EQ(size2, 3);
    EXPECT_FALSE(s2);
}

//begin()

TEST(BeginTest, FindingBegin) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Nastya Kim";
    student student21(15, name21);
    students1.insert(student21);
    std::string name31 = "Katya Kim";
    student student31(18, name31);
    students1.insert(student31);
    std::string name41 = "Rimma Kats";
    student student41(19, name41);
    students1.insert(student41);
    EXPECT_TRUE(students1.begin() == linkedhs::iterator(students1.head_));
}

//end()

TEST(EndTest, FindingEnd) {
    linkedhs students1;
    std::string name11 = "Sasha Ivanov";
    student student11(18, name11);
    students1.insert(student11);
    std::string name21 = "Nastya Kim";
    student student21(15, name21);
    students1.insert(student21);
    std::string name31 = "Katya Kim";
    student student31(18, name31);
    students1.insert(student31);
    std::string name41 = "Rimma Kats";
    student student41(19, name41);
    students1.insert(student41);
    EXPECT_TRUE(students1.end() == linkedhs::iterator(students1.last_));
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}