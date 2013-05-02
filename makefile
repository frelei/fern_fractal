# Linux-ubuntu com GLUT instalado
fern_home:
	gcc fractal.c -o fractal -lGL -lglut -lGLU 
# Compilação nos laboratorios
fern_lab:
	gcc fractal.c -o fractal -L/usr/include/GL -lGL -lglut -lGLU 
