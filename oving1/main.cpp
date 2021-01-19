#include <iostream>
#include "std_lib_facilities.h"

int maxOfTwo(int a, int b){
	if (a>b) {
		cout << "A is greater than B \n";
		return a;
	}
	else{
		cout << "B is greater than A \n";
		return b;
	}
}

int fibonacci(int n) {
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers: \n";
	for (int i = 0; i < n+1; i++){
		cout << i << "," << b <<  '\n';
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "---- \n";
	return b;
}


int squareNumberSum(int n){
	int totalSum = 0;
	for(int i = 1; i < n+1; i++){
		int temp = i*i;
		totalSum += temp;
		cout << temp <<'\n';
	}
	cout << totalSum <<'\n';
	return totalSum;
}
int triangleNumbersBelow(int n){
	int acc = 1;
	int num = 2;
	cout <<"Triangle numbers below " <<n<< ":\n";
	while(acc < n){
		cout << acc << '\n';
		acc += num;
		num += 1;
	}
	cout <<' ';
	return 1;
}

bool isPrime(int n){
	for (int i = 2; i < n; i++){
		if(n % i == 0){
			return false;
		}

	}
	return true;
}

int naivePrimeNumberSearch(int n){
	for(int number = 2; number < n+1; number++){
		if(isPrime(number)){
			cout << number << " is a prime";
		}
	}
	return 1;
}

int findGreatestDivisor(int n){
	for (int divisor = n-1; divisor > 0; divisor--){
		if (n%divisor == 0){
			return divisor;
		}
	}
}

int main() {
	int n = 11;
	int a = 1;
	int b = 2;
	cout << "Oppgave a) \n";
	cout << maxOfTwo(a,b) << '\n';
	cout << "Oppgave c) \n";
	cout << fibonacci(n) << '\n';
	cout << "Oppgave d) \n";
	cout << squareNumberSum(n) << '\n';
	cout << "Oppgave e) \n";
	cout << triangleNumbersBelow(n) << '\n';
	cout << "Oppgave f) \n";
	cout << isPrime(n) << '\n';
	cout << "Oppgave g) \n";
	cout << naivePrimeNumberSearch(n) << '\n';
	cout << "Oppgave h) \n";
	cout << findGreatestDivisor(n) << "\n";	
	keep_window_open();
}