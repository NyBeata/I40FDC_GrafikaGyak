#include "line.h"

void DrawLine(Line line)
{
    double x1 = 2*line.x1 / 800 - 1;
    double y1 = 2*line.y1 / 600 - 1;

    double x2 = 2*line.x2 / 800 - 1;
    double y2 = 2*line.y2 / 600 - 1;

    glBegin(GL_LINES);
        glVertex2f(x1, -y1);
        glVertex2f(x2, -y2);
    glEnd();
}