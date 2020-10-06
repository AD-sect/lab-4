#pragma once
#include"Sequence.h"
#include"ArraySequence.h"
#include<cassert>

void test_arr_seq_GetFirst(Sequence<int>* testSeq, int rez)
{
    assert(rez == testSeq->GetFirst());
}

void test_arr_seq_GetLast(Sequence<int>* testSeq, int rez)
{
    assert(rez == testSeq->GetLast());
}

void test_arr_seq_Get(Sequence<int>* testSeq, int rez, int i)
{
    assert(rez == testSeq->Get(i));
}

void test_arr_seq_Set(Sequence<int>* testSeq, int rez, int i)
{
    testSeq->Set(rez, i);
    assert(rez == testSeq->Get(i));
}

void test_arr_seq_GetSubsequence(Sequence<int>* testSeq, int start, int end)
{
    ArraySequence<int> test;
    Sequence<int>* testS = &test;
    testS = testSeq->GetSubsequence(start, end);

    for (int i(start); i < start - end + 1; i++)
        assert(testSeq->Get(i) == testS->Get(i));
}

void test_arr_seq_GetLength(Sequence<int>* testSeq, int rez)
{
    assert(rez == testSeq->GetLength());
}

void test_arr_seq_Append(Sequence<int>* testSeq, int rez0, int rez1)
{
    testSeq->Append(rez0);
    assert(rez0 == testSeq->Get(0));
    assert(rez1 == testSeq->Get(1));
}

void test_arr_seq_Prepend(Sequence<int>* testSeq, int rez, int rezPrev, int size)
{
    testSeq->Prepend(rez);
    assert(rez == testSeq->Get(size));
    assert(rezPrev == testSeq->Get(size - 1));
}

void test_arr_seq_InsertAt(Sequence<int>* testSeq, int rez, int rezNext, int rezPrev, int i)
{
    testSeq->InsertAt(rez, i);
    assert(rez == testSeq->Get(i));
    assert(rezNext == testSeq->Get(i + 1));
    assert(rezPrev == testSeq->Get(i - 1));
}

void test_arr_seq_Concat(Sequence<int>* testSeq1, int size1, Sequence<int>* testSeq2, int size2)
{
    testSeq1->Concat(testSeq2);
    for (int i(size1 + 1); i < size2; i++)
        assert(testSeq1->Get(i) == testSeq2->Get(i - size1));
}

void test_seq()
{
    ArraySequence<int> test0;
    Sequence<int>* testSeq0 = &test0;

    int mas2[2]{ 6, 89 };
    ArraySequence<int> test2(mas2, 2);
    Sequence<int>* testSeq2 = &test2;

    int mas7[7]{ 65, 966, 1, 0, -46, 7, -5786 };
    ArraySequence<int> test7(mas7, 7);
    Sequence<int>* testSeq7 = &test7;

    int mas1[1]{ 5 };
    ArraySequence<int> test1(mas1, 1);
    Sequence<int>* testSeq1 = &test1;

    //5
    test_arr_seq_GetFirst(testSeq1, 5);
    test_arr_seq_GetFirst(testSeq2, 6);
    test_arr_seq_GetFirst(testSeq7, 65);

    std::cout << "Test getFirst function is succesful" << std::endl;

    test_arr_seq_GetLast(testSeq1, 5);
    test_arr_seq_GetLast(testSeq2, 89);
    test_arr_seq_GetLast(testSeq7, -5786);

    std::cout << "Test getLast function is succesful" << std::endl;

    test_arr_seq_Get(testSeq1, 5, 0);
    test_arr_seq_Get(testSeq2, 6, 0);
    test_arr_seq_Get(testSeq2, 89, 1);
    test_arr_seq_Get(testSeq7, 7, 5);
    test_arr_seq_Get(testSeq7, 0, 3);
    test_arr_seq_Get(testSeq7, 966, 1);

    std::cout << "Test get function is succesful" << std::endl;


    test_arr_seq_Set(testSeq1, 48, 0);
    test_arr_seq_Set(testSeq1, 5, 0);
    test_arr_seq_Set(testSeq2, 4, 1);
    test_arr_seq_Set(testSeq2, 89, 1);
    test_arr_seq_Set(testSeq7, 3, 4);
    test_arr_seq_Set(testSeq7, -46, 4);

    std::cout << "Test Set function is succesful" << std::endl;

    test_arr_seq_GetLength(testSeq1, 1);
    test_arr_seq_GetLength(testSeq2, 2);
    test_arr_seq_GetLength(testSeq7, 7);

   
    std::cout << "Test get length function is succesful" << std::endl;
    test_arr_seq_Append(testSeq1, 8, 5);//8, 5
    test_arr_seq_Append(testSeq2, 11, 6);//11, 6, 89
    test_arr_seq_Append(testSeq7, 31, 65); // 31, 65, 966, 1, 0, -46, 7, -5786
   
    std::cout << "Test append function is succesful" << std::endl;
    test_arr_seq_Prepend(testSeq1, 3, 5, 2);//8, 5, 3
    test_arr_seq_Prepend(testSeq2, 7, 89, 3);//11, 6, 89, 7
    test_arr_seq_Prepend(testSeq7, 17, -5786, 8); // 31, 65, 966, 1, 0, -46, 7, -5786, 17
    
    std::cout << "Test prepend function is succesful" << std::endl;

    test_arr_seq_InsertAt(testSeq1, -8889, 3, 5, 2); //8, 5, -8889, 3
    test_arr_seq_InsertAt(testSeq2, 13, 6, 11, 1);//11, 13, 6, 89, 7
    test_arr_seq_InsertAt(testSeq7, 8, 65, 31, 1);// 31, 8,  65, 966, 1, 0, -46, 7, -5786, 17
    test_arr_seq_InsertAt(testSeq7, 555, -46, 0, 6);// 31, 8,  65, 966, 1, 0, 555, -46, 7, -5786, 17

    std::cout << "Test insertat function is succesful" << std::endl;
    test_arr_seq_Concat(testSeq1, 4, testSeq7, 7);
    test_arr_seq_Concat(testSeq2, 5, testSeq7, 7);
    test_arr_seq_Concat(testSeq7, 11, testSeq1, 4);

    std::cout << "Test concat function is succesful" << std::endl;
    test_arr_seq_GetSubsequence(testSeq2, 1, 2);
    test_arr_seq_GetSubsequence(testSeq7, 0, 5);

    std::cout << "Test get subsequence function is succesful" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "***All the test for sequence have worked!***" << std::endl;
    std::cout << " " << std::endl;

}

