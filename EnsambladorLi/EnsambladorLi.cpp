// analizar el archivo que se leerÅEen ensamblador
//DespuÈs de analizar el archivo, tenemos que crear la tabla de s˙äbolos

#include "EnsambladorLi.h"
#include <iostream>
#include <fstream>
using namespace std;

#pragma region Instrucciones

#define HALT 0X0		//Finish.
#define WR 0X1		//Writes a newline.
#define WRC 0X2		//Writes a char.
#define WRI 0X3		//Writes an int.
#define WRD 0X4		//Writes a double.
#define WRS 0X5		//Writes a string.
#define WRAC 0X6		//
#define WRAI 0X7		//
#define WRAD 0X8		//
#define WRAS 0X9		//
#define WRKS 0XA		//
#define PUSHC 0XB		//Inserts a char on top of the stack.
#define PUSHI 0XC		//Inserts an int on top of the stack.
#define PUSHD 0XD		//Inserts a double on top of the stack.
#define PUSHS 0XE		//Inserts a string on top of the stack.
#define PUSHKC 0XF		//Inserts a constant char on top of the stack.
#define PUSHKI 0X10		//Inserts a constant int on top of the stack.
#define PUSHKD 0X11		//Inserts a constant double on top of the stack.
#define PUSHKS 0X12		//Inserts a constant string on top of the stack.
#define PUSHAC 0X13		//Inserts a char from an array on top of the stack.
#define PUSHAI 0X14		//Inserts an int from an array on top of the stack.
#define PUSHAD 0X15		//Inserts a double from an array on top of the stack.
#define PUSHAS 0X16		//Inserts a string from an array on top of the stack.
#define POPC 0X17		//Pops data from the stack as a char.
#define POPI 0X18		//Pops data from the stack as an int.
#define POPD 0X19		//Pops data from the stack as a double.
#define POPS 0X1A		//Pops data from the stack as a string.
#define POPAC 0X1B		//Pops data from the stack as a char using the offset register.
#define POPAI 0X1C		//Pops data from the stack as a int using the offset register.
#define POPAD 0X1D		//Pops data from the stack as a double using the offset register.
#define POPAS 0X1E		//Pops data from the stack as a string using the offset register.
#define POPX 0X1F		//Pops from stack to pointer register (int).
#define RDC 0X20		//Reads a char into memory.
#define RDI 0X21		//Reads an int into memory.
#define RDD 0X22		//Reads a double into memory.
#define RDS 0X23		//Reads a string into memory.
#define RDAC 0X24		//Reads a char into an array using the offset register.
#define RDAI 0X25		//Reads a int into an array using the offset register.
#define RDAD 0X26		//Reads a double into an array using the offset register.
#define RDAS 0X27		//Reads a string into an array using the offset register.
#define JMP 0X28		//Jumps indonditionally to a memory address.
#define JEQ 0X29		//Jumps if the top of the stack is (==) 0.
#define JNE 0X2A		//Jumps if the top of the stack is different than (!=) 0.
#define JGT 0X2B		//Jumps if the top of the stack is greater than (>) 0.
#define JGE 0X2C		//Jumps if the top of the stack is greater or equal than (>=) 0.
#define JLT 0X2D		//Jumps if the top of the stack is less than (<) 0.
#define JLE 0X2E		//Jumps if the top of the stack is less or equal than (<=) 0.
#define STX 0X2F		//Stores a variable in the pointer register.
#define STKX 0X30		//Stores a constant int in the pointer register.
#define STY 0X31		//
#define	STKY 0X32
#define INC 0X33		//Increases the value of a memory address by 1.
#define RED 0X34		//Decreases the value of a memory address by 1.
#define ADD 0X35		//Pops the two topmost numbers from the stack and adds them. The result is stored in the stack.
#define SUB 0X36		//Pops the two topmost numbers from the stack and subtracts them. The result is stored in the stack.
#define MUL 0X37		//Pops the two topmost numbers from the stack and multiplies them. The result is stored in the stack.
#define DIV 0X38		//Pops the two topmost numbers from the stack and divides them. The result is stored in the stack.
#define MOD 0X39		//Pops the two topmost numbers from the stack and divides them. The remainder is stored in the stack.
#define CMP 0X3A		//Compares 2 stack values by subtracting them and stores the result in the stack.
#define DECC 0X3B		//Declares a char
#define DECI 0X3C		//Declares an int
#define DECD 0X3D		//Declares a double
#define DECS 0X3E		//Declares a string
#define DECAC 0X3F	//Declares an array of chars
#define DECAI 0X40	//Declares an array of integers
#define DECAD 0X41	//Declares an array of doubles
#define DECAS 0X42	//Declares an array of strings

#pragma endregion Mapa de Instrucciones a hexadecimal


void Li::addVar(string hex)
{
	if (variables.find(hex) != variables.end()) {
		addToCode(variables[hex]);
	}
	else {
		//error variable doesnt exists
	}
}

void Li::addToCode(unsigned int dir, int start)
{
	union {
		unsigned int value;
		char byte[4];
	} u;
	u.value = dir;
	for (int i = start; i >= 0; i--)
		code += (unsigned char)u.byte[i];
}

void Li::addToCode(unsigned int dir) {
	addToCode(dir, 1);
}

bool Li::validateDirection(unsigned int test) {
	return true;
}

int main (int argc, char* argv[])
{
	cout << argc << endl;

	if (argc > 1 && argc <= 3) {
		string source = argv[1];
		string dest = argv[2];
		Li test;
		test.load(source, dest);
	}
	else {
		cout << "Please provide source and destination params" << endl;
	}

	return 0;
	//	Li Eli;
	//
	//	Eli.load("C:/Users/Helio Jimenez/Desktop/prueba.cea");
	//	Eli.run();
	//
	//	return 0;
}


Li::Li()
{
	nextMemorySlot = 0;
	currentByte = 0;
}

Li::~Li()
{
}

//Carga el archivo para ser leido
//Falta mejorarlo y verificar el identificador
bool load(string source, string destination)
{

	ofstream target(destination, ios::out | ios::binary);
	ifstream sourceCode(source);
	//write the identifier
	target.write((char*)identifier.c_str(), identifier.length());
	unsigned int intContainer = 0;
	int intContainerSigned;
	unsigned char charContainer;
	double doubleContainer;
	//start code section


	while (sourceCode.is_open()) {
		string hex = "";
		sourceCode >> hex;
		if (comandos.find(hex) != comandos.end())
			switch (comandos[hex])
			{
			case HALT:
				code += (unsigned char)comandos[hex];
				sourceCode.close();
				break;
			case WR:
				code += (unsigned char)comandos[hex];
				break;
			case WRC:
			case WRI:
			case WRD:
			case WRAC:
			case WRAI:
			case WRAD:
			case PUSHC:
			case PUSHI:
			case PUSHD:
			case PUSHS:
			case PUSHAC:
			case PUSHAI:
			case PUSHAD:
			case POPC:
			case POPI:
			case POPD:
			case POPS:
			case POPAC:
			case POPAI:
			case POPAD:
			case RDC:
			case RDI:
			case RDD:
			case RDAC:
			case RDAI:
			case RDAD:
			case STX:
			case STY:
			case INC:
			case RED:
			case WRS:
				code += (unsigned char)comandos[hex];
				sourceCode >> hex;
				addVar(hex);
				break;
			case WRAS:
				code += (unsigned char)comandos[hex];
				sourceCode >> hex;
				addVar(hex);
				break;
			case PUSHKC:
				code += (unsigned char)comandos[hex];
				sourceCode >> charContainer;
				addToCode((unsigned int)charContainer, 1);
				break;
			case PUSHKI:
				break;
			case PUSHKD:
				break;
			case PUSHKS:
				break;
			case PUSHAS:
				break;
			case POPAS:
				break;
			case POPX:
				code += (unsigned char)comandos[hex];
				break;
			case RDS:
				code += (unsigned char)comandos[hex];
				sourceCode >> hex;
				addVar(hex);
				break;
			case RDAS:
				break;
			case JMP:
				code += (unsigned char)comandos[hex];
				sourceCode >> intContainer;
				if (validateDirection(intContainer))
					addToCode(intContainer);
				else {
					//error direction not valid
					sourceCode.putback(intContainer);
				}
				break;
			case JEQ:
				break;
			case JNE:
				break;
			case JGT:
				break;
			case JGE:
				break;
			case JLT:
				break;
			case JLE:
				break;
			case STKX:
			case STKY:
				code += (unsigned char)comandos[hex];
				sourceCode >> intContainer;
				addToCode(intContainer);
				break;
			case ADD:
			case SUB:
			case MUL:
			case DIV:
			case MOD:
			case CMP:
				code += (unsigned char)comandos[hex];
				break;
			case DECC:
				sourceCode >> hex;
				variables[hex] = nextMemorySlot;
				nextMemorySlot += 1;
				break;
			case DECI:
				sourceCode >> hex;
				variables[hex] = nextMemorySlot;
				nextMemorySlot += 4;
				break;
			case DECD:
				sourceCode >> hex;
				variables[hex] = nextMemorySlot;
				nextMemorySlot += 8;
				break;
			case DECS:
				sourceCode >> hex;
				variables[hex] = nextMemorySlot;
				sourceCode >> intContainer;
				nextMemorySlot += intContainer;
				stringSize[hex] = intContainer;
				break;
			case DECAC:
				sourceCode >> hex;
				variables[hex] = nextMemorySlot;
				sourceCode >> intContainer;
				nextMemorySlot += intContainer;
				arraySize[hex] = intContainer;
				break;
			case DECAI:
				sourceCode >> hex;
				variables[hex] = nextMemorySlot;
				sourceCode >> intContainer;
				nextMemorySlot += 4 * intContainer;
				arraySize[hex] = intContainer;
				break;
			case DECAD:
				sourceCode >> hex;
				variables[hex] = nextMemorySlot;
				sourceCode >> intContainer;
				nextMemorySlot += 8 * intContainer;
				arraySize[hex] = intContainer;
				break;
			case DECAS:
				sourceCode >> hex;
				variables[hex] = nextMemorySlot;
				sourceCode >> intContainer;
				nextMemorySlot += 4 * intContainer;
				arraySize[hex] = intContainer;
				sourceCode >> intContainer;
				nextMemorySlot += 4 * intContainer;
				stringSize[hex] = intContainer;
				//store array size in another list
				break;
			}

	}
	//calculate code segment size and data segment size
	target.write((char*)&codeSize, sizeof(codeSize));
	target.write((char*)&dataSize, sizeof(dataSize));

	for (int i = 0; i < code.length(); i++) {
		char* test = &code[i];
		target.write(test, 1);
	}
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