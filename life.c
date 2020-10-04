#include <stdio.h>
#include <stdbool.h>

#define MAPSIZE 100

bool map[MAPSIZE][MAPSIZE][10]={0};
unsigned int step_all = 0;
int map_num = 0,map_next = 1;

/*void print()
{
    for(int a=0;a<MAPSIZE;a++)
    {
        for(int b=0;b<MAPSIZE;b++)
            printf("%d",map[a][b][map_next]);
        printf("\n");
    }
    printf("\n");

}*/

bool step()
{
    for(int a=1;a<MAPSIZE-1;a++)
    {
        for(int b=1;b<MAPSIZE-1;b++)
        {
            int sum = map[a-1][b][map_num]+map[a-1][b-1][map_num]+map[a][b-1][map_num]+map[a+1][b][map_num]+map[a+1][b-1][map_num]+map[a][b+1][map_num]+map[a+1][b+1][map_num]+map[a-1][b+1][map_num];
            switch(sum)
            {
                case 3:
                    map[a][b][map_next] = 1;
                    break;
                case 2:
                    map[a][b][map_next] = map[a][b][map_num];
                    break;
                default:
                    map[a][b][map_next] = 0;
                    break;
            }
        }
    }

    int check_diff_all = 0;
    for(int c=0;c<10;c++)
    {
        bool check_diff = 0;
        if(c==map_next)
            continue;
        for(int a=0;a<MAPSIZE;a++)
        {
            for(int b=0;b<MAPSIZE;b++)
            {
                if(map[a][b][c]!=map[a][b][map_next])
                {
                    check_diff = 1;
                    check_diff_all++;
                    break;
                }
            }
            if(check_diff)
                break;
        }
    }
    if(check_diff_all<10-1)
    {
       // print();
        return 0;
    }

    //print();

    step_all++;

    map_num++;
    if(map_num>=10)
        map_num = 0;
    map_next++;
    if(map_next>=10)
        map_next = 0;

    return 1;
}

int main()
{
    map[MAPSIZE/2][MAPSIZE/2][0] = 1;
    map[MAPSIZE/2][MAPSIZE/2+1][0] = 1;
    map[MAPSIZE/2][MAPSIZE/2+2][0] = 1;
    map[MAPSIZE/2+1][MAPSIZE/2+1][0] = 1;
    while(step());
    printf("step:%d\n",step_all);
}
