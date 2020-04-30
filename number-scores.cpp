#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class ScoreCalulator
{
    int calculateScoreForSingleDigit(int num)
    {
        if(num==0)
            return 6;
        int score = 0;
        if(num%3==0)
            score += 2;
        while(num>0)
        {
            int d = num%10;
            if(d%2==0)
                score += 4;
            if(d==7)
                score += 1;
            num = num/10;
        }
        return score;
    }
    
    int calculateScoreForConsecutiveFives(int num)
    {
        if(num%10==num)
            return 0;
        int score = 0;
        int found = 0;
        int count = 0;
        while(num>0)
        {
            int d = num%10;
            if(d==5 && !found)
            {
               found = 1;
               count += 1;
            }
            else if(d==5)
            {
                count += 1;
            }
            else
            {
               found = 0;
               if(count >=2)
               {
                   int temp = count - 2;
                   score += 3;
                   temp *= 6;
                   score += temp;
               }
               count = 0;
            }
            num = num/10;
        }
        if(count >=2)
        {
           int temp = count - 2;
           score += 3;
           temp *= 6;
           score += temp;
        }
        return score;
    }
    
    int calculateScoreForSequence(int num)
    {
        if(num%10==num)
            return 1;
        int score = 0;
        int count = 1;
        int prev = num%10;
        num = num/10;
        while(num>0)
        {
            int d = num%10;
            if(d==prev+1)
            {
                count += 1;   
                prev = d;
            }
            else
            {
                score += pow(count,2);
                count = 1;
                prev = d;
            }
            num=num/10;
        }
        score += pow(count,2);
        return score;
        
    }
    public:
    int getScore(int num)
    {
       return calculateScoreForSequence(num) + calculateScoreForConsecutiveFives(num) + calculateScoreForSingleDigit(num); 
    }
    int getScoreForSequence(int num)
    {
        return calculateScoreForSequence(num);
    }
    int getScoreForConsecutiveFives(int num)
    {
        return calculateScoreForConsecutiveFives(num);
    }
    int getScoreForSingleDigit(int num)
    {
        return calculateScoreForSingleDigit(num);
    }
};


int main()
{
    int num = 555;
    ScoreCalulator SC;
    cout << SC.getScore(num) << endl;
    return 0;
}