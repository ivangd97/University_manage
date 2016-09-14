//============================================================================
// Name        : UI.cpp
// Author      : profesores de la asignatura EDi
// Version     : curso 14/15
// Copyright   : Your copyright notice
// Description : Implementación de la clase User Interface
//=============================================================================
#include <fstream>
#include <iostream>
#include "Universidad.h"
#include "ui.h"


using namespace std;


UI::UI() {
	ejecutar();
}

void UI::ejecutar() {
	Universidad *elZarzal = new Universidad;
	int opcion;
	int i;
	string nombre;
	string DNIBuscado;
	bool salir=false;
	do {
		opcion = menu();
		switch(opcion){
		case 1:
			cout << "Realizando la asignación de estudiantes... " << endl;
			elZarzal->cargarPilaEstudiantes();
			elZarzal->cargarTitulaciones();
			elZarzal->asignarTitulaciones();
			break;
		case 2:
			cout << "Introduzca el número de la titulación que desea consultar " << endl;
			cin>>i;
			if(i >7)
				cout << "Recuerde que sólo existen 7 titulaciones" << endl;
			else
				elZarzal->mostrarunaTitulacion(i);
			break;
		case 3:
			cout << "Introduzca el DNI del estudiante que desea consultar: " << endl;
			cin >> DNIBuscado;
			cout << "Mostrando estudiante..." << endl;
			elZarzal->buscarPorDNI(DNIBuscado);
			// Muestra un estudiante por DNI
			break;
		case 4:
			cout << "Vocando en árboles... " << endl;
			elZarzal->Matricula();
			break;
		case 5:
			cout << "Cargando el archivo de matrículas y renuncias..." << endl;
			elZarzal->cargaMatriculadosB();
			cout << "Para visualizar los archivos debe refrescarse el proyecto" << endl;
			// Realiza el proceso de matriculacion final con las matriculas y renuncias
			break;
		case 6:
			//Muestra la titulacion que le entre por parámetro escrito en teclado
			cout << "¿Qué titulación quiere mirar?..." << endl;
			cin>> i;
			if(i >= 8)
				cout << "Recuerde que sólo existen 7 titulaciones." << endl;
			else{
				cout << "Mostrando titulación... " << endl;
				elZarzal->mostrarTitulacionArbol(i);
			}
			break;
		case 7:
			// Búsqueda por apellido
			cout << "Introduzca la raiz del nombre que desea buscar: " << endl;
			cout << "(Recuerde que debe introducirlo en mayúsculas)" << endl;
			cin>>nombre;
			cout << "Ahora introduzca el número de la titulación" << endl;
			cin>>i;
			cout << "Mostrando el apellido..." << endl;
			elZarzal->mostrararbolraiz(nombre,i);
			break;
		case 8:
			// Muestra la nota de corte de todas las titulaciones
			cout << "Nota de corte de las titulaciones..." << endl;
			elZarzal->mostrarNotaCorteTit();
			break;
		case 9:
			cout<<"Hasta Pronto! :D"<<endl;
			salir = true;

			break;
		default:
			cout << "ERROR en la opcion de menu" << endl;
			break;
		}
	} while (!salir);
}


int UI::menu(){
	int opcion;
	string seleccionado;
	do {
		cout << "\n________________ MENU PRINCIPAL ________________\n" << endl;
		cout << "   1. Asignación de estudiantes                  " << endl;
		cout << "   2. Consulta de una titulación                 " << endl;
		cout << "   3. Consulta de un estudiante                  " << endl;
		cout << "   4. Matrícula                                  " << endl;
		cout << "   5. Proceso de Matrícula                       " << endl;
		cout << "   6  Consultar titulación                       " << endl;
		cout << "   7. Consulta por                               " << endl;
		cout << "   8. Nota de corte                              " << endl;
		cout << "   9. Finalizar                                  " << endl;

		cout << "Opcion:  ";
		cin>>opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 9));

	return opcion;
}

UI::~UI() {
}

int main () {
	cout << "\n------------------------------------------------------------------\n";
	cout << "-------->>   Bienvenidos a la aplicación Universidad  <<--------"<<endl;
	cout << "------------------------------------------------------------------\n";
	UI ui;
	cout << "\n** Fin de la aplicación."<<endl;
}


