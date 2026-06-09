#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

GLfloat ang;
float rotY = 0;
int dia = 1;
float tempo = 0.0f;

const float ALTURA_CHAO = 0.5f;

float corCeuR = 0.0;
float corCeuG = 1.0;
float corCeuB = 1.0;

float camX = 0;
float camY = ALTURA_CHAO;
float camZ = 15;

float angleY = 0;
float angleX = 0;

bool keys[256];

int lastMouseX = 450;
int lastMouseY = 400;

float mouseSens = 0.0015f;

bool mouseAtivo = false;

bool gravidadeAtiva = true;
float velocidadeY = 0.0f;

bool noChao = true;

void inicializa(void){
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	ang = 0.0;
	gluPerspective(60.0, 900.0/800.0, 0.1, 100.0);     // perspectiva 3D REAL
//	gluLookAt(0,0,10, 0,0,0, 0,1,0); //posição da camera
	glEnable(GL_DEPTH_TEST);
}

void Casa(){
    glPushMatrix();

    glColor3f(0.8, 0.5, 0.3);

    glScalef(2.0, 2.0, 2.0);
    glutSolidCube(1);

    glPopMatrix();
}

void CorpoPredio(){
    glPushMatrix();

    glColor3f(0.8, 0.8, 0.8);

    glScalef(2.0, 7, 2.0);
    glutSolidCube(1);

    glPopMatrix();
}

void Telhado(){
    glPushMatrix();

    glTranslatef(0, 1, 0);
    
    glRotatef(0,1,0,0);

    glColor3f(0.5, 0.1, 0.1);
    
    glBegin(GL_TRIANGLES);
     	// frente
        glVertex3f(-1.2,0,1.2);
        glVertex3f( 1.2,0,1.2);
        glVertex3f( 0,1,1.2);

        // trás
        glVertex3f(-1.2,0,-1.2);
        glVertex3f( 1.2,0,-1.2);
        glVertex3f( 0,1,-1.2);
    glEnd();
    
    glBegin(GL_QUADS);
    	// lado esquerdo
        glVertex3f(-1.2,0, 1.2);
        glVertex3f( 0,1, 1.2);
        glVertex3f( 0,1,-1.2);
        glVertex3f(-1.2,0,-1.2);

        // lado direito
        glVertex3f(1.2,0, 1.2);
        glVertex3f(0,1, 1.2);
        glVertex3f(0,1,-1.2);
        glVertex3f(1.2,0,-1.2);

    glEnd();

    glPopMatrix();
}

void Janela(){
    glPushMatrix();

	if(dia)
   		glColor3f(0,0,1);
	else
   		glColor3f(1,1,0);
   		
    glTranslatef(0.5,0,1.01);

    glScalef(0.3,0.3,0.05);

    glutSolidCube(1);

    glPopMatrix();
}

void Porta(){

    glPushMatrix();

    glTranslatef(0,-0.3,1.01);

    glColor3f(0.4,0.2,0);

    glScalef(0.3,0.6,0.1);

    glutSolidCube(1);

    glPopMatrix();
}

void Rua(){
    glPushMatrix();

    glColor3f(0.2,0.2,0.2);

    glTranslatef(0,-2,0);

    glScalef(20,3,15);

    glutSolidCube(1);

    glPopMatrix();
}

void Arvore(){

    // tronco
    glPushMatrix();

    glColor3f(0.4,0.2,0);

    glTranslatef(0,-0.5,0);

    glScalef(0.3,1,0.3);

    glutSolidCube(1);

    glPopMatrix();

    // copa
    glPushMatrix();

    glColor3f(0,1,0);

    glTranslatef(0,0.5,0);

    glutSolidSphere(0.6,20,20);

    glPopMatrix();
}

void Chao(){

    glPushMatrix();

    glColor3f(0,0.6,0);

    glTranslatef(0,-2.5,0);

    glScalef(30,3.7,30);

    glutSolidCube(1);

    glPopMatrix();
}

void pista(){

    glPushMatrix();

    glColor3f(0.1,0.1,0.1);

    glTranslatef(0,-0.9,0);

    glScalef(25,1,5);

    glutSolidCube(1);

    glPopMatrix();
}

void Garagem(){

    glPushMatrix();

    glColor3f(0.7,0.4,0.2);

    // posição lateral da casa
    glTranslatef(1.75,0,0);

    // tamanho da garagem
    glScalef(1.5,2,2.0);

    glutSolidCube(1);

    glPopMatrix();
}

void Cerca(){ //Cerca para as casas

glColor3f(0.55, 0.27, 0.07); // marrom madeira

    // ===== ESTACAS ESQUERDA =====
    for(float z=-2.0; z<=2.0; z+=0.3){

        glPushMatrix();
        glTranslatef(-1.5, -0.2, z);

        glScalef(0.1, 0.8, 0.1);

        glutSolidCube(1);
        glPopMatrix();
    }

    // ===== ESTACAS DIREITA =====
    for(float z=-2.0; z<=2.0; z+=0.3){

        glPushMatrix();
        glTranslatef(2.8, -0.3, z);

        glScalef(0.1, 0.8, 0.1);

        glutSolidCube(1);
        glPopMatrix();
    }

    // ===== ESTACAS FUNDO =====
    for(float x=-1.5; x<=2.8; x+=0.3){

        glPushMatrix();
        glTranslatef(x, -0.3, -2.0);

        glScalef(0.1, 0.8, 0.1);

        glutSolidCube(1);
        glPopMatrix();
    }

    // ===== TRILHO ESQUERDO =====
    glPushMatrix();
    glTranslatef(-1.5, -0.3, 0);

    glScalef(0.08, 0.1, 4.0);

    glutSolidCube(1);
    glPopMatrix();

    // ===== TRILHO DIREITO =====
    glPushMatrix();
    glTranslatef(2.8, -0.3, 0);

    glScalef(0.08, 0.1, 4.0);

    glutSolidCube(1);
    glPopMatrix();

    // ===== TRILHO FUNDO =====
    glPushMatrix();
    glTranslatef(0.65, -0.3, -2.0);

    glScalef(4.3, 0.1, 0.08);

    glutSolidCube(1);
    glPopMatrix();
}

//sol
void Sol(){

    glPushMatrix();

    glColor3f(1,1,0);

    float x = cos(tempo) * 15;
    float y = sin(tempo) * 10;

    glTranslatef(x,y,-18);

    glutSolidSphere(1.5,20,20);

    glPopMatrix();
}
//lua
void Lua(){

    glPushMatrix();

    glColor3f(0.9,0.9,0.9);

    float x = cos(tempo + 3.14f) * 15;
    float y = sin(tempo + 3.14f) * 10;

    glTranslatef(x,y,-15);

    glutSolidSphere(1.2,20,20);

    glPopMatrix();
}

void PortaoGaragem(){

    glPushMatrix();

    glColor3f(0.3,0.3,0.3);

    // frente da garagem
    glTranslatef(1.75,-0.5,1.01);

    glScalef(0.9,1.5,0.1);

    glutSolidCube(1);

    glPopMatrix();
}

void CasaCompleta(){

    Casa();

    Telhado();

    Porta();
    
    Garagem();

	PortaoGaragem();
	
	Cerca();

    glPushMatrix();
    glTranslatef(-1,0.5,0);
    Janela();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2,0,0);
    Janela();
    glPopMatrix();
}

void PredioCompleto(){
	CorpoPredio();
	Porta();
	
	glPushMatrix();
    glTranslatef(-1.1,0.5,0);
    Janela();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1,0.5,0);
    Janela();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.1,1.2,0);
    Janela();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.1,1.2,0);
    Janela();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.1,1.9,0);
    Janela();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.1,1.9,0);
    Janela();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.1,2.6,0);
    Janela();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.1,2.6,0);
    Janela();
    glPopMatrix();
}


//Animação dia noite

void Timer(int value){

    // tempo vai aumentando
    tempo += 0.002f;

    // mantém entre 0 e 2PI
    if(tempo > 6.28f)
        tempo = 0.0f;

    // intensidade do dia/noite
    float intensidade = (sin(tempo) + 1.0f) / 2.0f;

    // céu
    corCeuR = 0.05f * intensidade;
    corCeuG = 0.1f + (0.45f * intensidade);
    corCeuB = 0.2f + (0.8f * intensidade);

    // detectar noite
    if(intensidade < 0.4f)
        dia = 0;
    else
        dia = 1;

    glutPostRedisplay();

    glutTimerFunc(16, Timer, 0);
}

void DesenhaCasa(void){
	
	float dirX = cos(angleX) * sin(angleY);
	float dirY = sin(angleX);
	float dirZ = -cos(angleX) * cos(angleY);
	
	glClearColor(corCeuR, corCeuG, corCeuB, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(camX,camY,camZ, camX + dirX,camY + dirY,camZ + dirZ, 0,1,0);

	// chão
	Chao();

	// rua
	Rua();
	
	//pista
	pista();

	// CASA 1
	glPushMatrix();
	glTranslatef(-2,0,-5);
	CasaCompleta();
	glPopMatrix();

	// CASA 2
	glPushMatrix();
	glTranslatef(-8,0,-5);
	CasaCompleta();
	glPopMatrix();

	// CASA 3
	glPushMatrix();
	glTranslatef(4,0,-5);
	CasaCompleta();
	glPopMatrix();
	
	// CASA 4
	glPushMatrix();
	glTranslatef(4,0,5);
	glRotatef(180, 0,1,0); // gira a casa para frente das outras
	CasaCompleta();
	glPopMatrix();


	// ÁRVORE 1
	glPushMatrix();
	glTranslatef(-5,0,3);
	Arvore();
	glPopMatrix();

	// ÁRVORE 2
	glPushMatrix();
	glTranslatef(-4,0,-3.5);
	Arvore();
	glPopMatrix();

	// ÁRVORE 3
	glPushMatrix();
	glTranslatef(7,0,-3);
	Arvore();
	glPopMatrix();
	
	// PREDIO 1
	glPushMatrix();
	glTranslatef(8,0,5);
	glRotatef(180, 0,1,0); // gira o predio para frente das casas
	PredioCompleto();
	glPopMatrix();
	
	// PREDIO 2
	glPushMatrix();
	glTranslatef(-2,0,5);
	glRotatef(180, 0,1,0); // gira o predio para frente das casas
	PredioCompleto();
	glPopMatrix();

	
	//Ficar dia ou noite
	
	if(dia){
   	  Sol();
	} else{
  	  Lua();
	}
	glutSwapBuffers();
}

void MouseMotion(int x, int y){
	
	if(!mouseAtivo)
        return;
        
    int centroX = 450;
    int centroY = 400;

    int dx = x - centroX;
    int dy = y - centroY;

    angleY += dx * mouseSens;
    angleX -= dy * mouseSens;

    // limitar visão vertical
    if(angleX > 1.5f)
        angleX = 1.5f;

    if(angleX < -1.5f)
        angleX = -1.5f;

    lastMouseX = x;
    lastMouseY = y;

    glutWarpPointer(centroX, centroY);     // reposiciona mouse no centro

}

void Movimento(){

    float speed = 0.05f;

    // frente
    if(keys['w']){
        camX += sin(angleY) * speed;
        camZ -= cos(angleY) * speed;
    }

    // trás
    if(keys['s']){
        camX -= sin(angleY) * speed;
        camZ += cos(angleY) * speed;
    }

    // esquerda
    if(keys['a']){
        camX -= cos(angleY) * speed;
        camZ -= sin(angleY) * speed;
    }

    // direita
    if(keys['d']){
        camX += cos(angleY) * speed;
        camZ += sin(angleY) * speed;
    }

    // Modo criativo (sem gravidade)
    if(!gravidadeAtiva){

        if(keys['q']){
            camY += speed;
        }

        if(keys['e']){
            camY -= speed;
        }
    }
}

void Teclado(unsigned char key, int x, int y){

    keys[key] = true;

    if(key == 27){
        exit(0);
    }

    if(key == 'm'){
        mouseAtivo = !mouseAtivo;

        if(mouseAtivo){
            glutSetCursor(GLUT_CURSOR_NONE);
            glutWarpPointer(450,400);
        }else{
            glutSetCursor(GLUT_CURSOR_INHERIT);
        }
    }

    // Pulo (somente quando está no chão)
    if(key == ' ' && gravidadeAtiva && noChao){
        velocidadeY = 0.05f;
        noChao = false;
    }
}

void TecladoUp(unsigned char key, int x, int y){

    keys[key] = false;

    if(key == 'g'){

        gravidadeAtiva = !gravidadeAtiva;

        // ao voltar para o criativo
        if(!gravidadeAtiva){
            velocidadeY = 0.0f;
            noChao = false;
        }
    }
}

void Atualiza(int value){

    Movimento();

    if(gravidadeAtiva){

        // gravidade
        velocidadeY -= 0.003f;
        camY += velocidadeY;

        
		if(camY <= ALTURA_CHAO){

            camY = ALTURA_CHAO;
            velocidadeY = 0.0f;
            noChao = true;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, Atualiza, 0); // ~60 FPS

}

int main(void){
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900,800);
	glutCreateWindow("Casa");
	glutDisplayFunc(DesenhaCasa);
	inicializa();
	glutKeyboardFunc(Teclado);
	glutKeyboardUpFunc(TecladoUp);
	glutPassiveMotionFunc(MouseMotion);
	glutTimerFunc(16, Atualiza, 0);
	glutTimerFunc(5000, Timer, 0);
	glutMainLoop();
	
}
