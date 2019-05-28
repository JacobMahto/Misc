#include<stdio.h>

int main(){
  void arrayNameAsPointers();
  arrayNameAsPointers();
}

void simpleDemo(){
  int x = 10;

    // 1) Since there is * in declaration, ptr
    // becomes a pointer varaible (a variable
    // that stores address of another variable)
    // 2) Since there is int before *, ptr is
    // pointer to an integer type variable
    int *ptr;

    // & operator before x is used to get address
    // of x. The address of x is assigned to ptr.
    ptr = &x;
  }

  // C program to demonstrate use of * for pointers in C
void useOfAsterisk(){
  int Var = 10;

    // A pointer variable that holds address of var.
    int *ptr = &Var;

    // This line prints value at address stored in ptr.
    // Value stored is value of variable "var"
    printf("Value of Var = %d\n", *ptr);

    // The output of this line may be different in different
    // runs even on same machine.
    printf("Address of Var = %p\n", ptr);

    // We can also use ptr as lvalue (Left hand
    // side of assignment)
    *ptr = 20; // Value at address is now 20

    // This prints 20
    printf("After doing *ptr = 20, *ptr is %d\n", *ptr);
}

// C++ program to illustrate Array Name as Pointers in C++
void arrayNameAsPointers(){
    // Declare an array
    int val[3] = { 5, 10, 15};

    // Declare pointer variable
    int *ptr;

    // Assign address of val[0] to ptr.
    // We can use ptr=&val[0];(both are same)
    ptr = val ;
    printf("Elements of the array are: %d\t%d\t%d\n",ptr[0],ptr[1],ptr[2]);

    return;
}

// C program to illustrate Pointer Arithmetic
void pointerArithmetic(){

	// Declare an array
	int v[3] = {10, 100, 200};

	// Declare pointer variable
	int *ptr;

	// Assign the address of v[0] to ptr
	ptr = v;

	for (int i = 0; i < 3; i++)
	{
		printf("Value of *ptr = %d\n", *ptr);
		printf("Value of ptr = %p\n\n", ptr);

		// Increment pointer ptr by 1
		ptr++;
	}
}
