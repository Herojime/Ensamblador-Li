// analizar el archivo que se leerÅEen ensamblador
//DespuÈs de analizar el archivo, tenemos que crear la tabla de s˙äbolos

#include "EnsambladorLi.h"
#include <iostream>
#include <fstream>
using namespace std;

#pragma region Instrucciones

#define HALT 0X0		//Finish.
#define WR 0X1			//Writes a newline.
#define WRC 0X2			//Writes a char.
#define WRI 0X3			//Writes an int.
#define WRD 0X4			//Writes a double.
#define WRS 0X5			//Writes a string.
#define PUSHC 0X6		//Inserts a char on top of the stack.
#define PUSHI 0X7		//Inserts an int on top of the stack.
#define PUSHD 0X8		//Inserts a double on top of the stack.
#define PUSHS 0X9		//Inserts a string on top of the stack.
#define PUSHKC 0XA		//Inserts a constant char on top of the stack.
#define PUSHKI 0XB		//Inserts a constant int on top of the stack.
#define PUSHKD 0XC		//Inserts a constant double on top of the stack.
#define PUSHKS 0XD		//Inserts a constant string on top of the stack.
#define PUSHAC 0XE		//Inserts a char from an array on top of the stack.
#define PUSHAI 0XF		//Inserts an int from an array on top of the stack.
#define PUSHAD 0X11		//Inserts a double from an array on top of the stack.
#define PUSHAS 0X12		//Inserts a string from an array on top of the stack.
#define POPC 0X13		//Pops data from the stack as a char.
#define POPI 0X14		//Pops data from the stack as an int.
#define POPD 0X15		//Pops data from the stack as a double.
#define POPS 0X16		//Pops data from the stack as a string.
#define POPAC 0X17		//Pops data from the stack as a char using the offset register.
#define POPAI 0X18		//Pops data from the stack as a int using the offset register.
#define POPAD 0X19		//Pops data from the stack as a double using the offset register.
#define POPAS 0X1A		//Pops data from the stack as a string using the offset register.
#define POPX 0X1B		//Pops from stack to pointer register (int).
#define RDC 0X1C		//Reads a char into memory.
#define RDI 0X1D		//Reads an int into memory.
#define RDD 0X1E		//Reads a double into memory.
#define RDS 0X1F		//Reads a string into memory.
#define RDAC 0X20		//Reads a char into an array using the offset register.
#define RDAI 0X21		//Reads a int into an array using the offset register.
#define RDAD 0X22		//Reads a double into an array using the offset register.
#define RDAS 0X23		//Reads a string into an array using the offset register.
#define JMP 0X24		//Jumps indonditionally to a memory address.
#define JEQ 0X25		//Jumps if the top of the stack is (==) 0.
#define JNE 0X26		//Jumps if the top of the stack is different than (!=) 0.
#define JGT 0X27		//Jumps if the top of the stack is greater than (>) 0.
#define JGE 0X28		//Jumps if the top of the stack is greater or equal than (>=) 0.
#define JLT 0X29 		//Jumps if the top of the stack is less than (<) 0.
#define JLE 0X2A		//Jumps if the top of the stack is less or equal than (<=) 0.
#define STX 0X2B		//Stores a variable in the pointer register.
#define STKX 0X2C		//Stores a constant int in the pointer register.
#define INC 0X2D		//Increases the value of a memory address by 1.
#define RED 0X2E		//Decreases the value of a memory address by 1.
#define ADD 0X2F		//Pops the two topmost numbers from the stack and adds them. The result is stored in the stack.
#define SUB 0X30		//Pops the two topmost numbers from the stack and subtracts them. The result is stored in the stack.
#define MUL 0X31		//Pops the two topmost numbers from the stack and multiplies them. The result is stored in the stack.
#define DIV 0X32		//Pops the two topmost numbers from the stack and divides them. The result is stored in the stack.
#define MOD 0X33		//Pops the two topmost numbers from the stack and divides them. The remainder is stored in the stack.
#define CMP 0X34		//Compares 2 stack values by subtracting them and stores the result in the stack.
#define DECC 0X35		// Declares a variable of type char
#define DECI 0X36		//Declares a variable of type int
#define DECD 0X37		//Declares a variable of type double
#define DECS 0X38		// Declares a variable of type string
#define DECAC 0X39		// Declares an array of type char
#define DECAI 0X3A		// Declares an array of type int
#define DECAD 0X3B		// Declares an array of type double
#define DECAS 0X3C		// Declares an array of type string

#pragma endregion Mapa de Instrucciones a hexadecimal

int main()
{
	Li Eli;

	Eli.load("C:/Users/Helio Jimenez/Desktop/prueba.cea");
	Eli.run();

	return 0;
}

Li::Li()
{
}

Li::~Li()
{
}

//Carga el archivo para ser leido
//Falta mejorarlo y verificar el identificador
bool load(string archivo)
{
	ifstream infile;
	size_t length = 0;

	infile.open(archivo, ios::in | ios::binary);

	infile.seekg(0, infile.end);
	length = infile.tellg();
	infile.seekg(0, infile.beg);

	if (length < 13) {
		cout << "FATAL ERROR: Min file size is 13 bytes" << endl;
		return true;
		//error Minimum file size is 13
	}

	vector<unsigned char> oData(length);
	infile.read((char*)&oData[0], length);
}

//Aqui debe de ir leyendo el archivo y guardar los comandos en una lista que despues se tranforman en bytes y exportarlo en un archivo .inz
void run()
{
	map <string, int > Comandos;

	Comandos["HALT"] = int(1);
	Comandos["WR"] = int(1);
	Comandos["WRC"] = int(3);
	Comandos["WRI"] = int(3);
	Comandos["WRD"] = int(3);
	Comandos["WRS"] = int(3);
	Comandos["WRAC"] = int(3);
	Comandos["WRAI"] = int(3);
	Comandos["WRAD"] = int(3);
	Comandos["WRAS"] = int(3);
	Comandos["PUSHC"] = int(3);
	Comandos["PUSHI"] = int(3);
	Comandos["PUSHD"] = int(3);
	Comandos["PUSHS"] = int(3);
	Comandos["PUSHKC"] = int(2);
	Comandos["PUSHKI"] = int(5);
	Comandos["PUSHKD"] = int(9);
	Comandos["PUSHKS"] = int(1);
	Comandos["PUSHAC"] = int(1);
	Comandos["PUSHAI"] = int(1);
	Comandos["PUSHAD"] = int(1);
	Comandos["PUSHAS"] = int(1);
	Comandos["POPC"] = int(1);
	Comandos["POPI"] = int(1);
	Comandos["POPD"] = int(1);
	Comandos["POPS"] = int(1);
	Comandos["POPAC"] = int(1);
	Comandos["POPAI"] = int(1);
	Comandos["POPAS"] = int(1);
	Comandos["POPX"] = int(1);
	Comandos["RDC"] = int(1);
	Comandos["RDI"] = int(1);
	Comandos["RDD"] = int(1);
	Comandos["RDS"] = int(1);
	Comandos["RDAC"] = int(1);
	Comandos["RDAI"] = int(1);
	Comandos["RDAD"] = int(1);
	Comandos["RDAS"] = int(1);
	Comandos["JMP"] = int(1);
	Comandos["JEQ"] = int(1);
	Comandos["JNE"] = int(1);
	Comandos["JGT"] = int(1);
	Comandos["JGE"] = int(1);
	Comandos["JLT"] = int(1);
	Comandos["JLE"] = int(1);
	Comandos["STX"] = int(1);
	Comandos["STKX"] = int(1);
	Comandos["STY"] = int(1);
	Comandos["STKY"] = int(1);
	Comandos["INC"] = int(1);
	Comandos["RED"] = int(1);
	Comandos["ADD"] = int(1);
	Comandos["SUB"] = int(1);
	Comandos["MUL"] = int(1);
	Comandos["DIV"] = int(1);
	Comandos["MOD"] = int(1);
	Comandos["CMP"] = int(1);
	Comandos["DECC"] = int(1);
	Comandos["DECI"] = int(1);
	Comandos["DECD"] = int(1);
	Comandos["DECS"] = int(1);
	Comandos["DECAC"] = int(1);
	Comandos["DECAI"] = int(1);
	Comandos["DECAD"] = int(1);
	Comandos["DECAS"] = int(1);
}
