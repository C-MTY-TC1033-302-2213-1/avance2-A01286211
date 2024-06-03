/*
Nombre: Sebastian Zaragoza Diaz
Matricula: A01286211
Carrera: IDM
Fecha: 20/05/2024
*/

#include "Serie.h"

//Metodo Constructor
Serie::Serie() : Video(){
    // Solo vamos a inicializar cantidad
    cantidad = 0;
}

Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion) 
      : Video(_iD, _titulo, _duracion, _genero, _calificacion) {
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}
void Serie::calculaDuracion(){
    int acum = 0;
    //Primero revisar que la serie tenga episodios
    // Una vez que se verifica la existencia, se corre ciclo que recoja valor
    // de temporada uno por uno y lo sume a un acumulador
    if ( cantidad > 0 ){
        for (int index = 0; index < cantidad; index++){
            acum += episodios[index].getTemporada();
        }
    }
    else{
        acum = 0;
    }
    duracion = acum;
}

//Metodos Modificadores
void Serie::setEpisodio(int posicion, Episodio episodio){
    // Primero Validar que exista ese episodio

    if ( posicion >= 0 && posicion < cantidad ){
        episodios[posicion] = episodio;
    }else{
        cout << "NO se modifico el episodio" << endl;
    }
    

} 
void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}

//Metodos de Acceso
Episodio Serie::getEpisodio(int posicion){
    // Crea objeto tipo episodio y lo inicializa con el Constructor Default
    Episodio epi;
    // Primero Validar que exista ese episodio
    if ( posicion >= 0 && posicion < cantidad ){
        return episodios[posicion];
    }

    //Si no existe se retorna un default
    return epi;
}
int Serie::getCantidad(){
    return cantidad;
}

//Otros Metodos
double Serie::calculaPromedio(){
    double acum = 0;

    for( int index = 0 ; index < cantidad ; index++){
        acum += episodios[index].getCalificacion();
    }
    // Validar que tenga episodios

    if( cantidad > 0 ){
        return acum/cantidad;
    }else{
        return 0;
    }
}
string Serie::str(){
    /* Primero se verifica la existencia de Episodios, en caso de que exista, 
    se despliegan los episodios uno por uno, con su respectivo método string.*/
    string acum="";
    if(cantidad > 0){
        acum += Video::str() + ' ' + to_string(cantidad) + '\n';
        for(int index = 0 ; index < cantidad ; index++){
            acum += episodios[index].str() + '\n';
        }
    }else{
        acum +=  Video::str() + ' ' + to_string(cantidad) + '\n';
    }

    return acum;
}
void Serie::agregaEpisodio(Episodio *episodio){
    if(cantidad < 5){
        episodios[cantidad++] = *episodio; 
    }else{
        cout << "NO se agrego ningun episodio" << endl;
    }
}