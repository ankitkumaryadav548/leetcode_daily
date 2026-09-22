class StockSpanner {
public:

    stack<int> price;
    stack<int> index;

    int i = 0;

    StockSpanner() {
    }

    int next(int p) {

        while(price.size() > 0 && price.top() <= p) {
            price.pop();
            index.pop();
        }

        int span;

        if(price.size() == 0) {
            span = i + 1;
        }
        else {
            span = i - index.top();
        }

        price.push(p);
        index.push(i);

        i++;

        return span;
    }
};