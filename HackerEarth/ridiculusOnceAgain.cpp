// Rotate the given array to left by given number of times

#include <bits/stdc++.h>
using namespace std;

// Utility method to reverse the array
void reverseArray(int arr[], int start, int end){

	while(start < end){
		arr[start] ^= arr[end] ^= arr[start] ^= arr[end];
		start++;
		end--;
	}

}

/*****************************
* Time Complexity -> O(size) *
*****************************/
void method1(int arr[], int size, int rotations){
	
	rotations %= size;
	int temp[rotations];
	
	for(int i=0; i<rotations; i++)
		temp[i] = arr[i];
	
	for(int i=rotations; i<size; i++)
		arr[i-rotations] = arr[i];
	
	for(int i=0; i<rotations; i++)
		arr[i+size-rotations] = temp[i];

}

/***************************************
* Time Complexity -> O(size*rotations) *
***************************************/
void method2(int arr[], int size, int rotations){

	rotations %= size;

	while(rotations--){
		int temp = arr[0];
		for(int i=1; i<size; i++)
			arr[i-1] = arr[i];
		arr[size-1] = temp;
	}

}

/*****************************
* Reversal Algorithm		 *
* Time Complexity -> O(size) *
*****************************/
void method3(int arr[], int size, int rotations){

	rotations %= size;
	reverseArray(arr, 0, rotations-1);
	reverseArray(arr, rotations, size-1);
	reverseArray(arr, 0, size-1);

}

// Utility method to print the array
void printArray(int arr[], int size){
	cout <<endl;
	for(int i=0; i<size; i++)
		cout <<arr[i] <<" ";
	cout <<endl;
}

// Driver program
int main(){
	int size, rotations;
	cin >>size >>rotations;
	int arr[size];
	for(int i=0; i<size; i++)
		cin >>arr[i];
	method3(arr, size, rotations);
	for(int i=0; i<size; i++)
	    cout <<arr[i] <<" ";
	return 0;
}