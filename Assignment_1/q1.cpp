// #include <iostream>
// using namespace std;
// int main() {
// int n = 5;
// for(int i = 1; i <= n; i++) {
// for(int j = 1; j <= n; j++) {
// if(i == j)
// cout << "A ";
// else if(i + j == n + 1)
// cout << "B ";
// else if(i > j)
// cout << "C ";
// else
// cout << "D ";
// }
// cout << endl;
// }
// }

// #include <iostream>
// using namespace std;
// int main() {
// int arr[5] = {3, 1, 4, 1, 5};
// for(int i = 0; i < 5; i++) {
// for(int j = i; j < 5; j++) {
// if(arr[i] < arr[j])
// cout << arr[j] - arr[i] << " ";
// else if(arr[i] == arr[j])
// cout << "0 ";
// else
// cout << arr[i] - arr[j] << " ";
// }
// cout << endl;
// }
// }

#include <iostream>
using namespace std;
int main() {
    int n = 4;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 3 && j == 2)
            continue;
            if(i + j > 5)
            break;
            if((i * j) % 2 == 0)
            cout << i * j << " ";
            else
            cout << i + j << " ";
            }
    cout << endl;
    }
}