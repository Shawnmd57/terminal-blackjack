/* Program name: blackjack.cpp
*  Author: Shawn Daumer
*  Date last updated: 11/3/22
* Purpose: play a game of blackjack
*/
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>      /* printf, scanf, puts, NULL */

using namespace std;


//generated random number between 1-10;
int drawcard(){
    int newcard;
    newcard = rand() % 10 + 1;
    //possible wait function for when player draws 2 cards? makes for larger time gap between draws.
    return newcard;
};



int main(){
    
int usermoney = 100;    //user starts with $100.
int round = 0;  //used to track how many rounds are played;
int choice;  //used for user input when in stand/draw stage of game;
bool endgame = false;
int bet;

//start game loop
while( endgame == false){
    bool endround = false; //used to reset hands, rounds are counted;

    //round counter
round = round + 1;
cout<<endl<<endl<<endl<<"Round: "<<round<<endl<<endl;

//shows users current balance
cout<<"current balance: "<<usermoney<<endl<<endl;

    //prompt user to input bet amount
cout<<"place bet amount: ";
cin>>bet;

while(bet > usermoney){
    cout<<"you cannot bet more than you have"<<endl;
    cin>>bet;
};
 while( bet < 1){
    cout<<"bet must be greater than 0"<<endl;
    cin>>bet;
 }

//at this point bet is placed, dealer "flips" 1st card, 

int draw = drawcard(); //assigns "draw" a random value derived from previously called "drawcard" function
int dealerhand = draw;
cout<<endl<< "dealer's first card's value is "<< dealerhand<<endl;

//user gets delt 2 cards
draw = drawcard();
int playerhand = draw;
cout<<"first card: "<<draw<<endl; //after drawing 1st card, shows its value;
draw = drawcard();
cout<<"second card: "<<draw<<endl; //after drawing 2nd card, shows its value;
playerhand = playerhand + draw;
cout<<"hand value: "<<playerhand<<endl<<endl;   //shows user total value of hand;


if (dealerhand == 21){
    usermoney = usermoney - bet;
    endround = true;
}
 else if(playerhand == 21){
    usermoney = usermoney + bet;
    endround = true;
}
else if(playerhand == 21 && dealerhand == 21){
    int push;
    endround = true;
};
if(dealerhand < 21 && playerhand < 21){
endround = false;
}

if (endround == false){
    //prompts user to draw, stand, surrender or double (if options is avalible)
    if (usermoney >= bet*2){
        cout<< "1 (draw), 2 (stand), 3 (double) or 4 (surrender): ";
        cin>>choice;
            while (choice > 4){
                cout<<endl<< "you must choose either draw, stand, double or surrender"<<endl;
                cin>> choice;
                }  //users choice to draw or stand (when offer to double is unavalible)
                }else{
                    cout<< "1 (draw) or 2 (stand): " <<endl;
                    cin>>choice;
                        while (choice > 2){
                            cout<< "you must choose either draw, stand, or surrender"<<endl;
                            cin>> choice;
                        }
                } 

    if (choice == 1){
        draw = drawcard();
        cout<<endl<< "card drawn: "<<draw<<endl;
        playerhand = playerhand + draw;
        cout<<"playerhand value: "<<playerhand<<endl;
       
    }else if(choice == 2){
        draw = drawcard();
        cout <<"dealer flips card with value of "<<draw<<endl;
        dealerhand = dealerhand + draw;
        cout<<"dealer's hand: "<<dealerhand<<endl;
        while (dealerhand < 17){
            draw = drawcard();
        cout <<"dealer draws card with value of : "<<draw<<endl;
        dealerhand = dealerhand + draw;
        cout<< "dealer's hand: "<<dealerhand<<endl;
        }
        if (dealerhand > 21){
            cout<< "dealer bust"<<endl;
            usermoney = usermoney + bet;
        }else if(dealerhand > playerhand){
            cout<<"dealer wins"<<endl;
            usermoney = usermoney - bet;
        }else if (dealerhand < playerhand){
            cout<<"you win"<<endl;
            usermoney = usermoney + bet;
        }
        endround = true;
        
        }else if(choice == 3){
        bet = bet * 2;
        cout<< "new bet: "<<bet<<endl;
        draw = drawcard();
        cout<< "card drawn: "<<draw<<endl;
        playerhand = playerhand + draw;
        cout<<"playerhand value: "<<playerhand<<endl;
        draw = drawcard();
        cout<< "Dealer draws card with value of : "<<draw<<endl;
        dealerhand = dealerhand + draw;
        cout<<"dealers hand is "<<dealerhand<<endl;
        endround = true;
        //dealer draws, round ends;
    }else if(choice == 4){
        bet = (bet / 2);
        cout<< "bet cut in half, round loss: "<<bet<<endl;
        usermoney= usermoney - bet;
        endround = true;
    }

       while(playerhand < 21 && endround == false){
        cout<<endl<<"1 (draw) or 2 (stand): ";
        cin>>choice;
        cout<<endl;
            while (choice > 2){
                cout<< endl<<"you must choose either 1 (draw) or 2 (stand)"<<endl;
                cin>> choice;
            };

    if (choice == 1){
        draw = drawcard();
        cout<<endl<< "card drawn: "<<draw<<endl;
        playerhand = playerhand + draw;
        cout<<"playerhand value: "<<playerhand<<endl;
       
    }else if(choice == 2){
        draw = drawcard();
        cout <<"dealer flips card with value of "<<draw<<endl;
        dealerhand = dealerhand + draw;
        cout<<"dealer's hand: "<<dealerhand<<endl;
        while (dealerhand < 17){
            draw = drawcard();
        cout <<"dealer draws card with value of "<<draw<<endl;
        dealerhand = dealerhand + draw;
        cout<< "dealer's hand: "<<dealerhand<<endl;
        }
        if (dealerhand > 21){
            cout<<endl<< "dealer bust"<<endl;
            usermoney = usermoney + bet;
        }else if(dealerhand > playerhand){
            cout<<endl<<"dealer wins"<<endl;
            usermoney = usermoney - bet;
        }else if (dealerhand < playerhand){
            cout<<endl<<"you win"<<endl;
            usermoney = usermoney + bet;
        }
        endround = true;
        
        }
    }
    if(choice < 4){
    if (playerhand == 21){
        cout<<"Blackjack!"<<endl;
        usermoney = usermoney + bet;
        cout<<"$"<<bet<<" added to your wallet"<<endl; 
    }else if (playerhand > 21){
        cout<<endl<<"Bust..."<<endl;
        usermoney = usermoney - bet;
        cout<<"$"<<bet<<" lost."<<endl<<endl;
    }else if(dealerhand > playerhand){
        cout<<endl<<"dealer wins"<<endl;
        usermoney = usermoney - bet;
    }else if (dealerhand < playerhand){
        cout<<endl<<"you win"<<endl;
        usermoney = usermoney + bet;
        }
    }
} //'if endround == false' end

if(usermoney <= 0){ //If user runs out of money.
int refill;
    cout<<"you're out of money! "<<"Want to refill your wallet?"<<endl;
    cout<<"1 (yes), 2 (no); ((selecting 2 (no) will end game!))";
    cin>>refill;
    if(refill == 1){
        usermoney = 50;
        cout<<endl<< "$50 added to your wallet"<<endl;
    }else{
        cout<<endl<<"play again soon!"<<endl;
        endgame = true;
    }
}

};  //gameloop end

return 0;
};//main function end