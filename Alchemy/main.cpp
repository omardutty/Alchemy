#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<fstream>
#include<algorithm>
#include<Windows.h>


//Vector de strings global
std::vector<std::string> elemento;
//Mapa de los elementos
std::unordered_map<std::string, std::string> mapa;
//Puntuacion del player
int puntuacionplayer = 0;


void lecturadelfichero() {
	std::ifstream archivo("elements.dat");
	std::string line;
	std::string keydelelemento;
	std::string combinacion;
	int separacion;

	//Uso el getline para cojer desde el archivo cada linia
	while (getline(archivo, line)) {
		//Separacion va desde el caracter 0 al =          primer caracter = 0
		separacion = line.find(" = ", 0);
		combinacion = line.substr(0, separacion);
		keydelelemento = line.substr(separacion + 3);
		//Insertamos en el mapa la lectura del fichero
		mapa.insert({ keydelelemento, combinacion });
	}
	archivo.close();

	/*//For que pemite imprimir el documento de elementos
	for (auto it = mapa.begin(); it != mapa.end(); ++it){
	std::cout << " " << it->first << " : " << it->second << std::endl;
	}*/
}


/*std::string Combination(std::string comb1, std::string comb2) {
	std::pair<std::string, std::string> combinacion = std::make_pair(comb1, comb2);
	if ()
	{
		
	}
	else
	{
		//return std::cout << "No existe la combinacion" << std::endl;
	}
}
*/

//Le da los elementos basicos al player
void AddBasics() {
	elemento.push_back ("Air");
	elemento.push_back ("Fire");
	elemento.push_back ("Earth");
	elemento.push_back ("Water");
}

//Funcion que copia un elemento en concreto
void Add() {
	int posicion;
	std::cin >> posicion;
	std::string adder;
	adder = elemento[posicion];
	elemento.push_back(adder);
}

//Funcion que borra el elemento en concreto
void Delete() {
	int posicion;
	std::cin >> posicion;
	elemento.erase(elemento.begin() + posicion);
}

//Funcion que busca en Wikipedia el elemento
void Info() {
	int posicion;
	std::cin >> posicion;
	std::string url;
	url = "https://en.wikipedia.org/wiki/" + elemento[posicion];
	ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

//Funcion que te sortea los elementos
void Sort() {
	//Funcion tal cual ya esta bien
	std::sort(elemento.begin(), elemento.end());
}

//Funcion del clean problema solo borra cuando estan ordenados alfabeticamente
void Clean() {
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



void main() {
	lecturadelfichero();

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

	std::cout << "Your current score :" << puntuacionplayer << std::endl;
	
	// Printear los basics al inicio del juego
	AddBasics();
	std::cout << "You have those elements :" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << "     " << i << "  " << elemento[i] << std::endl;
	}

	std::string player;
	std::cin >> player;

	//std::cin >> posicion; //Les complexes es millor fer en un gran if amb substrings que separen entre el numero y la funcion
	/*std::pair<int, int>combination;
	int a, b;
	//std::cin >> a >> b;	BUG por el cin porque lo estamos haciendo abajo del main
	combinacion = (a, b);*/

	while (player != "endgame")
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
		else {
			std::cout << "I don't understand that buddy! Type help for help!"<<std::endl;
		}

		std::cout << "You have those elements :" << std::endl;
		for (int i = 0; i <= elemento.size()-1; i++){
			std::cout <<"     "<< i << "  " << elemento[i] << std::endl;
		}
		std::cin >> player;
	}
}
