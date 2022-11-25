#include <iostream>
#include <vector>
using namespace std;
struct предмет { double маса; double ціна;};
int main() {
srand(time(0));
int розмір=rand()%50+30;
vector <предмет> набір;
предмет окремий;
  for(int i=0;i<розмір;i++)
    {
      окремий.маса=rand()%100*0.1+0.1;
      окремий.ціна=rand()%1000*0.1+0.1;
      набір.push_back(окремий);
    }
  for(int i=0;i<набір.size();i++)
    {
      int index= i;
      for(int j=i+1;j<набір.size();j++)
        {
          if(набір[index].ціна<набір[j].ціна)
            index=j;
        }
      swap(набір[i], набір[index]);
    }
  vector <int> оптимальний;
  double summ=0.0, summp=0.0;
  for(int i=0; i<розмір; i++)
    {
      if((summ+набір[i].маса)<=50)
        {
          summp+=набір[i].ціна;
          summ=summ+набір[i].маса;
          оптимальний.push_back(i);
        }
    }
  cout<<"Весь набір "<<endl;
  for(int i=0;i<розмір;i++)
    {
      cout<<"Номер предмету "<<i;
      cout<<" Ціна  "<<набір[i].ціна;
      cout<<" Маса  "<<набір[i].маса;
      //оптимальний.push_back(i);
      cout<<endl;
    }
   cout<<"Оптимальний набір "<<endl;
  for(int i=0;i<оптимальний.size();i++)
    {
      cout<<"Номер предмету "<<оптимальний[i];
      cout<<" Ціна  "<<набір[оптимальний[i]].ціна;
      cout<<" Маса  "<<набір[оптимальний[i]].маса;
      cout<<endl;
    } 
  cout<<"Вартість "<<summp<<endl;
  cout<<"Загальна маса "<<summ<<endl;
}