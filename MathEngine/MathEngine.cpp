
#include <iostream>
#include "Quaternions.h"
#include "Matrix.h"
#include "Vectors.h"


using namespace machineman;

int main()
{
    std::cout << "Its Machineman's World!\n";
    Vector3d axis(0, 0, 1);
    Vector3d point(1, 0, 0);

    point.Print();

    point.rotateVectorAboutAngleAndAxis(90, axis).Print();
    float angle;
    while (true)
    {
        std::cin >> angle;

        point.rotateVectorAboutAngleAndAxis(angle, axis).Print();

    }

}
