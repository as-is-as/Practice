#include <cstdio>

char map[21][21];
bool alphabet[26];

int movX[4] = {0,0,-1,1};
int movY[4] = {-1,1,0,0};

int maxMove = 0;
int r, c;

void Go(int x, int y, int move)
{
    if(move > maxMove)
        maxMove = move;
    
    int posX, posY;
    for(int i=0; i<4; ++i)
    {
        posX = x + movX[i];
        posY = y + movY[i];

        if( posX < 0 || posX >= r || posY < 0 || posY >= c)  
            continue;
        if(alphabet[map[posX][posY] - 'A'])
            continue;

        alphabet[map[posX][posY] - 'A'] = true;
        Go(posX, posY, move + 1);
        alphabet[map[posX][posY] - 'A'] = false;
    }
}

int main(void)
{
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; ++i)
    {
        scanf("%s", map[i]);
    }
    alphabet[map[0][0] - 'A'] = true;
    Go(0,0, 1);

    printf("%d\n",maxMove);
    return 0;
}