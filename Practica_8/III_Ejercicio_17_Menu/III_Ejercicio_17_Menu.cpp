﻿/******************************************************************************
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - Ernesto Serrano Collado
	------------------------------
	En el main se leerán dos enteros y a continuación se ofrecerá al usuario un 
	menú con las opciones para realizar cualquiera de las opera- ciones 
	definidas en la clase ParejaEnteros. También se ofrecerá la posibilidad de 
	imprimir el valor de cada uno de los dos enteros. Una vez ejecutada la 
	operación, se volverá a mostrar el mismo menú, hasta que el usuario decida 
	salir. 

******************************************************************************/
#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class ParejaEnteros {

private: 

	//Atributos
	int numero1;
	int numero2;

public:
/*****************************************************************************/
	//Constructor
	ParejaEnteros(int pNumero1, int pNumero2) {
		
		//Asignamos los atributos
		numero1 = pNumero1;
		numero2 = pNumero2;

	}
/*****************************************************************************/
	//Métodos
	int Mayor() {
		//Devuelve el mayor de los dos numero
		if (numero1 > numero2) {
			return numero1;
		}else{
			return numero2;
		}
	}
/*****************************************************************************/
	int Menor() {
		//Devuelve el menor de los dos numero
		if (numero1 < numero2) {
			return numero1;
		}else{
			return numero2;
		}
	}
	bool Dividen() {

		//Segun el ejercicio 3 de la relación, si el resto es 0 es que dividen
		return Dividendo() % Divisor() == 0;

	}
/*****************************************************************************/
	int Dividendo() {
		//El mayor será el dividendo
		return Mayor();
	}
/*****************************************************************************/
	int Divisor() {
		//El menor será el divisor
		return Menor();
	}
/*****************************************************************************/
	void Intercambiar() {
	
		//Intercambiamos el valor de las variables usando una variable temporal
		int tmp = numero1;
		numero1 = numero2;
		numero2 = tmp;
		
	}
/*****************************************************************************/
	//Funcion que calcula el maximo comun divisor
	int MCD() {
	
		int menor = Menor();
		int mayor = Mayor();

		while(mayor != menor){
			if(mayor > menor)
				mayor -= menor;
			else
				menor -= mayor;
		}
		return mayor;

	}


};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los valores
	int numero1;				
	int numero2;
	int select = 0;

	//Obtenemos los datos necesarios
	cout << "Introduzca un numero (1): ";
	cin >> numero1;
	cout << "Introduzca un numero (2): ";
	cin >> numero2;

	//Creamos un objeto de la clase ParejaEnteros
	ParejaEnteros pareja_enteros(numero1,numero2);

	do {

		cout << "Elija un elementos de la lista: (0 para salir):\n";
		cout << "\t1: Mayor\n";
		cout << "\t2: Menor\n";
		cout << "\t3: ¿Dividen?\n";
		cout << "\t4: Divisor\n";
		cout << "\t5: Dividendo\n";
		cout << "\t6: MCD\n";
		cout << "\t7: Imprimir numero (1)\n";
		cout << "\t8: Imprimir numero (2)\n";
		cin >> select;

		//Pintamos los valores en la consola
		switch (select) {
			
		case 1:
			cout << "El mayor es: " << pareja_enteros.Mayor() << "\n";
			break;
		case 2:
			cout << "El menor es: " << pareja_enteros.Menor() << "\n";
			break;
		case 3:
			cout << "¿Se dividen? 0=No 1=Si: " << pareja_enteros.Dividen() << "\n";
			break;
		case 4:
			cout << "El Divisor es: " << pareja_enteros.Divisor() << "\n";
			break;
		case 5:
			cout << "El Dividendo es: " << pareja_enteros.Dividendo() << "\n";
			break;
		case 6:
			cout << "El MCD es: " << pareja_enteros.MCD() << "\n";
			break;
		case 7:
			cout << "El primer numero es: " << numero1 << "\n";
			break;
		case 8:
			cout << "El segundo numero es: " << numero2 << "\n";
			break;
		}
	
	} while (select != 0);


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}