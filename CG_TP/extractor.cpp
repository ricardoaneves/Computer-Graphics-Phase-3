#include "extractor.h"

void extractor(vector<First*>& files, vector<coords>& triangles)
{
    int n = 0;
    double triple[3];

    for (vector<First*>::iterator it = files.begin(); it != files.end(); it++) {

        First* first = *it;
        ifstream file;
        file.open(first->file);
        string line;

        if (file.is_open()) {

            while (getline(file, line)) {

                string temp;
                for (int i = 0; i <= line.length(); i++) {

                    if (line[i] == ' ' || line[i] == '\0') {

                        triple[n] = stod(temp);
                        temp.clear();
                        n++;

                    }
                    else
                        temp.push_back(line[i]);

                }

                coords point = make_tuple(triple[0], triple[1], triple[2]);
                triangles.push_back(point);
                first->npoints++;

                n = 0;

            }
        }

        coords end = make_tuple(12345, 12345, 12345);
        triangles.push_back(end);
        triangles.push_back(end);
        triangles.push_back(end);

    }
}