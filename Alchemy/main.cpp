#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<fstream>
#include<algorithm>
#include<Windows.h>
#include "HeaderMap.h"


//Vector de strings global
std::vector<std::string> elemento({" ", "Air", "Earth", "Fire", "Water"}); // Posicion vacia para poder imprimir la tabla empezando por el 1
//Mapa de los elementos, lo he vuelto a modificar para que entren pairs
std::unordered_map<std::string, std::string> mapa;
//Puntuacion del player
int puntuacionplayer = 0;


void lecturadelfichero() {
	std::ifstream archivo;						           //inicializamos una variable de tipo ifstring
	std::string texto;
	archivo.open("elements.dat", std::ios::in);			   //abrimos el archivo de los elementos

	if (archivo.fail()) {                                  //en caso de que no se pueda abrir el archivo paramos el sistema
		std::cout << "The file is not here! Sorry buddy but I can't open it!";
		system("pause");
	}

	while (!archivo.eof()) {							   //mientras no llegue al final del archivo
		std::getline(archivo, texto);                      //cojemos toda la linia i la guardamos como un string --> http://www.cplusplus.com/reference/string/string/getline/
		int j = 0;
        int i = 0;										   
		while (i < texto.length() && j == 0) {             //mientras i sea mas pequeño que el tamaño del texto y j sea 0 
			if (texto[i] == '=') j = i;                    //separamos la key que seria "Lava" de la suma de los elementos "Earth + Fire"
			++i;
		}
		std::string key = texto.substr(0, j - 1);          //cojemos desde el principio de la linia, 0 , hasta la poscion j-1 que evivale al =
		std::string cont = texto.substr(j + 2, texto.length() - (j + 2)); //a j le sumamos 2 por los espacios, y posteriormente al legth le restamos j + 2 para poder cojer el otro string "Fire + Earth"  
		mapa[cont] = key;                                  //el contenido del mapa es igual a la key "Fire + Earth = Lava"
	}
	archivo.close(); 

	/*//For que pemite imprimir el documento de elementos
	for (auto it = mapa.begin(); it != mapa.end(); ++it){
	std::cout << " " << it->first << " : " << it->second << std::endl;
	}*/
}

//Le da los elementos basicos al player
void AddBasics() {
	elemento.push_back ("Air");
	elemento.push_back ("Earth");
	elemento.push_back ("Fire");
	elemento.push_back ("Water");
}

//Funcion que copia un elemento en concreto
void Add() {
	int posicion;
	std::cin >> posicion;
	if (posicion > elemento.size()) {
		std::cout << "Sorry but that element dosn't exist" << std::endl;
	}
	else{
		std::string adder;
		adder = elemento[posicion];							//guardamos el elemento que queremos y posteriormente hacemos un push_back de este
		elemento.push_back(adder);
	}
}

//Funcion que borra el elemento en concreto
void Delete() {
	int posicion;
	std::cin >> posicion;
	if (posicion > elemento.size()) {
		std::cout << "Sorry but that element dosn't exist" << std::endl;
	}
	else{
		elemento.erase(elemento.begin() + posicion);
	}
}

//Funcion que busca en Wikipedia el elemento
void Info() {
	int posicion;
	std::cin >> posicion;
	if (posicion > elemento.size()) {
		std::cout << "Sorry but that element dosn't exist" << std::endl;
	}
	else{
		std::string url;
		url = "https://en.wikipedia.org/wiki/" + elemento[posicion];   //Union de los dos "strings", para poder buscar en wikipedia
		ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
	}
}

//Funcion que te sortea los elementos
void Sort() {
  std::sort(elemento.begin(), elemento.end());
}

//Funcion del clean problema solo borra cuando estan ordenados alfabeticamente
void Clean() {
	std::sort(elemento.begin(), elemento.end());
	elemento.erase(std::unique(elemento.begin(), elemento.end()), elemento.end());
}

//Funcion de Help para el player
void Help() {
	std::cout << "If you type addbasics you will get the basics elements : Air, Water, Fire, Earth" << std::endl;
	std::cout <<std::endl;
	std::cout << "If you type add and you insert a number you will copy the element" << std::endl;
	std::cout << std::endl;
	std::cout << "If you type delete and you insert a number you will delete that element" << std::endl;
	std::cout << std::endl;
	std::cout << "If you type info and you insert a number you will get information from the      internet" << std::endl;
	std::cout << std::endl;
	std::cout << "If you type sort you will order alphabetically your elements" << std::endl;
	std::cout << std::endl;
	std::cout << "If you type clean you will delete all repeteaded elements" << std::endl;
	std::cout << std::endl;
}

void Combinacion() {
	int num1, num2;
	std::cin >> num1 >> num2;												    //pedimos los dos numeros al player
	std::string elemento1, elemento2;											//generamos los dos strings para almacenarlos
	elemento1 = elemento[num1];													//asignamos el valor de la posicion del vector cogiendo el elemento que necesitamos
	elemento2 = elemento[num2];

	std::string aux = " + ";
	std::string comb = elemento1 + aux + elemento2;								//la suma de los tres strings es la combinacion, ejemplo  "Fire + Water"
	std::unordered_map<std::string, std::string>::iterator iterador;			//creacion del iterador que ira recorriendo el map

	iterador = mapa.find(comb);													//buscamos la combinacion, si existe
	if (iterador != mapa.end()) {												//si el iterador esta antes del fin del archivo existe si no, no

		elemento.erase(elemento.begin() + num1);								//borramos los elementos combinados
		elemento.erase(elemento.begin() + num2); 

		std::string result = iterador->second;								    //second hace referencia a lo que hay al otro lado del igual en el archivo de lectura
		std::cout << "Your new elements is : " << result << std::endl;
		elemento.push_back(result);												//pusheamos el nuevo elemento
		puntuacionplayer++;														//aumentamos la puntuacion del player
	}
	else {
		std::cout << "The combination have failed! I'm sorry!" << std::endl;
	}
}

void gamemenu() {
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "                FULLENTI ALCHEMIST               " << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Made by: Oscar Espejo Sagues && Omar Gil Sturlese" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "- Enter two numbers of your element list to combine them" << std::endl;
	std::cout << "- Enter the word 'add' and the number of a element to add a new instance of that element" << std::endl;
	std::cout << "- Enter 'addbasics' add new instances of the 4 basics elements" << std::endl;
	std::cout << "- Enter 'delete' and the number of a element to erase it" << std::endl;
	std::cout << "- Enter 'info' and the number of the element and you will get information of that element" << std::endl;
	std::cout << "- Enter 'sort' to sort alphabetical orders of the elements" << std::endl;
	std::cout << "- Enter 'clean' to delete all the instances of repeated elements" << std::endl;
	std::cout << "- Enter 'help' to show a tutorial" << std::endl;
	std::cout << " " << std::endl;
}



void main() {
	lecturadelfichero();
	gamemenu();
	// Printear los basics al inicio del juego
	std::cout << "You have those elements :" << std::endl;
		for (int i = 1; i < elemento.size(); i++) {				// Empezamos a imprimir por el 1
		std::cout << "     " << i << "  " << elemento[i] << std::endl;
	    }
	std::string player;
	std::string comando1;
	std::string comando2;
	//std::string cadena;
	//std::cin >> player;
	
	if (true)//hacer que el player pedir si es una funcion simple como sort, help, clean solo pedir uno si es una mas compleja pedir otra con ifs
	{

	}

	while (puntuacionplayer != 100)
	{
		if (player == "addbasics") {
			AddBasics();
		}
		else if (player == "help") {
			Help();
		}
		else if (player == "sort") {
			Sort();
		}
		else if (player == "clean") {
			Clean();
		}
		else if (player == "add") {
			Add();
		}
		else if (player == "delete") {
			Delete();
		}
		else if (player == "info") {
			Info();
		}
		else if (player == "comb") {
			Combinacion();
		}

		else {
			//std::cin >> cadena;

			/*if (/*std::stoi(player) && std::stoi(cadena)) {	//Combierte el string en un numero
				//No se como indicarle el primero mas el segundo
				Combinacion();
			}*/
			std::cout << "I don't understand that buddy! Type help for help!" << std::endl;
		}
			std::cout << "Your current score : " << puntuacionplayer << std::endl;
			std::cout << "You have those elements :" << std::endl;
			for (int i = 1; i <= elemento.size() - 1; i++) {			// Empezamos a imprimir por el 1
				std::cout << "     " << i << "  " << elemento[i] << std::endl;
			}
			std::cin >> player;
			system("cls");	
	}
}
