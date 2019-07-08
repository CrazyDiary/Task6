#include<gl/GLUT.H>
#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<math.h>
using namespace std;
GLfloat modelview_matrix[16];
const int win_w = 700, win_h = 700;
GLfloat ex[3] = { 0.0, 0.0, 0.0 }; //�۲���λ��
GLfloat ey[3] = { 1.0, 0.0, 0.0 };
GLfloat ez[3] = { 4.0, 0.0, 0.0 };
GLfloat fx[3] = { 0.0, 0.0, 0.0 }; //�۲����λ��
GLfloat fy[3] = { 0.0, 0.0, 0.0 };
GLfloat fz[3] = { 0.0, 0.0, 0.0 };

GLint view = 0;
GLfloat angle = 0.0f;
void reshape_func(int w,int h);
void display_func();
void drawPig();
void Initial(void);
void onMouse(int button, int state, int x, int y);
void RotateRect();

// ��ͼ����
void drawPig()
{
	// ��ת����
	glRotatef(angle, 0, 0, 0);
	glPushMatrix();
	glColor3f(1.0, 0.8, 0.8);
	glutSolidSphere(0.25f, 100, 100);  //����
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.2, 0);
	glColor3f(1.0, 0.8, 0.8);
	glutSolidSphere(0.25f, 100, 100);  //����
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.05, 0.08, 0.23);
	glutSolidSphere(0.013f, 1000, 1000);  //����
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-0.05, 0.08, 0.23);
	glutSolidSphere(0.013f, 1000, 1000);  //����
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(-0.01, 0.01, 0.23);
	glScaled(1.35, -1.0, 1.0);
	glutSolidSphere(0.06f, 1000, 1000);  //���
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glTranslatef(0.0175, 0.01, 0.23);
	glutSolidSphere(0.013f, 1000, 1000);  //��ǿ�
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glTranslatef(-0.0175, 0.01, 0.23);
	glutSolidSphere(0.013f, 1000, 1000);  //�ұǿ�
	glPopMatrix();

	// ���������Σ�����
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.2, 0.28, 0.15);
	glVertex3f(0.19, 0.06, 0.15);
	glVertex3f(0.07, 0.21, 0.1);

	glVertex3f(0.2, 0.28, 0.15);
	glVertex3f(0.07, 0.21, 0.1);
	glVertex3f(0.12, 0.2, 0.08);

	glVertex3f(0.2, 0.28, 0.15);
	glVertex3f(0.19, 0.06, 0.15);
	glVertex3f(0.12, 0.2, 0.08);
	glEnd(); //���
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.2, 0.28, 0.15);
	glVertex3f(-0.19, 0.06, 0.15);
	glVertex3f(-0.07, 0.21, 0.1);

	glVertex3f(-0.2, 0.28, 0.15);
	glVertex3f(-0.07, 0.21, 0.1);
	glVertex3f(-0.12, 0.2, 0.08);

	glVertex3f(-0.2, 0.28, 0.15);
	glVertex3f(-0.19, 0.06, 0.15);
	glVertex3f(-0.12, 0.2, 0.08);
	glEnd(); //�Ҷ�
	glPopMatrix();

	// ��
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glTranslatef(0.30, -0.2, 0.1);
	glScaled(2.0,-1.0,2.0);
	glutSolidSphere(0.035f, 50, 1000);  
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glTranslatef(-0.30, -0.2, 0.1);
	glScaled(2.0,1.0, 2.0);
	glutSolidSphere(0.035f, 50, 1000);  
	glPopMatrix();
	// ��
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.07, -0.4, 0.1);
	glutSolidSphere(0.05f, 1000, 1000);  //���
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-0.07, -0.4, 0.1);
	glutSolidSphere(0.05f, 1000, 1000);  //�ҽ�
	glPopMatrix();
}
// ��ʼ������
void Initial(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);//��ɫ������ǰ3����RGB�������Alphaֵ����������͸����1.0��ʾ��ȫ��͸��
	glShadeModel(GL_FLAT);
    //glMatrixMode(GL_PROJECTION);//OpenGL������ά��ʽ������ͼ��������Ҫһ��ͶӰ�任����άͼ��ͶӰ����ʾ���Ķ�ά�ռ���
	//gluOrtho2D(0.0, 200, 0.0, 150.0);//ָ��ʹ����ͶӰ��һ��x������0~200��y����0~150��Χ�ڵľ�����������ͶӰ����ʾ������
}
// ���ô���
void reshape_func(int w,int h)
{
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.0, 100.0);
}
// ��ʾ
void display_func()
{
	// ����
	//static int z = 0;
	//cout << "��ʾ��" << z++ << " " << endl;

	// ��ʾҪ�����ɫ����
	glClear(GL_COLOR_BUFFER_BIT);
	// ָ����ʾģʽ
	glMatrixMode(GL_MODELVIEW);
	// �ָ���ʼ����
	glLoadIdentity();
	// �ú�������һ����ͼ���󣬲��뵱ǰ�������
	gluLookAt(ex[view], ey[view], ez[view], fx[view], fy[view], fz[view], 0.0, 1.0, 0.0);

	// ��������
	glColor3f(0.82, 0.82, 0.82);
	glBegin(GL_LINES);
	float i, j;
	for (i = -50; i <= 50; i = i + 0.2)
	{
		glVertex3f(i, -0.25, -50);
		glVertex3f(i, -0.25, 50);
	}
	for (j = -50; j <= 50; j += 0.2)
	{
		glVertex3f(-50, -0.25, j);
		glVertex3f(50, -0.25, j);
	}
	glEnd();

	glPushMatrix();
	 drawPig();
	glPopMatrix();

	// ��������������ָ��
	glutSwapBuffers();
}
/*
	���������ʼ��ת���Ҽ�ֹͣ
*/
void RotateRect()
{
	angle += 0.5;
	if (angle > 360)
	{
		angle = 0.0f;
	}
	Sleep(30);
	display_func();
}
// ����¼�
void onMouse(int button,int state,int x,int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		glutIdleFunc(RotateRect);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		glutIdleFunc(NULL);
	}
}

int main(int argc, char*argv[])
{
	glutInit(&argc, argv);

	// ���ó�ʼ��ʾģʽ��ָ��RGB��ɫģʽ�Լ�ָ��˫���洰��
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("һֻ�������е���");
	// ��ʾͼ��
	glutDisplayFunc(display_func);
	// �ı䴰�ڴ�Сʱ����ͼ�����
	glutReshapeFunc(reshape_func);

	// ��������¼�
	glutMouseFunc(onMouse);
	Initial();
	glutMainLoop();
}