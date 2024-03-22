El algoritmo Postman, también conocido como "Bucket Sort" o "Radix Sort", es un método de ordenamiento que organiza los elementos de una matriz basándose en sus dígitos individuales. Este enfoque es especialmente eficaz para ordenar números con una longitud fija de dígitos.

Para ejecutar este programa es necesario entrar a guaneExa

ssh guane

Para compilar el código secuencial se tiene que ejecutar el siguiente comando (Se hará uso de OpenMP para medir los tiempos:

srun -n 10 -w ExaDELL --pty /bin/bash
gcc -fopenmp postmansort.c -o postmansort
./postmansort

Para ejecutar el codigo paralelizado se hace uso de este comando:

sbatch postmansort.sbatch

RESULTADOS DE LOS CODIGOS.

SECUENCIAL 

![image](https://github.com/SC3UIS/-IntroPP2204122./assets/94190445/4d444809-af8f-48d0-af69-e079cb27f3b7)

PARALELIZADO.

![image](https://github.com/SC3UIS/-IntroPP2204122./assets/94190445/5ff1b912-1009-4b15-8b2f-bfa55461f191)

Conclusiones.

La implementación del algoritmo en este código ha sido optimizada para mejorar la velocidad de ejecución. Hemos utilizado Quick Sort para la ordenación de elementos y OpenMP para la paralelización, permitiendo que el proceso se realice de manera eficiente, especialmente en sistemas con múltiples núcleos de procesamiento.

Al minimizar la sobrecarga y optimizar los bucles de partición, hemos logrado un rendimiento óptimo en el ordenamiento de los elementos del arreglo.


