#include <iostream>
using namespace std;

int main() {
    
    int rows, columns;
    
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    cout << "Enter the number of coloumns: ";
    cin >> columns;
    
    char reserveSeats [rows][columns];
    
    for (int i = 0; i < rows; i++){
        for (int j = 1; j <= columns; j++){
            reserveSeats [i][j] = 'F';
            cout << "(" << i << "-" << j << " " << reserveSeats [i][j] <<")  ";
        }
    cout << "\n";
    }
    
    int seatNumber;
    cout << "Enter seat number to reserve: ";
    cin >> seatNumber;
    
    reserveSeats [seatNumber/10][seatNumber%10] = 'R';
    
    bool runLoop = true;
    
    while (runLoop){
        
    for (int i = 0; i < rows; i++){
        for (int j = 1; j <= columns; j++){
            cout << "(" << i << "-" << j << " " << reserveSeats [i][j] <<")  ";
        }
    cout << "\n";
    }
    
    
       int option, freeSeat = 1;
      
       cout << "What do you want?\n";
       cout << "1. Reserve a seat\n";
       cout << "2. Free a seat\n";
       cout << "0. to exit\n";
       cout << "Enter: ";
       cin >> option;
    
        switch (option){
            case 1: cout << "Enter seat number to reserve: ";
                cin >> seatNumber;
                while (reserveSeats [seatNumber/10][seatNumber%10] == 'R' || seatNumber/10 >= rows || seatNumber%10 > columns){
                    if (reserveSeats [seatNumber/10][seatNumber%10] == 'R' ){
                        cout << seatNumber << " is already reserved\n";
                        cout << " Enter seat number to reserve: ";
                       cin >> seatNumber;
                    } else if (seatNumber/10 >= rows || seatNumber%10 > columns) {
                        cout << seatNumber << " is an invalid seat number\n";
                        cout << "Enter seat number to reserve: ";
                       cin >> seatNumber;
                    }
                } 
                reserveSeats [seatNumber/10][seatNumber%10] = 'R';
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