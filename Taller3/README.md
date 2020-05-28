# Pontificia Universidad Javeriana Departamento de Ingenieria de Sistemas Estructuras de Datos Taller 3: Arboles Binarios Ordenados, 2020-10 ́

## 1 Objetivo

Evaluar la eficiencia de los ́arboles binarios ordenados en operaciones de b ́usqueda de elementos. En especial, se desea
evaluar las habilidades del estudiante en el uso y an ́alisis de las operaciones de b ́usqueda, inserci ́on y eliminaci ́on de datos
en ́arboles AVL, ́arboles rojinegros (RN) y mont ́ıculos.

## 2 Recordatorio: compilaci ́on con g++

La compilaci ́on con g++ (compilador est ́andar que ser ́a usado en este curso para evaluar y calificar las entregas) se
realiza con los siguientes pasos:

```
1.Compilaci ́on: de todo el c ́odigo fuente compilable (UNICAMENTE LOS ARCHIVOS CON EXTENSIONES ́
*.c,*.cpp,*.cxx)
g++ -std=c++11 -c *.c *.cxx *.cpp
```
```
2.Encadenamiento: de todo el c ́odigo de bajo nivel en el archivo ejecutable
g++ -std=c++11 -o nombredemiprograma *.o
```
```
Nota: Estos dos pasos (compilaci ́on y encadenamiento) pueden abreviarse en un s ́olo comando:
g++ -std=c++11 -o nombredemiprograma *.c *.cxx *.cpp
```
```
3.Ejecuci ́on: del programa ejecutable anteriormente generado
./nombredemiprograma
```
ATENCION ́ : Los archivos de encabezados (*.h, *.hpp, *.hxx)NOSE COMPILAN, se incluyen en otros archivos
(encabezados o c ́odigo). As ́ı mismo, los archivos de c ́odigo fuente (*.c, *.cpp, *.cxx)NOSEINCLUYEN, se compilan.
Si el programa entregado como respuesta a este Taller no atiende estas recomendaciones, autom ́aticamente se calificar ́a
la entrega sobre un25%menos de la calificaci ́on m ́axima.

## 2.1 Medici ́on del tiempo de ejecuci ́on

Para la medici ́on de tiempos de ejecuci ́on en C++, se provee la funci ́onclock(librer ́ıactime), la cual retorna el tiempo
de procesador utilizado por el programa. Para calcular el tiempo actual utilizado por un programa, el valor retornado por
la funci ́on debe compararse con el valor retornado por un llamado previo a la misma funci ́on. A continuaci ́on se presenta
un ejemplo de uso (adaptado dehttp://www.cplusplus.com/reference/ctime/clock/):

```
#include<ctime>
#include<math>
#include<iostream>
```
```
int main (){
std::clockt inittime = std::clock( );
int freq = 99998;
```
```
for ( int i=2; i<=n; ++i )
for ( int j=sqrt(i); j>1; --j )
if ( i%j==0 ){
--freq;
break;
}
```
```
std::clockt endtime = std::clock( );
```

```
cout<< ‘‘The number of primes lower than 100000 is: ’’<< freq<< ‘‘\n’’;
double calctime = ( endtime - inittime ) / double( CLOCKSPERSEC );
cout<< ‘‘It took me ’’ <<calctime<< ‘‘ seconds.\n’’;
return 0;
}
```
# 3 Desarrollo del taller

Una empresa manufacturera almacena la informaci ́on de sus productos utilizando como ́ındice un c ́odigo num ́erico
(identificaci ́on) de 6 d ́ıgitos (0-9). La empresa busca una estrategia de almacenamiento de esta informaci ́on para que la
b ́usqueda de un producto particular o la extracci ́on de grupos de productos de acuerdo a rangos de c ́odigos sea f ́acil y
eficiente.
El objetivo del taller consistir ́a en utilizar y comparar tres implementaciones diferentes de ́arboles binarios ordena-
dos para organizar los c ́odigos de identificaci ́on de los productos: implementaci ́on propia del ́arbol AVL, la estructura
std::set<T>de la STL (implementada internamente como un ́arbol rojinegro (RN)) y la estructura mont ́ıculo (im-
plementada con los algoritmos de la STL). Por simplicidad, se asumir ́a que s ́olo se dispone del c ́odigo num ́erico de los
productos como informaci ́on asociada.
La informaci ́on necesaria para poblar los ́arboles con los c ́odigos de los productos se encuentra en un archivo de
texto, donde l ́ınea por l ́ınea se indica la operaci ́on a realizar. S ́olo dos operaciones son posibles:A: agregar el n ́umero de
identificaci ́on del producto dado yE: eliminar el mayor n ́umero de identificaci ́on de producto disponible en la estructura
(n ́otese que no es posible eliminar un n ́umero de identificaci ́on dado). Por ejemplo, el siguiente archivo:

```
A 243535
A 546384
E
```
Agregar ́ıa al ́arbol dos nuevos productos con c ́odigos 243535 y 546384, para luego eliminar del ́arbol el producto iden-
tificado con c ́odigo 546384. En el archivo, se garantiza que todos los c ́odigos tienen longitud de 6 d ́ıgitos, por lo que
pueden existir c ́odigos con ceros a la izquierda.
El desarrollo del taller consistir ́a en dise ̃nar (utilizando la plantilla de dise ̃no de TADs vista en clase) e implementar
un programa que permita almacenar ordenadamente los c ́odigos de productos de un archivo de texto, utilizando un ́arbol
AVL, uno rojinegro (RN) y un mont ́ıculo. En particular, el programa debe:

- Leer adecuadamente desde el archivo de texto la informaci ́on de los c ́odigos de productos y de las operaciones a
    aplicar (adici ́on y eliminaci ́on).
- Utilizar la implementaci ́on propia del ́arbol AVL, la estructurastd::set<T>de la STL ( ́arbol RN) y la estructura
    mont ́ıculo (con algoritmos de la STL) para cargar la informaci ́on de los c ́odigos en las tres diferentes estructuras.
    Adem ́as de que la informaci ́on quede adecuadamente distribu ́ıda y organizada dentro de cada una, es de especial
    importancia realizar la medici ́on del tiempo de ejecuci ́on del proceso de carga de la informaci ́on en cada estructura.
- Implementar una funci ́on que permita extraer el recorrido en inorden del ́arbol AVL en una lista (std::list<T>). El
    resultado de esta funci ́on permitir ́a verificar si, luego del proceso de carga, el ́arbol AVL, la estructurastd::set<T>
    de la STL ( ́arbol RN) y la estructura mont ́ıculo almacenan exactamente la misma informaci ́on.
- Utilizar las mediciones de tiempo y la comparaci ́on de los datos almacenados en los tres ́arboles, ejecutados sobre
    los diferentes archivos de ejemplo, para redactar un p ́arrafo (dentro del archivo de dise ̃no) en el cual describa cu ́al
    estructura es la m ́as adecuada para este problema.

Como entrada, el programa debe recibir por l ́ınea de comandos el nombre del archivo que contiene la informaci ́on necesaria.
Esto quiere decir que, una vez compilado el programa, debe ejecutarse por la l ́ınea de comandos de la siguiente forma:

```
./nombredemiprograma archivoentrada.txt
```
## 4 Evaluaci ́on

La entrega se har ́a a trav ́es de la correspondiente actividad de UVirtual, antes de las 11:00am del mi ́ercoles 15 de abril.
Se debe entregar un ́unico archivo comprimido ( ́unicos formatos aceptados: .zip, .tar, .tar.gz, .tar.bz2, .tgz) que contenga
dentro de un mismo directorio (sin estructura de carpetas interna) el documento de dise ̃no (.pdf) y el c ́odigo fuente (.h,


.hxx, .hpp, .c, .cxx, .cpp). Si la entrega contiene archivos en cualquier otro formato, ser ́a descartada y no ser ́a evaluada,
es decir, la nota definitiva de la entrega ser ́a de 0 (cero) sobre 5 (cinco).
La evaluaci ́on del taller tendr ́a la siguiente escala:

- Excelente(5.0/5.0): El estudiante dise ̃n ́o correctamente (siguiendo la plantilla) e implement ́o una soluci ́on que
    utiliza correctamente el ́arbol AVL, la estructurastd::set<T>de la STL ( ́arbol RN) y la estructura mont ́ıculo
    (con algoritmos de la STL) para almacenar ordenadamente los datos, y adem ́as realiza la comparaci ́on entre las
    estructuras en base a datos y hechos recopilados.
- Bueno(3.9/5.0): El estudiante dise ̃n ́o correctamente (siguiendo la plantilla) e implement ́o una soluci ́on que utiliza
    correctamente dos de las estructuras ( ́arbol AVL, ́arbol RN ́o mont ́ıculo) para almacenar ordenadamente los datos.
- Aceptable(3.2/5.0): El estudiante dise ̃n ́o correctamente (siguiendo la plantilla) e implement ́o una soluci ́on que
    utiliza correctamente s ́olo una de las estructuras ( ́arbol AVL, ́arbol RN ́o mont ́ıculo) para almacenar ordenadamente
    los datos.
- No fue un trabajo formal de ingenier ́ıa(2.7/5.0): El estudiante implement ́o una soluci ́on completa o parcial,
    pero no la dise ̃n ́o correcta o completamente.
- Necesita mejoras sustanciales(2.0/5.0): El estudiante dise ̃n ́o y/o implement ́o una soluci ́on, pero no es completa
    o no soluciona lo pedido.
- Malo(1.0/5.0): El c ́odigo entregado por el estudiante no compila en el compilador g++ (m ́ınimo versi ́on n ́umero
    4.5).
- No entreg ́o(0.0/5.0).


