# Documentación del fichero `main.cc`

Este documento describe el funcionamiento del fichero `main.cc`, el cual contiene una implementación para generar la secuencia C/A de GPS para un satélite específico.

## Descripción

El fichero `main.cc` contiene una función principal y una función auxiliar para generar la secuencia C/A de GPS.

## Funciones

### generar_CA

```cpp
std::vector<int> generar_CA(int sat_id, int longitud);
```

#### Descripción

Esta función genera la secuencia C/A de GPS para un satélite específico.

#### Parámetros

- `sat_id`: ID del satélite (1-32).
- `longitud`: Longitud de la secuencia de salida.

#### Retorno

- `std::vector<int>`: Secuencia C/A generada.

## Uso

El programa solicita al usuario el ID del satélite y la longitud de la secuencia de salida. Luego, genera y muestra la secuencia C/A correspondiente.

## Ejemplo

A continuación se muestra un ejemplo de ejecución del programa:

```
Ingrese el ID del satélite (1-32): 1
Ingrese la longitud de la secuencia de salida: 14
Secuencia C/A generada: 11001000001110
```
