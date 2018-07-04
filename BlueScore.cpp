/*=============================================================================== 
On my honor,
The following program is a result of personal e#ffort. I have not discussed with
anyone other than my instructor or any appropriate person in charge of the class.
I have not used, or slightly modified  code or portion of code from another
student, or an unauthorized source.
If any C++ language code or documentation used in my program was obtained from
another source, such as a textbook or course notes, that has been clearly noted
with a proper citation in the comments of my program.
I have not designed this program in such a way as to defeat or interfere with the
normal operation of the eniac system or cslab machines at Hunter College .
< Johnny Qiu >  
===============================================================================*/
/*
Author: <Johnny Qiu>
Course: {493.62}
Instructor: <Jia Xu>
Assignment: <Project Question4>
Due Date:  12/15/2017
      
       This program allows testing for different languages, using BLEU score to determine the similarity between sentences, I have implement Bleu score with
    1-gram,2-gram,3-gram,4-gram, but for sentences 1-gram worked the best in my case .All sentences were given a random number under uniform distribution,
    if the sentences did not have more that 0.1 , it was removed from testing. Also uses Levenstein Distance for the metrifc distance.
    

*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <random>
int d[1000][1000];
#define MIN(x,y) ((x) < (y) ? (x) : (y))

using namespace std;

void calcBleu(string firstRef,string secRef,string thirdRef){
   //Formula of Bleu Score 1 since BLeu score 4 is usually for entire corpus but since these are sentences i implement unigram, I have tested using BI GRAM,4 gram and it was not as good as uni gram .
    double bleuscore,bleuscore2,bleuscore3,tempScore,tempScore2,tempScore3;
    map<string,int> uniGramFirst,uniGramSec,uniGramThird;
    string temp,secTemp,thirdTemp;
    int counting=0,counting2=0,counting3=0,counting4=0,counting5=0,counting6=0;
    int sentenceNum,sentenceNum2,sentenceNum3;
    int counterword=0;
    int record,brevity;
 
for(int i=0;i<firstRef.size();i++){
    temp+=firstRef[i];
    if(firstRef[i]=='.'||firstRef[i]=='?'||firstRef[i]=='!'||firstRef[i]==' '){
    uniGramFirst[temp]=0;
    temp.clear();
 }

}
for(int i=0;i<secRef.size();i++){
    temp+=secRef[i];
    if(secRef[i]=='.'||secRef[i]=='?'||secRef[i]=='!'||secRef[i]==' '){
        uniGramSec[temp]=0;
        temp.clear();
    
}

}
for(int i=0;i<thirdRef.size();i++){
    temp+=thirdRef[i];
    if(thirdRef[i]=='.'||thirdRef[i]=='?'||thirdRef[i]=='!'||thirdRef[i]==' '){
        uniGramThird[temp]=0;
        temp.clear();
    
}
}


//--------------------------------------------------------------------------------------------//Mapped UniGram
//------------------------------------------------------------------------------------Unigram for S1 reference S2 Candidate


        for(int j=0;j<secRef.size();j++){
            secTemp+=secRef[j];
           
            if(secRef[j]=='.'||secRef[j]=='?'||secRef[j]=='!'||secRef[j]==' '){
            map<string,int>::iterator t=uniGramFirst.find(secTemp);  
            if(t!=uniGramFirst.end()){
         
             counting++;
            }
            secTemp.clear();
         }
        }
        
         bleuscore=1.0*counting/uniGramFirst.size();
         sentenceNum=2;
         cout<<endl;

        for(int j=0;j<secRef.size();j++){
           secTemp+=secRef[j];
   
    if(secRef[j]=='.'||secRef[j]=='?'||secRef[j]=='!'||secRef[j]==' '){
    map<string,int>::iterator t=uniGramFirst.find(secTemp);  
    if(t!=uniGramFirst.end()){
 
     counting++;
    }
    secTemp.clear();
 }
}

 bleuscore=1.0*counting/uniGramFirst.size();
 sentenceNum=2;
 cout<<endl;

        for(int k=0;k<thirdRef.size();k++){
           thirdTemp+=thirdRef[k];
           if(thirdRef[k]=='.'||thirdRef[k]=='?'||thirdRef[k]=='!'||thirdRef[k]==' '){
            map<string,int>::iterator t=uniGramFirst.find(thirdTemp);
             if(t!=uniGramFirst.end()){
             counting2++;
             
             }
             thirdTemp.clear();
           }

        }
        tempScore=1.0*counting2/uniGramFirst.size();
             if(tempScore>bleuscore){
                 bleuscore=tempScore;
                 sentenceNum=3;
             } 
 
    //-----------------------------------------------------------------------------------------------------------------------------------First of the Setence

    for(int j=0;j<firstRef.size();j++){
        temp+=firstRef[j];
       
        if(firstRef[j]=='.'||firstRef[j]=='?'||firstRef[j]=='!'||firstRef[j]==' '){
        map<string,int>::iterator t=uniGramSec.find(temp);  
        if(t!=uniGramSec.end()){
     
         counting3++;
        }
        temp.clear();
     }
    }

     bleuscore2=1.0*counting3/uniGramSec.size();
     sentenceNum2=1;
     cout<<endl;

    for(int k=0;k<thirdRef.size();k++){
       thirdTemp+=thirdRef[k];
       if(thirdRef[k]=='.'||thirdRef[k]=='?'||thirdRef[k]=='!'||thirdRef[k]==' '){
        map<string,int>::iterator t=uniGramSec.find(thirdTemp);
         if(t!=uniGramSec.end()){
         counting4++;
         
         }
         thirdTemp.clear();
       }

    }
    tempScore2=1.0*counting4/uniGramSec.size();
         if(tempScore2>bleuscore2){
             bleuscore2=tempScore2;
             sentenceNum2=3;
         } 

    
   // cout<<endl;
 //-----------------------------------------------------------------------------------------------------------------------------------Second Sentence 
 for(int j=0;j<firstRef.size();j++){
    temp+=firstRef[j];
   
    if(firstRef[j]=='.'||firstRef[j]=='?'||firstRef[j]=='!'||firstRef[j]==' '){
    map<string,int>::iterator t=uniGramThird.find(temp);  
    if(t!=uniGramThird.end()){
 
     counting5++;
    }
    temp.clear();
 }
}

 bleuscore3=1.0*counting5/uniGramThird.size();
 sentenceNum3=1;
 cout<<endl;
//----------------------------------------------------------------------------------------------------------------------------------Third Sentence
for(int k=0;k<secRef.size();k++){
   temp+=secRef[k];
   if(secRef[k]=='.'||secRef[k]=='?'||secRef[k]=='!'||secRef[k]==' '){
    map<string,int>::iterator t=uniGramThird.find(temp);
     if(t!=uniGramThird.end()){
     counting6++;
     
     }
     temp.clear();
   }

}
tempScore3=1.0*counting6/uniGramThird.size();
 if(tempScore3>bleuscore3){
     bleuscore3=tempScore3;
     sentenceNum3=2;
 }

if(bleuscore2>bleuscore && bleuscore2>bleuscore3){
    cout<<"Highest Bleu score is " <<bleuscore2<<endl;
    cout<<"S2 is closest to"<<" S"<<sentenceNum2;
}
else if(bleuscore3>bleuscore && bleuscore3>bleuscore2){
    cout<<"Highest Bleu score is " <<bleuscore3<<endl;
    cout<<"S3 is closest to"<<" S"<<sentenceNum3;
}
else{
    cout<<"Highest Bleu score is " <<bleuscore<<endl;
    cout<<"S1 is closest to"<<" S"<<sentenceNum;
}
    

        }
 void ldistance(string firstRef,string secRef,string thirdRef){
            int temp,tracker,i,j,n,m;
          
            m = firstRef.length();
            n = secRef.length();
         
            for(i=0;i<=m;i++)
            d[0][i] = i;
            for(j=0;j<=n;j++)
            d[j][0] = j;
         
            for (j=1;j<=m;j++)
            {
                for(i=1;i<=n;i++)
                {
                    if(firstRef[i-1] == secRef[j-1])
                    {
                        tracker = 0;
                    }
                    else
                    {
                        tracker = 1;
                    }
                    temp = MIN((d[i-1][j]+1),(d[i][j-1]+1));
                    d[i][j] = MIN(temp,(d[i-1][j-1]+tracker));
                }
            }
            cout<<endl;
            cout<<"The Distance between Sentence 1 and Sentence 2 is : "<<d[n][m]<<endl;
        
            m=firstRef.length();
            n=thirdRef.length();
            for(i=0;i<=m;i++)
            d[0][i] = i;
            for(j=0;j<=n;j++)
            d[j][0] = j;
         
            for (j=1;j<=m;j++)
            {
                for(i=1;i<=n;i++)
                {
                    if(firstRef[i-1] == thirdRef[j-1])
                    {
                        tracker = 0;
                    }
                    else
                    {
                        tracker = 1;
                    }
                    temp = MIN((d[i-1][j]+1),(d[i][j-1]+1));
                    d[i][j] = MIN(temp,(d[i-1][j-1]+tracker));
                }
            }
            cout<<"The Distance between Sentence 1 and Sentence 3 is : "<<d[n][m]<<endl;
        
            m=secRef.length();
            n=firstRef.length();
            for(i=0;i<=m;i++)
            d[0][i] = i;
            for(j=0;j<=n;j++)
            d[j][0] = j;
         
            for (j=1;j<=m;j++)
            {
                for(i=1;i<=n;i++)
                {
                    if(secRef[i-1] == firstRef[j-1])
                    {
                        tracker = 0;
                    }
                    else
                    {
                        tracker = 1;
                    }
                    temp = MIN((d[i-1][j]+1),(d[i][j-1]+1));
                    d[i][j] = MIN(temp,(d[i-1][j-1]+tracker));
                }
            }
            cout<<"The Distance between Sentence 2 and Sentence 1 is : "<<d[n][m]<<endl;;
            
            m=secRef.length();
            n=thirdRef.length();
            for(i=0;i<=m;i++)
            d[0][i] = i;
            for(j=0;j<=n;j++)
            d[j][0] = j;
         
            for (j=1;j<=m;j++)
            {
                for(i=1;i<=n;i++)
                {
                    if(secRef[i-1] == thirdRef[j-1])
                    {
                        tracker = 0;
                    }
                    else
                    {
                        tracker = 1;
                    }
                    temp = MIN((d[i-1][j]+1),(d[i][j-1]+1));
                    d[i][j] = MIN(temp,(d[i-1][j-1]+tracker));
                }
            }
            cout<<"The Distance between Sentence 2 and Sentence 3 is : "<<d[n][m]<<endl;
           
            m=thirdRef.length();
            n=firstRef.length();
            for(i=0;i<=m;i++)
            d[0][i] = i;
            for(j=0;j<=n;j++)
            d[j][0] = j;
         
            for (j=1;j<=m;j++)
            {
                for(i=1;i<=n;i++)
                {
                    if(thirdRef[i-1] == firstRef[j-1])
                    {
                        tracker = 0;
                    }
                    else
                    {
                        tracker = 1;
                    }
                    temp = MIN((d[i-1][j]+1),(d[i][j-1]+1));
                    d[i][j] = MIN(temp,(d[i-1][j-1]+tracker));
                }
            }
            cout<<"The Distance between Sentence 3 and Sentence 1 is : "<<d[n][m]<<endl;
            
            m=thirdRef.length();
            n=secRef.length();
                for(i=0;i<=m;i++){
                     d[0][i] = i;
                                 }
                 for(j=0;j<=n;j++){
                     d[j][0] = j;
                                 }
            for (j=1;j<=m;j++)
            {
                for(i=1;i<=n;i++)
                {
                    if(thirdRef[i-1] == secRef[j-1])
                    {
                        tracker = 0;
                    }
                    else
                    {
                        tracker = 1;
                    }
                    temp = MIN((d[i-1][j]+1),(d[i][j-1]+1));
                    d[i][j] = MIN(temp,(d[i-1][j-1]+tracker));
                }
            }
            cout<<"The Distance between Sentence 3 and Sentence 2 is : " <<d[n][m]<<endl;
         }

    

     
void divideBleu(string input){
    map<int,string > calcBleuScore;
    string temp;
    string firstRef,secRef,thirdRef;
    int count=0,sentenceNo=1;
     for(unsigned i=0;i<input.length();i++){
         temp+=input[i];
         if(input[i]=='.'||input[i]=='?'||input[i]=='!'){
            count++;
             if(count==1){
              firstRef=temp;
              temp.clear();
             }
             else if(count==2){
               secRef=temp;
               temp.clear();
             }
             else if(count==3){
                thirdRef=temp;
                temp.clear();
                count=0;
               
                calcBleu(firstRef,secRef,thirdRef);  
                ldistance(firstRef,secRef,thirdRef);
                cout<<endl;
                cout<<"These are the closest match for sentence : "<<sentenceNo<<endl;     
                sentenceNo++;
             }
            
            }
            
     }
   
}


 

void firstTask(string input){
      map<int,vector<string> > allStrings;

      int counter=1;
      string temp;
    for(unsigned i=0;i<input.length();i++){
         temp+=input[i];
        
    
        if(input[i]=='.'||input[i]=='?'||input[i]=='!'){
         allStrings[counter].push_back(temp);
         temp.clear();
     
        }

        
        if(allStrings[counter].size()==3){
    
            counter++;
        }
    }
      for(map<int,vector<string> > :: iterator i=allStrings.begin();i!=allStrings.end();++i){
    
          cout<<endl;
          cout<<"S"<<(*i).first<<":";
          vector<string> allStrings=(*i).second;
          for(unsigned k=0;k<allStrings.size();k++){
           cout<<"("<<allStrings[k]<<")"<<" ";   
           }
           cout<<endl;
} 

 
}


int main(){
    map<string, double > rdSentences;//real distribution sentences
    default_random_engine generator;
    double number;
    int findPosition;
    uniform_real_distribution<double> distribution(0.0,1.0);
    string temp,fileContent;
    ifstream myfile("example.txt");
    if(myfile.fail()){
        cerr<<"Error Can't Open File"<<endl;
        exit(1);
    }
    while(!myfile.eof()){
        myfile>>temp;
        fileContent+=temp;
        fileContent+=" ";
        
    }
    
    for(unsigned i=0;i<fileContent.length();i++){
       temp+=fileContent[i];
    
        if(fileContent[i]=='.'||fileContent[i]=='?'||fileContent[i]=='!'){
          number=distribution(generator);
          if(number<0.05){        //Uniform Distribution 
         findPosition=fileContent.find(temp);
         fileContent.erase(findPosition,i);
         
         }
         rdSentences[temp]=number;
         temp.clear();
    }
}
    

    firstTask(fileContent);
    divideBleu(fileContent);
  
}