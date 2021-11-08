#pragma once

#include "Array.h"
#include <string>
#include <iostream>
#include <sstream>
#include <regex>

using namespace std;

class Money : public Array<char>
{
private:
	static const char m_base = 10;
	bool m_is_negative = false;
	int m_point_pos = 2;
	// TODO �������� ��������� ������� �����
public:
	// ������ ��� ���������� ������������� ����������� ��������. ���������� ��� ��������� �.�. ����� �������� �� ���������
	// �������� �����
	static Money uIntAdd(const Money& left, const Money& right);
	static Money uIntSub(const Money& left, const Money& right);
	static Money uIntMulByDigit(const Money& left, const char right_digit);
	static Money uIntMul(const Money& left, const Money& right);
	static Money uIntDiv(const Money& left, const Money& right);

public:
	// ������������, ������������, ���������� ��������� ������������.
	Money();
	Money(const Money& a);
	Money(const string str);
	~Money();
	Money& operator=(const Money& a);

	// ������ ��������� ��������� ����� � ��������������.
	string toString() const;
	void fromString(string str);
	void removeLeadingZeros();

	bool isNegative() const;

	friend ostream& operator<<(ostream& out, const Money& a);
	friend istream& operator>>(istream& in, Money& a);

	
	// ������ � ��������� ���������
	static int compareByAbs(const Money& left, const Money& right);
	static int compare(const Money& left, const Money& right);

	friend bool operator==(const Money& left, const Money& right);
	friend bool operator!=(const Money& left, const Money& right);
	friend bool operator>=(const Money& left, const Money& right);
	friend bool operator<=(const Money& left, const Money& right);
	friend bool operator >(const Money& left, const Money& right);
	friend bool operator <(const Money& left, const Money& right);
	
	// �������� �������������� ���������

	Money& rightShift(int x);
	Money& leftShift(int x);

	friend Money operator+(const Money& left, const Money& right);
	friend Money operator-(const Money& left, const Money& right);

	Money operator+() const;
	Money operator-() const;

	friend Money operator*(const Money& a, const Money& b);
	friend Money operator/(Money a, Money b);	

};
