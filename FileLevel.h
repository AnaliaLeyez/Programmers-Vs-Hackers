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
    std::string getName() { return _name; }
    void setId(int i) { _id = i; }
    void setStatus(bool s) { _status = s; }
    void Cargar(int i) {
        std::cout << "NOMBRE: ";
        cargarCadena(_name, 39);
        _id=i;
        i==0 ? _status = true : _status = false;
    }
    void Mostrar() {
        std::cout << "NOMBRE: " << _name << std::endl;
        std::cout << "ID: " << _id << std::endl;
        std::cout << "ESTADO: " << _status << std::endl << std::endl;
    }
};

class FileLevels {
private:
    char name[20]= "unlockedLevels.dat";
public:
    //FileLevels() { strcpy_s(name, "unlockedLevels.dat"); }
    Levels read(int pos) {
        Levels reg;
        FILE* p;
        fopen_s(&p, name, "rb");
        if (p != nullptr) {
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        else {
            reg.setId(-1);
            return reg;
        }
    }
    void save(Levels reg) {
        FILE* p;
        fopen_s(&p, name, "ab");
        if (p != nullptr) {
            fwrite(&reg, sizeof reg, 1, p);
            fclose(p);
        }
        else return;
    }
    void edit(Levels reg, int pos) {
        FILE* p;
        fopen_s(&p, name, "rb+");
        if (p != nullptr) {
        fseek(p, pos * sizeof(Levels), 0);
        fwrite(&reg, sizeof(Levels), 1, p);
        fclose(p);
        }
        else return;
    }
};

void altaLevels() {
    FileLevels arc;
    Levels reg;
    for (int i = 0; i < 5; i++) {
        reg.Cargar(i);
        arc.save(reg);
        system("pause");
    }  
}

void leerLevels() {
    FileLevels arc;
    Levels reg;
    for (int i = 0; i < 5; i++) {
        reg= arc.read(i);
        reg.Mostrar();
    }
}