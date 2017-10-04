/**
 *  by Zhaoyuan Fang
 *  CSE20133 HW05
 *  stats
 */


#include <iostream>
#include <cmath>
using namespace std;

//declare functions
int inputNumbers(double[], int);
double getMin(const double[], int);
double getMax(const double[], int);
double getSum(const double[], int);
double getStdDev(const double[], int, double);

#define ARRAY_SIZE (100000)

int main()
{
  double a[ARRAY_SIZE];
  int asize=inputNumbers(a,ARRAY_SIZE);  // get the size of the array
  if(!cin.eof()){
    cerr<<"Error reading numbers."<<endl;
    return 1;
  }
  double min_num=getMin(a,asize);        // get the min
  double max_num=getMax(a,asize);        // get the max
  double sum_num=getSum(a,asize);        // get the sum
  double amean=sum_num/asize;            // get the mean
  double StdDev_num=getStdDev(a,asize,amean);
  //cout the results
  cout<<"min\t"<<"max\t"<<"sum\t"<<"count\t"<<"mean\t"<<"stddev"<<endl;
  cout<<min_num<<'\t'<<max_num<<'\t'<<sum_num<<'\t'<<asize<<'\t'<<amean<<'\t'<<$
  return 0;
}

int inputNumbers(double a[], int maxsize){
  double x;
  int asize=0;
  while(cin>>x){
    // check if too many numbers are inputted
    if(asize==maxsize){
      cerr<<"Error reading numbers."<<endl;
      return 1;
    }
    a[asize]=x;
    asize++;
  }
  return asize;
}

double getMin(const double a[], int asize){
  //set the initial val of num to the maximum of int
  double min_num=2147483647;
  for(int i=0;i<asize;i++){
    if(a[i]<min_num) min_num=a[i];
  }
  return min_num;
}

double getMax(const double a[], int asize){
  //set the initial val of num to the minimum of int
  double max_num=-2147483648;
  for(int i=0;i<asize;i++){
    if(a[i]>max_num) max_num=a[i];
  }
  return max_num;
}

double getSum(const double a[], int asize){
  //set the sum to 0 initially
  double sum_num=0;
  for(int i=0;i<asize;i++){
    sum_num+=a[i];
  }
  return sum_num;
}

double getStdDev(const double a[], int asize, double amean){
  double diff=0;
  for(int i=0;i<asize;i++){
    diff+=(a[i]-amean)*(a[i]-amean);
  }
  double stddev=sqrt(diff/asize);
  return stddev;
}
