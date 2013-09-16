/***
	
	Autor : Dragon4GitD
	Data :14.09.2013

*/



#include <iostream>
#include <cstdlib>
#include "functions.h"
#include <cstring>
#include <fstream>

using namespace std;

ofstream out("test.out");

/** Functie care aplica functia a carui nume este f_name
	asupra valorii intregi number */
void compare_for_functions (int number, char* f_name) {

	if (!strcmp (f_name, "add_one"))
		out << add_one(number);
		
	if (!strcmp (f_name, "add_five"))
		out << add_five(number);
		
	if (!strcmp (f_name, "add_seven"))
		out << add_seven(number);
		
	if (!strcmp (f_name, "add_ten"))
		out << add_ten(number);
		
	if (!strcmp (f_name, "add_twelve"))
		out << add_twelve(number);
		
	if (!strcmp (f_name, "substract_two"))
		out << substract_two(number);
		
	if (!strcmp (f_name, "substract_three"))
		out << substract_three(number);
		
	if (!strcmp (f_name, "substract_five"))
		out << substract_five(number);
		
	if (!strcmp (f_name, "substract_eight"))
		out << substract_eight(number);
		
	if (!strcmp (f_name, "substract_fifty"))
		out << substract_fifty(number);

	if (!strcmp (f_name, "multiply_by_two"))
		out << multiply_by_two(number);
		
	if (!strcmp (f_name, "multiply_by_three"))
		out << multiply_by_three(number);
		
	if (!strcmp (f_name, "multiply_by_four"))
		out << multiply_by_four(number);
		
	if (!strcmp (f_name, "multiply_by_five"))
		out << multiply_by_five(number);
		
	if (!strcmp (f_name, "multiply_by_seven"))
		out << multiply_by_seven(number);
		
	if (!strcmp (f_name, "divide_by_two"))
		out<< divide_by_two(number);

	if (!strcmp (f_name, "divide_by_three"))
		out<< divide_by_three(number);
		
	if (!strcmp (f_name, "divide_by_four"))
		out<< divide_by_four(number);
		
	if (!strcmp (f_name, "divide_by_five"))
		out<< divide_by_five(number);
		
	if (!strcmp (f_name, "divide_by_six"))
		out<< divide_by_six(number);
}

void show_results (int number, string functions_name) {

	out << " Output => [";
	
	char* names = new char [functions_name.length() + 1]; 
	char* f_name;
	strcpy (names, functions_name.c_str());
	
	//preia numele functiei din colectie
	f_name = strtok(names, " ,");
	
	/** Functie care aplica functia a carui nume este f_name
	asupra valorii intregi number */	
	compare_for_functions(number, f_name);

	while (f_name != NULL) {
		
		//preia numele functiei din colectie
		f_name = strtok(NULL, " ,");
		
		if (f_name != NULL) {
		
			out << ", ";
			compare_for_functions(number, f_name);
			
		}
	}
	
	out << "]\n";
	
	delete [] names;
}
 
int main () {

	/** Citim input-ul din fisier */
	fstream f("test.in");
	//ofstream g("test.out");
	int N, n;
	string colection, partial;
	
	/**  Numarul de input-uri*/
	f >> n;
	
	for (int i = 0 ; i < n; i++ ) {
	
		f >> N;	//valoarea intreaga		
		getline(f, colection);	//colectia de functii
		out << "Input : "<< N << " " << colection;

		/** Preiau numele de functii dintre paranteze */
		partial = colection.substr(colection.find_first_of("[") + 1, 
											colection.find_first_of("]") - 2);
		
		/** Afisez rezultatele aplicarii functiilor asupra valorii intregi */
		show_results(N, partial);		
		
	}

f.close();
out.close();

return 0;
}
