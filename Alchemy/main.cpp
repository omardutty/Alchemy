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
std::unordered_map<std::string, std::string, std::string>mapa;

void Combinacion() {

}

//Le da los elementos basicos al player
void AddBasics() {
	elemento.push_back ("Aire");
	elemento.push_back ("Fuego");
	elemento.push_back ("Tierra");
	elemento.push_back ("Agua");
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

	std::cout << "-------------------------------" << std::endl;
	std::cout << "       FULLENTI ALCHEMIST      " << std::endl;
	std::cout << "-------------------------------" << std::endl;
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

	//std::cout << "Your current score :" << puntuacion << std::endl;

	std::ifstream archivo ("elements.dat");
	std::string line;
	std::string keydelelemento;
	std::string combinacion;
	int separacion;
	
	//Uso el getline para cojer desde el archivo cada linia
	while (getline(archivo, line)){
		//Separacion va desde el caracter 0 al =          primer caracter = 0
		separacion = line.find('=', 0);
		combinacion = line.substr(0, separacion);
		keydelelemento = line.substr(separacion + 3 );
		//Insertamos en el mapa la lectura del fichero
		mapa.insert({ keydelelemento, combinacion });
	}
	archivo.close();
	
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
