#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> rail;
    vector<int> station;
    int num, max, former;
    for(;;){
        cin >> num;
        rail.push_back(num);
        if(cin.get() == '\n'){
            break;
        }
    }
    for(int i = 1; i < rail[0]; i++){
        station.push_back(i);
    }

    max = rail[0];
    former = rail[0];
    for(int i = 1; i < rail.size() - 1; i++){
        if(rail[i] > max){
            for(int j = max+1; j < rail[i]; j++){
                station.push_back(j);
            }
            max = rail[i];
        }
        else if(rail[i] < former){
            if(rail[i] == former-1){
                station.pop_back();
                former--;
            }
            else{
                cout << "不正確";
                // cout << endl << max << endl;
                // for(auto &k : station){
                //     cout << k << ' ';
                // }
                return 0;
            }
        }
    }
    cout << "正確";
    // for(auto &i : rail){
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for(auto &i : station){
    //     cout << i << ' ';
    // }
    return 0;
}