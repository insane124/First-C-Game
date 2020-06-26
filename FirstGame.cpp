#include<iostream>
#include<ctime>
using namespace std;

void DisplayImage()
{

    cout << " __      .__   __.          _______.          ___          .__   __.      _______ " << endl;
    cout << "|  |     |  \\ |  |         /       |         /   \\         |  \\ |  |     |   ____|" << endl;
    cout << "|  |     |   \\|  |        |   (----`        /  ^  \\        |   \\|  |     |  |__   " << endl;
    cout << "|  |     |  . `  |         \\   \\           /  /_\\  \\       |  . `  |     |   __|  " << endl;
    cout << "|  |     |  |\\   |     .----)   |         /  _____  \\      |  |\\   |     |  |____ " << endl;
    cout << "|__|     |__| \\__|     |_______/         /__/     \\__\\     |__| \\__|     |_______|" << endl;
    cout << "" << endl;
}

void PrintIntro(int Difficulty)
{
    //Print Welcome Message
    cout<<"\n\nWelcome to the XXX Game!"<<endl;
    cout<<"Level Difficulty: "<<Difficulty;
    cout << "\nGuess the correct codes and break in to the system!\n";
    cout << "Enter the correct codes to breach the security and continue the game to other levels...\n\n";
}

bool PlayGame(int Difficulty)
{

    PrintIntro(Difficulty);

    //Declare variables
    const int CodeA=rand()%Difficulty+3; //adding difficulty will set the rand number to be generated within difficulty value(EX:difficulty=5 then rand numbers will be 0,1,2,3,4)
    const int CodeB=rand()%Difficulty+3; //adding +3 will increase the random numbers generate by 3 more numbers (EX:if rand number is 3 then + 3 will make it generate 6 numbers)
    const int CodeC=rand()%Difficulty+3;

    const int CodeSum=CodeA+CodeB+CodeC;
    const int CodeProduct=CodeA*CodeB*CodeC;


    //Print Sum and Product
    cout<<"There are three numbers in the code\n";
    cout<<"+The three numbers sum(addition) gives: "<<CodeSum<<endl;
    cout<<"*The three numbers product(multiplication) gives: "<<CodeProduct<<endl;

    int GuessA,GuessB,GuessC;

    //Getting input from user
    cout<<"Enter your answer(Please hit enter after you type each number!):"<<endl;
    cin>>GuessA;
    cin>>GuessB;
    cin>>GuessC;
    
    cout << "You Entered: "<<GuessA<<GuessB<<GuessC<<endl;
   
    //Checking the entered value with stored value
    const int GuessSum=GuessA+GuessB+GuessC;
    const int GuessProduct=GuessA*GuessB*GuessC;

    //Output the result after checking the result
    if(GuessSum==CodeSum && GuessProduct==CodeProduct)
    {
        cout<<"Congrats! You have Entered the correct Code!\n\n\n";
        return true;
    }
    else
    {
        cout<<"OOPS! You have Entered the wrong Code!"<<endl<<"Try Again!\n\n\n"<<endl;
        return false;
    }
}

    int main()

{
    srand(time(NULL));

    int LevelDifficulty=1;      //Current level difficulty
    int const MaxDifficulty=11; //Maximum Difficulty
    DisplayImage();

    while(LevelDifficulty<=MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();  // Clears any errors
        cin.ignore(); // Discards the Buffer(If we enter string or any other datatype value, the code restarts!)

        if(bLevelComplete)
        {
            //Increase the level difficulty
            ++LevelDifficulty;

        }
    }   

    cout<<"\n***Great Work! You have cracked all the codes and completed the mission!***\n";
    cout<<"\n Developed by Prajwal.N\n"<<endl;
    
    return 0;
    
    
}

        