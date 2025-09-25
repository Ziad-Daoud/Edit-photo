#include <iostream>
#include "Image_Class.h"
using namespace std;

int main()
{
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    string filename;
    getline(cin, filename);
    Image image(filename);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int avg = 0;
            for (int k = 0; k < image.channels; k++)
            {
                avg += image(i, j, k);
            }
            avg /= image.channels;
            if (avg > 127)
            {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
            else if (avg <= 127)
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
        }
    }
    image.saveImage(filename);

    return 0;
}
