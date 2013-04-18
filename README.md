Fractals
========

Computes matrices of fractals using multiple processes.

== Platforma: Ubuntu 12.04 LTS ==


Fiecare proces prelucreaza nr_linii/numar_procese * numar_coloane elemente.
Sincronizarea proceselor se face cu send si recieve.
Fiecarui proces ii trimit o structura de tip parameters in care se afla parametrii matricii 
care urmeaza sa fie prelucrata:

  tipul multimii, Mandelbrot sau Julia, 
	x_min, x_max, y_min, y_max
	rezolutia
	numarul de iteratii
	parametrul complex pt calcului multimilor Julia
	dimensiunile matricii
	numarul de linii in matricea initiala (se foloseste la calcului dimensiunii unei partitii)

Procesele trimit rezultatul procesului master ca acesta sa faca un recieve la adresa corespunzatoare in matricea finala.
