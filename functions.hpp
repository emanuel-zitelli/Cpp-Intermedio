#ifndef FUNCIONES_H //si no está definido FUNCIONES_H
#define FUNCIONES_H //si la condición anterior es verdadera, se define FUNCIONES_H

#include <iostream> //basico para compilar
#include <cstdlib> //para usar system pause
#include <vector> //para trabajar con el vector dinamico
#include <fstream> //para trabajar con archivos
#include <string> //para usar getline

struct Agenda 
{
    std::string nombreApellido;
    std::string correo;
    int numero;
};

enum Action
{
    Agendar=1,
    Eliminar=2,
    Mostrar=3,
    Terminar=4,
};

short int presentacion(std::string frase)
{
    short int opcion;

    std::cout << frase;

    std::cout << "1. Agendar \n";
    std::cout << "2. Eliminar \n";
    std::cout << "3. Mostrar \n";
    std::cout << "4. Finalizar \n"; 

    std::cin >> opcion;
    std::cin.ignore(); //porque sino el enter llena el nombre, porque queda en el buffer

    return opcion;
    
}

void agendar(std::vector<Agenda>& contactos)
{   
    Agenda guardarContacto;


    std::cout << "\nIngrese el nombre y apellido del contacto: ";
    std::getline(std::cin, guardarContacto.nombreApellido);

    std::cout << "\nIngrese el email del contacto: ";
    std::cin >> guardarContacto.correo;

    std::cout << "\nIngrese el numero de telefono del contacto:";
    std::cin >> guardarContacto.numero;

    contactos.push_back(guardarContacto);
    
}

void eliminar(std::vector<Agenda>& contactos) 
{
    int i=0;
    bool encontrado=false;
    std::string nombreAEliminar;

    std::cout << "Ingrese el nombre de la persona que quiere eliminar: ";
    std::getline(std::cin, nombreAEliminar);

    //comentario end()-1 es la ultima posicion
    while(i<contactos.size() && encontrado==false)
    {
        if (contactos[i].nombreApellido == nombreAEliminar) 
        {
            
            contactos.erase(contactos.begin()+i); // `erase` devuelve la posicion que le sigue al elemento eliminado.
            //erase no toma valores, no le puedo dar i. Tengo que darle un iterador
            std::cout << "Contacto eliminado: " << nombreAEliminar << "\n";
            encontrado=true;
        } 
        else 
        {
            i++; 
        }
    }

}

void mostrar(const std::vector<Agenda>& contactos)
    {
        if(contactos.size()==0)
            std::cout << "Usted no tiene contactos agendados\n";
        else
        {
            std::cout << "\nLista de contactos:" << std::endl;
            for (int i = 0; i < contactos.size(); i++) 
            {
                std::cout 
                << "Nombre: " << contactos[i].nombreApellido << "\n"
                << "Correo: "<< contactos[i].correo << "\n"
                << "Numero: "<< contactos[i].numero << "\n";

                std::cout << "\n";
            }
        }
    
    } 

void exportarCSV(const std::vector<Agenda>& contactos) 
{
    std::ofstream archivo("contactos.csv", std::ios::app); // Modo apend

    if (archivo.is_open()) 
    {
        for (size_t i = 0; i < contactos.size(); i++) 
        {
            archivo << contactos[i].nombreApellido << ";"
                    << contactos[i].correo << ";"
                    << contactos[i].numero << "\n"; 
        }
        archivo.close(); 
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}





#endif // FUNCIONES_H