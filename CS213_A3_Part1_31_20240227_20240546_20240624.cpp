// CS213 - Assignment 1 - Part 1

// Ziad Yahia Zakria - 20240227
// Mahmoud Ahmed Abdalla - 20240546
// Mina Hany Atef - 20240624

#include <iostream>
#include <cstdlib>
using namespace std;
#include "Image_Class.h"

Image image;
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
    cout << "chose\n";
    cout << "1 One color\n";
    cout << "2 Many colors\n";
    int frameType;
    cin >> frameType;
    bool isCheckerboard = (frameType == 2);
    if (isCheckerboard) {
        cout << "Colors:-" << endl;
        cout << "1|Black & White   2|Blue & Yellow" << endl;
        cout << "3|Red & Black     4|Green & White" << endl;
        cout << "Choose color combination: ";
        int colorChoice;
        cin >> colorChoice;
        if (colorChoice==1){
            for (int i = 0; i < 51; i++){
                for (int j = 0; j < image.height; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;
                    }
                    else {
                        image(i, j, 0) = 255;
                        image(i, j, 1) = 255;
                        image(i, j, 2) = 255;
                    }
                }
            }
            for (int i = image.width-1 ; i > image.width-51; i--){
                for (int j = 0; j < image.height; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;
                    }
                    else {
                        image(i, j, 0) = 255;
                        image(i, j, 1) = 255;
                        image(i, j, 2) = 255;
                    }
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = 0; j < 51; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;
                    }
                    else {
                        image(i, j, 0) = 255;
                        image(i, j, 1) = 255;
                        image(i, j, 2) = 255;
                    }
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = image.height-1; j > image.height-51; j--){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;
                    }
                    else {
                        image(i, j, 0) = 255;
                        image(i, j, 1) = 255;
                        image(i, j, 2) = 255;
                    }
                }
            }
        }else if (colorChoice==2){
            for (int i = 0; i < 51; i++){
                for (int j = 0; j < image.height; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 255;
                    }
                    else {
                        image(i, j, 0) = 245;
                        image(i, j, 1) = 188;
                        image(i, j, 2) = 17;
                    }
                }
            }
            for (int i = image.width-1 ; i > image.width-51; i--){
                for (int j = 0; j < image.height; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 255;
                    }
                    else {
                        image(i, j, 0) = 245;
                        image(i, j, 1) = 188;
                        image(i, j, 2) = 17;
                    }
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = 0; j < 51; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 255;
                    }
                    else {
                        image(i, j, 0) = 245;
                        image(i, j, 1) = 188;
                        image(i, j, 2) = 17;
                    }
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = image.height-1; j > image.height-51; j--){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 255;
                    }
                    else {
                        image(i, j, 0) = 245;
                        image(i, j, 1) = 188;
                        image(i, j, 2) = 17;
                    }
                }
            }
        }else if (colorChoice==3){
            for (int i = 0; i < 51; i++){
                for (int j = 0; j < image.height; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;
                    }
                    else {
                        image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                    }
                }
            }
            for (int i = image.width-1 ; i > image.width-51; i--){
                for (int j = 0; j < image.height; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;
                    }
                    else {
                        image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                    }
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = 0; j < 51; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;
                    }
                    else {
                        image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                    }
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = image.height-1; j > image.height-51; j--){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;
                    }
                    else {
                        image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                    }
                }
            }
        }else if (colorChoice==4){
            for (int i = 0; i < 51; i++){
                for (int j = 0; j < image.height; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
                    }
                    else {
                        image(i, j, 0) = 0;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                    }
                }
            }
            for (int i = image.width-1 ; i > image.width-51; i--){
                for (int j = 0; j < image.height; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
                    }
                    else {
                        image(i, j, 0) = 0;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                    }
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = 0; j < 51; j++){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
                    }
                    else {
                        image(i, j, 0) = 0;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                    }
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = image.height-1; j > image.height-51; j--){
                    int photo = (i / 50 + j / 50) % 2;
                    if (photo == 0) {
                        image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
                    }
                    else {
                        image(i, j, 0) = 0;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                    }
                }
            }
        }
    }else {
        cout << "Colors:-" << endl;
        cout << "1|Black   2|White" << endl;
        cout << "3|Yellow  4|Blue" << endl;
        cout << "5|Red     6|Green" << endl;
        cout << "Choose color: ";
        int colorChoice;
        cin >> colorChoice;
        if (colorChoice==1){
            for (int i = 0; i < 51; i++){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                }
            }
            for (int i = image.width-1 ; i > image.width-51; i--){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = 0; j < 51; j++){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = image.height-1; j > image.height-51; j--){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
            
                }
            }
        }else if (colorChoice==2){
            for (int i = 0; i < 51; i++){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
                }
            }
            for (int i = image.width-1 ; i > image.width-51; i--){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = 0; j < 51; j++){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = image.height-1; j > image.height-51; j--){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
            
                }
            }
        }else if (colorChoice==3){
            for (int i = 0; i < 51; i++){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 245;
                    image(i, j, 1) = 188;
                    image(i, j, 2) = 17;
                }
            }
            for (int i = image.width-1 ; i > image.width-51; i--){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 245;
                    image(i, j, 1) = 188;
                    image(i, j, 2) = 17;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = 0; j < 51; j++){
                    image(i, j, 0) = 245;
                    image(i, j, 1) = 188;
                    image(i, j, 2) = 17;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = image.height-1; j > image.height-51; j--){
                    image(i, j, 0) = 245;
                    image(i, j, 1) = 188;
                    image(i, j, 2) = 17;
                }
            }
        }else if (colorChoice==4){
            for (int i = 0; i < 51; i++){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 255;
                }
            }
            for (int i = image.width-1 ; i > image.width-51; i--){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 255;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = 0; j < 51; j++){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 255;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = image.height-1; j > image.height-51; j--){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 255;
            
                    }
                }
        }else if (colorChoice==5){
            for (int i = 0; i < 51; i++){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                }
            }
            for (int i = image.width-1 ; i > image.width-51; i--){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = 0; j < 51; j++){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = image.height-1; j > image.height-51; j--){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                }
            }
        }else if (colorChoice==6){
            for (int i = 0; i < 51; i++){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                }
            }
            for (int i = image.width-1 ; i > image.width-51; i--){
                for (int j = 0; j < image.height; j++){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = 0; j < 51; j++){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                }
            }
            for (int i = 11 ; i < image.width-50; i++){
                for (int j = image.height-1; j > image.height-51; j--){
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 0;
                }
            }
            
        }
    }
    return image;
}   
    
Image Filter11(int new_width, int new_height, Image resize) {
        
    // Create new image
    Image resized_image(new_width, new_height);

    // Ratios
    double x_ratio = static_cast<double>(resize.width) / new_width;
    double y_ratio = static_cast<double>(resize.height) / new_height;

    // Nearest Neighbor Interpolation
    for (int i = 0; i < new_width; i++)
    {
        for (int j = 0; j < new_height; j++)
        {
            int src_x = static_cast<int>(i * x_ratio);
            int src_y = static_cast<int>(j * y_ratio);

            for (int k = 0; k < resize.channels; k++)
            {
                resized_image(i, j, k) = resize(src_x, src_y, k);
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
    cout << "1|Grayscale   2|B&W" << endl;
    cout << "3|Invert      4|Merge" << endl;
    cout << "5|Flip        " << endl;
    cout << "7|Brightness  8|Crop" << endl;
    cout << "9|Frame       " << endl;
    cout << "11|Resize" << endl;
    cout << "Filter number: ";
    int filterNum;
    cin >> filterNum;

    if (filterNum==1){
        image = Filter1();
    }else if (filterNum==2){
        image = Filter2();
    }else if (filterNum==3){
        image = Filter3();
    }else if(filterNum==4){
        image = Filter4();
    }else if(filterNum==5){
        image = Filter5();
    }else if (filterNum==7){
        image = Filter7();
    }else if (filterNum==8){
        image = Filter8();
    }else if (filterNum==9){
        image = Filter9();
    }else if (filterNum==11){
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
        image = Filter11(new_width, new_height, image);
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
        image = Filter11(new_width, new_height, image);
    }
    else
    {
        cout << "Wrong input" << endl;
        return 1;
    }
    
    }
    string newfilename;
    cout << "Pls enter new image name to save: ";
    cin >> newfilename;
    image.saveImage(newfilename);
    system(newfilename.c_str());
    return 0;
}