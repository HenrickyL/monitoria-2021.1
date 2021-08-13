#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "LList.h"
using namespace std;



int main(){
	LList l;
	l.append(1);
	l.append(2);
	l.append(3);
	l.append(4);
	l.append(5);
	l.append(6);
	l.print();
	l.reverse();
	l.print();
}


