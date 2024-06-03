#ifndef POLIMORFISMO_H
#define POLIMORFISMO_H
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <stdio.h>
#include <iostream>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
const int MAX_VIDEOS = 100;

/* 
Para identificar si un objeto es de cierta clase usaremos
la funcion typeid()
*/

class Polimorfismo{
    private:
        Video *arrPtrVideos[MAX_VIDEOS];
        int cantidad;

    public:
    //Metodo Constructor
        Polimorfismo();

    // Metodos Modificadores
        void setPtrVideo(int index, Video *video);
        void setCantidad(int _cantidad);

    // Métodos de Acceso
        Video* getPtrVideo(int index);
        int getCantidad();

    // Otros Metodos
        void leerArchivo(string nombre);
        void reporteInventario();
        void reporteCalificacion(double _calificacion);
        void reporteGenero(string _genero);
        void reportePeliculas();
        void reporteSeries();

};
#endif /* POLIMORFISMO_H */