class Solution {
public:
    long helper (long firsthalf,bool odd){
        long res = firsthalf;
        if(odd){
            firsthalf/=10;
        }
        while(firsthalf > 0){
            res = res*10 + (firsthalf%10);
            firsthalf /= 10;
        }
        return res;
    }
    string nearestPalindromic(string n,string chk = "") {
       vector<long> anss;
       int siz = n.size();
       bool odd = (siz%2 != 0);
       int mid = (odd) ? (siz/2 + 1) : (siz/2);
       long firsthalf = stoll(n.substr(0,mid));
       anss.push_back(helper(firsthalf,odd));
       anss.push_back(helper(firsthalf + 1,odd));
       anss.push_back(helper(firsthalf - 1,odd));

       anss.push_back((long)(pow(10,siz - 1) - 1));
       anss.push_back((long)(pow(10,siz) + 1));
       long num = stoll(n);
       long minDiff = LLONG_MAX;
       long res = LLONG_MAX;

       for(auto it : anss){
        if(it == num) continue;
        long curr = abs(it - num);
        if(curr < minDiff){
            // cout<<it<<"  - current element "<<endl;
            res = it;
            minDiff = curr;
        }
        else if(curr == minDiff){
            res =  min(res,it);
        }
       }
       return to_string(res);
    }
};