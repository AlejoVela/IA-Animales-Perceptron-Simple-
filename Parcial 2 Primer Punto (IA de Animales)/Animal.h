#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

class Animal
{
	private:
		string nom; //nombre animal
		int domes;  //domesticable, si = 0, no = 1
		int alimen; //alimentacion, animales pequeños = 0, grandes = 1
		int tama;   //tamaño, pequeño = 0, grande = 1
		int habitad;// Urbano = 0, salvaje = 1
	public:
		Animal(string,int, int, int, int); //constructor
		string getNom();
		int getDomes();
		int getAlimen();
		int getTama();
		int getHabitad();
		void setNom(string);
		void setDomes(int);
		void setAlimen(int);
		void setTama(int);
		void setHabitad(int);
};


//constructor
Animal::Animal(string n, int d, int a, int t, int h) {
	nom = n;
	domes = d;
	alimen = a;
	tama = t;
	habitad = h;
}

//GETTERS

string Animal::getNom() {
	return nom;
}

int Animal::getDomes() {
	return domes;
}

int Animal::getAlimen() {
	return alimen;
}

int Animal::getTama() {
	return tama;
}

int Animal::getHabitad() {
	return habitad;
}

//SETTERS

void Animal::setNom(string n) {
	nom = n;
}

void Animal::setDomes(int d) {
	domes = d;
}

void Animal::setAlimen(int a) {
	alimen = a;
}

void Animal::setTama(int t) {
	tama = t;
}

void Animal::setHabitad(int h) {
	habitad = h;
}

#endif