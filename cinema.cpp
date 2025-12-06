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
void displaySeats(int r, int c, int freeSeat, int reservedSeat, vector<vector<char>>& reserveSeats){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "(" << i << "-" << j << " " << reserveSeats [i][j] <<")  ";
        }
    cout << "\n";
    }
    cout << "\n";
    cout << "Total free seats= " << freeSeat << endl;
    cout << "Total Reserved Seats= " << reservedSeat << endl;
    
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
void reserveFunction(int r, int c, int& rowIn, int& columnIn, vector<vector<char>>& reserveSeats){
    
        cout << "Enter row and column to reserve seat: ";
        cin >> rowIn >> columnIn;

        while (true) {
            if (rowIn >= r || columnIn >= c) {
                cout << rowIn << columnIn << " is an invalid seat number\n";
                cout << "Enter row and column: ";
                cin >> rowIn >> columnIn;
                continue;
            }

            if (reserveSeats[rowIn][columnIn] == 'R') {
                cout << rowIn << columnIn << " is already reserved\n";
                cout << "Enter row and column: ";
                cin >> rowIn >> columnIn;
                continue;
            }
        reserveSeats[rowIn][columnIn] = 'R';
        break;
    }
    }   
    
    
    // change the availibility of seat to free
void freeFunction(int r, int c, int& rowIn, int& columnIn, vector<vector<char>>& reserveSeats){
        
        cout << "Enter row and column to free seat: ";
        cin >> rowIn >> columnIn;
        
        while (true) {
            if (rowIn >= r || columnIn >= c) {
                cout << rowIn << columnIn << " is an invalid seat number\n";
                cout << "Enter row and column: ";
                cin >> rowIn >> columnIn;
                continue;
            }

            if (reserveSeats[rowIn][columnIn] == 'F') {
                cout << rowIn << columnIn << " is already free\n";
                cout << "Enter row and column: ";
                cin >> rowIn >> columnIn;
                continue;
            }
        reserveSeats[rowIn][columnIn] = 'F';
        break;
    }
}
    

int main() {
    
    int rows, columns, numOfSeats, rowIn, columnIn, totalAmount = 0;
    
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    cout << "Enter the number of columns: ";
    cin >> columns;
    
    int freeSeats = (rows*columns), reservedSeats = 0;
    cout << "\n";
    vector<vector<char>> reserveSeats (rows, vector<char>(columns));
    
    // Get all seats empty
    emptySeats(rows, columns, reserveSeats);
    
    // Display Seats Plan
    displaySeats(rows, columns, freeSeats, reservedSeats, reserveSeats);
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
        reserveFunction(rows, columns, rowIn, columnIn, reserveSeats);
        reservedSeats++;
        freeSeats--;
        userAmount += seatPrice(rowIn);
        totalAmount += seatPrice(rowIn);
        displaySeats(rows, columns, freeSeats, reservedSeats, reserveSeats);
        cout << "\n";
        cout <<"Your Total bill = " << userAmount << endl;
    }
    
    bool runLoop = true;
    do{
        
    
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
                       reserveFunction(rows, columns,  rowIn, columnIn, reserveSeats);
                       reservedSeats++;
                       freeSeats--;
                       userAmount += seatPrice(rowIn);
                       totalAmount += seatPrice(rowIn);
                       displaySeats(rows, columns, freeSeats, reservedSeats, reserveSeats);
                       cout << "\n";
                       cout <<"Your Total bill = " << userAmount << endl;
                    }
            break;
            case 2: freeFunction(rows, columns, rowIn, columnIn, reserveSeats);
                    reservedSeats--;
                    freeSeats++;
                    displaySeats(rows, columns, freeSeats, reservedSeats, reserveSeats);
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