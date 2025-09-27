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

    cout << "RESIZE BY:" << endl;
    cout << "1|New dimensions" << endl;
    cout << "2|Scale factor" << endl;
    cout << "Your choice: (1/2) ";
    int answer;
    cin >> answer;

    int new_width, new_height;

    if (answer == 1)
    {
        cout << "Enter new width: ";
        while (true)
        {
            cin >> new_width;
            if (new_width <= 0)
            {
                cout << "Invalid input new_width must be > 0, pls enter again: ";
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
                cout << "Invalid input new_height must be > 0, pls enter again: ";
                continue;
            }
            break;
        }
    }
    else if (answer == 2)
    {
        double scale_factor;
        cout << "Enter scale factor: ";
        cin >> scale_factor;

        if (scale_factor <= 0)
        {
            cout << "Invalid scale factor!" << endl;
            return 1;
        }

        new_width = static_cast<int>(image.width * scale_factor);
        new_height = static_cast<int>(image.height * scale_factor);
    }
    else
    {
        cout << "Wrong input" << endl;
        return 1;
    }

    // Create new image
    Image resized_image(new_width, new_height);

    // Ratios
    double x_ratio = static_cast<double>(image.width) / new_width;
    double y_ratio = static_cast<double>(image.height) / new_height;

    // Nearest Neighbor Interpolation
    for (int i = 0; i < new_width; i++)
    {
        for (int j = 0; j < new_height; j++)
        {
            int src_x = static_cast<int>(i * x_ratio);
            int src_y = static_cast<int>(j * y_ratio);

            for (int k = 0; k < image.channels; k++)
            {
                resized_image(i, j, k) = image(src_x, src_y, k);
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
