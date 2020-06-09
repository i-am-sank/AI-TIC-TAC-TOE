#include<bits/stdc++.h>
using namespace std;
struct Move 
{ 
    int row, col; 
}; 
char game[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int n,temp,d=9;
vector <int> comp;
char player='X',opponent='X';
bool isMovesLeft(char game[3][3]) 
{ 
    for (int i = 0; i<3; i++) 
        for (int j = 0; j<3; j++) 
            if (game[i][j]==' ') 
                return true; 
    return false; 
} 
int evaluate()
{
	int i;
	for(i=0;i<3;i++)   // rows
	if(game[i][0]==game[i][1]&&game[i][2]==game[i][1])
	{
		if(game[i][0]=='X')
		return 10;
		else if(game[i][0]=='O')
		return -10;
	}
	
	for(i=0;i<3;i++)  //columns
	if(game[0][i]==game[1][i]&&game[2][i]==game[1][i])
	{
		if(game[0][i]=='X')
		return 10;
		else if(game[0][i]=='O')
		return -10;
	}

	if(game[0][0]==game[1][1]&&game[2][2]==game[1][1]) // diagnols
    {
		if(game[0][0]=='X')
		return 10;
		else if(game[0][0]=='O')
		return -10;
	}
    if(game[0][2]==game[1][1]&&game[2][0]==game[1][1])
    {
		if(game[0][2]=='X')
		return 10;
		else if(game[0][2]=='O')
		return -10;
	}
return 0;			
}
char win()
{
	int i;
	for(i=0;i<3;i++)   // rows
	if(game[i][0]==game[i][1]&&game[i][2]==game[i][1])
	{
		if(game[i][0]=='X')
		return 'X';
		else if(game[i][0]=='O')
		return 'O';
	}
	
	for(i=0;i<3;i++)  //columns
	if(game[0][i]==game[1][i]&&game[2][i]==game[1][i])
	{
		if(game[0][i]=='X')
		return 'X';
		else if(game[0][i]=='O')
		return 'O';
	}

	if(game[0][0]==game[1][1]&&game[2][2]==game[1][1]) // diagnols
    {
		if(game[0][0]=='X')
		return 'X';
		else if(game[0][0]=='O')
		return 'O';
	}
    if(game[0][2]==game[1][1]&&game[2][0]==game[1][1])
    {
		if(game[0][2]=='X')
		return 'X';
		else if(game[0][2]=='O')
		return 'O';
	}
return '/';			
}
int minimax(char game[3][3], int depth, bool isMax) 
{ 
    int score = evaluate(); 
  
    // If Maximizer has won the game return his/her 
    // evaluated score 
    if (score == 10) 
        return (score-depth); 
  
    // If Minimizer has won the game return his/her 
    // evaluated score 
    if (score == -10) 
        return (score+depth); 
  
    // If there are no more moves and no winner then 
    // it is a tie 
    if (isMovesLeft(game)==false) 
        return 0; 
  
    // If this maximizer's move 
    if (isMax) 
    { 
        int best = -1000; 
  
        // Traverse all cells 
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                // Check if cell is empty 
                if (game[i][j]==' ') 
                { 
                    // Make the move 
                    game[i][j] = player; 
  
                    // Call minimax recursively and choose 
                    // the maximum value 
                    best = max( best, 
                        minimax(game, depth+1, !isMax) ); 
  
                    // Undo the move 
                    game[i][j] = ' '; 
                } 
            } 
        } 
        return best; 
    } 
  
    // If this minimizer's move 
    else
    { 
        int best = 1000; 
  
        // Traverse all cells 
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                // Check if cell is empty 
                if (game[i][j]==' ') 
                { 
                    // Make the move 
                    game[i][j] = opponent; 
  
                    // Call minimax recursively and choose 
                    // the minimum value 
                    best = min(best, 
                           minimax(game, depth+1, !isMax)); 
  
                    // Undo the move 
                    game[i][j] = ' '; 
                } 
            } 
        } 
        return best; 
    } 
} 
void multiplaysetup()
{
	   cout<<"       "<<"**TIC TAC TOE V3.0**"<<endl;
   cout<<endl;
   cout<<"Position's Map"<<endl;
   cout<<"              1 | 2 | 3"<<endl;
   cout<<"             ==========="<<endl;
   cout<<"              4 | 5 | 6"<<endl;
   cout<<"             ==========="<<endl;
   cout<<"              7 | 8 | 9"<<endl;
   cout<<"-------------------------------"<<endl;
   cout<<"             MULTIPLAYER GAME"<<endl;
   cout<<" Player1 is X"<<endl;
   cout<<" Player2 is O"<<endl;
}
void singleplaysetup()
{
	   cout<<"       "<<"**TIC TAC TOE V3.0**"<<endl;
   cout<<endl;
   cout<<"Position's Map"<<endl;
   cout<<"              1 | 2 | 3"<<endl;
   cout<<"             ==========="<<endl;
   cout<<"              4 | 5 | 6"<<endl;
   cout<<"             ==========="<<endl;
   cout<<"              7 | 8 | 9"<<endl;
   cout<<"-------------------------------"<<endl;
   cout<<"              PLAYER V/S COMPUTER"<<endl;
   cout<<" Player is X"<<endl;
   cout<<" Computer is O"<<endl;
}
void setgame()
{  
 
for(int i=0;i<3;i++)
{   cout<<"               ";
	for(int j=0;j<3;j++)
	{
		cout<<game[i][j];
		if(j<2)
		cout<<" | ";
	}
	cout<<endl;
	cout<<"               ";
	for(int j=0;j<3;j++)
	if(i<2)
	cout<<"===";	
	
	cout<<endl;
}
}
Move findBestMove(char game[3][3]) 
{ 
    int bestVal = -1000; 
    Move bestMove; 
    bestMove.row = -1; 
    bestMove.col = -1; 
  
    // Traverse all cells, evaluate minimax function for 
    // all empty cells. And return the cell with optimal 
    // value. 
    for (int i = 0; i<3; i++) 
    { 
        for (int j = 0; j<3; j++) 
        { 
            // Check if cell is empty 
            if (game[i][j]==' ') 
            { 
                // Make the move 
                game[i][j] = opponent; 
  
                // compute evaluation function for this 
                // move. 
                int moveVal = minimax(game, 0, false); 
  
                // Undo the move 
                game[i][j] = ' '; 
  
                // If the value of the current move is 
                // more than the best value, then update 
                // best/ 
                if (moveVal > bestVal) 
                { 
                    bestMove.row = i; 
                    bestMove.col = j; 
                    bestVal = moveVal; 
                } 
            } 
        } 
    } 
  
    return bestMove; 
} 
void input()
{ 
  int a;
   if(player=='X')
  {
  cout<<"Player1 turn"<<endl;
  cout<<"Enter the position where you want to tic :  ";
   cin>>a;
 }
  else if(player=='O')
  {
    cout<<"Player2 turn"<<endl;
  cout<<"Enter the position where you want to tic :  ";	
   cin>>a; 
  }

 if(a==1)
   {
   	 if(game[0][0]==' ')
   	 game[0][0]=player;
   	 else
     { 
        cout<<"already filled try another place "<<endl;
     	input();  	 
	 }
   	}
   	else if(a==2)
   {
   	 if(game[0][1]==' ')
   	 game[0][1]=player;
   	 else
     {
     	
        cout<<"already filled try another place "<<endl;
     	input();  	 
	 }
   	}
   	 	else if(a==3)
   {
   	 if(game[0][2]==' ')
   	 game[0][2]=player;
   	 else
     { 
        
        cout<<"already filled try another place "<<endl;
     	input();  	 
	 }
   	} 	
	   else if(a==4)
   {
   	 if(game[1][0]==' ')
   	 game[1][0]=player;
   	 else
     {
     
        cout<<"already filled try another place "<<endl;
     	input();  	 
	 }
   	} 	else if(a==5)
   {
   	 if(game[1][1]==' ')
   	 game[1][1]=player;
   	 else
     {
     	
        cout<<"already filled try another place "<<endl;
     	input();  	 
	 }
   	} 
	else if(a==6)
   {
   	 if(game[1][2]==' ')
   	 game[1][2]=player;
   	 else
     {
     
        cout<<"already filled try another place "<<endl;
     	input();  	 
	 }
   	} 	else if(a==7)
   {
   	 if(game[2][0]==' ')
   	 game[2][0]=player;
   	 else
     {
     
        cout<<"already filled try another place "<<endl;
     	input();  	 
	 }
   	} 	else if(a==8)
   {
   	 if(game[2][1]==' ')
   	 game[2][1]=player;
   	 else
     {
        cout<<"already filled try another place "<<endl;
     	input();  	 
	 }
   	} 	else if(a==9)
   {
   	 if(game[2][2]==' ')
   	 game[2][2]=player;
   	 else
     {
     	
        cout<<"already filled try another place "<<endl;
     	input();  	 
	 }
   	}
   else
   {
   	cout<<"Enter number within range 1 to 9."<<endl;
   	input();
	}	
}
void input1()
{ 
  int a;
   if(player=='X')
  {
  cout<<"Player1 turn"<<endl;
  cout<<"Enter the position where you want to tic :  ";
   cin>>a;
 }

  else if(player=='O')
  {
  	temp=rand()%d;
  	a=comp[temp];
  	comp.erase(comp.begin()+temp);
  	d--;  
  }
   
 if(a==1)
   {
   	 if(game[0][0]==' ')
   	 game[0][0]=player;
   	 else
     { 
        cout<<"already filled try another place "<<endl;
     	input1();  	 
	 }
   	}
   	else if(a==2)
   {
   	 if(game[0][1]==' ')
   	 game[0][1]=player;
   	 else
     {
     	
        cout<<"already filled try another place "<<endl;
     	input1();  	 
	 }
   	}
   	 	else if(a==3)
   {
   	 if(game[0][2]==' ')
   	 game[0][2]=player;
   	 else
     { 
        
        cout<<"already filled try another place "<<endl;
     	input1();  	 
	 }
   	} 	
	   else if(a==4)
   {
   	 if(game[1][0]==' ')
   	 game[1][0]=player;
   	 else
     {
     
        cout<<"already filled try another place "<<endl;
     	input1();  	 
	 }
   	} 	else if(a==5)
   {
   	 if(game[1][1]==' ')
   	 game[1][1]=player;
   	 else
     {
     	
        cout<<"already filled try another place "<<endl;
     	input1();  	 
	 }
   	} 
	else if(a==6)
   {
   	 if(game[1][2]==' ')
   	 game[1][2]=player;
   	 else
     {
     
        cout<<"already filled try another place "<<endl;
     	input1();  	 
	 }
   	} 	else if(a==7)
   {
   	 if(game[2][0]==' ')
   	 game[2][0]=player;
   	 else
     {
     
        cout<<"already filled try another place "<<endl;
     	input1();  	 
	 }
   	} 	else if(a==8)
   {
   	 if(game[2][1]==' ')
   	 game[2][1]=player;
   	 else
     {
        cout<<"already filled try another place "<<endl;
     	input1();  	 
	 }
   	} 	else if(a==9)
   {
   	 if(game[2][2]==' ')
   	 game[2][2]=player;
   	 else
     {
     	
        cout<<"already filled try another place "<<endl;
     	input1();  	 
	 }
   	}
   else
   {
   	cout<<"Enter number within range 1 to 9."<<endl;
   	input1();
	}	
}

void turn()
{
	if(player=='X')
	player='O';
	
	else
	player='X';
}	

  
int main()
{   
    int x;
   cout<<"ENTER 1 FOR MULTIPLAYER GAME AND 2 FOR SINGLE PLAYER :";
   cin>>x;
   if(x==1)
   {
   	  system("cls");
   	  n=0;
   multiplaysetup();  
   setgame();
   while(1)
   {    n++;
       
   	    input();
   	    
   	    system("cls"); 
   	    multiplaysetup();
   	    setgame();
   	
   	    if(win()=='X')
   	   {
   	  	cout<<"Player1 wins!"<<endl;
   	  	break;
		} 
		else if(win()=='O')
   	   {
   	  	cout<<"Player2 wins!"<<endl;
   	  	break;
		}
		else if(win()=='/'&&n==9)
		{
			cout<<"it's a draw"<<endl;
			break;
		}
   	  turn();
   }
 
   }
   else
   {
   	cout<<"Difficulty level  PRESS 1 FOR **EASY**  AND PRESS 2 FOR **HARD** :";
   	cin>>x;
   	
   	system("cls");
   	n=0;
   	singleplaysetup();   
   setgame();
   if(x==1)
   {
    int i=9;
    while(i!=0)
    {
    	comp.push_back(i);
    	i--;
	}
   	     while(1)
   {    n++;
        
   	    input1();
   	    
   	    system("cls");
		singleplaysetup(); 
   	    setgame();
   	
   	    if(win()=='X')
   	   {
   	  	cout<<"Player wins!"<<endl;
   	  	break;
		} 
		else if(win()=='O')
   	   {
   	  	cout<<"Computer wins!"<<endl;
   	  	break;
		}
		else if(win()=='/'&&n==9)
		{
			cout<<"it's a draw"<<endl;
			break;
		}
   	  turn();
   }}
   else
   {
   	   while(1)
   {    n++;
        if(player=='X')
   	    input();
   	    
   	    else if(player=='O')
   	    {
   	     Move bestmove=findBestMove(game);
  	     game[bestmove.row][bestmove.col]='O';
		   }
   	    system("cls");
		singleplaysetup(); 
   	    setgame();
   	
   	    if(win()=='X')
   	   {
   	  	cout<<"Player wins!"<<endl;
   	  	break;
		} 
		else if(win()=='O')
   	   {
   	  	cout<<"Computer wins!"<<endl;
   	  	break;
		}
		else if(win()=='/'&&n==9)
		{
			cout<<"it's a draw"<<endl;
			break;
		}
   	  turn();
   }
   }
   
}}
