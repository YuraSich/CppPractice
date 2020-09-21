#include <iostream>
#include "header.h"
#include <windows.h>

using namespace std;

int main() {
	String s1, s2, s3;

	s1 = "Hello word";
	s2 = "Good Bye word";

	s3 = s1 + s2;

	cout << s3.len();

	return EXIT_SUCCESS;
}


