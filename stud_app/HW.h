#pragma once
//#define _USE_MATH_DEFINES
//#include <math.h>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>


//#ifdef _USE_MATH_DEFINES 
//void ssa();
//#endif

/// first == длина окружности
/// second == площадь окружности
//std::pair<double, double> searchS(const double &rad) 
//{
//	double dlin = 2 * M_PI * rad;
//	double s = M_PI * rad * rad;
//	return std::pair<double, double> {dlin, s};
//}
//
//void arr(const int n)
//{
//	const int r = n;
//	std::vector<int> start_vec = { 1 };
//	start_vec.resize(3, n);
//	std::vector<std::vector<int>> arr = { start_vec };
//	arr.resize(3, start_vec);
//	for (int i = 0; i < arr.size(); i++)
//	{
//		for (int j = 0; j < arr[i].size(); j++)
//		{
//			std::cout << arr[i][j] << " ";
//		}
//		std::cout << "\n";
//	}
//	
//}
//
//void test_int_double()
//{
//	int intNum = 5;
//	double dbNum = 6.53234;
//	int aa = dbNum;
//	std::cout << std::format("intNum * dbNum = {} \n \
//		dbNum / 1 = {} \n  \
//		dbNum / 1.0 = {} \n  \
//		int aa = {} \n"
//		, intNum * dbNum, dbNum / 1, dbNum / 1.0, aa);
//}
//
#include <bitset>
//void xor_test()
//{
//	unsigned short int i = 63;
//	std::cout << std::bitset<8> {i} << "\n";
//	i = 1 + 4 + 32;
//	uint8_t x = 255;
//	std::cout << std::bitset<8> {i} << "\n" << (std::bitset<8> {x}) << "\n";
//	uint8_t result = i ^ x;
//	std::cout << std::bitset<8> {result};
//	
//}

void bit_shift()
{
	uint32_t a = 2;
	std::cout << (a << 3) << " " << 32.0 / 7 << std::endl;
}

void bit_op_test(uint8_t a, uint8_t b)
{
	std::cout << unsigned(a) << " " << std::bitset<8> {a} << " \n" << unsigned(b) << " " << std::bitset<8> {b} << " \n";
	std::cout << std::bitset<8> {static_cast<uint8_t>(a & b)} << std::endl;
	std::cout << std::bitset<8> {static_cast<uint8_t>(a | b)} << std::endl;
	std::cout << std::bitset<8> {static_cast<uint8_t>(a ^ b)} << std::endl;
}

void bit_shift_base()
{
	uint32_t number = 1;
	uint32_t result = ((number << 1) + 5) << 1;
	std::cout << result;
	std::string str = "Hello CPP!";
	for (auto i : str)
	{
		if ((i) == 'e') {
			continue;
		};
		std::cout << i << " ";
	}
}void lesson_6()
{
	////int arr[5] = { 1, 5, 7 , 5, 999 };
	//std::vector<std::string> arr = {"ssdf", "sdfsfd", "fe324"};
	//int i = 0;
	//std::string x = arr[i];
	//std::vector<std::string> arr = {i auto i : arr};
	////std::cout << sizeof(arr) << ' ' << sizeof(*arr) << '\n';
	//for (auto i : arr) {
	//	std::cout << i << " ";
	//}
	uint16_t a = 6;
	uint32_t z = 89;
	std::cout << bool(a > z);
	int loop = 0;
	while (loop < 5) {
		std::cout << loop << " ";
		loop++;
	}
}

/*
	С++20
	Начало Лабораторной работы #1
	Задание #29:
	Разработать программу, которая генерирует число в определенном диапазоне.
	Пользователь пытается угадать число, ориентируясь на подсказки компьютера.
	Каждую новую игру диапазон генерации случайного числа меняется случайным образом.
*/ 
#include <random>
#include <cstdlib>
#include <ctime>

uint32_t gen_rand(uint32_t &a, uint32_t &b)
{
	uint32_t x = b + 1;
	while (x > b)
		x = a + std::rand() / ((RAND_MAX + 1u) / b);
	return x;
}

void prog_lab1()
{
	std::srand(std::time(0));
	setlocale(LC_ALL, "Russian");
	uint16_t difficult;
	std::cout << "Укажите сложность(1 - 4): ";
	std::cin >> difficult;
	std::vector<uint32_t> num_set_for_random;
	switch (difficult) {
	case 1:
		num_set_for_random = { 3, 15, 18, 40 };
		break;
	case 2:
		num_set_for_random = { 1, 100, 103, 200 };
		break;
	case 3:
		num_set_for_random = { 1, 1000, 1003, 2000 };
		break;
	case 4:
		num_set_for_random = { 50, 10000, 10003, 30000 };
		break;
	default: // По факту, если мы вводим туда строку, то прога ломается, но пусть будет(на случай если введут другое число)
		num_set_for_random = { 1, 10, 12, 30 };
		std::cout << "Чё сказал? \n Выбрана самая простая сложность";
		break;
	}
	
	std::string user_choice = "y";
	while (user_choice == "y") {
		uint32_t range_a = gen_rand(num_set_for_random[0], num_set_for_random[1]);
		uint32_t range_b = gen_rand(num_set_for_random[2], num_set_for_random[3]);
		uint32_t to_find = gen_rand(range_a, range_b);
		uint32_t user_input;
		bool finded_flag = false;
		while (!finded_flag) {
			std::cout << "Введите число: ";
			std::cin >> user_input;
			//std::cout << '\n';

			if (user_input > to_find) {
				std::cout << "Введённое число больше заданного\n";
			}
			else if (user_input < to_find) {
				std::cout << "Введённое число меньше заданного\n";
			}
			else if (user_input == to_find) {
				finded_flag = true;
			}
			else {
				std::cout << "Чё сказал?";
				user_input = 1;
			}
		}
		std::cout << std::format("Вы угадали, это число {}\nХотите продолжить? (y/n): ", to_find);
		std::cin >> user_choice;
	}
}

