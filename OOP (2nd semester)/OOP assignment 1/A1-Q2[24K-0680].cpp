
#include<iostream>
#include<string>
//#include<tuple>
using namespace std;

class Robot{
	string name;
	static int hits;
	public:
		Robot(string n):name(n){
		}
		void hitBall(int &ballX, int &ballY,const string &direction);
		void resetHit(){
		    hits=0;
		}
		int final_hits(){
			return hits;
		}
};

int Robot::hits=0;

class Ball{
    public:
	    int x,y;
		Ball(int x,int y){
			this->x=x;
			this->y=y;
		}
		int getX();
		int getY();
		void move(int dx,int dy);
		
//   		tuple<int, int> getPosition() const {
//        return make_tuple(x, y);
//    	}		
};

class Goal{
	public:
		int i;
		int flag;
		Goal(){
			i=1;
		}
		int isGoalReached(int ballX, int ballY){
			if(ballX!=3 || ballY!=3){
				cout<<"Ball doesnot reach the goal"<<endl;
				flag=0;
			}
			else{
				cout<<"Congragulations! Team '"<<i<<"' have scored the goal"<<endl<<endl<<endl;
				i++;
				flag=1;
			}
			return flag;
		}
};

class Team {
    string teamName;
public:
    string name;
    Robot *robot;  

    Team(string n) : teamName(n) {
        cout << "Enter name of the Robot: ";
        cin >> name;
        robot = new Robot(name);  
    }
    ~Team() {
        delete robot;
    }
};


class Game{
	int score1;
	int score2;
	int i;
	public:
		Ball ball;
		Goal goal;
		Game() : ball(0, 0) {i=0;}
		void startGame(){
			cout<<"Game is started and the current coordinates are  (0,0)"<<endl;
		}
		int play(Team *team) {
		  	team->robot->resetHit();
        int flag;
        	string direction;
        
        while (true) {
            cout<<"Enter horizontal direction (up/down/right/left): ";
            cin>>direction;
            
            team->robot->hitBall(ball.x,ball.y,direction);
            
            cout << "Ball Position: (" << ball.getX() << ", " << ball.getY() << ")" << endl;

			flag = goal.isGoalReached(ball.getX(), ball.getY());
	        if (flag == 1) {
	            return team->robot->final_hits(); 
	        }
                
        }
    }
	void declareWinner(Team *team1, Team *team2,int score1,int score2) {
    	cout << team1->name << " took " << score1 << " hits." << endl;
    	cout << team2->name << " took " << score2 << " hits." << endl;

    	if (score1 < score2) {
        	cout << "Team1`s ROBOT " << team1->name << " WINS with fewer hits!" << endl;
    	} else if (score1 < score2) {
        	cout << "Team2`s ROBOT " << team2->name << " WINS with fewer hits!" << endl;
    	} else {
	        cout << "It's a DRAW! Both teams took the same number of hits." << endl;
    	}
	}
};


void Robot::hitBall(int &ballX, int &ballY, const string &direction){

	if (direction=="up"){
		ballY++;
	}
	if(direction=="down"){
		ballY--;}
 
	if(direction=="right"){
		ballX++;
	}
	if(direction=="left"){
		ballX--;}

	hits++;
}

int Ball::getX(){
	return x;
}
int Ball::getY(){
	return y;
}
void Ball::move(int dx,int dy){
	x=dx;
	y=dy;
}

int main() {
	int hit1,hit2;
    Team t1("Warrior");
    Team t2("Spartan");

    Game game1,game2;
    game1.startGame();

    hit1 = game1.play(&t1);
    hit2 = game2.play(&t2);

    game1.declareWinner(&t1, &t2,hit1,hit2);

    return 0;
}




