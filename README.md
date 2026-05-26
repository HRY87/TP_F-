# Versión 0.2

## Importante
⚠️ **NO ES UNA VERSIÓN COMPLETA**  
Todavía faltan pruebas y correcciones, pero al menos el sistema ya no se rompe.

Intenté implementar las funcionalidades mínimas **1 y 2**, ya que ambas están relacionadas entre sí.

---

# Funcionalidad 1

La base ya está hecha.  
Actualmente solo falta encontrar el lugar correcto donde actualizar `puntos_acumulados` dentro del TDA `Piloto`, que será el encargado de conservar la cantidad de puntos obtenidos durante toda la temporada.

---

# Funcionalidad 2

Todavía tengo dudas sobre si estoy encarando esta parte de la mejor manera.

Inicialmente intenté hacer una **matriz dinámica**, pero no funciono.  
Quiero consultarle al profesor especialmente sobre la estructura de la matriz de resultados.

Por el momento, la matriz será **fija**, con un límite máximo de pilotos.

En Fórmula 1 el máximo será de **20 pilotos**

Mientras exista al menos 1 piloto, habrá carrera.  
Esto se controla mediante `cant_resultados`.

Si `cant_resultados` tiene un valor entre `1` y `20`, el sistema repartirá automáticamente los puntos según la posición de llegada.

Para eso estoy utilizando el algoritmo **Fisher-Yates**.

La matriz `resultados` quedó planteada de esta forma:

```c
int resultados[20][2];

Estructura
i → posición en la carrera
j
0 → ID del piloto que ocupó esa posición
1 → puntos obtenidos por llegar a esa posición
```
Uso de TDA Vector
Decidí usar un TDA Vector porque trabajar únicamente con archivos implicaba una tortura constante de abrir y cerrar FILE*.

Además de ser incómodo, personalmente no me parecía una solución óptima.

Con el TDA vector aprovechamos que sea generico y simplificamos bastante el manejo de datos.

Nota final

Disculpen la desprolijidad del código 

Durante el desarrollo tuve varios mareos y terminé priorizando que funcionara antes que dejarlo prolijo.

Más adelante voy mejorar la organización del proyecto.
