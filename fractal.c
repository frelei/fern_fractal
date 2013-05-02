/*
	Identificação: 	
		Nome: Rodrigo Freitas Leite;
		Cartão: 160568;
		Email: rodrigo.freitas.leite@gmail.com
	Descrição: 
		Programa que cria o fractal de Barnsley fern;
		Programa compilado e gerado em ubuntu linux, segue makefile
			com instruções para compilá-lo
*/

#include <GL/glut.h>
#include <stdlib.h> 
#include <stdio.h>
#include <unistd.h>

#define WINDOW_X 800
#define WINDOW_Y 600

typedef struct Point{
	float x;
	float y;
}Point;

Point p;

void  init(void){
		
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Cor de fundo preta   
	glMatrixMode(GL_PROJECTION); 
	// meio da tela p(0,0);
    gluOrtho2D(-WINDOW_X/2, WINDOW_X/2, -WINDOW_Y/2, WINDOW_Y/2);
	p.x = 0.0f;
	p.y = 0.0f;

}

void fern(void){
	
	// Probabilidade de 0 a 99
	int prob = rand() % 100; 
	float temp_x = p.x, temp_y = p.y;

	if(prob == 0){
        p.x = 0.0f;
        p.y = 0.16f*temp_y; 
		glColor3f(0.62f, 0.32f, 0.17f);  
	}
	if(prob >= 1 && prob <= 6){
        p.x = 0.2f*temp_x - 0.26f*temp_y;
        p.y = 0.23f*temp_x + 0.22f*temp_y + 1.6f;
		glColor3f(0.8f, 0.0f, 0.0f);      
	}
    if(prob >= 7 && prob <= 14){
        p.x = -0.15f*temp_x + 0.28f*temp_y;
        p.y = 0.26f*temp_x + 0.24f*temp_y + 0.44f;
		glColor3f(1.0f, 1.0f, 0.0f);      
	}
    if(prob >= 15 && prob <= 99){
        p.x = 0.85f*temp_x + 0.04f*temp_y;
        p.y = -0.04f*temp_x + 0.85f*temp_y + 1.6f;
		glColor3f(0.0f, 0.7f, 0.0f);      
	}        
}

void draw(void){
	int i = 0;
	glClear(GL_COLOR_BUFFER_BIT);

	for(i = 0; i < 100000; i++){
		fern();		
		glBegin (GL_POINTS);
			// adquar a visao da tela
			glVertex2f(p.x * 80, p.y * 50 - 250) ; 
		glEnd();	
		/* plotar mais devagar durante execução */		
		//usleep(5000/2);
		glFlush();
	}
}


int main(int argc, char **argv){
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition(220,100);
	glutInitWindowSize(WINDOW_X,WINDOW_Y);
	glutCreateWindow("FERN FRACTAL");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
