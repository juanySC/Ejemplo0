#include <stdio.h> 
void func1(void) 
{
	puts("Segunda funci�n"); 
	return; 
}
void func2(void) 
{ 
	puts("Tercera funci�n"); 
	return; 
}
int main() 
{
	puts("Primera funci�n llamada main()");
	func1(); 
	func2(); 
	puts("main se termina");
	return 0;
}
