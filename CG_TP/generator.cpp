#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


void plane(char* l, char* fileName)
{
    double length = atof(l);

    ofstream file;
    file.open(fileName, ios::app);

    if (file.is_open()) {
        file << "" << (-length/2) << " 0 " << (-length/2) << "\n";
        file << "" << (-length/2) << " 0 " << (length/2) << "\n";
        file << "" << (length/2) << " 0 " << (length/2) << "\n";

        file << "" << (-length/2) << " 0 " << (-length/2) << "\n";
        file << "" << (length/2) << " 0 " << (length/2) << "\n";
        file << "" << (length/2) << " 0 " << (-length/2) << "\n";
    }

    file.close();
}


void box(char* len, char* hei, char* wid, int div, char* fileName)
{
    double length = atof(len);
    double height = atof(hei);
    double width = atof(wid);

    double x, y, z;

    double divX = length/div;
    double divY = height/div;
    double divZ = width/div;

    ofstream file;
    file.open(fileName, ios::app);

    if (file.is_open()) {

        z = width/2;
        for (int i = 0; i < div; i++) {
            x = -length/2;
            for (int j = 0; j < div; j++) {
                file << "" << x << " 0 " << (z - divZ) << "\n";
                file << "" << (x + divX) << " 0 " << z << "\n";
                file << "" << x << " 0 " << z << "\n";

                file << "" << x << " 0 " << (z - divZ) << "\n";
                file << "" << (x + divX) << " 0 " << (z - divZ) << "\n";
                file << "" << (x + divX) << " 0 " << z << "\n";

                x += divX;
            }
            z -= divZ;
        }

        x = -length/2;
        z = -width/2;
        for (int i = 0; i < div; i++) {
            y = height;
            for (int j = 0; j < div; j++) {
                file << "" << x << " " << y << " " << z << "\n";
                file << "" << x << " " << (y - divY) << " " << z << "\n";
                file << "" << x << " " << (y - divY) << " " << (z + divZ) << "\n";

                file << "" << x << " " << y << " " << z << "\n";
                file << "" << x << " " << (y - divY) << " " << (z + divZ) << "\n";
                file << "" << x << " " << y << " " << (z + divZ) << "\n";

                y -= divY;
            }
            z += divZ;
        }

        x = -length/2;
        z = width/2;
        for (int i = 0; i < div; i++) {
            y = height;
            for (int j = 0; j < div; j++) {
                file << "" << x << " " << y << " " << z << "\n";
                file << "" << x << " " << (y - divY) << " " << z << "\n";
                file << "" << (x + divX) << " " << y << " " << z << "\n";

                file << "" << x << " " << (y - divY) << " " << z << "\n";
                file << "" << (x + divX) << " " << (y - divY) << " " << z << "\n";
                file << "" << (x + divX) << " " << y << " " << z << "\n";

                y -= divY;
            }
            x += divX;
        }

        x = -length/2;
        z = -width/2;
        for (int i = 0; i < div; i++) {
            y = height;
            for (int j = 0; j < div; j++) {
                file << "" << x << " " << y << " " << z << "\n";
                file << "" << (x + divX) << " " << y << " " << z << "\n";
                file << "" << (x + divX) << " " << (y - divY) << " " << z << "\n";

                file << "" << x << " " << y << " " << z << "\n";
                file << "" << (x + divX) << " " << (y - divY) << " " << z << "\n";
                file << "" << x << " " << (y - divY) << " " << z << "\n";

                y -= divY;
            }
            x += divX;
        }

        x = length/2;
        z = width/2;
        for (int i = 0; i < div; i++) {
            y = height;
            for (int j = 0; j < div; j++) {
                file << "" << x << " " << y << " " << z << "\n";
                file << "" << x << " " << (y - divY) << " " << z << "\n";
                file << "" << x << " " << (y - divY) << " " << (z - divZ) << "\n";

                file << "" << x << " " << y << " " << z << "\n";
                file << "" << x << " " << (y - divY) << " " << (z - divZ) << "\n";
                file << "" << x << " " << y << " " << (z - divZ) << "\n";

                y -= divY;
            }
            z -= divZ;
        }

        y = height;
        z = -width/2;
        for (int i = 0; i < div; i++) {
            x = -length/2;
            for (int j = 0; j < div; j++) {
                file << "" << (x + divX) << " " << y << " " << z << "\n";
                file << "" << x << " " << y << " " << z << "\n";
                file << "" << x << " " << y << " " << (z + divZ) << "\n";

                file << "" << (x + divX) << " " << y << " " << z << "\n";
                file << "" << x << " " << y << " " << (z + divZ) << "\n";
                file << "" << (x + divX) << " " << y << " " << (z + divZ) << "\n";

                x += divX;
            }
            z += divZ;
        }
    }

    file.close();
}


void sphere(char* r, char* sl, char* st, char* fileName) {
    int radius = atoi(r);
    int slices = atoi(sl);
    int stacks = atoi(st);

    double alpha = 0;
    double deltaAlpha = (2 * M_PI) / slices;
    double beta = 0;
    double deltaBeta = M_PI / stacks;

    double p1x_S, p1y_S, p1z_S, p2x_S, p2y_S, p2z_S, p3x_S, p3y_S, p3z_S, p4x_S, p4y_S, p4z_S;

    ofstream file;
    file.open(fileName, ios::app);

    if (file.is_open()) {
        for (int i = 0; i < stacks; i++) {
            alpha = 0;
            for (int j = 0; j < slices; j++) {

                p1x_S = radius * sin(beta) * sin(alpha);
                p1y_S = radius * cos(beta);
                p1z_S = radius * sin(beta) * cos(alpha);

                p2x_S = radius * sin(beta + deltaBeta) * sin(alpha);
                p2y_S = radius * cos(beta + deltaBeta);
                p2z_S = radius * sin(beta + deltaBeta) * cos(alpha);

                p3x_S = radius * sin(beta) * sin(alpha + deltaAlpha);
                p3y_S = radius * cos(beta);
                p3z_S = radius * sin(beta) * cos(alpha + deltaAlpha);

                p4x_S = radius * sin(beta + deltaBeta) * sin(alpha + deltaAlpha);
                p4y_S = radius * cos(beta + deltaBeta);
                p4z_S = radius * sin(beta + deltaBeta) * cos(alpha + deltaAlpha);

                file << p1x_S << " " << p1y_S << " " << p1z_S << "\n";
                file << p2x_S << " " << p2y_S << " " << p2z_S << "\n";
                file << p4x_S << " " << p4y_S << " " << p4z_S << "\n";

                file << p1x_S << " " << p1y_S << " " << p1z_S << "\n";
                file << p4x_S << " " << p4y_S << " " << p4z_S << "\n";
                file << p3x_S << " " << p3y_S << " " << p3z_S << "\n";

                alpha += deltaAlpha;
            }
            beta += deltaBeta;
        }
    }
    file.close();
}


void cone(char* r, char* h, char* sl, char* fileName)
{
    double radius = atof(r);
    double height = atof(h);
    double slices = atof(sl);

    double alpha = 0;
    double delta = (2 * M_PI) / slices;

    ofstream file;
    file.open(fileName, ios::app);

    if (file.is_open()) {
        for (int i = 0; i < slices; i++) {
            file << "" << "0" << " 0 " << "0" << "\n";
            file << "" << (radius * sin(alpha + delta)) << " 0 " << (radius * cos(alpha + delta)) << "\n";
            file << "" << (radius * sin(alpha)) << " 0 " << (radius * cos(alpha)) << "\n";

            file << "" << "0 " << height << " 0" << "\n";
            file << "" << (radius * sin(alpha)) << " 0 " << (radius * cos(alpha)) << "\n";
            file << "" << (radius * sin(alpha + delta)) << " 0 " << (radius * cos(alpha + delta)) << "\n";

            alpha += delta;
        }
    }

    file.close();
}

void cylinder(char* radius, char* ht, char* ss, char* fileName)
{
    int r = atoi(radius);
    int height = atoi(ht);
    int slices = atoi(ss);

    double delta = 2 * M_PI / slices;
    double alpha = 0;

    ofstream file;
    file.open(fileName, ios::app);

    if (file.is_open()) {
        for (int i = 0; i < slices; i++) {
            file << "0 0 0" << "\n";
            file << (r * sin(alpha + delta)) << " 0 " << (r * cos(alpha + delta)) << "\n";
            file << (r * sin(alpha)) << " 0 " << (r * cos(alpha)) << "\n";

            file << (r * sin(alpha + delta)) << " " << height << " " << (r * cos(alpha + delta)) << "\n";
            file << (r * sin(alpha)) << " " << height << " " << (r * cos(alpha)) << "\n";
            file << (r * sin(alpha)) << " 0 " << (r * cos(alpha)) << "\n";

            file << (r * sin(alpha + delta)) << " " << height << " " << (r * cos(alpha + delta)) << "\n";
            file << (r * sin(alpha)) << " 0 " << (r * cos(alpha)) << "\n";
            file << (r * sin(alpha + delta)) << " 0 " << (r * cos(alpha + delta)) << "\n";

            file << "0 " << height << " 0" << "\n";
            file << (r * sin(alpha)) << " " << height << " " << (r * cos(alpha)) << "\n";
            file << (r * sin(alpha + delta)) << " " << height << " " << (r * cos(alpha + delta)) << "\n";
            alpha += delta;
        }
    }
    file.close();
}

int main(int argc, char** argv)
{
    // Plane(length, filename)
    if (strcmp(argv[1], "plane") == 0)
        plane(argv[2], argv[3]);

    // Box(length, height, width, divisions, filename)
    if (strcmp(argv[1], "box") == 0) {
        if (argc == 6)
            box(argv[2], argv[3], argv[4], 1, argv[5]);
        if (argc == 7)
            box(argv[2], argv[3], argv[4], atoi(argv[5]), argv[6]);
    }

    // Sphere(radius, slices, stacks, filename)
    if (strcmp(argv[1], "sphere") == 0)
        sphere(argv[2], argv[3], argv[4], argv[5]);

    // Cone(radius, height, slices, filename)
    if (strcmp(argv[1], "cone") == 0)
        cone(argv[2], argv[3], argv[4], argv[5]);

    // Cylinder(radius, height, slices, filename)
    if (strcmp(argv[1], "cylinder") == 0)
        cylinder(argv[2], argv[3], argv[4], argv[5]);

    return 0;
}