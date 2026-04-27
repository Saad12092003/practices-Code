#include <bits/stdc++.h>
using namespace std;
#define SIZE 13

int a[SIZE];
int f = 0, r = -1;

int top = -1;

void Mergeing(int a[], int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int temp[h + 1];

    while (i <= mid && j <= h) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            k++;
            i++;
        } else {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= h) {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (i = l; i <= h; i++) {
        a[i] = temp[i];
    }
}
void Mergesort(int a[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;

        Mergesort(a, l, mid);
        Mergesort(a, mid + 1, h);
        Mergeing(a, l, mid, h);
    }
}

void Enqueue(int val) {
    if (r== SIZE - 1) {
        cout << "Queue Overflow\n";
        return;
    }

    a[++r] = val;
}
int Dequeue() {
    if (f > r) {
        cout << " Queue Underflow\n";
        return -1;
    }
    return a[f++];
}

void Push(int val) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    top++;
    a[top] = val;
}
void Pop()
{
    if(top == -1)
    {
        cout<<" Stack is empty"<<endl;
        return ;
    }
    top--;
}

void printQueue() {
    if(f>r)
    {
        cout<<" Queue: Queue is empty"<<endl;
    }
    else
    {
        cout << " Queue: ";
    for (int i = f; i <= r; i++)
        cout << a[i] << " ";
    cout << endl;
    }

}

void printStack() {
   if(top == -1)
   {
       cout<<" Stack: Stack is empty"<<endl;
   }
   else
   {
           cout << " Stack (top to bottom): ";
    for (int i = top; i >= 0; i--)
        cout << a[i] << " ";
    cout << endl;

   }
}
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
string infixtopostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(st.top()) >=prec(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
string infixtoprefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    stack<char> st;
    string prefix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            prefix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {

            while (!st.empty() && prec(st.top()) > prec(c)) {
                prefix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}


int main() {
    int n;
    cout << " Enter number of digits in your id: ";
    cin >> n;

    int a[100];
char oper[] = {'+', '-', '*', '/', '+', '-', '*', '/', '+', '-', '*','/'};
string expr = "";

 cout<<" Enter your ID :";
for (int i = 0; i < n; i++) {
    cin >> a[i];
}


for (int i = 0; i < n; i++) {
    expr += to_string(a[i]);
    if (i < n - 1) expr += oper[i % 12];
}


    cout << "\n Student ID:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout<<endl;

    Mergesort(a, 0, n - 1);

    cout << "\n Merge Sort:\n";
    for (int i = 0; i < n; i++) {
        cout << " "<<a[i] << " ";
        Enqueue(a[i]);
    }
    cout << endl;
    cout<<endl;

     cout << "\n Queue implement :\n";
    printQueue();
    printStack();

    while (f <= r) {
        int x = Dequeue();
        Push(x);
    }

    cout << "\n After Dequeue & Push into stack:\n";

    printStack();
    printQueue();

       string postfix = infixtopostfix(expr);
    string prefix = infixtoprefix(expr);
    cout<<endl;
    cout<<endl;
    cout << " Infix expression: " <<expr<<endl;
    cout << " Postfix expression: " << postfix << endl;
    cout << " Prefix expression: " << prefix << endl;

    return 0;
}


