#include "functions.hpp"

int main() 
{   
    short int opcion;
    std::vector<Agenda> contactos; //vector dinamico de tipo Agenda
    
    
    opcion=presentacion("Bienvenido a su agenda personal. Que le gustaria hacer?\n");
    while(opcion!=Action::Terminar)
    {
        if(opcion==Action::Agendar)
            agendar(contactos);

        if(opcion==Action::Eliminar)
            eliminar(contactos);

        if(opcion==Action::Mostrar)
            mostrar(contactos);
        
        opcion=presentacion("Que otra operacion le gustaria hacer? \n");
        
    }

    exportarCSV(contactos);

    std::cout << "\n";
    system("pause");
    return 0;
}