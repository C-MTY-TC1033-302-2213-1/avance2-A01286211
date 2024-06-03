/*
Nombre: Sebastian Zaragoza Diaz
Matricula: A01286211
Carrera: IDM
Fecha: 20/05/2024
*/

#include "Pelicula.h"

// Metodo Constructor, Default y con Parametros
Pelicula::Pelicula() : Video(){
    oscares = 100;
}
Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares)
        : Video(_iD, _titulo, _duracion, _genero, _calificacion)  {
            oscares = _oscares;
}

// Metodo Modificador
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
}

// Metodo de Acceso
int Pelicula::getOscares(){
    return oscares;
}
    
// Otros Metodos
string Pelicula::str(){
    // Tenemos acceso directo a los atributos de la clase padre, porque son protected.
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacion) + ' ' + to_string(oscares);
}