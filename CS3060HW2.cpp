#include <iostream>
#include <iomanip>

const int NUM_MONKEYS = 3;
const int DAYS = 5;

using namespace std;


//method that prompts the user to enter the food eaten
//by the monkeys over the amount of days
void inputInfo(double arr[][DAYS]);


//Calculates the average amount of food eaten per day
//by the family of monkeys
void calcFamilyFood(double arr[][DAYS]);


//Calculate the least amount of food eaten during the
//week by one monkey
void calcLeastEaten(double arr[][DAYS]);


//Calculate the least amount of food eaten during the
//week by one monkey
void calcMostEaten(double arr[][DAYS]);

int main(int argc, const char * argv[]) {
    
    //2d array of doubles that will hold our
    //values
    double monkeys[NUM_MONKEYS][DAYS];
    
    
    inputInfo(monkeys);
    calcFamilyFood(monkeys);
    calcLeastEaten(monkeys);
    calcMostEaten(monkeys);
    
    
    return 0;
}

void inputInfo(double arr[][DAYS]){
    
    
    //prompting for values and filling the 2d array
    for(int i = 0; i < NUM_MONKEYS; i++){
        for(int j = 0; j < DAYS; j++){
            
            cout << "\nEnter the amount of food eaten by monkey " << i + 1 <<
            " on day " << j + 1 << endl;
            
            cin >> arr[i][j];
            
            
            //while loop will handle errors and reprompt
            //if the user inputs invalid input
            while(arr[i][j] < 0){
                cout << "\nNegative input not valid!\nRe-enter the amount of food eaten by monkey " << i + 1 <<
                " on day " << j + 1 << endl;
                
                cin >> arr[i][j];
            }//while(arr[i][j] < 0)
            
        }//for(int j = 0; j < DAYS; j++)
    }//for(int i = 0; i < NUM_MONKEYS; i++)
    
}


void calcFamilyFood(double arr[][DAYS]){
    
    double sum = 0.0;
    
    for(int i = 0; i < NUM_MONKEYS; i++){
        for(int j = 0; j < DAYS; j++){
            sum += arr[i][j];
        }//for(int j = 0; j < DAYS; j++)
    }//for(int i = 0; i < NUM_MONKEYS; i++)
    
    //calculating average
    double mean = sum / DAYS;
    
    //printing the reults
    cout << fixed << setprecision(2) << "\n\nAverage amount of food eaten per day by the whole family of monkeys is: " << mean << " lbs." << endl;

}

void calcLeastEaten(double arr[][DAYS]){
    
    double smallest = 0.0;
    int leastMonkey = 0;

    //traverses the rows (monkeys)
    for(int i = 0; i < NUM_MONKEYS; i++){
        double sum = 0.0;
        
        //traverses the columns (days of the week)
        for(int j = 0; j < DAYS; j++){
            sum += arr[i][j];
        }
        
        //if first iteration smallest = sum
        smallest = (i == 0) ? smallest = sum : smallest = smallest;
        
        
        if(smallest > sum){
            smallest = sum;
            leastMonkey = i + 1;
        }

    }
    
    //printing results
    cout << fixed << setprecision(2) << "The monkey that ate the least through out the week was monkey " << leastMonkey << " that ate a total of " << smallest << " lbs. of food." << endl;
}


void calcMostEaten(double arr[][DAYS]){
    
    double largest = 0.0;
    int mostMonkey = 0;
    
    //traverses the rows (monkeys)
    for(int i = 0; i < NUM_MONKEYS; i++){
        double sum = 0.0;
        
        ////traverses the columns (days of the week)
        for(int j = 0; j < DAYS; j++){
            sum += arr[i][j];
        }
        
        largest = (i == 0) ? largest = sum : largest = largest;
        
        if(largest < sum){
            largest = sum;
            mostMonkey = i + 1;
        }
    }
    
    //printing results
    cout << setprecision(2) << "The monkey that ate the most throughout the week was monkey " << mostMonkey << " that ate a total of " << largest << " lbs. of food.\n" << endl;
}

