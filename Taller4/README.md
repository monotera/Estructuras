# Pontificia Universidad Javeriana Departamento de Ingenier ́ıa de Sistemas Estructuras de Datos Taller 4: Rutas de costo m ́ınimo en Grafos, 2020-

## 1 Objetivo

Utilizar la implementaci ́on de grafos vista en clase para modelar un problema. En particular, se desea evaluar las habili-
dades del estudiante en el uso de diferentes algoritmos que permitan responder preguntas particulares de la informaci ́on
estructurada.

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

## 3 Descripci ́on del problema

En la planeaci ́on para la construcci ́on de un nuevo condominio residencial, una empresa de arquitectos utiliza una
herramienta muy sencilla: un plano cartesiano. Inicialmente, las casas a construir se ubican dentro del plano cartesiano
con puntos (x,y), y una vez est ́an todas ubicadas, se conectan con algunos caminos que van a permitir la movilidad de
los residentes dentro del condominio. Para cada camino se almacena su longitud, la cual se calcula sobre el plano como
la distancia entre los dos puntos cartesianos que conecta. Dentro de la planeaci ́on, se incluye la porter ́ıa como la primera
“casa” del condominio. La Figura 1 representa un ejemplo de como se ver ́ıa un plano cartesiano con un conjunto de
casas ubicadas y conectadas por medio de algunos caminos, en este ejemplo el v ́ertice A1 representa la porter ́ıa o punto
de entrada al condominio.
La informaci ́on utilizada por los arquitectos para la planeaci ́on se almacena en un archivo de texto con la siguiente
estructura:

```
N
X(0) Y(0)
X(1) Y(1)
...
X(N-1) Y(N-1)
E
A(0) B(0)
A(1) B(1)
...
A(E-1) B(E-1)
```

```
Figure 1: Ejemplo que muestra la ubicaci ́on de las casas y los caminos que las conectan.
```
Donde:

- Nes un n ́umero entero positivo que representa la cantidad de casas a ubicar en el plano.
- X(i) Y(i)es la coordenada cartesiana de la i- ́esima casa. Cada valor de la coordenada es real.
- Ees un n ́umero entero positivo que representa la cantidad de caminos que conectan las casas en el plano.
- A(j) B(j)son los ́ındices de las casas que definen (est ́an conectadas por) el j- ́esimo camino. Cada valor de esta
    tupla es un n ́umero entero que representa un ́ındice de una casa en el plano.

Entre las revisiones que deben realizar los arquitectos al momento de la planeaci ́on del condominio, una de las m ́as
importantes es verificar qu ́e tan separadas quedan las casas y qu ́e tan largos podr ́ıa llegar a ser los caminos entre ellas,
como para tener una idea del tiempo que le tomar ́ıa a los residentes recorrer todo el condominio a partir de la porter ́ıa.
Para esto, requieren de un sistema que, sobre la informaci ́on contenida en los archivos de texto, y asumiendo que la
primera casa en el archivo representa la ubicaci ́on de la porter ́ıa, calcule las distancias lineales entre la porter ́ıa y las casas
(en t ́erminos de su distancia euclidiana), y luego las compare con las distancias de los caminos que las conectan. De esta
forma, el sistema debe generar un informe donde se indique, para cada casa en el condominio, la ruta m ́as corta que la
conecta a la porter ́ıa a trav ́es de los caminos, la distancia total a recorrer, y la distancia lineal que existe entre la casa y
la porter ́ıa.

## 4 Descripci ́on de la implementaci ́on

Para resolver el problema de las rutas m ́as cortas entre las casas y la porter ́ıa del condominio, se propone una imple-
mentaci ́on contenida en el archivo fuente‘‘taller 4 grafos.cxx’’. El programa recibe como par ́ametro (por la l ́ınea
de comandos) el nombre del archivo que contiene la informaci ́on del condominio: la ubicaci ́on de las casas y la definci ́on
de los caminos entre ellas. Para identificar las rutas de menor costo, el programa compara los resultados obtenidos con 2
algoritmos diferentes: Prim y Dijkstra. Al ejecutarse, el programa muestra en pantalla las casas con sus coordenadas, la
distancia lineal entre cada una y la porter ́ıa, y para cada algoritmo, la secuencia de caminos interconectados que generan
la ruta de menor costo junto con la sumatoria del costo total de la ruta.

## 5 Desarrollo del taller

El taller consistir ́a en implementar (o integrar) el c ́odigo necesario para que el archivo fuente‘‘taller 4 grafos.cxx’’
sirva para crear un programa que imprima por pantalla el informe con los datos relacionados a las rutas de menor costo
entre las casas y la porter ́ıa del condominio.
Para completar el taller, realice las siguientes actividades:

1. Estudie el archivo de c ́odigo fuente entregado. Aseg ́urese de entender completamente los procesos all ́ı descritos.
    Si encuentra alguna porci ́on de c ́odigo que no entienda, pregunte al profesor o al monitor de la clase.


2. Reemplace las secciones de c ́odigo marcadas como‘‘TODO’’con las porciones de c ́odigo adecuadas para el correcto
    funcionamiento del programa que se pide.

## 6 Evaluaci ́on

Como parte del desarrollo del taller, se debe entregar el c ́odigo fuente modificado y funcional (que compile y ejecute
correctamente). Al c ́odigo fuente modificado del programa, debe adjuntarse la implementaci ́on propia del TAD Grafo,
para garantizar su correcta ejecuci ́on.
La entrega se har ́a a trav ́es de la correspondiente actividad de UVirtual antes del mi ́ercoles 20 de mayo a las 9a.m.
Se debe entregar un ́unico archivo comprimido( ́unicos formatos aceptados: .zip, .tar, .tar.gz, .tar.bz2, .tgz)que
contenga dentro de un mismo directorio(sin estructura de carpetas interna)todo el c ́odigo fuente( ́unicos formatos
aceptados: .h, .hxx, .hpp, .c, .cxx, .cpp). Si la entrega contiene archivos en cualquier otro formato, ser ́a descartada
y no ser ́a evaluada, es decir, la nota definitiva de la entrega ser ́a de 0 (cero) sobre 5 (cinco).
La evaluaci ́on del taller tendr ́a la siguiente escala para cada secci ́on de c ́odigo a completar:

- Excelente(5.0/5.0): El c ́odigo compila, ejecuta y genera resultados correctos para los dos algoritmos (Prim y
    Dijkstra).
- Bueno(3.0/5.0): El c ́odigo compila, ejecuta y genera resultados correctos s ́olo para uno de los algoritmos (Prim
    o Dijkstra).
- No fue un trabajo formal de ingenier ́ıa(2.5/5.0): El c ́odigo compila y ejecuta, pero no genera resultados
    correctos.
- Necesita mejoras sustanciales(2.0/5.0): El c ́odigo compila, pero genera errores de ejecuci ́on (violaciones de
    segmento, por ejemplo), o no puede ejecutarse adecuadamente.
- Malo(1.0/5.0) : El c ́odigo entregado por el estudiante no compila en el compilador g++ (m ́ınimo versi ́on n ́umero
    4.5).
- No entreg ́o(0.0/5.0).


