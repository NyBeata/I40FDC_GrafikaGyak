#ifndef LINE_H
#define LINE_H

#include <GL/gl.h>

typedef struct Line
{
	GLfloat x1;
	GLfloat y1;
    GLfloat x2;
	GLfloat y2;
} Line;

void DrawLine(Line line);

#endif // LINE_H