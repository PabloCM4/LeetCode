#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers
{
public:
private:
    // Creating the stream vector to store the numbers
    vector<int> stream;

public:
    ProductOfNumbers() {};

    // Adding the number to the stream vector
    void add(int num)
    {
        stream.push_back(num);
    }

    // Getting the product of the last k numbers in the stream vector
    int getProduct(int k)
    {
        int sum = 1;
        for (int i = 1; i <= k; i++)
        {
            sum *= stream[stream.size() - i];
        }
        return sum;
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

//-------------------------------// Smarter solution //------------------------------------------//

//  class ProductOfNumbers {
// private:
// Creating the stream vector to store the numbers
//     vector<int> stream;

// public:
// Constructor to initialize the stream vector with 1
//     ProductOfNumbers() {
//         stream.push_back(1);
//     }

// Adding the number to the stream vector, clearing everything if the number is 0, and multiplying the last number in the stream vector with the new number
// This way we always have the product of all number in the back of the stream vector, and if we have a 0, we clear everything and start again
//     void add(int num) {
//         if (num == 0) {
//             stream.clear();
//             stream.push_back(1);
//         } else {
//             stream.push_back(stream.back() * num);
//         }
//     }

// Gett the value in the back (product of all numbers) and divide it by the value in the stream vector that is k positions back
// This way we get the product of the last k numbers.
// Returning 0 if k is greater than the size of the stream vector (covering the case where there was a cleared 0)
//     int getProduct(int k) {
//         int size_stream = stream.size();

//         if (k >= size_stream) {
//             return 0;
//         }

//         return stream.back() / stream[size_stream - k - 1];
//     }
// };

// /**
//  * Your ProductOfNumbers object will be instantiated and called as such:
//  * ProductOfNumbers* obj = new ProductOfNumbers();
//  * obj->add(num);
//  * int param_2 = obj->getProduct(k);
//  */

int main()
{
    ProductOfNumbers productOfNumbers;

    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);

    int results[] = {
        productOfNumbers.getProduct(2),
        productOfNumbers.getProduct(3),
        productOfNumbers.getProduct(4),
    };
    int expected[] = {20, 40, 0};

    for (int i = 0; i < 3; ++i)
    {
        cout << "Example " << i + 1
             << ": expected = " << expected[i]
             << ", got = " << results[i] << '\n';
    }

    productOfNumbers.add(8);
    int result = productOfNumbers.getProduct(2);

    cout << "Example 4: expected = 32"
         << ", got = " << result << '\n';

    return 0;
}