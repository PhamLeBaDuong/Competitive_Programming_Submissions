#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n & 1) {
        if((n/2)&1) {
            cout << "YES" << endl;
            cout << n/2+1 << endl;
            auto temp = n/2;
            int i = 1;
            while(temp > 0) {
                cout << i << " " << n-i << " ";
                temp -= 2;
                i++;
            }
            cout << endl << n/2 << endl;
            cout << n << " ";
            temp = n/2;
            while(temp > 1) {
                cout << i << " " << n-i << " ";
                temp-=2;
                i++;
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else {
        if((n/2) % 2 == 0) {
            cout << "YES" << endl;
            cout << n/2 << endl;
            auto temp = n/2;
            int i = 1;
            while(temp > 0) {
                cout << i << " " << n+1-i << " ";
                temp -= 2;
                i++;
            }
            cout << endl << n/2 << endl;
            temp = n/2;
            while(temp > 1) {
                cout << i << " " << n+1-i << " ";
                temp-=2;
                i++;
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}