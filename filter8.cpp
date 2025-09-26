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
    int x, y = 0;
    cout << "Pls enter the starting point (upper left corner of the part to keep)\n";
    cout << "x: ";
    while (true)
    {
        cin >> x;
        if (x < 0)
        {
            cout << "Invalid input x must be >= 0, pls enter again: ";
            continue;
        }
        break;
    }

    cout << "y: ";
    while (true)
    {
        cin >> y;
        if (y < 0)
        {
            cout << "Invalid input y must be >= 0, pls enter again: ";
            continue;
        }
        break;
    }

    int width, height = 0;
    cout << "Pls enter the width and height of the part to keep\n";
    cout << "width: ";
    while (true)
    {
        cin >> width;
        if (width < 0)
        {
            cout << "Invalid input width must be >= 0, pls enter again: ";
            continue;
        }
        break;
    }
    cout << "height: ";
    while (true)
    {
        cin >> height;
        if (height < 0)
        {
            cout << "Invalid input height must be >= 0, pls enter again: ";
            continue;
        }
        break;
    }
    if (x + width > image.width || y + height > image.height)
    {
        cout << "Error: crop area exceeds image boundaries!" << endl;
        return 1;
    }

    Image image2(width, height);

    for (int i = x; i < x + width; i++)
    {
        for (int j = y; j < y + height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                image2(i - x, j - y, k) = image(i, j, k);
            }
        }
    }
    string newfilename;
    cout << "Pls enter new image name to save: ";
    cin >> newfilename;
    image2.saveImage(newfilename);
    system(newfilename.c_str());

    return 0;
}
