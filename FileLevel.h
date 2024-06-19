#pragma once
#include <cstdio>
#include <iostream>
#include <cstring>

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
    void Cargar(int i);
    void Mostrar();
};

class FileLevels {
private:
    char name[20]= "unlockedLevels.dat";
public:
    Levels read(int pos);
    void save(Levels reg);
    void edit(Levels &reg, int pos);
    void reset();
};

//void altaLevels() {
//    FileLevels arc;
//    Levels reg;
//    for (int i = 0; i < 5; i++) {
//        reg.Cargar(i);
//        arc.save(reg);
//        system("pause");
//    }  
//}

