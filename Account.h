#pragma once
#include<iostream>

using namespace std;

class NegativeDeposit{};

class InsufficientFunds {};

class Account
{
private:
	double balance;
public:
	Account() { balance = 0; }
	Account(double initialDeposit) { balance = initialDeposit; }
	double getBalance() { return balance; }

	//returns new balance or -1 if error 
	double deposit(double amount)
	{
		NegativeDeposit error;
		if (amount > 0) 
			balance += amount;
		else 
			throw error;
		return balance;
	}

	//return new balance or -1 if invalid amount 
	double withdraw(double amount)
	{
		InsufficientFunds error;
		if ((amount > balance) || (amount < 0)) 
			throw error;
		else 
			balance -= amount;
		return balance;
	}
};
