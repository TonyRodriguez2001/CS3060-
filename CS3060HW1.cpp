

#include <iostream>
#include <iomanip>

#define WAGE 25.0
#define GAL_COVERAGE 110
#define HOURS_PER_GAL 8.0

using namespace std;

//paintNeeded method prototype
double paintNeeded(double area);

//laborTime method prototype
double laborTime(double area);

//getNumRooms method prototype
double getNumRooms();

//getPaintPrice method prototype
double getPaintPrice();

//laborCost method prototype
double laborCost(double time);

//getRoomArea method prototype
double getRoomArea(int roomNum);

//printReceipt method prototype
void printReceipt(double *totals[]);

int main(int argc, const char * argv[]) {
    
    //prompting for and storing the number of rooms in the numRooms variable by
    //utilizing the getNumRooms method
    double numRooms = getNumRooms();
    double paintPrice = getPaintPrice();
    
    //variables that will hold totals
    double totalPaint = 0.0, totalLaborTime = 0.0, totalPaintCost = 0.0, totalLaborCost = 0.0, entireCost = 0.0;
    double *totalsData[5] = {&totalPaint, &totalLaborTime, &totalPaintCost, &totalLaborCost, &entireCost};
    
    //for loop executes the same number of times as there are rooms and collects the totals
    //for each room
    for(int i = 0; i < numRooms; i++){
        
        double area = getRoomArea(i+1);
            
         totalPaint += paintNeeded(area);
         
         totalLaborTime += laborTime(area);
         
         totalPaintCost += paintPrice * paintNeeded(area);
         
         totalLaborCost += laborCost(laborTime(area));
         
         entireCost += totalLaborCost + totalPaintCost;
            
    }//for(int i = 0; i < numRooms; i++)
    
    printReceipt(totalsData);
    
    return 0;
}//Main


//The paintNeeded method calculates the amount of paint that will be needed in gallons
//based on the area to be painted. The value is then returned in gallons as a double.
double paintNeeded(double area){
    return area / GAL_COVERAGE;
}//paintNeeded()


//The laborTime method calculates the amount of labor time that will be needed
//to paint based on the square footage. The time is then returned in hours as a double.
double laborTime(double area){
    return (area / GAL_COVERAGE) * HOURS_PER_GAL;
}//laborTime()


//The getNumRooms method prompts the user for the number of rooms to be painted
//and obtains the value through standard input. The value is then returned as a double.
double getNumRooms(){
    double numRooms;
    
    //Prompting for and and storing the number of rooms
    cout << "How many rooms will be painted: " << endl;
    cin >> numRooms;
    
    //While loop catches invalid input and reprompts user
    while(numRooms < 1){
        cout << "The value entered is not valid!" << "\nRe-enter your value for number of rooms: " << endl;
        cin >> numRooms;
    }//while(numRooms < 1)
    
    return numRooms;
}//getNumRooms()


//The getPaintPrice method prompts the user for the price of each gallon of paint
//and obtains the value through standard input. The value is then returned as a double.
double getPaintPrice(){
    double paintPrice;
    
    //Prompting for and and storing the price per gallon of paint
    cout << "What is price per gallon of paint?: " << endl;
    cin >> paintPrice;
    
    //While loop catches invalid input and reprompts user
    while(paintPrice < 10.00){
        cout << "The value entered is not valid!" << "\nRe-enter your value for paint price: " << endl;
        cin >> paintPrice;
    }//while(paintPrice < 10.00)
    
    return paintPrice;
}//getPaintPrice()


double laborCost(double time){
    return time * WAGE;
}//laborCost()


//The getRoomArea method prompts the user for the area of a certain room
//and obtains the value through standard input. The value is then returned as a double.
double getRoomArea(int roomNum){
    double area;
    
    //Prompting for and and storing the area of the room
    cout << "\n\nEnter the area for room " << roomNum << ":" << endl;
    cin >> area;
    
    
    //While loop catches invalid input and reprompts user
    while(area < 0){
        
        cout << "ONLY POSITIVE VALUES ARE ACCEPTED\n" << "Re-enter the area for room " << roomNum << ":" << endl;
        cin >> area;
        
    }//while(area < 0)
    
    return area;
}//getRoomaArea()


//The printReceipt method takes in an array of pointers to doubles that store
//the information to be printed
void printReceipt(double *totals[]){
    
    cout << fixed << setprecision(2) << "\n***************************************************************\n" <<
    "Total gallons of paint required: " << *totals[0] << " gallons\n" << "Total hours of labor required: " <<
    *totals[1] << " hours\n" << "Total cost of paint: $" << *totals[2] << endl << "Total cost of labor: $" <<
    *totals[3] << endl << "TOTAL: $" << *totals[4] << endl;
    
}
