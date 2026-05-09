// 	11945	Financial Management
#include <bits/stdc++.h>
using namespace std;

string convert (double avg){
    avg = round(avg * 100.0) / 100.0;    
    stringstream ss;
    ss << fixed << setprecision(2) << avg;
    string s = ss.str();  
    int pos = s.find(".");
    string int_part = s.substr(0, pos);
    string dec_part = s.substr(pos + 1);  
    int sz = (int)int_part.size();
    for (int i = sz - 3; i > 0; i -= 3){
        int_part.insert(i, ",");
    }
    return int_part + "." + dec_part;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++){
        double avg, sum = 0.0;
        for (int i = 0; i < 12; i++){
            double m;
            cin >> m;
            sum += m;
        }
        avg = sum / 12.0;
        cout << tc << " $" << convert(avg) << "\n";
    } 

    return 0;
}
