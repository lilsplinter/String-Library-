#include <iostream>
#include <vector>
#include "clsString.h"
using namespace std;




int main() {
	clsString Str;
	Str.String = "Ahmed Hussein Ahmed";
	vector<string> vWords = Str.Split();
	return 0;
}