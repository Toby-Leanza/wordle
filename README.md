# Wordle - Tobías Leanza, Tomás Luján
## ¿Cómo funciona?
Esté código funciona mediante bases de datos donde tienen todas las posibles palabras con su respectiva frecuencia. Se tienen 6 intentos de palabras donde el tamaño de cada una tiene que ser de 5 letras.

Por cada intento cada letra aparecerá con 1 de 3 colores: verde, amarillo y gris, significando el color verde que la letra se encuentra en esa posición, el amarillo que la letra se encuentra en la palabra pero está en una posición diferente a la ingresada, mientras que el color gris significa que la letra puesta directamente no se encuentra en la palabra.

El código consta de 4 partes importantes de código, el apartado `jugador.c`, el apartado `jugable.c`, el `mainED.c` y el `mainED2.c`.

1. El primer apartado se encarga de buscar la palabra con mayor frecuencia y filtrar las palabras comprobando si las letras de la palabra ingresada por un jugador están en la posición correcta o incorrecta y poniendo el color correspondiente y eliminar la palabra que no sea correcta para que en caso de volver a ponerse no perder un intento.

2. El segundo apartado se encarga de solicitarle al jugador una palabra y quitarle un intento si no se adivina en ese intento, imprimiendo la palabra con el color correspondiente en cada letra.

Mientras que la funcionalidad de los últimos puntos es la de cargar la base de datos donde se encuentran las palabras y elegir la palabra secreta a adivinar, y la de mostrar las letras que se fueron usando con su color respectivo (gris, amarillo o verde).

## ¿Cómo se ejecuta?
Para poder ejecutar este archivo se le ha proporcionado un archivo makefile que le va a permitir compilar el código de forma más sencilla. Para llevar esto a cabo vamos a utilizar el comando `make` en la consola y esto compilará todo de forma instantánea. Luego para ejecutar el codigo, vamos a utilizar el siguiente comando

~~~
> ./mainEd
~~~

Esto va a permitir que se ejecute el código

## Resolución de problemas

Durante la codificación de este programa, nos topamos con diferentes problemas tal como por qué se utilizaron ciertas estructuras de datos o cómo desempatamos palabras con misma frecuencia.

- Para el problema de las estructuras de datos utilizadas, decidimos usar los viejos y confiables arreglos, ya que son EDs con las que nos hemos acostumbrado a utilizar para la mayoría de los problemas propuestos. Estos obviamente se crearon de forma dinámica

- En el caso de desempate, no fue necesario agregar un criterio ya que utilizamos un arreglo temporal que almacena las palabras con mayor frecuencia y haciendo uso la librería `<time.h>` y sus funciones respectivas, elije de forma aleatoria una de esas palabras para utilizar de palabra secreta.