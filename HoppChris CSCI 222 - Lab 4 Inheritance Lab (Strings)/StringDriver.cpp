// StringDriver.cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "StringDriver.h"

using namespace std;

ofstream csis;

int main() {

	csis.open("csis.txt");
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	test13();
	test14();
	test15();
	test16();
	test17();
	test18();
	test19();
	test20();
	csis.close();
}

void test1() {
	cout << "1. Testing S1: String default ctor." << endl << endl;
	csis << "1. Testing S1: String default ctor." << endl << endl;
	String s1;
	s1.print();
	wait();
}

void test2() {
	cout << "2. Testing S2: String one arg (char *) ctor." << endl << endl;
	csis << "2. Testing S2: String one arg (char *) ctor." << endl << endl;
	String s2("ABC");
	s2.print();
	wait();
}

void test3() {
	cout << "3. Testing S3: String one arg (char) ctor." << endl << endl;
	csis << "3. Testing S3: String one arg (char) ctor." << endl << endl;
	String s3('Z');
	s3.print();
	wait();
}

void test4() {
	cout << "4. Testing S4: String one arg (int) ctor." << endl << endl;
	csis << "4. Testing S4: String one arg (int) ctor." << endl << endl;
	String s4(10);
	s4.print();
	wait();
}

void test5() {
	cout << "5. Testing S5, T5: String copy ctor." << endl << endl;
	csis << "5. Testing S5, T5: String copy ctor." << endl << endl;
	String s5("Purple Rain");
	s5.print();
	String t5(s5);
	t5.print();
	wait();
}

void test6() {
	cout << "6. Testing S6: String two arg (char, int) ctor." << endl << endl;
	csis << "6. Testing S6: String two arg (char, int) ctor." << endl << endl;
	String s6('*', 10);
	s6.print();
	wait();
}

void test7() {
	cout << "7. Testing S7, T7, U7: String assignment." << endl << endl;
	csis << "7. Testing S7, T7, U7: String assignment." << endl << endl;
	String s7("Sally Ride"), t7, u7;
	t7 = u7 = s7;
	s7.print();
	t7.print();
	u7.print();
	wait();
}

void test8() {
	cout << "8. Testing S8: String assignment." << endl << endl;
	csis << "8. Testing S8: String assignment." << endl << endl;
	String s8("ABC");
	s8 = s8;
	s8.print();
	wait();
}

void test9() {
	cout << "9. Testing S9: Implicit type conversion." << endl << endl;
	csis << "9. Testing S9: Implicit type conversion." << endl << endl;
	String s9;
	s9 = "ABC";
	s9.print();
	wait();
}

void test10() {
	cout << "10. Testing S10, T10, U10: String concatenation." << endl << endl;
	csis << "10. Testing S10, T10, U10: String concatenation." << endl << endl;
	String s10("DEF");
	String t10('H');
	String u10("ABC" + s10 + "G" + t10 + 'I');
	u10.print();
	String v10('X' + u10);
	v10.print();
	wait();
}

void test11() {
	cout << "11. Testing S11, T11: String concatenation." << endl << endl;
	csis << "11. Testing S11, T11: String concatenation." << endl << endl;
	String s11('A');
	String t11("BC");
	s11 += s11 += t11 += 'D';
	s11.print();
	t11.print();
	wait();
}

void test12() {
	cout << "12. Testing S12, T12: String unary operator." << endl << endl;
	csis << "12. Testing S12, T12: String unary operator." << endl << endl;
	String s12("Unary +");
	String t12(+s12);
	s12.print();
	t12.print();
	s12 = +s12;
	s12.print();
	wait();
}

void test13() {
	cout << "13. Testing S13, T13: String comparison operators." << endl << endl;
	csis << "13. Testing S13, T13: String comparison operators." << endl << endl;
	String s13("ABC"), t13("ABCD");
	s13.print();
	t13.print();
	cout << endl;
	cout << "== " << (s13 == t13 ? "True" : "False") << endl;
	cout << "!= " << (s13 != t13 ? "True" : "False") << endl;
	cout << "<  " << (s13 <  t13 ? "True" : "False") << endl;
	cout << "<= " << (s13 <= t13 ? "True" : "False") << endl;
	cout << ">  " << (s13 >  t13 ? "True" : "False") << endl;
	cout << ">= " << (s13 >= t13 ? "True" : "False") << endl;
	csis << endl;
	csis << "== " << (s13 == t13 ? "True" : "False") << endl;
	csis << "!= " << (s13 != t13 ? "True" : "False") << endl;
	csis << "<  " << (s13 <  t13 ? "True" : "False") << endl;
	csis << "<= " << (s13 <= t13 ? "True" : "False") << endl;
	csis << ">  " << (s13 >  t13 ? "True" : "False") << endl;
	csis << ">= " << (s13 >= t13 ? "True" : "False") << endl;
	wait();
}

void test14() {
	cout << "14. Testing S14: Overloaded subscript operator." << endl << endl;
	csis << "14. Testing S14: Overloaded subscript operator." << endl << endl;
	String s14("C++ is fun.");
	for (int i = -1; i <= s14.getLength(); i++) {
		char& ch = s14[i];
		if (ch != '\0')
			++ch;
	}
	s14.print();
	wait();
}

void test15() {
	cout << "15. Testing S15: Pointer notation." << endl << endl;
	csis << "15. Testing S15: Pointer notation." << endl << endl;
	String s15("ABCDE");
	for (int i = 0; i < s15.getLength(); i++)
		++(*(s15 + i));
	for (int j = 0; j < s15.getLength(); j++) {
		cout << *(j + s15);
		csis << *(j + s15);
	}
	cout << endl;
	csis << endl;
	wait();
}

void test16() {
	cout << "16. Testing S16, T16, U16, V16, W16, X16, Y16, Z16: Increment and decrement operators." << endl << endl;
	csis << "16. Testing S16, T16, U16, V16, W16, X16, Y16, Z16: Increment and decrement operators." << endl << endl;
	String s16("ABC");
	String t16(++s16);
	s16.print();
	t16.print();

	String u16("ABC");
	String v16(u16++);
	u16.print();
	v16.print();

	String w16("ABC");
	String x16(--w16);
	w16.print();
	x16.print();

	String y16("ABC");
	String z16(y16--);
	y16.print();
	z16.print();
	wait();
}

void test17() {
	cout << "17. Testing S17, T17: Substr function." << endl << endl;
	csis << "17. Testing S17, T17: Substr function." << endl << endl;
	String s17("All You Need Is Love"), t17;
	t17 = s17.substr(4, 8);
	s17.print();
	t17.print();
	wait();
}

void test18() {
	cout << "18. Testing S18, T18: Output function." << endl << endl;
	csis << "18. Testing S18, T18: Output function." << endl << endl;
	String s18("Red-");
	String t18("Green-");
	String u18("Blue");
	cout << s18 << t18 << u18;
	csis << s18 << t18 << u18;
	cout << endl;
	csis << endl;
	wait();
}

void test19() {
	cout << "19. Testing S19, T19, U19: ReverseString class." << endl << endl;
	csis << "19. Testing S19, T19, U19: ReverseString class." << endl << endl;
	ReverseString s19("Computer");
	ReverseString t19;
	t19 = ~s19;
	s19.print();
	t19.print();

	ReverseString u19(~~s19);
	u19.print();
	wait();
}

void test20() {
	cout << "20. Testing S20, T20, U20: CaseString class." << endl << endl;
	csis << "20. Testing S20, T20, U20: CaseString class." << endl << endl;
	CaseString s20("BaLLooN");
	CaseString t20;
	t20 = s20;
	s20.print();
	t20.print();

	CaseString u20(s20);
	u20.print();
	wait();
}



void wait() {
	char buf;

	cout << endl << "Press any key to continue." << endl;
	csis << endl << endl;
	cin.get(buf);
}
