#include <iostream>
#include <vector>
using namespace std;

// To assign all seats empty for first time
void emptySeats(int r, int c, vector<vector<char>>& reserveSeats){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            reserveSeats [i][j] = 'F';
        }
    }
}

// First show complete theater seating plan and seats numbers
void displaySeats(int r, int c, vector<vector<char>>& reserveSeats){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "(" << i << "-" << j << " " << reserveSeats [i][j] <<")  ";
        }
    cout << "\n";
    }
    
}

// Price of different seats
void priceList(){
    cout << "Front 2 row = 1000\n";
    cout << "Middle 3 rows = 600\n";
    cout << "Last  rows = 350\n";
}

// find price of selected seat
int seatPrice(int rowIn){
    int price = 0;
    if (rowIn <= 1){
        price = 1000;
    } else if (rowIn <= 4){
        price = 600;
    }else {
        price = 350;
    }
    return price;
}

// change the availability of seat to reserve
void reserveFunction(int r, int c,vector<vector<char>>& reserveSeats){
    
        int rowIn, columnIn;
        cout << "Enter row number to reserve seat: ";
        cin >> rowIn;
    
        cout << "Enter column number to reserve seat: ";
        cin >> columnIn;
        while (rowIn >= r || columnIn >= c || reserveSeats [rowIn][columnIn] == 'R' ){
            if (reserveSeats [rowIn][columnIn] == 'R' ){
                    cout << rowIn << columnIn << " is already reserved\n";
                    cout << "Enter row number to reserve seat: ";
                    cin >> rowIn;
    
                    cout << "Enter column number to reserve seat: ";
                    cin >> columnIn;
                } else if (rowIn >= r || columnIn > c) {
                    cout << rowIn << columnIn << " is an invalid seat number\n";
                    cout << "Enter row number to reserve seat: ";
                    cin >> rowIn;
    
                    cout << "Enter column number to reserve seat: ";
                    cin >> columnIn;
            }
        }
        reserveSeats [rowIn][columnIn] = 'R';
    }   
    
    
    // change the availibility of seat to free
void freeFunction(int r, int c, vector<vector<char>>& reserveSeats){
        int rowIn, columnIn;
        cout << "Enter row number to free seat: ";
        cin >> rowIn;
    
        cout << "Enter column number to free seat: ";
        cin >> columnIn;
                while (reserveSeats [rowIn][columnIn] == 'F' || rowIn >= r || columnIn >= c){
                    if (reserveSeats [rowIn][columnIn] == 'F' ){
                        cout << rowIn << columnIn << " is already free\n";
                        cout << "Enter row number to free seat: ";
                        cin >> rowIn;
    
                        cout << "Enter column number to free seat: ";
                        cin >> columnIn;
                    } else if (rowIn >= r || columnIn >= c) {
                        cout << rowIn << columnIn << " is an invalid seat number\n";
                        cout << "Enter row number to free seat: ";
                        cin >> rowIn;
    
                        cout << "Enter column number to free seat: ";
                       cin >> columnIn;
                    }
                }
                reserveSeats [rowIn][columnIn] = 'F';
    }
    

int main() {
    
    int rows, columns, numOfSeats, rowIn, columnIn, totalAmount = 0,;
    
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    cout << "Enter the number of columns: ";
    cin >> columns;
    
    int reserveSeats = (rows*columns), freeSeats = 
    cout << "\n";
    vector<vector<char>> reserveSeats (rows, vector<char>(columns));
    
    // Get all seats empty
    emptySeats(rows, columns, reserveSeats);
    
    // Display Seats Plan
    displaySeats(rows, columns, reserveSeats);
    cout << "\n";
    // Ask user for number of seats
    cout << "How many seats you needed?\n";
    cout << "Number of seats: ";
    cin >> numOfSeats;
    cout << "\n";
    priceList();
    cout << "\n";
    // Enter seats to reserve and show amounts
    int userAmount = 0;
    for (int i = 1; i <= numOfSeats; i++){
        cout << "Enter row number to reserve seat no " << i << ": ";
        cin >> rowIn;
        cout << "Enter column number to reserve seat no "<< i << ": ";
        cin >> columnIn;
        reserveSeats [rowIn][columnIn] = 'R';
        userAmount += seatPrice(rowIn);
        totalAmount += seatPrice(rowIn);
        cout << "\n";
        cout <<"Your Total bill = " << userAmount << endl;
    }
    
    bool runLoop = true;
    do{
        displaySeats(rows, columns, reserveSeats);
    
       // Menu
       int option;
      
       cout << "\n";
       cout << "What do you want?\n";
       cout << "1. Reserve a seat\n";
       cout << "2. Free a seat\n";
       cout << "3. Show Total Amount of sold out tickets\n";
       cout << "0. to exit\n";
       cout << "Enter: ";
       cin >> option;
       cout << "\n";
       
        switch (option){
            case 1:priceList();
                    cout << "How many seats you needed?\n";
                    cout << "Number of seats: ";
                    cin >> numOfSeats;
                    userAmount = 0;
                    for (int i = 1; i <= numOfSeats; i++){ 
                       reserveFunction(rows, columns, reserveSeats);
                       userAmount += seatPrice(rowIn);
                       totalAmount += seatPrice(rowIn);
                       cout << "\n";
                       cout <<"Your Total bill = " << userAmount << endl;
                    }
            break;
            case 2: freeFunction(rows, columns, reserveSeats);
                    totalAmount -= seatPrice(rowIn);
            break;
            case 3: cout << "Total sold out amount= " << totalAmount << endl;
            break;
            case 0: runLoop = false;
            break;
            default: cout << "Invalid Option\n";
            break;
        }
    }while (runLoop);
    
    
    return 0;
}        