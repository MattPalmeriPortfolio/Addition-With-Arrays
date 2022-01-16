# Addition-With-Arrays

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Array_Addition.cpp (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 9. Project 1.
A program that does addition using the typical pencil-and-paper algorithm on large numbers stored as arrays. Demonstrates ability to work with algorithms on large numbers stared as arrays in c++.
Written using Microsoft Visual Studio. 

## Algorithm

	1. Get first number
		1a. get input of max size of first number; for convenience, don't require every digit be filled.
			1aa. Since every digit doesn't need to be filled, fill the array with zeroes first.
		1b. get input of first number, with \n acting as sentinel value.
			1ba. only take in up to (max size) characters, and clear the rest with newLine function.
	2. Get second number - same steps as first number
	3. Set sum array to the size of the largest number + 1
	4. Sum numbers
		4a. add the numbers in the corresponding positions together; if their sum > 10, subtract 10 and add 1 to the next index
			4aa. since the size of the sum array is + 1 that of the largest array, this will never result in an error
	5. Output
		5a. skip indexes until you find the first index without a zero
	6. delete arrays and prompt to continue

## Requirements
No requirements or modules needed for running this program.
