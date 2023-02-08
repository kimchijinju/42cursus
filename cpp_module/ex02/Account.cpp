#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static void print_with_semicolon(std::string s, int n)
{
	std::cout << s << ":" << n << ";";
}

static void print_with_endl(std::string s, int n)
{
	std::cout << s << ":" << n << std::endl;
}

int Account::getNbAccounts()
{
	return _nbAccounts;

}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	print_with_semicolon("accounts", _nbAccounts);
	print_with_semicolon("total", _totalAmount);
	print_with_semicolon("deposits", _totalNbDeposits);
	print_with_endl("withdrawals", _totalNbWithdrawals);
}


Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	_accountIndex = _nbAccounts;
	print_with_semicolon("index", _accountIndex);
	print_with_semicolon("amount", _amount);
	std::cout << "created" << std::endl;

	_nbAccounts += 1;
	_totalAmount += _amount;
}

Account::~Account()
{
	_displayTimestamp();
	print_with_semicolon("index", _accountIndex);
	print_with_semicolon("amount", _amount);
	std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{

	_displayTimestamp();
	print_with_semicolon("index", _accountIndex);
	print_with_semicolon("p_amount", _amount);
	print_with_semicolon("deposit", deposit);

	_amount += deposit;
	_nbDeposits += 1;

	print_with_semicolon("amount", _amount);
	print_with_endl("nb_deposits:", _nbDeposits);

	_totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	print_with_semicolon("index", _accountIndex);
	print_with_semicolon("p_amount", _amount);
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return false;
	}
	print_with_semicolon("withdrawal", withdrawal);
	_amount -= withdrawal;
	print_with_semicolon("amount", _amount);
	_nbWithdrawals += 1;
	print_with_endl("nb_withdrawals", _nbWithdrawals);

	_totalNbWithdrawals += 1;
	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	print_with_semicolon("index", _accountIndex);
	print_with_semicolon("amount", _amount);
	print_with_semicolon("deposits", _nbDeposits);
	print_with_endl("withdrawals", _nbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "[%Y%m%d_%H%M%S] ", timeinfo);

	std::cout << buffer;
}
