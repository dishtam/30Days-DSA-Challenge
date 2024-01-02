class DataStream {
public:
    int val,K,cnt;
    deque<int> dq;
    DataStream(int value, int k) {
        val = value;
        K=k;
        cnt=0;
    }
    
    bool consec(int num) {
        if(num==val){
            cnt++;
            if(cnt>=K) return 1;
            else if(cnt<K) return 0;
        }
        else cnt=0;
        return 0;
    }
};
