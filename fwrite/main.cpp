// fwrite.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>

enum class Bones
{
    Bone_Entity = 0,
    Bone_Hips = 1,
};

int getFileSize(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    int res = ftell(fp);
    fclose(fp);
    return res;

}

int main()
{
    //char* t = (char*)malloc(100 * sizeof(char));
    FILE* f = fopen("data.txt", "w");
    if (f == NULL)
    {
        std::cerr << "open file failed" << std::endl;
        return -1;
    }

    //just test enum functionality
    //Bones num = Bones::Bone_Hips;
    //if (num == Bones::Bone_Entity)
    //{
    //    return 0;
    //}

    char msg[] = "this";
    std::cout << strlen(msg) << std::endl;

    FILE* fr = fopen("create_cube.mel", "r");
    if (fr == NULL)
    {
        std::cerr << "open file failed" << std::endl;
        return -1;
    }
    char gg[100];
    long int n = getFileSize("create_cube.mel");
    if (n == -1)
    {
        std::cerr << "open file failed" << std::endl;
        return -1;
    }
    std::cout << n << std::endl;
    char* t = (char*)malloc((n + 1) * sizeof(char));

    while (!feof(fr))
    {
        fread(t, sizeof(char), (n + 1), fr);
    }
    //t[0] = 'a';
    //t[1] = 'b';
    //t[2] = 'D';
    //t[3] = '\0';
    //char c[4] = { 'a', 'g', 'd', '\0' };
    //char dd[100];
    //dd[0] = 'a';
    //dd[1] = 'b';
    //dd[2] = 'D';
    //dd[3] = '\0';
    //std::cout << strlen(dd) << std::endl;
    //fwrite(dd, sizeof(char), strlen(dd), f);
    t[n] = '\0';
    std::cout << strlen(t) << std::endl;

    for (int i = 0; i < strlen(t); i++)
    {
        t[i] = t[i] + 1;
        t[i]++;
    }
    fwrite(t, sizeof(char), strlen(t), f);

    fclose(fr);
    fclose(f);
    std::cout << t << std::endl;
    free(t);
    std::cout << "Hello World!\n";

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
