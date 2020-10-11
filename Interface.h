#pragma once
#include<iostream>
#include"ArraySequence.h"
#include"Sequence.h"
#include "Sorts.h"
#include "TestSort.h"
#include "TestSequence.h"
#include"Time.h"

void interface()
{
	int choice{ 0 };
	std::cout << "*** INT SORTER ***" << std::endl;
	bool exit{ false };
	Sequence<int> * seq{ nullptr };

	while (!exit)
	{
		ArraySequence<int> arseq = new ArraySequence<int>{ 1 };
		Sequence<int>* seqA{ &arseq };
		LinkedListSequence<int> liseq = new LinkedListSequence<int>{ 1 };
		Sequence<int>* seqL{ &liseq };

		Sequence<int>* seq{ nullptr };

		std::cout << " " << std::endl;
		std::cout << "Choose the option:" << std::endl <<
			"1. Array" << std::endl <<
			"2. List" << std::endl;

		std::cin >> choice;
		if (choice == 1)
			seq = seqA;
		if (choice == 2)
			seq = seqL;
		
		std::cout << "  " << std::endl;
		std::cout << "Choose the action:" << std::endl;
		std::cout <<
			"1. Sort your sequence" << std::endl <<
			"2. See the time results" << std::endl <<
			"3. Sort random sequence  " << std::endl <<
			"4. See the test results  " << std::endl <<
			"5. See the time results of your sequence" << std::endl <<
			"6. Exit" << std::endl;

		std::cin >> choice;

		int size{ 0 };
		int item{ 0 };
		int choice1{ 0 };
	
		
			switch (choice)
			{
			case 1:

				std::cout << "Write the quantaty of elements [0 - 320000]:" << std::endl;
				std::cin >> size;
				if (size == 0)
				{
					std::cout << "It is not nesessary to sort empty sequence" << std::endl;
					break;
				}

				if (0 > size || size > 32000)
					throw IndexOutOfRange();
				else
				{
					std::cout << "Write the elements:" << std::endl;
				
						std::cin >> item;
						seq->Set(item, 0);
	
					for (int i(1); i < size; i++)
					{
						std::cin >> item;
						seq->Prepend(item);
					}

					std::cout << "Which sort do you want to use:" << std::endl;
					std::cout <<
						"1. Bubble sort" << std::endl <<
						"2. Quike sort" << std::endl <<
						"3. Shell sort" << std::endl;

					std::cin >> choice1;

					if (choice1 == 1)
					{
						bubble_sort(seq);
						seq->Print();
					}
					if (choice1 == 2)
					{
						quick_sort(seq, 0, size - 1);
						seq->Print();
					}
					if (choice1 == 3)
					{
						shell_sort(seq, size);
						seq->Print();
					}

				}
				break;

			case 2:
			
				seq->Set(rand(), 0);
				for (int i(1); i < 1500; ++i)
					seq->Prepend(rand());
			
				std::cout << "Results for 1500 elements:" << std::endl;
				{
					LOG_DURATION("time of bubble sort");
					bubble_sort(seq);
				}
				{
					LOG_DURATION("time of shell sort");
					shell_sort(seq, 1500);
				}
				{
					LOG_DURATION("time of quick sort");
					quick_sort(seq, 0, 1499);
				}
				break;

			case 3:
				std::cout << "Write the quantaty of elements [0 - 320000]:" << std::endl;
				std::cin >> size;
				if (size == 0)
				{
					std::cout << "It is not necessary to sort empty sequence" << std::endl;
					break;
				}
				if (0 > size || size > 32000)
					throw IndexOutOfRange();
				else
				{
					seq->Set(rand(), 0);
					for (int i(0); i < size; ++i)
						seq->Prepend(rand());

					seq->Print();
					std::cout << "  " << std::endl;
					std::cout << "Which sort do you want to use:" << std::endl;
					std::cout <<
						"1. Bubble sort" << std::endl <<
						"2. Quike sort" << std::endl <<
						"3. Shell sort" << std::endl;

					std::cin >> choice1;

					if (choice1 == 1)
					{
						bubble_sort(seq);
						seq->Print();
					}
					if (choice1 == 2)
					{
						quick_sort(seq, 0, size - 1);
						seq->Print();
					}
					if (choice1 == 3)
					{
						shell_sort(seq, size);
						seq->Print();
					}
					if (choice1 != 1 && choice1 != 2 && choice1 != 3)
						std::cout << "You choose wrong number" << std::endl;
				}
				break;

			case 4:
				std::cout << "Which test result do tou want to see:" << std::endl
					<< "1.Sequence test" << std::endl
					<< "2.Sort test" << std::endl;
				std::cin >> choice1;
				if (choice1 == 1)
					test_seq();

				if (choice1 == 2)
					test_sort();

				choice1 = 0;
				break;


			case 5:

				std::cout << "Write the quantaty of elements [0 - 320000]:" << std::endl;
				std::cin >> size;

				if (size == 0)
				{
					std::cout << "It is not necessary to sort empty sequence" << std::endl;
					break;
				}

				if (0 > size || size > 32000)
					throw IndexOutOfRange();
				else
				{
					std::cout << "Write the elements:" << std::endl;
					std::cin >> item;
					seq->Set(item, 0);

					for (int i(1); i < size; i++)
					{
						std::cin >> item;
						seq->Prepend(item);
					}

					std::cout << "Results for your elements:" << std::endl;
					{
						LOG_DURATION("time of bubble sort");
						bubble_sort(seq);
					}
					{
						LOG_DURATION("time of shell sort");
						shell_sort(seq, size);
					}
					{
						LOG_DURATION("time of quick sort");
						quick_sort(seq, 0, size - 1);
					}
				}
				break;

			case 6:
				std::cout << "Goodbye!" << std::endl;
				exit = true;
				break;

			default:
				std::cout << "WRONG CHOISE";
			}
			std::cout << std::endl;
	}

	

}





