//Cách 1 : Tính toán trực tiếp bằng vòng lặp for
//Độ phức tạp : O(|n|)

// FUNCTION Vong_Lap(n):
//     IF n >= 0 THEN
//         SET result = 1
//         FOR i FROM 0 TO n-1:
//             result = result * 2
//         END FOR
//         PRINT result 
//     ELSE
//         SET result = 1
//         FOR i FROM 0 TO -n-1:
//             result = result * 2
//         END FOR
//         PRINT (1 / result)

//Cách 2 : Dùng phép dịch bit
// Độ phức tạp: O(1)

// FUNCTION Dich_Bit(n): 
//     IF n >= 0 THEN
//         PRINT (1 << n) 
//     ELSE
//         PRINT (1 / (1 << -n)) 

//Chương trình
#include<iostream>
using namespace std;
void Vong_Lap(int n)  // Độ phức tạp: O(|n|)
{
    double result = 1;
    if (n >= 0) {
        for (int i = 0; i < n; i++) {
            result *= 2; 
        }
        cout << result << endl;  
    } 
    else {
        for (int i = 0; i < -n; i++) {
            result *= 2; 
        }
        cout << (1 / result) << endl; 
    }
}
void Dich_Bit(int n)  // Độ phức tạp: O(1)
{
    if (n >= 0) {
        cout << (1 << n) << endl;
    } else {
        cout << (1.0 / (1 << -n)) << endl;
    }
}
int main()
{
    int n ;
    cin>>n;
    Vong_Lap(n);
    cout<<endl;
    Dich_Bit(n);
    cout<<endl;
    return 0;
}