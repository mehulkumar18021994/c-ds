/*
Maximum Profit on App
Send Feedback
You have made a smartphone app and want to set its price such that the profit earned is maximised. There are certain buyers who will buy your app only if their budget is greater than or equal to your price.
You will be provided with a list of size N having budgets of buyers and you need to return the maximum profit that you can earn.
Lets say you decide that price of your app is Rs. x and there are N number of buyers. So maximum profit you can earn is :
 m * x
where m is total number of buyers whose budget is greater than or equal to x.
Input format :
Line 1 : N (No. of buyers)
Line 2 : Budget of buyers (separated by space)
Output Format :
 Maximum profit
Constraints :
1 <= N <= 10^6
Sample Input 1 :
4
30 20 53 14
Sample Output 1 :
60
Sample Output 1 Explanation :
Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.
Sample Input 2 :
5
34 78 90 15 67
Sample Output 2 :
201
Sample Output 2 Explanation :
Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).
*/



#include <iostream>
using namespace std;

void merge(int a[], int start, int mid, int end){
  int temp[end + 1];
  int leftCurr = start;
  int leftEnd = mid;
  int rightCurr = mid + 1;
  int rightEnd = end;
  int k = start;
  while(leftCurr <= leftEnd && rightCurr <= rightEnd){
    if(a[leftCurr] < a[rightCurr]){
      temp[k++] = a[leftCurr++];
    }else{
      temp[k++] = a[rightCurr++];
    }
  }
  for(;leftCurr<=leftEnd; leftCurr++){
    temp[k++] = a[leftCurr];
  }
  for(;rightCurr<=rightEnd; rightCurr++){
    temp[k++] = a[rightCurr];
  }
  for(int i = start; i < end + 1; i++){
    a[i] = temp[i];
  }
}

void mergeSort(int a[], int start, int end){
    if(start < end){
      int mid = (start + end)/2;
      mergeSort(a, start, mid);
      mergeSort(a, mid + 1, end);
      merge(a, start, mid, end);
    }
}

int maximumProfit1(int budget[], int n) {
    // Write your code here
    if(n == 1)
      return *budget;
    else{
      int currentPr = (*budget)*n;
      int recvPr = maximumProfit1(budget + 1, n - 1);
      return (currentPr > recvPr) ? currentPr : recvPr;
    }
}

int maximumProfit(int budget[], int n) {
  mergeSort(budget, 0, n - 1);
  // cout<<"After mergeSort:"<<endl;
  // for(int i = 0; i < n; i++){
  //   cout<<budget[i]<<" ";
  // }
  // cout<<endl;
  return maximumProfit1(budget,n);
}

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];

    cout << maximumProfit(input, n) << endl;
}
