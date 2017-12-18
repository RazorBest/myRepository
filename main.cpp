#include <cstdio>
using namespace std;
#include <ctime>
#include <windows.h>
#include <winuser.h>

char a[100][100];
int height, width;
int x, y;

void Stealth()
{
  HWND Stealth;
  AllocConsole();
  Stealth = FindWindowA("ConsoleWindowClass", NULL);
  ShowWindow(Stealth,0);
}

void draw_margin()
{
    for (int i = 0; i < width; i++)
        a[i][0] = a[i][height - 1] = '*';
    for (int i = 0; i < height; i++)
        a[0][i] = a[width - 1][i] = '*';
}

void init()
{
    x = 1;
    y = 1;

    width = 20;
    height = 40;

    draw_margin();
}

void clear_buffer()
{
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            a[i][j] = 0;
}

void update_player()
{
    if (x < width - 2)
    {
        x ++;
    }
    else x = width - 2;

    a[x][y] = '#';
}

void afisare()
{
    system("cls");
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
            if (a[i][j]) printf("%c", a[i][j]);
            else printf(" ");
        printf("\n");
    }
}

int main()
{
    init();
	//Stealth();
	char key[200] = {0}, buf[10000], len = 0;
	double t = clock();
	double ticks = 5, interval = 1000 / ticks;

    a[x][y] = '#';

    afisare();

	while (1)
	{
	    if (clock() - t > interval)
        {
            clear_buffer();
            draw_margin();
            update_player();
            t = clock();
            afisare();
        }

		for(int i = 8; i <= 190; i++)
		{
			if (GetAsyncKeyState(i) == -32767)
			{
			    if (!key[i])
                {
                    if (i == VK_RIGHT)
                    {
                        y++;
                    }
                    else if (i == VK_LEFT)
                        y--;
                    else if (i == VK_SPACE)
                        x -= 3;
                }
			}
			else
				key[i] = 0;
		}
	}

	return 0;
}
