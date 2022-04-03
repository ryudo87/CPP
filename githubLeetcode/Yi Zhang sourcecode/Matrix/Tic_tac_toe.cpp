
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <cassert>
using namespace std;


//template<unsigned N>
//class Board
//{
//public:
//	Player matrix[N][N];
//	Board()
//	{
////			for(unsigned i=0;i<N;++i)
////				for(unsigned j=0;j<N;++j)
////					matrix[i][j]=NoOne;
//	}
//	bool operator == (const Board& bd ){
//
//		for(unsigned row=0;row<N;++row){
//			for(unsigned col=0;col<N;++col){
//				if(bd.matrix[row][col] != matrix[row][col])
//					return false;
//			}
//		}
//		return true;
//	}
//
//};

template<unsigned N>
class Tic_tac_toe
{
	enum Player {NoOne=0,Player1=1,Player2=2, Invalid=3};
	class Board
		{
		public:
			Player matrix[N][N];
			Board()
			{
				for(unsigned i=0;i<N;++i)
					for(unsigned j=0;j<N;++j)
						matrix[i][j]=NoOne;
			}
			bool operator == (const Board& bd ){

				for(unsigned row=0;row<N;++row){
					for(unsigned col=0;col<N;++col){
						if(bd.matrix[row][col] != matrix[row][col])
							return false;
					}
				}
				return true;
			}

		};

	Board board;
	list< Board > winSet1; //Player1 & Player2 share this winning positions
	list< Board > winSet2;
	unsigned p1Symbol,p2Symbol;
public:

	void clean_board()
	{
		for(unsigned i=0;i<N;++i)
			for(unsigned j=0;j<N;++j)
				board.matrix[i][j]=NoOne;
	}

	void print_winSet()
	{
		cout<<"winSet1:"<<endl;
		for(typename list< Board >::iterator it=winSet1.begin(); it!=winSet1.end(); it++)
		{
			for(unsigned i=0;i<N;++i){
				for(unsigned j=0;j<N;++j)
						cout<<it->matrix[i][j]<<" ";
				cout<<endl;
			}
			cout<<endl;
		}
		cout<<"winSet2:"<<endl;
		for(typename list< Board >::iterator it=winSet2.begin(); it!=winSet2.end(); it++)
		{
			for(unsigned i=0;i<N;++i){
				for(unsigned j=0;j<N;++j)
						cout<<it->matrix[i][j]<<" ";
				cout<<endl;
			}
			cout<<endl;
		}
	}
	void print_board()
	{
		for(unsigned i=0;i<N;++i){
			for(unsigned j=0;j<N;++j)
				cout<<board.matrix[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}

	//return which player has won
	Player winnerIs()    //need to be optimized
	{
		//check two disgonals
		Player flag=board.matrix[0][0];
		unsigned i=1;
		for(;i<N;++i){
			if(board.matrix[i][i] != flag)
				break;
		}
		if(i==N) return flag;

		flag=board.matrix[0][N-1];
		i=1;
		for(;i<N;++i){
			if(board.matrix[i][N-i-1] != flag)
				break;
		}
		if(i==N) return flag;



		//check all the rows
		Player winner=NoOne;
		for(unsigned row=0;row<N;++row){
			Player flag=NoOne;
			unsigned col=0;
			for(;col<N;++col){//check if the row has same symbols
				if(board.matrix[row][col]==NoOne) {break;}
				if(col==0){
					flag=board.matrix[row][col];
				}
				else{
					if(flag!=board.matrix[row][col]) break;
				}
			}
			if(col == N){
				if(winner!=NoOne)
					return Invalid;
				else winner=flag;
			}
		}
		if(winner!=NoOne) return winner;

		for(unsigned col=0;col<N;++col){  //check all the columns
			Player flag=NoOne;
			unsigned row=0;
			for(;row<N;++row){//check if the column has same symbols
				if(board.matrix[row][col]==NoOne) {break;}
				if(row==0){
					flag=board.matrix[row][col];
				}
				else{
					if(flag!=board.matrix[row][col]) break;
				}
			}
			if(row == N){
				if(winner!=NoOne)
					return Invalid;
				else winner=flag;
			}
		}


		return winner;
	}

	void preprocess_sets(unsigned row, unsigned col)
	{

		if(row==N-1 && col == N ){
			//print_board();
			Player winner=winnerIs();;
			if( p1Symbol==p2Symbol+1 || p1Symbol==p2Symbol)
			{

				if(winner== Player1)
					winSet1.push_back(board);

			}
			if(p2Symbol==p1Symbol+1 || p1Symbol==p2Symbol){

				if(winner == Player2)
					winSet2.push_back(board);
			}

			return;
		}
		if(col==N){ col=0;row++;}

		//put 3 symbols into board[row][col] respectively
		board.matrix[row][col]=NoOne;
		preprocess_sets(row,col+1);


		{
			board.matrix[row][col]=Player1;
			p1Symbol++;
			preprocess_sets(row,col+1);
			p1Symbol--;
		}

		{
			board.matrix[row][col]=Player2;
			p2Symbol++;
			preprocess_sets(row,col+1);
			p2Symbol--;
		}

		board.matrix[row][col]=NoOne;
	}



	bool checkWin(unsigned row, unsigned col, Player p)
	{
		 assert(row>=0 && row<N && col>=0 && col<N && (p==Player1 || p==Player2));
		 assert(board.matrix[row][col]==NoOne);//this postion is not in use

		 board.matrix[row][col]=p;

		 if(p==Player1){
			 if( find(winSet1.begin(),winSet1.end(), board) !=winSet1.end())
				 return true;
		 }
		 else {
			 if( find(winSet2.begin(),winSet2.end(), board) !=winSet2.end())
				 return true;
		 }
		return false;
	}
	void run()
	{
		Player curPlayer=Player1;
		unsigned row=N,col=N,step=0;
		while(true){
			row=N,col=N;
			cout<<"Player "<<curPlayer<<" input position:"<<endl;

			cout<<"row:";
			cin>>row;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
			if(row>=N ){
				cout<<"Row input is not valid, input again"<<endl;
				continue;
			}


			cout<<"column:";
			cin>>col;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
			if(col>=N ){
				cout<<"Col input is not valid, input again"<<endl;
				continue;
			}

			if(board.matrix[row][col]!=NoOne){
			 cout<<"this postion has been used, input again"<<endl;//this postion is not in use
			 continue;
			}

			step++;
			bool win=checkWin(row,col,curPlayer);
			print_board();
			if(curPlayer==Player1  ){
				curPlayer=Player2;
				if(win){
					cout<<"Player1 win!"<<endl;
					exit(0);
				}
			}
			else if(curPlayer==Player2  ){
				curPlayer=Player1;
				if(win){
					cout<<"Player2 win!"<<endl;
					exit(0);
				}
			}

			if(step==N*N){
				cout<<"Draw!"<<endl;
				exit(0);
			}
		}
	}

	Tic_tac_toe()
	{
		p1Symbol=0,p2Symbol=0;
		//preprocessing winSet
		preprocess_sets(0,0);
		//print_winSet();
		clean_board();
		run();
	};
};


int main()
{
	Tic_tac_toe<3> tic;
	return 0;
}

