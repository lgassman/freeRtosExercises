# Ejercicios de freeRTOS
## FI-UBA
### Especialización en sistemas embebidos

Los ejercicios están diseñados para ser ejecutados en una EDU-CIAA,
para lo cual se debe descargar el firmware de la CIAA de 

`http://github.com/epernia/cese-edu-ciaa-template/`

```
  git clone http://github.com/epernia/cese-edu-ciaa-template/
```

Luego generar la carpeta 
`cese-edu-ciaa-template/_programs` (En realidad puede ser cualquier subcarpeta, pero _programs ya está configurada en el .gitignore
para que no conflictúe los cambios realizados en el programa con el git del firmware de la CIAA.

```
   cd cese-edu-ciaa-template/
   mkdir _programs
```

clonar este repositorio dentro de `cese-edu-ciaa-template/_programs`

```
   cd _programs
   git clone git@github.com:lgassman/freeRtosExercises.git
```

Luego de debe seleccionar el ejercicio que se quiere ejecutar en la 
Edu-CIAA editando el archivo `cese-edu-ciaa-template/program.mk`
En PROGRAM_PATH debe ir ` _programs/rtosExamples` mientras que en PROGRAM_NAME debe ir el nombre del ejericicio que se quiere ejecutar, por ejemplo `ejercicio1`


```
PROGRAM_PATH = _programs/rtosExamples
PROGRAM_NAME = ejercicio1

```

Finalmente, Para ejecutar el programa, luego de conectar la Edu-CIAA a la computadora a través del usb DEBUG

```
   make download
```

#Ejercicio 1.

program.mk
``` Makefile
PROGRAM_PATH = _programs/rtosExamples
PROGRAM_NAME = ejercicio1
```

Se utilizó como base el template que ya viene con el firmware de la Edu-CIAA para utilizar freeRTOS de manera dinámica.

Se cambio el uso de parámetros de la tarea para que el LED pueda ser configurado. Se quitó algunas líneas innecesarias del inicio y se renombró los achivos.

#Ejercicio 2.

program.mk
``` Makefile
PROGRAM_PATH = _programs/rtosExamples
PROGRAM_NAME = ejercicio2
```

Se detectó que no se lleva bien la función vTaskDelayUntil cuando el segundo parámetro es un 0. Por eso se armó una función auxiliar que actualiza la base de tiempo sin ningún delay cuando el valor es 0.




