#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<fstream>
#include<algorithm>
#include<Windows.h>


//Vector de strings global
std::vector<std::string> elemento;
std::unordered_map<std::string, std::string, std::string>mapa;

//Le da los elementos basicos al player
void AddBasics() {
	elemento.push_back = "Aire";
	elemento.push_back = "Fuego";
	elemento.push_back = "Tierra";
	elemento.push_back = "Agua";
}

//Funcion que copia un elemento en concreto
void Add(int posicion) {
	std::string adder;
	adder = elemento[posicion];
	elemento.push_back(adder);
}

//Funcion que borra el elemento en concreto
void Delete(int posicion) {
	elemento.erase(elemento.begin() + posicion);
}

//Funcion que busca en Wikipedia el elemento
void Info(int posicion) {
	std::string url;
	url = "https://en.wikipedia.org/wiki/" + elemento[posicion];
	ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

//Funcion que te sortea los elementos
void Sort() {
	//Funcion tal cual ya esta bien
	std::sort(elemento.begin(), elemento.end());
}

//Funcion del clean
void Clean() {


}

//Funcion de Help para el player
void Help() {
	std::cout << "If you type addbasics you will get the basics elements : Air, Water, Fire, Earth" << std::endl;
	std::cout << "If you type add and you insert a number you will copy the element" << std::endl;
	std::cout << "If you type delete and you insert a number you will delete that element" << std::endl;
	std::cout << "If you type info and you insert a number you will get information from the internet" << std::endl;
	std::cout << "If you type sort you will order alphabetically your elements" << std::endl;
	std::cout << "If you type clean you will delete all repeteaded elements" << std::endl;
}


void main() {

	std::ifstream archivo;
	archivo.open("doc.txt");
	std::string line;
	std::string key("=");
	std::size_t punto = str.find(key);
	std::string p1, p2, p3;
	std::size_t symbol = str.find(key, 0);

	while (getline(archivo, line)) {
		p1 = str.substr(1, line - (line - symbol));

		mapa.insert(p1, p2, p3);
	}

	int posicion;
	std::string player;
	std::cin >> player;
	//std::cin >> posicion; Les complexes es millor fer en un gran if amb substrings que separen entre el numero y la funcion


	if (player == "addbasics") {
		AddBasics();
	}
	else if (player == "help") {
		Help();
	}
	else if (player == "sort") {
		Sort();
	}


	//if megalitico
	else if (player == "add") {
		Add(posicion);
	}
	else if (player == "delete") {
		Delete(posicion);
	}
	else if (player == "info") {
		Info(posicion);
	}
}
