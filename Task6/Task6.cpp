#include<gl/GLUT.H>
#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<math.h>
using namespace std;
GLfloat modelview_matrix[16];
GLfloat theta[3] = { 0.0,0.0,0.0 };
const int n = 1000;
const GLfloat Pi = 3.1415926536F;
const int win_w = 700, win_h = 700;
GLfloat ex[3] = { 0.0, 0.0, 0.0 }; //�۲���λ��
GLfloat ey[3] = { 1.0, 0.0, 0.0 };
GLfloat ez[3] = { 4.0, 0.0, 0.0 };
GLfloat fx[3] = { 0.0, 0.0, 0.0 }; //�۲����λ��
GLfloat fy[3] = { 0.0, 0.0, 0.0 };
GLfloat fz[3] = { 0.0, 0.0, 0.0 };
GLfloat default_matrix[16];
GLfloat modelview_z_dis;
GLfloat ax = -1.0f; //��һֻ��ĳ�ʼ����
GLfloat ay = 0.0f;
GLfloat az = 0.0f;
GLfloat mx = 1.0f; //��һֻ�����ű���
GLfloat my = 1.0f;
GLfloat mz = 1.0f;
GLint view = 0;
GLfloat angle = 0.0f;
void reshape_func(int w,int h);
void display_func();
void draw();
void drawPig();
void Initial(void);
void onMouse(int button, int state, int x, int y);
void RotateRect();
void absolute_default();
void absolute_scale(GLfloat factor);

// ��ͼ����
void draw()
{
	// 
	//GLfloat color[] = { .4f,.4f,.4f,.4f,1.0f };
	drawPig();
}
// ����һֻ��
void drawPig()
{
	//RotateRect();
	glRotatef(angle, 0, 1, 0);
	glTranslatef(ax, ay, az);
	glScalef(mx, my, mz);
	// ÿ�������ת�Ƕ�
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	//glRotatef(theta[2], 0.0, 0.0, 1.0);

	glPushMatrix();
	glTranslatef(0.15, -0.2, 0.125);
	glColor3f(1.0, 0.5, 0.5);
	glutSolidSphere(0.05f, 100, 100); //��ǰ��
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glTranslatef(-0.15, -0.2, 0.125);
	glutSolidSphere(0.05f, 100, 100); //��ǰ��
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glTranslatef(0.15, -0.2, -0.125);
	glutSolidSphere(0.05f, 100, 100); //����
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glTranslatef(-0.15, -0.2, -0.125);
	glutSolidSphere(0.05f, 100, 100); //�Һ��
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, 0.05f, 0.05f, 0.27f, 50, 50); //����
	glPopMatrix();

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

	glPushMatrix();
	glColor3f(1.0, 0.8, 0.8);
	glutSolidSphere(0.25f, 100, 100);  //����
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; ++i)
		glVertex3f(0.06*cos(2 * Pi / n * i), 0.04*sin(2 * Pi / n * i), 0.27f);
	glEnd();//����(����)
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; ++i)
		glVertex3f(-0.02 + 0.01*cos(2 * Pi / n * i), 0.01*sin(2 * Pi / n * i), 0.27f);
	glEnd();//�ұǿ�
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; ++i)
		glVertex3f(0.02 + 0.01*cos(2 * Pi / n * i), 0.01*sin(2 * Pi / n * i), 0.27f);
	glEnd();//��ǿ�
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

	//glMatrixMode(GL_MODELVIEW);
	
	//glColor3f(0.0f, 0.0f, 0.0f);
	//glRectf(50.0f, 100.0f, 150.0f, 50.0f);//ͼ�ε����꣬����һ�����Ͻ��ڣ�50��100�������½��ڣ�150��50���ľ���
	// ָ���ĸ������ǵ�ǰ����
	// GL_PROJECTION ͶӰ, GL_MODELVIEW ģ����ͼ, GL_TEXTURE ����
	// ?
	//glLoadMatrixf(modelview_matrix);
	// ��ͼ����	

	glPushMatrix();
	drawPig();
	glPopMatrix();

	// ��������������ָ��
	glutSwapBuffers();
}
/*
	���������ʼ��ת���Ҽ���ͣ
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
static bool l_button_down = false, r_button_down = false, mid_button_down = false;
static int last_x = -1, last_y = -1;
#define  GLUT_WHEEL_UP		3 // ���ֲ���  
#define  GLUT_WHEEL_DOWN	4
void absolute_default()
{
	memcpy(modelview_matrix, default_matrix, sizeof(default_matrix));
}
void absolute_scale(GLfloat factor)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(.0, .0, -modelview_z_dis);		// ƽ�ƻ�ȥ��ע��þ�ͺ�����Ҫ��������
	glScalef(factor, factor, factor);
	glTranslatef(.0, .0, modelview_z_dis);		// ��ƽ�Ƶ�ԭ��
	glMultMatrixf(modelview_matrix); // ʹ�任������˵���ǰ�����������ʺϾ�������Ŀ���
	glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
	glPopMatrix();
}
void mouse_click_func(int button, int state, int x, int y)
{
	y = win_h - y;
	switch (button) {
		// ��ť
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			l_button_down = true;
			last_x = x; last_y = y;
			glutSetCursor(GLUT_CURSOR_CROSSHAIR);
		}
		else {
			l_button_down = false;
			last_x = -1; last_y = -1;
			glutSetCursor(GLUT_CURSOR_INHERIT);
		}
		break;
		// �м�
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN) {
			mid_button_down = true;
			last_x = x; last_y = y;
			glutSetCursor(GLUT_CURSOR_CYCLE);

		}
		else {
			mid_button_down = false;
			last_x = -1; last_y = -1;
			glutSetCursor(GLUT_CURSOR_INHERIT);
		}
		break;
		// �ұ�
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			r_button_down = true;
			absolute_default();
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
			glutPostRedisplay();
		}
		else {
			r_button_down = false;
			glutSetCursor(GLUT_CURSOR_INHERIT);
		}
		break;
		// ת��
	case GLUT_WHEEL_UP:
		if (state == GLUT_UP) {
			absolute_scale(.9f);
			glutPostRedisplay();
		}
		break;
		// ����ת��
	case GLUT_WHEEL_DOWN:
		if (state == GLUT_UP) {
			absolute_scale(1.1f);
			glutPostRedisplay();
		}
		break;
	}
}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	// ���ó�ʼ��ʾģʽ��ָ��RGB��ɫģʽ�Լ�ָ��˫���洰��
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("CrazyCake�ĵ�һ��opengl����");
	// ��ʾͼ��
	glutDisplayFunc(display_func);
	// �ı䴰�ڴ�Сʱ����ͼ�����
	glutReshapeFunc(reshape_func);

	// ��������¼�
	glutMouseFunc(onMouse);
	Initial();
	glutMainLoop();
}