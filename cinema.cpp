#include <iostream>
#include <vector>
using namespace std;

void reserveFunction(int r, int c, int seatNum, vector<vector<char>>& reserveSeats){
    
        cout << "Enter seat number to reserve: ";
        cin >> seatNum;
        while (reserveSeats [seatNum/10][seatNum%10] == 'R' || seatNum/10 >= r || seatNum%10 > c){
            if (reserveSeats [seatNum/10][seatNum%10] == 'R' ){
                    cout << seatNum << " is already reserved\n";
                    cout << " Enter seat number to reserve: ";
                    cin >> seatNum;
                } else if (seatNum/10 >= r || seatNum%10 > c) {
                    cout << seatNum << " is an invalid seat number\n";
                    cout << "Enter seat number to reserve: ";
                    cin >> seatNum;
                    }
            } 
            reserveSeats [seatNum/10][seatNum%10] = 'R';
               
}

int main() {
    
    int rows, columns;
    
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    cout << "Enter the number of columns: ";
    cin >> columns;
    
    vector<vector<char>> reserveSeats (rows, vector<char>(columns));
    
    // Display Seats Plan
    for (int i = 0; i < rows; i++){
        for (int j = 1; j <= columns; j++){
            reserveSeats [i][j] = 'F';
            cout << "(" << i << "-" << j << " " << reserveSeats [i][j] <<")  ";
        }
    cout << "\n";
    }
    
    // Enter seats to reserve
    int seatNumber;
    cout << "Enter seat number to reserve: ";
    cin >> seatNumber;
    
    reserveSeats [seatNumber/10][seatNumber%10] = 'R';
    
    bool runLoop = true;
    
    
    
    // Run Loop to reserve and unreserve seats
    while (runLoop){
        
    for (int i = 0; i < rows; i++){
        for (int j = 1; j <= columns; j++){
            cout << "(" << i << "-" << j << " " << reserveSeats [i][j] <<")  ";
        }
    cout << "\n";
    }
    
    // Menu
       int option, freeSeat = 1;
      
       cout << "What do you want?\n";
       cout << "1. Reserve a seat\n";
       cout << "2. Free a seat\n";
       cout << "0. to exit\n";
       cout << "Enter: ";
       cin >> option;
    
        switch (option){
            case 1:
            break;
            case 2: cout << "Enter seat number to unreserve: ";
                cin >> seatNumber;
                while (reserveSeats [seatNumber/10][seatNumber%10] == 'F' || seatNumber/10 >= rows || seatNumber%10 > columns){
                    if (reserveSeats [seatNumber/10][seatNumber%10] == 'F' ){
                        cout << seatNumber << " is already free\n";
                        cout << " Enter seat number to free: ";
                       cin >> seatNumber;
                    } else if (seatNumber/10 >= rows || seatNumber%10 > columns) {
                        cout << seatNumber << " is an invalid seat number\n";
                        cout << "Enter seat number to free: ";
                       cin >> seatNumber;
                    }
                }
                reserveSeats [seatNumber/10][seatNumber%10] = 'F';
            break;
            case 0: runLoop = false;
            break;
            default: cout << "Invalid Option\n";
            break;
        }
    }
    
    
    return 0;
}