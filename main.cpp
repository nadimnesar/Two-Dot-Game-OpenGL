#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

bool lefti = false, righti = false;
bool upi = false, downi = false;

bool lefta = true, righta = true;
bool upa = true, downa = true;

int ix = 30, iy = 30;
int ifx = 200, ify = 200;

int speed = 5, score = 0;
int tt = 500, now = tt;

bool gover = false;

typedef struct node {
  int x1, y1, x2, y2, x3, y3, x4, y4;
} node;

vector < node > v;
node x;

void scorei() {
  glColor3ub(255, 255, 255);
  glRasterPos2f(20, 550);

  string str = "Score: ", num;
  int s = score;
  if (s == 0) num += '0';
  while (s) {
    num += char((s % 10) + '0');
    s /= 10;
  }
  reverse(num.begin(), num.end());
  str += num;

  for (int i = 0; i < str.size(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
  }
}

void timei() {
  glColor3ub(255, 255, 255);
  glRasterPos2f(300, 550);

  string str = "Time: ", num;
  int s = now;
  if (s == 0) num += '0';
  while (s) {
    num += char((s % 10) + '0');
    s /= 10;
  }
  reverse(num.begin(), num.end());
  str += num;
  str += "ms";

  for (int i = 0; i < str.size(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
  }
}

void gameover() {
  glColor3ub(255, 255, 255);
  glRasterPos2f(150, 300);

  string str = "Game Over! Score: ", num;
  int s = score;
  if (s == 0) num += '0';
  while (s) {
    num += char((s % 10) + '0');
    s /= 10;
  }
  reverse(num.begin(), num.end());
  str += num;

  for (int i = 0; i < str.size(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
  }
}

float dis(float xp, float yp, float xf, float yf) {
  float x = xf - xp, y = yf - yp;
  return sqrt(x * x + y * y);
}

void food(int x, int y) {
  glPointSize(12);
  glBegin(GL_POINTS);
  glColor3ub(255, 0, 0);
  glVertex2f(x, y);
  glEnd();
}

void player(int x, int y) {
  glPointSize(20);
  glBegin(GL_POINTS);
  glColor3ub(0, 255, 0);
  glVertex2f(x, y);
  glEnd();
}



void display(void) {
  glClear (GL_COLOR_BUFFER_BIT);
  if (!gover) {

    scorei(); timei();

    // start walls

    x.x1 = 0; x.y1 = 0;
    x.x2 = 500; x.y2 = 0;
    x.x3 = 500; x.y3 = 5;
    x.x4 = 0; x.y4 = 5;

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 495; x.y1 = 0;
    x.x2 = 500; x.y2 = 0;
    x.x3 = 500; x.y3 = 500;
    x.x4 = 495; x.y4 = 500;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 0; x.y1 = 495;
    x.x2 = 500; x.y2 = 495;
    x.x3 = 500; x.y3 = 500;
    x.x4 = 0; x.y4 = 500;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 0; x.y1 = 0;
    x.x2 = 5; x.y2 = 0;
    x.x3 = 5; x.y3 = 500;
    x.x4 = 0; x.y4 = 500;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    // obstracls

    x.x1 = 0; x.y1 = 100;
    x.x2 = 100; x.y2 = 100;
    x.x3 = 100; x.y3 = 105;
    x.x4 = 0; x.y4 = 105;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 95; x.y1 = 65;
    x.x2 = 100; x.y2 = 65;
    x.x3 = 100; x.y3 = 105;
    x.x4 = 95; x.y4 = 105;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 300; x.y1 = 100;
    x.x2 = 500; x.y2 = 100;
    x.x3 = 500; x.y3 = 105;
    x.x4 = 300; x.y4 = 105;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 150; x.y1 = 180;
    x.x2 = 155; x.y2 = 180;
    x.x3 = 155; x.y3 = 400;
    x.x4 = 150; x.y4 = 400;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 250; x.y1 = 300;
    x.x2 = 500; x.y2 = 300;
    x.x3 = 500; x.y3 = 305;
    x.x4 = 250; x.y4 = 305;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 0; x.y1 = 400;
    x.x2 = 300; x.y2 = 400;
    x.x3 = 300; x.y3 = 405;
    x.x4 = 0; x.y4 = 405;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 300; x.y1 = 105;
    x.x2 = 305; x.y2 = 105;
    x.x3 = 305; x.y3 = 245;
    x.x4 = 300; x.y4 = 245;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 350; x.y1 = 350;
    x.x2 = 355; x.y2 = 350;
    x.x3 = 355; x.y3 = 500;
    x.x4 = 350; x.y4 = 500;
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    x.x1 = 200; x.y1 = 0;
    x.x2 = 205; x.y2 = 0;
    x.x3 = 205; x.y3 = 150;
    x.x4 = 200; x.y4 = 150;

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f( x.x1, x.y1 );
    glVertex2f( x.x2, x.y2 );
    glVertex2f( x.x3, x.y3 );
    glVertex2f( x.x4, x.y4 );
    glEnd();
    if (v.size() <= 13) v.push_back(x);

    // others

    food(ifx, ify);

    int px1 = ix - 10, py1 = iy - 10;
    int px2 = ix + 10, py2 = iy - 10;
    int px3 = ix + 10, py3 = iy + 10;
    int px4 = ix - 10, py4 = iy + 10;

    for (int i = 0; i < v.size(); i++) {
      int bx1 = v[i].x1, by1 = v[i].y1;
      int bx2 = v[i].x2, by2 = v[i].y2;
      int bx3 = v[i].x3, by3 = v[i].y3;
      int bx4 = v[i].x4, by4 = v[i].y4;

      if (lefti) {
        for (int pj = py1; pj <= py4 - 1; pj++) {
          for (int bk = by2; bk <= by3 - 1; bk++) {
            if (dis(px1, pj, bx2, bk) <= 0) {
              lefta = false; lefti = false;
              righta = true; upa = true;
              downa = true;
              break;
            }
          }
          if (!lefta) break;
        }
      }

      if (righti) {
        for (int pj = py2; pj <= py3 - 1; pj++) {
          for (int bk = by1; bk <= by4 - 1; bk++) {
            if (dis(px2, pj, bx1, bk) <= 0) {
              lefta = true; righta = false;
              upa = true; downa = true;
              righti = false;
              break;
            }
          }
          if (!righta) break;
        }
      }

      if (upi) {
        for (int pj = px4; pj <= px3 - 1; pj++) {
          for (int bk = bx1; bk <= bx2 - 1; bk++) {
            if (dis(pj, py4, bk, by1) <= 0) {
              lefta = true; righta = true;
              upa = false; downa = true;
              upi = false;
              break;
            }
          }
          if (!upa) break;
        }
      }

      if (downi) {
        for (int pj = px1; pj <= px2 - 1; pj++) {
          for (int bk = bx4; bk <= bx3 - 1; bk++) {
            if (dis(pj, py1, bk, by4) <= 0) {
              lefta = true; righta = true; upa = true;
              downa = false;
              downi = false;
              break;
            }
          }
          if (!downa) break;
        }
      }
    }

    if (upi) iy += speed;
    if (downi) iy -= speed;
    if (lefti) ix -= speed;
    if (righti) ix += speed;

    player(ix, iy);

    if (dis(ix, iy, ifx, ify) <= 20) {
      ifx = (10 + (rand() % ( 450 - 10 + 1 )));
      ify = (10 + (rand() % ( 450 - 10 + 1 )));
      score++;
      now = tt;
    }
  }
  else gameover();

  glFlush ();
}

void init (void) {
  glClearColor (0.0, 0.0, 0.0, 0.0); //window Color
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 500, 0, 600); //View Size same as window size.
}

void keyboardfun(unsigned char key, int x, int y) {
  if (key == 'w' && upa) {
    upi = true; downi = false;
    lefti = false; righti = false;

    lefta = true; righta = true; downa = true;
  }

  if (key == 's' && downa) {
    upi = false; downi = true;
    lefti = false; righti = false;
    lefta = true; righta = true; upa = true;
  }

  if (key == 'a' && lefta ) {
    upi = false; downi = false;
    lefti = true; righti = false;
    righta = true; upa = true; downa = true;
  }

  if (key == 'd' && righta) {
    upi = false; downi = false;
    lefti = false; righti = true;
    lefta = true; upa = true; downa = true;
  }
}

void update(int val) {
  now--;
  if (now == 0) gover = true;
  glutPostRedisplay();
  glutTimerFunc(1, update, 0);
}

int main(int argc, char** argv) {
  //srand(time(NULL));

  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize (500, 600);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Two Point Game");

  init();
  glutDisplayFunc(display);

  glutTimerFunc(25, update, 0);
  update(0);

  glutKeyboardFunc(keyboardfun);

  sndPlaySound("gs.wav", SND_ASYNC);
  glutMainLoop();

  return 0;
}
