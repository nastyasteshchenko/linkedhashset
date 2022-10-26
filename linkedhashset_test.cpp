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

TEST(OperatorNotEqStudentsTest, NotEqForEqStudents) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(18, "Sasha Ivanov");
    students.insert(student2);
    bool s1 = student1 != student2;
    EXPECT_FALSE(s1);
}

TEST(OperatorNotEqStudentsTest, NotEqForNotEqStudents) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    bool s1 = student1 != student2;
    EXPECT_TRUE(s1);
}

//operator==()

TEST(OperatorEqStudentsTest, EqForEqStudents) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(18, "Sasha Ivanov");
    students.insert(student2);
    bool s1 = student1 == student2;
    EXPECT_TRUE(s1);
}

TEST(OperatorEqStudentsTest, EqForNotEqStudents) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(16, "Sasha Ivanov");
    students.insert(student2);
    bool s1 = student1 == student2;
    EXPECT_FALSE(s1);
}

//linkedhs.h

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


TEST(CopyConstructorLinkedhsTest, CopiedListUfterRemovingInTheFirst) {
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

TEST(CopyConstructorLinkedhsTest, CopiedListUfterClearingInTheCopy) {
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
    studentsCopy.clear();
    EXPECT_EQ(students.size(), 4);
    EXPECT_EQ(studentsCopy.size(), 0);
    EXPECT_FALSE(studentsCopy == students);
}

TEST(CopyConstructorLinkedhsTest, CopiedListUfterClearingInTheFirst) {
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
    students.clear();
    EXPECT_EQ(students.size(), 0);
    EXPECT_EQ(studentsCopy.size(), 4);
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
    linkedhs studentsTmp = students;
    EXPECT_TRUE(studentsTmp == students);
}

TEST(OperatorAssigningTest, AssigningToListAndClearing1) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    students.insert(student4);
    linkedhs studentsTmp = students;
    EXPECT_TRUE(studentsTmp == students);
    students.clear();
    EXPECT_EQ(students.size(), 0);
    EXPECT_EQ(studentsTmp.size(), 4);
    EXPECT_TRUE(studentsTmp != students);
}

TEST(OperatorAssigningTest, AssigningToListAndClearing2) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    students.insert(student4);
    linkedhs studentsTmp = students;
    EXPECT_TRUE(studentsTmp == students);
    studentsTmp.clear();
    EXPECT_EQ(students.size(), 4);
    EXPECT_EQ(studentsTmp.size(), 0);
    EXPECT_TRUE(studentsTmp != students);
}

//operator==()

TEST(OperatorEqListsTest, EqForEqListInTheSameOrder) {
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

TEST(OperatorEqListsTest, EqForNotEqListInTheSameOrder) {
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
    student student32(18, "Kostya Kim");
    students2.insert(student32);
    student student42(19, "Rimma Kats");
    students2.insert(student42);
    bool s1 = students1 == students2;
    EXPECT_FALSE(s1);
}

TEST(OperatorEqListsTest, EqForEqListNotInTheSameOrder) {
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

TEST(OperatorEqListsTest, EqForNotEqListNotInTheSameOrder) {
    linkedhs students1;
    student student11(18, "Sasha Ivanov");
    students1.insert(student11);
    student student21(15, "Nastya Kim");
    students1.insert(student21);
    student student31(18, "Kostya Kim");
    students1.insert(student31);
    student student41(19, "Masha Kats");
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
    EXPECT_FALSE(s1);
}

//operator!=()

TEST(OperatorNotEqListsTest, NotEqForNotEqList) {
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
    bool s1 = students1 != students2;
    EXPECT_TRUE(s1);
}

TEST(OperatorNotEqListsTest, NotEqForEqList) {
    linkedhs students1;
    student student11(18, "Sasha Ivanov");
    students1.insert(student11);
    student student21(15, "Nastya Ivanova");
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
    bool s1 = students1 != students2;
    EXPECT_FALSE(s1);
}

//insert

//insert()

TEST(InsertTest, Empty) {
    linkedhs students;
    student arrOfStudent[1];
    arrOfStudent[0] = student(18, "Sasha Ivanov");
    bool s1 = students.insert(arrOfStudent[0]);
    EXPECT_TRUE(s1);
    EXPECT_EQ(students.size(), 1);
    auto begin = students.begin();
    auto it = begin;
    auto end = students.end();
    int i = 0;
    while (it != end) {
        EXPECT_EQ(it->age_, arrOfStudent[i].age_);
        EXPECT_EQ(it->name_, arrOfStudent[i].name_);
        it++;
        i++;
    }
}

TEST(InsertTest, TwoElements) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    EXPECT_TRUE(students.insert(s1));
    EXPECT_EQ(students.size(), 1);

    student s2(15, "Nastya Kim");
    EXPECT_TRUE(students.insert(s2));
    EXPECT_EQ(students.size(), 2);

    EXPECT_TRUE(students.contains(s1));
    EXPECT_TRUE(students.contains(s2));

    // student arrOfStudent[2];
    // arrOfStudent[0] = student(18, "Sasha Ivanov");
    // bool s1 = students.insert(arrOfStudent[0]);
    // EXPECT_TRUE(s1);
    // arrOfStudent[1] = student(15, "Nastya Kim");
    // bool s2 = students.insert(arrOfStudent[1]);
    // EXPECT_TRUE(s2);
    // EXPECT_EQ(students.size(), 2);
    // auto begin = students.begin();
    // auto it = begin;
    // auto end = students.end();
    // int i = 0;
    // while (it != end) {
    //     EXPECT_EQ(it->age_, arrOfStudent[i].age_);
    //     EXPECT_EQ(it->name_, arrOfStudent[i].name_);
    //     it++;
    //     i++;
    // }
}

TEST(InsertTest, SameElement) {
      linkedhs students;
    student s1(18, "Sasha Ivanov");
    EXPECT_TRUE(students.insert(s1));
    EXPECT_EQ(students.size(), 1);
    EXPECT_TRUE(students.contains(s1));

    EXPECT_FALSE(students.insert(s1));
    EXPECT_EQ(students.size(), 1);


    // linkedhs students;
    // student arrOfStudent[2];
    // arrOfStudent[0] = student(18, "Sasha Ivanov");
    // bool s1 = students.insert(arrOfStudent[0]);
    // EXPECT_TRUE(s1);
    // arrOfStudent[1] = student(18, "Sasha Ivanov");
    // bool s2 = students.insert(arrOfStudent[1]);
    // EXPECT_FALSE(s2);
    // EXPECT_EQ(students.size(), 1);
    // auto begin = students.begin();
    // auto it = begin;
    // auto end = students.end();
    // int i = 0;
    // while (it != end) {
    //     EXPECT_EQ(it->age_, arrOfStudent[i].age_);
    //     EXPECT_EQ(it->name_, arrOfStudent[i].name_);
    //     it++;
    //     i++;
    // }
}

TEST(InsertTest, Doubling2) {
    linkedhs students;
    student arrOfStudent[3];
    arrOfStudent[0] = student(18, "Sasha Ivanov");
    bool s1 = students.insert(arrOfStudent[0]);
    EXPECT_TRUE(s1);
    arrOfStudent[1] = student(15, "Nastya Kim");
    bool s2 = students.insert(arrOfStudent[1]);
    EXPECT_TRUE(s2);
    arrOfStudent[2] = student(18, "Sasha Ivanov");
    bool s3 = students.insert(arrOfStudent[2]);
    EXPECT_FALSE(s3);
    EXPECT_EQ(students.size(), 2);
    auto begin = students.begin();
    auto it = begin;
    auto end = students.end();
    int i = 0;
    while (it != end) {
        EXPECT_EQ(it->age_, arrOfStudent[i].age_);
        EXPECT_EQ(it->name_, arrOfStudent[i].name_);
        it++;
        i++;
    }
}

TEST(InsertTest, Doubling3) {
    linkedhs students;
    student arrOfStudent[3];
    arrOfStudent[0] = student(15, "Nastya Kim");
    bool s1 = students.insert(arrOfStudent[0]);
    EXPECT_TRUE(s1);
    arrOfStudent[1] = student(18, "Sasha Ivanov");
    bool s2 = students.insert(arrOfStudent[1]);
    EXPECT_TRUE(s2);
    arrOfStudent[2] = student(18, "Sasha Ivanov");
    bool s3 = students.insert(arrOfStudent[2]);
    EXPECT_FALSE(s3);
    EXPECT_EQ(students.size(), 2);
    auto begin = students.begin();
    auto it = begin;
    auto end = students.end();
    int i = 0;
    while (it != end) {
        EXPECT_EQ(it->age_, arrOfStudent[i].age_);
        EXPECT_EQ(it->name_, arrOfStudent[i].name_);
        it++;
        i++;
    }
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
    EXPECT_TRUE(s1);
    size_t size1 = students.size();
    bool returnRemove = students.remove(student1);
    EXPECT_TRUE(returnRemove);
    size_t size2 = students.size();
    bool s2 = students.contains(student1);
    EXPECT_FALSE(s2);
    EXPECT_EQ(size1, 4);
    EXPECT_EQ(size2, 3);

}

TEST_F(RemoveTest, RemovingTheLastElement) {
    bool s1 = students.contains(student4);
    EXPECT_TRUE(s1);
    size_t size1 = students.size();
    bool returnRemove = students.remove(student4);
    EXPECT_TRUE(returnRemove);
    size_t size2 = students.size();
    bool s2 = students.contains(student4);
    EXPECT_FALSE(s2);
    EXPECT_EQ(size1, 4);
    EXPECT_EQ(size2, 3);
}

TEST_F(RemoveTest, RemovingUnexistedElement) {
    student student6 = student(17, "Olga Pogibelnaya");
    bool returnRemove = students.remove(student6);
    EXPECT_FALSE(returnRemove);
    size_t size2 = students.size();
    EXPECT_EQ(size2, 4);
}

TEST_F(RemoveTest, RemovingTheMiddleElement) {
    bool s1 = students.contains(student3);
    EXPECT_TRUE(s1);
    size_t size1 = students.size();
    bool returnRemove = students.remove(student3);
    EXPECT_TRUE(returnRemove);
    size_t size2 = students.size();
    bool s2 = students.contains(student3);
    EXPECT_FALSE(s2);
    EXPECT_EQ(size1, 4);
    EXPECT_EQ(size2, 3);
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

//size()

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

//empty()

TEST(EmptyTest, EmptyList) {
    linkedhs students;
    EXPECT_TRUE(students.empty());
}

TEST(EmptyTest, NotEmptyList) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(13, "Katya Kim");
    students.insert(student3);
    EXPECT_FALSE(students.empty());
}

//contains()

TEST(ContainsTest, IfContainingCertainElement) {
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

TEST(ContainsTest, Empty) {
    linkedhs students;
    student student1(19, "Rimma Kats");
    bool s1 = students.contains(student1);
    EXPECT_FALSE(s1);
}

//find()

TEST(FindTest, FindingCertainElement) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    auto certainStudent = students.find(student2);
    EXPECT_TRUE(certainStudent->name_ == student2.name_ && certainStudent->age_ == student2.age_);
}

TEST(FindTest, FindingNotExistedCertainElement) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    auto certainStudent = students.find(student4);
    auto it = students.end();
    EXPECT_TRUE(certainStudent == it);
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
    EXPECT_FALSE(s1);
    bool s2 = students.contains(student2);
    EXPECT_FALSE(s2);
    bool s3 = students.contains(student3);
    EXPECT_FALSE(s3);
    bool s4 = students.contains(student4);
    EXPECT_FALSE(s4);
    EXPECT_EQ(students.size(), 0);
}

//begin()

TEST(BeginTest, Begin) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    students.insert(student4);
    auto it = students.begin();
    EXPECT_EQ(it->age_, student1.age_);
    EXPECT_EQ(it->name_, student1.name_);
}

//end()

TEST(EndTest, End) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    students.insert(student4);
    auto it = students.end();
    it--;
    EXPECT_EQ(it->age_, student4.age_);
    EXPECT_EQ(it->name_, student4.name_);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
