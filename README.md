# Wordle
## ¿Cómo funciona?
**Esté código funciona mediante bases de datos donde tienen todas las posibles palabras con su respectiva frecuencia. Se tienen 6 intentos de palabras donde el tamaño de cada una tiene que ser de 5 letras, ni una más, ni una menos.**

Por cada intento cada letra aparecerá con 1 de 3 colores: verde, amarillo y gris, significando el color verde que la letra se encuentra en esa posición, el amarillo que la letra se encuentra en la palabra pero está en una posición diferente a la ingresada, mientras que el color gris significa que la letra puesta directamente no se encuentra en la palabra.

El código consta de 4 partes importantes de código, el `apartado jugador.c`, el `apartado jugable.c`, el `mainED.c` y el `mainED2.c`.

1. **El primer apartado se encarga de buscar la palabra con mayor frecuencia y filtrar las palabras corrompiendo si las letras de la palabra ingresada por un jugador están en la posición correcta o incorrecta y ponerle el color correspondiente y eliminar la palabra que no es la correcta para que en caso de volver a ponerse no perder un intento.**

2. **El segundo apartado se encarga de solicitarle al jugador una palabra y quitarle un intento si no se adivina en ese intento, imprimiendo la palabra con el color correspondiente en cada letra.**

**Mientras que la funcionalidad de los últimos puntos es la de cargar la base de datos donde se encuentran las palabras y elegir la palabra secreta a adivinar, y la de mostrar las letras que se fueron usando con su color respectivo (gris, amarillo o verde).**


## ¿Cómo se ejcuta?
𝘗𝘢𝘳𝘢 𝘦𝘫𝘦𝘤𝘶𝘵𝘢𝘳 𝘦𝘭 𝘤ó𝘥𝘪𝘨𝘰 𝘦𝘴 𝘯𝘦𝘤𝘦𝘴𝘢𝘳𝘪𝘰 𝘲𝘶𝘦 𝘦𝘭 𝘢𝘳𝘤𝘩𝘪𝘷𝘰 𝘫𝘶𝘨𝘢𝘣𝘭𝘦.𝘤 𝘵𝘦𝘯𝘨𝘢 𝘭𝘰𝘴 𝘢𝘳𝘤𝘩𝘪𝘷𝘰𝘴 𝘦𝘥.𝘤 𝘺 𝘫𝘶𝘨𝘢𝘥𝘰𝘳.𝘤, 𝘦𝘭 𝘤𝘶𝘢𝘭 𝘥𝘦𝘣𝘦 𝘵𝘦𝘯𝘦𝘳 𝘭𝘰𝘴 𝘢𝘳𝘤𝘩𝘪𝘷𝘰𝘴 𝘫𝘶𝘨𝘢𝘥𝘰𝘳.𝘩 𝘺 𝘦𝘥2.𝘤, 𝘵𝘦𝘯𝘪𝘦𝘯𝘥𝘰 𝘭𝘰𝘴 𝘢𝘳𝘤𝘩𝘪𝘷𝘰𝘴 𝘦𝘥.𝘤 𝘺 𝘦𝘥2.𝘤 𝘴𝘶𝘴 𝘢𝘳𝘤𝘩𝘪𝘷𝘰𝘴 𝘮𝘢𝘪𝘯.𝘤 𝘺 𝘦𝘥.𝘩 (𝘦𝘥.𝘩 𝘦𝘯 𝘤𝘢𝘴𝘰 𝘥𝘦𝘭 𝘦𝘥.𝘤 𝘺 𝘦𝘥2.𝘩 𝘦𝘯 𝘦𝘭 𝘤𝘢𝘴𝘰 𝘥𝘦𝘭 𝘦𝘥2.𝘤).

𝘗𝘢𝘳𝘢 𝘪𝘳 𝘱𝘳𝘰𝘣𝘢𝘯𝘥𝘰 𝘭𝘢 𝘧𝘶𝘯𝘤𝘪𝘰𝘯𝘢𝘭𝘪𝘥𝘢𝘥 𝘥𝘦 𝘢𝘭𝘨ú𝘯 𝘢𝘱𝘢𝘳𝘵𝘢𝘥𝘰 𝘦𝘯 𝘦𝘴𝘱𝘦𝘤í𝘧𝘪𝘤𝘰, 𝘫𝘶𝘨𝘢𝘥𝘰𝘳.𝘤 𝘱𝘰𝘳 𝘦𝘫𝘦𝘮𝘱𝘭𝘰, 𝘩𝘢𝘺 𝘲𝘶𝘦 𝘶𝘵𝘪𝘭𝘪𝘻𝘢𝘳 𝘦𝘭 𝘤𝘰𝘮𝘢𝘯𝘥𝘰 "𝘨𝘤𝘤 𝘫𝘶𝘨𝘢𝘥𝘰𝘳.𝘤 𝘦𝘥2.𝘤 𝘮𝘢𝘪𝘯𝘌𝘥2.𝘤" 𝘱𝘢𝘳𝘢 𝘭𝘶𝘦𝘨𝘰 𝘩𝘢𝘤𝘦𝘳 𝘶𝘴𝘰 𝘥𝘦𝘭 𝘤𝘰𝘮𝘢𝘯𝘥𝘰 "./𝘢.𝘰𝘶𝘵"
