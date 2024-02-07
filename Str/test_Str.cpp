#include<iostream>
#include "Str.h"
using namespace std;
int main()
{
	Str s1;
	char courseName[] = "ali";
	Str s2(courseName);
	Str s3(s2);
	s2.print(); //ali
	s3.print(); //ali
	s1 = s2; s1.print(); //ali
	++s1; s1.print(); //bmj
	s1[0] = 'P'; s1.print(); //Pmj
	return 0;
}
