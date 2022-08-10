#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <typeinfo>

//#ifdef _USE_MATH_DEFINES 
//void ssa();
//#endif

/// first == длина окружности
/// second == площадь окружности
std::pair<double, double> searchS(const double &rad) 
{
	double dlin = 2 * M_PI * rad;
	double s = M_PI * rad * rad;
	return std::pair<double, double> {dlin, s};
}

void arr(const int n)
{
	const int r = n;
	std::vector<int> start_vec = { 1 };
	start_vec.resize(3, n);
	std::vector<std::vector<int>> arr = { start_vec };
	arr.resize(3, start_vec);
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
	
}

void test_int_double()
{
	int intNum = 5;
	double dbNum = 6.53234;
	int aa = dbNum;
	std::cout << std::format("intNum * dbNum = {} \n \
		dbNum / 1 = {} \n  \
		dbNum / 1.0 = {} \n  \
		int aa = {} \n"
		, intNum * dbNum, dbNum / 1, dbNum / 1.0, aa);
}

#include <bitset>
void xor_test()
{
	unsigned short int i = 63;
	std::cout << std::bitset<8> {i} << "\n";
	i = 1 + 4 + 32;
	uint8_t x = 255;
	std::cout << std::bitset<8> {i} << "\n" << (std::bitset<8> {x}) << "\n";
	uint8_t result = i ^ x;
	std::cout << std::bitset<8> {result};
	
}