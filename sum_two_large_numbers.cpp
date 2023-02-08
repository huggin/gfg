        reverse(begin(X), end(X));
        reverse(begin(Y), end(Y));
        char ans[100001] = {0};
        int more = 0;
        int i = 0;
        for(; i < X.size() && i < Y.size(); ++i) {
            int t = more + ans[i]+ X[i] - '0' + Y[i] - '0';
            if (t >= 10) {
                more = 1;
                ans[i] = t - 10;
            } else {
                more = 0;
                ans[i] = t;
            }
        }
        for(; i < X.size(); ++i) {
            int t = more + ans[i] + X[i] - '0';
            if (t >= 10) {
                more = 1;
                ans[i] = t - 10;
            } else {
                ans[i] = t;
                more = 0;
            }
        }
        for(; i < Y.size(); ++i) {
            int t = more + ans[i] + Y[i] - '0';
            if (t >= 10) {
                more = 1;
                ans[i] = t - 10;
            } else {
                ans[i] = t;
                more = 0;
            }
        }
        int n = i;
        if (more == 1) {
            ans[i] = 1;
            n = i+1;
        }
        int len = 0;
        for(int i = n-1; i >= 0; --i) {
            if (ans[i] != 0) {
                len = i+1;
                break;
            }
        }
        if (len == 0) return "0";
        string s(len, ' ');
        for(int j=len-1; j>=0; --j) {
            s[len-1-j] = ans[j]+'0';
        }
        
        return s;
