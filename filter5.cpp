#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

int main()
{
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: \n";
    string filename;
    getline(cin, filename);
    cout << "Horizontal or Vertical flip? (h/v): \n";
    char flipDirection;
    cin >> flipDirection;
    Image image(filename);
    if (flipDirection == 'h')
    {
        for (int i = image.width - 1; i >= image.width / 2; i--)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    swap(image(i, j, k), image(image.width - i - 1, j, k));
                }
            }
        }
    }
    else if (flipDirection == 'v')
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = image.height - 1; j >= image.height / 2; j--)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    swap(image(i, j, k), image(i, image.height - j - 1, k));
                }
            }
        }
    }
    else
    {
        cout << "Invalid input. Please enter 'h' for horizontal flip or 'v' for vertical flip." << endl;
        return 1;
    }

    image.saveImage(filename);

    return 0;
}
