/*
Nombre: Sebastián Zaragoza Díaz
Matricula: A01286211
Carrera: IDM
Fecha: 02/06/24
- ¿Qué aprendí en el desarrollo de la clase Polimorfismo?
    En el desarrollo de la clase Polimorfismo, puse en práctica muchos conceptos revisados en clase. En
    primer lugar se puso en práctica conocimiento básico de lenguaje, con condicionales, y ciclos, además,
    se utilizo el conocimiento de arreglos básicos, y como recorrer los arreglos con ciclos y su index. En
    segundo lugar puse en práctica los nuevos conceptos aprendidos sobre arreglos de apuntadores, y cómo
    estos facilitan la realizacion de organizacion de bases de datos. Por último, aprendi el uso de la
    función typeid, y como esta me permite relacionar un objeto de un arreglo con un tipo de clase hecha
    previamente en el proyecto.
*/

#include "Polimorfismo.h"

using namespace std;

//Metodo Constructor
Polimorfismo::Polimorfismo(){
    for (int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }

    // Inicializar cantidad de videos
    cantidad = 0;
}

// Metodos Modificadores
void Polimorfismo::setPtrVideo(int index, Video *video){
    // Validar index - >= 0 y < cantidad
    if(index >= 0 && index < cantidad){
        // Modificar el apuntador
        arrPtrVideos[index] = video;
    }
}
void Polimorfismo::setCantidad(int _cantidad){
    // Cambia valor de atributo cantidad
    // Cantidad debe ser entre 0 y MAX_VIDEOS -1, de lo contrario NO se modifica el valor de la cantidad
    if(_cantidad >= 0 && _cantidad < MAX_VIDEOS){
        cantidad = _cantidad;
    }
}

// Métodos de Acceso
Video* Polimorfismo::getPtrVideo(int index){
    if (index > 0 && index < cantidad){
        return arrPtrVideos[index];
    } 
    
    // Si no existe, un return de nullptr
        return nullptr;

}
int Polimorfismo::getCantidad(){
        return cantidad;
}


// Otros Metodos
void Polimorfismo::reporteInventario(){
    // Declaracion de contadores
    int contPeliculas, contSeries;

    //inicializar
    contPeliculas = 0;
    contSeries = 0;

    // Recorrer todo el arreglo de ptr utilizando un for
    for (int index = 0; index < cantidad; index++){

        cout << arrPtrVideos[index]->str() << endl;
        // Indireccion (ptr) genera el objeto
        if(typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            contPeliculas++;
        }
        else if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            contSeries++;
        }    

    } 

    // Fuera del for, desplegamos los totales de cada uno
    cout << "Peliculas = " << contPeliculas << endl;
    cout << "Series = " << contSeries << endl;

}

void Polimorfismo::reporteCalificacion(double _calificacion){
// Contador Total
    int total;

// Inicializar el contador
    total = 0;

    for(int index = 0; index < cantidad; index++){
        if(arrPtrVideos[index]->getCalificacion() == _calificacion){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }

    // Desplegar el total fuera del for.
    cout << "Total = " << total << endl;
}
void Polimorfismo::reporteGenero(string _genero){
    // Inicializar con valor de 0 el contador de episoios con ese genero
    int total = 0;

    // Recorre todo el arreglo de peliculas y series, si el genero de el episodio en esa iteracion es
    // el mismo que el ingresado, entonces se despliega y se agrega uno al contador
    for (int index = 0; index < cantidad; index++){  
        if(arrPtrVideos[index]->getGenero() == _genero){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    } 

    // Desplegar el total fuera del for.
    cout << "Total = " << total << endl;
}
void Polimorfismo::reportePeliculas(){
    // Inicializar contador de peliculas en el arreglo con 0
    int total = 0;

    // Recorrer todo el arreglo de Videos, si el typeId de el episodio es el de pelicula,
    // se despliega y se suma al contador.
    for (int index = 0; index < cantidad; index++){  
        if( typeid(*arrPtrVideos[index]) == typeid(Pelicula) ){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    } 
    
    // Fuera del for, se despliega el Total de Peliculas.
    // Si el total sigue siendo 0, se despliega No peliculas
    if(total > 0){
        cout << "Total Peliculas = " << total << endl;
    }else{
        cout << "No peliculas" << endl;
    }

}
void Polimorfismo::reporteSeries(){
    // Inicializar contador de series en el arreglo con 0
    int total = 0;

    // Recorrer todo el arreglo de Videos, si el typeId de el episodio es el de series,
    // se despliega y se suma al contador.
    for (int index = 0; index < cantidad; index++){  
        if( typeid(*arrPtrVideos[index]) == typeid(Serie) ){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    } 
    
    // Fuera del for, se despliega el Total de Series.
    // Si el total sigue siendo 0, se despliega No series
    if(total > 0){
        cout << "Total Series = " << total << endl;
    }else{
        cout << "No series" << endl;
    }

}

//Otros Metodos
void Polimorfismo::leerArchivo(string nombre){
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7];              // row - arreglo de 7 elementos de strings, para almacenar los datos de la línea del archivo ya separados
    string line, word;          // line - almacena la línea leída, y word da la palabra que se saca de line
    int cantidadPeliculas = 0;  // Contadores de peliculas y series, inicialmente son 0.
    int cantidadSeries = 0;
    cantidad = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in);      //Abrir archivo de entrada.

    while ( getline(entrada, line) ) {  // lee una línea del archivo y la almacena en line
        stringstream s(line);           // usado para separar las palabras  split()
        iR = 0;                         // Cada vez que inicia una nueva línea inicializar iR = 0

        // Ciclo que extrae caracteres de s y los almacena en word hasta que encuentra el delimitador ','
        while ( getline(s, word, ',') ) {
            row[iR++] = word;           // añade word al arreglo row, e incrementa iR p/la proxima palabra
        }

        // Determinar si la línea es P-Pelicula, S-Serie, E-Episodio
        if (row[0] == "P") {
            // se crea un apuntador usando el operador new y el constructor con parámetros y se guarda en el arrPtrPeliculas
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            // cout << "Pelicula" << arrPtrPeliculas[cantidadPeliculas]->str() << endl;
            cantidadPeliculas++; // inc la cantidad de peliculas
        }
        else if (row[0] == "S") {
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            // cout << "Serie" << arrSeries[cantidadSeries]->str() << endl;
            cantidadSeries++;
        }

        else if (row[0] == "E") {
            // Calcular a qué Serie le pertenece el episodio?
            index = stoi(row[1]) - 500;
            // Se agrega el episodio usando el método agregaEpisodio
            // Se crea el apuntador y se convierte a objeto usando el operador de indireccion
            arrPtrSeries[index]->agregaEpisodio((new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
            // cout << "Episodio" << arrSeries[index]->str() << endl;
        }
    }

    /* fuera del ciclo
    ya se termino de leer todo el archivo ahora se guardan 
    todos los apuntadores de Pelicula y serie en el arrPtrVideo
    copiar todos los apuntadores del arreglo de Series al arreglo de
    apuntadores de Video calculando su calificacionPromedio
    ya que tiene todos los episodios.*/
    for(int index = 0; index < cantidadSeries; index++) {
        promedio = arrPtrSeries[index]->calculaPromedio(); // calcula la calificación de la Serie
        arrPtrSeries[index]->setCalificacion(promedio); // cambia la calificación de la Serie
        // añade el calcular la duración de la serie
        arrPtrSeries[index]->calculaDuracion();
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

    // copiar todos los apuntadores del arreglo de Peliculas al arreglo de apuntadores de Video
    for(int index = 0; index < cantidadPeliculas; index++) {
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

    /* Desplegar todo el contenido del arreglo de apuntadores de la clase Video (Base)
    - se da el POLIFORMISMO -- SUPER SUPER SUPER !!
    - se ejecuta el método str() que corresponde al tipo del apuntador almacenado,
    no el correspondiente al tipo del arreglo.
    */
//    for(int index = 0; index < cantidadVideos; index++) {
//       cout << index << " " << arrPtrVideos[index]->str() << endl;
//   }

    entrada.close(); // cerrar el archivo
}