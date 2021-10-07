#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <time.h>


void print_array(std::vector<int> &array)
{
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}


void fill_array(std::vector<int> &array)
{
	for (int i = 0; i < array.size(); i++)
	{
		array[i] = i;
	}

	std::random_shuffle(array.begin(), array.end());

	std::stack<int> odd_stack;
	std::stack<int> even_stack;
	for (int i = 0; i < array.size(); i++)
	{
		int number = array[i];
		if (number % 2 == 0)
		{
			even_stack.push(number);
		}
		else
		{
			odd_stack.push(number);
		}
	}

	for (int i = 0; i < array.size(); i++)
	{
		if (i % 2 == 0)
		{
			array[i] = even_stack.top();
			even_stack.pop();
		}
		else
		{
			array[i] = odd_stack.top();
			odd_stack.pop();
		}
	}
}


bool sequential_search(std::vector<int> array1, int number)
{
	for (int item : array1)
	{
		if (item == number)
		{
			return true;
		}
	}
	return false;
}


std::vector<int> union_array(std::vector<int> array1, std::vector<int> array2)
{
	int new_size = array1.size() + array2.size();
	std::vector<int> temp(new_size);
	
	for (int i = 0; i < array1.size(); i++)
	{
		temp[i] = array1[i];
	}

	int offset = array1.size();

	for (int i = 0; i < array2.size(); i++)
	{
		temp[offset + i] = array2[i];
	}
	
	return temp;
}


std::vector<int> intersection_array(std::vector<int> array1, std::vector<int> array2)
{
	std::vector<int> temp;

	for (int number : array1)
	{
		if (sequential_search(array2, number) == true)
		{
			temp.push_back(number);
		}
	}

	return temp;
}


std::vector<int> subtract_array(std::vector<int> array1, std::vector<int> array2)
{
	std::vector<int> temp = array1;

	for (int i = 0; i < array2.size(); i++)
	{
        int number = array2[i];
        temp.erase(std::find(temp.begin(), temp.end(), number));
	}

	return temp;
}


int main()
{
	int m;

	std::cout << "m: ";
	std::cin >> m;

	std::srand(time(0));

	std::vector<int> array1(m);
	fill_array(array1);
	print_array(array1);

	std::vector<int> array2(m);
	fill_array(array2);
	print_array(array2);

	std::cout << "\nUnion:\n";
	std::vector<int> array3 = union_array(array1, array2);
	print_array(array3);

	std::cout << "\nIntersection:\n";
	std::vector<int> array4 = intersection_array(array1, array2);
	print_array(array4);

	std::cout << "\nUnion subtract intersection:\n";
	std::vector<int> array5 = subtract_array(array3, array4);
	print_array(array5);

	return 0;
}
