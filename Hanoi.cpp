#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;


bool Stack1[64] = {false};
bool Stack2[64] = {false};
bool Stack3[64] = {false};

bool verbose = false;
bool graph  = false;


void Init(const int iSize)
{
  int i =0;
  for(i=0;i<iSize;++i)
  {
        Stack1[i] = true;
  }
        
}
void PrintStacks()
{
  system("clear");
  int i =0;
  cout << "1  2  3 " << endl;
  for(i=63;i>=0;i--)
  {
        if(Stack1[i] || Stack2[i] || Stack3[i])
        {
                cout << 
                (Stack1[i] ? "_ ":"  " ) << 
                (Stack2[i] ? " _ ":"   " ) <<
                (Stack3[i] ? " _ ":"   " ) << endl;

        }
  }     
  //bottom
  cout << "__________________________" << endl << endl;
}

void Move(bool* myStack1, bool* myStack2, bool* myStack3, int cnt, int from, int to)
{
  //move the first cnt slides from stack1 to stack3
  if(cnt > 0)
  {
        Move(myStack1,myStack3,myStack2,cnt-1,1,2);
        if(verbose)
                cout << "Moving Slide " << cnt << " from " << from<< " to " << to << endl; 
        if(graph)
                PrintStacks();
        myStack1[cnt-1] = false;
        myStack3[cnt-1] = true;
        Move(myStack2,myStack1,myStack3,cnt-1,2,3);
        if(graph)
                PrintStacks();
  }
}



int main(int argc, char** argv)
{
        if (argc > 1)
        {
                if(argc >2)
                {
                        if(!strncmp(argv[2],"g",1))
                                graph = true;
                        if(!strncmp(argv[2],"v",1))
                                verbose = true;
                }
                if(argc >3)
                {
                        if(!strncmp(argv[3],"g",1))
                                graph = true;
                        if(!strncmp(argv[3],"v",1))
                                verbose = true;
                }
                
                int Nb = atoi(argv[1]);
                
                cout << "Starting with " <<  Nb  << " Slides. graph =" << graph
                << " verbose=" << verbose << endl;
                
                cout << "arguments: " << endl;
                for (int i =0;i<argc;++i)
                        cout << i <<": " << "\"" << argv[i] << "\"" << endl;

                Init(Nb);
                PrintStacks();
                Move(Stack1, Stack2,Stack3,Nb,1,3);
                PrintStacks();
        }
        return 0;
}

