#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 24
#define DEPTH 20

typedef struct {
    float x, y, z;
} Point3D;

typedef struct {
    float x, y;
} Point2D;

Point2D project(Point3D p) {
    Point2D result;
    float scale = 400.0 / (8.0 + p.z);
    result.x = p.x * scale + WIDTH / 2;
    result.y = p.y * scale + HEIGHT / 2;
    return result;
}

Point3D rotateX(Point3D p, float angle) {
    Point3D result;
    result.x = p.x;
    result.y = p.y * cos(angle) - p.z * sin(angle);
    result.z = p.y * sin(angle) + p.z * cos(angle);
    return result;
}

Point3D rotateY(Point3D p, float angle) {
    Point3D result;
    result.x = p.x * cos(angle) + p.z * sin(angle);
    result.y = p.y;
    result.z = -p.x * sin(angle) + p.z * cos(angle);
    return result;
}

Point3D rotateZ(Point3D p, float angle) {
    Point3D result;
    result.x = p.x * cos(angle) - p.y * sin(angle);
    result.y = p.x * sin(angle) + p.y * cos(angle);
    result.z = p.z;
    return result;
}

int main() {
    Point3D vertices[8] = {
        {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
        {-1, -1, 1},  {1, -1, 1},  {1, 1, 1},  {-1, 1, 1}
    };

    float angle = 0;

    while (1) {
        char buffer[WIDTH * HEIGHT];
        memset(buffer, ' ', sizeof(buffer));

        Point3D rotated[8];
        for (int i = 0; i < 8; i++) {
            rotated[i] = rotateX(vertices[i], angle);
            rotated[i] = rotateY(rotated[i], angle * 1.3);
            rotated[i] = rotateZ(rotated[i], angle * 0.7);
        }

        int edges[12][2] = {
            {0,1}, {1,2}, {2,3}, {3,0}, {4,5}, {5,6},
            {6,7}, {7,4}, {0,4}, {1,5}, {2,6}, {3,7}
        };

        for (int e = 0; e < 12; e++) {
            Point2D p1 = project(rotated[edges[e][0]]);
            Point2D p2 = project(rotated[edges[e][1]]);

            int x1 = (int)p1.x, y1 = (int)p1.y;
            int x2 = (int)p2.x, y2 = (int)p2.y;

            int dx = x2 - x1, dy = y2 - y1;
            int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

            for (int i = 0; i <= steps; i++) {
                int x = x1 + dx * i / (steps ? steps : 1);
                int y = y1 + dy * i / (steps ? steps : 1);
                if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                    buffer[y * WIDTH + x] = '*';
                }
            }
        }

        printf("\033[2J\033[H");
        for (int i = 0; i < HEIGHT; i++) {
            printf("%.*s\n", WIDTH, &buffer[i * WIDTH]);
        }

        angle += 0.05;
        usleep(50000);
    }

    return 0;
}