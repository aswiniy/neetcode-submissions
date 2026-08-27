class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n= profits.size();

        struct project{
            int capital;
            int profit;
        };

        struct comp_cap{
            bool operator()(project & p1,project & p2){
                return p1.capital > p2.capital;
            }
        };

        struct comp_pro{
            bool operator()(project & p1, project & p2){
                return p1.profit<p2.profit;
            }
        };

        priority_queue<project, vector<project>, comp_cap> min_heap;
        priority_queue<project, vector<project>, comp_pro> max_heap;



        for(int i=0;i<n;i++){
           min_heap.push({capital[i],profits[i]});
        }

        for(int i=0;i<k;i++){

            while( !min_heap.empty() && min_heap.top().capital <= w){
                project p=min_heap.top();
                min_heap.pop();
                max_heap.push(p);
            }
            
            if(max_heap.empty())return w;
            project curr= max_heap.top();
            max_heap.pop();
            w+=curr.profit;
        }

        return w;
    }
};