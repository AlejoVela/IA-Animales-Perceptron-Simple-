#ifndef MARCHIVO_H
#define MARCHIVO_H
#include <stdlib.h>     
#include <string>     
#include <fstream>     
#include <iostream>
using namespace std;

void escribir(string m) {
    //creamos archivo
    ofstream archivo;

    //con esto abrimos el archivo
    //el primer parametro que recibe es la direccion
    //y nombre del archivo, el segundo parametro es el modo
    //en que lo usaremos, en este caso "out" significa que lo abriremos
    //si el archivo con este nombre existe, entonces lo va a reemplazar
    //sino, entonces lo creará
    archivo.open("./datos.txt", ios::out);

    //si el archivo fallo, envia un true si hubo un error al
    //abrir o crear el archivo, sino enviara false
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    archivo << m;

    archivo.close();
}


void lectura() {
    //creamos el archivo
    ifstream archivo;
    string texto;
    //abrimos el archivo, se le pasa el nombre del archivo  abrir
    //el segundo parametro in, hace referencia a que lo abrimos en modo lectura
    archivo.open("./datos.txt", ios::in);

    if (archivo.fail()) {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    //mientras no sea el final del archivo
    //recorra todo el archivo
    while (!archivo.eof()) {
        //copiamos el contenido del archivo
        //a la variable texto
        getline(archivo, texto);
        cout << texto;
    }

    archivo.close();//cerramos el archivo

}

void addinfo() {

    ofstream archivo;
    string texto = "este es el texto añadido";

    //se abre el archivo en modo añadir texto
    archivo.open("datos.txt", ios::app);

    if (archivo.fail()){
        cout << "no se pudo añadir informacion";
            exit(1);
    }

    archivo << texto << endl;

    archivo.close();

}

#endif