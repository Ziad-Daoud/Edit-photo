#include <iostream>
#include <cmath>
#include "Image_Class.h"
using namespace std;

int main()
{
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    string filename;
    getline(cin, filename);
    Image image(filename);

    cout << "RESIZE BY:" << endl;
    cout << "1|New dimensions" << endl;
    cout << "2|Scale factor" << endl;
    cout << "Your choice: (1/2) ";
    int answer;
    cin >> answer;

    int new_width, new_height;

    while (true)
    {
        if (answer != 1 && answer != 2)
        {
            cout << "Invalid choice. Pls enter 1 or 2: ";
            cin >> answer;
            continue;
        }

        if (answer == 1)
        {
            cout << "Enter new width: ";
            while (true)
            {
                cin >> new_width;
                if (new_width <= 0)
                {
                    cout << "Invalid input! new_width must be > 0, pls enter again: ";
                    continue;
                }
                break;
            }

            cout << "Enter new height: ";
            while (true)
            {
                cin >> new_height;
                if (new_height <= 0)
                {
                    cout << "Invalid input! new_height must be > 0, pls enter again: ";
                    continue;
                }
                break;
            }
        }
        else if (answer == 2)
        {
            double scale_factor;
            cout << "Enter scale factor: ";
            while (true)
            {
                cin >> scale_factor;
                if (scale_factor <= 0)
                {
                    cout << "Invalid input! scale_factor must be > 0, pls enter again: ";
                    continue;
                }
                break;
            }

            new_width = round(image.width * scale_factor);
            new_height = round(image.height * scale_factor);
        }
        break;
    }

    Image resized_image(new_width, new_height);

    double x_ratio = 1.0 * image.width / new_width;
    double y_ratio = 1.0 * image.height / new_height;

    for (int i = 0; i < new_width; i++)
    {
        for (int j = 0; j < new_height; j++)
        {
            int sourceX_coordinate = i * x_ratio;
            int sourceY_coordinate = j * y_ratio;

            for (int k = 0; k < image.channels; k++)
            {
                resized_image(i, j, k) = image(sourceX_coordinate, sourceY_coordinate, k);
            }
        }
    }

    string newfilename;
    cout << "Pls enter new image name to save: ";
    cin >> newfilename;
    resized_image.saveImage(newfilename);

    cout << "Image resized and saved successfully!" << endl;
    return 0;
}

