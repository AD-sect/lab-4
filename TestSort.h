#pragma once
#include"Sorts.h"
#include<cassert>

void test_check(Sequence<int>* mas, int* check, int size)
{
	for (int i(0); i < size; i++)	
		assert(check[i] == mas->Get(i));
}

void test_bubble_sort( Sequence<int>* mas,int* checkMas,int checkSize)
{
	bubble_sort(mas);
	test_check(mas, checkMas, checkSize);
}

void test_quick_sort(Sequence<int>* mas, int* checkMas,int checkSize)
{
	quick_sort(mas, 0, checkSize - 1);
	test_check(mas, checkMas, checkSize);
}

void test_shell_sort(Sequence<int>* mas, int* checkMas,int checkSize)
{
	shell_sort(mas, checkSize);
	test_check(mas, checkMas, checkSize);
}

void test_mix(Sequence<int>* mas, int* mixMas)
{
	for (int i(0); i < mas->GetLength(); i++)
		mas->Set(mixMas[i], i);

}

void test_all_mas(Sequence <int>* mas, int* checkMas, int* mixMas)
{
	test_bubble_sort(mas, checkMas, mas->GetLength() );
	test_mix(mas, mixMas);
	test_quick_sort(mas, checkMas, mas->GetLength());
	test_mix(mas, mixMas);
	test_shell_sort(mas, checkMas, mas->GetLength());

}



void test_sort()
{
	int mas10[10]{ 8, 4, 5, 2, 7, 9, 1, 3, 6, 10 };
	ArraySequence<int> test10(mas10, 10);
	Sequence<int>* testMas10 = &test10;
	int* checkMas10 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int mas0[10]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	ArraySequence<int> test0(mas0, 10);
	Sequence<int>* testMas0 = &test0;
	int* checkMas0 = new int[10]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int mas2[2]{ 558, 58 };
	ArraySequence<int> test2(mas2, 2);
	Sequence<int>* testMas2 = &test2;
	int* checkMas2 = new int[2]{ 58, 558 };

	int mas1[1]{ 3 };
	ArraySequence<int> test1(mas1, 1);
	Sequence<int>* testMas1 = &test1;
	int* checkMas1 = new int[1]{ 3 };

	int mas6[6]{ 6, 6, 6, 6, 6, 6 };
	ArraySequence<int> test6(mas6, 6);
	Sequence<int>* testMas6 = &test6;
	int* checkMas6 = new int[6]{ 6, 6, 6, 6, 6, 6 };

	int masNeg[8]{ -15, -897, -1, -99, -797, -65, -2, -8888899 };
	ArraySequence<int> testNeg(masNeg, 8);
	Sequence<int>* testMasNeg = &testNeg;
	int* checkMasNeg = new int[8]{ -8888899, -897, -797, -99, -65, -15, -2, -1 };

	int masMix[5]{ -15, 897, -1, 99, -37 };
	ArraySequence<int> testMix(masMix, 5);
	Sequence<int>* testMasMix = &testMix;
	int* checkMasMix = new int[5]{ -37, -15, -1, 99, 897 };

	test_all_mas(testMas10, checkMas10, mas10);
	//std::cout << "ok10" << std::endl;
	test_all_mas(testMas0, checkMas0, mas0);
	//std::cout << "ok0" << std::endl;
	test_all_mas(testMas2, checkMas2, mas2);
	//std::cout << "ok2" << std::endl;
	test_all_mas(testMas1, checkMas1, mas1);
	//std::cout << "ok1" << std::endl;
	test_all_mas(testMas6, checkMas6, mas6);
	//std::cout << "ok6" << std::endl;
	test_all_mas(testMasNeg, checkMasNeg, masNeg);
	//std::cout << "okneg" << std::endl;
	test_all_mas(testMasMix, checkMasMix, masMix);
	//std::cout << "okmix" << std::endl;

	std::cout << "Test bubble sort is succesful" << std::endl;
	std::cout << "Test quick sort is succesful" << std::endl;
	std::cout << "Test shell sort is succesful" << std::endl;
	std::cout << "***All the test for sorts have worked!***" << std::endl;
}

