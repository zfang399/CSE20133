/**
 * by Zhaoyuan Fang
 * CSE20133 HW6
 * rand.cpp
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char * argv[])
{
  float num_min=0,num_max=0;
  int count=0,seed=0;
  char flag_int[]="-int";
  char flag_min[]="-min";
  char flag_max[]="-max";
  char flag_count[]="-count";
  char flag_seed[]="-seed";
  bool gen_int=false,gen_seed=false,incomplete=false,invalid=false;

  /*Error Codes
    No flags provided          --- 1
    Incomplete flag            --- -1
    Invalid flag               --- -2
    invalid falg combination   --- -3
  */
  if(argc==1){
    cerr<<"Usage: rand [flags]"<<endl;
    cerr<<"  Available Flags:"<<endl;
    cerr<<"             -int - Produce integers rather than floating point numbers."<<endl;
    cerr<<"    -min <number> - The smallest number to be returned. Defaults to 0."<<endl;
    cerr<<"    -max <number> - The largest number to be returned. Defaults to 0."<<endl;
    cerr<<"  -count <number> - How many random numbers to return. Defaults to 0."<<endl;
    cerr<<"  -seed <number> - Seed the Random Number Generator with a specific value."<<endl;
    return 1;
  }
  for(int i=1;i<argc;i++){
    if(strcmp(argv[i],flag_int)==0){
      gen_int=true;
    }else if(strcmp(argv[i],flag_min)==0){
      i++;
      if(i==argc){
        incomplete=true;
        break;
      }
      char* endptr;
      num_min=strtof(argv[i],&endptr);
      if(*endptr!='\0'){
        invalid=true;
        break;
      }
    }else if(strcmp(argv[i],flag_max)==0){
      i++;
      if(i==argc){
        incomplete=true;
        break;
      }
      char* endptr;
      num_max=strtof(argv[i],&endptr);
      if(*endptr!='\0'){
        invalid=true;
        break;
      }
    }else if(strcmp(argv[i],flag_count)==0){
      i++;
      if(i==argc){
        incomplete=true;
        break;
      }
      char* endptr;
      count=strtof(argv[i],&endptr);
      if(*endptr!='\0'){
        invalid=true;
        break;
      }
    }else if(strcmp(argv[i],flag_seed)==0){
      i++;
      if(i==argc){
        incomplete=true;
        break;
      }
      char* endptr;
      seed=strtof(argv[i],&endptr);
      if(*endptr!='\0'){
        invalid=true;
        break;
      }
      gen_seed=true;
    }else{
      invalid=true;
      break;
    }
  }
  if(invalid){
    cerr<<"Usage: rand [flags]"<<endl;
    cerr<<"  Available Flags:"<<endl;
    cerr<<"             -int - Produce integers rather than floating point numbers."<<endl;
    cerr<<"    -min <number> - The smallest number to be returned. Defaults to 0."<<endl;
    cerr<<"    -max <number> - The largest number to be returned. Defaults to 0."<<endl;
    cerr<<"  -count <number> - How many random numbers to return. Defaults to 0."<<endl;
    cerr<<"  -seed <number> - Seed the Random Number Generator with a specific value."<<endl;
    return -2;
  }
  if(incomplete){
    cerr<<"Usage: rand [flags]"<<endl;
    cerr<<"  Available Flags:"<<endl;
    cerr<<"             -int - Produce integers rather than floating point numbers."<<endl;
    cerr<<"    -min <number> - The smallest number to be returned. Defaults to 0."<<endl;
    cerr<<"    -max <number> - The largest number to be returned. Defaults to 0."<<endl;
    cerr<<"  -count <number> - How many random numbers to return. Defaults to 0."<<endl;
    cerr<<"  -seed <number> - Seed the Random Number Generator with a specific value."<<endl;
    return -1;
  }

  if(!gen_seed){
    srand(time(NULL));
  }else{
    srand(seed);
  }

  for(int i=0;i<count;i++){
    if(gen_int){
      cout<<(int)(rand()%(int)(num_max-num_min)+num_min)<<endl;
    }else{
      cout<<setprecision(4)<<(float)(num_min+(float)rand()/RAND_MAX*(num_max-num_min))<<endl;
    }
  }
  return 0;
}