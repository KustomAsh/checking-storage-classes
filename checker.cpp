#include<iostream>
using namespace std;
void fun3();
void fun();
void fun2();
int global_variable;
extern int extern_variable;
int main()
{
	cout << "Calling basic function from Main : " << endl;
	fun3();
	cout << "Calling fucntion again from Main"<<endl;
	fun3();
	cout << "\nThe lifetime of the variables of type auto and register was limited to function call. "<<endl
		<< "So their values are again zero on the second fucntion call. The values of type global " << endl
		<< "and static were affected becuase their scope is not limited to only function call. The" << endl
		<< "variable extern was initialized in another file but it was used here because of its file" << endl
		<< "to file scope";
	system("pause>0");
}
void fun3()
{
	int auto_variable = 0;
	register int reg_variable = 0;
	extern_variable = 1;
	global_variable = 2;
	cout << "Calling another Function multiple times to check static variable." << endl;
	fun(); fun(); fun();
	cout << "Printing auto variable in Fun1 : " << auto_variable << endl;
	cout << "Printing reg variable in Fun1 : " << reg_variable << endl;
	cout << "Printing extern variable in Fun1 : " << extern_variable << endl;
	cout << "Printing global variable in Fun1 : " << global_variable << endl;
	cout << "Calling second function to check Auto/REG/EXTERN/static variables." << endl;
	fun2();
	cout << "Returned from variables\' check. Changing values of variables and returning control to main." << endl;
	auto_variable = 5;
	reg_variable = 6;
	extern_variable = 7;
	global_variable = 8;
}
void fun()
{
	static int static_variable = 0;
	static_variable++;
	cout << "Function is called " << static_variable << " times. Static variable is not destroyed after function call." << endl;
}
void fun2()
{
	cout << "Printing auto variable in function causes error because the scope of variable is limited. " << endl;
	cout << "Printing reg variable in function causes error because the scope of variable is limited. " << endl;
	cout << "Printing extern variable in function : " << extern_variable << endl;
	cout << "Printing global variable in function : " << global_variable << endl;
}
