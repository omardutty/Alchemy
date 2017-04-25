#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<fstream>



struct Elemento {
	std::string Elemento;
};

std::vector<Elemento> listaElementos;
std::unordered_map<std::string, std::string, std::string>mapa;

void main() {

	std::ifstream archivo;
	archivo.open("doc.txt");
	std::string line;
	std::string key ("=");
	std::size_t punto = str.find(key);
	std::string p1, p2, p3;
	std::size_t symbol = str.find(key, 0);
	
	while (getline(archivo, line)) {
		p1 = str.substr(1, line - (line - symbol));
		
			mapa.insert(p1, p2, p3);
	}





	listaElementos.push_back(Elemento());
	listaElementos[0].Elemento = "Aire";
	listaElementos[1].Elemento = "Fuego";
	listaElementos[2].Elemento = "Tierra";
	listaElementos[3].Elemento = "Agua";
}
