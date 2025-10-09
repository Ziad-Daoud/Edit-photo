#include <iostream>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

int main()
{
    cout << "Enter image filename (with extension .jpg, .png, .bmp, .tga): ";
    string filename;
    getline(cin, filename);

    Image image(filename);

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int newR = image(i, j, 0) + 40;
            if (newR > 255)
            {
                newR = 255;
            }
            int newG = image(i, j, 1) - 30;
            if (newG < 0)
            {
                newG = 0;
            }
            int newB = image(i, j, 2) + 60;
            if (newB > 255)
            {
                newB = 255;
            }

            image(i, j, 0) = newR;
            image(i, j, 1) = newG;
            image(i, j, 2) = newB;
        }
    }

    cout << "Enter new filename to save the purple version: ";
    string outname;
    cin >> outname;

    image.saveImage(outname);

    return 0;
}
