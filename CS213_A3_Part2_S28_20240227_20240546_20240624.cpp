// CS213 - Assignment 1 - Part 2

// Ziad Yahia Zakria - 20240227 - filter 1 - filter 4 - filter 7 - filter 10 - filter 13
// Mahmoud Ahmed Abdullah Hassanin - 20240546 - filter 2 - filter 5 - filter 8 - filter 11 - filter 16
// Mina Hany Atef - 20240624 - filter 3 - filter 6 - filter 9 - filter 12 - filter 15
//https://docs.google.com/document/d/1EmZm2uBw_T1K9sXmDeZoLfR4hNmodrU0LY2726kyamI/edit?usp=sharing
//https://img.plantuml.biz/plantuml/svg/hLTDRziu4BqRy7yOz90wMxiR-Ti2Tb5l4ZS2yeKus1wA7XY9aTbGf41IIPmY-zjtA5anNJks0Ji7GPwXvhsP8TymNxGXocG9hrOCCvp2w7WOG92GcCAraY7LcedOllwaeQbMgXNzm4HA54aW9U43hXkRANwdq4r4pAcx8kH4ww4nYjrbXWQX56FsGk78NIDaH3LDeRbWLKGyMAlNSQrwGYBvP0dT4wwffVCH_h9_45mClvx20LmCWyl2LAtayBDaVbKh00suPvmAab3mGPl8zpLo4t7XUsAHcQ232LCO9fJ54-DQmWaHWdBjsfYDVq8CGMCcD8i5ZUn2zOVrVohmQuVkZzKi5fOat-Piwf2SELHcw_vR2Ap98oqCCZDfPaOh8GuEyVUTbBpuAARccZrJNdikWQRbIpZ3-ZsfWshbjLeHqb2COunCGDuNbAkLCo8YJdLH4GZ-l08qG6eHW8HsBq7jyyyqhiFdLDZdNPBYqyG4aw2ur8QrJIqQTq6OAFhs2H9yhnsMPLzcODTMAoTCfvnCDIHKP7NWaaGpDdKWQSePaWidKbDXDuAXgfxNJUFkrHatYoJcUsiKdD-UteoXrdvkGwnOT5ZkiDaHW0-ZF9p-OFbQnaK6XTKhah1fM1BJ6ajYp2GlMjwGHyaYk-BLFdvBR1R2UefNy7pugZ39aDZ31k1oNWHkxWxST82RFlp3CM4yPTycp6m0R-qEtdB0M_YfUAJAmB7aKkdruEtTmTiEUDk72whidhO1Dc1tTiVkEDWT7qQSfLj1TtU7xZhGNHzkf25ckxnxkuFt7F0UxZPbHKzOtJYMmgX2jjvdqD-TGTzXqFVXMCdjAZ_O7NhWG0zy64QH7NGZd7iRJfftj0U1EN8LviY7qmYt-marEDQP51i8x4FX5YGEDUw6QlPYAp0RBci9x47fF5Vgl5phChKL-1wKpdEbpaEj6sU2vnD_gutlxK7lF5VmF5Iyonm_pLIwQSvuUv0ypzKy3qNlYaTm--yYyElYNBuvFH_U1bUNuxFWUboEvFpMq6ZyFRltuVL5syFxPfwFQh-y4xWnpyaKBr1mBr7rPzE-ZFmHrV09F9X8nLwmBGHlDTWaWPSDl3gKixxnVSAYY8eVZVa8BSVnagzL-bhBldP1os8srs9sbh_jbhxkigzN-dhBlluSixKMSx3yhPMGDq5QzdfltXKrieUl16wlB_2AIjcj-tOGbhsT8ZRU6x94WBr3i73BtdNMr7YmhXOjY_bkszUrPqCPs_F0AognhhSREj2P1rvHn7xfwx_Nl2zuJF7_oFy1
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#include "Image_Class.h"

Image image;
string filename;

Image Filter1(){
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

Image Filter6(){
    Image photo(image.height, image.width);
    cout << "Choose rotate angle:" << endl;
    cout << "1|Rotate 90°     2|Rotate 180°     3|Rotate 270°" << endl;
    int angle;
    cin >> angle;
    if (angle == 1) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
               photo(j, image.width - i - 1, k) = image(i, j, k);
            }
        }
    }
    }
    else if (angle == 2) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
              photo(image.width - i - 1, image.height - j - 1, k) = image(i, j, k);
            }
        }
    }
    }
    else if (angle == 3) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                photo(image.height - j - 1, i, k) = image(i, j, k);
            }
        }
    }
}
    else {
        cout << "Invalid angle!" << endl;
    }
    return photo;
}

Image Filter7(){
    cout << "Choose mode (D/d) for dark, (L/l) for light: ";
    char choice; 
    cin >> choice;

    if (choice=='L' || choice=='l'){
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                unsigned int pixcolor = 0;
                for (int k = 0; k < image.channels; k++) {
                    pixcolor = image(i, j, k);
                    if (pixcolor * 1.5 >= 255) {
                        pixcolor = 255;
                    } else {
                    pixcolor *= 1.5;
                    image(i, j, k) = pixcolor;
                    }
                }
            }
        }
    }else if (choice=='D' || choice=='d'){
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                unsigned int pixcolor = 0;
                for (int k = 0; k < image.channels; k++) {
                    pixcolor = image(i, j, k);
                    pixcolor *= 0.5;
                    image(i, j, k) = pixcolor;
                }
            }
        }
    }
    
    return image;
}

Image Filter8(){
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
    return image2;
}

Image Filter9(){
    cout << "Choose frame type:\n";
    cout << "1| Simple\n";
    cout << "2| Decoration\n";
    int frameType;
    cin >> frameType;
    bool isCheckerboard = (frameType == 2);
    if (isCheckerboard) {
        for (int i = 0; i < 61; i++){
            for (int j = 0; j < image.height; j++){
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
        }
        for (int i = image.width-1 ; i > image.width-61; i--){
            for (int j = 0; j < image.height; j++){
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
        }
        for (int i = 61 ; i < image.width-60; i++){
            for (int j = 0; j < 61; j++){
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
        }
        for (int i = 0 ; i < image.width-60; i++){
            for (int j = image.height-1; j > image.height-61; j--){
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 255;
            }
        }
        for (int i = 46; i < 61; i++){
            for (int j = 0; j < image.height; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = image.width-46 ; i > image.width-61; i--){
            for (int j = 0; j < image.height; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = 0 ; i < image.width; i++){
            for (int j = 46; j < 61; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = 0 ; i < image.width; i++){
            for (int j = image.height-46; j > image.height-61; j--){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }


        for (int i = 0; i < 121; i++){
            for (int j = 101; j < 116; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = image.width-1; i > image.width - 121; i--){
            for (int j = 101; j < 116; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = 101; i < 116; i++){
            for (int j = 0; j < 121; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = image.width-101; i > image.width - 116; i--){
            for (int j = 0; j < 121; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = 0; i < 121; i++){
            for (int j = image.height-101; j > image.height-116; j--){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = image.width-1; i > image.width - 121; i--){
            for (int j = image.height-101; j > image.height-116; j--){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = 101; i < 116; i++){
            for (int j = image.height-1; j > image.height-121; j--){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = image.width-101; i > image.width-116; i--){
            for (int j = image.height-1; j > image.height-121; j--){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }

        for (int i = 0; i < 191; i++){
            for (int j = 171; j < 186; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = image.width-1; i > image.width - 191; i--){
            for (int j = 171; j < 186; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = 171; i < 186; i++){
            for (int j = 0; j < 191; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = image.width-171; i > image.width - 186; i--){
            for (int j = 0; j < 191; j++){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = 0; i < 191; i++){
            for (int j = image.height-171; j > image.height-186; j--){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = image.width-1; i > image.width - 191; i--){
            for (int j = image.height-171; j > image.height-186; j--){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = 171; i < 186; i++){
            for (int j = image.height-1; j > image.height-191; j--){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }
        for (int i = image.width-171; i > image.width-186; i--){
            for (int j = image.height-1; j > image.height-191; j--){
                image(i, j, 0) = 245;
                image(i, j, 1) = 188;
                image(i, j, 2) = 17;
            }
        }

        }else {
            for (int i = 0; i < 61; i++){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 245;
                    image(i, j, 1) = 188;
                    image(i, j, 2) = 17;
                }
            }
            for (int i = image.width-1 ; i > image.width-61; i--){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 245;
                    image(i, j, 1) = 188;
                    image(i, j, 2) = 17;
                }
            }
            for (int i = 61 ; i < image.width-60; i++){
                for (int j = 0; j < 61; j++){
                    image(i, j, 0) = 245;
                    image(i, j, 1) = 188;
                    image(i, j, 2) = 17;
                }
            }
            for (int i = 61 ; i < image.width-60; i++){
                for (int j = image.height-1; j > image.height-61; j--){
                    image(i, j, 0) = 245;
                    image(i, j, 1) = 188;
                    image(i, j, 2) = 17;
                }
            }
        }
    return image;
}   
    
Image Filter10(){
    image = Filter1();

    int Gx[3][3] = {
        {-1, 0, +1},
        {-2, 0, +2},
        {-1, 0, +1}
    };

    int Gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        {+1, +2, +1}
    };

    Image output(image.width, image.height);
    for (int x = 1; x < image.width - 1; x++) {
        for (int y = 1; y < image.height - 1; y++) {
            double sumX = 0.0;
            double sumY = 0.0;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int pixel = image(x + i, y + j,0);
                    sumX += pixel * Gx[i + 1][j + 1];
                    sumY += pixel * Gy[i + 1][j + 1];
                }
            }

            double magnitude = sqrt(sumX * sumX + sumY * sumY);
            
            int edgeVal;

            if (magnitude > 100) {
                 edgeVal = 0;
            } else {
                 edgeVal = 255;
            }

            for (int c = 0; c < image.channels; c++) {
                output(x, y, c) = edgeVal;
            }
        }
    }
    image = output;

    return image;
}

Image Filter11(int new_width, int new_height, Image resize){

    Image resized_image(new_width, new_height);

    double x_ratio = 1.0 * resize.width / new_width;
    double y_ratio = 1.0 * resize.height / new_height;

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
    return resized_image;
}

Image Filter4(){

    cout << "Enter second image name: ";
    string filename2;
    cin >> filename2;
    Image image2;
    try{
        image2 = Image(filename2);
    } catch (const std::invalid_argument& e){
        cout << "This image format is not supported." << endl;
    }catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    if (image.width == image2.width && image.height == image2.height){
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < image.channels; k++) {
                    image(i, j, k) = (image(i, j, k) + image2(i, j, k)) / 2;
                }
            }
        }
    } else {
        image2 = Filter11(image.width, image.height, image2);
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < image.channels; k++) {
                    image(i, j, k) = (image(i, j, k) + image2(i, j, k)) / 2;
                }
            }
        }
    }
    return image;
}

Image Filter12(){
        int n = 3;  
    int count = ((2 * n) + 1) * ((2 * n) + 1);  

    Image photo(image.width, image.height);

    for (int y = n; y < image.height - n; ++y) {
        for (int x = n; x < image.width - n; ++x) {
            for (int k = 0; k < 3; ++k) {  
                int sum = 0;
                for (int ky = -n; ky <= n; ++ky) {
                    for (int kx = -n; kx <= n; ++kx) {
                        int ny = y + ky;
                        int nx = x + kx;
                        sum += image(nx, ny, k); 
                    }
                }
                photo(x, y, k) = sum / count;
            }
        }
    }

    return photo;
}

Image Filter13(){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            image(i, j, 0) = (image(i, j, 0)+255)/2;
            image(i, j, 1) = (image(i, j, 1)+255)/2;
            image(i, j, 2) = (image(i, j, 2)+183)/2;
        }
    }
    return image;
}

int randomBetween(int min, int max) {
    return rand() % (max - min + 1) + min;
}

Image Filter15(){

    Image photo = image;

    int Space = 4; 

    for (int j = 0; j < photo.height; j += Space) {
        for (int i = 0; i < photo.width; ++i) {
            for (int k = 0; k < 3; ++k) { 
                if (photo(i, j, k) > 64) {
                    photo(i, j, k) = min(photo(i, j, k) + randomBetween(192, 255), 255);
                }
            }
        }
    }
    return photo;
}

Image Filter16(){
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
    return image;
}

int main(){
    cout << "-----------------------------------------" << endl;
    cout << "|Welcome to Image Processing Application|" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "You can exit by enter (E/e)" << endl;
    do {
        try{
            cout << "Enter image name: ";
            cin >> filename;
            if (filename == "E" || filename == "e") {
                cout << "Are you sure you want to exit? (Y/N): ";
                char confirm; 
                cin >> confirm;
                if (confirm == 'Y' || confirm == 'y') {
                    cout << "Exiting the program." << endl;
                    return 0;
                } else {
                    cout << "Returning to load image." << endl;
                    continue;
                }
            }
            image = Image(filename);
        }catch (const std::invalid_argument& e){
            cout << "This image format is not supported." << endl;
        }catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;
        }   
    }while (image.imageData == nullptr);

    
    cout << "Choose filter's number to apply: " << endl;
    cout << "1|Grayscale   2|B&W" << endl;
    cout << "3|Invert      4|Merge" << endl;
    cout << "5|Flip        6|Rotate" << endl;
    cout << "7|Brightness  8|Crop" << endl;
    cout << "9|Frame       10|Edge Detection" << endl;
    cout << "11|Resize     12|Blur" << endl;
    cout << "13|Sunlight   14|Night purple" << endl;
    cout << "15|Old TV" << endl;
    cout << "Filter number: ";
    int filterNum;

    do {
        cin >> filterNum;
        if (filterNum==1){
            image = Filter1();
        }else if (filterNum==2){
            image = Filter2();
        }else if (filterNum==3){
            image = Filter3();
        }else if (filterNum==4){
            image = Filter4();
        }else if (filterNum==5){
            image = Filter5();
        }else if (filterNum==6){
            image = Filter6();
        }else if (filterNum==7){
            image = Filter7();
        }else if (filterNum==8){
            image = Filter8();
        }else if (filterNum==9){
            image = Filter9();
        }else if (filterNum==10){
            image = Filter10();
        }else if (filterNum==11){
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
            image = Filter11(new_width, new_height, image);
        }else if (filterNum==12){
            image = Filter12();
        }else if (filterNum==13){
            image = Filter13();
        }else if (filterNum==15){
            image = Filter15();
        }
        else if (filterNum==14){
            image = Filter16();
        }
        else{
            cout << "Invalid filter number!" << endl;
            cout << "Pls enter filter number again: ";
        }
    }while (filterNum<1 || filterNum>15);
    string newfilename;
    Image newimage;
    do {
        try{
            cout << "Pls enter new image name to save: ";
            cin >> newfilename;
            image.saveImage(newfilename);
            newimage= Image (newfilename);
            if (newfilename == "E" || newfilename == "e") {
                cout << "Are you sure you want to exit? (Y/N): ";
                char confirm; 
                cin >> confirm;
                if (confirm == 'Y' || confirm == 'y') {
                    cout << "Exiting the program." << endl;
                    return 0;
                } else {
                    cout << "Returning to save image." << endl;
                    continue;
                }
            }
        }catch (const std::invalid_argument& e){
            cout << "This image format is not supported." << endl;
        }catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;
        }   
    }while (newimage.imageData == nullptr);
    system(newfilename.c_str());
    return 0;
}
