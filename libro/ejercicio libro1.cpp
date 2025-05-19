#include <stdio.h> 
void func1(void) 
{
	puts("Segunda función"); 
	return; 
}
void func2(void) 
{ 
	puts("Tercera función"); 
	return; 
}
int main() 
{
	puts("Primera función llamada main()");
	func1(); 
	func2(); 
	puts("main se termina");
	return 0;
}
