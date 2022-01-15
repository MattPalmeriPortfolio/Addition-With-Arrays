#include <iostream>
typedef int* intPtr;
//declare functions
bool promptContinue();
//prompts user to continue, returns TRUE if they choose yes and FALSE otherwise
void fillZero(intPtr& intarr, const unsigned int size);
//fills an array with zeroes.
void getInt(intPtr& intarr, const unsigned int size, std::istream& inStream = std::cin);
//fills an array with single digit integers, starting from index (size - 1) to index 0. clears remaining line of input afterwards.
void outputInt(intPtr intarr, const unsigned int size, std::ostream& outStream = std::cout);
//outputs an array acting as a large integer, skipping leading zeroes.

//main
int main()
{
	using namespace std;
	//initialize variables
	intPtr firstNum, secondNum, sum;
	unsigned int firstSize, secondSize, sumSize;
	//begin program
	cout << "This program will sum together two large integers.\nNote that if you input less digits than you specify as the max size, it will be assumed that the digits after are zero.\n";
	do
	{
		char next;
		//get inputs
		cout << "Enter the maximum # of digits for the first integer\n";
		cin >> firstSize; cin.get(next); //clear \n after
		firstNum = new int[firstSize];
		fillZero(firstNum, firstSize);
		cout << "Enter the first integer and press ENTER to finish\n";
		getInt(firstNum, firstSize);
		cout << "Enter the maximum # of digits for the second integer\n";
		cin >> secondSize; cin.get(next); //clear \n after
		secondNum = new int[secondSize];
		fillZero(secondNum, secondSize);
		cout << "Enter the second integer and press ENTER to finish\n";
		getInt(secondNum, secondSize);
		//prepare sum array
		if (firstSize >= secondSize)
			sumSize = firstSize + 1;
		else
			sumSize = secondSize + 1;
		sum = new int[sumSize];
		fillZero(sum, sumSize);
		//sum
		for (int i = firstSize - 1, j = sumSize - 1; i >= 0; i--, j--)
			sum[j] += firstNum[i];

		for (int i = secondSize - 1, j = sumSize - 1; i >= 0; i--, j--)
		{
			sum[j] += secondNum[i];
			if (sum[j] > 10)
			{
				sum[j] -= 10;
				sum[j - 1] += 1;
			}
		}
		//output
		cout << "The sum of\n";
		outputInt(firstNum, firstSize);
		cout << "and\n";
		outputInt(secondNum, secondSize);
		cout << "is\n";
		outputInt(sum, sumSize);
		//free memory
		delete[] firstNum;
		delete[] secondNum;
		delete[] sum;
	} while (promptContinue());
	cout << "Goodbye!\n";
	return 0;
}
//define functions
//uses <iostream>
bool promptContinue()
{
	char next;
	std::cout << "Would you like to continue? y/n: ";
	std::cin >> next;
	if (next == 'y' || next == 'Y')
		return true;
	else
		return false;
}

void fillZero(intPtr& intarr, const unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		intarr[i] = 0;
	return;
}
//uses <iostream>
void getInt(intPtr& intarr, const unsigned int size, std::istream& inStream)
{
	char next = 'a';
	unsigned int index = 0;
	inStream.get(next);
	while (next != '\n' && index < size)
	{
		if (isdigit(next))
		{
			intarr[index] = static_cast<int>(next) - 48;
			index++;
		}
		inStream.get(next);
	}
	if (next != '\n')
	{
		do
		{
			inStream.get(next);
		} while (next != '\n');
	}
	return;
}
//uses <iostream>
void outputInt(intPtr intarr, const unsigned int size, std::ostream& outStream)
{
	unsigned int firstNum = 0;
	for (firstNum = 0; firstNum < size; firstNum++)
		if (intarr[firstNum] > 0)
			break;
	for (firstNum; firstNum < size; firstNum++)
		outStream << intarr[firstNum];
	outStream << std::endl;
	return;
}