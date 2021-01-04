#include<iostream>
#include<fstream>
#include "ChangeOddLocNumsOrder.hpp"

using namespace std;

/*******************************************************************************
 * Function: main
 * ----------------
 * Description:
 *   This is the main function of the program. 
 *
 * Arguments:
 *   int argc     : Count of command line argument to program
 *   char *argv[] : Command line arguments array
 *
 * returns:
 *   int  : '0' on Success
 *          Non-Zero value on failure
 ******************************************************************************/
int main(int argc, char *argv[]){
  FUNC_ENTRY;

  string sFileName="input_file";
  string sLine="";
  ifstream ifsFileHndlr(sFileName);
  SingleLinkedList& sll = *new SingleLinkedList();
  SingleLinkedList& queue = *new SingleLinkedList();
  SingleLinkedList& stack = *new SingleLinkedList();

  while(getline(ifsFileHndlr, sLine, ' ')){
    int a = std::stoi(sLine);
    sll.push_back(a);
  }

  sll.printData();

  int iTemp;
  for (int i = 0; i < sll.size(); ++i) {
    iTemp = sll.at(i);
    if( iTemp % 2 == 1){
      queue.push_back(i);
      stack.push_front(iTemp);
    }
  }

  for (int j = 0; j < queue.size(); ++j) {
    sll.replace(queue.at(j),stack.at(j));
  }

  sll.printData();

  return 0;
}


