/*
---------------------------------------------------------------------------------------------------------------------------------------
FCAI - Structured Programming - 2024 - Assignment 3 - Part 2
Program Name: Image Filters
Author1: George Ezat Hosni Saeed      | ID: 20231041 | Group B | S25 | filter : 1,4,7,10,16
Author2: Ruth Gad Labeb Gerges        | ID: 20231055 | Group B | S26 | filter : 2,5,8,11,17
Author3: Marco Raafat Zakaria Sawares | ID: 20231129 | Group B | S26 | filter : 3,6,9,12,13
---------------------------------------------------------------------------------------------------------------------------------------
*/
#include "Image_Class.h"
#include <cstdlib>
using namespace std;

// Prototype of Filter Functions
void load_image(Image &image);
void save_image(Image &image);
void displayImage(string name);
void endingFilter();
void validChoice();
//--------------------------------------------------------
void filter_1(Image &image);
void filter_2(Image &image);
void filter_3(Image &image);
//--------------------------------------------------------
void filter_4(Image &image);
Image resize(Image image, double MaxWidth, double MaxHeight);
Image crop(Image image, double minWidth, double minHeight);
void merge(Image &image, Image image2);
//--------------------------------------------------------
void filter_5(Image &image);
//--------------------------------------------------------
void filter_6(Image &image);
Image rotate_image90(Image image);
Image rotate_image270(Image image);
Image rotate_image180(Image image);
//--------------------------------------------------------
void filter_7(Image &image);
Image filter_8(Image image);
Image filter_9(Image image);
Image filter_10(Image image);
Image filter_11(Image image);
Image filter_12(Image image);
void filter_13(Image &image);
void filter_16(Image &image);
void filter_17(Image &image);
//--------------------------------------------------------
int main()
{
    cout << "------------------------\n";
    cout << "Welcome to Image Filters\n";
    cout << "------------------------\n";
    string choice, filter;
    Image loadedImage;
    load_image(loadedImage);
    while (true)
    {
        cout << "--------------------\n";
        cout << "Choose what you want\n";
        cout << "(1) Load a new image\n(2) Apply a filter on the current image\n(3) Save the image\n(4) Exit\n";
        getline(cin, choice);
        if (choice == "1")
        {
            load_image(loadedImage);
        }
        else if (choice == "2")
        {
            while (true)
            {
                cout << "------------------------\n";
                cout << "Choose a filter\n(1) Grayscale Conversion\n(2) Black and White\n(3) Invert Image\n(4) Merge Images\n(5) Flip Image\n";
                cout << "(6) Rotate Image\n(7) Darken and Lighten Image\n(8) Crop images\n(9) Adding a Frame\n(10) Detect Image Edges\n";
                cout << "(11) Resizing Images\n(12) Blur Images\n(13) Sunlight Filter\n(16) Purple Filter\n(17) Infrared Filter\n";
                getline(cin, filter);
                if (filter == "1")
                {
                    filter_1(loadedImage);
                    break;
                }
                else if (filter == "2")
                {
                    filter_2(loadedImage);
                    endingFilter();
                    break;
                }
                else if (filter == "3")
                {
                    filter_3(loadedImage);
                    break;
                }
                else if (filter == "4")
                {
                    filter_4(loadedImage);
                    break;
                }
                else if (filter == "5")
                {
                    filter_5(loadedImage);
                    break;
                }
                else if (filter == "6")
                {
                    filter_6(loadedImage);
                    break;
                }
                else if (filter == "7")
                {
                    filter_7(loadedImage);
                    break;
                }
                else if (filter == "8")
                {
                    loadedImage = filter_8(loadedImage);
                    break;
                }
                else if (filter == "9")
                {
                    loadedImage = filter_9(loadedImage);
                    break;
                }
                else if (filter == "10")
                {
                    loadedImage = filter_10(loadedImage);
                    break;
                }
                else if (filter == "11")
                {
                    loadedImage = filter_11(loadedImage);
                    break;
                }
                else if (filter == "12")
                {
                    loadedImage = filter_12(loadedImage);
                    break;
                }
                else if (filter == "13")
                {
                    filter_13(loadedImage);
                    break;
                }
                else if (filter == "16")
                {
                    filter_16(loadedImage);
                    break;
                }
                else if (filter == "17")
                {
                    filter_17(loadedImage);
                    break;
                }
                else
                {
                    validChoice();
                }
            }
        }
        else if (choice == "3")
        {
            save_image(loadedImage);
        }
        else if (choice == "4")
        {
            cout << "------------------------------\n";
            cout << "Thanks for using Image Filters\n";
            cout << "------------------------------";
            break;
        }
        else
        {
            validChoice();
        }
    }
    return 0;
}
//--------------------------------------------------------
void load_image(Image &image)
{
    string name = "";
    cout << "Please enter image name with extension: ";
    getline(cin, name);
    while (true)
    { // check name and extension are valid
        try
        {
            image.loadNewImage(name);
            cout << "-------------------------\n";
            cout << "Image loaded successfully\n";
            cout << "-------------------------\n";
            break;
        }
        catch (invalid_argument)
        {
            cout << "---------------------------------------\n";
            cout << "Please enter a valid name and extention\n";
            cout << "---------------------------------------\n";
            getline(cin, name);
        }
    }
}
//--------------------------------------------------------
void save_image(Image &image)
{
    string name = "";
    cout << "Enter a name and specify extension (.jpg, .bmp, .png, .tga): ";
    getline(cin, name);
    while (true)
    { // check name and extension are valid
        try
        {
            image.saveImage(name);
            cout << "------------------------\n";
            cout << "Image saved successfully\n";
            cout << "------------------------\n";
            break;
        }
        catch (invalid_argument)
        {
            cout << "---------------------------------------\n";
            cout << "Please enter a valid name and extention\n";
            cout << "---------------------------------------\n";
            getline(cin, name);
        }
    }
    displayImage(name);
}
//--------------------------------------------------------
void displayImage(string name)
{
    string answer;
    cout << "Do you want to display it?(Y,N) ";
    while (true)
    {
        getline(cin, answer);
        answer[0] = toupper(answer[0]);
        if (answer == "Y")
        {
            system(name.c_str());
            break;
        }
        else if (answer == "N")
        {
            cout << "------------------------\n";
            cout << "Thanks for your Patience\n";
            cout << "------------------------\n";
            break;
        }
        else
        {
            cout << "Please enter just Y or N: ";
        }
    }
}
//--------------------------------------------------------
void endingFilter()
{
    cout << "-------------------------------\n";
    cout << "Filter has applied successfully\n";
    cout << "-------------------------------\n";
}
//--------------------------------------------------------
void validChoice()
{
    cout << "---------------------------\n";
    cout << "Please enter a valid choice\n";
    cout << "---------------------------\n";
}
//--------------------------------------------------------
void filter_1(Image &image) // GrayScale Filter
{
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k)
            {
                avg += image(i, j, k);
            }
            avg /= 3; // avg for each pixel = (image(i,j,0) + image(i,j,1) + image(i,j,2))/3
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, k) = avg;
            } // we make all channels of each pixel equals to avg to make the image gray
        }
    }
    endingFilter();
}
//--------------------------------------------------------
void filter_2(Image &image) // Black & White filter
{
    for (int i = 0; i < image.width; i++)
    { // loop on the image
        for (int j = 0; j < image.height; j++)
        {
            unsigned int avg = 0;
            for (int k = 0; k < image.channels; k++)
            {
                avg += image(i, j, k);
            }
            avg /= 3; // calculate average of pixels
            for (int k = 0; k < 3; k++)
            {
                if (avg > 124)
                { // if average greater than 124(gray scale) make it white
                    image(i, j, k) = 255;
                }
                else
                { // otherwise make it black
                    image(i, j, k) = 0;
                }
            }
        }
    }
}
//--------------------------------------------------------
void filter_3(Image &image) // Invert Image filter
{
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < image.channels; ++k)
            {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    endingFilter();
}
//--------------------------------------------------------
void filter_4(Image &image) // Merge Filter
{
    Image image2;
    load_image(image2);
    if ((image.width == image2.width) && (image.height == image2.height))
    {
        merge(image, image2);
    }
    else
    {
        string answer;
        cout << "The images are of different sizes, choose what you want to do now:\n";
        cout << "(1) Resize both images to the biggest height and the biggest width and then merge\n";
        cout << "(2) Merge the common area of the smaller width and the smaller height\n";
        while (true)
        {
            getline(cin, answer);
            if (answer == "1")
            {
                double MaxWidth, MaxHeight, newWidth, newHeight;
                MaxWidth = max(image.width, image2.width);
                MaxHeight = max(image.height, image2.height);
                image = resize(image, MaxWidth, MaxHeight);
                image2 = resize(image2, MaxWidth, MaxHeight);
                merge(image, image2);
                break;
            }
            else if (answer == "2")
            {
                double minWidth, minHeight;
                minWidth = min(image.width, image2.width);
                minHeight = min(image.height, image2.height);
                image = crop(image, minWidth, minHeight);
                image2 = crop(image2, minWidth, minHeight);
                merge(image, image2);
                break;
            }
            else
            {
                validChoice();
            }
        }
    }
    endingFilter();
}
//--------------------------------------------------------
Image resize(Image image, double MaxWidth, double MaxHeight)
{
    double newWidth, newHeight;
    newWidth = image.width / MaxWidth;
    newHeight = image.height / MaxHeight;
    Image image2(MaxWidth, MaxHeight);
    for (int i = 0; i < image2.width; ++i)
    {
        for (int j = 0; j < image2.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image2(i, j, k) = image(round(i * newWidth), round(j * newHeight), k);
            }
        }
    }
    return image2;
}
//--------------------------------------------------------
Image crop(Image image, double minWidth, double minHeight)
{
    Image image2(minWidth, minHeight);
    for (int i = 0; i < image2.width; i++)
    {
        for (int j = 0; j < image2.height; j++)
        {
            for (int k = 0; k < image2.channels; k++)
            {
                image2(i, j, k) = image(i, j, k);
            }
        }
    }
    return image2;
}
//--------------------------------------------------------
void merge(Image &image, Image image2)
{
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, k) = (unsigned char)((image(i, j, k) / 2) + (image2(i, j, k) / 2));
            }
        }
    }
}
//--------------------------------------------------------
void filter_5(Image &image) // Flip Filter
{
    cout << "--------------------\n";
    string choice;
    while (true)
    {
        cout << "Choose what you want\n";
        cout << "(1) Vertical Flip\n(2) Horizontal Flip\n(3) Exit\n";
        getline(cin, choice);
        if (choice == "1")
        {
            Image image2(image.width, image.height); // create new image has the same width and height of original image
            for (int i = 0; i < image.width; i++)
            { // loop on the image
                for (int j = 0; j < image.height; j++)
                {
                    for (int k = 0; k < image.channels; k++)
                    {
                        if (j <= image.height / 2)
                        { // while the height less than half store the pixel in the new image
                            image2(i, j, k) = image(i, j, k);
                            image(i, j, k) = image(i, (image.height - 1) - j, k); // change the pixel in original image to its inverse
                        }
                        else
                        {
                            image(i, j, k) = image2(i, (image.height - 1) - j, k);
                        }
                    }
                }
            }
            endingFilter();
        }
        else if (choice == "2")
        {
            Image image2(image.width, image.height); // create new image has the same width and height of original image
            for (int i = 0; i < image.width; i++)
            { // loop on the image
                for (int j = 0; j < image.height; j++)
                {
                    for (int k = 0; k < image.channels; k++)
                    {
                        if (i <= image.width / 2)
                        { // while the width less than half store the pixel in the new image
                            image2(i, j, k) = image(i, j, k);
                            image(i, j, k) = image((image.width - 1) - i, j, k); // change the pixel in original image to its inverse
                        }
                        else
                        {
                            image(i, j, k) = image2((image.width - 1) - i, j, k);
                        }
                    }
                }
            }
            endingFilter();
        }
        else if (choice == "3")
        {
            break;
        }
        else
        {
            validChoice();
        }
    }
}
//--------------------------------------------------------
void filter_6(Image &image) // Rotate filter
{
    cout << "--------------------\n";
    string choice6;
    while (true)
    {
        cout << "Choose what you want\n";
        cout << "(1) Rotate 90 degree\n(2) Rotate 180 degree\n(3) Rotate 270 degree\n(4) Exit\n";
        getline(cin, choice6);
        if (choice6 == "1")
        {
            image = rotate_image90(image);
            endingFilter();
        }
        else if (choice6 == "2")
        {
            image = rotate_image180(image);
            endingFilter();
        }
        else if (choice6 == "3")
        {
            image = rotate_image270(image);
            endingFilter();
        }
        else if (choice6 == "4")
        {
            break;
        }
        else
        {
            validChoice();
        }
    }
}
//--------------------------------------------------------
Image rotate_image90(Image image)
{
    Image newImg(image.height, image.width); // new image by replacing width with height and vice versa
    // Rotate the image
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                newImg(image.height - 1 - j, i, k) = image(i, j, k); // Rotate pixels
            }
        }
    }
    return newImg;
}
//--------------------------------------------------------
Image rotate_image180(Image image)
{
    Image newImg(image.width, image.height);
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                newImg(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k); // Rotate pixels
            }
        }
    }
    return newImg;
}
//--------------------------------------------------------
Image rotate_image270(Image image)
{
    Image newImg(image.height, image.width); // new image by replacing width with height and vice versa
    // Rotate the image
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                newImg(image.height - 1 - j, i, k) = image(i, j, k); // Rotate pixels
            }
        }
    }
    Image image2(newImg.width, newImg.height); // create new image has the same width and height of original image
    for (int i = 0; i < newImg.width; i++)
    { // loop on the image
        for (int j = 0; j < newImg.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (i <= (newImg.width / 2))
                { // while the width less than half store the pixel in the new image
                    image2(i, j, k) = newImg(i, j, k);
                    newImg(i, j, k) = newImg(newImg.width - 1 - i, j, k); // change the pixel in original image to its inverse
                }
                else
                {
                    newImg(i, j, k) = image2(newImg.width - 1 - i, j, k);
                }
            }
        }
    }
    return newImg;
}
//--------------------------------------------------------
void filter_7(Image &image) // Lightness Filter
{
    cout << "--------------------\n";
    while (true)
    {
        string answer;
        cout << "Choose what you want\n";
        cout << "(1) Increase the lightness\n(2) Decrease the lightness\n(3) Exit\n";
        getline(cin, answer);
        //-------------------------------------------------------------------------------------
        if (answer == "1")
        {
            for (int i = 0; i < image.width; ++i)
            {
                for (int j = 0; j < image.height; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        image(i, j, k) = (unsigned char)min(int((image(i, j, k) * 1.5)), 255); // we multiply by 1.5 to get each pixel lightness increased by 50%
                    }
                }
            }
            endingFilter();
        } //------------------------------------------------------------------------------------
        else if (answer == "2")
        {
            for (int i = 0; i < image.width; ++i)
            {
                for (int j = 0; j < image.height; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        image(i, j, k) = (unsigned char)min(int((image(i, j, k) * 0.5)), 255); // we multiply by 0.5 to get each pixel lightness decreased by 50%
                    }
                }
            }
            endingFilter();
        } //------------------------------------------------------------------------------------
        else if (answer == "3")
        {
            break;
        }
        else
        {
            validChoice();
        }
    }
}
//--------------------------------------------------------
Image filter_8(Image image) // Crop Filter
{
    cout << "--------------------\n";
    int stPoint1, stPoint2, W, H;
    cout << "Please enter the starting point" << endl;
    cin >> stPoint1 >> stPoint2; // take starting points from the user
    // check validation of starting points
    while (stPoint1 >= image.width || stPoint2 >= image.height || stPoint1 < 0 || stPoint2 < 0)
    {
        cout << "Please enter starting point less than size of the image" << endl;
        cin >> stPoint1 >> stPoint2;
    }
    cout << "Please enter the dimensions of the area to cut" << endl;
    cin >> W >> H; // take the dimensions of the area to cut from the user
    cin.ignore();
    // check validation of the dimensions
    while (W > image.width || H > image.height || W <= 0 || H <= 0 || (stPoint1 > 0 && W == image.width) || (stPoint2 > 0 && H == image.height))
    {
        cout << "Please enter dimensions less than original" << endl;
        cin >> W >> H;
        cin.ignore();
    }
    Image image2(W, H); // create a new image with new dimensions
    for (int i = 0; i < image2.width; i++)
    {
        for (int j = 0; j < image2.height; j++)
        {
            for (int k = 0; k < image2.channels; k++)
            {
                image2(i, j, k) = image(i + stPoint1, j + stPoint2, k); // add each pixel in the area to the new image
            }
        }
    }
    endingFilter();
    return image2;
}
//--------------------------------------------------------
Image filter_9(Image image) // Adding a Frame Filter
{
    cout << "--------------------\n";
    Image newImg(image.width + 2 * 20, image.height + 2 * 20);
    while (true)
    {
        cout << "What do you want to make?\n(1) simple frame\n(2) fancy frame\n(3) Exit\n";
        string answer;
        getline(cin, answer);
        if (answer == "1")
        {
            // simple frame
            while (true)
            {
                cout << "What do you want the color of the frame?\n(1) Red\n(2) black\n(3) white\n";
                string answer2;
                getline(cin, answer2);
                // -----------------------------------------------------------
                if (answer2 == "1")
                {
                    // Red
                    for (int i = 0; i < newImg.width; ++i)
                    {
                        for (int j = 0; j < newImg.height; ++j)
                        {
                            newImg(i, j, 0) = 255;
                            newImg(i, j, 1) = 0;
                            newImg(i, j, 2) = 0;
                        }
                    }
                    for (int i = 20; i < image.width - 20; ++i)
                    {
                        for (int j = 20; j < image.height - 20; ++j)
                        {
                            for (int k = 0; k < 3; ++k)
                            {
                                newImg(i, j, k) = image(i - 20, j - 20, k);
                            }
                        }
                    }
                    endingFilter();
                    break;
                }
                // -----------------------------------------------------------
                else if (answer2 == "2")
                {
                    // black
                    for (int i = 0; i < newImg.width; ++i)
                    {
                        for (int j = 0; j < newImg.height; ++j)
                        {
                            newImg(i, j, 0) = 0;
                            newImg(i, j, 1) = 0;
                            newImg(i, j, 2) = 0;
                        }
                    }
                    for (int i = 20; i < image.width - 20; ++i)
                    {
                        for (int j = 20; j < image.height - 20; ++j)
                        {
                            for (int k = 0; k < 3; ++k)
                            {
                                newImg(i, j, k) = image(i - 20, j - 20, k);
                            }
                        }
                    }
                    endingFilter();
                    break;
                }
                // -----------------------------------------------------------
                else if (answer2 == "3")
                {
                    // white
                    for (int i = 0; i < newImg.width; ++i)
                    {
                        for (int j = 0; j < newImg.height; ++j)
                        {
                            newImg(i, j, 0) = 255;
                            newImg(i, j, 1) = 255;
                            newImg(i, j, 2) = 255;
                        }
                    }
                    for (int i = 20; i < image.width - 20; ++i)
                    {
                        for (int j = 20; j < image.height - 20; ++j)
                        {
                            for (int k = 0; k < 3; ++k)
                            {
                                newImg(i, j, k) = image(i - 20, j - 20, k);
                            }
                        }
                    }
                    endingFilter();
                    break;
                }
                // -----------------------------------------------------------
                else
                {
                    validChoice();
                }
            }
        }
        // -----------------------------------------------------------
        else if (answer == "2")
        {
            // fancy frame
            while (true)
            {
                cout << "What do you want the color of the frame?\n(1) Red and black\n(2) blue and black\n(3) white and black\n";
                string answer2;
                getline(cin, answer2);
                // -----------------------------------------------------------
                if (answer2 == "1")
                {
                    // Red and black
                    for (int i = 0; i < newImg.width; ++i)
                    {
                        for (int j = 0; j < newImg.height; ++j)
                        {
                            if ((i / 55 + j / 55) % 2 == 0)
                            {
                                newImg(i, j, 0) = 255;
                                newImg(i, j, 1) = 0;
                                newImg(i, j, 2) = 0;
                            }
                            else
                            {
                                newImg(i, j, 0) = 0;
                                newImg(i, j, 1) = 0;
                                newImg(i, j, 2) = 0;
                            }
                        }
                    }
                    for (int i = 20; i < image.width - 20; ++i)
                    {
                        for (int j = 20; j < image.height - 20; ++j)
                        {
                            for (int k = 0; k < 3; ++k)
                            {
                                newImg(i, j, k) = image(i - 20, j - 20, k);
                            }
                        }
                    }
                    endingFilter();
                    break;
                }
                // -----------------------------------------------------------
                else if (answer2 == "2")
                {
                    // blue and black
                    for (int i = 0; i < newImg.width; ++i)
                    {
                        for (int j = 0; j < newImg.height; ++j)
                        {
                            if ((i / 55 + j / 55) % 2 == 0)
                            {
                                newImg(i, j, 0) = 0;
                                newImg(i, j, 1) = 0;
                                newImg(i, j, 2) = 255;
                            }
                            else
                            {
                                newImg(i, j, 0) = 0;
                                newImg(i, j, 1) = 0;
                                newImg(i, j, 2) = 0;
                            }
                        }
                    }
                    for (int i = 20; i < image.width - 20; ++i)
                    {
                        for (int j = 20; j < image.height - 20; ++j)
                        {
                            for (int k = 0; k < 3; ++k)
                            {
                                newImg(i, j, k) = image(i - 20, j - 20, k);
                            }
                        }
                    }
                    endingFilter();
                    break;
                }
                // -----------------------------------------------------------
                else if (answer2 == "3")
                {
                    // white
                    for (int i = 0; i < newImg.width; ++i)
                    {
                        for (int j = 0; j < newImg.height; ++j)
                        {
                            if ((i / 55 + j / 55) % 2 == 0)
                            {
                                newImg(i, j, 0) = 255;
                                newImg(i, j, 1) = 255;
                                newImg(i, j, 2) = 255;
                            }
                            else
                            {
                                newImg(i, j, 0) = 0;
                                newImg(i, j, 1) = 0;
                                newImg(i, j, 2) = 0;
                            }
                        }
                    }
                    for (int i = 20; i < image.width - 20; ++i)
                    {
                        for (int j = 20; j < image.height - 20; ++j)
                        {
                            for (int k = 0; k < 3; ++k)
                            {
                                newImg(i, j, k) = image(i - 20, j - 20, k);
                            }
                        }
                    }
                    endingFilter();
                    break;
                }
                // -----------------------------------------------------------
                else
                {
                    validChoice();
                }
            }
        }
        else if (answer == "3")
        {
            return newImg;
        }
        else
        {
            validChoice();
        }
    }
}
//--------------------------------------------------------
Image filter_10(Image image) // Edge Detection Filter
{
    filter_2(image);                                 // change color of the image to be B&W
    Image edgesImage((image.width), (image.height)); // make a new variable to save the edges in it
    // Sobel method to find edges of the image
    int IX[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};
    int IY[3][3] = {{1, 2, 1},
                    {0, 0, 0},
                    {-1, -2, -1}};
    for (int x = 1; x < (image.width - 1); ++x)
    {
        for (int y = 1; y < (image.height - 1); ++y)
        {
            int sumX = 0, sumY = 0;
            for (int i = -1; i <= 1; ++i)
            {
                for (int j = -1; j <= 1; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        sumX += image.getPixel(x + i, y + j, k) * IX[i + 1][j + 1];
                        sumY += image.getPixel(x + i, y + j, k) * IY[i + 1][j + 1];
                    }
                }
            }
            int edgeGradient = round(sqrt(sumX * sumX + sumY * sumY));
            edgeGradient = (edgeGradient > 128) ? 255 : 0;
            for (int k = 0; k < 3; ++k)
            {
                edgesImage.setPixel(x, y, k, (255 - edgeGradient));
            }
        }
    }
    endingFilter();
    return edgesImage;
}
//--------------------------------------------------------
Image filter_11(Image image) // Resizing Filter
{
    while (true)
    {
        cout << "--------------------\n";
        string choice;
        cout << "Choose what you want\n";
        cout << "(1) Enter new dimensions\n(2) Enter a ratio of reduction or increase" << endl;
        getline(cin, choice);
        if (choice == "1")
        {
            double W, H, widthRatio, heightRatio; // declare variables
            cout << "Please enter the new dimensions" << endl;
            cin >> W >> H; // take new width and new height from the user
            cin.ignore();
            while (W <= 0 || H <= 0)
            { // check new dimensions validation
                cout << "Please enter new dimensions greater than zero" << endl;
                cin >> W >> H;
                cin.ignore();
            }
            widthRatio = image.width / W;   // get the ratio between the old and new width
            heightRatio = image.height / H; // get the ratio between the old and new height
            Image image2(W, H);             // create a new image with new dimensions
            for (int i = 0; i < image2.width; i++)
            {
                for (int j = 0; j < image2.height; j++)
                {
                    for (int k = 0; k < image2.channels; k++)
                    {
                        image2(i, j, k) = image(round(i * widthRatio), round(j * heightRatio), k); // multiply each pixel by the ratio
                    }
                }
            }
            endingFilter();
            return image2;
        }
        else if (choice == "2")
        {
            double ratio, W, H, newRatio, widthRatio, heightRatio;
            cout << "Enter a ratio of reduction or increase" << endl;
            cin >> ratio; // take ratio from the user
            cin.ignore();
            while (ratio <= 0)
            { // check ratio validation
                cout << "Please enter a ratio greater than zero" << endl;
                cin >> ratio;
                cin.ignore();
            }
            // get the new dimensions
            newRatio = ratio / 100;
            W = image.width * newRatio;
            H = image.height * newRatio;
            widthRatio = image.width / W;   // get the ratio between the old and new width
            heightRatio = image.height / H; // get the ratio between the old and new height
            Image image2(W, H);             // create a new image with new dimensions
            for (int i = 0; i < image2.width; i++)
            {
                for (int j = 0; j < image2.height; j++)
                {
                    for (int k = 0; k < image2.channels; k++)
                    {
                        image2(i, j, k) = image(round(i * widthRatio), round(j * heightRatio), k); // multiply each pixel by the ratio
                    }
                }
            }
            endingFilter();
            return image2;
        }
        else
        {
            validChoice();
        }
    }
}
//--------------------------------------------------------
Image filter_12(Image image) // Blur Filter
{
    Image newImg(image.width, image.height);
    int neighbor_size = 12;
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            double sum_r = 0, sum_g = 0, sum_b = 0, count = 0;
            for (int t = -neighbor_size / 2; t <= neighbor_size / 2; ++t)
            {
                for (int l = -neighbor_size / 2; l <= neighbor_size / 2; ++l)
                {
                    int neighbor_i = i + l;
                    int neighbor_j = j + t;
                    if (neighbor_i >= 0 && neighbor_i < image.width && neighbor_j >= 0 && neighbor_j < image.height)
                    {
                        sum_r += image(neighbor_i, neighbor_j, 0);
                        sum_g += image(neighbor_i, neighbor_j, 1);
                        sum_b += image(neighbor_i, neighbor_j, 2);
                        count++;
                    }
                }
            }
            // getting average
            int avg_r = sum_r / count;
            int avg_g = sum_g / count;
            int avg_b = sum_b / count;
            // putting avg color to the pixel
            newImg(i, j, 0) = avg_r;
            newImg(i, j, 1) = avg_g;
            newImg(i, j, 2) = avg_b;
        }
    }
    endingFilter();
    return newImg;
}
//--------------------------------------------------------
void filter_13(Image &image) // Sunlight Filter
{
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, k) = (unsigned char)min(int((image(i, j, k) * 0.8)), 255); // we multiply by 1.5 to get each pixel lightness increased by 50%
            }
            image(i, j, 0) = (unsigned char)min(int((image(i, j, 0) * 1.5)), 255); // red
            image(i, j, 1) = (unsigned char)min(int((image(i, j, 1) * 1.5)), 255); // green
        }
    }
    endingFilter();
}
//--------------------------------------------------------
void filter_16(Image &image) // Purple Filter
{
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            image(i, j, 1) = (unsigned char)(image(i, j, 1) * 0.75); // decrease degree of green to make image look purple
        }
    }
    endingFilter();
}
//--------------------------------------------------------
void filter_17(Image &image) // Infrared Filter
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int red = image(i, j, 0);   // set variable red to the first channel
            int green = image(i, j, 1); // set variable green to the second channel
            int blue = image(i, j, 2);  // set variable blue to the third channel
            for (int k = 0; k < image.channels; k++)
            {
                image(i, j, 0) = 255; // set first channel(red) to max value of it
                image(i, j, 1) = 255 - green;
                image(i, j, 2) = 255 - blue;
            }
        }
    }
    endingFilter();
}
//--------------------------------------------------------