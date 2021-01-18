

#include <iostream>
#include<cstdlib>
using namespace std;

int* ArrAllocator(int s);
int mode(int* arr, int s,int*);

int main() {
	int size, randomN;
	int* numArr;
	
	//get the size of the array from the user
	do {
		cout << "Please enter the size of the array" << endl;
		cout << "size: ";
		cin >> size;
		if (size < 5 || size>50)
			cout << "The size numnber should between 5 to 50 (inclusive)" << endl;
	} while (size<5||size>50);

	// call ArrAllocator function to generate an empty array
	numArr = ArrAllocator(size);
	//seed the random number
	srand(6000);
	//Populate the array with random integer numbers 0 to 9 
	cout <<"Array data: "<<endl;
	for (int i = 0; i < size; i++) {
		randomN = rand() % 10;
		*(numArr + i) = randomN;
		cout << *(numArr + i) <<"  ";
	}

	cout << "\n----------------------------\n";
	//call the mode function to determine the mode number
	int maxFrqc;
	int result = mode(numArr, size,&maxFrqc);
	//output
	if (result == -1)
		cout << "There is no mode number in this array" << endl;
	else
		cout<<"The mode number of the array is "<<result<<", with frequency of "<<maxFrqc <<"\n\n";
	//free the memory
	delete[] numArr;

	system("pause");
	return 0;
}

int* ArrAllocator(int s) {
	int* theArray;
	theArray = new int[s];
	return theArray;
}

int mode(int* arr, int s,int* maxFrqc) {
	int temp=0,counter=0, modeN = 0;
	*maxFrqc = 0;
	//take each one of the number out from the array then looping over the array again to compare
	for (int i = 0; i < s; ++i) {
		temp = *(arr + i);
		for (int j = 0; j < s; ++j) {
			if (*(arr + j) == temp) {
				counter++;
				if (counter >= *maxFrqc) {
					*maxFrqc = counter;
					modeN = temp;
				}
			}
		}
		//after checking a number, set the counter back to 0
		counter = 0;
	}
	
	if (*maxFrqc == 1)
		return -1;

	return modeN;
}