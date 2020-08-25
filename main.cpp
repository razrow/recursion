//p10 Recursion
//Rowan Briggs
//May 23, 2018
/* Description:
Implement and test the following from the recursion lecture
- Merge Sort

- Binary Search (Iterative & Recursive)

- Factorial (Iterative and Recursive)

- Triangle (Iterative and Recursive)

- Implement the following method recursively
 */

#include <iostream>
#include <iomanip>
using namespace std;

class Recursion{
public:
    //triangle Iterative
    int triangleIterative(int num){
        int total = 0;
        while (num > 0) {
        total = total + num;
        num--;
        }
        return total;
    }
    //triangle recursive
    int triangleRecursive(int num){
        //for triangle(1), return 1
        //for triangle(2), return 2 + triangle(1) = return (2 + 1) = return 3
        //for triangle(3), return 3 + triangle(2) = return (3 + 3) = return 6
        //for triangle(4), return 4 + triangle(3) = return (4 + 6) = return 10
        if (num == 1){
            return 1;
        }
        else {
            return (num + triangleRecursive(num - 1));
        }
    }
    //factorial iterative
    int factorialIterative(int num) {
        int total = 1;
        while(num > 0) {
            total = total * num;
            num--;
        }
        return total;
    }
    //factorial recursive
    int factorialRecursive(int num) {
        if (num == 0){
            return 1;
        }
        else{
            return num * factorialRecursive(num-1);
        }
    }
    //binary search iterative
    void binarySearchIterative(int guess, int numToGuess, int count, int upperLimit, int lowerLimit){
        //assumes that 1) guess is between upper and lower limit
        //assumes that 2) numToGuess is between upper and lower limit
        while(true){
            if(guess == numToGuess){
                cout << "\nYou guessed it in " << count << " iterative tries\n";
                break;
            }
            else if(guess > numToGuess){
                upperLimit = guess;
                guess = (upperLimit + lowerLimit) / 2;
            }
            else if(guess < numToGuess){
                lowerLimit = guess;
                guess = (upperLimit + lowerLimit) / 2;
            }
            count++;
        }
    }
    //binary search recursive
    void binarySearchRecursive(int guess, int numToGuess, int count, int upperLimit, int lowerLimit){
        //assumes that 1) guess is between upper and lower limit
        //assumes that 2) numToGuess is between upper and lower limit
        if(guess == numToGuess){
            cout << "\nYou guessed it in " << count << " recursive tries\n";
        }
        else if(guess > numToGuess){
            upperLimit = guess;
            guess = (upperLimit + lowerLimit) / 2;
            binarySearchRecursive(guess, numToGuess, count + 1, upperLimit, lowerLimit);
        }
        else if(guess < numToGuess){
            lowerLimit = guess;
            guess = (upperLimit + lowerLimit) / 2;
            binarySearchRecursive(guess, numToGuess, count+1, upperLimit, lowerLimit);
        }
    }
    //compoundInterest Recursively
    void compoundInterestRecursive(double monthlyDeposit, double interest,
                                  int years, int year, double total,
                                  double payments, double interestEarned){
        if(year <= years){
            total += monthlyDeposit*12;
            total = total + total*(interest/100);
            payments += monthlyDeposit*12;
            interestEarned = total - payments;
            cout << "REC at end of year " << setw(2) << year;
            cout << " : total savings " << setw(7) << total;
            cout << " : total payments " << setw(5) << payments;
            cout << " : interestEarned " << interestEarned;
            cout << endl;
            year++;
            compoundInterestRecursive(monthlyDeposit, interest, years, year, total, payments, interestEarned);
        }
    }
    //compoundInterest Iterative
    void compoundInterestIterative(double monthlyDeposit, double interest, int years){
        double total = 0, payments = 0, interestEarned;
        cout << endl;
        for(int year = 1; year <= years; year++){
            total += monthlyDeposit*12;
            total = total + total*(interest/100);
            payments += monthlyDeposit*12;
            interestEarned = total - payments;
            cout << "at end of year " << setw(2) << year;
            cout << " : total savings " << setw(7) << total;
            cout << " : total payments " << setw(5) << payments;
            cout << " : interestEarned " << interestEarned;
            cout << endl;
        }
    }
};

class DArray{
private:
    double *array;
    int nElems;
public:
    DArray(int max){
        array = new double[max];
        nElems = 0;
    }
    void insert(double value){
        array[nElems++] = value;
    }
    void display(){
        for(int j = 0; j < nElems; j++){
            cout << array[j] << " ";
        }
        cout << endl;
    }
    void mergeSort(){
        double *workSpace = new double[nElems];
        recMergeSort(workSpace, 0, nElems-1);
    }
    //merge sort recursive
    void recMergeSort(double *workSpace, int lowerBound, int upperBound){
        if(lowerBound == upperBound) {
            return;
        }
        else{
            int mid = (lowerBound+upperBound) /2;
            recMergeSort(workSpace, lowerBound, mid); //sort lower half
            recMergeSort(workSpace, mid+1, upperBound); //sort high half
            merge(workSpace, lowerBound, mid+1, upperBound); //merge them
        } //end else
    }
    //merge (needed for mergeSort)
    void merge(double *workSpace, int lowPtr, int highPtr, int upperBound){
        int j = 0;
        int lowerBound = lowPtr;
        int mid = highPtr - 1;
        int n = upperBound - lowerBound + 1; //a of items
        while(lowPtr <= mid && highPtr <= upperBound){
            if (array[lowPtr] < array[highPtr] ) {
                workSpace[j+1] = array[lowPtr++];
            }
            else {
                workSpace[j++] = array[highPtr++];
            }
        }

        while(lowPtr <= mid){
            workSpace[j++] = array[lowPtr++];
        }
        while(highPtr <= upperBound){
            workSpace[j++] = array[highPtr++];
        }
        for (j=0; j<n; j++){
            array[lowerBound+j] = workSpace[j];
        }
    } //end of merge
};

int main() {
    //triangle iterative
    Recursion *rec = new Recursion;
    cout << "triangleIterative(1):" << rec->triangleIterative(1) << endl;
    cout << "triangleIterative(2):" << rec->triangleIterative(2) << endl;
    cout << "triangleIterative(3):" << rec->triangleIterative(3) << endl;
    cout << "triangleIterative(4):" << rec->triangleIterative(4) << endl;
    //triangle recursive
    cout << "triangleRecursive(1):" << rec->triangleRecursive(1) << endl;
    cout << "triangleRecursive(2):" << rec->triangleRecursive(2) << endl;
    cout << "triangleRecursive(3):" << rec->triangleRecursive(3) << endl;
    cout << "triangleRecursive(4):" << rec->triangleRecursive(4) << endl;
    //factorial Iterative
    cout << "factorialIterative(1):" << rec->factorialIterative(1) << endl;
    cout << "factorialIterative(2):" << rec->factorialIterative(2) << endl;
    cout << "factorialIterative(3):" << rec->factorialIterative(3) << endl;
    cout << "factorialIterative(4):" << rec->factorialIterative(4) << endl;
    //factorial Recursive
    cout << "factorialRecursive(1):" << rec->factorialRecursive(1) << endl;
    cout << "factorialRecursive(2):" << rec->factorialRecursive(2) << endl;
    cout << "factorialRecursive(3):" << rec->factorialRecursive(3) << endl;
    cout << "factorialRecursive(4):" << rec->factorialRecursive(4) << endl;
    //binary search iterative
    rec->binarySearchIterative(5,2,1,100,1);
    //binary search recursive
    rec->binarySearchRecursive(5,2,1,100,1);
    //merge Sort
    DArray *arr = new DArray(100);
    arr->insert(64);
    arr->insert(21);
    arr->insert(33);
    arr->insert(70);
    arr->insert(12);
    arr->insert(85);
    arr->insert(44);
    arr->insert(3);
    arr->insert(99);
    arr->insert(8);
    arr->insert(108);
    arr->insert(36);
    arr->display();
    arr->mergeSort();
    arr->display();
    //compound Interest Iterative
    rec->compoundInterestIterative(200.00,5,20);
    //compound interest Recursive
    rec->compoundInterestRecursive(200.00,5, 20, 1, 0, 0, 0);
    return 0;
}
/* Output
triangleIterative(1):1
triangleIterative(2):3
triangleIterative(3):6
triangleIterative(4):10
triangleRecursive(1):1
triangleRecursive(2):3
triangleRecursive(3):6
triangleRecursive(4):10
factorialIterative(1):1
factorialIterative(2):2
factorialIterative(3):6
factorialIterative(4):24
factorialRecursive(1):1
factorialRecursive(2):2
factorialRecursive(3):6
factorialRecursive(4):24

You guessed it in 3 iterative tries

You guessed it in 3 recursive tries
64 21 33 70 12 85 44 3 99 8 108 36
36 108 8 0 0 0 0 0 0 0 0 0

at end of year  1 : total savings    2520 : total payments  2400 : interestEarned 120
at end of year  2 : total savings    5166 : total payments  4800 : interestEarned 366
at end of year  3 : total savings  7944.3 : total payments  7200 : interestEarned 744.3
at end of year  4 : total savings 10861.5 : total payments  9600 : interestEarned 1261.51
at end of year  5 : total savings 13924.6 : total payments 12000 : interestEarned 1924.59
at end of year  6 : total savings 17140.8 : total payments 14400 : interestEarned 2740.82
at end of year  7 : total savings 20517.9 : total payments 16800 : interestEarned 3717.86
at end of year  8 : total savings 24063.8 : total payments 19200 : interestEarned 4863.75
at end of year  9 : total savings 27786.9 : total payments 21600 : interestEarned 6186.94
at end of year 10 : total savings 31696.3 : total payments 24000 : interestEarned 7696.29
at end of year 11 : total savings 35801.1 : total payments 26400 : interestEarned 9401.1
at end of year 12 : total savings 40111.2 : total payments 28800 : interestEarned 11311.2
at end of year 13 : total savings 44636.7 : total payments 31200 : interestEarned 13436.7
at end of year 14 : total savings 49388.6 : total payments 33600 : interestEarned 15788.6
at end of year 15 : total savings   54378 : total payments 36000 : interestEarned 18378
at end of year 16 : total savings 59616.9 : total payments 38400 : interestEarned 21216.9
at end of year 17 : total savings 65117.7 : total payments 40800 : interestEarned 24317.7
at end of year 18 : total savings 70893.6 : total payments 43200 : interestEarned 27693.6
at end of year 19 : total savings 76958.3 : total payments 45600 : interestEarned 31358.3
at end of year 20 : total savings 83326.2 : total payments 48000 : interestEarned 35326.2
REC at end of year  1 : total savings    2520 : total payments  2400 : interestEarned 120
REC at end of year  2 : total savings    5166 : total payments  4800 : interestEarned 366
REC at end of year  3 : total savings  7944.3 : total payments  7200 : interestEarned 744.3
REC at end of year  4 : total savings 10861.5 : total payments  9600 : interestEarned 1261.51
REC at end of year  5 : total savings 13924.6 : total payments 12000 : interestEarned 1924.59
REC at end of year  6 : total savings 17140.8 : total payments 14400 : interestEarned 2740.82
REC at end of year  7 : total savings 20517.9 : total payments 16800 : interestEarned 3717.86
REC at end of year  8 : total savings 24063.8 : total payments 19200 : interestEarned 4863.75
REC at end of year  9 : total savings 27786.9 : total payments 21600 : interestEarned 6186.94
REC at end of year 10 : total savings 31696.3 : total payments 24000 : interestEarned 7696.29
REC at end of year 11 : total savings 35801.1 : total payments 26400 : interestEarned 9401.1
REC at end of year 12 : total savings 40111.2 : total payments 28800 : interestEarned 11311.2
REC at end of year 13 : total savings 44636.7 : total payments 31200 : interestEarned 13436.7
REC at end of year 14 : total savings 49388.6 : total payments 33600 : interestEarned 15788.6
REC at end of year 15 : total savings   54378 : total payments 36000 : interestEarned 18378
REC at end of year 16 : total savings 59616.9 : total payments 38400 : interestEarned 21216.9
REC at end of year 17 : total savings 65117.7 : total payments 40800 : interestEarned 24317.7
REC at end of year 18 : total savings 70893.6 : total payments 43200 : interestEarned 27693.6
REC at end of year 19 : total savings 76958.3 : total payments 45600 : interestEarned 31358.3
REC at end of year 20 : total savings 83326.2 : total payments 48000 : interestEarned 35326.2

Process finished with exit code 0
 */