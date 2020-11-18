#include <iostream>
#include <ctime>
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2/Sort.h"
#include "../Lab2/Sort.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(SearchBinary1)
		{
			int arr[10] = { 1, 24 ,34 ,41 ,58 ,62 ,64 ,67 ,69 ,78 };
			Assert::IsTrue(SearchBinary(arr, 10, 62) == 5);
			Assert::IsTrue(SearchBinary(arr, 10, 8) == -1);
			Assert::IsTrue(SearchBinary(arr, 10, 78) == 9);
		}
		TEST_METHOD(QuickSort1)
		{
			int arr[10];
			srand(time(0));
			for (int j = 0; j < 10; j++)
			{
				for (int i = 0; i < 10; i++)
					arr[i] = rand();
				QuickSort(arr, 10);
				Assert::IsTrue(isSorted(arr, 10));
			}
		}
		TEST_METHOD(InsertionSort1)
		{
			int arr[10];
			srand(time(0));
			for (int j = 0; j < 10; j++)
			{
				for (int i = 0; i < 10; i++)
					arr[i] = rand();
				InsertionSort(arr, 10);
				Assert::IsTrue(isSorted(arr, 10));
			}
		}
		TEST_METHOD(BogoSort1)
		{
			int arr[10];
			srand(time(0));
			for (int j = 0; j < 10; j++)
			{
				for (int i = 0; i < 10; i++)
					arr[i] = rand();
				BogoSort(arr, 10);
				Assert::IsTrue(isSorted(arr, 10));
			}
		}
		TEST_METHOD(CountingSort1)
		{
			bool flag = true;
			char input[9] = { "hgfeabcd" };
			char ans[9] = { "abcdefgh" };
			CountingSort(input, 8);
			for (int i = 0; i < 8; i++)
				if (input[i] != ans[i])
					flag = false;
			Assert::IsTrue(flag);
		}
	};
}
