#include <iostream>
#include <fstream>

#define DRAW_BLACK image << 0 << " " << 0 << " " << 0 << endl
#define DRAW_WHITE image << 255 << " "  << 255 << " " << 255 << endl

using namespace std;

bool isSquare(int x, int y, int side, int offsetX, int offsetY, int border);

int main(int argc, char const *argv[])
{
    ofstream image;
    int iWidth = 250;
    int iHeight = 250;
    int bSize = 5;
    int offsetX = 25;
    int offsetY = 25;
    int squareSide = 200;

    image.open("image.ppm");

    image << "P3" << endl;
    image << iWidth << " " << iHeight << endl;
    image << "255" << endl;

    for (int y = 0; y < iWidth; y++){
        for (int x = 0; x < iHeight; x++) {
            if (isSquare(x, y, squareSide, offsetX, offsetY, bSize))
            {
                DRAW_BLACK;
            }
            else
            {
                DRAW_WHITE;
            }
        }
    }

    return 0;
}


bool isSquare(int x, int y, int side, int offsetX, int offsetY, int border)
{
    return (
                (
                    (x >= offsetX && x < offsetX + border) 
                    ||
                    (x >= side + offsetX && x < side + offsetX + border)
                )
                && 
                (
                    y >= offsetY && y < offsetY + side + border
                )

            )
            ||
            (
                (
                    (y >= offsetY && y < offsetY + border)
                    ||
                    (y >= side + offsetY && y < side + offsetY + border)
                )
                &&
                (
                    x >= offsetX && x < offsetX + side + border
                )
            );
}
