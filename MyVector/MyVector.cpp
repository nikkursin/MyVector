#include <iostream>
#include "Vector.h"
 
using namespace MyVector;

int main()
{
	Vector<int> vec1{1,2};
	Vector<int> vec2 { 7, 8, 9, 4, 5 };


	std::cout << "vec1 = ";
	for (size_t i = 0; i < vec1.size(); i++) {
		std::cout << vec1.at(i) << " ";
	} std::cout << std::endl;

	std::cout << "vec2 = ";
	for (size_t i = 0; i < vec2.size(); i++) {
		std::cout << vec2.at(i) << " ";
	} std::cout << std::endl;

	//vec1.swap(vec2);
	vec1.clear();

	std::cout << "vec1 = ";
	for (size_t i = 0; i < vec1.size(); i++) {
		std::cout << vec1.at(i) << " ";
	} std::cout << std::endl;

	std::cout << "vec2 = ";
	for (size_t i = 0; i < vec2.size(); i++) {
		std::cout << vec2.at(i) << " ";
	} std::cout << std::endl;


	std::cout << "vec1 size = " << vec1.size() << std::endl;;
	std::cout << "vec2 size = " << vec2.size();


}
