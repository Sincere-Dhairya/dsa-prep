#include<bits/stdc++.h>

using namespace std;

bool checksubstring(string s){
    if(s.length() <= 1) return true;
    if(s.front() == s.back()) return checksubstring(s.substr(1, s.length()-2));
    else return false;
}

string findlongestpalindromesubstring1(string s){
    string ans = "";
        
    for(int i =1 ;i <=s.length(); i++){
        for(int j = 0; j<=s.length()-i; j++){
            string temp = s.substr(j, i);
            bool check = checksubstring(temp);
            if(check && temp.length() > ans.length()) {
                ans = temp;
                break;
            } 
        }
    }
    return ans;
}

string findlongestpalindromesubstring2(string s){
    int n = s.length();
    vector<vector<bool> > dp (n, vector<bool> (n, 0));

    for(int i = 0; i< n; i++) dp[i][i] = 1;

//    for(int i =0; i<n-1; i++) {
//        if(s[i] == s[i+1]) dp[i][i+1] = 1;
//    }

    for(int i = 2; i<=n; i++){
        for(int j = 0; j<n-i+1 ; j++){
            if(s[j] == s[j+i-1]){
                if(i == 2){
                    dp[j][j+i-1] = 1;
                }
                else{
                    if(dp[j+1][j+i-2]) dp[j][j+i-1] = 1;
                }
            }
        }
    }

    string ans = "";
    ans+=s.front();
    
    bool flag = 0;
    
    //dp[1][6] = 1;
    
    for(int i = 0; i<n-1; i++){
        for(int j=n-i-1, k = 0; k<=i, j<n; k++, j++){
            if(dp[k][j]) {
                //cout<<k<<" "<<j<<endl;
                ans = s.substr(k, j-k+1);
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }

    return ans;
}

int main(){
    string s = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";

    string ans = findlongestpalindromesubstring2(s);
    cout<<ans;
    return 0;
}