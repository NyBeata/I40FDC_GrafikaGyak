#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Brick{
    int side_a;
    int side_b;
    int side_c;

} Brick;

void setSize( Brick* b);
int calcVolume(const Brick* b);
int calcSurface(const Brick* b);
bool isSquare(const Brick* b);

int main()
{
    Brick test;

    setSize(&test);
    printf(" Surface: %d \t Volume: %d\n",calcSurface(&test),calcVolume(&test));
    if( isSquare(&test) == true){
        printf("The body has square sides\n");
    }else{
        printf("The body has no square sides\n");
    }

    return 0;
}


void setSize( Brick* b){

    bool is_ok;
    is_ok=false;
    do{
        printf("Enter the length of edge 'a':");
        scanf("%d",&b->side_a);
        if(b->side_a < 1){
            printf("The edge can't be less than 1!\n");
        }else is_ok=true;
    }while(!is_ok);

    is_ok= false;

    do{
        printf("Enter the length of edge 'b':");
        scanf("%d",&b->side_b);
        if(b->side_b < 1){
            printf("The edge can't be less than 1!\n");
        }else is_ok=true;
    }while(!is_ok);

    is_ok=false;

    do{
        printf("Enter the length of edge 'b':");
        scanf("%d",&b->side_c);
        if(b->side_c < 1){
            printf("The edge can't be less than 1!\n");
        }else is_ok=true;
    }while(!is_ok);

    return ;
}

int calcVolume(const Brick* b){

    int volume;
    volume = b->side_a*b->side_b*b->side_c;

    return volume;

}

int calcSurface(const Brick* b){

    int surface;
    surface = 2*(b->side_a+b->side_b+b->side_a+b->side_c+b->side_b+b->side_c);

    return surface;

}

bool isSquare(const Brick* b){

    bool is_square;
    is_square= false;
    if(b->side_a == b->side_b){
        is_square=true;
    }else if( b->side_a == b->side_c){
        is_square=true;
    }else if(b->side_b == b->side_c){
        is_square=true;
    }

    return is_square;

}