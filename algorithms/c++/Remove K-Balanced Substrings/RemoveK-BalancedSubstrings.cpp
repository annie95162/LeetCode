class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<char> st;
        stack<char> temp;
        int first = 0;
        int second = 0;
        bool ltor = false;
        bool rtol = false;
        for(int i = 0; i < s.size(); i++){
            //cout << i;
            if(s[i] == '('){
                second = 0;
                if(first < k){
                    first++;
                    //cout << s[i];
                }
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(first == k){
                    second++;
                }else{
                    first = 0;
                    second = 0;
                }
                st.push(s[i]);
            }
            if(second == k){
                //cout << st.size();
                for(int j = 0; j < 2*k && !st.empty(); j++){
                    //cout << st.size() << j << endl;
                    st.pop();
                }
                cout << st.size();
                first = 0;
                second = 0;
                //cout << st.empty();
                while(!st.empty()){
                    if(st.top() == '(' && first < k){
                        temp.push(st.top());
                        st.pop();
                        first++;
                        ltor = true;
                        if(first == k){
                            for(int m = 0; m < temp.size(); m++){
                                st.push(temp.top());
                                temp.pop();
                            }
                            ltor = false;
                            rtol = false;
                            break;
                        }
                        if(st.empty()){
                            for(int m = 0; m < temp.size(); m++){
                                st.push(temp.top());
                                temp.pop();
                            }
                            if(second != 0){
                                first = 0;
                                second = 0;
                            }
                            ltor = false;
                            rtol = false;
                            break;
                        }
                    }else if(st.top() == ')' && second < k-1){
                        if(ltor || st.size() == 1){
                            for(int m = 0; m < temp.size(); m++){
                                st.push(temp.top());
                                temp.pop();
                            }
                            first = 0;
                            second = 0;
                            ltor = false;
                            rtol = false;
                            break;
                        }
                        temp.push(st.top());
                        st.pop();
                        second++;
                        if(second == k-1){
                            rtol = true;
                        }
                        
                    }else{
                        first = 0;
                        second = 0;
                        ltor = false;
                        rtol = false;
                        for(int m = 0; m < temp.size(); m++){
                            st.push(temp.top());
                            temp.pop();
                        }
                        break;
                    }
                }
            }
        }
        string ans(st.size(), ' ');
        for(int i = st.size()-1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;

    }
};
