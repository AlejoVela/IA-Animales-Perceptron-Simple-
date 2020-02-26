#include <iostream>     //para los componetes de c++
#include <stdlib.h>     //para los componentes de c
#include <string>       //facilita el manejo de string
#include <fstream>      //permite el manejo de archivo
#include "ListaDoble.h" //archivo que controla las listas
#include "mArchivo.h"   //para el manejo de archivos
#include "Animal.h"     //para crear objetos de tipo animal
#include <sstream>
using namespace std;
//string m = "1.InsertFirst\n2. InsertLast\n3. InsertAfter\n4.DeleteFirst\n5. 
//DeleteLast\n6.SearchItem \n7. PrintList \n8. ReversePrint \n9. DeleteItem 
//\n10. Left Rotate \n11. Right Rotate \n12. Exit  \n13.Make reverse\n";

void mostrar(string);
int pedirInt(string);
string pedirString(string);
float pedirFloat(string);
void ingresarAnimal();
string ITS(int);
/*CARACTERISTICAS USADAS

    d:  domesticable, si = 0, no = 1
    a:  alimentacion, animales pequeños = 0, grandes = 1
    t:  tamaño, pequeño = 0, grande = 1
    h:  Urbano = 0, salvaje = 1

*/
string dat;
float pd = 0.5, pa = 0.5, pt = 0.5, ph = 0.5, umbral = 1 , pu = 0.5;                                         //pesos para los pesos de las caracteristica: pa = peso alimentación,..,etc.

int main()
{

    init();                                                                 //inicializa la cabecera y la cola de la lista

    int op = 0;                                                             //variable para controlar las opciones del menu
    string m = "Menu:\n1. Ingresar animal\n2. Consultar datos\n3. Salir";   //menu

    string name;

    do {

        op = pedirInt(m);

        switch (op)
        {
        case 1:

            ingresarAnimal();

            break;

        case 2:

            lectura();

            break;
        case 3:

            mostrar("Gracias por usar el programa\nPresiona cualquier tecla para continuar");
            system("PAUSE");
            exit(1);
            break;

        default:
            break;
        }

    } while (op!=3);
 
}

void mostrar(string m) {
    cout << m << endl;
}

int pedirInt(string m) {
    int n;
    mostrar(m);
    cin >> n;
    return n;
}

string pedirString(string m) {
    string n;
    mostrar(m);
    cin.ignore();
    getline(cin, n);
    return n;
}

float pedirFloat(string m) {
    float n;
    mostrar(m);
    cin >> n;
    return n;
}

string ITS(int i) {//entero a string
    stringstream ss;
    ss << i;
    string str = ss.str();
    return str;
}

string FTS(float f) {
    ostringstream ss;
    ss << f;
    string s(ss.str());
    return s;
}

void ingresarAnimal() {
    float so;//salida obtenida

    string datos = " Estado inicial\n";

    string n = pedirString("ingresa el nombre el animal");

    int d = pedirInt("Domesticable = 0, no domesticable = 1");
    int a = pedirInt("Caza animales: pequeños = 0, grandes = 1");
    int t = pedirInt("Su tamaño es: pequeño = 0, grande = 1");
    int h = pedirInt("Su habitad es: Urbano = 0, salvaje = 1");
    int sd = pedirInt("Ingrese la salida deseada, peligroso = 1, inofensivo = 0");//salida deseada
    Animal animal(n, d, a, t, h);
    //guardar animal en la lista u operarlo
    datos += " \nNombre del animal: " + n;
    datos += " \nDomesticable: "+ ITS(d);

    datos += " \nTamano de animales que caza: "+ ITS(a);
    datos += " \nSu tamaño es: "+ ITS(t);
    datos += " \nSu habitad es: " + ITS(h);

    datos += " \nPeso de entrada domesticable: " + FTS(pd);                      
    datos += " \nPeso de entrada Tamano de animales que caza: " + FTS(pa);
    datos += " \nPeso de entrada Su tamaño es: " + FTS(pt);
    datos += " \nPeso de entrada Su habitad es: " + FTS(ph);
    datos += " \nUmbral: " + FTS(umbral);
    datos += " \nPeso del umbral: " + FTS(pu);

 
    int epoca = 0;
    int estado; //para verificar si el estado cambio entre epocas
    int suma; //para llevar el resultado al usar la funcion escalonada en la sumatoria
    do {
        
        datos += " \nEpoca: "+ITS(epoca);

        if (epoca > 0) {
            //modificamos los pesos
            float w1, w2, w3, w4, wu;
            datos += " \nCorrecion de pesos con la ecuacion Wn = Wi + a*(sd - so)*Xi";
            pd = pd + 0.03 * (float)((sd + (-1*so)) * d);
            pa = pa + 0.03 * (float)((sd - so) * a);
            pt = pt + 0.03 * (float)((sd - so) * t);
            ph = ph + 0.03 * (float)((sd - so) * h);
            pu = pu + 0.03 * (float)((sd - so) * umbral);
            datos += " \nPeso de entrada domesticable corregido: " + FTS(pd);
            datos += " \nPeso de entrada Tamano de animales que caza corregido: " + FTS(pa);
            datos += " \nPeso de entrada Su tamaño corregido es: " + FTS(pt);
            datos += " \nPeso de entrada Su habitad corregido es: " + FTS(ph);
            datos += " \nPeso del umbral corregido: " + FTS(pu);

            
        }

        float sumatoria = (d*pd) + (a*pa) + (t*pt) + (h*+ph) + (umbral*pu);
        datos += " \nLa sumatoria de s = x1*w1 + x2*w2 + x3*w3 + x4*w4 +umbral*w0 = " + FTS(sumatoria);

        if (sumatoria > 0) {
            suma = 1;
            datos += " \nUsando la funcion escalonada el resultado queda en: " + ITS(suma);
            datos += " \nEl animal es peligroso!!, el chico debe correr!!";
            so = (float) suma;
        }
        else if(sumatoria < 1){
            suma = 0;
            datos += " \nUsando la funcion escalonada el resultado queda en: " + ITS(suma);
            datos += " \nEl animal no es peligroso, el chico pude estar tranquilo";
            so = (float) suma;
        }

        //si la epica ha cambiado!
        if (epoca > 0) {
            //verificamos el cambio respecto a epocas anteriores
            if (estado != suma) {
                datos += " \nEl estado ha cambiado respecto a estados anteriores!!\nEl estado ha pasado de " + ITS(estado) + " a " + ITS(suma);
            }
            else {
                datos += " \nEl estado se mantiene respecto a estados anteriores!!";
            }
        }


        mostrar(datos);
        dat += "\n" + datos ;

        datos = "";

        epoca++;
        estado = suma;

    } while (estado!=sd);
    
    escribir(dat);

  
}

