#pragma once
//#include <cstdio>
//#include <iostream>
#include <cstring>

void cargarCadena(char* pal, int tam) {
    int i;
    fflush(stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for (i = 0; i < tam;i++) {
        pal[i] = cin.get();
        if (pal[i] == '\n')break;
    }
    pal[i] = '\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}

class Levels {
private:
	int _id;
	char _name[40];
	bool _status;
public:
    int getId() const;
    std::string getName() const;
    bool getStatus() const;
    void setId(int i);
    void setStatus(bool s);
   // void Cargar(int i);
    void Mostrar();
};

class FileLevels {
private:
    char name[20]= "unlockedLevels.dat";
public:
    Levels read(int);
    void save(Levels);
    void edit(Levels&, int);
    void reset();
};


