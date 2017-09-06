// analizar el archivo que se leerá en ensamblador
//Después de analizar el archivo, tenemos que crear la tabla de símbolos

#include <iostream>
#include <fstream>
using namespace std;


class li
{

//public:

//private:

	int main
	{
		ofstream archivo;
		Archivo.open(“codigo.txt”);
	}

}

#pragma region Instrucciones

#define HALT 0		//Finish.
#define WR 1		//Writes a newline.
#define WRC 2		//Writes a char.
#define WRI 3		//Writes an int.
#define WRD 4		//Writes a double.
#define WRS 5		//Writes a string.
#define PUSHC 6		//Inserts a char on top of the stack.
#define PUSHI 7		//Inserts an int on top of the stack.
#define PUSHD 8		//Inserts a double on top of the stack.
#define PUSHS 9		//Inserts a string on top of the stack.
#define PUSHKC A	//Inserts a constant char on top of the stack.
#define PUSHKI B	//Inserts a constant int on top of the stack.
#define PUSHKD C	//Inserts a constant double on top of the stack.
#define PUSHKS D	//Inserts a constant string on top of the stack.
#define PUSHAC E	//Inserts a char from an array on top of the stack.
#define PUSHAI F	//Inserts an int from an array on top of the stack.
#define PUSHAD 11	//Inserts a double from an array on top of the stack.
#define PUSHAS 12	//Inserts a string from an array on top of the stack.
#define POPC 13		//Pops data from the stack as a char.
#define POPI 14		//Pops data from the stack as an int.
#define POPD 15		//Pops data from the stack as a double.
#define POPS 16		//Pops data from the stack as a string.
#define POPAC 17	//Pops data from the stack as a char using the offset register.
#define POPAI 18	//Pops data from the stack as a int using the offset register.
#define POPAD 19	//Pops data from the stack as a double using the offset register.
#define POPAS 1A	//Pops data from the stack as a string using the offset register.
#define POPX 1B		//Pops from stack to pointer register (int).
#define RDC 1C		//Reads a char into memory.
#define RDI 1D		//Reads an int into memory.
#define RDD 1E		//Reads a double into memory.
#define RDS 1F		//Reads a string into memory.
#define RDAC 20		//Reads a char into an array using the offset register.
#define RDAI 21		//Reads a int into an array using the offset register.
#define RDAD 22		//Reads a double into an array using the offset register.
#define RDAS 23		//Reads a string into an array using the offset register.
#define JMP 24		//Jumps indonditionally to a memory address.
#define JEQ 25		//Jumps if the top of the stack is (==) 0.
#define JNE 26		//Jumps if the top of the stack is different than (!=) 0.
#define JGT 27		//Jumps if the top of the stack is greater than (>) 0.
#define JGE 28		//Jumps if the top of the stack is greater or equal than (>=) 0.
#define JLT 29 		//Jumps if the top of the stack is less than (<) 0.
#define JLE 2A		//Jumps if the top of the stack is less or equal than (<=) 0.
#define STX 2B		//Stores a variable in the pointer register.
#define STKX 2C		//Stores a constant int in the pointer register.
#define INC 2D		//Increases the value of a memory address by 1.
#define DEC 2E		//Decreases the value of a memory address by 1.
#define ADD 2F		//Pops the two topmost numbers from the stack and adds them. The result is stored in the stack.
#define SUB 30		//Pops the two topmost numbers from the stack and subtracts them. The result is stored in the stack.
#define MUL 31		//Pops the two topmost numbers from the stack and multiplies them. The result is stored in the stack.
#define DIV 32		//Pops the two topmost numbers from the stack and divides them. The result is stored in the stack.
#define MOD 33		//Pops the two topmost numbers from the stack and divides them. The remainder is stored in the stack.
#define CMP 34		//Compares 2 stack values by subtracting them and stores the result in the stack.
#define DECC 35		// Declares a variable of type char
#define DECI 36		//Declares a variable of type int
#define DECD 37		//Declares a variable of type double
#define DECS 38		// Declares a variable of type string
#define DECAC 39		// Declares an array of type char
#define DECAI 3A		// Declares an array of type int
#define DECAD 3B		// Declares an array of type double
#define DECAS 3C		// Declares an array of type string

# pragma endregion Mapa de Instrucciones a hexadecimal
