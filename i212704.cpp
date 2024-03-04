#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;
const int ROWS = 15;
const int COLS = 25;

int get_pellets_count(char maze[][COLS]);
void print_maze(char maze[][COLS]);

int main()
{
int i=0;
int j=0;
int score=0;
 // this is use for make the pac man board AND obstacles inside the board 
char ar[ROWS][COLS] = {
      {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', '#', '#', '#', '#', '#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#', 'o', 'o', 'o', 'o', '#'}, 
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#', '#', '#', '#', '#', '#', '#', 'o', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#', 'o', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#', '#', '#', '#', '#', '#', '#', 'o', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', '#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', '#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', '#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', '#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#'},
      {'#', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
   };
// n and m variables are use for pacman intilization
int n=4, m=3;
char pac_up = 'V';
char pac_down = '^';
char pac_right = '<';
char pac_left = '>';
// random ghost intilization
int rg1=2;
int rg2=2;
int check=0;
srand(time(0));
int t1=rand() % 3;

cout<<ar[rg1][rg2];
// decleartion of variables for ghost
char ghost = '8';
int gx = 10;
int gy = 15;
// pacman intilization inside board
ar[n][m] = pac_right;
// ghost inlization inside the board
ar[gx][gy] = ghost;
// printing the board with pacman(<)
cout<<"the total score is"<<endl;
for(  i=0; i<ROWS; i++)
{
 for( j=0; j<COLS; j++)
 {
   cout<<ar[i][j]<<" ";
  }
  cout<<endl;
}

bool game_over=false;
char move;
int pellets;
// Game loop and moving up, down, forward and backward
while(true)
{
 cout<<"Move your pacman please!"<<endl;
 cin>>move;
 ar[n][m]=' ';
 // This if is use for moving the pacman upward
  if(move=='w')
  {
     n--;
     if(ar[n][m] == '#') // detection of walls
     {
       cout << "Cannot move here!"<<endl;
       n++;       
     }
       if(ar[n][m] == 'o') // score 
       {
         score++;
       }
     ar[n][m]=pac_up;
     pellets = get_pellets_count(ar); 
    	 if(pellets == 0)
         {			
 	       cout << "GAME OVER!"<<endl;;
               print_maze(ar);
               break;
         }

  }
  // This if is use for moving the pacman downwards
     else if(move=='s')
     {
        n++;
        if(ar[n][m]=='#') // detection of walls
        {
          cout<<"Cannot move here!"<<endl;
          n--;
        }
         if(ar[n][m]=='o') // score
         {
          score++;
         }
      ar[n][m]=pac_down;
      pellets = get_pellets_count(ar);
     if(pellets == 0)
      {
        
        cout << "GAME OVER"<<endl;
        print_maze(ar);
        break;
      }
     }
     
     
     // This if is use for moving the pacman rightwards
      else if(move=='d')
      {
        m++;
        if(ar[n][m]=='#') // detection of walls
        {
          cout<<"cannot move here!"<<endl;
          m--;
        }
         if(ar[n][m]=='o') // score
         {
           score++;
         }
      ar[n][m]=pac_right;
      pellets = get_pellets_count(ar);
            if(pellets == 0)
            {
             cout << "GAME OVER!"<<endl;
             print_maze(ar);
             break;
            }
      }
     
     
     // This if is use for moving the pacman leftward
      else if(move=='a')
      {
        m--;
        if(ar[n][m]=='#') // detection of walls
        {
          cout<<"cannot move here!"<<endl;
          m++;
        }
         if(ar[n][m]=='o') // score
         {
           score++;
         }
      ar[n][m]=pac_left;
      pellets = get_pellets_count(ar);
          if(pellets == 0)
          {
             cout << "GAME OVER!"<<endl;
             print_maze(ar);
             break;
          }
     }
    
    //ghost movement
      int d1 = 999, d2 = 999, d3 = 999, d4 = 999;
      int min_distance = 999;
      int mov_gx;
      int mov_gy;
      
      // ghost down movement
      int down_gx = gx + 1;
      int down_gy = gy;
      if (ar[down_gx][down_gy] != '#')
      {
        d2 = sqrt( (pow(n - down_gx,2)) + (pow(m - down_gy,2)) );
         if(d2 < min_distance)
         {
           min_distance = d2;
           mov_gx = down_gx;
           mov_gy = down_gy;
         }
      }

      // ghost up movement
      int up_gx = gx - 1;
      int up_gy = gy;
      if (ar[up_gx][up_gy] != '#')
      {
        d1 = sqrt( (pow(n - up_gx,2)) + (pow(m - up_gy,2)) );
        if(d1 < min_distance)
        {
          min_distance = d1;
          mov_gx = up_gx;
          mov_gy = up_gy;
        }
      }

      // ghost left movement
      int left_gx = gx;
      int left_gy = gy - 1;
      if (ar[left_gx][left_gy] != '#')
      {
        d3 = sqrt( (pow(n - left_gx,2)) + (pow(m - left_gy,2)) );
        if(d3 < min_distance)
        {
          min_distance = d3;
          mov_gx = left_gx;
          mov_gy = left_gy;
        }
      }
      
      // ghost right movement
      int right_gx = gx;
      int right_gy = gy + 1;
      if (ar[right_gx][right_gy] != '#')
      {
        d4 = sqrt( (pow(n - right_gx,2)) + (pow(m - right_gy,2)) );
        if(d4 < min_distance)
        {
          min_distance = d4;
          mov_gx = right_gx;
          mov_gy = right_gy;
        }
      }

      ar[gx][gy] = 'o';
      gx = mov_gx;
      gy = mov_gy;
      ar[gx][gy] = ghost;
  // game is over when ghost eats pacman
  if(ar[n][m]==ghost)
  {
    cout<<"game is end"<<endl;
    break;
  }
   
  // printing the score
  cout<<"The score is"<<":"<<score<<endl;
  
  	for(  i=0; i<ROWS; i++)
  	{
   		for( j=0; j<COLS; j++)
  		{
     			cout<<ar[i][j]<<" ";
     
  		 }
	cout<<endl;
	}
    
 
  																										 

switch(rand() % 3)
{
 case 0:
 {
    ar[rg1][rg2]='o';
      rg1++;
      if(ar[rg1][rg2]=='<' || ar[rg1][rg2]=='>' || ar[rg1][rg2]=='v' || ar[rg1][rg2]=='^')
      {
        cout<<"game over"<<endl;
        break;
      }
      ar[rg1][rg2]='8';
      
   break;   
  }
 case 1:
  {
     ar[rg1][rg2]='o';
      rg1--;
      if(ar[rg1][rg2]=='<' || ar[rg1][rg2]=='>' || ar[rg1][rg2]=='v' || ar[rg1][rg2]=='^')
      {
        cout<<"game over"<<endl;
        game_over=false;
        break;
      }
      ar[rg1][rg2]='8';
     
   break; 
  }  
 case 2:
  {
      ar[rg1][rg2]='o';
      rg2++;
      if(ar[rg1][rg2]=='<' || ar[rg1][rg2]=='>' || ar[rg1][rg2]=='v' || ar[rg1][rg2]=='^')
      {
        cout<<"game over"<<endl;
        game_over=false;
        break;
      }
      ar[rg1][rg2]='8';
      
   break;   
   }
 case 3:
  {
     ar[rg1][rg2]='o';
     rg2--;
     if(ar[rg1][rg2]=='<' || ar[rg1][rg2]=='>' || ar[rg1][rg2]=='v' || ar[rg1][rg2]=='^')
      {
        cout<<"game over"<<endl;
        game_over=false;
        
        break;
      }
      
     ar[rg1][rg2]='8';
      
   break;   
   }
   // game is over 
 if(game_over==false)
 	{
  		 cout<<"game is over";
   		break;
	}
 }

	
}
return 0; 
}


int get_pellets_count(char maze[][COLS])
{
  int count = 0;
   	for(int i = 0; i < ROWS; i++)
   	{
      		for(int j = 0; j < COLS; j++)
      		{
         		if(maze[i][j] == 'o')
           		count++;
     		 }
  	 }
  return count;
}

void print_maze(char maze[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    
}
