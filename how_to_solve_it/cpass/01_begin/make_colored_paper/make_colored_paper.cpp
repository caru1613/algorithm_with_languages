#include <cstdio>
#include <iostream>

#define MAX_WIDTH_HEIGHT 130
#define WHITE_PAPER 0
#define BLUE_PAPER 1

int colored_paper[MAX_WIDTH_HEIGHT][MAX_WIDTH_HEIGHT] = {0};
int total_color[2] = {0}; /* 0: White, 1: Blue */
int N;

using namespace std;

void print_colored_paper()
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            printf("%d ",colored_paper[y][x]); 
        }
        printf("\n");
    }
}

bool is_the_same_color(int x, int y, int size)
{
    int candidate_color;

    candidate_color = colored_paper[y][x];
    //cout << "Enterring :" << x << ", " <<  y << "," << size << "," << candidate_color << endl;
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (candidate_color != colored_paper[i][j])
                return false;
        }
    }
    
    total_color[candidate_color] += 1;
    //cout << "Exiting :" << x << ", " <<  y << "," << size << "," << candidate_color << ", " << total_color[candidate_color] << endl;

    return true;
}

void calculate_colored_paper(int x, int y, int size)
{
    if(is_the_same_color(x,y,size))
    {
        return;
    }

    int new_size = size/2;
    int new_x = (x + new_size);
    int new_y = (y + new_size);
    calculate_colored_paper(x, y, new_size);
    calculate_colored_paper(x, new_y, new_size);
    calculate_colored_paper(new_x, y, new_size);
    calculate_colored_paper(new_x, new_y, new_size);
}

int main()
{
    scanf("%d\n", &N);

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf(" %d", &colored_paper[y][x]); 
        }
    }

    calculate_colored_paper(0, 0, N);
    printf("%d\n%d", total_color[0], total_color[1]);
    return 0;

}
