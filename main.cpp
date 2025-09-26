#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#include "Image_Class.h"

Image image;// Image object
string filename;
    

Image Filter1() {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int bixcolor = 0;
            for (int k = 0; k < image.channels; k++) {
                bixcolor += image(i, j, k);
            }
            bixcolor /= 3;
            for (int k = 0; k < image.channels; k++) {
                image(i, j, k) = bixcolor;
            }
        }
    }
    return image;
}

Image Filter2(){
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            unsigned avg = 0;
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
    return image;
}

Image Filter3(){
     for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }

    return image;
}

Image Filter5(){
    cout << "Horizontal or Vertical flip? (h/v): ";
    char flipDirection;
    cin >> flipDirection;
    if (flipDirection == 'h'|| flipDirection == 'H')
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
    else if (flipDirection == 'v'|| flipDirection == 'V')
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
    }
    return image;
}

Image Filter7() {
    cout << "Choose mode (0 for dark, 1 for light): ";
    int choice; 
    cin >> choice;

    if (choice==1){
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                unsigned int bixcolor = 0;
                for (int k = 0; k < image.channels; k++) {
                    bixcolor = image(i, j, k);
                    if (bixcolor * 1.5 >= 255) {
                        bixcolor = 255;
                    } else {
                    bixcolor *= 1.5;
                    image(i, j, k) = bixcolor;
                    }
                }
            }
        }
    }else if (choice==0){
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                unsigned int bixcolor = 0;
                for (int k = 0; k < image.channels; k++) {
                    bixcolor = image(i, j, k);
                    bixcolor *= 0.5;
                    image(i, j, k) = bixcolor;
                }
            }
        }
    }
    
    return image;
}


int main(){
    cout << "-----------------------------------------" << endl;
    cout << "|Welcome to Image Processing Application|" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Enter image name: ";
    cin >> filename;
    try{
        image = Image(filename);
    } catch (const std::invalid_argument& e){
        cout << "This image format is not supported." << endl;
        return -1;
    }catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }    
    
    
    cout << "Choose filter's number to apply: " << endl;
    cout << "1|Grayscale" << endl;
    cout << "2|B&W" << endl;
    cout << "3|Invert      " << endl;
    cout << "5|Flip        " << endl;
    cout << "7|Brightness" << endl;
    cout << "Filter number: ";
    int filterNum;
    cin >> filterNum;

    if (filterNum==1){
        image = Filter1();
    }else if (filterNum==2){
        image = Filter2();
    }else if(filterNum==5){
        image = Filter5();
    }else if (filterNum==7){
        image = Filter7();
    }

    string newfilename;
    cout << "Pls enter new image name to save: ";
    cin >> newfilename;
    image.saveImage(newfilename);
    system(newfilename.c_str());
    return 0;

}
