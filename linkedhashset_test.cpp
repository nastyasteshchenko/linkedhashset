#include <gtest/gtest.h>
#include "linkedhashset.h"

//linkedhs

//constructor

TEST(ConstructorTest, Constructor) {
    linkedhs students;
    EXPECT_EQ(students.size(), 0);
}

//insert()

TEST(InsertTest, Empty) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    EXPECT_TRUE(students.insert(s1));
    EXPECT_EQ(students.size(), 1);

    EXPECT_TRUE(students.contains(s1));
}

TEST(InsertTest, ThreeElements) {
    linkedhs students;
    student s1 = student(18, "Sasha Ivanov");
    EXPECT_TRUE(students.insert(s1));
    EXPECT_EQ(students.size(), 1);

    student s2 = student(12, "Sasha Kim");
    EXPECT_TRUE(students.insert(s2));
    EXPECT_EQ(students.size(), 2);

    student s3 = student(16, "Katya Ivanova");
    EXPECT_TRUE(students.insert(s3));
    EXPECT_EQ(students.size(), 3);

    EXPECT_TRUE(students.contains(s1));
    EXPECT_TRUE(students.contains(s2));
    EXPECT_TRUE(students.contains(s3));
}

TEST(InsertTest, EqElements) {
    linkedhs students;
    student s1 = student(18, "Sasha Ivanov");
    EXPECT_TRUE(students.insert(s1));
    EXPECT_EQ(students.size(), 1);

    student s2 = student(12, "Sasha Kim");
    EXPECT_TRUE(students.insert(s2));
    EXPECT_EQ(students.size(), 2);

    student s3 = student(18, "Sasha Ivanov");
    EXPECT_FALSE(students.insert(s3));
    EXPECT_EQ(students.size(), 2);

    EXPECT_TRUE(students.contains(s1));
    EXPECT_TRUE(students.contains(s2));
}

//swap()

TEST(SwapTest, Empty) {
    linkedhs students1;
    linkedhs students2;
    students1.swap(students2);
    EXPECT_TRUE(students1.empty());
    EXPECT_TRUE(students2.empty());
}

TEST(SwapTest, SwapingTwoLists) {
    linkedhs students1;
    student s11(18, "Sasha Ivanov");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Katya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Ivanova");
    students2.insert(s22);
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);

    linkedhs tmp1(students1);
    linkedhs tmp2(students2);
    students1.swap(students2);
    EXPECT_TRUE(students1 == tmp2);
    EXPECT_TRUE(students2 == tmp1);
    EXPECT_FALSE(students1 == tmp1);
    EXPECT_FALSE(students2 == tmp2);
}

//size()

TEST(SizeTest, EmptyList) {
    linkedhs students;
    EXPECT_EQ(students.size(), 0);
}

TEST(SizeTest, NotEmptyLists) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    EXPECT_EQ(students.size(), 1);

    student s2(15, "Nastya Kim");
    students.insert(s2);
    EXPECT_EQ(students.size(), 2);

    student s3(18, "Katya Kim");
    students.insert(s3);
    EXPECT_EQ(students.size(), 3);
}

TEST(SizeTest, SizeOfListAfterRemoving) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    EXPECT_EQ(students.size(), 1);

    student s2(15, "Nastya Kim");
    students.insert(s2);
    EXPECT_EQ(students.size(), 2);

    student s3(13, "Katya Kim");
    students.insert(s3);
    EXPECT_EQ(students.size(), 3);

    students.remove(s3);
    EXPECT_EQ(students.size(), 2);
}

TEST(SizeTest, SizeOfListAfterClearing) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    EXPECT_EQ(students.size(), 1);

    student s2(15, "Nastya Kim");
    students.insert(s2);
    EXPECT_EQ(students.size(), 2);

    student s3(13, "Katya Kim");
    students.insert(s3);
    EXPECT_EQ(students.size(), 3);

    students.clear();
    EXPECT_EQ(students.size(), 0);
}

TEST(SizeTest, EqElements) {
    linkedhs students;
    student s1(15, "Nastya Kim");
    students.insert(s1);
    EXPECT_EQ(students.size(), 1);

    student s2(18, "Sasha Ivanov");
    students.insert(s2);
    EXPECT_EQ(students.size(), 2);

    student s3(18, "Sasha Ivanov");
    students.insert(s3);
    EXPECT_EQ(students.size(), 2);
}

//empty()

TEST(EmptyTest, EmptyList) {
    linkedhs students;
    EXPECT_TRUE(students.empty());
}

TEST(EmptyTest, NotEmptyList) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(13, "Katya Kim");
    students.insert(s3);
    EXPECT_FALSE(students.empty());
}

//contains()

TEST(ContainsTest, ExistedElement) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    EXPECT_TRUE(students.contains(student2));
}

TEST(ContainsTest, UnexistedElement) {
    linkedhs students;
    student student1(18, "Sasha Ivanov");
    students.insert(student1);
    student student2(15, "Nastya Kim");
    students.insert(student2);
    student student3(18, "Katya Kim");
    students.insert(student3);
    student student4(19, "Rimma Kats");
    EXPECT_FALSE(students.contains(student4));
}

TEST(ContainsTest, Empty) {
    linkedhs students;
    student s1(19, "Rimma Kats");
    EXPECT_FALSE(students.contains(s1));
}

//find()

TEST(FindTest, Empty) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    EXPECT_FALSE(students.contains(s1));
    EXPECT_TRUE(students.find(s1) == students.end());
}

TEST(FindTest, ExistedElement) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(18, "Katya Kim");
    students.insert(s3);
    EXPECT_TRUE(students.contains(s3));
    EXPECT_TRUE(students.find(s3) != students.end());
}

TEST(FindTest, UnexistedElement) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(18, "Katya Kim");
    students.insert(s3);
    student s4(19, "Rimma Kats");
    EXPECT_FALSE(students.contains(s4));
    EXPECT_TRUE(students.find(s4) == students.end());
}

//clear()

TEST(ClearTest, Empty) {
    linkedhs students;
    EXPECT_EQ(students.size(), 0);

    students.clear();
    EXPECT_EQ(students.size(), 0);
}

TEST(ClearTest, NotEmpty) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(18, "Katya Kim");
    students.insert(s3);
    student s4(19, "Rimma Kats");
    students.insert(s4);
    EXPECT_TRUE(students.contains(s1));
    EXPECT_TRUE(students.contains(s2));
    EXPECT_TRUE(students.contains(s3));
    EXPECT_TRUE(students.contains(s4));
    EXPECT_EQ(students.size(), 4);

    students.clear();
    EXPECT_FALSE(students.contains(s1));
    EXPECT_FALSE(students.contains(s2));
    EXPECT_FALSE(students.contains(s3));
    EXPECT_FALSE(students.contains(s4));
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
    EXPECT_EQ(students.begin()->age_, student1.age_);
    EXPECT_EQ(students.begin()->name_, student1.name_);
}

//end()

TEST(EndTest, End) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(18, "Katya Kim");
    students.insert(s3);
    student s4(19, "Rimma Kats");
    students.insert(s4);
    EXPECT_EQ((--students.end())->age_, s4.age_);
    EXPECT_EQ((--students.end())->name_, s4.name_);
}

//operator=()

TEST(OperatorAssigningTest, Empty) {
    linkedhs students;
    const linkedhs &studentsTmp = students;
    EXPECT_TRUE(studentsTmp.empty());
    EXPECT_TRUE(studentsTmp == students);
}

TEST(OperatorAssigningTest, NotEmpty) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(18, "Katya Kim");
    students.insert(s3);
    student s4(19, "Rimma Kats");
    students.insert(s4);
    linkedhs studentsTmp = students;
    EXPECT_FALSE(studentsTmp.empty());
    EXPECT_TRUE(studentsTmp == students);

    EXPECT_TRUE(studentsTmp.contains(s1));
    EXPECT_TRUE(studentsTmp.contains(s2));
    EXPECT_TRUE(studentsTmp.contains(s3));
    EXPECT_TRUE(studentsTmp.contains(s4));
}

TEST(OperatorAssigningTest, NotEmptyBoth) {
    linkedhs students1;
    student s11(18, "Masha Ivanova");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Katya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Kim");
    students2.insert(s22);
    student s32(18, "Kostya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);

    students1 = students2;

    EXPECT_FALSE(students1.empty());
    EXPECT_TRUE(students1 == students2);

    EXPECT_TRUE(students1.contains(s12));
    EXPECT_TRUE(students1.contains(s22));
    EXPECT_TRUE(students1.contains(s32));
    EXPECT_TRUE(students1.contains(s42));

    EXPECT_FALSE(students1.contains(s31));
}

TEST(OperatorAssigningTest, EqLinkedhs) {
    linkedhs students1;
    student s11(18, "Sasha Ivanov");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Katya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Kim");
    students2.insert(s22);
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);

    students1 = students2;
    EXPECT_FALSE(students1.empty());
    EXPECT_TRUE(students1 == students2);

    EXPECT_TRUE(students1.contains(s12));
    EXPECT_TRUE(students1.contains(s22));
    EXPECT_TRUE(students1.contains(s32));
    EXPECT_TRUE(students1.contains(s42));
}

TEST(OperatorAssigningTest, Removing) {
    linkedhs students1;
    student s11(18, "Masha Ivanova");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Kostya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Kim");
    students2.insert(s22);
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);

    students1 = students2;

    students2.remove(s22);
    EXPECT_EQ(students2.size(), 3);
    EXPECT_EQ(students1.size(), 4);
    EXPECT_FALSE(students1 == students2);

    EXPECT_TRUE(students1.contains(s12));
    EXPECT_TRUE(students1.contains(s22));
    EXPECT_TRUE(students1.contains(s32));
    EXPECT_TRUE(students1.contains(s42));

    EXPECT_TRUE(students2.contains(s12));
    EXPECT_FALSE(students2.contains(s22));
    EXPECT_TRUE(students2.contains(s32));
    EXPECT_TRUE(students2.contains(s42));
}

TEST(OperatorAssigningTest, RemovingInTheCopy) {
    linkedhs students1;
    student s11(18, "Masha Ivanova");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Kostya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Kim");
    students2.insert(s22);
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);

    students1 = students2;

    students1.remove(s22);
    EXPECT_EQ(students2.size(), 4);
    EXPECT_EQ(students1.size(), 3);
    EXPECT_FALSE(students1 == students2);

    EXPECT_TRUE(students1.contains(s12));
    EXPECT_FALSE(students1.contains(s22));
    EXPECT_TRUE(students1.contains(s32));
    EXPECT_TRUE(students1.contains(s42));

    EXPECT_TRUE(students2.contains(s12));
    EXPECT_TRUE(students2.contains(s22));
    EXPECT_TRUE(students2.contains(s32));
    EXPECT_TRUE(students2.contains(s42));
}

TEST(OperatorAssigningTest, ClearingOther) {
    linkedhs students1;
    student s11(18, "Masha Ivanova");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Kostya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Kim");
    students2.insert(s22);
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);

    students1 = students2;
    EXPECT_TRUE(students1 == students2);

    students2.clear();
    EXPECT_EQ(students2.size(), 0);
    EXPECT_EQ(students1.size(), 4);
    EXPECT_TRUE(students1 != students2);

    EXPECT_FALSE(students2.contains(s12));
    EXPECT_FALSE(students2.contains(s22));
    EXPECT_FALSE(students2.contains(s32));
    EXPECT_FALSE(students2.contains(s42));

    EXPECT_TRUE(students1.contains(s12));
    EXPECT_TRUE(students1.contains(s22));
    EXPECT_TRUE(students1.contains(s32));
    EXPECT_TRUE(students1.contains(s42));
}

TEST(OperatorAssigningTest, ClearingThis) {
    linkedhs students1;
    student s11(18, "Masha Ivanova");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Kostya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Kim");
    students2.insert(s22);
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);

    students1 = students2;
    EXPECT_TRUE(students1 == students2);

    students1.clear();
    EXPECT_EQ(students2.size(), 4);
    EXPECT_EQ(students1.size(), 0);
    EXPECT_TRUE(students1 != students2);

    EXPECT_FALSE(students1.contains(s12));
    EXPECT_FALSE(students1.contains(s22));
    EXPECT_FALSE(students1.contains(s32));
    EXPECT_FALSE(students1.contains(s42));

    EXPECT_TRUE(students2.contains(s12));
    EXPECT_TRUE(students2.contains(s22));
    EXPECT_TRUE(students2.contains(s32));
    EXPECT_TRUE(students2.contains(s42));
}

//operator==()

TEST(OperatorEqListsTest, EqListsInTheSameOrder) {
    linkedhs students1;
    student s11(18, "Sasha Ivanov");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Katya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Kim");
    students2.insert(s22);
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);
    EXPECT_TRUE(students1 == students2);
}

TEST(OperatorEqListsTest, NotEqListsInTheSameOrder) {
    linkedhs students1;
    student s11(18, "Sasha Ivanov");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Katya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Kim");
    students2.insert(s22);
    student s32(18, "Kostya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);
    EXPECT_FALSE(students1 == students2);
}

TEST(OperatorEqListsTest, EqListsNotInTheSameOrder) {
    linkedhs students1;
    student s11(18, "Sasha Ivanov");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Katya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);
    student s22(15, "Nastya Kim");
    students2.insert(s22);
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    EXPECT_TRUE(students1 == students2);
}

TEST(OperatorEqListsTest, NotEqListsNotInTheSameOrder) {
    linkedhs students1;
    student s11(18, "Sasha Ivanov");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Kostya Kim");
    students1.insert(s31);
    student s41(19, "Masha Kats");
    students1.insert(s41);

    linkedhs students2;
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);
    student s22(15, "Nastya Kim");
    students2.insert(s22);
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    EXPECT_FALSE(students1 == students2);
}

//operator!=()

TEST(OperatorNotEqListsTest, NotEqLists) {
    linkedhs students1;
    student s11(18, "Sasha Ivanov");
    students1.insert(s11);
    student s21(15, "Nastya Kim");
    students1.insert(s21);
    student s31(18, "Katya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Ivanova");
    students2.insert(s22);
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);
    EXPECT_TRUE(students1 != students2);
}

TEST(OperatorNotEqListsTest, EqLists) {
    linkedhs students1;
    student s11(18, "Sasha Ivanov");
    students1.insert(s11);
    student s21(15, "Nastya Ivanova");
    students1.insert(s21);
    student s31(18, "Katya Kim");
    students1.insert(s31);
    student s41(19, "Rimma Kats");
    students1.insert(s41);

    linkedhs students2;
    student s12(18, "Sasha Ivanov");
    students2.insert(s12);
    student s22(15, "Nastya Ivanova");
    students2.insert(s22);
    student s32(18, "Katya Kim");
    students2.insert(s32);
    student s42(19, "Rimma Kats");
    students2.insert(s42);
    EXPECT_FALSE(students1 != students2);
}

//copy constructor

TEST(CopyConstructorLinkedhsTest, Empty) {
    linkedhs students;
    const linkedhs &studentsTmp(students);
    EXPECT_TRUE(studentsTmp.empty());
    EXPECT_TRUE(studentsTmp == students);
}

TEST(CopyConstructorLinkedhsTest, NotEmpty) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(18, "Katya Kim");
    students.insert(s3);
    student s4(19, "Rimma Kats");
    students.insert(s4);
    linkedhs studentsCopy(students);
    EXPECT_TRUE(studentsCopy == students);

    EXPECT_TRUE(studentsCopy.contains(s1));
    EXPECT_TRUE(studentsCopy.contains(s2));
    EXPECT_TRUE(studentsCopy.contains(s3));
    EXPECT_TRUE(studentsCopy.contains(s4));

    EXPECT_TRUE(students.contains(s1));
    EXPECT_TRUE(students.contains(s2));
    EXPECT_TRUE(students.contains(s3));
    EXPECT_TRUE(students.contains(s4));
}

TEST(CopyConstructorLinkedhsTest, Removing) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(18, "Katya Kim");
    students.insert(s3);
    student s4(19, "Rimma Kats");
    students.insert(s4);
    linkedhs studentsCopy(students);

    students.remove(s2);
    EXPECT_EQ(students.size(), 3);
    EXPECT_EQ(studentsCopy.size(), 4);
    EXPECT_FALSE(studentsCopy == students);

    EXPECT_TRUE(studentsCopy.contains(s1));
    EXPECT_TRUE(studentsCopy.contains(s2));

    EXPECT_TRUE(studentsCopy.contains(s3));
    EXPECT_TRUE(studentsCopy.contains(s4));

    EXPECT_TRUE(students.contains(s1));
    EXPECT_FALSE(students.contains(s2));
    EXPECT_TRUE(students.contains(s3));
    EXPECT_TRUE(students.contains(s4));
}

TEST(CopyConstructorLinkedhsTest, RemovingInTheCopy) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(18, "Katya Kim");
    students.insert(s3);
    student s4(19, "Rimma Kats");
    students.insert(s4);
    linkedhs studentsCopy(students);

    studentsCopy.remove(s2);
    EXPECT_EQ(students.size(), 4);
    EXPECT_EQ(studentsCopy.size(), 3);
    EXPECT_FALSE(studentsCopy == students);

    EXPECT_TRUE(studentsCopy.contains(s1));
    EXPECT_FALSE(studentsCopy.contains(s2));
    EXPECT_TRUE(studentsCopy.contains(s3));
    EXPECT_TRUE(studentsCopy.contains(s4));

    EXPECT_TRUE(students.contains(s1));
    EXPECT_TRUE(students.contains(s2));
    EXPECT_TRUE(students.contains(s3));
    EXPECT_TRUE(students.contains(s4));
}

TEST(CopyConstructorLinkedhsTest, ClearingTheCopy) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(18, "Katya Kim");
    students.insert(s3);
    student s4(19, "Rimma Kats");
    students.insert(s4);
    linkedhs studentsCopy(students);

    studentsCopy.clear();
    EXPECT_EQ(students.size(), 4);
    EXPECT_EQ(studentsCopy.size(), 0);
    EXPECT_FALSE(studentsCopy == students);

    EXPECT_FALSE(studentsCopy.contains(s1));
    EXPECT_FALSE(studentsCopy.contains(s2));
    EXPECT_FALSE(studentsCopy.contains(s3));
    EXPECT_FALSE(studentsCopy.contains(s4));

    EXPECT_TRUE(students.contains(s1));
    EXPECT_TRUE(students.contains(s2));
    EXPECT_TRUE(students.contains(s3));
    EXPECT_TRUE(students.contains(s4));
}

TEST(CopyConstructorLinkedhsTest, Clearing) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    student s3(18, "Katya Kim");
    students.insert(s3);
    student s4(19, "Rimma Kats");
    students.insert(s4);
    linkedhs studentsCopy(students);

    students.clear();
    EXPECT_EQ(students.size(), 0);
    EXPECT_EQ(studentsCopy.size(), 4);
    EXPECT_FALSE(studentsCopy == students);

    EXPECT_TRUE(studentsCopy.contains(s1));
    EXPECT_TRUE(studentsCopy.contains(s2));
    EXPECT_TRUE(studentsCopy.contains(s3));
    EXPECT_TRUE(studentsCopy.contains(s4));

    EXPECT_FALSE(students.contains(s1));
    EXPECT_FALSE(students.contains(s2));
    EXPECT_FALSE(students.contains(s3));
    EXPECT_FALSE(students.contains(s4));
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

TEST_F(RemoveTest, OneElement) {
    EXPECT_TRUE(students.contains(student1));
    EXPECT_EQ(students.size(), 4);
    EXPECT_TRUE(students.remove(student1));
    EXPECT_FALSE(students.contains(student1));
    EXPECT_EQ(students.size(), 3);
}

TEST_F(RemoveTest, TwoElements) {
    EXPECT_TRUE(students.contains(student3));
    EXPECT_EQ(students.size(), 4);
    EXPECT_TRUE(students.remove(student3));
    EXPECT_FALSE(students.contains(student3));
    EXPECT_EQ(students.size(), 3);

    EXPECT_TRUE(students.contains(student4));
    EXPECT_EQ(students.size(), 3);
    EXPECT_TRUE(students.remove(student4));
    EXPECT_FALSE(students.contains(student4));
    EXPECT_EQ(students.size(), 2);
}

TEST_F(RemoveTest, UnexistedElement) {
    student student5 = student(17, "Olga Pogibelnaya");
    EXPECT_FALSE(students.contains(student5));
    EXPECT_EQ(students.size(), 4);
    EXPECT_FALSE(students.remove(student5));
    EXPECT_FALSE(students.contains(student5));
    EXPECT_EQ(students.size(), 4);
}

//student.h

//constructor

TEST(ConstructorStudentTest, Declaration) {
    student s1(18, "Alina Vasilyeva");
    EXPECT_EQ(s1.name_, "Alina Vasilyeva");
    EXPECT_EQ(s1.age_, 18);
}

//operator!=()

TEST(OperatorNotEqStudentsTest, EqStudents) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(18, "Sasha Ivanov");
    students.insert(s2);
    EXPECT_FALSE(s1 != s2);
}

TEST(OperatorNotEqStudentsTest, NotEqStudents) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(15, "Nastya Kim");
    students.insert(s2);
    EXPECT_TRUE(s1 != s2);
}

//operator==()

TEST(OperatorEqStudentsTest, EqStudents) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(18, "Sasha Ivanov");
    students.insert(s2);
    EXPECT_TRUE(s1 == s2);
}

TEST(OperatorEqStudentsTest, NotEqStudents) {
    linkedhs students;
    student s1(18, "Sasha Ivanov");
    students.insert(s1);
    student s2(16, "Sasha Ivanov");
    students.insert(s2);
    EXPECT_FALSE(s1 == s2);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
