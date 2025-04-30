//COMP 1602 - assignment 4
//816019037 - BRANDON RAMPERSAD


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <conio.h>

using namespace std;

struct Case {
	int num;
	int dnum; //displayed in ui
	int value;
	int dvalue; //displayed in ui
	bool displayNum;
	bool displayVal;
};


int intNumCases; //integer value of the number of cases chosen
char numCases[2]; // corresponding cstring value of the number of cases
//int cashvalue[26]; // array with the values of each case
int rounds[11]; //array with with the data on rounds 


//this function takes the number of cases and creates a cstring value for use later
int getNumCases (int intNumCases, char numCases[]){
	
	cout<<"Welcome to Deal or No Deal (With a Twist)! "<<endl;
	cout<<"How many cases do you want in the game? (16, 18, 20, 22, 24, 26)  ";
	cin>>intNumCases;
	
	if(intNumCases != 16&&intNumCases != 18&&intNumCases != 20&&intNumCases != 22&&intNumCases != 24&&intNumCases != 26 ){
	cout<<"Please choose a valid number of cases"<<endl;
}
	
	if(intNumCases==16)
		strcpy(numCases, "16");
	if(intNumCases==18)
		strcpy(numCases, "18");
	if(intNumCases==20)
		strcpy(numCases, "20");
	if(intNumCases==22)
		strcpy(numCases, "22");
	if(intNumCases==24)
		strcpy(numCases, "24");
	if(intNumCases==26)
		strcpy(numCases, "26");
		
		//cout<<numCases;
		
	return intNumCases;
}

//this function opens the file with the corresponding name using the cstring value
// and fills the arrays with data from file
void readfile (char numCases[],int intNumCases, int cashvalue[], int rounds[]){  
	
	
	char file[10];
	strcpy(file, "Data");
	strcat(file, numCases);
	strcat(file, ".txt");
	//cout<<"test"<<file;
	
	ifstream in;
	in.open(file);
	if(!in.is_open()){
		cout<<"Error...file could not be opened";
		return ;
	}
	
	int a;
	//reads in the monetary values for each case
	for (int x=0;x<intNumCases;x++){
		in>>a;
		cashvalue[x]=a;
//		cout<<cashvalue[x]<<endl;
	}
	//reads in the num of rounds and number of cases to open for each round. (rounds[0] = num of rounds)
		int x=0;
		in>>a;
		
	while(!in.eof()){
		rounds[x]=a;
	//	cout<<rounds[x]<<endl;
		x++;
		in>>a;
	
		
	}
		
	
	
}

//fills the cases with data from the arrays
void fillCases (Case cases[], int intNumCases, int cashvalue[]){
	
	for (int x=0;x<intNumCases;x++){
		cases[x].num = x+1;
		cases[x].dnum = x+1;
		cases[x].value = cashvalue[x];
		cases[x].displayNum = true;
		cases[x].displayVal = true;
	}
	
	return ;
}

//checks to see if the  case has a specific value or not
bool hasValue (Case cases[], int cashvalue, int intNumCases) {
		int x;
		bool found = false;
	for (x=0;x<intNumCases;x++){
		if ( cases[x].value ==cashvalue)
		found = true;
	}

	return found;
}

//randomly assigns the values of money to different cases everytime
void shuffleCases (Case cases[],Case newCase[], int intNumCases, int cashvalue[]){
	int b = 0;
	//Case newCase[intNumCases];
	int r1;
	
	
//	if(question.responses.shuffle==1){
		
		srand((time(0)));
		
	
		
		while (b<intNumCases){
			
		//	srand((time(0)));
			
			bool contains;
		
			r1 = 0 + rand() % ((intNumCases-1) - 0 + 1);
			contains = hasValue(newCase, cashvalue[r1], intNumCases );
			if (contains == true){
			}
			else{
				newCase[b].num = cases[b].num;
				newCase[b].dnum = cases[b].dnum;
				newCase[b].displayNum =cases[b].displayNum;
				newCase[b].displayVal =cases[b].displayVal;
				newCase[b].value = cashvalue[r1];
				newCase[b].dvalue = cashvalue[r1];
				b++;
			}
		}

	return;
	
}
	
//prints the board with all available values of money remaining	
void printMoneyboard(Case cases[], int intNumCases, Case newCase[]){
	
	int h = intNumCases/2;
	
	cout<<"-----------MONEYBOARD-----------"<<"\n";
	
	for (int x=0; x<h; x++){
		
	bool found1 = false;
	cout<<"|  ";
		for(int y=0;y<intNumCases;y++){
		
			if (newCase[y].value == cases[x].value && newCase[y].displayVal == true){
			cout<<newCase[y].value;
			found1 = true;
		}
	}
		if(found1 == false){
			cout<<"   ";
		}
	cout<<"          ";
bool found2 = false;
		for(int y=0;y<intNumCases;y++){
		
			if (newCase[y].value == cases[h+x].value && newCase[y].displayVal == true){
			cout<<newCase[y].value;
			found2 = true;
		}
	}
		if(found2 == false){
			cout<<"   ";
		}
	
	cout<<"\n";
}
	cout<<"-------------------------------"<<"\n";

	
}

//prints cases remaining
void printCaseboard(Case cases[], int intNumCases, Case newCase[]){
	
	int h = intNumCases/2;
	
	cout<<"------------------------  "<<"\n";
	cout<<"|         CASES                    "<<"\n"<<"|"<<"\n";
	
	for (int x=0; x<h; x++){
		
	bool found1 = false;
	cout<<"|  ";
		for(int y=0;y<intNumCases;y++){
		
			if (newCase[y].num == cases[x].num && newCase[y].displayNum == true){
			cout<<newCase[y].num;
			found1 = true;
		}
	}
		if(found1 == false){
			cout<<" ";
		}
	cout<<"          ";
bool found2 = false;
		for(int y=0;y<intNumCases;y++){
		
			if (newCase[y].num == cases[h+x].num && newCase[y].displayNum == true){
			cout<<newCase[y].num;
			found2 = true;
		}
	}
		if(found2 == false){
			cout<<" ";
		}
	
	cout<<"\n";
}
	cout<<"----------------------"<<"\n";

	
}






//function to pick the first case separate it so it cant be chosen again	
int firstCase(Case newCase[]){
	
	int first;
	
	cout<<"You must now pick a starting case. "<<endl;
	bool exit = false;
	
	while (exit==false){
	cin>>first;
	if(first<=intNumCases && first>=1 && newCase[first-1].displayNum == true){
		cout<<"You picked case "<<first<<"."<<endl;
		newCase[first-1].displayNum = false;
		exit == true;
		break;
	}
	else{
		cout<<"please enter a valid case number."<<endl;
		}
	}
	
	return first-1;

}	


//function to pick a case, and remove it from the boards
int pickCase(Case newCase[]){
	
	int pick;
	
	cout<<"Please select a case: ";
	bool exit = false;
	
	while (exit==false){
	cin>>pick;
	if(pick<=intNumCases && pick>=1 && newCase[pick-1].displayNum == true){
		cout<<"The value of case "<<pick<<" is $"<<newCase[pick-1].value<<endl;
		newCase[pick-1].displayNum = false;
		newCase[pick-1].displayVal = false;
		exit = true;
		break;
	}
	else{
		cout<<"please choose an unopened case"<<endl;
		cin>>pick;
		}
	}
	
	return newCase[pick-1].value;

}

//function to play the last rounds where player can swap cases with the first case
int lastround(int first, Case newCase[]){
	
	int num;
	cout<<"Do you want to keep your case (1) or do you want to swap with the last case? (0) ";
	cin>>num;
	
	if(num==1){
		cout<<"Your case is "<<newCase[first].num<<"."<<endl;
		cout<<"Congratulations! You WON $"<<newCase[first].value<<".";
		return newCase[first].value;
	}
	if(num==0){
		cout<<"Swapping your case "<<newCase[first].num<<" with ";
		for(int y=0;y<intNumCases;y++){
		
			if (newCase[y].displayNum == true){
			cout<<newCase[y].num<<"."<<endl;
			cout<<"Congratulations! You WON $"<<newCase[y].value<<".";
			return newCase[y].value;
		//	break;
		}
	}
}
		
//return 0;
	
}

//fucntion to get the average of the remaining cases
int getAverage(Case newCase[], int intNumCases ){
	
	int count=0;
	int total=0;
	
	for(int x=0;x<intNumCases;x++){
		
		if(newCase[x].displayNum == true){
			count = count+1;
			total = total+newCase[x].value;
		}
	}
	
	int average = total/count;
	
	return average;
	
}

//BONUS FUNCTION - Randomly assigns a x3 multiplier to one of three boxes everytime, and a X0.5 in the rest.
//                 Allows the player to triple their earnings if they choose a correct box , or lose half :(

int bonus(float winnings){
	
	int ans2;
	int randNum;
	
	
		cout<<endl<<" You made it to the end, BUT WAIT! There is a secret bonus MULTIPLIER round! "<<endl<<"Would you like a chance to WIN BIG (1) or go home (2)? ";
		cin>>ans2;
			while(ans2!=1&&ans2!=2)
			cout<<endl<<"Press 1 to risk it or 2 to leave and go home."<<endl;
		if(ans2==1){
			cout<<endl<<"Multipliers are placed RANDOMLY in 3 boxes. They will either TRIPLE your winnings or HALF it."<<"\n"<<"In 2 there are x0.5 & in one there is a x3!"<<endl;
			
			srand((time(0)));
		//generate a random number from one to three , for the three possible cases	
			randNum = 1 + rand()% (3 - 1 + 1);
	
	//case 1		
	if (randNum == 1){
				cout<<" =======  =======  ======= "<<endl;
				cout<<"|       ||       ||       |"<<endl;
				cout<<"|   1   ||   2   ||   3   |"<<endl;
				cout<<" =======  =======  ======= "<<endl;
				
				int choice;
				cout<<"Choose a box! 1, 2, or 3."<<endl; // player can choose box
				cin>>choice;
				cout<<" =======  =======  ======= "<<endl;
				cout<<"|       ||       ||       |"<<endl;
				cout<<"| x0.5  ||  x3   || x0.5  |"<<endl;
				cout<<" =======  =======  ======= "<<endl; // prints inside
				
				while(choice!=1&&choice!=2&&choice!=3){
					cout<<"Pick 1 2 or 3";
					cin>>choice;
				}
				
				if(choice==2){
						cout<<"YOU WON X3!"<<endl;
						cout<<"Your new winnings is $"<<winnings*3; //multiplies their winning by 3
						cout<<endl<<"THANKS FOR PLAYING!";
						return 0;
					}
				else{
						cout<<"You lost half ..."<<endl;
						cout<<"Your new winnings is $"<<(winnings*0.5); // divides their winnings in half
						cout<<endl<<"THANKS FOR PLAYING!";
						return 0;
					}
				}
	if (randNum == 2){
				cout<<" =======  =======  ======= "<<endl;
				cout<<"|       ||       ||       |"<<endl;
				cout<<"|   1   ||   2   ||   3   |"<<endl;
				cout<<" =======  =======  ======= "<<endl;
				
				int choice;
				cout<<"Choose a box! 1, 2, or 3."<<endl;
				cin>>choice;
				cout<<" =======  =======  ======= "<<endl;
				cout<<"|       ||       ||       |"<<endl;
				cout<<"|   x3  || x0.5  || x0.5  |"<<endl;
				cout<<" =======  =======  ======= "<<endl;
				
				while(choice!=1&&choice!=2&&choice!=3){
					cout<<"Pick 1 2 or 3";
					cin>>choice;
				}
				
				if(choice==1){
						cout<<"YOU WON X3!"<<endl;
						cout<<"Your new winnings is $"<<winnings*3;
						cout<<endl<<"THANKS FOR PLAYING!";
						return 0;
					}
				else{
						cout<<"You lost half ..."<<endl;
						cout<<"Your new winnings is $"<<(winnings*0.5);
						cout<<endl<<"THANKS FOR PLAYING!";
						return 0;
					}
				}
	if (randNum == 3){
				cout<<" =======  =======  ======= "<<endl;
				cout<<"|       ||       ||       |"<<endl;
				cout<<"|   1   ||   2   ||   3   |"<<endl;
				cout<<" =======  =======  ======= "<<endl;
				
				int choice;
				cout<<"Choose a box! 1, 2, or 3."<<endl;
				cin>>choice;
				cout<<" =======  =======  ======= "<<endl;
				cout<<"|       ||       ||       |"<<endl;
				cout<<"| x0.5  || x0.5  ||   x3  |"<<endl;
				cout<<" =======  =======  ======= "<<endl;
				
				while(choice!=1&&choice!=2&&choice!=3){
					cout<<"Pick 1 2 or 3";
					cin>>choice;
				}
				
				if(choice==3){
						cout<<"YOU WON X3!"<<endl;
						cout<<"Your new winnings is $"<<winnings*3;
						cout<<endl<<"THANKS FOR PLAYING!";
						return 0;
					}
				else{
						cout<<"You lost half ..."<<endl;
						cout<<"Your new winnings is $"<<(winnings*0.5);
						cout<<endl<<"THANKS FOR PLAYING!";
						return 0;
					}
				}			
		
}

}

//function to play the game and call the previous functions
int playGame(Case newCase[], Case cases[], int rounds[], int intNumCases,int first){
	
	int avg,ans;
	float f;
	float offer;
	float winnings;
	
	//Goes throught each round from the rounds array above until the final-1 round (final round is different)
	for(int x=0; x<rounds[0]-1; x++){
		
		cout<<"We are in round "<<x+1<<endl;
		cout<<"You must choose "<<rounds[x+1]<<" cases this round. "<<endl;
		
		//goes throuhg the different amount of cases per round (from rounds array)
		for (int r=0; r<rounds[x+1]; r++){
			
			printCaseboard(cases, intNumCases, newCase);
			pickCase(newCase);
			printMoneyboard(cases,intNumCases,newCase);		
		}
		
		avg = getAverage(newCase, intNumCases);
	//	cout<<"average: "<<avg;
		f = ((float)(x+1)/rounds[0]);
	//	cout<<f;
		offer = avg*f;
		cout<<"This is what the banker offers: $"<<offer<<endl;
		cout<<"Deal (1) or No Deal (2)   ";
		cin>>ans;
		while(ans!=1&&ans!=2)
			cout<<"DEAL (PRESS 1) OR NO DEAL (PRESS 2)"<<endl;
		if(ans==1){
			cout<<"Congratulations! You WON $"<<offer<<endl;
			winnings = offer;
			return 0;
		}
		if(ans==2){
			cout<<endl;
		}
	}
		winnings = lastround(first, newCase);
		bonus(winnings);
		
	return 0;
}







//main function
int main(){
	

	intNumCases = getNumCases(intNumCases, numCases);    //get the number of cases from player
	int cashvalue[intNumCases];                           // initialize array for money values
	readfile(numCases,intNumCases, cashvalue,rounds);     //read corresponding file with data 


	Case cases[intNumCases];                              //init. case array
	fillCases(cases, intNumCases, cashvalue);			//fill each struct in case the array 
	Case newCases[intNumCases];                         // makes NEW array for randomized money values per case
	shuffleCases(cases, newCases, intNumCases, cashvalue);  // randomizes cases into new array
	
//	printMoneyboard(cases, intNumCases, newCases);
	
	
	int first;											//variable to hold the first case and remember it
	printMoneyboard(cases, intNumCases, newCases);      
	printCaseboard(cases, intNumCases, newCases);
	first = firstCase(newCases);                         //get the first case separately
	
	playGame(newCases, cases, rounds, intNumCases,first);  //call play game function from above.


	
	
	return 0;
}
