#ifndef _MYTERM_H_
#define _MYTERM_H_

#include <iostream>
using namespace std;

class myPolynominal;

class myTerm
{
	public myTerm(int c = 0, unsigned e = 0);

	//copy constructor
	myTerm(const myTerm&term);

	//overloaded operators
	bool operator == (const myTerm&term) const;
	bool operator !=(const myTerm&term)const;
	bool operator <(const myTerm&term) const;
	myTerm operator - () const;


};
#endif // !_MYTERM_H_

