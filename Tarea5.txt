#TAREA5 

Results_hw5.pdf: Results_hw5.tex datos.pdf
	pdflatex Results_hw5.tex 


datos.pdf: Plots.py mod.txt 
	python Plots.py

mod.txt: CurvaRotacion.x
	./CurvaRotacion.x

CurvaRotacion.x: CurvaRotacion.c
	cc CurvaRotacion.c -lm -o CurvaRotacion.x