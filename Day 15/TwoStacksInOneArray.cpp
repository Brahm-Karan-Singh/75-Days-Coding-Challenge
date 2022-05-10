class TwoStack {
	int *a;
	int top1;
	int top2;
	int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
		a = new int[s];
		top1 = -1;
		top2 = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
// 		Means space is availaible there 
        if(top2 - top1 > 1){
			top1++;
			a[top1] = num;
		}
    }

    // Push in stack 2.
    void push2(int num) {
//         Means space is availaible there 
        if(top2 - top1 > 1){
			top2--;
			a[top2] = num;
		}
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
       if(top1 >= 0){
		   int ans = a[top1];
		   top1--;
		   return ans;
	   }else{
			return -1;
	   }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 < size){
		   int ans = a[top2];
		   top2++;
		   return ans;
	   }else{
			return -1;
	   }
    }

};
